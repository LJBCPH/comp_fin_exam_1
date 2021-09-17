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
