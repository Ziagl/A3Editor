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

private:
	Logger logger;
};