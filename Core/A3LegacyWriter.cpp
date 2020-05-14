#include "A3LegacyWriter.h"
#include <fstream>
#include <sstream>
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "StadiumFactory.h"
#include "ReporterFactory.h"

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

	// reporter
	stream << "%SECT%MEDIAP\n";
	auto reporter = country->getReporter();
	for (std::vector<Reporter>::iterator it = reporter.begin(); it < reporter.end(); ++it)
	{
		stream << "%SECT%REPORTER\n";
		ReporterFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%REPORTER\n";
	}
	
	stream << "%ENDSECT%MEDIAP\n";

	// critics
	stream << "%SECT%KRITIP\n";
	auto critics = country->getCritics();
	for (std::vector<Person>::iterator it = critics.begin(); it < critics.end(); ++it)
	{
		stream << "%SECT%KRITIKER\n";
		writePerson(*it, stream, false, false);
		stream << "%ENDSECT%KRITIKER\n";
	}
	stream << "%ENDSECT%KRITIP\n";

	// president
	stream << "%SECT%VPRAESID\n";
	Person president = country->getPresident();
	writePerson(president, stream);
	stream << "%ENDSECT%VPRAESID\n";

	stream << "%ENDSECT%LAND\n";

	stream.flush();
	stream.close();

	return;
}

void A3LegacyWriter::writePerson(Person& p, std::ofstream& out, bool birthday, bool firstnameFirst)
{
	if(firstnameFirst)
		out << p.getFirstname() << "\n";
	out << p.getLastname() << "\n";
	if(!firstnameFirst)
		out << p.getFirstname() << "\n";
	if(birthday)
		out << p.getBirthday() << "\n";
}