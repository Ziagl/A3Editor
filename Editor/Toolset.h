#pragma once

#include <memory>
#include "Translator.h"
#include "PlayableCountries.h"
#include "CountriesWithLeagues.h"
#include "GraphFactory.h"
#include "LoggerFactory.h"

class Toolset
{
public:
    Toolset() 
    {
        InitializeLogger();
    }

    // initializers
    virtual void SetTranslator(const std::shared_ptr<Editor::Translator> translator)
    {
        this->translator = translator;
    }
    virtual void SetPlayableCountries(const std::shared_ptr<Editor::PlayableCountries> playableCountries)
    {
        this->playableCountries = playableCountries;
    }
    virtual void SetCountriesWithLeagues(const std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues)
    {
        this->countriesWithLeagues = countriesWithLeagues;
    }
    virtual void InitializeGraph()
    {
        graph = Core::GraphFactory::create();
    }
    virtual void InitializeLogger()
    {
       logger = Core::LoggerFactory::create();
    }

    // actions
    std::string translate(const std::string value);
    std::vector<std::string> GetPlayableCountries();
    std::vector<std::string> GetCountriesWithLeagues();
    void reinitializeGraph();
    void loadGraph();
    void saveGraph();

protected:
    std::shared_ptr<Editor::Translator> translator = nullptr;
    std::shared_ptr<Editor::PlayableCountries> playableCountries = nullptr;
    std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues = nullptr;
    std::shared_ptr<Core::Graph> graph = nullptr;
    Core::Logger logger = nullptr;
};