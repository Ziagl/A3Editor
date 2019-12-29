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
	Player(const Logger& logger) : logger(logger), value(0.0f) {}
	~Player() {}

private:
	std::string artistName;

	short age;

	short skinColor;
	short hairColor;
	short hairType;
	bool unshaven;
	bool beard;
	bool moustache;
	bool goatee;
	
	float value;

	short mainPosition;
	short alternativeFristPosition;
	short alternativeSecondPosition;

	short foot;
	short talent;
	short health;
	short audience;

	bool captainResigned;
	bool residient;
	bool nationalPlayer;
	bool nationalPlayerResigned;

	short backNumber;

	short propertyFirst;
	short propertySecond;
	short characterFirst;
	short characterSecond;

	short nationalityFirst;
	short nationalitySecond;

	short playerSkillFirst;
	short playerSkillSecond;
	short playerSkillThird;

	short goalkeeperSkillFirst;
	short goalkepperSkillSecond;
	short goalkeeperSkillThird;

	Logger logger;
};