#pragma once

#include <string>
#include <vector>
#include "Stadium.h"
#include "LoggingFacility.h"

class StadiumFactory
{
public:
	StadiumFactory(const Logger& logger) : logger(logger) {}

	Stadium create();
	Stadium createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Stadium& stadium, std::ofstream& out);

private:
	Logger logger;
};