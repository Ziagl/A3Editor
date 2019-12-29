#pragma once

#include "Person.h"

class Manager : public Person
{
	friend class ManagerFactory;
public:
	Manager() {}
	
	// getter/setter
	short getCompetence() { return competence; }
protected:
	void setCompetence(const short competence) { this->competence = competence; }
	void setAge(const short age) { this->age = age; }
private:
	short competence;
	short age;			// nonsense because of birthday
};