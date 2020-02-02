#include <iostream>
#include <ctime>
#include <memory>
#include "PlayerFactory.h"
#include "TeamFactory.h"
#include "LoggerFactory.h"
#include "A3LegacyReader.h"

int main()
{
	Logger logger = LoggerFactory::create();
	
	/*PlayerFactory playerFactory(logger);
	for (int i = 0; i < 3; ++i)
	{
		Player player = playerFactory.create();
		std::cout << player.getFirstname() << " " << player.getLastname() << std::endl;
		logger->writeWarnEntry("Something is wrong!");
	}*/

	A3LegacyReader reader(logger);
	reader.loadCountryFile("data/data.a3/LandOest.sav");
	reader.loadCountryFile("data/data.a3/LandDeut.sav");

	return 0;
}