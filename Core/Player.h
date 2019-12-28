#pragma once

#include <string>
#include <string_view>
#include "LoggingFacility.h"

class Player
{
public:
	explicit Player(const Logger& logger, std::string firstname, std::string lastname) : logger(logger), firstName(firstname), lastName(lastname), value(0.0f) {};
	~Player() {};

	// Getter / Setter
	std::string_view getFirstname() { return firstName; }
	void setFirstname(std::string firstname) { this->firstName = firstname; }

	std::string_view getLastname() { return lastName; }
	void setLastname(std::string lastname) { this->lastName = lastname; }

private:
	std::string firstName;
	std::string lastName;
	std::string artistName;

	short age;
	time_t birthday;

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