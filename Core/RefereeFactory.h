#pragma once

#include <string>
#include <vector>
#include "Referee.h"
#include "LoggingFacility.h"

class RefereeFactory {
public:
	RefereeFactory(const Logger& logger) : logger(logger) {}

	Referee create();
	Referee createFromSAV(std::vector<std::string> data);

private:
	Logger logger;
};