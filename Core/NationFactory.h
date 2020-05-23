#pragma once

#include <string>
#include <vector>
#include "Nation.h"
#include "EasyLogger.h"

namespace Core
{
	class NationFactory {
	public:
		NationFactory(const Logger& logger) : logger(logger) {}

		Nation create();
		Nation createFromSAV(std::vector<std::string> data);
		static void writeToSAV(Nation& nation, std::ofstream& out);

	private:
		Logger logger;
	};
}