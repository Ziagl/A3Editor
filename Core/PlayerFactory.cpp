#include "PlayerFactory.h"

Player PlayerFactory::create() 
{
	// generate random name tuple (firstname, lastname)
	auto names = nameGenerator.createName();

	// creates player with random name
	Player p(logger);
	p.setFirstname(std::get<0>(names));
	p.setLastname(std::get<1>(names));

	logger->writeInfoEntry("pointer auf logger: " + std::to_string(logger.use_count()));					//TODO remove

	return p;
}

Player PlayerFactory::createFromSAV(std::vector<std::string> data)
{
	Player player;

	if (data.empty())
	{
		logger->writeErrorEntry("Player data is empty.");
		return player;
	}

	player.setLastname(data[0]);
	player.setLastname(data[1]);
	//2


	return player;
}