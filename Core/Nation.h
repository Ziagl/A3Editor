#pragma once

#include <string>
#include <time.h>

namespace Core
{
	class Nation
	{
		friend class NationFactory;
	public:
		Nation() : continent(0), unknown4(0), unknown5(0), unknown6(0), unknown7(0), unknown8(0), unknown9(0), unknown10(0), unknown11(0) {}
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
		
		// metadata
		short getCountryId() { return countryId; }
		void setCountryId(const short countryId) { this->countryId = countryId; }
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
		short continent = 0;
		std::string shortname;
		short unknown4 = 0;
		short unknown5 = 0;
		short unknown6 = 0;
		short unknown7 = 0;
		short unknown8 = 0;
		short unknown9 = 0;
		short unknown10 = 0;
		short unknown11 = 0;

		// metadata
		short countryId = 0;
	};
}