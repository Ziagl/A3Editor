#include "CountryFactory.h"

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
	country.setCountryId(std::stoi(data[2]));
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
	out << country.getCupName() << "\n";
	out << country.getUnknown2() << "\n";
	out << country.getCountryId() << "\n";
	out << country.getUnknown4() << "\n";
	out << country.getUnknown5() << "\n";
	out << country.getUnknown6() << "\n";
}