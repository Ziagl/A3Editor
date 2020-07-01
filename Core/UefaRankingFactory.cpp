#include "AdditionalFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

Additional AdditionalFactory::createFromSAV(std::vector<std::string> data, short countLines, short valuesPerLine)
{
	Additional additional;

	std::vector<UefaCountry> values;

	if (data.empty())
	{
		logger->writeErrorEntry("UefaRankung data is empty.");
		return additional;
	}

	int index = 0;
	for (int i = 0; i < countLines; ++i)
	{
		UefaCountry uefaCountry;
		uefaCountry.countryId = std::stoi(data[index++]);
		short sum = 0;
		for (int j = 0; j < valuesPerLine; ++j)
		{
			short value = std::stoi(data[index++]);
			uefaCountry.years.push_back(value);
			// skip last season which is not part of planning
			if(j != valuesPerLine - 1)
				sum+= value;
		}
		uefaCountry.sum = sum;
		
		values.push_back(uefaCountry);
	}
	
	additional.setValue(values);
	return additional;
}

void AdditionalFactory::writeToSAV(Additional& additional, std::ofstream& out)
{
	auto value = additional.getValue();
	for (auto uefaTeam : value)
	{
		out << uefaTeam.countryId << ENDOFLINE;
		for (auto year : uefaTeam.years)
			out << year << ENDOFLINE;
	}
}