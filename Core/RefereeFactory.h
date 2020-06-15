#pragma once

#include <string>
#include <vector>
#include "Referee.h"
#include "EasyLogger.h"

namespace Core
{
	class RefereeFactory {
	public:
		RefereeFactory(const Logger& logger) : logger(logger) {}

		Referee create();
		Referee createFromSAV(std::vector<std::string> data, bool firstlast = true);
		static void writeToSAV(Referee& referee, std::ofstream& out, bool firstlast = true);

	private:
		Logger logger;
	};
}