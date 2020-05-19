#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Country.h"
#include "EasyLogger.h"

class CountryFactory {
public:
	CountryFactory(const Logger& logger) : logger(logger) {}

	Country create();
	Country createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Country &country, std::ofstream &out);

private:
	Logger logger;
};