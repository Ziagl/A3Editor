#include "SponsorFactory.h"

Sponsor SponsorFactory::create()
{
	return Sponsor();
}

Sponsor SponsorFactory::createFromSAV(std::vector<std::string> data)
{
	Sponsor sponsor;

	if (data.empty())
	{
		logger->writeErrorEntry("Sponsor data is empty.");
		return sponsor;
	}

	sponsor.setName(data[0]);
	sponsor.setAdImage(std::stoi(data[1]));
	sponsor.setUnknown1(std::stoi(data[2]));
	sponsor.setUnknown2(std::stoi(data[3]));
	sponsor.setUnknown3(std::stoi(data[4]));
	sponsor.setUnknown4(std::stoi(data[5]));
	sponsor.setFontThickness(std::stoi(data[6]));
	sponsor.setFontType(std::stoi(data[7]));
	sponsor.setUnknown5(std::stoi(data[8]));
	sponsor.setUnknown6(std::stoi(data[9]));
	sponsor.setFontScript(std::stoi(data[10]));
	sponsor.setUnknown7(std::stoi(data[11]));
	sponsor.setFontSize(std::stoi(data[12]));
	sponsor.setUnknown8(std::stoi(data[13]));
	sponsor.setUnknown9(std::stoi(data[14]));
	sponsor.setUnknown10(std::stoi(data[15]));
	sponsor.setFont(data[16]);
	sponsor.setSize(std::stol(data[17]));
	sponsor.setTextColor(std::stoi(data[18]));

	return sponsor;
}