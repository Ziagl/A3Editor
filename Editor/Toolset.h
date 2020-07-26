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

struct RGBColor
{
    short r;
    short g;
    short b;
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
    std::vector<RGBColor> getSponsorColors() { return sponsorColors; }

    // actions
    std::wstring translate(const std::string value);
    std::vector<std::string> GetPlayableCountries();
    std::vector<std::string> GetCountriesWithLeagues();
    void reinitializeGraph();
    void reinitializeGraph(DialogLoader *dlg);
    void loadGraph();
    void loadGraph(DialogLoader *dlg);
    void saveGraph();
    void saveAllSponsorImages();

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
    vertex_t getNationIdByCountryId(vertex_t countryId) { return graph->getNationIdByCountryId(countryId); }
    std::shared_ptr<Core::Additional> getAdditional() { return graph->getAdditional(); }
    std::shared_ptr<Core::Competition> getCompetition() { return graph->getCompetition(); }
    std::shared_ptr<Core::International> getInternational() { return graph->getInternational(); }
    std::shared_ptr<Core::Playerpool> getPlayerpool() { return graph->getPlayerpool(); }
    std::vector<vertex_t> getFormerPlayerIds() { return graph->getFormerPlayerIds(); }
    std::shared_ptr<Core::Player> getFormerPlayerById(vertex_t formerPlayerId) { return graph->getFormerPlayerById(formerPlayerId); }
    vertex_t getTeamIdByPlayerId(vertex_t playerId) { return graph->getTeamIdByPlayerId(playerId); }
    std::shared_ptr<Core::Player> getOtherPlayerById(vertex_t playerId) { return graph->getOtherPlayerById(playerId); }
    std::vector<vertex_t> getOtherPlayerIds() { return graph->getOtherPlayerIds(); }

    // global useful methods
    std::wstring translateTrainerCompetence(short type);
    std::string positionToString(short position, bool zeroBased = false);
    std::string propertiesToString(int properties);
    std::string personalityToString(int personality);
    std::string nationIndexToNationShortname(short nationId);

    std::string getAdImagePath();
    std::string getClubImagePath();
    std::string getImagePath();
    std::string getConfigPath();

    // hard coded lists of possible EC and WC countries ###TODO### export to XML?
    std::vector<std::string> getCLeagueCountries() { return std::vector<std::string> {"BEL", "BOS", "BUL", "DEN", "GER", "ENG", "FIN", "FRA", "GRE", "ISL", "ISR", "ITA", "YUG", "CRO", "LUX", "MLT", "HOL", "NIR", "NOR", "AUT", "POL", "POR", "IRL", "ROM", "RUS", "SCO", "SWE", "SUI", "SVK", "SLO", "ESP", "CZE", "TUR", "UKR", "HUN", "WAL", "CYP"}; }
    std::vector<std::string> getWMCountries() { return std::vector<std::string> { "EGY", "ARG", "AUS", "BEL", "BOS", "BRA", "BUL", "CHL", "CHN", "CRI", "DEN", "GER", "ENG", "FIN", "FRA", "GHA", "GRE", "IRN", "ISL", "ISR", "ITA", "JAM", "JPN", "YUG", "CMR", "CAN", "COL", "CRO", "LUX", "MLT", "MAR", "MEX", "NZL", "HOL", "NIG", "NIR", "NOR", "AUT", "PAR", "POL", "POR", "IRL", "KOR", "ROM", "RUS", "SAU", "SCO", "SWE", "SUI", "SVK", "SLO", "ESP", "SAF", "CZE", "TUR", "UKR", "HUN", "URY", "USA", "VEN", "WAL", "CYP"}; }
    // countries 
    std::vector<std::string> getEuropeanChampionshipCountries() { return std::vector<std::string> { "BEL", "DEN", "DEU", "ENG", "FRA", "GRE", "ITA", "HOL", "AUT", "POR", "ROM", "RUS", "SCO", "ESP", "TUR" }; }
    std::vector<std::string> getWorldCupCountries() {
        std::vector<std::string> world = { "ARG", "BRA", "JPN", "MEX", "USA" };
        auto europe = getEuropeanChampionshipCountries();
        std::vector<std::string> result;
        result.reserve(world.size() + europe.size()); // preallocate memory
        result.insert(result.end(), world.begin(), world.end());
        result.insert(result.end(), europe.begin(), europe.end());
        return result;
    };

    // sponsor images helper methods
    wxImage redrawSponsorImage(std::string filename, short backgroundColorIndex, short textColorIndex, short overlayIndex,
                               std::string fontName, int fontSize, int fontWeight, bool italic, std::string text);
    int getSponsorImageStartIndex(std::string selectedCountry);
    double convertFontSize(int size);
    int backConvertFontSize(int size);
    short getColorIndex(long data, bool index = true);

    // club image helper methods
    std::string getClubImageCountryCode(std::string selectedCountry);

    // search methods
    vertex_t findTeamOfPlayer(const Core::Player& player, std::string selectedCountry);        // get team graph node for a specific player of a country

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
    std::vector<RGBColor> sponsorColors;
};