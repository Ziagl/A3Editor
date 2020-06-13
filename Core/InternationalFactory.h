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

		International createFromSAV(std::vector<std::string> dataTeams, std::vector<Referee>& referees);
		void writeToSAV(International& international, std::ofstream& outTeams, std::ofstream& outReferees);

	private:
		Logger logger;
	};
}