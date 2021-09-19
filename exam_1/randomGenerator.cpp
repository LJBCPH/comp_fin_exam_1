#include <random>
#include "randomGenerator.h"
#include "gaussian_header.hpp"

int random_number_mt(std::uint_fast32_t seed_)
{
	std::mt19937 random_number_mt_;

	random_number_mt_.seed(seed_);

	return random_number_mt_();

}

MTRNG::MTRNG(std::uint_fast32_t seed)
{
	RandNumMT.seed(seed);
}

MTRNG::MTRNG(std::mt19937 MT19937Object)
{
	RandNumMT = MT19937Object;
}

MTRNG::MTRNG(std::uint_fast32_t seed, size_t dimension) : dim(dimension)
{
}

double MTRNG::genUniform()
{
	return RandNumMT() / (double)RandNumMT.max();
}

double MTRNG::genUniform(double lower_bound, double upper_bound)
{
	return RandNumMT() / (double)RandNumMT.max() * (upper_bound - lower_bound) + lower_bound;
}

void MTRNG::setSeed(std::uint_fast32_t seed)
{
	RandNumMT.seed(seed);
}

double MTRNG::genNormal()
{
	return invNormalCdf(genUniform());
}

double MTRNG::genNormal(std::uint_fast32_t randMT)
{
	double unif = randMT / (double)RandNumMT.max();
	return invNormalCdf(unif);
}

std::vector<double> MTRNG::genNormal(std::vector<double>& vector)
{
	for (int i = 0; i < dim; i++) {
		vector[i] = invNormalCdf(genUniform());
	}
	return vector;
}

MTRNG::MTRNG(const MTRNG&)
{
}
