#pragma once

#include "Person.h"
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

	struct EMWM
	{
		short year;
		short type;			// 0...EM, 1...WM
		short nationIndex;
	};

	class Additional
	{
	public:
		Additional() {}
		~Additional() {}

		// getter
		std::vector<UefaCountry> getValue() { return value; }
		Person getPresident() { return president; }
		short getStartingYear() { return startingYear; }
		short getTax() { return tax; }
		short getSubstitutionsFriendlyGames() { return substitutionsFriendlyGames; }
		std::string getChampionsLeagueName() { return championsLeagueName; }
		std::string getEuropeLeagueName() { return europeLeagueName; }
		std::vector<EMWM> getEMWM() { return emwm; }
		std::vector<std::string> getOutfitter() { return outfitter; }
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
		void setPresident(Person& president) { this->president = president; }
		void setStartingYear(short startingYear) { this->startingYear = startingYear; }
		void setTax(short tax) { this->tax = tax; }
		void setSubstitutionsFriendlyGames(short substitutionsFriendlyGames) { this->substitutionsFriendlyGames = substitutionsFriendlyGames; }
		void setChampionsLeagueName(std::string championsLeagueName) { this->championsLeagueName = championsLeagueName; }
		void setEuropeLeagueName(std::string europeLeagueName) { this->europeLeagueName = europeLeagueName; }
		void setEMWM(std::vector<EMWM> emwm) { this->emwm = emwm; }
		void setOutfitter(std::vector<std::string> outfitter) { this->outfitter = outfitter; }
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
		Person president;
		short startingYear = 1999;
		short tax = 0;
		short substitutionsFriendlyGames = 0;
		std::string championsLeagueName;
		std::string europeLeagueName;
		std::vector<EMWM> emwm;
		std::vector<std::string> outfitter;
	};
}