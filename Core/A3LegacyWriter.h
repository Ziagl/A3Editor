#pragma once

#include <string>
#include <memory>
#include "LoggingFacility.h"
#include "CountryFactory.h"
#include "Graph.h"

class A3LegacyWriter
{
public:
	A3LegacyWriter(const Logger& logger) : logger(logger) {}

	void saveCountryFile(std::shared_ptr<Graph> graph, vertex_t countryId);

private:
	void writePerson(Person& p, std::ofstream& out, bool birthday = true, bool firstnameFirst = true);

	Logger logger;
};