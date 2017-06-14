#ifndef myTask_h
#define myTask_h

#include <circle/sched/task.h>
#include <circle/logger.h>

class myTask : public CTask
{
public:
	myTask (char arg);
	~myTask (void);

	void Run (void);

private:
        void foo (void);

	char var;
};

#endif
