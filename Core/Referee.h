#pragma once

#include <string>
#include "Person.h"

namespace Core
{
	class Referee : public Person
	{
	public:
		Referee() : competence(0), hardness(0), unpopularTeamNationality(0), homeReferee(0), guestReferee(0), hatesGripe(0), hatesTimeGame(0), hatesCoaching(0) {}
		~Referee() {}

		// getter
		short getCompetence() { return competence; }
		short getHardness() { return hardness; }
		int getUnpopularTeamNationality() { return unpopularTeamNationality; }
		bool getHomeReferee() { return homeReferee; }
		bool getGuestReferee() { return guestReferee; }
		bool getHatesGripe() { return hatesGripe; }
		bool getHatesTimeGame() { return hatesTimeGame; }
		bool getHatesCoaching() { return hatesCoaching; }
		// setter
		void setCompetence(const short competence) { this->competence = competence; }
		void setHardness(const short hardness) { this->hardness = hardness; }
		void setUnpopularTeamNationality(const int unpopularTeamNationality) { this->unpopularTeamNationality = unpopularTeamNationality; }
		void setHomeReferee(const bool homeReferee) { this->homeReferee = homeReferee; }
		void setGuestReferee(const bool guestReferee) { this->guestReferee = guestReferee; }
		void setHatesGripe(const bool hatesGripe) { this->hatesGripe = hatesGripe; }
		void setHatesTimeGame(const bool hatesTimeGame) { this->hatesTimeGame = hatesTimeGame; }
		void setHatesCoaching(const bool hatesCoaching) { this->hatesCoaching = hatesCoaching; }
	private:
		short competence = 0;
		short hardness = 0;
		int unpopularTeamNationality = 0;		// this field is teamId of unpopular team for country referees or nationality for international referees
		bool homeReferee = 0;
		bool guestReferee = 0;
		bool hatesGripe = 0;
		bool hatesTimeGame = 0;
		bool hatesCoaching = 0;
	};
}