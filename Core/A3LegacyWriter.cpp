#include "A3LegacyWriter.h"
#include "globals.h"
#include <fstream>
#include <sstream>
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "StadiumFactory.h"
#include "ReporterFactory.h"
#include "CelebrityFactory.h"
#include "SponsorFactory.h"
#include "RefereeFactory.h"
#include "ManagerFactory.h"
#include "TrainerFactory.h"
#include "YouthPlayerFactory.h"
#include "NationFactory.h"
#include "EurowinnerFactory.h"

using namespace Core;

/*
 * export of individual country files for example LandDeut.sav
 */
void A3LegacyWriter::saveCountryFile(std::shared_ptr<Graph> graph, vertex_t countryId)
{
	auto country = graph->getCountryById(countryId);
	// only continue if it is a playable country, all not playable countries are stored in one file -> saveNotPlayableCountryFile
	if (!country->isPlayable())
	{
		return;
	}

	std::ofstream stream;
	std::string filename = country->getFilename();

#ifdef _DEBUG
	filename = filename.substr(0, filename.size() - 4) + "1" + filename.substr(filename.size() - 4, filename.size());
#endif

	stream.open(filename, std::ios::out);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while writing " + filename);
		stream.close();
		return;
	}

	// write file "header"
	stream << fileHeader << ENDOFLINE;

	// country
	stream << "%SECT%LAND" << ENDOFLINE;
	CountryFactory::writeToSAV(*country, stream);
	writeTeams(stream, graph, countryId);

	// amateur teams
	auto amateurTeams = country->getAmateurTeams();
	for (std::vector<std::string>::iterator it = amateurTeams.begin(); it < amateurTeams.end(); ++it)
	{
		stream << "%SECT%AMATEURV" << ENDOFLINE;
		stream << *it  << ENDOFLINE;
		stream << "%ENDSECT%AMATEURV" << ENDOFLINE;
	}
	
	// national trainer
	stream << "%SECT%TRAINER" << ENDOFLINE;
	auto nationalTrainer = country->getNationalTrainer();
	TrainerFactory::writeToSAV(nationalTrainer, stream);
	stream << "%ENDSECT%TRAINER" << ENDOFLINE;

	// youth player
	stream << "%SECT%AJUGEND" << ENDOFLINE;
	auto youthPlayer = country->getYouthPlayer();
	for (std::vector<YouthPlayer>::iterator it = youthPlayer.begin(); it < youthPlayer.end(); ++it)
	{
		YouthPlayerFactory::writeToSAV(*it, stream);
	}
	stream << "%ENDSECT%AJUGEND" << ENDOFLINE;

	// co-trainer
	stream << "%SECT%TRAINERP" << ENDOFLINE;
	auto coTrainer = country->getCoTrainer();
	for (std::vector<Trainer>::iterator it = coTrainer.begin(); it < coTrainer.end(); ++it)
	{
		stream << "%SECT%TRAINER" << ENDOFLINE;
		TrainerFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%TRAINER" << ENDOFLINE;
	}
	stream << "%ENDSECT%TRAINERP" << ENDOFLINE;

	// goalkeeper trainer
	stream << "%SECT%TWTRAINP" << ENDOFLINE;
	auto goalKeeperTrainer = country->getGoalKeeperTrainer();
	for (std::vector<Trainer>::iterator it = goalKeeperTrainer.begin(); it < goalKeeperTrainer.end(); ++it)
	{
		stream << "%SECT%TWTRAINER" << ENDOFLINE;
		TrainerFactory::writeToSAV(*it, stream, true);
		stream << "%ENDSECT%TWTRAINER" << ENDOFLINE;
	}
	stream << "%ENDSECT%TWTRAINP" << ENDOFLINE;

	// manager
	stream << "%SECT%MANAGERP" << ENDOFLINE;
	auto managers = country->getUnemployedManager();
	for (std::vector<Manager>::iterator it = managers.begin(); it < managers.end(); ++it)
	{
		stream << "%SECT%MANAGER" << ENDOFLINE;
		ManagerFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%MANAGER" << ENDOFLINE;
	}
	stream << "%ENDSECT%MANAGERP" << ENDOFLINE;

	// referee
	stream << "%SECT%SCHIRIP" << ENDOFLINE;
	auto referees = country->getReferees();
	for (std::vector<Referee>::iterator it = referees.begin(); it < referees.end(); ++it)
	{
		stream << "%SECT%SCHIRI" << ENDOFLINE;
		RefereeFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%SCHIRI" << ENDOFLINE;
	}
	stream << "%ENDSECT%SCHIRIP" << ENDOFLINE;

	// sponsor
	stream << "%SECT%SPONSORP" << ENDOFLINE;
	auto sponsors = country->getSponsors();
	for (std::vector<Sponsor>::iterator it = sponsors.begin(); it < sponsors.end(); ++it)
	{
		stream << "%SECT%SPONSOR" << ENDOFLINE;
		SponsorFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%SPONSOR" << ENDOFLINE;
	}
	stream << "%ENDSECT%SPONSORP" << ENDOFLINE;


	// celebrity
	stream << "%SECT%PROMIP" << ENDOFLINE;
	auto celebrities = country->getCelebrities();
	for (std::vector<Celebrity>::iterator it = celebrities.begin(); it < celebrities.end(); ++it)
	{
		stream << "%SECT%PROMI" << ENDOFLINE;
		CelebrityFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%PROMI" << ENDOFLINE;
	}
	stream << "%ENDSECT%PROMIP" << ENDOFLINE;

	// reporter
	stream << "%SECT%MEDIAP" << ENDOFLINE;
	auto reporter = country->getReporter();
	for (std::vector<Reporter>::iterator it = reporter.begin(); it < reporter.end(); ++it)
	{
		stream << "%SECT%REPORTER" << ENDOFLINE;
		ReporterFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%REPORTER" << ENDOFLINE;
	}
	
	stream << "%ENDSECT%MEDIAP" << ENDOFLINE;

	// critics
	stream << "%SECT%KRITIP" << ENDOFLINE;
	auto critics = country->getCritics();
	for (std::vector<Person>::iterator it = critics.begin(); it < critics.end(); ++it)
	{
		stream << "%SECT%KRITIKER" << ENDOFLINE;
		writePerson(*it, stream, false, false);
		stream << "%ENDSECT%KRITIKER" << ENDOFLINE;
	}
	stream << "%ENDSECT%KRITIP" << ENDOFLINE;

	// president
	stream << "%SECT%VPRAESID" << ENDOFLINE;
	Person president = country->getPresident();
	writePerson(president, stream);
	stream << "%ENDSECT%VPRAESID" << ENDOFLINE;

	stream << "%ENDSECT%LAND" << ENDOFLINE;

	stream.flush();
	stream.close();

	return;
}

/*
 * export of nations file Laender.sav
 */
void A3LegacyWriter::saveNationFile(std::shared_ptr<Graph> graph, std::string filename)
{
	std::ofstream stream;

#ifdef _DEBUG
	filename = filename.substr(0, filename.size() - 4) + "1" + filename.substr(filename.size() - 4, filename.size());
#endif

	stream.open(filename, std::ios::out);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while writing " + filename);
		stream.close();
		return;
	}

	// write file "header"
	stream << fileHeader << ENDOFLINE;
	stream << "%SECT%NATION" << ENDOFLINE;

	auto nations = graph->getNationIds();
	for (std::vector<vertex_t>::iterator it = nations.begin(); it < nations.end(); ++it)
	{
		stream << "%SECT%NATION" << ENDOFLINE;
		auto nation = graph->getNationById(*it);
		NationFactory::writeToSAV(*nation, stream);
		stream << "%ENDSECT%NATION" << ENDOFLINE;
	}

	stream << "%ENDSECT%NATION" << ENDOFLINE;

	stream.flush();
	stream.close();

	return;
}

/*
 * export of not playable countries to one file Internat.sav
 */
void A3LegacyWriter::saveNotPlayableCountryFile(std::shared_ptr<Graph> graph, std::string filename)
{
	std::ofstream stream;

#ifdef _DEBUG
	filename = filename.substr(0, filename.size() - 4) + "1" + filename.substr(filename.size() - 4, filename.size());
#endif

	stream.open(filename, std::ios::out);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while writing " + filename);
		stream.close();
		return;
	}

	// write file "header"
	stream << fileHeader << ENDOFLINE;

	auto countries = graph->getCountryIds();
	for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
	{
		auto country = graph->getCountryById(*it);
		// skip all playable countries, they are stored in separate files -> saveCountryFile
		if (country->isPlayable())
		{
			continue;
		}

		stream << "%SECT%LAND" << ENDOFLINE;
		writeTeams(stream, graph, *it);
		// national trainer
		stream << "%SECT%TRAINER" << ENDOFLINE;
		auto nationalTrainer = country->getNationalTrainer();
		TrainerFactory::writeToSAV(nationalTrainer, stream);
		stream << "%ENDSECT%TRAINER" << ENDOFLINE;
		stream << "%ENDSECT%LAND" << ENDOFLINE;
	}
	
	stream << "%SECT%EUROSIEGER" << ENDOFLINE;
	auto eurowinner = graph->getEurowinner();
	EurowinnerFactory::writeToSAV(*eurowinner, stream);
	stream << "%ENDSECT%EUROSIEGER" << ENDOFLINE;

	stream.flush();
	stream.close();

	return;
}


void A3LegacyWriter::writeTeams(std::ofstream& out, std::shared_ptr<Graph> graph, vertex_t countryId)
{
	// team
	auto teams = graph->getTeamIdsByCountry(countryId);
	for (std::vector<vertex_t>::iterator it = teams.begin(); it < teams.end(); ++it)
	{
		auto team = graph->getTeamById(*it);
		out << "%SECT%VEREIN" << ENDOFLINE;
		TeamFactory::writeToSAV(*team, out);

		// player
		auto players = graph->getPlayerIdsByTeam(*it);
		for (std::vector<vertex_t>::iterator itp = players.begin(); itp < players.end(); ++itp)
		{
			auto player = graph->getPlayerById(*itp);
			out << "%SECT%SPIELER" << ENDOFLINE;
			PlayerFactory::writeToSAV(*player, out);
			out << "%ENDSECT%SPIELER" << ENDOFLINE;
		}
		out << "%ENDSECT%VEREIN" << ENDOFLINE;

		// stadium
		out << "%SECT%STADION" << ENDOFLINE;
		Stadium s = team->getStadium();
		StadiumFactory::writeToSAV(s, out);
		out << "%ENDSECT%STADION" << ENDOFLINE;
	}
}

void A3LegacyWriter::writePerson(Person& p, std::ofstream& out, bool birthday, bool firstnameFirst)
{
	if(firstnameFirst)
		out << p.getFirstname() << ENDOFLINE;
	out << p.getLastname() << ENDOFLINE;
	if(!firstnameFirst)
		out << p.getFirstname() << ENDOFLINE;
	if(birthday)
		out << p.getBirthday() << ENDOFLINE;
}