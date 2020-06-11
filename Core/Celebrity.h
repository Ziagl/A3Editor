#pragma once

#include "Person.h"

namespace Core
{
	class Celebrity : public Person
	{
	public:
		Celebrity() : favoriteTeam(0) {}
		~Celebrity() {}

		// getter
		int getFavoriteTeam() { return favoriteTeam; }
		// setter
		void setFavoriteTeam(const int favoriteTeam) { this->favoriteTeam = favoriteTeam; }

	private:
		int favoriteTeam = 0;
	};
}