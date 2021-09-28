#include "CallOption.h"

CallOption::CallOption(const double K_, const double T_)
	:K(K_), T(T_)
{
}

double CallOption::callPayoff(const double ST_)
{

	if (ST_ > K) {
		return ST_ - K;
	}
	else {
		return 0;
	}
}
