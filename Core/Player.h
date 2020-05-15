#pragma once

#include <string>
#include <string_view>
#include "Person.h"
#include "LoggingFacility.h"

class Player : public Person
{
	friend class PlayerFactory;
public:
	Player() {}
	Player(const Logger& logger) : logger(logger) {}
	~Player() {}

	// getter/setter
	short getSkinColor() { return skinColor; }
	short getHairColor() { return hairColor; }
	short getAge() { return age; }
	short getSkill() { return skill; }
	short getNationalityFirst() { return nationalityFirst; }
	bool getResidient() { return residient; }
	short getMainPosition() { return mainPosition; }
	short getAlternativeFirstPosition() { return alternativeFristPosition; }
	short getAlternativeSecondPosition() { return alternativeSecondPosition; }
	int getPlayerSkillPositive() { return playerSkillPositive; }
	int getPlayerSkillNegative() { return playerSkillNegative; }
	int getPlayerProperties() { return playerProperties; }
	int getPlayerCharacter() { return playerCharacter; }
	bool getHasArtistName() { return hasArtistName; }
	std::string getArtistName() { return artistName; }
	short getFoot() { return foot; }
	short getTalent() { return talent; }
	short getHealth() { return health; }
	short getAudience() { return audience; }
	short getNationalitySecond() { return nationalitySecond; }
	bool getNationalPlayer() { return nationalPlayer; }
	bool getNationalPlayerResigned() { return nationalPlayerResigned; }
	bool getNationalTeam() { return nationalTeam; }
	bool getCaptainResigned() { return captainResigned; }
	short getBackNumber() { return backNumber; }
	long getAppearence() { return appearence; }
	short getUnknown1() { return unknown1; }
	short getUnknown2() { return unknown2; }
	short getUnknown3() { return unknown3; }
	short getUnknown4() { return unknown4; }
	short getUnknown5() { return unknown5; }
	short getUnknown6() { return unknown6; }
	short getUnknown7() { return unknown7; }

protected:
	void setSkinColor(const short skinColor) { this->skinColor = skinColor; }
	void setHairColor(const short hairColor) { this->hairColor = hairColor; }
	void setAge(const short age) { this->age = age; }
	void setSkill(const short skill) { this->skill = skill; }
	void setNationalityFirst(const short nationalityFirst) { this->nationalityFirst = nationalityFirst; }
	void setResidient(const bool residient) { this->residient = residient; }
	void setMainPosition(const short mainPosition) { this->mainPosition = mainPosition; }
	void setAlternativeFirstPosition(const short alternativeFirstPosition) { this->alternativeFristPosition = alternativeFirstPosition; }
	void setAlternativeSecondPosition(const short alternativeSecondPosition) { this->alternativeSecondPosition = alternativeSecondPosition; }
	void setPlayerSkillPositive(const int playerSkillPositive) { this->playerSkillPositive = playerSkillPositive; }
	void setPlayerSkillNegative(const int playerSkillNegative) { this->playerSkillNegative = playerSkillNegative; }
	void setPlayerProperties(const int playerProperties) { this->playerProperties = playerProperties; }
	void setPlayerCharacter(const int playerCharacter) { this->playerCharacter = playerCharacter; }
	void setHasArtistName(const bool hasArtistName) { this->hasArtistName = hasArtistName; }
	void setArtistName(const std::string artistName) { this->artistName = artistName; }
	void setFoot(const short foot) { this->foot = foot; }
	void setTalent(const short talent) { this->talent = talent; }
	void setHealth(const short health) { this->health = health; }
	void setAudience(const short audience) { this->audience = audience; }
	void setNationalitySecond(const short nationalitySecond) { this->nationalitySecond = nationalitySecond; }
	void setNationalPlayer(const bool nationalPlayer) { this->nationalPlayer = nationalPlayer; }
	void setNationalPlayerResigned(const bool nationalPlayerResigned) { this->nationalPlayerResigned = nationalPlayerResigned; }
	void setNationalTeam(const bool nationalTeam) { this->nationalTeam =  nationalTeam; }
	void setCaptainResigned(const bool captainResigned) { this->captainResigned = captainResigned; }
	void setBackNumber(const short backNumber) { this->backNumber = backNumber; }
	void setAppearence(const long appearence) { this->appearence = appearence; }
	void setUnknown1(const short unknown1) { this->unknown1 = unknown1; }
	void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
	void setUnknown3(const short unknown3) { this->unknown3 = unknown3; }
	void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
	void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
	void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
	void setUnknown7(const short unknown7) { this->unknown7 = unknown7; }
private:
	bool hasArtistName;
	std::string artistName;
	short age;					// nonsense because of birthday
	short skinColor;
	short hairColor;
	short skill;
	short nationalityFirst;
	bool residient;
	short mainPosition;
	short alternativeFristPosition;
	short alternativeSecondPosition;
	int playerSkillPositive;		// bitmask for goalkeeper or field player
	int playerSkillNegative;
	int playerProperties;			// bitmask
	int playerCharacter;			// bitmask
	short foot;
	short talent;
	short health;
	short audience;
	short nationalitySecond;
	bool nationalPlayer;
	bool nationalPlayerResigned;
	bool nationalTeam;
	bool captainResigned;
	short backNumber;
	long appearence;			// bitmask for hair type and beard

	short unknown1;
	short unknown2;
	short unknown3;
	short unknown4;
	short unknown5;
	short unknown6;
	short unknown7;

	Logger logger;
};