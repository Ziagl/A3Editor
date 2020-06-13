#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "International.h"
#include "EasyLogger.h"

namespace Core
{
	class InternationalFactory 
	{
	public:
		InternationalFactory(const Logger& logger) : logger(logger) {}

		International createFromSAV(std::vector<std::string> data);
		static void writeToSAV(International& international, std::ofstream& out);

	private:
		Logger logger;
	};
}