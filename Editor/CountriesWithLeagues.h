#pragma once

#include "../Core/CountriesWithLeagues.h"
#include <string>
#include <vector>

namespace Editor {
	// wrapper class for Core CountriesWithLeagues
	class CountriesWithLeagues
	{
	public:
		CountriesWithLeagues(std::string filename) : countriesWithLeagues(filename) {}

		std::vector<std::string> GetList() { return countriesWithLeagues.GetList(); }
	private:
		Core::CountriesWithLeagues countriesWithLeagues;
	};
}