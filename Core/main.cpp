#include <iostream>
#include <ctime>
#include <memory>
#include "PlayerFactory.h"
#include "LoggerFactory.h"

int main()
{
	Logger logger = LoggerFactory::create();
	PlayerFactory playerFactory(logger);
	for (int i = 0; i < 3; ++i)
	{
		Player player = playerFactory.create();
		std::cout << player.getFirstname() << " " << player.getLastname() << std::endl;
		logger->writeWarnEntry("Something is wrong!");
	}

	return 0;
}