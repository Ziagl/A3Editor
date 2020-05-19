#include "RefereeFactory.h"
#include <fstream>

using namespace Core;

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

void RefereeFactory::writeToSAV(Referee& referee, std::ofstream& out)
{
	out << referee.getFirstname() << "\n";
	out << referee.getLastname() << "\n";
	out << referee.getCompetence() << "\n";
	out << referee.getHardness() << "\n";
	out << referee.getUnpopularTeam() << "\n";
	short value = 0;
	if (referee.getHomeReferee())
		value += 1;						//	0 0001
	if (referee.getGuestReferee())
		value += 2;						//	0 0010
	if (referee.getHatesGripe())
		value += 4;						//	0 0100
	if (referee.getHatesTimeGame())
		value += 8;						//	0 1000
	if (referee.getHatesCoaching())
		value += 16;					//	1 0000
	out << value << "\n";
}