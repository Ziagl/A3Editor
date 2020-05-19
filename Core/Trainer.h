#pragma once

#include "Person.h"

namespace Core
{
	class Trainer : public Person
	{
		friend class TrainerFactory;
	public:
		Trainer() {}

		// getter/setter
		short getCompetence() { return competence; }
		short getReputation() { return reputation; }
		short getAge() { return age; }
		short getUnknown1() { return unknown1; }
		short getUnknown2() { return unknown2; }
	protected:
		void setCompetence(const short competence) { this->competence = competence; }
		void setReputation(const short reputation) { this->reputation = reputation; }
		void setAge(const short age) { this->age = age; }
		void setUnknown1(const short unknown1) { this->unknown1 = unknown1; }
		void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
	private:
		short competence;
		short reputation;
		short age;			// nonsense because of birthday
		short unknown1;
		short unknown2;
	};
}