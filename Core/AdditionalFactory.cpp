#include "AdditionalFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

Additional AdditionalFactory::createFromSAV(std::vector<std::string> dataUefa, short countLines, short valuesPerLine, std::vector<std::string> data, std::vector<std::string> dataEmwm, std::vector<std::string> dataOutfitter)
{
	Additional additional;

	std::vector<UefaCountry> values;

	if (dataUefa.empty())
	{
		logger->writeErrorEntry("Uefa data is empty.");
		return additional;
	}
	if (data.empty())
	{
		logger->writeErrorEntry("Additional data is empty.");
		return additional;
	}
	if (dataEmwm.empty())
	{
		logger->writeErrorEntry("EMWM data is empty.");
		return additional;
	}
	if (dataOutfitter.empty())
	{
		logger->writeErrorEntry("Outfitter data is empty.");
		return additional;
	}

	int index = 0;
	for (int i = 0; i < countLines; ++i)
	{
		UefaCountry uefaCountry;
		uefaCountry.countryId = std::stoi(dataUefa[index++]);
		short sum = 0;
		for (int j = 0; j < valuesPerLine; ++j)
		{
			short value = std::stoi(dataUefa[index++]);
			uefaCountry.years.push_back(value);
			// skip last season which is not part of planning
			if(j != valuesPerLine - 1)
				sum+= value;
		}
		uefaCountry.sum = sum;
		
		values.push_back(uefaCountry);
	}
	
	additional.setValue(values);
	additional.setStartingYear(std::stoi(data.at(0)));
	additional.setTax(std::stoi(data.at(1)));
	additional.setSubstitutionsFriendlyGames(std::stoi(data.at(2)));
	additional.setChampionsLeagueName(data.at(6));
	additional.setEuropeLeagueName(data.at(7));
	std::vector<EMWM> emwmList;
	for (int i = 1; i < dataEmwm.size(); i += 3)
	{
		EMWM emwm;
		emwm.year = std::stoi(dataEmwm.at(i));
		emwm.type = std::stoi(dataEmwm.at(i + 1));
		emwm.nationIndex = std::stoi(dataEmwm.at(i + 2));
		emwmList.push_back(emwm);
	}
	additional.setEMWM(emwmList);
	additional.setOutfitter(dataOutfitter);
	return additional;
}

void AdditionalFactory::writeToSAVUefa(Additional& additional, std::ofstream& out)
{
	auto value = additional.getValue();
	for (auto uefaTeam : value)
	{
		out << uefaTeam.countryId << ENDOFLINE;
		for (auto year : uefaTeam.years)
			out << year << ENDOFLINE;
	}
}

void AdditionalFactory::writeToSAVMisc(Additional& additional, std::ofstream& out)
{
	out << additional.getStartingYear() << ENDOFLINE;
	out << additional.getTax() << ENDOFLINE;
	out << additional.getSubstitutionsFriendlyGames() << ENDOFLINE;
	out << additional.getPresident().getLastname() << ENDOFLINE;
	out << additional.getPresident().getFirstname() << ENDOFLINE;
	out << additional.getPresident().getBirthday() << ENDOFLINE;
	out << additional.getChampionsLeagueName() << ENDOFLINE;
	out << additional.getEuropeLeagueName() << ENDOFLINE;
}

void AdditionalFactory::writeToSAVEmwm(Additional& additional, std::ofstream& out)
{
	auto emwmList = additional.getEMWM();
	out << emwmList.size() << ENDOFLINE;
	for (auto emwm : emwmList)
	{
		out << emwm.year << ENDOFLINE;
		out << emwm.type << ENDOFLINE;
		out << emwm.nationIndex << ENDOFLINE;
	}
}

void AdditionalFactory::writeToSAVOutfitter(Additional& additional, std::ofstream& out)
{
	auto outfitterList = additional.getOutfitter();
	for (auto outfitter : outfitterList)
	{
		out << outfitter << ENDOFLINE;
	}
}