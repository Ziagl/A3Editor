#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <mutex>
#include "EasyLogger.h"
#include "CountryFactory.h"
#include "Graph.h"

namespace Core
{
	class A3LegacyReader
	{
	public:
		A3LegacyReader(const Logger& logger) : logger(logger), fileHeader("17373592") {}

		std::shared_ptr<Country> loadCountryFile(std::shared_ptr<Graph> graph, const std::string filename);
		void loadNationFile(std::shared_ptr<Graph> graph, std::string filename);
		void loadNotPlayableCountryFile(std::shared_ptr<Graph> graph, std::string filename);
		void loadLeagueFile(std::shared_ptr<Graph> graph, vertex_t countryId, std::string filename, short hierarchy);
		void loadAdditionalFile(std::shared_ptr<Graph> graph, std::string filename);
		void loadInternationalFiles(std::shared_ptr<Graph> graph, std::string filenameTeams, std::string filenameReferees);
		void loadYouthFiles(std::shared_ptr<Graph> graph, std::string filename);
		void loadFormerPlayers(std::shared_ptr<Graph> graph, std::string filename);
		void loadOtherPlayers(std::shared_ptr<Graph> graph, std::string filename);

	private:
        inline std::string fixLineEnding(std::string line);
    
		Logger logger;
		std::mutex mutex;
		std::string fileHeader;
	};
}