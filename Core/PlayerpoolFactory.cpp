#include "PlayerpoolFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

Playerpool PlayerpoolFactory::createFromSAV(std::vector<std::vector<std::string>> data)
{
	Playerpool playerpool;

	if (data.empty())
	{
		logger->writeErrorEntry("Playerpool data is empty.");
		return playerpool;
	}

	std::vector<std::vector<std::tuple<std::string, std::string>>> playerpoolData;

	// each individual file
	for (auto fileData : data)
	{
		std::vector<std::tuple<std::string, std::string>> countrypool;
		for (int i = 0; i < fileData.size(); i += 2)
		{
			auto playerName = std::make_tuple(fileData[i], fileData[i + 1]);
			countrypool.push_back(playerName);
		}
		playerpoolData.push_back(countrypool);
	}

	playerpool.setPool(playerpoolData);

	return playerpool;
}

void PlayerpoolFactory::writeToSAV(std::vector<std::tuple<std::string, std::string>> countrypool, std::ofstream& out)
{
	for (auto data : countrypool)
	{
		out << std::get<0>(data) << ENDOFLINE;
		out << std::get<1>(data) << ENDOFLINE;
	}
}