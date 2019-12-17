#pragma once

#include "Player.h"
#include "LoggingFacility.h"
#include "NameGenerator.h"

class PlayerFactory {
public:
	PlayerFactory(const Logger& logger) : logger(logger), nameGenerator(logger) {}

	Player create();

private:
	NameGenerator nameGenerator;
	Logger logger;
};