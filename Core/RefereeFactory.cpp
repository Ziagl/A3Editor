#include "RefereeFactory.h"

Referee RefereeFactory::create()
{
	return Referee();
}

Referee RefereeFactory::createFromSAV(std::vector<std::string> data)
{
	Referee referee;

	if (data.empty())
	{
		logger->writeErrorEntry("Referee data is empty.");
		return referee;
	}

	referee.setFirstname(data[0]);
	referee.setLastname(data[1]);
	referee.setCompetence(std::stoi(data[2]));
	referee.setHardness(std::stoi(data[3]));
	referee.setUnpopularTeam(std::stoi(data[4]));
	referee.setHomeReferee((std::stoi(data[5]) & 1) != 0);		//	0 0001
	referee.setGuestReferee((std::stoi(data[5]) & 2) != 0);		//	0 0010
	referee.setHatesGripe((std::stoi(data[5]) & 4) != 0);		//	0 0100
	referee.setHatesTimeGame((std::stoi(data[5]) & 8) != 0);	//	0 1000
	referee.setHatesCoaching((std::stoi(data[5]) & 16) != 0);	//	1 0000

	return referee;
}