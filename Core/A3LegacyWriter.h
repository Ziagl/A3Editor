#pragma once

#include <string>
#include <memory>
#include "LoggingFacility.h"
#include "CountryFactory.h"

class A3LegacyWriter
{
public:
	A3LegacyWriter(const Logger& logger) : logger(logger) {}

	void saveCountryFile(std::shared_ptr<Country> country, std::string filename);

private:
	Logger logger;
};