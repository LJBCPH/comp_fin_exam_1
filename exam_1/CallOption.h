#pragma once

class CallOption
{
public:
	CallOption(const double K_, const double T_);
	double getK() { return K; }
	double getT() { return T; }
	double callPayoff(const double ST_);
private:
	const double K, T;
};