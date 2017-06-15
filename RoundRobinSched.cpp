#include "RoundRobinSched.h"

RoundRobinSched::RoundRobinSched(unsigned long quantum):
	CScheduler()
{
	//s_pThis = this;
	m_nQuantum = quantum;
}

RoundRobinSched::~RoundRobinSched() {

}

/*
RoundRobinSched* RoundRobinSched::Get(){
	return s_pThis;
}
*/