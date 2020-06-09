#pragma once

#include <vector>

namespace Core
{
	struct UefaTeam
	{
		short countryId;
		std::vector<short> years;
		short sum;
	};

	class UefaRanking
	{
	public:
		UefaRanking() {}
		~UefaRanking() {}

		// getter
		std::vector<UefaTeam> getValue() { return value; }
		// setter
		void setValue(const std::vector<UefaTeam> value) { this->value = value; }
	private:
		std::vector<UefaTeam> value;
	};
}