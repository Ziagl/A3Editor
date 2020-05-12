#include <iostream>
#include <ctime>
#include <memory>
#include "PlayerFactory.h"
#include "TeamFactory.h"
#include "LoggerFactory.h"
#include "A3LegacyReader.h"
#include "A3LegacyWriter.h"
#include "GraphFactory.h"

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

	auto graph = GraphFactory::create();

	A3LegacyReader reader(logger);
	reader.loadCountryFile(graph, "data/data.a3/LandOest.sav");
	reader.loadCountryFile(graph, "data/data.a3/LandDeut.sav");

	A3LegacyWriter writer(logger);
	//writer.saveCountryFile(country1, "data/data.a3/LandOest.sav1");
	//writer.saveCountryFile(country2, "data/data.a3/LandDeut.sav1");

	return 0;
}