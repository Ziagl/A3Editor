#pragma once

#include <string>
#include <vector>
#include "Manager.h"
#include "LoggingFacility.h"

class ManagerFactory {
public:
	ManagerFactory(const Logger& logger) : logger(logger) {}

	Manager create();
	Manager createFromSAV(std::vector<std::string> data);

private:
	Logger logger;
};