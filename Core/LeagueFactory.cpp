#include "LeagueFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

League LeagueFactory::create()
{
	return League();
}

League LeagueFactory::createFromSAV(std::vector<std::string> data, const std::string filename)
{
	League league;

	if (data.empty())
	{
		logger->writeErrorEntry("League data is empty.");
		return league;
	}

	league.setName(data[0]);
	league.setShortname(data[1]);
	league.setTeamNumber(std::stoi(data[2]));
	int start = 3;
	std::vector<short> teamIds;
	for (int i = start; i < league.getTeamNumber() + start; ++i)
	{
		teamIds.push_back(std::stoi(data[i]));
	}
	league.setTeamIds(teamIds);
	start += league.getTeamNumber();
	std::vector<std::tuple<short, short>> schedule;
	for (int i = start; i < data.size(); i += 2)
	{
		std::tuple<short, short> gameday = std::make_tuple(std::stoi(data[i]), std::stoi(data[i + 1]));
		schedule.push_back(gameday);
	}
	league.setSchedule(schedule);

	// meta data
	league.setFilename(filename);

	return league;
}

void LeagueFactory::writeToSAV(League& league, std::ofstream& out)
{
	out << league.getName() << ENDOFLINE;
	out << league.getShortname() << ENDOFLINE;
	out << league.getTeamNumber() << ENDOFLINE;
	for (auto teamId : league.getTeamIds())
	{
		out << teamId << ENDOFLINE;
	}
	for( auto gameday : league.getSchedule())
	{
		out << std::get<0>(gameday) << ENDOFLINE;
		out << std::get<1>(gameday) << ENDOFLINE;
	}
}