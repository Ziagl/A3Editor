#include "ReporterFactory.h"
#include <fstream>

using namespace Core;

Reporter ReporterFactory::create()
{
	return Reporter();
}

Reporter ReporterFactory::createFromSAV(std::vector<std::string> data)
{
	Reporter reporter;

	if (data.empty())
	{
		logger->writeErrorEntry("Reporter data is empty.");
		return reporter;
	}

	reporter.setChannel(data[0]);
	reporter.setLastname(data[1]);
	reporter.setFirstname(data[2]);
	reporter.setCharacter(std::stoi(data[3]));

	return reporter;
}

void ReporterFactory::writeToSAV(Reporter& reporter, std::ofstream& out)
{
	out << reporter.getChannel() << "\n";
	out << reporter.getLastname() << "\n";
	out << reporter.getFirstname() << "\n";
	out << reporter.getCharacter() << "\n";
}