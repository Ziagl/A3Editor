#include "PlayerFactory.h"

Player PlayerFactory::create() 
{
	// generate random name tuple (firstname, lastname)
	auto names = nameGenerator.createName();

	// creates player with random name
	Player p(logger, std::get<0>(names), std::get<1>(names));

	logger->writeInfoEntry("pointer auf logger: " + std::to_string(logger.use_count()));					//TODO remove

	return p;
}