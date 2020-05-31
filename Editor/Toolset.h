#pragma once

#include <memory>
#include "Translator.h"
#include "PlayableCountries.h"
#include "CountriesWithLeagues.h"
#include "GraphFactory.h"
#include "LoggerFactory.h"
#include "DialogLoader.h"
#include "Country.h"

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
    virtual void InitializeGraph()
    {
        graph = Core::GraphFactory::create();
    }
    virtual void InitializeLogger()
    {
       logger = Core::LoggerFactory::create();
    }

    // getter/setter
    std::shared_ptr<Core::Graph> getGraph() { return graph; }

    // actions
    std::wstring translate(const std::string value);
    std::vector<std::string> GetPlayableCountries();
    std::vector<std::string> GetCountriesWithLeagues();
    void reinitializeGraph();
    void reinitializeGraph(DialogLoader *dlg);
    void loadGraph();
    void loadGraph(DialogLoader *dlg);
    void saveGraph();

    vertex_t getCountryIdByShortname(std::string shortname) { return graph->getCountryIdByShortname(shortname); }
    std::shared_ptr<Core::Country> getCountryById(vertex_t countryId) { return graph->getCountryById(countryId); }
    std::vector<std::shared_ptr<Core::Team>> getTeamsByCountryId(vertex_t countryId);

private:
    void loadSAVFiles(std::string path, DialogLoader* dlg);
protected:
    std::shared_ptr<Editor::Translator> translator = nullptr;
    std::shared_ptr<Editor::PlayableCountries> playableCountries = nullptr;
    std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues = nullptr;
    std::shared_ptr<Core::Graph> graph = nullptr;
    Core::Logger logger = nullptr;
};