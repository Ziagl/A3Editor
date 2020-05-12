#include "YouthPlayerFactory.h"

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