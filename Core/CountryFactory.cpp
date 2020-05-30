#include "CountryFactory.h"
#include "globals.h"

using namespace Core;

Country CountryFactory::create()
{
	return Country();
}

Country CountryFactory::createFromSAV(std::vector<std::string> data, std::string filename, bool playable)
{
	Country country;

	if (data.empty())
	{
		logger->writeErrorEntry("Country data is empty.");
		return country;
	}

	country.setCupName(data[0]);
	country.setUnknown2(std::stoi(data[1]));
	country.setTeamsCount(std::stoi(data[2]));
	country.setUnknown4(std::stoi(data[3]));
	country.setUnknown5(std::stoi(data[4]));
	country.setUnknown6(std::stoi(data[5]));

	// meta data
	country.setFilename(filename);
	country.setPlayable(playable);

	return country;
}

/*
 * this method prints out all data from country object
 */
void CountryFactory::writeToSAV(Country &country, std::ofstream &out)
{
	out << country.getCupName() << ENDOFLINE;
	out << country.getUnknown2() << ENDOFLINE;
	out << country.getTeamsCount() << ENDOFLINE;
	out << country.getUnknown4() << ENDOFLINE;
	out << country.getUnknown5() << ENDOFLINE;
	out << country.getUnknown6() << ENDOFLINE;
}