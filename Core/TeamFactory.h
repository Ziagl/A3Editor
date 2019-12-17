#pragma once

#include "Team.h"

class TeamFactory {
public:
	static Team create() {
		return Team();
	}
};