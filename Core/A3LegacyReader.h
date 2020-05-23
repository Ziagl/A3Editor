#pragma once

#include <string>
#include <memory>
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

		std::shared_ptr<Country> loadCountryFile(std::shared_ptr<Graph> graph, std::string filename);
		void loadNationFile(std::shared_ptr<Graph> graph, std::string filename);

	private:
		Logger logger;
		std::mutex mutex;
		std::string fileHeader;
	};
}