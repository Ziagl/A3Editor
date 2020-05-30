#include "NationFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

Nation NationFactory::create() 
{
	return Nation();
}

Nation NationFactory::createFromSAV(std::vector<std::string> data)
{
	Nation nation;

	if (data.empty())
	{
		logger->writeErrorEntry("Nation data is empty.");
		return nation;
	}

	nation.setName(data[0]);
	nation.setContinent(std::stoi(data[1]));
	nation.setShortname(data[2]);
	nation.setUnknown4(std::stoi(data[3]));
	nation.setUnknown5(std::stoi(data[4]));
	nation.setUnknown6(std::stoi(data[5]));
	nation.setUnknown7(std::stoi(data[6]));
	nation.setUnknown8(std::stoi(data[7]));
	nation.setUnknown9(std::stoi(data[8]));
	nation.setUnknown10(std::stoi(data[9]));
	nation.setUnknown11(std::stoi(data[10]));

	return nation;
}

void NationFactory::writeToSAV(Nation& nation, std::ofstream& out)
{
	out << nation.getName() << ENDOFLINE;
	out << nation.getContinent() << ENDOFLINE;
	out << nation.getShortname() << ENDOFLINE;
	out << nation.getUnknown4() << ENDOFLINE;
	out << nation.getUnknown5() << ENDOFLINE;
	out << nation.getUnknown6() << ENDOFLINE;
	out << nation.getUnknown7() << ENDOFLINE;
	out << nation.getUnknown8() << ENDOFLINE;
	out << nation.getUnknown9() << ENDOFLINE;
	out << nation.getUnknown10() << ENDOFLINE;
	out << nation.getUnknown11() << ENDOFLINE;
}