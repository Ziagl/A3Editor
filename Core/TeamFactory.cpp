#include "TeamFactory.h"
#include "TrainerFactory.h"
#include "ManagerFactory.h"
#include "globals.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace Core;

Team TeamFactory::create()
{
	return Team();
}

Team TeamFactory::createFromSAV(std::vector<std::string> data)
{
	Team team;
	
	if (data.empty())
	{
		logger->writeErrorEntry("Team data is empty.");
		return team;
	}

	team.setCountryId(std::stoi(data[0]));
	team.setName(data[1]);
	team.setShortName(data[2]);
	team.setAccentuation(data[3]);
	team.setFanLabel(data[4]);
	team.setHomeShirtColorFirst(strToColor(data[5]));
	team.setHomeShirtColorSecond(std::stoi(data[6]));
	team.setHomeShirtPattern(strToPattern(data[5]));
	team.setHomeShirtTrousersColor(std::stoi(data[7]));
	team.setHomeShirtSocksColor(strToColor(data[8]));
	team.setHomeShirtHoopedSocks(strToPattern(data[8]) > 0);
	team.setAwayShirtColorFirst(strToColor(data[9]));
	team.setAwayShirtColorSecond(std::stoi(data[10]));
	team.setAwayShirtPattern(strToPattern(data[9]));
	team.setAwayShirtTrousersColor(std::stoi(data[11]));
	team.setAwayShirtSocksColor(strToColor(data[12]));
	team.setAwayShirtHoopedSocks(strToPattern(data[12]) > 0);
	team.setCapital(std::stoi(data[13]));
	switch(std::stoi(data[14]))
	{
		case 1:
			team.setShortNamePrefix("Der");			// TODO: schlecht für Übersetzungen!!!
			break;
		case 2:
			team.setShortNamePrefix("Die");
			break;
		default:
			team.setShortNamePrefix("");
	}
	team.setFanAttendance(std::stoi(data[15]));
	team.setFanType(std::stoi(data[16]));
	team.setFanFriendship(std::stoi(data[17]));
	team.setArchrival(std::stoi(data[18]));
	team.setBoard(std::stoi(data[19]));
	team.setCupTeam(std::stoi(data[20]) != 0);
	team.setGrammar(std::stoi(data[21]));
	team.setAmateurProfessionalDivisionFrom(std::stoi(data[22]));
	team.setMapX(std::stoi(data[23]));
	team.setMapY(std::stoi(data[24]));
	team.setUnknown1(std::stoi(data[25]));
	team.setUnknown2(std::stoi(data[26]));
	team.setUnknown3(std::stoi(data[27]));
	team.setOpposition(std::stoi(data[28]));
	team.setFinancialStrength(std::stoi(data[29]));
	team.setMaxFanAttendance(std::stoi(data[30]));
	team.setHooligans(std::stoi(data[31]));
	team.setMediaCity(std::stoi(data[32]) != 0);
	team.setPerpetualTableGoalsScored(std::stoi(data[33]));
	team.setPerpetualTableGoalsConceded(std::stoi(data[34]));
	team.setPerpetualTableGames(std::stoi(data[35]));
	team.setPerpetualTablePoints(std::stoi(data[36]));
	{
		Person chairman(data[38], data[37], data[39]);
		team.setChairman(chairman);
	}
	team.setPublicCorporation(std::stoi(data[40]));
	team.setChampionshipWins(std::stoi(data[41]));
	team.setTrophiesWins(std::stoi(data[42]));
	team.setLeagueCupWins(std::stoi(data[43]));
	team.setEuropeLeagueWins(std::stoi(data[44]));
	team.setChampionsLeagueWins(std::stoi(data[45]));
	team.setWorldCupWins(std::stoi(data[46]));
	team.setRegionalLeagueRelegation(std::stoi(data[47]));
	team.setFoundingYear(data[48]);
	team.setUnknown4(std::stoi(data[49]));
	team.setUnknown5(std::stoi(data[50]));
	team.setUnknown6(std::stoi(data[51]));
	team.setUnknown7(std::stoi(data[52]));
	team.setUnknown8(std::stoi(data[53]));
	team.setUnknown9(std::stoi(data[54]));
	team.setUnknown10(std::stoi(data[55]));

	return team;
}

/*
 * this method prints out all data from team object
 */
void TeamFactory::writeToSAV(Team& team, std::ofstream &out)
{
	out << team.getCountryId() << ENDOFLINE;
	out << team.getName() << ENDOFLINE;
	out << team.getShortName() << ENDOFLINE;
	out << team.getAccentuation() << ENDOFLINE;
	out << team.getFanLabel() << ENDOFLINE;
	
	// ### TODO ###
	// should be extra node in graph
	// Trainer output
	out << "%SECT%TRAINER" << ENDOFLINE;
	TrainerFactory::writeToSAV(team.trainer, out);
	out << "%ENDSECT%TRAINER" << ENDOFLINE;

	// Manager output
	out << "%SECT%MANAGER" << ENDOFLINE;
	ManagerFactory::writeToSAV(team.manager, out);
	out << "%ENDSECT%MANAGER" << ENDOFLINE;

	out << team.getHomeShirtColorFirst() + team.getHomeShirtPattern() << ENDOFLINE;					// 00001111 + 11110000
	out << team.getHomeShirtColorSecond() << ENDOFLINE;
	out << team.getHomeShirtTrousersColor() << ENDOFLINE;
	out << team.getHomeShirtSocksColor() + (team.getHomeShirtHoopedSocks()?16:0) << ENDOFLINE;		// 00001111 + bool (converted to 10000)
	out << team.getAwayShirtColorFirst() + team.getAwayShirtPattern() << ENDOFLINE;
	out << team.getAwayShirtColorSecond() << ENDOFLINE;
	out << team.getAwayShirtTrousersColor() << ENDOFLINE;
	out << team.getAwayShirtSocksColor() + (team.getAwayShirtHoopedSocks()?16:0) << ENDOFLINE;
	out << team.getCapital() << ENDOFLINE;
	if (team.getShortNamePrefix() == "Der")
		out << "1" << ENDOFLINE;
	else if (team.getShortNamePrefix() == "Die")
		out << "2" << ENDOFLINE;
	else
		out << "0" << ENDOFLINE;
	out << team.getFanAttendance() << ENDOFLINE;
	out << team.getFanType() << ENDOFLINE;
	out << team.getFanFriendship() << ENDOFLINE;
	out << team.getArchrival() << ENDOFLINE;
	out << team.getBoard() << ENDOFLINE;
	out << (team.getCupTeam()?"1":"0") << ENDOFLINE;
	out << team.getGrammar() << ENDOFLINE;
	out << team.getAmateurProfessionalDivisionFrom() << ENDOFLINE;
	out << team.getMapX() << ENDOFLINE;
	out << team.getMapY() << ENDOFLINE;
	out << team.getUnknown1() << ENDOFLINE;
	out << team.getUnknown2() << ENDOFLINE;
	out << team.getUnknown3() << ENDOFLINE;
	out << team.getOpposition() << ENDOFLINE;
	out << team.getFinancialStrength() << ENDOFLINE;
	out << team.getMaxFanAttendance() << ENDOFLINE;
	out << team.getHooligans() << ENDOFLINE;
	out << (team.getMediaCity()?"1":"0") << ENDOFLINE;
	out << team.getPerpetualTableGoalsScored() << ENDOFLINE;
	out << team.getPerpetualTableGoalsConceded() << ENDOFLINE;
	out << team.getPerpetualTableGames() << ENDOFLINE;
	out << team.getPerpetualTablePoints() << ENDOFLINE;
	
	// Chairman
	out << team.chairman.getLastname() << ENDOFLINE;
	out << team.chairman.getFirstname() << ENDOFLINE;
	out << team.chairman.getBirthday() << ENDOFLINE;
	
	out << team.getPublicCorporation() << ENDOFLINE;
	out << team.getChampionshipWins() << ENDOFLINE;
	out << team.getTrophiesWins() << ENDOFLINE;
	out << team.getLeagueCupWins() << ENDOFLINE;
	out << team.getEuropeLeagueWins() << ENDOFLINE;
	out << team.getChampionsLeagueWins() << ENDOFLINE;
	out << team.getWorldCupWins() << ENDOFLINE;
	out << team.getRegionalLeagueRelegation() << ENDOFLINE;
	out << team.getFoundingYear() << ENDOFLINE;
	out << team.getUnknown4() << ENDOFLINE;
	out << team.getUnknown5() << ENDOFLINE;
	out << team.getUnknown6() << ENDOFLINE;
	out << team.getUnknown7() << ENDOFLINE;
	out << team.getUnknown8() << ENDOFLINE;
	out << team.getUnknown9() << ENDOFLINE;
	out << team.getUnknown10() << ENDOFLINE;
}

int TeamFactory::strToColor(std::string data)
{
	int value = std::stoi(data);
	return value & 15;	// 0000 1111
}

int TeamFactory::strToPattern(std::string data)
{
	int value = std::stoi(data);
	return value & 240;	// 1111 0000
}
