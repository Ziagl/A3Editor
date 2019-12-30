#pragma once

#include <string>
#include <vector>
#include "Country.h"
#include "LoggingFacility.h"

class CountryFactory {
public:
	CountryFactory(const Logger& logger) : logger(logger) {}

	Country create();
	Country createFromSAV(std::vector<std::string> data);

private:
	Logger logger;
};