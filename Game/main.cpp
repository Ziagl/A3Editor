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
	auto logger = Core::LoggerFactory::create();

	/*PlayerFactory playerFactory(logger);
	for (int i = 0; i < 3; ++i)
	{
		Player player = playerFactory.create();
		std::cout << player.getFirstname() << " " << player.getLastname() << std::endl;
		logger->writeWarnEntry("Something is wrong!");
	}*/

	auto graph = Core::GraphFactory::create();

	Core::A3LegacyReader reader(logger);
#ifdef __LINUX__
    std::string path = "../data/Data.a3/";
#else
    std::string path = "data/Data.a3/";
#endif
    reader.loadNationFile(graph, path + "Laender.sav");
	reader.loadCountryFile(graph, path + "LandOest.sav");
	reader.loadCountryFile(graph, path + "LandDeut.sav");
    reader.loadNotPlayableCountryFile(graph, path + "Internat.sav");
	reader.loadAdditionalFile(graph, path + "Kleinig.sav");

	// get all nations
	auto nationIds = graph->getNationIds();
	int count = 1;
	std::cout << "All european nations: " << std::endl;
	for (auto nationId : nationIds)
	{
		auto nation = graph->getNationById(nationId);
		if (nation->getContinent() == 0)	//europe
		{
			std::cout << /*count << ": " <<*/ nation->getShortname() /*<< " " << nation->getCountryId()*/ << std::endl;
			++count;
		}
	}

	Core::A3LegacyWriter writer(logger);
	auto countries = graph->getCountryIds();
	for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
	{
		writer.saveCountryFile(graph, *it);
	}

	return 0;
}