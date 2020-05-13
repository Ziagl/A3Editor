#pragma once

#include "Player.h"
#include "LoggingFacility.h"
#include "NameGenerator.h"

class PlayerFactory {
public:
	PlayerFactory(const Logger& logger) : logger(logger), nameGenerator(logger) {}

	Player create();
	Player createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Player& player, std::ofstream& out);

private:
	NameGenerator nameGenerator;
	Logger logger;
};