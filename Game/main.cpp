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
	auto countries = graph->getCountryIds();
	for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
	{
		writer.saveCountryFile(graph, *it);
	}

	return 0;
}