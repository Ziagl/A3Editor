#include "TeamFactory.h"
#include "TrainerFactory.h"
#include "ManagerFactory.h"
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

	team.setCountry(std::stoi(data[0]));
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
	team.setLeague(std::stoi(data[55]));

	return team;
}

/*
 * this method prints out all data from team object
 */
void TeamFactory::writeToSAV(Team& team, std::ofstream &out)
{
	out << team.getCountry() << "\n";
	out << team.getName() << "\n";
	out << team.getShortName() << "\n";
	out << team.getAccentuation() << "\n";
	out << team.getFanLabel() << "\n";
	
	// ### TODO ###
	// should be extra node in graph
	// Trainer output
	out << "%SECT%TRAINER\n";
	TrainerFactory::writeToSAV(team.trainer, out);
	out << "%ENDSECT%TRAINER\n";

	// Manager output
	out << "%SECT%MANAGER\n";
	ManagerFactory::writeToSAV(team.manager, out);
	out << "%ENDSECT%MANAGER\n";

	out << team.getHomeShirtColorFirst() + team.getHomeShirtPattern() << "\n";					// 00001111 + 11110000
	out << team.getHomeShirtColorSecond() << "\n";
	out << team.getHomeShirtTrousersColor() << "\n";
	out << team.getHomeShirtSocksColor() + (team.getHomeShirtHoopedSocks()?16:0) << "\n";		// 00001111 + bool (converted to 10000)
	out << team.getAwayShirtColorFirst() + team.getAwayShirtPattern() << "\n";
	out << team.getAwayShirtColorSecond() << "\n";
	out << team.getAwayShirtTrousersColor() << "\n";
	out << team.getAwayShirtSocksColor() + (team.getAwayShirtHoopedSocks()?16:0) << "\n";
	out << team.getCapital() << "\n";
	if (team.getShortNamePrefix() == "Der")
		out << "1\n";
	else if (team.getShortNamePrefix() == "Die")
		out << "2\n";
	else
		out << "0\n";
	out << team.getFanAttendance() << "\n";
	out << team.getFanType() << "\n";
	out << team.getFanFriendship() << "\n";
	out << team.getArchrival() << "\n";
	out << team.getBoard() << "\n";
	out << (team.getCupTeam()?"1":"0") << "\n";
	out << team.getGrammar() << "\n";
	out << team.getAmateurProfessionalDivisionFrom() << "\n";
	out << team.getMapX() << "\n";
	out << team.getMapY() << "\n";
	out << team.getUnknown1() << "\n";
	out << team.getUnknown2() << "\n";
	out << team.getUnknown3() << "\n";
	out << team.getOpposition() << "\n";
	out << team.getFinancialStrength() << "\n";
	out << team.getMaxFanAttendance() << "\n";
	out << team.getHooligans() << "\n";
	out << (team.getMediaCity()?"1":"0") << "\n";
	out << team.getPerpetualTableGoalsScored() << "\n";
	out << team.getPerpetualTableGoalsConceded() << "\n";
	out << team.getPerpetualTableGames() << "\n";
	out << team.getPerpetualTablePoints() << "\n";
	
	// Chairman
	out << team.chairman.getLastname() << "\n";
	out << team.chairman.getFirstname() << "\n";
	out << team.chairman.getBirthday() << "\n";
	
	out << team.getPublicCorporation() << "\n";
	out << team.getChampionshipWins() << "\n";
	out << team.getTrophiesWins() << "\n";
	out << team.getLeagueCupWins() << "\n";
	out << team.getEuropeLeagueWins() << "\n";
	out << team.getChampionsLeagueWins() << "\n";
	out << team.getWorldCupWins() << "\n";
	out << team.getRegionalLeagueRelegation() << "\n";
	out << team.getFoundingYear() << "\n";
	out << team.getUnknown4() << "\n";
	out << team.getUnknown5() << "\n";
	out << team.getUnknown6() << "\n";
	out << team.getUnknown7() << "\n";
	out << team.getUnknown8() << "\n";
	out << team.getUnknown9() << "\n";
	out << team.getLeague() << "\n";
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
