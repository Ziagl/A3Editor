#include "InternationalFactory.h"
#include "RefereeFactory.h"
#include "globals.h"
#include <iterator>

using namespace Core;

International InternationalFactory::createFromSAV(std::vector<std::string> dataTeams, std::vector<Referee>& referees)
{
	International international;

	if (dataTeams.empty())
	{
		logger->writeErrorEntry("International team data is empty.");
		return international;
	}

	if (referees.empty())
	{
		logger->writeErrorEntry("International referee data is empty.");
		return international;
	}

	std::vector<InternationalTeam> internationalTeams;
	for (std::vector<std::string>::iterator it = dataTeams.begin(); it < dataTeams.end(); it+=2)
	{
		InternationalTeam internationalTeam;
		internationalTeam.name = *it;
		auto next = std::next(it, 1);
		internationalTeam.nationId = std::stoi(*next);
		internationalTeams.push_back(internationalTeam);
	}

	international.setTeams(internationalTeams);

	international.setReferees(referees);

	return international;
}

void InternationalFactory::writeToSAV(International& international, std::ofstream& outTeams, std::ofstream& outReferees)
{
	// export teams
	auto teams = international.getTeams();
	for (auto team : teams)
	{
		outTeams << "%SECT%IVEREIN" << ENDOFLINE;
		outTeams << team.name << ENDOFLINE;
		outTeams << team.nationId << ENDOFLINE;
		outTeams << "%ENDSECT%IVEREIN" << ENDOFLINE;
	}

	// export referees
	auto referees = international.getReferees();
	for (auto referee : referees)
	{
		RefereeFactory::writeToSAV(referee, outReferees);
	}
}