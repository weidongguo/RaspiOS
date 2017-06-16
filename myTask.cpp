#include <circle/sched/scheduler.h>
#include <hal/uart.h>
#include "myTask.h"
#include <circle/timer.h>


myTask::myTask (char arg)
{
  var = arg;
}

myTask::~myTask ()
{
}

void myTask::foo()
{
  while(1) {
    CTimer::Get()->MsDelay(1000);

    CLogger::Get ()->Write ("Foo", LogNotice, "core %d is running foo(%c)", CScheduler::GetCore (), var );

    CScheduler::Get ()->Yield();
    //CScheduler::Get ()->Sleep(1);
  }
}

void myTask::Run ()
{
  //CTimer::Get()->StartKernelTimer (1 * HZ, TimerHandler);
  foo();
}
