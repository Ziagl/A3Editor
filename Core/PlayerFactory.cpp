#include "PlayerFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

Player PlayerFactory::create(NameGenerator& nameGenerator) 
{
	// generate random name tuple (firstname, lastname)
	auto names = nameGenerator.createName();

	// creates player with random name
	Player p(logger);
	p.setFirstname(std::get<0>(names));
	p.setLastname(std::get<1>(names));

	logger->writeInfoEntry("pointer auf logger: " + std::to_string(logger.use_count()));					//TODO remove

	return p;
}

Player PlayerFactory::createFromSAV(std::vector<std::string> data)
{
	Player player(logger);

	if (data.empty())
	{
		logger->writeErrorEntry("Player data is empty.");
		return player;
	}

	player.setFirstname(data[0]);
	player.setLastname(data[1]);
	player.setUnknown1(std::stoi(data[2]));
	player.setSkinColor(std::stoi(data[3]));
	player.setHairColor(std::stoi(data[4]));
	player.setAge(std::stoi(data[5]));
	player.setSkill(std::stoi(data[6]));
	player.setNationalityFirst(std::stoi(data[7]) & 127);	// 0111 1111
	player.setResidient((std::stoi(data[7]) & 128) != 0);	// 1000 0000
	player.setMainPosition(std::stoi(data[8]));
	player.setAlternativeFirstPosition(std::stoi(data[9]));
	player.setAlternativeSecondPosition(std::stoi(data[10]));
	player.setPlayerSkillPositive(std::stoi(data[11]));
	player.setPlayerSkillNegative(std::stoi(data[12]));
	player.setPlayerProperties(std::stoi(data[13]));
	player.setPlayerCharacter(std::stoi(data[14]));
	player.setHasArtistName(std::stoi(data[15]) != 0);
	player.setArtistName(data[16]);
	player.setFoot(std::stoi(data[17]));
	player.setTalent(std::stoi(data[18]));
	player.setHealth(std::stoi(data[19]));
	player.setAudience(std::stoi(data[20]));
	player.setBirthday(data[21]);
	player.setUnknown2(std::stoi(data[22]));
	player.setNationalitySecond(std::stoi(data[23]));
	player.setNationalPlayer((std::stoi(data[24]) & 1) != 0);			// 001
	player.setNationalPlayerResigned((std::stoi(data[24]) & 2) != 0);	// 010
	player.setNationalTeam((std::stoi(data[24]) & 4) != 0);				// 100
	player.setUnknown3(std::stoi(data[25]));
	player.setUnknown4(std::stoi(data[26]));
	player.setCaptainResigned(std::stoi(data[27]) != 0);
	player.setBackNumber(std::stoi(data[28]));
	player.setAppearence(std::stol(data[29]));
	player.setUnknown5(std::stoi(data[30]));
	player.setUnknown6(std::stoi(data[31]));
	player.setUnknown7(std::stoi(data[32]));

	return player;
}

void PlayerFactory::writeToSAV(Player& player, std::ofstream& out)
{
	out << player.getFirstname() << ENDOFLINE;
	out << player.getLastname() << ENDOFLINE;
	out << player.getUnknown1() << ENDOFLINE;
	out << player.getSkinColor() << ENDOFLINE;
	out << player.getHairColor() << ENDOFLINE;
	out << player.getAge() << ENDOFLINE;
	out << player.getSkill() << ENDOFLINE;
	out << player.getNationalityFirst() + (player.getResidient()?128:0) << ENDOFLINE;		// 0111 1111 + 1000 0000
	out << player.getMainPosition() << ENDOFLINE;
	out << player.getAlternativeFirstPosition() << ENDOFLINE;
	out << player.getAlternativeSecondPosition() << ENDOFLINE;
	out << player.getPlayerSkillPositive() << ENDOFLINE;
	out << player.getPlayerSkillNegative() << ENDOFLINE;
	out << player.getPlayerProperties() << ENDOFLINE;
	out << player.getPlayerCharacter() << ENDOFLINE;
	out << (player.getHasArtistName()?"1":"0") << ENDOFLINE;
	out << player.getArtistName() << ENDOFLINE;
	out << player.getFoot() << ENDOFLINE;
	out << player.getTalent() << ENDOFLINE;
	out << player.getHealth() << ENDOFLINE;
	out << player.getAudience() << ENDOFLINE;
	out << player.getBirthday() << ENDOFLINE;
	out << player.getUnknown2() << ENDOFLINE;
	out << player.getNationalitySecond() << ENDOFLINE;
	short value = 0;
	if (player.getNationalPlayer())
		value += 1;							// 001
	if (player.getNationalPlayerResigned())
		value += 2;							// 010
	if (player.getNationalTeam())
		value += 4;							// 100
	out << value << ENDOFLINE;
	out << player.getUnknown3() << ENDOFLINE;
	out << player.getUnknown4() << ENDOFLINE;
	out << (player.getCaptainResigned()?"1":"0") << ENDOFLINE;
	out << player.getBackNumber() << ENDOFLINE;
	out << player.getAppearence() << ENDOFLINE;
	out << player.getUnknown5() << ENDOFLINE;
	out << player.getUnknown6() << ENDOFLINE;
	out << player.getUnknown7() << ENDOFLINE;
}