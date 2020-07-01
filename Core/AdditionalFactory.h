#pragma once

#include "Additional.h"
#include "EasyLogger.h"

namespace Core
{
	class AdditionalFactory
	{
	public:
		AdditionalFactory(const Logger& logger) : logger(logger) {}

		Additional createFromSAV(std::vector<std::string> dataUefa, short countLines, short valuesPerLine, std::vector<std::string> data, std::vector<std::string> dataEmwm, std::vector<std::string> dataOutfitter);
		static void writeToSAVUefa(Additional& additional, std::ofstream& out);
		static void writeToSAVMisc(Additional& additional, std::ofstream& out);
		static void writeToSAVEmwm(Additional& additional, std::ofstream& out);
		static void writeToSAVOutfitter(Additional& additional, std::ofstream& out);

	private:
		Logger logger;
	};
}