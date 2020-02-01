#pragma once

#include <string>
#include <vector>

namespace Core {
	class CountriesWithLeagues
	{
	public:
		CountriesWithLeagues(std::string filename);

		std::vector<std::string> GetList() { return list; }
	private:
		std::vector<std::string> list;
	};
}