#pragma once

#include "League.h"
#include "EasyLogger.h"

namespace Core
{
	class LeagueFactory 
	{
	public:
		LeagueFactory(const Logger& logger) : logger(logger) {}

		League create();
		League createFromSAV(std::vector<std::string> data);
		static void writeToSAV(League& league, std::ofstream& out);

	private:
		Logger logger;
	};
}