#include "CompetitionFactory.h"
#include "globals.h"

using namespace Core;

Competition CompetitionFactory::create()
{
	return Competition();
}

Competition CompetitionFactory::createFromSAV(std::vector<std::vector<std::string>> dataCleague, 
											  std::vector<std::vector<std::string>> dataEM, 
											  std::vector<std::vector<std::string>> dataWM)
{
	Competition competition;

	if (dataCleague.empty())
	{
		logger->writeErrorEntry("CLeague data is empty.");
		return competition;
	}

	std::vector<std::vector<std::tuple<short, short>>> championsLeague;

	for (auto group : dataCleague)
	{
		std::vector<std::tuple<short, short>> cleagueGroup;

		for (int i = 2; i < group.size(); i+=2)
		{
			auto team = std::make_tuple(std::stoi(group.at(i)), std::stoi(group.at(i + 1)));
			cleagueGroup.push_back(team);
		}

		championsLeague.push_back(cleagueGroup);
	}

	std::vector<std::vector<std::tuple<short, short>>> em;

	for (auto group : dataEM)
	{
		std::vector<std::tuple<short, short>> emGroup;

		for (int i = 2; i < group.size(); i += 2)
		{
			auto team = std::make_tuple(std::stoi(group.at(i)), std::stoi(group.at(i + 1)));
			emGroup.push_back(team);
		}

		em.push_back(emGroup);
	}

	std::vector<std::vector<std::tuple<short, short>>> wm;

	for (auto group : dataWM)
	{
		std::vector<std::tuple<short, short>> wmGroup;

		for (int i = 2; i < group.size(); i += 2)
		{
			auto team = std::make_tuple(std::stoi(group.at(i)), std::stoi(group.at(i + 1)));
			wmGroup.push_back(team);
		}

		wm.push_back(wmGroup);
	}

	competition.setChampionsLeague(championsLeague);
	competition.setEM(em);
	competition.setWM(wm);

	return competition;
}

void CompetitionFactory::writeToSAVCleague(Competition& competition, std::ofstream& out)
{
	auto cleague = competition.getChampionsLeague();

	out << cleague.size() << ENDOFLINE;
	int groupIndex = 1;
	for (auto group : cleague)
	{
		out << "%SECT%CLEAGUEGRP" << ENDOFLINE;
		out << groupIndex << ENDOFLINE;
		out << group.size() << ENDOFLINE;
		for (auto team : group)
		{
			out << std::get<0>(team) << ENDOFLINE;
			out << std::get<1>(team) << ENDOFLINE;
		}
		out << "%ENDSECT%CLEAGUEGRP" << ENDOFLINE;
		++groupIndex;
	}
}

void CompetitionFactory::writeToSAVEmwm(Competition& competition, std::ofstream& out)
{
	auto em = competition.getEM();

	out << "%SECT%EMGRP" << ENDOFLINE;
	out << em.size() << ENDOFLINE;
	for (auto group : em)
	{
		out << "%SECT%TURNIERGRP" << ENDOFLINE;
		out << "0" << ENDOFLINE;
		out << group.size() << ENDOFLINE;
		for (auto team : group)
		{
			out << std::get<0>(team) << ENDOFLINE;
			out << std::get<1>(team) << ENDOFLINE;
		}
		out << "%ENDSECT%TURNIERGRP" << ENDOFLINE;
	}
	out << "%ENDSECT%EMGRP" << ENDOFLINE;

	auto wm = competition.getWM();

	out << "%SECT%WMGRP" << ENDOFLINE;
	out << wm.size() << ENDOFLINE;
	for (auto group : wm)
	{
		out << "%SECT%TURNIERGRP" << ENDOFLINE;
		out << "0" << ENDOFLINE;
		out << group.size() << ENDOFLINE;
		for (auto team : group)
		{
			out << std::get<0>(team) << ENDOFLINE;
			out << std::get<1>(team) << ENDOFLINE;
		}
		out << "%ENDSECT%TURNIERGRP" << ENDOFLINE;
	}
	out << "%ENDSECT%WMGRP" << ENDOFLINE;
}