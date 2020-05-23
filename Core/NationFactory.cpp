#include "NationFactory.h"
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
	out << nation.getName() << "\n";
	out << nation.getContinent() << "\n";
	out << nation.getShortname() << "\n";
	out << nation.getUnknown4() << "\n";
	out << nation.getUnknown5() << "\n";
	out << nation.getUnknown6() << "\n";
	out << nation.getUnknown7() << "\n";
	out << nation.getUnknown8() << "\n";
	out << nation.getUnknown9() << "\n";
	out << nation.getUnknown10() << "\n";
	out << nation.getUnknown11() << "\n";
}