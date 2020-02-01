#include "Toolset.h"

std::string Toolset::translate(std::string value)
{
    if (translator == nullptr)
        return std::string();
    else
        return translator->translate(value);
}

std::vector<std::string> Toolset::GetPlayableCountries()
{
    if (playableCountries == nullptr)
        return std::vector<std::string>();
    else
        return playableCountries->GetList();
}

std::vector<std::string> Toolset::GetCountriesWithLeagues()
{
    if (countriesWithLeagues == nullptr)
        return std::vector<std::string>();
    else
        return countriesWithLeagues->GetList();
}