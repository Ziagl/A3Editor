#pragma once

#include <string>

class Country
{
public:
	Country(const std::string cup, const short countryId, const short unknown2, const short unknown4, const short unknown5, const short unknown6) :
			cup(cup), countryId(countryId), unknown2(unknown2), unknown4(unknown4), unknown5(unknown5), unknown6(unknown6) {}

	// getter/setter
	std::string getCupName() { return cup; }
	short getCountryId() { return countryId; }

private:
	std::string cup;
	short countryId;

	short unknown2;
	short unknown4;
	short unknown5;
	short unknown6;
};