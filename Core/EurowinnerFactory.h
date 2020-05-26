#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Eurowinner.h"
#include "EasyLogger.h"

namespace Core
{
	class EurowinnerFactory {
	public:
		EurowinnerFactory(const Logger& logger) : logger(logger) {}

		Eurowinner createFromSAV(std::vector<std::string> data);
		static void writeToSAV(Eurowinner& eurowinner, std::ofstream& out);

	private:
		Logger logger;
	};
}