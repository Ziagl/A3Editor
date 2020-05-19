#pragma once

#include <string>
#include <vector>
#include "Reporter.h"
#include "EasyLogger.h"

namespace Core
{
	class ReporterFactory {
	public:
		ReporterFactory(const Logger& logger) : logger(logger) {}

		Reporter create();
		Reporter createFromSAV(std::vector<std::string> data);
		static void writeToSAV(Reporter& reporter, std::ofstream& out);

	private:
		Logger logger;
	};
}