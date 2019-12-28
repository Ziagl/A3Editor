#pragma once

#include <string>

class Team 
{
public:
	Team() {};
	~Team() {};
private:
	std::string name;
	std::string shortName;
	std::string shortNamePrefix;
	std::string accentuation;
	std::string fanLabel;

	std::string chairmanFirstName;
	std::string chairmanLastName;
	time_t chairmanBirthday;

	short homeShirtColorFirst;
	short homeShirtColorSecond;
	short homeShirtPattern;
	short homeShirtTrousersColor;
	short homeShirtSocksColor;
	bool homeShirtHoopedSocks;


	int capital;		// Wert * 10000€
	short financialStrength;
	bool publicCorporation;

	short fanAttendance;
	short maxFanAttendance;
	short fanType;
	short hooligans;
	int fanFriendship;
	short board;
	short opposition;

	bool cupTeam;
	bool mediaCity;

	int perpetualTableGoalsScored;
	int perpetualTableGoalsConceded;
	int perpetualTableGames;

	int championshipWins;
	int trophiesWins;
	int leagueCupWins;
	int europeLeagueWins;
	int championsLeagueWins;
	int worldCupWins;

	short regionalLeagueRelegation;

	short foundingYear;
	short country;
	int archrival;

	int professionalDivisionFrom;
	int amateurDivisionFrom;
};