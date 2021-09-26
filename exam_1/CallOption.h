#pragma once

class CallOption
{
public:
	CallOption(double K_, double T_);
	double getK() { return K; }
	double getT() { return T; }
	double callPayoff(double ST_);
private:
	double K, T;
};