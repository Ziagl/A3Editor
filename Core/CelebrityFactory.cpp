#include "CelebrityFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

Celebrity CelebrityFactory::create()
{
	return Celebrity();
}

Celebrity CelebrityFactory::createFromSAV(std::vector<std::string> data)
{
	Celebrity celebrity;

	if (data.empty())
	{
		logger->writeErrorEntry("Celebrity data is empty.");
		return celebrity;
	}

	celebrity.setLastname(data[0]);
	celebrity.setFirstname(data[1]);
	celebrity.setFavoriteTeam(std::stoi(data[2]));

	return celebrity;
}

void CelebrityFactory::writeToSAV(Celebrity& celebrity, std::ofstream& out)
{
	out << celebrity.getLastname() << ENDOFLINE;
	out << celebrity.getFirstname() << ENDOFLINE;
	out << celebrity.getFavoriteTeam() << ENDOFLINE;
}