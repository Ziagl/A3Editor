#pragma once

#include "Competition.h"
#include "EasyLogger.h"

namespace Core
{
	class CompetitionFactory {
	public:
		CompetitionFactory(const Logger& logger) : logger(logger) {}

		Competition create();
		Competition createFromSAV(std::vector<std::vector<std::string>> dataCleague, std::vector<std::vector<std::string>> dataEM, std::vector<std::vector<std::string>> dataWM);
		static void writeToSAVCleague(Competition& competition, std::ofstream& out);
		static void writeToSAVEmwm(Competition& competition, std::ofstream& out);

	private:
		Logger logger;
	};
}