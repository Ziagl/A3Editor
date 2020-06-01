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
		League() {}
		League(const std::string name, const std::string shortname, const short teamNumber) : name(name), shortname(shortname), teamNumber(teamNumber) {}

		// getter/setter
		std::string getName() { return name; }
		std::string getShortname() { return shortname; }
		short getTeamNumber() { return teamNumber; }
		short getUnknown1() { return unknown1; }
		short getUnknown2() { return unknown2; }
		short getUnknown3() { return unknown3; }
		short getUnknown4() { return unknown4; }
		short getUnknown5() { return unknown5; }
		short getUnknown6() { return unknown6; }
		short getUnknown7() { return unknown7; }
		short getUnknown8() { return unknown8; }
		short getUnknown9() { return unknown9; }
		short getUnknown10() { return unknown10; }
		std::vector<std::tuple<short, short>> getSchedule() { return schedule; }
	protected:
		void setName(const std::string name) { this->name = name; }
		void setShortname(const std::string shortname) { this->shortname = shortname; }
		void setTeamNumber(const short teamNumber) { this->teamNumber = teamNumber; }
		void setUnknown1(const short unknown1) { this->unknown1 = unknown1; }
		void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
		void setUnknown3(const short unknown3) { this->unknown3 = unknown3; }
		void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
		void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
		void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
		void setUnknown7(const short unknown7) { this->unknown7 = unknown7; }
		void setUnknown8(const short unknown8) { this->unknown8 = unknown8; }
		void setUnknown9(const short unknown9) { this->unknown9 = unknown9; }
		void setUnknown10(const short unknown10) { this->unknown10 = unknown10; }
		void setSchedule(const std::vector<std::tuple<short, short>> schedule) { this->schedule = schedule; }
	private:
		std::string name;
		std::string shortname;
		short teamNumber;
		short unknown1;
		short unknown2;
		short unknown3;
		short unknown4;
		short unknown5;
		short unknown6;
		short unknown7;
		short unknown8;
		short unknown9;
		short unknown10;
		std::vector<std::tuple<short, short>> schedule;
	};
}