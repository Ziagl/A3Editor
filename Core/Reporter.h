#pragma once

#include "Person.h"

namespace Core
{
	class Reporter : public Person
	{
	public:
		Reporter() : character(0) {}
		~Reporter() {}

		// getter
		std::string getChannel() { return channel; }
		short getCharacter() { return character; }
		// setter
		void setChannel(const std::string channel) { this->channel = channel; }
		void setCharacter(const short character) { this->character = character; }
	private:
		std::string channel;
		short character = 0;
	};
}