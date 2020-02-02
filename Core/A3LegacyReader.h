#pragma once

#include <string>
#include <memory>
#include "LoggingFacility.h"
#include "CountryFactory.h"

class A3LegacyReader
{
public:
	A3LegacyReader(const Logger& logger) : logger(logger) {}

	std::shared_ptr<Country> loadCountryFile(std::string filename);


private:
	Logger logger;
};