#pragma once

#include "Playerpool.h"
#include "EasyLogger.h"

namespace Core
{
	class PlayerpoolFactory {
	public:
		PlayerpoolFactory(const Logger& logger) : logger(logger) {}

		Playerpool createFromSAV(std::vector<std::vector<std::string>> data);
		static void writeToSAV(std::vector<std::tuple<std::string, std::string>> countrypool, std::ofstream& out);

	private:
		Logger logger;
	};
}