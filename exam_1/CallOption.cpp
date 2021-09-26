#include "CallOption.h"

CallOption::CallOption(double K_, double T_)
	:K(K_), T(T_)
{
}

double CallOption::callPayoff(double ST_)
{
	if (ST_ > K) {
		return ST_ - K;
	}
	else {
		return 0;
	}
}
