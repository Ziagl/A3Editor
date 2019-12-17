#pragma once

#include <string>
#include <string_view>
#include "LoggingFacility.h"

class Player
{
public:
	explicit Player(const Logger& logger, std::string firstname, std::string lastname) : logger(logger), firstname(firstname), lastname(lastname), value(0.0f) {};
	~Player() {};

	// Getter / Setter
	std::string_view getFirstname() { return firstname; }
	void setFirstname(std::string firstname) { this->firstname = firstname; }

	std::string_view getLastname() { return lastname; }
	void setLastname(std::string lastname) { this->lastname = lastname; }

private:
	std::string firstname;
	std::string lastname;
	
	float value;

	Logger logger;
};