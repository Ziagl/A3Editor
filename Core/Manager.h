#pragma once

#include "Person.h"

namespace Core
{
	class Manager : public Person
	{
		friend class ManagerFactory;
	public:
		Manager() {}

		// getter/setter
		short getCompetence() { return competence; }
		short getAge() { return age; }
	protected:
		void setCompetence(const short competence) { this->competence = competence; }
		void setAge(const short age) { this->age = age; }
	private:
		short competence;
		short age;			// nonsense because of birthday
	};
}