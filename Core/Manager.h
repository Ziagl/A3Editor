#pragma once

#include "Person.h"

namespace Core
{
	class Manager : public Person
	{
	public:
		Manager() : competence(0), age(0) {}
		~Manager() {}

		// getter
		short getCompetence() { return competence; }
		short getAge() { return age; }
		// setter
		void setCompetence(const short competence) { this->competence = competence; }
		void setAge(const short age) { this->age = age; }
	private:
		short competence = 0;
		short age = 0;			// nonsense because of birthday
	};
}