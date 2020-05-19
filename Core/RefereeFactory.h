#pragma once

#include <string>
#include <vector>
#include "Referee.h"
#include "EasyLogger.h"

class RefereeFactory {
public:
	RefereeFactory(const Logger& logger) : logger(logger) {}

	Referee create();
	Referee createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Referee& referee, std::ofstream& out);

private:
	Logger logger;
};