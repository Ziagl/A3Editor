#pragma once

#include <string>
#include <vector>
#include "Manager.h"
#include "EasyLogger.h"

class ManagerFactory {
public:
	ManagerFactory(const Logger& logger) : logger(logger) {}

	Manager create();
	Manager createFromSAV(std::vector<std::string> data);
	static void writeToSAV(Manager& manager, std::ofstream &out);

private:
	Logger logger;
};