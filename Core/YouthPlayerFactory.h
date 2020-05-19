#pragma once

#include "YouthPlayer.h"
#include "EasyLogger.h"
#include "NameGenerator.h"

class YouthPlayerFactory {
public:
	YouthPlayerFactory(const Logger& logger) : logger(logger), nameGenerator(logger) {}

	YouthPlayer createFromSAV(std::vector<std::string> data);
	static void writeToSAV(YouthPlayer& youthPlayer, std::ofstream& out);

private:
	NameGenerator nameGenerator;
	Logger logger;
};