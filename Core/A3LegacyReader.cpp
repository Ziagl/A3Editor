#include "A3LegacyReader.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "Country.h"
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "ManagerFactory.h"
#include "TrainerFactory.h"
#include "StadiumFactory.h"

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

	TeamFactory teamfactory(logger);
	ManagerFactory managerfactory(logger);
	PlayerFactory playerfactory(logger);
	TrainerFactory trainerfactory(logger);
	StadiumFactory stadiumfactory(logger);
	std::vector<Team> teams;
	std::vector<Player> player;

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
			for (std::vector<Player>::iterator it = player.begin(); it != player.end(); ++it)
				team.addPlayer(*it);
			player.clear();
			teams.push_back(team);
			teamData.clear();
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
			}
		}
		
	}
	
	Country c(countryData[0], std::stoi(countryData[2]), std::stoi(countryData[1]), std::stoi(countryData[3]), std::stoi(countryData[4]), std::stoi(countryData[5]));

	stream.close();

	logger->writeInfoEntry("Teams found: " + std::to_string(teams.size()));
	logger->writeInfoEntry("Players found: " + std::to_string(players));

	return;
}