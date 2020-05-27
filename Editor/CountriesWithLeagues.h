#pragma once

#include <string>
#include <vector>
#include "GraphFactory.h"

namespace Editor {
	// wrapper class for Core CountriesWithLeagues
	class CountriesWithLeagues
	{
	public:
		CountriesWithLeagues(std::shared_ptr<Core::Graph> graph) 
		{
			countriesWithLeagues = graph->getCountriesWithLeagues();
			for (std::vector<std::tuple<vertex_t, vertex_t>>::iterator it = countriesWithLeagues.begin();
				it < countriesWithLeagues.end();
				++it)
			{
				auto nation = graph->getNationById(std::get<1>(*it));
				list.push_back(nation->getShortname());
			}
		}

		std::vector<std::string> GetList() { return list; }
	private:
		std::vector<std::tuple<vertex_t, vertex_t>> countriesWithLeagues;
		std::vector<std::string> list;
	};
}