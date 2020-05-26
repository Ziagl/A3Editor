#pragma once

#include "Person.h"

namespace Core
{
	class Celebrity : public Person
	{
		friend class CelebrityFactory;
	public:
		Celebrity() : favoriteTeam(0) {}
		~Celebrity() {}

		int getFavoriteTeam() { return favoriteTeam; }
	protected:
		void setFavoriteTeam(const int favoriteTeam) { this->favoriteTeam = favoriteTeam; }
	private:
		int favoriteTeam = 0;
	};
}