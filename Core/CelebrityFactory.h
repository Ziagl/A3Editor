#pragma once

#include <string>
#include <vector>
#include "Celebrity.h"
#include "EasyLogger.h"

namespace Core
{
	class CelebrityFactory
	{
	public:
		CelebrityFactory(const Logger& logger) : logger(logger) {}

		Celebrity create();
		Celebrity createFromSAV(std::vector<std::string> data);
		static void writeToSAV(Celebrity& celebrity, std::ofstream& out);

	private:
		Logger logger;
	};
}