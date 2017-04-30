#ifndef  THREAD_H
#define THREAD_H

#define MB                  1048576
#define DEFAULT_STACK_SIZE  MB

enum THREAD_STATE
{
  THREAD_INIT,
  THREAD_READY,
  THREAD_RUNNING,
  THREAD_WAITTING,
  THREAD_FINISHED
};

struct TCB {
  volatile THREAD_STATE state;
  arm_regfile_t regs;
  size_t       stack_size;
  u8           *stack;
};

typedef void (thread_handler_t)();

class Thread {
   public:
    TCB *tcb;
    size_t id;
  
};
class ThreadManager {
    
  private:
    Thread mainThread;
    Thread *currentThread;
    Thread *parentThread;

  public:
    ThreadManager();
    /*
    Create  a new thread, storing information about it  in  thread. Concurrently with the calling thread, thread  executes  the function  func  with the argument arg.
    */
    Thread* thread_create(thread_handler_t func, ThreadManager *tm);

    /*
    The calling thread  voluntarily gives up  the processor to  let some  other thread(s) run.
    The scheduler can resume  running the calling thread  whenever  it  chooses to  do  so.
    */
    void thread_yield();

    /*
    Wait  for thread  to  finish  if  it  has not already done  so; then  return  the value passed  to
    thread_exit by  that  thread. Note  that  thread_join may be  called  only  once  for each
    thread.
    */
    int thread_join();


    /*
    Finish  the current thread. Store the value ret in  the current thread’s  data  structure.  If another thread  is  already waiting in  a call  to  thread_join,  resume  it.
    */
    void thread_exit();

   
    void thread_switch(Thread *from, Thread *to);
    Thread * getCurrentThread();
    Thread * getParentThread();

};




#endif
