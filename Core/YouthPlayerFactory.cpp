#include "YouthPlayerFactory.h"
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
	out << youthPlayer.getFirstname() << "\n";
	out << youthPlayer.getLastname() << "\n";
	out << youthPlayer.getTeamId() << "\n";
	out << youthPlayer.getMainPosition() << "\n";
}