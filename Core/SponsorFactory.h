#pragma once

#include <string>
#include <vector>
#include "Sponsor.h"
#include "LoggingFacility.h"

class SponsorFactory 
{
public:
	SponsorFactory(const Logger& logger) : logger(logger) {}

	Sponsor create();
	Sponsor createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Sponsor& sponsor, std::ofstream& out);

private:
	Logger logger;
};