#pragma once
#include <random>

class MTRNG
{
public:
	MTRNG(std::uint_fast32_t seed); // setting seed
	MTRNG(std::mt19937 MT19937Object); // overloading to take 
	MTRNG(std::uint_fast32_t seed, size_t dimension); // overloading to take 
	double operator()();
	double operator()(double lowerBound, double upperBound); //p5
	void setSeed(std::uint_fast32_t seed); //p4
	std::uint_fast32_t getMTRNG() { return RandNumMT(); }
	double genNormal();
	//double genNormal(std::uint_fast32_t randMT);
	size_t getDim() { return dim; }
	std::vector<double> genNormal(std::vector<double>& vector);
	MTRNG(const MTRNG&);

private:
	std::mt19937 RandNumMT; //p2
	size_t dim;
};