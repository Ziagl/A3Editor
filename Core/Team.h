#pragma once

#include <string>
#include <vector>
#include "Person.h"
#include "Player.h"
#include "Manager.h"
#include "Trainer.h"

class Team 
{
	friend class TeamFactory;
public:
	Team() {};
	~Team() {};

	// getter/setter
	std::string getName() { return name; }
	std::string getShortName() { return shortName; }
	std::string getShortNamePrefix() { return shortNamePrefix; }
	std::string getAccentuation() { return accentuation; }
	std::string getFanLabel() { return fanLabel; }
	
	void setManager(const Manager &manager) { this->manager = manager; }
	void setTrainer(const Trainer &trainer) { this->trainer = trainer; }
protected:
	// getter/setter
	void setCountry(const short country) { this->country = country; }
	void setName(const std::string name) { this->name = name; }
	void setShortname(const std::string shortName) { this->shortName = shortName; }
	void setShortNamePrefix(const std::string shortNamePrefix) { this->shortNamePrefix = shortNamePrefix; }
	void setAccentuation(const std::string accentuation) { this->accentuation = accentuation; }
	void setFanLabel(const std::string fanLabel) { this->fanLabel = fanLabel; }
	void setHomeShirtColorFirst(const short homeShirtColorFirst) { this->homeShirtColorFirst = homeShirtColorFirst; }
	void setHomeShirtColorSecond(const short homeShirtColorSecond) { this->homeShirtColorSecond = homeShirtColorSecond; }
	void setHomeShirtPattern(const short homeShirtPattern) { this->homeShirtPattern = homeShirtPattern; }
	void setHomeShirtTrousersColor(const short homeShirtTrousersColor) { this->homeShirtTrousersColor = homeShirtTrousersColor; }
	void setHomeShirtSocksColor(const short homeShirtSocksColor) { this->homeShirtSocksColor = homeShirtSocksColor; }
	void setHomeShirtHoopedSocks(const bool homeShirtHoopedSocks) { this->homeShirtHoopedSocks = homeShirtHoopedSocks; }
	void setAwayShirtColorFirst(const short awayShirtColorFirst) { this->awayShirtColorFirst = awayShirtColorFirst; }
	void setAwayShirtColorSecond(const short awayShirtColorSecond) { this->awayShirtColorSecond = awayShirtColorSecond; }
	void setAwayShirtPattern(const short awayShirtPattern) { this->awayShirtPattern = awayShirtPattern; }
	void setAwayShirtTrousersColor(const short awayShirtTrousersColor) { this->awayShirtTrousersColor = awayShirtTrousersColor; }
	void setAwayShirtSocksColor(const short awayShirtSocksColor) { this->awayShirtSocksColor = awayShirtSocksColor; }
	void setAwayShirtHoopedSocks(const bool awayShirtHoopedSocks) { this->awayShirtHoopedSocks = awayShirtHoopedSocks; }
	void setCapital(const int capital) { this->capital = capital; }
	void setFanAttendance(const short fanAttendance) { this->fanAttendance = fanAttendance; }
	void setFanType(const short fanType) { this->fanType = fanType; }
	void setFanFriendship(const int fanFriendship) { this->fanFriendship = fanFriendship; }
	void setArchrival(const int archrival) { this->archrival = archrival; }
	void setBoard(const short board) { this->board = board; }
	void setCupTeam(const bool cupTeam) { this->cupTeam = cupTeam; }
	void setGrammar(const short grammar) { this->grammar = grammar; }
	void setAmateurProfessionalDivisionFrom(const int amateurProfessionalDivisionFrom) { this->amateurProfessionalDivisionFrom= amateurProfessionalDivisionFrom; }
	void setMapX(const short mapX) { this->mapX = mapX; }
	void setMapY(const short mapY) { this->mapY = mapY; }
	void setUnknown1(const short unknown1) { this->unknown1 = unknown1; }
	void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
	void setUnknown3(const short unknown3) { this->unknown3 = unknown3; }
	void setOpposition(const short opposition) { this->opposition = opposition; }
	void setFinancialStrength(const short financialStrength) { this->financialStrength = financialStrength; }
	void setMaxFanAttendance(const short maxFanAttendance) { this->maxFanAttendance = maxFanAttendance; }
	void setHooligans(const short hooligans) { this->hooligans = hooligans; }
	void setMediaCity(const bool mediaCity) { this->mediaCity = mediaCity; }
	void setPerpetualTableGoalsScored(const int perpetualTableGoalsScored) { this->perpetualTableGoalsScored = perpetualTableGoalsScored; }
	void setPerpetualTableGoalsConceded(const int perpetualTableGoalsConceded) { this->perpetualTableGoalsConceded = perpetualTableGoalsConceded; }
	void setPerpetualTableGames(const int perpetualTableGames) { this->perpetualTableGames = perpetualTableGames; }
	void setPerpetualTablePoints(const int perpetualTablePoints) { this->perpetualTablePoints = perpetualTablePoints; }
	void setChairman(const Person chairman) { this->chairman = chairman; }
	void setPublicCorporation(const bool publicCorporation) { this->publicCorporation = publicCorporation; }
	void setChampionshipWins(const int championshipWins) { this->championshipWins = championshipWins; }
	void setTrophiesWins(const int trophiesWins) { this->trophiesWins = trophiesWins; }
	void setLeagueCupWins(const int leagueCupWins) { this->leagueCupWins = leagueCupWins; }
	void setEuropeLeagueWins(const int europeLeagueWins) { this->europeLeagueWins = europeLeagueWins; }
	void setChampionsLeagueWins(const int championsLeagueWins) { this->championsLeagueWins = championsLeagueWins; }
	void setWorldCupWins(const int worldCupWins) { this->worldCupWins = worldCupWins; }
	void setRegionalLeagueRelegation(const short regionalLeagueRelegation) { this->regionalLeagueRelegation = regionalLeagueRelegation; }
	void setFoundingYear(const std::string foundingYear) { this->foundingYear = foundingYear; }
	void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
	void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
	void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
	void setUnknown7(const short unknown7) { this->unknown7 = unknown7; }
	void setUnknown8(const short unknown8) { this->unknown8 = unknown8; }
	void setUnknown9(const short unknown9) { this->unknown9 = unknown9; }
	void setLeague(const int league) { this->league = league; }
private:
	Trainer trainer;
	Manager manager;

	std::string name;
	std::string shortName;
	std::string shortNamePrefix;
	std::string accentuation;
	std::string fanLabel;
	Person chairman;
	short homeShirtColorFirst;
	short homeShirtColorSecond;
	short homeShirtPattern;
	short homeShirtTrousersColor;
	short homeShirtSocksColor;
	bool homeShirtHoopedSocks;
	short awayShirtColorFirst;
	short awayShirtColorSecond;
	short awayShirtPattern;
	short awayShirtTrousersColor;
	short awayShirtSocksColor;
	bool awayShirtHoopedSocks;
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
	int perpetualTablePoints;
	int championshipWins;
	int trophiesWins;
	int leagueCupWins;
	int europeLeagueWins;
	int championsLeagueWins;
	int worldCupWins;
	std::string foundingYear;
	int archrival;
	// 0: ...kann der Verein... / ...von Verein kam...
	// 1: ...können die Verein... / ...von der Verein kam...
	// 2: ...kam Verein... / ...von Verein kam...
	// 3: ...kann die Verein... / ...von der Verein kam...
	short grammar;
	short mapX;
	short mapY;
	short regionalLeagueRelegation;
	// Verbindung zu anderem Verein (Amateurverein von /  Profiverein von)
	int amateurProfessionalDivisionFrom;
	short unknown1;
	short unknown2;
	short unknown3;
	short unknown4;
	short unknown5;
	short unknown6;
	short unknown7;
	short unknown8;
	short unknown9;
	short country;
	int league;
};