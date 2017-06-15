#ifndef ROUNDROBINSCHED_H
#define ROUNDROBINSCHED_H

#include <circle/sched/scheduler.h>

#define QUANTUM_MS	3000


class RoundRobinSched : public CScheduler {
	//static RoundRobinSched *s_pThis;

	unsigned long m_nQuantum;


	public:
		RoundRobinSched(unsigned long quantum = QUANTUM_MS);
		~RoundRobinSched();

		//static RoundRobinSched* Get();	
		



};

#endif
