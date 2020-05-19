#pragma once

#include <string>
#include <memory>
#include "EasyLogger.h"
#include "CountryFactory.h"
#include "Graph.h"

class A3LegacyReader
{
public:
	A3LegacyReader(const Logger& logger) : logger(logger) {}

	std::shared_ptr<Country> loadCountryFile(std::shared_ptr<Graph> graph, std::string filename);

private:
	Logger logger;
};