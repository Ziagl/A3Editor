#pragma once

#include <string>
#include <vector>
#include "Person.h"
#include "Player.h"
#include "Manager.h"
#include "Trainer.h"
#include "Stadium.h"

namespace Core
{
	class Team
	{
		friend class TeamFactory;
	public:
		Team() : homeShirtColorFirst(0), homeShirtColorSecond(0), homeShirtPattern(0), homeShirtTrousersColor(0), homeShirtSocksColor(0), homeShirtHoopedSocks(false),
				 awayShirtColorFirst(0), awayShirtColorSecond(0), awayShirtPattern(0), awayShirtTrousersColor(0), awayShirtSocksColor(0), awayShirtHoopedSocks(false),
				 capital(0), financialStrength(0), publicCorporation(false), fanAttendance(0), maxFanAttendance(0), fanType(0), hooligans(0), fanFriendship(0),
				 board(0), opposition(0), cupTeam(false), mediaCity(false), perpetualTableGoalsScored(0), perpetualTableGoalsConceded(0), perpetualTableGames(0), perpetualTablePoints(0), 
				 championshipWins(0), trophiesWins(0), leagueCupWins(0), europeLeagueWins(0), championsLeagueWins(0), worldCupWins(0), archrival(0), grammar(0), mapX(0), mapY(0), 
				 regionalLeagueRelegation(0), amateurProfessionalDivisionFrom(0), unknown1(0), unknown2(0), unknown3(0), unknown4(0), unknown5(0), unknown6(0), unknown7(0), 
				 unknown8(0), unknown9(0), countryId(0), unknown10(0), teamId(0) {};
		~Team() {};

		// getter/setter
		short getCountryId() { return countryId; }
		std::string getName() { return name; }
		std::string getShortName() { return shortName; }
		std::string getShortNamePrefix() { return shortNamePrefix; }
		std::string getAccentuation() { return accentuation; }
		std::string getFanLabel() { return fanLabel; }
		short getHomeShirtColorFirst() { return homeShirtColorFirst; }
		short getHomeShirtColorSecond() { return homeShirtColorSecond; }
		short getHomeShirtPattern() { return homeShirtPattern; }
		short getHomeShirtTrousersColor() { return homeShirtTrousersColor; }
		short getHomeShirtSocksColor() { return homeShirtSocksColor; }
		bool getHomeShirtHoopedSocks() { return homeShirtHoopedSocks; }
		short getAwayShirtColorFirst() { return awayShirtColorFirst; }
		short getAwayShirtColorSecond() { return awayShirtColorSecond; }
		short getAwayShirtPattern() { return awayShirtPattern; }
		short getAwayShirtTrousersColor() { return awayShirtTrousersColor; }
		short getAwayShirtSocksColor() { return awayShirtSocksColor; }
		bool getAwayShirtHoopedSocks() { return awayShirtHoopedSocks; }
		int getCapital() { return capital; }
		short getFanAttendance() { return fanAttendance; }
		short getFanType() { return fanType; }
		int getFanFriendship() { return fanFriendship; }
		int getArchrival() { return archrival; }
		short getBoard() { return board; }
		bool getCupTeam() { return cupTeam; }
		short getGrammar() { return grammar; }
		int getAmateurProfessionalDivisionFrom() { return amateurProfessionalDivisionFrom; }
		short getMapX() { return mapX; }
		short getMapY() { return mapY; }
		short getUnknown1() { return unknown1; }
		short getUnknown2() { return unknown2; }
		short getUnknown3() { return unknown3; }
		short getOpposition() { return opposition; }
		short getFinancialStrength() { return financialStrength; }
		short getMaxFanAttendance() { return maxFanAttendance; }
		short getHooligans() { return hooligans; }
		bool getMediaCity() { return mediaCity; }
		int getPerpetualTableGoalsScored() { return perpetualTableGoalsScored; }
		int getPerpetualTableGoalsConceded() { return perpetualTableGoalsConceded; }
		int getPerpetualTableGames() { return perpetualTableGames; }
		int getPerpetualTablePoints() { return perpetualTablePoints; }
		bool getPublicCorporation() { return publicCorporation; }
		int getChampionshipWins() { return championshipWins; }
		int getTrophiesWins() { return trophiesWins; }
		int getLeagueCupWins() { return leagueCupWins; }
		int getEuropeLeagueWins() { return europeLeagueWins; }
		int getChampionsLeagueWins() { return championsLeagueWins; }
		int getWorldCupWins() { return worldCupWins; }
		short getRegionalLeagueRelegation() { return regionalLeagueRelegation; }
		std::string getFoundingYear() { return foundingYear; }
		short getUnknown4() { return unknown4; }
		short getUnknown5() { return unknown5; }
		short getUnknown6() { return unknown6; }
		short getUnknown7() { return unknown7; }
		short getUnknown8() { return unknown8; }
		short getUnknown9() { return unknown9; }
		int getUnknown10() { return unknown10; }
		short getTeamId() { return teamId; }

		void setManager(const Manager& manager) { this->manager = manager; }
		void setTrainer(const Trainer& trainer) { this->trainer = trainer; }
		void setStadium(const Stadium& stadium) { this->stadium = stadium; }
		void setTeamId(const short teamId) { this->teamId = teamId; }
		Manager getManager() { return manager; }
		Trainer getTrainer() { return trainer; }
		Stadium getStadium() { return stadium; }
	protected:
		// getter/setter
		void setCountryId(const short countryId) { this->countryId = countryId; }
		void setName(const std::string name) { this->name = name; }
		void setShortName(const std::string shortName) { this->shortName = shortName; }
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
		void setAmateurProfessionalDivisionFrom(const int amateurProfessionalDivisionFrom) { this->amateurProfessionalDivisionFrom = amateurProfessionalDivisionFrom; }
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
		void setUnknown10(const int unknown10) { this->unknown10 = unknown10; }
	private:
		Trainer trainer;
		Manager manager;
		Stadium stadium;

		std::string name;
		std::string shortName;
		std::string shortNamePrefix;
		std::string accentuation;
		std::string fanLabel;
		Person chairman;
		short homeShirtColorFirst = 0;
		short homeShirtColorSecond = 0;
		short homeShirtPattern = 0;
		short homeShirtTrousersColor = 0;
		short homeShirtSocksColor = 0;
		bool homeShirtHoopedSocks;
		short awayShirtColorFirst = 0;
		short awayShirtColorSecond = 0;
		short awayShirtPattern = 0;
		short awayShirtTrousersColor = 0;
		short awayShirtSocksColor = 0;
		bool awayShirtHoopedSocks;
		int capital = 0;		// Wert * 10000€
		short financialStrength = 0;
		bool publicCorporation;
		short fanAttendance = 0;
		short maxFanAttendance = 0;
		short fanType = 0;
		short hooligans = 0;
		int fanFriendship = 0;
		short board = 0;
		short opposition = 0;
		bool cupTeam;
		bool mediaCity;
		int perpetualTableGoalsScored = 0;
		int perpetualTableGoalsConceded = 0;
		int perpetualTableGames = 0;
		int perpetualTablePoints = 0;
		int championshipWins = 0;
		int trophiesWins = 0;
		int leagueCupWins = 0;
		int europeLeagueWins = 0;
		int championsLeagueWins = 0;
		int worldCupWins = 0;
		std::string foundingYear;
		int archrival = 0;
		// 0: ...kann der Verein... / ...von Verein kam...
		// 1: ...können die Verein... / ...von der Verein kam...
		// 2: ...kam Verein... / ...von Verein kam...
		// 3: ...kann die Verein... / ...von der Verein kam...
		short grammar = 0;
		short mapX = 0;
		short mapY = 0;
		// in welche Regionalliga kommt der Verein bei Abstieg
		// Österreich alle 2, Deutschland 2 und 5
		short regionalLeagueRelegation = 0;
		// status of last year
		// 128	Pokalfinalist
		// 64   Pokalsieger
		// 1	Meister
		// 6	Vizemeister
		// 4	Aufsteiger
		// 3	Absteiger
		// 16	Amateur ohne Liga (Österreich)
		// 0	Normal
		int amateurProfessionalDivisionFrom = 0;
		short unknown1 = 0;
		short unknown2 = 0;
		short unknown3 = 0;
		short unknown4 = 0;
		short unknown5 = 0;
		short unknown6 = 0;
		short unknown7 = 0;
		short unknown8 = 0;
		short unknown9 = 0;
		short countryId = 0;		// 0 based index of nation in Laender.sav
		int unknown10 = 0;

		// metadata
		short teamId = 0;			// position of team in Land****.sav file for league connection
									// 1 based and only for playable countries
	};
}