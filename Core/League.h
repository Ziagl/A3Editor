#pragma once

#include <string>
#include <vector>
#include <tuple>

namespace Core
{
	class League
	{
		friend class LeagueFactory;
	public:
		League() : teamNumber(0), hierarchy(0) {}
		~League() {}

		// getter
		std::string getName() { return name; }
		std::string getShortname() { return shortname; }
		short getTeamNumber() { return teamNumber; }
		std::vector<short> getTeamIds() { return teamIds; }
		std::vector<std::tuple<short, short>> getSchedule() { return schedule; }
		// setter
		void setName(const std::string name) { this->name = name; }
		void setShortname(const std::string shortname) { this->shortname = shortname; }
		void setTeamNumber(const short teamNumber) { this->teamNumber = teamNumber; }
		void setTeamIds(const std::vector<short> teamIds) { this->teamIds = teamIds; }
		void setSchedule(const std::vector<std::tuple<short, short>> schedule) { this->schedule = schedule; }

		//metadata
		std::string getFilename() { return filename; }
		short getHierarchy() { return hierarchy; }

	private:
		// metadata
		void setFilename(std::string filename) { this->filename = filename; }
		void setHierarchy(short hierarchy) { this->hierarchy = hierarchy; }

		std::string name;
		std::string shortname;
		short teamNumber;
		std::vector<short> teamIds;						// list of team ids that are in this league
														// id is a 1 based enumeration of Land****.sav file
		std::vector<std::tuple<short, short>> schedule;

		// metadata
		std::string filename;	// filename A3Legacy
		short hierarchy = 0;	// needed to identify hierarchy tree of leages of country (looks as if that was hardcoded in original code)
	};
}