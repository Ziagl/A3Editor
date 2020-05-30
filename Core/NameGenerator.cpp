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
    line = getline(csvread);
	while(!line.empty())
	{
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

        //read next line
        line = getline(csvread);
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
    line = getline(csvread);
	while (!line.empty())
	{
		if (line.empty())				// skip empty lines:
			continue;

		std::istringstream iss(line);
		std::string lineStream;

		std::getline(iss, lineStream, ',');	// index
		std::getline(iss, lineStream, ','); // name
		lastname.push_back(lineStream);
		std::getline(iss, lineStream, ','); // language

        //read next line
        line = getline(csvread);
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
 * this method encapsulates std::getine for same results for Windows and Linux
 * it fixes \r\n vs \n line ending conflicts 
 */
std::string NameGenerator::getline(std::ifstream& stream)
{
    std::string result;
    std::string line;
    if(std::getline(stream, line))
	{
#ifdef __LINUX__
        // fix \r problem for linux
        if (line[line.size() - 1] == '\r')
        {
            result = line.substr(0, line.size()-1);
        }
#else
        result = line;
#endif
    }
    return result;
}