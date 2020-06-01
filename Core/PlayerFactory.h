#pragma once

#include "Player.h"
#include "EasyLogger.h"
#include "NameGenerator.h"

namespace Core
{
	class PlayerFactory {
	public:
		PlayerFactory(const Logger& logger) : logger(logger) {}

		Player create(NameGenerator& nameGenerator);
		Player createFromSAV(std::vector<std::string> data);
		static void writeToSAV(Player& player, std::ofstream& out);

	private:
		Logger logger;
	};
}