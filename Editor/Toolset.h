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
    MANAGER,
    REFEREE,
    INTERNATIONALREFEREE
};

enum ClubselectType
{
    TEAM,
    PLAYER
};

class Toolset
{
public:
    Toolset() : startingYear(0), minAge(0), minAgeYouth(0), maxSkill(0), maxSkillPerson(0)
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
    short getMaxSkillPerson() { return maxSkillPerson; }

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
    std::vector<vertex_t> getCountryIds() { return graph->getCountryIds(); }
    std::vector<vertex_t> getTeamIdsByCountryId(vertex_t countryId) { return graph->getTeamIdsByCountryId(countryId); }
    std::shared_ptr<Core::Team> getTeamById(vertex_t teamId) { return graph->getTeamById(teamId); }
    std::vector<vertex_t> getTeamIdsByLeagueId(vertex_t leagueId) { return graph->getTeamIdsByLeagueId(leagueId); }
    std::vector<vertex_t> getPlayerIdsByTeamId(vertex_t teamId) { return graph->getPlayerIdsByTeamId(teamId); }
    std::shared_ptr<Core::Player> getPlayerById(vertex_t playerId) { return graph->getPlayerById(playerId); }
    std::vector<vertex_t> getPlayerIds() { return graph->getPlayerIds(); }
    vertex_t getLeagueIdByTeamId(vertex_t teamId) { return graph->getLeagueIdByTeamId(teamId); }
    std::vector<vertex_t> getLeagueIdsByCountryId(vertex_t countryId) { return graph->getLeagueIdsByCountryId(countryId); }
    std::shared_ptr<Core::League> getLeagueById(vertex_t leagueId) { return graph->getLeagueById(leagueId); }
    std::shared_ptr<Core::Nation> getNationById(vertex_t nationId) { return graph->getNationById(nationId); }
    std::vector<vertex_t> getNationIds() { return graph->getNationIds(); }
    vertex_t getNationIdByIndex(short index) { return graph->getNationIdByIndex(index); }
    std::shared_ptr<Core::UefaRanking> getUefaRanking() { return graph->getUefaRanking(); }
    std::shared_ptr<Core::International> getInternational() { return graph->getInternational(); }

    // global useful methods
    std::wstring translateTrainerCompetence(short type);
    std::string positionToString(short position, bool zeroBased = false);

private:
    void loadSAVFiles(std::string path, DialogLoader* dlg);
protected:
    std::shared_ptr<Editor::Translator> translator = nullptr;
    std::shared_ptr<Editor::PlayableCountries> playableCountries = nullptr;
    std::shared_ptr<Editor::CountriesWithLeagues> countriesWithLeagues = nullptr;
    std::shared_ptr<Core::Graph> graph = nullptr;
    Core::Logger logger = nullptr;

private:
    // global config values
    short startingYear = 0;
    short minAge = 0;
    short minAgeYouth = 0;
    short maxSkill = 0;
    short maxSkillPerson = 0;
    std::string language;
};