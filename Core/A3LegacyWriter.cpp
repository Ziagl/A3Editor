#include "A3LegacyWriter.h"
#include <fstream>
#include <sstream>
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "StadiumFactory.h"

void A3LegacyWriter::saveCountryFile(std::shared_ptr<Graph> graph, vertex_t countryId)
{
	auto country = graph->getCountryById(countryId);

	std::ofstream stream;
	std::string filename = country->getFilename();

	filename = filename.substr(0, filename.size() - 4) + "1" + filename.substr(filename.size() - 4, filename.size());

	stream.open(filename, std::ios::out);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while writing " + filename);
		stream.close();
		return;
	}

	// write file "header"
	stream << "17373592\n";

	// country
	stream << "%SECT%LAND\n";
	CountryFactory::writeToSAV(*country, stream);

	// team
	auto teams = graph->getTeamIdsByCountry(countryId);
	for (std::vector<vertex_t>::iterator it = teams.begin(); it < teams.end(); ++it)
	{
		auto team = graph->getTeamById(*it);
		stream << "%SECT%VEREIN\n";
		TeamFactory::writeToSAV(*team, stream);

		// player
		auto players = graph->getPlayerIdsByTeam(*it);
		for (std::vector<vertex_t>::iterator itp = players.begin(); itp < players.end(); ++itp)
		{
			auto player = graph->getPlayerById(*itp);
			stream << "%SECT%SPIELER\n";
			PlayerFactory::writeToSAV(*player, stream);
			stream << "%ENDSECT%SPIELER\n";
		}
		stream << "%ENDSECT%VEREIN\n";

		// stadium
		stream << "%SECT%STADION\n";
		Stadium s = team->getStadium();
		StadiumFactory::writeToSAV(s, stream);
		stream << "%ENDSECT%STADION\n";
	}

	stream << "%ENDSECT%LAND\n";

	stream.flush();
	stream.close();

	return;
}