#include "NameGenerator.h"
#include "RandomNumberGenerator.h"
#include <fstream>
#include <sstream>

using namespace Core;

NameGenerator::NameGenerator(const Logger& logger) : logger(logger)
{
#ifdef __LINUX__
    loadFromFile("../../Game/data/");                  // TODO: über Konfiguration laden
#else
	loadFromFile("../Game/data/");                  // TODO: über Konfiguration laden
#endif
}

void NameGenerator::loadFromFile(std::string path)
{
	std::string filename = path + "firstnames.csv";		// TODO: über Konfiguration laden
	std::ifstream csvread;
	std::string line;
	
	csvread.open(filename, std::ios::in);
	if (!csvread.is_open()) 
	{
		logger->writeErrorEntry("Error while reading " + filename);
		csvread.close();
		return;
	}

	while(std::getline(csvread, line))
	{
		line = fixLineEnding(line);
		if (line.empty())				// skip empty lines:
			continue;

		std::istringstream iss(line);
		std::string lineStream;

		std::getline(iss, lineStream, ',');	// index
		std::getline(iss, lineStream, ','); // name
		firstname.push_back(lineStream);
		std::getline(iss, lineStream, ','); // male
		std::getline(iss, lineStream, ','); // female
		std::getline(iss, lineStream, ','); // language

	}
	csvread.close();

	filename = path + "lastnames.csv";					// TODO: über Konfiguration laden
	csvread.open(filename, std::ios::in);
	if (!csvread.is_open())
	{
		logger->writeErrorEntry("Error while reading " + filename);
		csvread.close();
		return;
	}

	while (std::getline(csvread, line))
	{
		line = fixLineEnding(line);
		if (line.empty())				// skip empty lines:
			continue;

		std::istringstream iss(line);
		std::string lineStream;

		std::getline(iss, lineStream, ',');	// index
		std::getline(iss, lineStream, ','); // name
		lastname.push_back(lineStream);
		std::getline(iss, lineStream, ','); // language

	}
	csvread.close();
}

std::tuple<std::string, std::string> NameGenerator::createName()
{
	std::string firstname;
	std::string lastname;
	
	firstname = this->firstname[RandomNumberGenerator::randomNumber(0, static_cast<int>(this->firstname.size()))];
	lastname = this->lastname[RandomNumberGenerator::randomNumber(0, static_cast<int>(this->lastname.size()))];

	return std::make_tuple(firstname, lastname);
}

/*
 * this method fixes \r\n vs \n line ending conflicts from Windows and Linux
 */
std::string NameGenerator::fixLineEnding(std::string line)
{
#ifdef __LINUX__
	// fix \r problem for linux
	if (line[line.size() - 1] == '\r')
	{
		return line.substr(0, line.size() - 1);
	}
#else
	return line;
#endif
}