#include "Thread.h"


Thread::Thread(thread_handler_t pThreadHandler, unsigned int count, const void *params)
	: CTask()
{
	m_pThreadHandler = pThreadHandler;
	m_nParamCount = count;
	m_pParams = params;
}

Thread::~Thread()
{
	m_pThreadHandler = 0;
	m_pParams = 0;
}

void Thread::Run(){
	m_pThreadHandler(m_nParamCount, m_pParams);
}

