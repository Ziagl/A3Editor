#pragma once

#include <vector>

namespace Core
{
	class Competition
	{
	public:
		Competition() {}
		~Competition() {}

		// getter
		std::vector<std::vector<std::tuple<short, short>>> getChampionsLeague() { return championsLeague; }
		std::vector<std::vector<std::tuple<short, short>>> getEM() { return em; }
		std::vector<std::vector<std::tuple<short, short>>> getWM() { return wm; }

		// setter
		void setChampionsLeague(std::vector<std::vector<std::tuple<short, short>>> championsLeague) { this->championsLeague = championsLeague; }
		void setEM(std::vector<std::vector<std::tuple<short, short>>> em) { this->em = em; }
		void setWM(std::vector<std::vector<std::tuple<short, short>>> wm) { this->wm = wm; }

	private:
		std::vector<std::vector<std::tuple<short, short>>> championsLeague;		// champions league
		std::vector<std::vector<std::tuple<short, short>>> em;					// european championship
		std::vector<std::vector<std::tuple<short, short>>> wm;					// world cup
	};
}