#pragma once

#include <string>
#include <vector>

namespace Core
{
	class PlayableCountries
	{
	public:
		PlayableCountries(std::string filename);

		std::vector<std::string> GetList() { return list; }
	private:
		std::vector<std::string> list;
	};
}