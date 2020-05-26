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
		void saveNationFile(std::shared_ptr<Graph> graph, std::string filename);
		void saveNotPlayableCountryFile(std::shared_ptr<Graph> graph, std::string filename);

	private:
		void writePerson(Person& p, std::ofstream& out, bool birthday = true, bool firstnameFirst = true);
		void writeTeams(std::ofstream& out, std::shared_ptr<Graph> graph, vertex_t countryId);

		Logger logger;
		std::string fileHeader;
	};
}