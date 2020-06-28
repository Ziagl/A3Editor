#include "SponsorFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

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
	sponsor.setFontSize(std::stoi(data[2]));
	sponsor.setUnknown1(std::stoi(data[3]));
	sponsor.setUnknown2(std::stoi(data[4]));
	sponsor.setUnknown3(std::stoi(data[5]));
	sponsor.setFontWeight(std::stoi(data[6]));
	sponsor.setFontType(std::stoi(data[7]));
	sponsor.setUnknown4(std::stoi(data[8]));
	sponsor.setUnknown5(std::stoi(data[9]));
	sponsor.setFontScript(std::stoi(data[10]));
	sponsor.setUnknown6(std::stoi(data[11]));
	sponsor.setUnknown7(std::stoi(data[12]));
	sponsor.setUnknown8(std::stoi(data[13]));
	sponsor.setUnknown9(std::stoi(data[14]));
	sponsor.setUnknown10(std::stoi(data[15]));
	sponsor.setFont(data[16]);
	sponsor.setBackgroundColorSize(std::stol(data[17]));
	sponsor.setTextColor(std::stoi(data[18]));

	return sponsor;
}

void SponsorFactory::writeToSAV(Sponsor& sponsor, std::ofstream& out)
{
	out << sponsor.getName() << ENDOFLINE;
	out << sponsor.getAdImage() << ENDOFLINE;
	out << sponsor.getFontSize() << ENDOFLINE;
	out << sponsor.getUnknown1() << ENDOFLINE;
	out << sponsor.getUnknown2() << ENDOFLINE;
	out << sponsor.getUnknown3() << ENDOFLINE;
	out << sponsor.getFontWeight() << ENDOFLINE;
	out << sponsor.getFontType() << ENDOFLINE;
	out << sponsor.getUnknown4() << ENDOFLINE;
	out << sponsor.getUnknown5() << ENDOFLINE;
	out << sponsor.getFontScript() << ENDOFLINE;
	out << sponsor.getUnknown6() << ENDOFLINE;
	out << sponsor.getUnknown7() << ENDOFLINE;
	out << sponsor.getUnknown8() << ENDOFLINE;
	out << sponsor.getUnknown9() << ENDOFLINE;
	out << sponsor.getUnknown10() << ENDOFLINE;
	out << sponsor.getFont() << ENDOFLINE;
	out << sponsor.getBackgroundColorSize() << ENDOFLINE;
	out << sponsor.getTextColor() << ENDOFLINE;
}