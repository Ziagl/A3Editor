#include "Toolset.h"
#include "A3LegacyReader.h"
#include "A3LegacyWriter.h"

std::string Toolset::translate(const std::string value)
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

// reinitialize default data
void Toolset::reinitializeGraph()
{
    // load graph data from Data.org folder
    InitializeGraph();
    Core::A3LegacyReader reader(logger);
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandDeut.sav"); // ### todo from config file
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandEngl.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandFran.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandHoll.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandItal.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandOest.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandPort.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandScho.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandSchw.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandSpan.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandTuer.sav");
}

// load current user defined data from filesystem
void Toolset::loadGraph()
{
    // load graph data from Data.org folder
    InitializeGraph();
    Core::A3LegacyReader reader(logger);
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandDeut.sav"); // ### todo from config file
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandEngl.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandFran.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandHoll.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandItal.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandOest.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandPort.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandScho.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandSchw.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandSpan.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandTuer.sav");
    
}

// save current user defined data to filesystem
void Toolset::saveGraph()
{
    // save all loaded countries to filesystem
    Core::A3LegacyWriter writer(logger);
    auto countries = graph->getCountryIds();
    for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
    {
        writer.saveCountryFile(graph, *it);
    }
}