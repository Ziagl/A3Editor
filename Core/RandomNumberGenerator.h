#pragma once

namespace Core
{
	class RandomNumberGenerator
	{
	public:
		RandomNumberGenerator() {}
		~RandomNumberGenerator() {}

		// min include, max exclude
		static int randomNumber(int min, int max);
	};
}