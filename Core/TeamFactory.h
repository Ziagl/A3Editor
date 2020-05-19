#pragma once

#include <string>
#include <vector>
#include "Team.h"
#include "EasyLogger.h"

class TeamFactory 
{
public:
	TeamFactory(const Logger& logger) : logger(logger) {}

	Team create();
	Team createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Team& team, std::ofstream& out);

private:
	// helper: 
	// convert string with int to color (last nibble)
	int strToColor(std::string data);
	// convert string with int to pattern (second last nibble)
	int strToPattern(std::string data);

	Logger logger;
};