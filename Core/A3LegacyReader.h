#pragma once

#include <string>
#include "LoggingFacility.h"

class A3LegacyReader
{
public:
	A3LegacyReader(const Logger& logger) : logger(logger) {}

	void loadFile(std::string filename);


private:
	Logger logger;
};