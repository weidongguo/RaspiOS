#include <circle/sysconfig.h>
#include <circle/types.h>
#include <circle/util.h>
#include <circle/synchronize.h>

#include "contextswitch.h"
#include "thread.h"

void stub(thread_handler_t func, ThreadManager *tm){
  (*func)(); //Execute the function func()
  //thread_exit(0);//If func() does not call exit,call it here.
  tm->thread_switch(tm->getCurrentThread(), tm->getParentThread());
}

ThreadManager::ThreadManager(){
  TCB *tcb = new TCB();
  mainThread.tcb = tcb;
  currentThread = &mainThread;
  // TODO: Find if it requires more stack size.
  // TODO: check if stack size is to be determined for the main thread. 
  //tcb->stack_size = DEFAULT_STACK_SIZE;
  //tcb->stack = new u8[DEFAULT_STACK_SIZE];
  //tcb->regs.sp = (size_t) (tcb->stack) + tcb->stack_size;
}

Thread* ThreadManager::thread_create(thread_handler_t func, ThreadManager *tm) {
  Thread *t = new Thread();
  TCB *tcb = new TCB();
  t->tcb = tcb; 

  tcb->stack_size = DEFAULT_STACK_SIZE;
  tcb->stack = new u8[DEFAULT_STACK_SIZE];
  tcb->regs.sp = (size_t) (tcb->stack) + tcb->stack_size;
  tcb->regs.lr = (size_t) stub;
  
  tcb->regs.r0 = (size_t) func;
  tcb->regs.r1 = (size_t) tm;
  tcb->state = THREAD_READY;

  return t;
}

void ThreadManager::thread_switch(Thread *from, Thread *to){
  parentThread = from; 
  currentThread = to;
  ContextSwitch(&from->tcb->regs, &to->tcb->regs);
}

Thread* ThreadManager::getCurrentThread() {
  return currentThread;
}

Thread* ThreadManager::getParentThread(){
  return parentThread;
}
