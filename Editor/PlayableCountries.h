#pragma once

#include "../Core/PlayableCountries.h"
#include <string>
#include <vector>

namespace Editor {
	// wrapper class for Core PlayableCountries
	class PlayableCountries
	{
	public:
		PlayableCountries(std::string filename) : playableCountries(filename) {}

		std::vector<std::string> GetList() { return playableCountries.GetList(); }
	private:
		Core::PlayableCountries playableCountries;
	};
}