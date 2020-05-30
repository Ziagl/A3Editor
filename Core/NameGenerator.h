#pragma once

#include <vector>
#include <tuple>
#include <string>
#include "EasyLogger.h"

namespace Core
{
	class NameGenerator
	{
	public:
		NameGenerator(const Logger& logger);
		~NameGenerator() {}

		std::tuple<std::string, std::string> createName();

	private:
		void loadFromFile(std::string path);
        std::string getline(std::ifstream& stream);

		std::vector<std::string> firstname;
		std::vector<std::string> lastname;

		Logger logger;
	};
}