#include "UefaRankingFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

UefaRanking UefaRankingFactory::createFromSAV(std::vector<std::string> data, short countLines, short valuesPerLine)
{
	UefaRanking uefaRanking;

	std::vector<UefaTeam> values;

	if (data.empty())
	{
		logger->writeErrorEntry("UefaRankung data is empty.");
		return uefaRanking;
	}

	int index = 0;
	for (int i = 0; i < countLines; ++i)
	{
		UefaTeam uefaTeam;
		uefaTeam.countryId = std::stoi(data[index++]);
		short sum = 0;
		for (int j = 0; j < valuesPerLine; ++j)
		{
			short value = std::stoi(data[index++]);
			uefaTeam.years.push_back(value);
			// skip last season which is not part of planning
			if(j != valuesPerLine - 1)
				sum+= value;
		}
		uefaTeam.sum = sum;
		
		values.push_back(uefaTeam);
	}
	
	uefaRanking.setValue(values);
	return uefaRanking;
}

void UefaRankingFactory::writeToSAV(UefaRanking& uefaRanking, std::ofstream& out)
{
	auto value = uefaRanking.getValue();
	for (auto uefaTeam : value)
	{
		out << uefaTeam.countryId << ENDOFLINE;
		for (auto year : uefaTeam.years)
			out << year << ENDOFLINE;
	}
}