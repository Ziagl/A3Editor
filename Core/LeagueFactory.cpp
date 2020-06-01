#include "LeagueFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

League LeagueFactory::create()
{
	return League();
}

League LeagueFactory::createFromSAV(std::vector<std::string> data)
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
	league.setUnknown1(std::stoi(data[3]));
	league.setUnknown2(std::stoi(data[4]));
	league.setUnknown3(std::stoi(data[5]));
	league.setUnknown4(std::stoi(data[6]));
	league.setUnknown5(std::stoi(data[7]));
	league.setUnknown6(std::stoi(data[8]));
	league.setUnknown7(std::stoi(data[9]));
	league.setUnknown8(std::stoi(data[10]));
	league.setUnknown9(std::stoi(data[11]));
	league.setUnknown10(std::stoi(data[12]));
	std::vector<std::tuple<short, short>> schedule;
	for (int i = 13; i < data.size(); i += 2)
	{
		std::tuple<short, short> gameday = std::make_tuple(std::stoi(data[i]), std::stoi(data[i + 1]));
		schedule.push_back(gameday);
	}
	league.setSchedule(schedule);

	return league;
}

void LeagueFactory::writeToSAV(League& league, std::ofstream& out)
{
	out << league.getName() << ENDOFLINE;
	out << league.getShortname() << ENDOFLINE;
	out << league.getTeamNumber() << ENDOFLINE;
	out << league.getUnknown1() << ENDOFLINE;
	out << league.getUnknown2() << ENDOFLINE;
	out << league.getUnknown3() << ENDOFLINE;
	out << league.getUnknown4() << ENDOFLINE;
	out << league.getUnknown5() << ENDOFLINE;
	out << league.getUnknown6() << ENDOFLINE;
	out << league.getUnknown7() << ENDOFLINE;
	out << league.getUnknown8() << ENDOFLINE;
	out << league.getUnknown9() << ENDOFLINE;
	out << league.getUnknown10() << ENDOFLINE;
	for( auto gameday : league.getSchedule())
	{
		out << std::get<0>(gameday) << ENDOFLINE;
		out << std::get<1>(gameday) << ENDOFLINE;
	}
}