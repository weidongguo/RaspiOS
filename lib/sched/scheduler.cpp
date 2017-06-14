//
// scheduler.cpp
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2015-2016  R. Stange <rsta2@o2online.de>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <circle/sched/scheduler.h>
#include <circle/timer.h>
#include <circle/logger.h>
#include <assert.h>
#include <circle/spinlock.h>

CTask *m_pTask[MAX_TASKS];
unsigned m_nTasks (0);

static CSpinLock getCoreSpinLock;
static CSpinLock SpinLock;

static const char FromScheduler[] = "sched";

CScheduler *CScheduler::s_pThis [CORES] = {0};

CScheduler::CScheduler (void)
:	//m_nTasks (0),
	m_pCurrent (0),
	m_nCurrent (0)
{
	assert (s_pThis[CScheduler::GetCore()] == 0);
	s_pThis[CScheduler::GetCore()] = this;

	m_pCurrent = new CTask (0);		// main task currently running on this core
	m_pCurrent->SetState(TaskStateRunning);
	assert (m_pCurrent != 0);
}

CScheduler::~CScheduler (void)
{
	SpinLock.Acquire ();
	assert (m_nTasks == 1);
	assert (m_pTask[0] == m_pCurrent);

	RemoveTask (m_pCurrent);
	delete m_pCurrent;
	m_pCurrent = 0;

	s_pThis[GetCore()] = 0;

	SpinLock.Release ();
}

void CScheduler::startFromSecondary (void)
{
	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d is in startFromSecondary", CScheduler::GetCore ());

	// only choose one
	m_pCurrent->SetState (TaskStateTerminated); // get rid of original task so it doesnt clutter up list of tasks
	//m_pCurrent->SetState (TaskStateBlocked);  // prevent returning to original task until it is woken in case we want to go back to it

	Yield();
}


void CScheduler::Yield (void)
{
	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d is in yield()", CScheduler::GetCore ());

	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d tried to get lock", CScheduler::GetCore ());
	SpinLock.Acquire ();
	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d got lock", CScheduler::GetCore ());

	while ((m_nCurrent = GetNextTask ()) == MAX_TASKS)	// no task is ready
	{
		CLogger::Get ()->Write ("scheduler", LogNotice, "core %d releasing lock", CScheduler::GetCore ());
		SpinLock.Release ();

		CLogger::Get ()->Write ("scheduler", LogNotice, "core %d tried to get a task but none were available", CScheduler::GetCore ());
    CTimer::Get()->MsDelay(100); // idle a bit before checking for new tasks

		CLogger::Get ()->Write ("scheduler", LogNotice, "core %d tried to get lock", CScheduler::GetCore ());
		SpinLock.Acquire ();
		CLogger::Get ()->Write ("scheduler", LogNotice, "core %d got lock", CScheduler::GetCore ());

		assert (m_nTasks > 0);
	}
	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d got task %u", CScheduler::GetCore (), m_nCurrent);

	assert (m_nCurrent < MAX_TASKS);
	CTask *pNext = m_pTask[m_nCurrent];
	assert (pNext != 0);
	if (m_pCurrent == pNext)
	{
		CLogger::Get ()->Write ("scheduler", LogNotice, "core %d releasing lock", CScheduler::GetCore ());
		SpinLock.Release ();

		return;
	}

	if (m_pCurrent->GetState() == TaskStateRunning)
	{
		m_pCurrent->SetState(TaskStateReady);
	}

	TTaskRegisters *pOldRegs = m_pCurrent->GetRegs ();
	m_pCurrent = pNext;
	TTaskRegisters *pNewRegs = m_pCurrent->GetRegs ();

	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d releasing lock", CScheduler::GetCore ());
  SpinLock.Release ();


	assert (pOldRegs != 0);
	assert (pNewRegs != 0);

	CLogger::Get ()->Write ("scheduler", LogNotice, "core %d is about to taskswitch", CScheduler::GetCore ());
	TaskSwitch (pOldRegs, pNewRegs);
}

//calls usSleep
void CScheduler::Sleep (unsigned nSeconds)
{
	// be sure the clock does not run over taken as signed int
	const unsigned nSleepMax = 1800;	// normally 2147 but to be sure
	while (nSeconds > nSleepMax)
	{
		usSleep (nSleepMax * 1000000);

		nSeconds -= nSleepMax;
	}

	usSleep (nSeconds * 1000000);
}

//Calls usSleep
void CScheduler::MsSleep (unsigned nMilliSeconds)
{
	if (nMilliSeconds > 0)
	{
		usSleep (nMilliSeconds * 1000);
	}
}

//reads/edits data in m_pCurrent, needs to commit before call to yield()
void CScheduler::usSleep (unsigned nMicroSeconds)
{
	if (nMicroSeconds > 0)
	{
		unsigned nTicks = nMicroSeconds * (CLOCKHZ / 1000000);

		unsigned nStartTicks = CTimer::Get ()->GetClockTicks ();

		SpinLock.Acquire ();

		assert (m_pCurrent != 0);
		assert (m_pCurrent->GetState () == TaskStateRunning);
		m_pCurrent->SetWakeTicks (nStartTicks + nTicks);
		m_pCurrent->SetState (TaskStateSleeping);

		SpinLock.Release ();

		Yield ();
	}
}

// reads m_nTasks and list of tasks, adds task to list of tasks and increments m_nTasks, can wait
// only called in task constructor, where there is no lock
void CScheduler::AddTask (CTask *pTask)
{
	assert (pTask != 0);

	unsigned i;

	SpinLock.Acquire ();

	for (i = 0; i < m_nTasks; i++)
	{
		if (m_pTask[i] == 0)
		{
			m_pTask[i] = pTask;

			return;
		}
	}

	if (m_nTasks >= MAX_TASKS)
	{
		CLogger::Get ()->Write (FromScheduler, LogPanic, "System limit of tasks exceeded");
	}

	m_pTask[m_nTasks++] = pTask;

	SpinLock.Release ();
}

//removes task from list of tasks, called in getNextTask and Destructor only while lock is acquired
void CScheduler::RemoveTask (CTask *pTask)
{
	for (unsigned i = 0; i < m_nTasks; i++)
	{
		if (m_pTask[i] == pTask)
		{
			m_pTask[i] = 0;

			if (i == m_nTasks-1)
			{
				m_nTasks--;
			}

			return;
		}
	}

	assert (0);
}


void CScheduler::BlockTask (CTask **ppTask)
{
	assert (ppTask != 0);
	*ppTask = m_pCurrent;

	assert (m_pCurrent != 0);
	assert (m_pCurrent->GetState () == TaskStateRunning);
	m_pCurrent->SetState (TaskStateBlocked);

	Yield ();
}


void CScheduler::WakeTask (CTask **ppTask)
{
	assert (ppTask != 0);
	CTask *pTask = *ppTask;

	*ppTask = 0;

#ifdef NDEBUG
	if (   pTask == 0
	    || pTask->GetState () != TaskStateBlocked)
	{
		CLogger::Get ()->Write (FromScheduler, LogPanic, "Tried to wake non-blocked task");
	}
#else
	assert (pTask != 0);
	assert (pTask->GetState () == TaskStateBlocked);
#endif

	pTask->SetState (TaskStateReady);
}

// needs global list of tasks, returns index of task to run next
//only called in yield() while lock is acquired
unsigned CScheduler::GetNextTask (void)
{
	unsigned nTask = m_nCurrent < MAX_TASKS ? m_nCurrent : 0;

	unsigned nTicks = CTimer::Get ()->GetClockTicks ();

	for (unsigned i = 1; i <= m_nTasks; i++)
	{
		if (++nTask >= m_nTasks)
		{
			nTask = 0;
		}

		CTask *pTask = m_pTask[nTask];
		if (pTask == 0)
		{
			continue;
		}

		switch (pTask->GetState ())
		{
		case TaskStateReady:
			pTask->SetState (TaskStateRunning);
			return nTask;

		case TaskStateRunning:
			if (m_pCurrent != pTask){
				continue;
			}
			else{
				return nTask;
			}

		case TaskStateBlocked:
			continue;

		case TaskStateSleeping:
			if ((int) (pTask->GetWakeTicks () - nTicks) > 0)
			{
				continue;
			}
			pTask->SetState (TaskStateRunning);
			return nTask;

		case TaskStateTerminated:
			RemoveTask (pTask);
			delete pTask;
			return MAX_TASKS;

		default:
			assert (0);
			break;
		}
	}

	return MAX_TASKS;
}

CScheduler *CScheduler::Get (void)
{
	assert (s_pThis[GetCore()] != 0);
	return s_pThis[GetCore()];
}

int CScheduler::GetCore (void)
{
	getCoreSpinLock.Acquire ();

	u32 nMPIDR;
	asm volatile ("mrc p15, 0, %0, c0, c0, 5" : "=r" (nMPIDR));
	int val = nMPIDR & (CORES-1);

	getCoreSpinLock.Release ();

	return val;
}
