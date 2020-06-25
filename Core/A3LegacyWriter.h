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
		void saveLeagueFile(std::shared_ptr<Graph> graph, vertex_t leagueId);
		void saveAdditionalFile(std::shared_ptr<Graph> graph, std::string filename);
		void saveInternationalFiles(std::shared_ptr<Graph> graph, std::string filenameTeams, std::string filenameReferees);
		void saveYouthFiles(std::shared_ptr<Graph> graph, std::string filename);

	private:
		inline void writePerson(Person& p, std::ofstream& out, bool birthday = true, bool firstnameFirst = true);
		inline void writeTeams(std::ofstream& out, std::shared_ptr<Graph> graph, vertex_t countryId);

		Logger logger;
		std::string fileHeader;
	};
}