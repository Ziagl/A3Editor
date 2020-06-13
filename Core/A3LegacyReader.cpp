#include "A3LegacyReader.h"
#include <sstream>
#include <vector>
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "ManagerFactory.h"
#include "TrainerFactory.h"
#include "StadiumFactory.h"
#include "RefereeFactory.h"
#include "SponsorFactory.h"
#include "CelebrityFactory.h"
#include "ReporterFactory.h"
#include "YouthPlayerFactory.h"
#include "NationFactory.h"
#include "EurowinnerFactory.h"
#include "LeagueFactory.h"
#include "UefaRankingFactory.h"
#include "InternationalFactory.h"

using namespace Core;

std::shared_ptr<Country> Core::A3LegacyReader::loadCountryFile(std::shared_ptr<Core::Graph> graph, std::string filename)
{
	std::ifstream stream;
	std::string line;

	stream.open(filename, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filename);
		stream.close();
		return nullptr;
	}

	// test if file is valid
	std::getline(stream, line);
	line = fixLineEnding(line);
    if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
    {
        logger->writeErrorEntry("Unknown file type.");
        stream.close();
        return nullptr;
    }
	
	int players = 0;
	int type = 0;

	std::vector<std::string> countryData;
	std::vector<std::string> teamData;
	std::vector<std::string> trainerData;
	std::vector<std::string> managerData;
	std::vector<std::string> playerData;
	std::vector<std::string> stadiumData;
	std::vector<std::string> amateurClubData;
	std::vector<std::string> youthPlayerData;
	std::vector<std::string> refereeData;
	std::vector<std::string> sponsorData;
	std::vector<std::string> celebrityData;
	std::vector<std::string> reporterData;
	std::vector<std::string> criticsData;

	CountryFactory countryfactory(logger);
	TeamFactory teamfactory(logger);
	ManagerFactory managerfactory(logger);
	PlayerFactory playerfactory(logger);
	TrainerFactory trainerfactory(logger);
	StadiumFactory stadiumfactory(logger);
	RefereeFactory refereefactory(logger);
	SponsorFactory sponsorfactory(logger);
	CelebrityFactory celebrityfactory(logger);
	ReporterFactory reporterfactory(logger);
	YouthPlayerFactory youthplayerfactory(logger);
	
	std::vector<Team> teams;
	std::vector<Player> player;
	std::vector<std::vector<Player>> allPlayer;

	Trainer nationalTrainer;
	Person president;
	bool coTrainerFlag = false;
	bool unemployedManagerFlag = false;
	std::vector<Trainer> coTrainer;
	std::vector<Trainer> goalKeeperTrainer;
	std::vector<Manager> unemployedManager;
	std::vector<Referee> referees;
	std::vector<Sponsor> sponsors;
	std::vector<Celebrity> celebrity;
	std::vector<Reporter> reporter;
	std::vector<Person> critics;
	std::vector<YouthPlayer> youthPlayer;

	int lastTeamId = 0;

    // read first line
	while (std::getline(stream, line))
	{
		line = fixLineEnding(line);
		if (line == "%SECT%LAND")
		{
			type = 1;
			continue;
		}
		else if (line == "%SECT%VEREIN")
		{
			type = 2;
			continue;
		}
		else if (line == "%ENDSECT%VEREIN")
		{
			type = 1;
		}
		else if (line == "%SECT%TRAINER")
		{
			type = 3;
			continue;
		}
		else if (line == "%ENDSECT%TRAINER")
		{
			if (coTrainerFlag)
			{
				Trainer t = trainerfactory.createFromSAV(trainerData);
				coTrainer.push_back(t);
				trainerData.clear();
			}
			else
			{
				type = 2;
			}
		}
		else if (line == "%SECT%MANAGER")
		{
			type = 4;
			continue;
		}
		else if (line == "%ENDSECT%MANAGER")
		{
			if (unemployedManagerFlag)
			{
				Manager m = managerfactory.createFromSAV(managerData);
				unemployedManager.push_back(m);
				managerData.clear();
			}
			else
			{
				type = 2;
			}
		}
		else if (line == "%SECT%SPIELER")
		{
			type = 5;
			continue;
		}
		else if (line == "%ENDSECT%SPIELER")
		{
			type = 2;
			Player p = playerfactory.createFromSAV(playerData);
			player.push_back(p);
			playerData.clear();
			players++;
		}
		else if (line == "%SECT%STADION")
		{
			type = 6;
			continue;
		}
		else if (line == "%ENDSECT%STADION")
		{
			// end stadion is last step of one team
			// we should now have x players, 1 manager, 1 trainer, 1 stadium
			Manager m = managerfactory.createFromSAV(managerData);
			managerData.clear();

			Trainer t = trainerfactory.createFromSAV(trainerData);
			trainerData.clear();

			Stadium s = stadiumfactory.createFromSAV(stadiumData);
			stadiumData.clear();

			Team team = teamfactory.createFromSAV(teamData);
			team.setManager(m);
			team.setTrainer(t);
			team.setStadium(s);
			team.setTeamId(++lastTeamId);
			std::vector<Player> players;
			for (std::vector<Player>::iterator it = player.begin(); it != player.end(); ++it)
				players.push_back(*it);
			allPlayer.push_back(players);
			player.clear();
			teams.push_back(team);
			teamData.clear();
		}
		else if (line == "%SECT%AMATEURV")
		{
			type = 7;
		}
		else if (line == "%ENDSECT%AMATEURV")
		{
			type = 0;
		}
		else if (line == "%SECT%AJUGEND")
		{
			type = 8;
		}
		else if (line == "%ENDSECT%AJUGEND")
		{
			for (int i = 0; i < youthPlayerData.size(); i+=4)
			{
				std::vector<std::string> tempData;
				tempData.push_back(youthPlayerData[i]);
				tempData.push_back(youthPlayerData[i+1]);
				tempData.push_back(youthPlayerData[i+2]);
				tempData.push_back(youthPlayerData[i+3]);
				YouthPlayer yp = youthplayerfactory.createFromSAV(tempData);
				youthPlayer.push_back(yp);
			}
			youthPlayerData.clear();
			type = 0;
		}
		else if (line == "%SECT%TRAINERP")
		{
			nationalTrainer = trainerfactory.createFromSAV(trainerData);
			trainerData.clear();
			coTrainerFlag = true;
			continue;
		}
		else if (line == "%ENDSECT%TRAINERP")
		{
			continue;
		}
		else if (line == "%SECT%TWTRAINP")
		{
			continue;
		}
		else if (line == "%ENDSECT%TWTRAINP")
		{
			continue;
		}
		else if (line == "%SECT%TWTRAINER")
		{
			type = 9;
			continue;
		}
		else if (line == "%ENDSECT%TWTRAINER")
		{
			Trainer t = trainerfactory.createFromSAV(trainerData);
			goalKeeperTrainer.push_back(t);
			trainerData.clear();
			continue;
		}
		else if (line == "%SECT%MANAGERP")
		{
			unemployedManagerFlag = true;
			continue;
		}
		else if (line == "%ENDSECT%MANAGERP")
		{
			continue;
		}
		else if (line == "%SECT%SCHIRIP")
		{
			continue;
		}
		else if (line == "%ENDSECT%SCHIRIP")
		{
			continue;
		}
		else if (line == "%SECT%SCHIRI")
		{
			type = 10;
			continue;
		}
		else if (line == "%ENDSECT%SCHIRI")
		{
			Referee r = refereefactory.createFromSAV(refereeData);
			referees.push_back(r);
			refereeData.clear();
			continue;
		}
		else if (line == "%SECT%SPONSORP")
		{
			continue;
		}
		else if (line == "%ENDSECT%SPONSORP")
		{
			continue;
		}
		else if (line == "%SECT%SPONSOR")
		{
			type = 11;
			continue;
		}
		else if (line == "%ENDSECT%SPONSOR")
		{
			Sponsor s = sponsorfactory.createFromSAV(sponsorData);
			sponsors.push_back(s);
			sponsorData.clear();
			continue;
		}
		else if (line == "%SECT%PROMIP")
		{
			continue;
		}
		else if (line == "%ENDSECT%PROMIP")
		{
			continue;
		}
		else if (line == "%SECT%PROMI")
		{
			type = 12;
			continue;
		}
		else if (line == "%ENDSECT%PROMI")
		{
			Celebrity c = celebrityfactory.createFromSAV(celebrityData);
			celebrity.push_back(c);
			celebrityData.clear();
			continue;
		}
		else if (line == "%SECT%MEDIAP")
		{
			continue;
		}
		else if (line == "%ENDSECT%MEDIAP")
		{
			continue;
		}
		else if (line == "%SECT%REPORTER")
		{
			type = 13;
			continue;

		}
		else if (line == "%ENDSECT%REPORTER")
		{
			Reporter r = reporterfactory.createFromSAV(reporterData);
			reporter.push_back(r);
			reporterData.clear();
			continue;
		}
		else if (line == "%SECT%KRITIP")
		{
			continue;
		}
		else if (line == "%ENDSECT%KRITIP")
		{
			continue;
		}
		else if (line == "%SECT%KRITIKER")
		{
			type = 14;
			continue;
		}
		else if (line == "%ENDSECT%KRITIKER")
		{
			Person p(criticsData[1], criticsData[0], "");
			critics.push_back(p);
			criticsData.clear();
			continue;
		}
		else if (line == "%SECT%VPRAESID")
		{
			type = 15;
			continue;
		}
		else if (line == "%ENDSECT%VPRAESID")
		{
			president = { managerData[0], managerData[1], managerData[2] };
			managerData.clear();
			continue;
		}
		else
		{
			switch (type)
			{
				// LAND
				case 1:
					countryData.push_back(line);
					break;
				// VEREIN
				case 2:
					teamData.push_back(line);
					break;
				// TRAINER
				case 3:
					trainerData.push_back(line);
					break;
				// MANAGER
				case 4:
					managerData.push_back(line);
					break;
				// SPIELER
				case 5:
					playerData.push_back(line);
					break;
				// STADION
				case 6:
					stadiumData.push_back(line);
					break;
				// AMATEURV
				case 7:
					amateurClubData.push_back(line);
					break;
				// AJUGEND
				case 8:
					youthPlayerData.push_back(line);
					break;
				// TWTRAINER
				case 9:
					trainerData.push_back(line);
					break;
				// SCHIRI
				case 10:
					refereeData.push_back(line);
					break;
				// SPONSOR
				case 11:
					sponsorData.push_back(line);
					break;
				// PROMI
				case 12:
					celebrityData.push_back(line);
					break;
				// REPORTER
				case 13:
					reporterData.push_back(line);
					break;
				// KRITIKER
				case 14:
					criticsData.push_back(line);
					break;
				// VPRAESID
				case 15:
					managerData.push_back(line);
					break;
			}
		}
	}
	
	stream.close();
	// game data
	std::shared_ptr<Country> country = std::make_shared<Country>(countryfactory.createFromSAV(countryData, filename, true));
	country->setNationalTrainer(nationalTrainer);
	country->setPresident(president);
	country->setAmateurTeams(amateurClubData);
	country->setCoTrainer(coTrainer);
	country->setGoalKeeperTrainer(goalKeeperTrainer);
	country->setUnemployedManager(unemployedManager);
	country->setReferees(referees);
	country->setSponsors(sponsors);
	country->setCelebrity(celebrity);
	country->setReporter(reporter);
	country->setCritics(critics);
	country->setYouthPlayer(youthPlayer);
	
	logger->writeInfoEntry("Teams found: " + std::to_string(teams.size()));
	logger->writeInfoEntry("Players found: " + std::to_string(players));

	// makes graph insertion thread safe
	std::lock_guard<std::mutex> lockguard(mutex);

	// find corresponding Nation in graph
	vertex_t nationId = -1;
	if (teams.size() > 0)
		nationId = graph->getNationIdByIndex(teams[0].getCountryId());
	
	// add data into graph structure
	auto graphCountryId = graph->addCountry(country, nationId);	// add country
	int i = 0;
	for (std::vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it)
	{
		auto t = std::make_shared<Team>(*it);
		auto graphTeamId = graph->addTeam(t, graphCountryId, nationId);	// add team
		
		auto tempPlayers = allPlayer[i++];
		for (std::vector<Player>::iterator itPlayer = tempPlayers.begin(); itPlayer != tempPlayers.end(); ++itPlayer)
		{
			auto p = std::make_shared<Player>(*itPlayer);
			graph->addPlayer(p, graphTeamId);	// add player
		}
	}

	return country;
}

void A3LegacyReader::loadNationFile(std::shared_ptr<Graph> graph, std::string filename)
{
	std::ifstream stream;
	std::string line;

	stream.open(filename, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filename);
		stream.close();
		return;
	}

	// test if file is valid
    std::getline(stream, line);
	line = fixLineEnding(line);
    if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
    {
        logger->writeErrorEntry("Unknown file type.");
        stream.close();
        return;
    }

	NationFactory nationfactory(logger);
	std::vector<std::string> nationData;
	std::vector<Nation> nations;
	short countryId = 0;

	while (std::getline(stream, line))
	{
		line = fixLineEnding(line);
		if (line == "%SECT%NATION")
		{
			continue;
		}
		else if (line == "%ENDSECT%NATION")
		{
			if (nationData.size() > 0)
			{
				Nation nation = nationfactory.createFromSAV(nationData);
				nation.setCountryId(countryId++);
				nations.push_back(nation);
				nationData.clear();
			}
		}
		else 
		{
			nationData.push_back(line);
		}
	}

	stream.close();

	// makes graph insertion thread safe
	std::lock_guard<std::mutex> lockguard(mutex);

	for (std::vector<Nation>::iterator it = nations.begin(); it < nations.end(); ++it)
	{
		auto nation = std::make_shared<Nation>(*it);
		graph->addNation(nation);
	}
}

void A3LegacyReader::loadNotPlayableCountryFile(std::shared_ptr<Graph> graph, std::string filename)
{
	std::ifstream stream;
	std::string line;

	stream.open(filename, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filename);
		stream.close();
		return;
	}

	// test if file is valid
	std::getline(stream, line);
	line = fixLineEnding(line);
	if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
	{
		logger->writeErrorEntry("Unknown file type.");
		stream.close();
		return;
	}

	int players = 0;
	int type = 0;

	std::vector<std::string> countryData;
	std::vector<std::string> teamData;
	std::vector<std::string> trainerData;
	std::vector<std::string> managerData;
	std::vector<std::string> playerData;
	std::vector<std::string> stadiumData;
	std::vector<std::string> eurowinnerData;

	CountryFactory countryfactory(logger);
	TeamFactory teamfactory(logger);
	ManagerFactory managerfactory(logger);
	PlayerFactory playerfactory(logger);
	TrainerFactory trainerfactory(logger);
	StadiumFactory stadiumfactory(logger);
	EurowinnerFactory eurowinnerfactory(logger);

	std::vector<Team> teams;
	std::vector<Player> player;
	std::vector<std::vector<Player>> allPlayer;

	while (std::getline(stream,line))
	{
		line = fixLineEnding(line);

		if (line == "%SECT%LAND")
		{
			type = 1;
			continue;
		}
		else if (line == "%ENDSECT%LAND")
		{
			type = 1;
			Country country = countryfactory.createFromSAV(countryData, filename, false);

			// add national trainer
			auto nationalTrainer = trainerfactory.createFromSAV(trainerData);
			country.setNationalTrainer(nationalTrainer);

			// makes graph insertion thread safe
			std::lock_guard<std::mutex> lockguard(mutex);

			// find corresponding Nation in graph
			vertex_t nationId = -1;
			if (teams.size() > 0)
			{
				nationId = graph->getNationIdByIndex(teams[0].getCountryId());
				logger->writeInfoEntry("Country " + std::to_string(teams[0].getCountryId()));
			}
			logger->writeInfoEntry("Teams found: " + std::to_string(teams.size()));
			logger->writeInfoEntry("Players found: " + std::to_string(players));

			// add data into graph structure
			auto graphCountryId = graph->addCountry(std::make_shared<Country>(country), nationId);	// add country
			int i = 0;
			
			for (std::vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it)
			{
				auto t = std::make_shared<Team>(*it);
				auto graphTeamId = graph->addTeam(t, graphCountryId, nationId);	// add team

				auto tempPlayers = allPlayer[i++];
				for (std::vector<Player>::iterator itPlayer = tempPlayers.begin(); itPlayer != tempPlayers.end(); ++itPlayer)
				{
					auto p = std::make_shared<Player>(*itPlayer);
					graph->addPlayer(p, graphTeamId);	// add player
				}
			}

			teams.clear();
			player.clear();
			countryData.clear();
			teamData.clear();
			trainerData.clear();
			managerData.clear();
			playerData.clear();
			stadiumData.clear();
			allPlayer.clear();
			continue;
		}
		else if (line == "%SECT%VEREIN")
		{
			type = 2;
			continue;
		}
		else if (line == "%ENDSECT%VEREIN")
		{
			type = 1;
		}
		else if (line == "%SECT%TRAINER")
		{
			type = 3;
			continue;
		}
		else if (line == "%ENDSECT%TRAINER")
		{
			type = 2;
		}
		else if (line == "%SECT%MANAGER")
		{
			type = 4;
			continue;
		}
		else if (line == "%ENDSECT%MANAGER")
		{
			type = 2;
		}
		else if (line == "%SECT%SPIELER")
		{
			type = 5;
			continue;
		}
		else if (line == "%ENDSECT%SPIELER")
		{
			type = 2;
			Player p = playerfactory.createFromSAV(playerData);
			player.push_back(p);
			playerData.clear();
			players++;
		}
		else if (line == "%SECT%STADION")
		{
			type = 6;
			continue;
		}
		else if (line == "%ENDSECT%STADION")
		{
			// end stadion is last step of one team
			// we should now have x players, 1 manager, 1 trainer, 1 stadium
			Manager m = managerfactory.createFromSAV(managerData);
			managerData.clear();

			Trainer t = trainerfactory.createFromSAV(trainerData);
			trainerData.clear();

			Stadium s = stadiumfactory.createFromSAV(stadiumData);
			stadiumData.clear();

			Team team = teamfactory.createFromSAV(teamData);
			team.setManager(m);
			team.setTrainer(t);
			team.setStadium(s);
			std::vector<Player> players;
			for (std::vector<Player>::iterator it = player.begin(); it != player.end(); ++it)
				players.push_back(*it);
			allPlayer.push_back(players);
			player.clear();
			teams.push_back(team);
			teamData.clear();
		}
		else if (line == "%SECT%EUROSIEGER")
		{
			type = 7;
			continue;
		}
		else if (line == "%ENDSECT%EUROSIEGER")
		{
			auto eurowinner = eurowinnerfactory.createFromSAV(eurowinnerData);
			graph->addEurowinner(std::make_shared<Eurowinner>(eurowinner));
		}
		else
		{
			switch (type)
			{
				// LAND
			case 1:
				countryData.push_back(line);
				break;
				// VEREIN
			case 2:
				teamData.push_back(line);
				break;
				// TRAINER
			case 3:
				trainerData.push_back(line);
				break;
				// MANAGER
			case 4:
				managerData.push_back(line);
				break;
				// SPIELER
			case 5:
				playerData.push_back(line);
				break;
				// STADION
			case 6:
				stadiumData.push_back(line);
				break;
				// EUROSIEGER
			case 7:
				eurowinnerData.push_back(line);
				break;
			}
		}
	}
	
	stream.close();
}

void A3LegacyReader::loadLeagueFile(std::shared_ptr<Graph> graph, vertex_t countryId, std::string filename, short hierarchy)
{
	std::ifstream stream;
	std::string line;

	stream.open(filename, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filename);
		stream.close();
		return;
	}

	// test if file is valid
	std::getline(stream, line);
	line = fixLineEnding(line);
	if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
	{
		logger->writeErrorEntry("Unknown file type.");
		stream.close();
		return;
	}

	LeagueFactory leaguefactory(logger);
	std::vector<std::string> leagueData;
	std::vector<League> leagues;

	while (std::getline(stream, line))
	{
		line = fixLineEnding(line);
		if (line == "%SECT%LIGA")
		{
			continue;
		}
		else if (line == "%ENDSECT%LIGA")
		{
			if (leagueData.size() > 0)
			{
				League league = leaguefactory.createFromSAV(leagueData, filename, hierarchy);
				leagues.push_back(league);
				leagueData.clear();
			}
		}
		else
		{
			leagueData.push_back(line);
		}
	}

	stream.close();

	// makes graph insertion thread safe
	std::lock_guard<std::mutex> lockguard(mutex);

	for (std::vector<League>::iterator it = leagues.begin(); it < leagues.end(); ++it)
	{
		auto league = std::make_shared<League>(*it);
		graph->addLeague(league, countryId);
	}
}

void A3LegacyReader::loadAdditionalFile(std::shared_ptr<Graph> graph, std::string filename)
{
	std::ifstream stream;
	std::string line;

	stream.open(filename, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filename);
		stream.close();
		return;
	}

	// test if file is valid
	std::getline(stream, line);
	line = fixLineEnding(line);
	if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
	{
		logger->writeErrorEntry("Unknown file type.");
		stream.close();
		return;
	}

	int type = 0;

	std::vector<std::string> miscData;
	std::vector<std::string> uefaData;

	UefaRankingFactory uefaRankingFactory(logger);

	while (std::getline(stream, line))
	{
		line = fixLineEnding(line);
		if (line == "%SECT%MISC")
		{
			type = 1;
			continue;
		}
		else if (line == "%ENDSECT%MISC")
		{
			type = 0;
			continue;
		}
		else if (line == "%SECT%UEFA")
		{
			type = 2;
			continue;
		}
		else if (line == "%ENDSECT%UEFA")
		{
			type = 1;
			continue;
		}
		else
		{
			switch (type)
			{
			case 0:
				break;
				//MISC
			case 1:
				miscData.push_back(line);
				break;
				//UEFA
			case 2:
				uefaData.push_back(line);
				break;
			}
		}
	}

	stream.close();
	
	// uefaData --> 39x (NationId + 6 years) the order depends on desc sorted list of points, last 2 nations are ENG and BRA in original data and are ignored
	auto uefaRanking = uefaRankingFactory.createFromSAV(uefaData, 39, 6);

	// makes graph insertion thread safe
	std::lock_guard<std::mutex> lockguard(mutex);

	graph->addUefaRanking(std::make_shared<UefaRanking>(uefaRanking));

	//			--> 38x association name	11 playable countries (+1 bonus) and 26 countries -> 38
	//			#### TODO #### very bad data design!
	//			--> association names are in this order:
	/*	GER
		ENG
		FRA
		ITA
		ESP
		POR
		HOL
		TUR
		AUT
		SCO
		SUI*/
	//			--> all other 27 lines are in an unknown order
	int index = 272;
	std::vector<std::string> playableCountries = { "GER", "ENG", "FRA", "ITA", "ESP", "POR", "HOL", "TUR", "AUT", "SCO", "SUI" };
	for (auto shortname : playableCountries)
	{
		++index;
		auto countryId = graph->getCountryIdByShortname(shortname);
		// should only happen in debug mode
		if (countryId == 0)
			continue;
		auto country = graph->getCountryById(countryId);
		std::string name = uefaData.at(index);
		country->setAssociationName(name);
	}
	auto nonPlayableCountries = graph->getCountriesWithLeagues();
	for (auto countryIdTuple : nonPlayableCountries)
	{
		auto country = graph->getCountryById(std::get<0>(countryIdTuple));
		auto nation = graph->getNationById(std::get<1>(countryIdTuple));
		// if this country is one of playable countries, skip
		if (std::find(playableCountries.begin(), playableCountries.end(), nation->getShortname()) != playableCountries.end())
			continue;
		country->setAssociationName(uefaData.at(index++));
	}
}

void A3LegacyReader::loadInternationalFiles(std::shared_ptr<Graph> graph, std::string filenameTeams, std::string filenameReferees)
{
	std::ifstream stream;
	std::string line;
	InternationalFactory internationalfactory(logger);
	RefereeFactory refereefactory(logger);
	std::vector<std::string> teamsData;
	std::vector<std::string> refereeData;
	std::vector<Referee> referees;

	////////////////////////////////////////////////////////////////////////
	// load teams
	////////////////////////////////////////////////////////////////////////
	stream.open(filenameTeams, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filenameTeams);
		stream.close();
		return;
	}

	// test if file is valid
	std::getline(stream, line);
	line = fixLineEnding(line);
	if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
	{
		logger->writeErrorEntry("Unknown file type.");
		stream.close();
		return;
	}

	while (std::getline(stream, line))
	{
		line = fixLineEnding(line);
		if (line == "%SECT%IVEREINE" || line == "%SECT%IVEREIN" ||
			line == "%ENDSECT%IVEREINE" || line == "%ENDSECT%IVEREIN")
		{
			continue;
		}
		else
		{
			teamsData.push_back(line);
		}
	}

	stream.close();


	////////////////////////////////////////////////////////////////////////
	// load referees
	////////////////////////////////////////////////////////////////////////
	stream.open(filenameReferees, std::ios::in);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filenameReferees);
		stream.close();
		return;
	}

	// test if file is valid
	std::getline(stream, line);
	line = fixLineEnding(line);
	if (line != fileHeader)		// constant value for Anstoss 3 *.sav files
	{
		logger->writeErrorEntry("Unknown file type.");
		stream.close();
		return;
	}

	int counter = 0;

	while (std::getline(stream, line))
	{
		line = fixLineEnding(line);
		if (line == "%SECT%ISCHIRI" || line == "%ENDSECT%ISCHIRI")
		{
			continue;
		}
		else
		{
			refereeData.push_back(line);
			counter++;
			if (counter == 6)
			{
				Referee referee = refereefactory.createFromSAV(refereeData);
				referees.push_back(referee);
				refereeData.clear();
				counter = 0;
			}
		}
	}

	stream.close();

	International international = internationalfactory.createFromSAV(teamsData, referees);

	// makes graph insertion thread safe
	std::lock_guard<std::mutex> lockguard(mutex);

	graph->addInternational(std::make_shared<International>(international));
}

/*
 * this method fixes \r\n vs \n line ending conflicts from Windows and Linux
 */
std::string A3LegacyReader::fixLineEnding(std::string line)
{
#ifdef __LINUX__
	// fix \r problem for linux
	if (line[line.size() - 1] == '\r')
	{
		return line.substr(0, line.size() - 1);
	}
#else
	return line;
#endif
}