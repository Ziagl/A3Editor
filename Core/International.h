#pragma once

#include <string>
#include <vector>
#include "Referee.h"

namespace Core
{
	struct InternationalTeam
	{
		short nationId;		// id of nation in Laender.sav file
		std::string name;	// name of team
	};

	class International
	{
	public:
		International() {}
		~International() {}

		// getter
		std::vector<Referee> getReferees() { return referees; }
		std::vector<InternationalTeam> getTeams() { return teams; }
		// setter
		void setReferees(std::vector<Referee>& referees) { this->referees = referees; }
		void setTeams(std::vector<InternationalTeam>& teams) { this->teams = teams; }

	private:
		std::vector<InternationalTeam> teams;
		std::vector<Referee> referees;
	};
}