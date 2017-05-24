#ifndef THREAD_H
#define THREAD_H

#include <circle/sched/task.h>

typedef void (*thread_handler_t)(unsigned int count, const void *params);

class Thread : public CTask {
	thread_handler_t m_pThreadHandler;
	unsigned int m_nParamCount;
	const void *m_pParams;

	public:
		Thread (thread_handler_t pThreadHandler, unsigned int count = 0, const void *params = 0);
		~Thread();
		void Run(void);


};


#endif