#include "A3LegacyReader.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "CountryFactory.h"
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "ManagerFactory.h"
#include "TrainerFactory.h"
#include "StadiumFactory.h"
#include "RefereeFactory.h"
#include "SponsorFactory.h"
#include "CelebrityFactory.h"
#include "ReporterFactory.h"

void A3LegacyReader::loadFile(std::string filename)
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
	if (std::getline(stream, line))
	{
		if (line != "17373592")		// constant value for Anstoss 3 *.sav files
		{
			logger->writeErrorEntry("Unknown file type.");
			stream.close();
			return;
		}
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
	
	std::vector<Team> teams;
	std::vector<Player> player;

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

	while (std::getline(stream, line))
	{
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
			for (std::vector<Player>::iterator it = player.begin(); it != player.end(); ++it)
				team.addPlayer(*it);
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
		else if (line == "%SECT%REPORTER")
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
			Person p(criticsData[0], criticsData[1], "");
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
	
	//TODO add jugend spieler
	Country country = countryfactory.createFromSAV(countryData);
	country.setNationalTrainer(nationalTrainer);
	country.setPresident(president);
	country.setAmateurTeams(amateurClubData);
	country.setCoTrainer(coTrainer);
	country.setGoalKeeperTrainer(goalKeeperTrainer);
	country.setUnemployedManager(unemployedManager);
	country.setReferees(referees);
	country.setSponsors(sponsors);
	country.setCelebrity(celebrity);
	country.setReporter(reporter);
	country.setCritics(critics);

	logger->writeInfoEntry("Teams found: " + std::to_string(teams.size()));
	logger->writeInfoEntry("Players found: " + std::to_string(players));

	return;
}