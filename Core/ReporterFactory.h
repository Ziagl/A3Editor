#pragma once

#include <string>
#include <vector>
#include "Reporter.h"
#include "LoggingFacility.h"

class ReporterFactory {
public:
	ReporterFactory(const Logger& logger) : logger(logger) {}

	Reporter create();
	Reporter createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Reporter& reporter, std::ofstream& out);

private:
	Logger logger;
};