#pragma once

#include <string>
#include <memory>
#include "EasyLogger.h"
#include "CountryFactory.h"
#include "Graph.h"

namespace Core
{
	class A3LegacyWriter
	{
	public:
		A3LegacyWriter(const Logger& logger) : logger(logger), fileHeader("17373592") {}

		void saveCountryFile(std::shared_ptr<Graph> graph, vertex_t countryId);

	private:
		void writePerson(Person& p, std::ofstream& out, bool birthday = true, bool firstnameFirst = true);

		Logger logger;
		std::string fileHeader;
	};
}