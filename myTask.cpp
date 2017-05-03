#include <circle/sched/scheduler.h>
#include <hal/uart.h>
#include "myTask.h"

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
    const char *b = &var;
    uart_puts(b);
    uart_puts("\n");
    
    CScheduler::Get ()->Sleep(1);
  }
}

void myTask::Run ()
{
  foo();
}
