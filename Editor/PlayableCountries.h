#pragma once

#include <string>
#include <vector>
#include "GraphFactory.h"

namespace Editor {
	// wrapper class for Core PlayableCountries
	class PlayableCountries
	{
	public:
		PlayableCountries(std::shared_ptr<Core::Graph> graph) 
		{
			playableCountries = graph->getPlayableCountries();
			for (std::vector<std::tuple<vertex_t, vertex_t>>::iterator it = playableCountries.begin();
				it < playableCountries.end();
				++it)
			{
				auto nation = graph->getNationById(std::get<1>(*it));
				list.push_back(nation->getShortname());
			}
		}

		std::vector<std::string> GetList() { return list; }
	private:
		std::vector<std::tuple<vertex_t, vertex_t>> playableCountries;
		std::vector<std::string> list;
	};
}