#pragma once

#include <memory>
#include "Translator.h"
#include "PlayableCountries.h"
#include "CountriesWithLeagues.h"
#include "GraphFactory.h"
#include "LoggerFactory.h"
#include "DialogLoader.h"
#include "Country.h"

enum PersonType 
{
    COTRAINER,
    GOALKEEPER,
    MANAGER
};

class Toolset
{
public:
    Toolset() : startingYear(0), minAge(0), minAgeYouth(0), maxSkill(0)
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
    virtual void InitializeGlobals(std::string filename);

    // getter/setter
    std::shared_ptr<Core::Graph> getGraph() { return graph; }
    // global config values
    std::string getLanguage() { return language; }
    short getStartingYear() { return startingYear; }
    short getMinAge() { return minAge; }
    short getMinAgeYouth() { return minAgeYouth; }
    short getMaxSkill() { return maxSkill; }

    // actions
    std::wstring translate(const std::string value);
    std::vector<std::string> GetPlayableCountries();
    std::vector<std::string> GetCountriesWithLeagues();
    void reinitializeGraph();
    void reinitializeGraph(DialogLoader *dlg);
    void loadGraph();
    void loadGraph(DialogLoader *dlg);
    void saveGraph();

    // use graph interface
    vertex_t getCountryIdByShortname(std::string shortname) { return graph->getCountryIdByShortname(shortname); }
    std::shared_ptr<Core::Country> getCountryById(vertex_t countryId) { return graph->getCountryById(countryId); }
    std::vector<vertex_t> getTeamIdsByCoutryId(vertex_t countryId) { return graph->getTeamIdsByCountryId(countryId); }
    std::shared_ptr<Core::Team> getTeamById(vertex_t teamId) { return graph->getTeamById(teamId); }
    std::vector<vertex_t> getPlayerIdsByTeamId(vertex_t teamId) { return graph->getPlayerIdsByTeamId(teamId); }
    std::shared_ptr<Core::Player> getPlayerById(vertex_t playerId) { return graph->getPlayerById(playerId); }
    vertex_t getLeagueIdByTeam(vertex_t teamId) { return graph->getLeagueIdByTeam(teamId); }
    std::shared_ptr<Core::League> getLeagueById(vertex_t leagueId) { return graph->getLeagueById(leagueId); }

    // global useful methods
    std::wstring translateTrainerCompetence(short type);

private:
    void loadSAVFiles(std::string path, DialogLoader* dlg);
protected:
    std::shared_ptr<Editor::Translator> translator = nullptr;
    std::shared_ptr<Editor::PlayableCountries> playableCountries = nullptr;
    std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues = nullptr;
    std::shared_ptr<Core::Graph> graph = nullptr;
    Core::Logger logger = nullptr;

    // global config values
    short startingYear = 0;
    short minAge = 0;
    short minAgeYouth = 0;
    short maxSkill = 0;
    std::string language;
};