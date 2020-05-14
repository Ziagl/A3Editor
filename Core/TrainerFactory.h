#pragma once

#include <string>
#include <vector>
#include "Trainer.h"
#include "LoggingFacility.h"

class TrainerFactory {
public:
	TrainerFactory(const Logger& logger) : logger(logger) {}

	Trainer create();
	Trainer createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Trainer& trainer, std::ofstream& out, bool goalkeeper=false);

private:
	Logger logger;
};