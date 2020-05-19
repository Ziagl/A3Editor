#pragma once

#include <memory>
#include "Translator.h"
#include "PlayableCountries.h"
#include "CountriesWithLeagues.h"
#include "Graph.h"

class Toolset
{
public:
    // initializers
    virtual void SetTranslator(std::shared_ptr<Editor::Translator> translator)
    {
        this->translator = translator;
    }
    virtual void SetPlayableCountries(std::shared_ptr<Editor::PlayableCountries> playableCountries)
    {
        this->playableCountries = playableCountries;
    }
    virtual void SetCountriesWithLeagues(std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues)
    {
        this->countriesWithLeagues = countriesWithLeagues;
    }

    // actions
    std::string translate(std::string value);
    std::vector<std::string> GetPlayableCountries();
    std::vector<std::string> GetCountriesWithLeagues();

protected:
    std::shared_ptr<Editor::Translator> translator = nullptr;
    std::shared_ptr<Editor::PlayableCountries> playableCountries = nullptr;
    std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues = nullptr;
    std::shared_ptr<Core::Graph> graph = nullptr;
};