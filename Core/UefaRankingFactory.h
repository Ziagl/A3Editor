#pragma once

#include "UefaRanking.h"
#include "EasyLogger.h"

namespace Core
{
	class UefaRankingFactory
	{
	public:
		UefaRankingFactory(const Logger& logger) : logger(logger) {}

		UefaRanking createFromSAV(std::vector<std::string> data, short countLines, short valuesPerLine);
		static void writeToSAV(UefaRanking& uefaRanking, std::ofstream& out);

	private:
		Logger logger;
	};
}