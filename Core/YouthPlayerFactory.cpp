#include "YouthPlayerFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

YouthPlayer YouthPlayerFactory::createFromSAV(std::vector<std::string> data)
{
	YouthPlayer youthPlayer;

	if (data.empty())
	{
		logger->writeErrorEntry("YouthPlayer data is empty.");
		return youthPlayer;
	}

	youthPlayer.setFirstname(data[0]);
	youthPlayer.setLastname(data[1]);
	youthPlayer.setTeamId(std::stoi(data[2]));
	youthPlayer.setMainPosition(std::stoi(data[3]));

	return youthPlayer;
}

void YouthPlayerFactory::writeToSAV(YouthPlayer& youthPlayer, std::ofstream& out)
{
	out << youthPlayer.getFirstname() << ENDOFLINE;
	out << youthPlayer.getLastname() << ENDOFLINE;
	out << youthPlayer.getTeamId() << ENDOFLINE;
	out << youthPlayer.getMainPosition() << ENDOFLINE;
}