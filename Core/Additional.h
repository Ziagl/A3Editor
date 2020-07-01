#pragma once

#include <vector>
#include <algorithm>

namespace Core
{
	struct UefaCountry
	{
		short countryId;
		std::vector<short> years;
		short sum;
	};

	class Additional
	{
	public:
		Additional() {}
		~Additional() {}

		// getter
		std::vector<UefaCountry> getValue() { return value; }
		// setter
		void setValue(const std::vector<UefaCountry> value) { this->value = value; sortList(); }
		void setValue(const UefaCountry value, const int index)
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
			std::vector<UefaCountry> temp(value.begin(), value.end() - 2);	// create sub vector
			std::sort(temp.begin(), temp.end(),							// sort sub vector
				[](const UefaCountry& a, const UefaCountry& b) -> bool
			{
				return a.sum > b.sum;
			});
			for (int i = 0; i < temp.size(); ++i)						// merge sub vector into original
				value.at(i) = temp.at(i);
		}

		std::vector<UefaCountry> value;
	};
}