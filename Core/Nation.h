#pragma once

#include <string>
#include <time.h>

namespace Core
{
	class Nation
	{
		friend class NationFactory;
	public:
		Nation() {}
		~Nation() {}

		// getter/setter
		std::string getName() { return name; }
		short getContinent() { return continent; }
		std::string getShortname() { return shortname; }
		short getUnknown4() { return unknown4; }
		short getUnknown5() { return unknown5; }
		short getUnknown6() { return unknown6; }
		short getUnknown7() { return unknown7; }
		short getUnknown8() { return unknown8; }
		short getUnknown9() { return unknown9; }
		short getUnknown10() { return unknown10; }
		short getUnknown11() { return unknown11; }
	protected:
		void setName(const std::string name) { this->name = name; }
		void setContinent(const short continent) { this->continent = continent; }
		void setShortname(const std::string shortname) { this->shortname = shortname; }
		void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
		void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
		void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
		void setUnknown7(const short unknown7) { this->unknown7 = unknown7; }
		void setUnknown8(const short unknown8) { this->unknown8 = unknown8; }
		void setUnknown9(const short unknown9) { this->unknown9 = unknown9; }
		void setUnknown10(const short unknown10) { this->unknown10 = unknown10; }
		void setUnknown11(const short unknown11) { this->unknown11 = unknown11; }
	private:
		std::string name;
		short continent;
		std::string shortname;
		short unknown4;
		short unknown5;
		short unknown6;
		short unknown7;
		short unknown8;
		short unknown9;
		short unknown10;
		short unknown11;
	};
}