#pragma once

#include "YouthPlayer.h"
#include "EasyLogger.h"

namespace Core
{
	class YouthPlayerFactory
	{
	public:
		YouthPlayerFactory(const Logger& logger) : logger(logger) {}

		YouthPlayer createFromSAV(std::vector<std::string> data);
		static void writeToSAV(YouthPlayer& youthPlayer, std::ofstream& out);

	private:
		Logger logger;
	};
}