#include "CountryFactory.h"

Country CountryFactory::create()
{
	return Country();
}

Country CountryFactory::createFromSAV(std::vector<std::string> data)
{
	Country country;

	if (data.empty())
	{
		logger->writeErrorEntry("Country data is empty.");
		return country;
	}

	country.setCup(data[0]);
	country.setUnknown2(std::stoi(data[1]));
	country.setCountryId(std::stoi(data[2]));
	country.setUnknown4(std::stoi(data[3]));
	country.setUnknown5(std::stoi(data[4]));
	country.setUnknown6(std::stoi(data[5]));

	return country;
}