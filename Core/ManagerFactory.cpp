#include "ManagerFactory.h"
#include <fstream>

using namespace Core;

Manager ManagerFactory::create()
{
	return Manager();
}

Manager ManagerFactory ::createFromSAV(std::vector<std::string> data)
{
	Manager manager;

	if (data.empty())
	{
		logger->writeErrorEntry("Manager data is empty.");
		return manager;
	}

	manager.setFirstname(data[0]);
	manager.setLastname(data[1]);
	manager.setCompetence(std::stoi(data[2]));
	manager.setAge(std::stoi(data[3]));
	manager.setBirthday(data[4]);

	return manager;
}

void ManagerFactory::writeToSAV(Manager& manager, std::ofstream& out)
{
	out << manager.getFirstname() << "\n";
	out << manager.getLastname() << "\n";
	out << manager.getCompetence() << "\n";
	out << manager.getAge() << "\n";
	out << manager.getBirthday() << "\n";
}