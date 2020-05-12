#pragma once

#include "YouthPlayer.h"
#include "LoggingFacility.h"
#include "NameGenerator.h"

class YouthPlayerFactory {
public:
	YouthPlayerFactory(const Logger& logger) : logger(logger), nameGenerator(logger) {}

	YouthPlayer createFromSAV(std::vector<std::string> data);

private:
	NameGenerator nameGenerator;
	Logger logger;
};