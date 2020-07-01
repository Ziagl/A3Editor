#pragma once

#include "Additional.h"
#include "EasyLogger.h"

namespace Core
{
	class AdditionalFactory
	{
	public:
		AdditionalFactory(const Logger& logger) : logger(logger) {}

		Additional createFromSAV(std::vector<std::string> data, short countLines, short valuesPerLine);
		static void writeToSAV(Additional& additional, std::ofstream& out);

	private:
		Logger logger;
	};
}