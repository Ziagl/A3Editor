#include "RandomNumberGenerator.h"
#include <random>

using namespace Core;

int RandomNumberGenerator::randomNumber(int min, int max)
{
	std::random_device rd;								// obtain a random number from hardware
	std::mt19937 eng(rd());								// seed the generator
	std::uniform_int_distribution<> distr(min, max-1);	// define the range

	return distr(eng);
}