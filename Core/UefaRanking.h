#pragma once

#include <vector>
#include <algorithm>

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
		void setValue(const std::vector<UefaTeam> value) { this->value = value; sortList(); }
		void setValue(const UefaTeam value, const int index) 
		{ 
			if (index < this->value.size()) 
			{ 
				this->value.at(index) = value; 
				sortList(); 
			} 
		}
	private:
		void sortList()
		{
			// do not sort last 2 entries!
			std::vector<UefaTeam> temp(value.begin(), value.end() - 2);	// create sub vector
			std::sort(temp.begin(), temp.end(),							// sort sub vector
				[](const UefaTeam& a, const UefaTeam& b) -> bool
			{
				return a.sum > b.sum;
			});
			for (int i = 0; i < temp.size(); ++i)						// merge sub vector into original
				value.at(i) = temp.at(i);
		}

		std::vector<UefaTeam> value;
	};
}