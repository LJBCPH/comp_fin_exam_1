#pragma once
#include <random>

int random_number_mt(std::uint_fast32_t seed_);

class MTRNG
{
public:
	MTRNG(std::uint_fast32_t seed); // setting seed
	double genUniform(); //p3
	double genUniform(double lower_bound, double upper_bound); //p5
	void setSeed(std::uint_fast32_t seed); //p4
	int getMTRNG() { return RandNumMT(); }
	double genNormal();
private:
	std::mt19937 RandNumMT; //p2
};