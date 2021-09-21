#pragma once

template <typename T>
class TemplatedRNG
{
public:
	TemplatedRNG(unsigned int seed);
	TemplatedRNG(T MyRandomNumber, unsigned int seed);
	void setSeed(unsigned int seed);
	double genUniform();

private:
	T RandomNumber;
};

template<typename T>
inline TemplatedRNG<T>::TemplatedRNG(unsigned int seed)
{
	RandomNumber.seed(seed);
}

template<typename T>
inline TemplatedRNG<T>::TemplatedRNG(T MyRandomNumber, unsigned int seed) : RandomNumber(MyRandomNumber)
{
	RandomNumber.seed(seed);
}

template<typename T>
inline void TemplatedRNG<T>::setSeed(unsigned int seed)
{
	RandomNumber.seed(seed);
}

template<typename T>
inline double TemplatedRNG<T>::genUniform()
{
	return RandomNumber() / (double)RandomNumber.max();
}
