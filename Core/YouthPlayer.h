#pragma once

#include <string>
#include <string_view>
#include "Person.h"
#include "EasyLogger.h"

namespace Core
{
	class YouthPlayer : public Person
	{
	public:
		YouthPlayer() : mainPosition(0), teamId(0) { }
		~YouthPlayer() {}

		// getter
		short getMainPosition() { return mainPosition; }
		short getTeamId() { return teamId; }
		// setter
		void setMainPosition(short mainPosition) { this->mainPosition = mainPosition; }
		void setTeamId(short teamId) { this->teamId = teamId; }

	private:
		short mainPosition = 0;
		short teamId = 0;
	};
}