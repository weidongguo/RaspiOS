#include <circle/sysconfig.h>
#include <circle/types.h>
#include <circle/util.h>
#include <circle/synchronize.h>

#include "contextswitch.h"
#include "thread.h"

void stub(thread_handler_t func){
  (*func)(); //Execute the function func()
  //thread_exit(0);//If func() does not call exit,call it here.

}


void Thread::thread_create(thread_handler_t func) {
  TCB *tcb = new TCB();
  this->tcb = tcb; 

  tcb->stack_size = DEFAULT_STACK_SIZE;
  tcb->stack = new u8[DEFAULT_STACK_SIZE];
  tcb->regs.sp = (size_t) (tcb->stack) + tcb->stack_size;
  tcb->regs.lr = (size_t) stub;
  
  tcb->regs.r0 = (size_t) func;
  tcb->regs.r1 = (size_t) 0;
  tcb->state = THREAD_READY;

}
