#pragma once

#include <string>
#include <time.h>

class Person
{
public:
	Person() {}
	Person(const std::string firstname, const std::string lastname, const std::string birthday) : firstname(firstname), lastname(lastname), birthday(birthday) {}

	// getter/setter
	std::string getFirstname() { return firstname; }
	std::string getLastname() { return lastname; }
	std::string getBirthday() { return birthday; }
protected:
	void setFirstname(const std::string firstname) { this->firstname = firstname; }
	void setLastname(const std::string lastname) { this->lastname = lastname; }
	void setBirthday(const std::string birthday) { this->birthday = birthday; }
private:
	std::string firstname;
	std::string lastname;
	std::string birthday;
};