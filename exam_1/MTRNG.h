#pragma once
#include <random>

class MTRNG
{
public:
	MTRNG(std::uint_fast32_t seed); 
	MTRNG(std::mt19937 MT19937Object); 
	MTRNG(std::uint_fast32_t seed, size_t dimension); 
	const double operator()(); // Random uniform
	const double operator()(const double lowerBound, const double upperBound); // Random uniform with boundaries
	void setSeed(std::uint_fast32_t seed); 
	std::uint_fast32_t getMTRNG() { return RandNumMT(); } 
	double genNormal(); 
	size_t getDim() { return dim; } 
	std::vector<double> genNormal(std::vector<double>& vector);
	MTRNG(const MTRNG&);

private:
	std::mt19937 RandNumMT; 
	size_t dim;
};