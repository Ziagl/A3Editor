#pragma once

#include <string>
#include "Person.h"

namespace Core
{
	class Referee : public Person
	{
		friend class RefereeFactory;
	public:
		Referee() {}
		~Referee() {}

		// getter/setter
		short getCompetence() { return competence; }
		short getHardness() { return hardness; }
		int getUnpopularTeam() { return unpopularTeam; }
		bool getHomeReferee() { return homeReferee; }
		bool getGuestReferee() { return guestReferee; }
		bool getHatesGripe() { return hatesGripe; }
		bool getHatesTimeGame() { return hatesTimeGame; }
		bool getHatesCoaching() { return hatesCoaching; }

	protected:
		void setCompetence(const short competence) { this->competence = competence; }
		void setHardness(const short hardness) { this->hardness = hardness; }
		void setUnpopularTeam(const int unpopularTeam) { this->unpopularTeam = unpopularTeam; }
		void setHomeReferee(const bool homeReferee) { this->homeReferee = homeReferee; }
		void setGuestReferee(const bool guestReferee) { this->guestReferee = guestReferee; }
		void setHatesGripe(const bool hatesGripe) { this->hatesGripe = hatesGripe; }
		void setHatesTimeGame(const bool hatesTimeGame) { this->hatesTimeGame = hatesTimeGame; }
		void setHatesCoaching(const bool hatesCoaching) { this->hatesCoaching = hatesCoaching; }
	private:
		short competence;
		short hardness;
		int unpopularTeam;
		bool homeReferee;
		bool guestReferee;
		bool hatesGripe;
		bool hatesTimeGame;
		bool hatesCoaching;
	};
}