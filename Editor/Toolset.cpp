#include "Toolset.h"
#include "A3LegacyReader.h"
#include "A3LegacyWriter.h"
#include <thread>

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
    // load data parallelized
    std::thread t1(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandDeut.sav"); // ### todo from config file
    std::thread t2(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandEngl.sav");
    std::thread t3(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandFran.sav");
    std::thread t4(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandHoll.sav");
    std::thread t5(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandItal.sav");
    std::thread t6(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandOest.sav");
    std::thread t7(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandPort.sav");
    std::thread t8(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandScho.sav");
    std::thread t9(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandSchw.sav");
    std::thread t10(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandSpan.sav");
    std::thread t11(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandTuer.sav");
    // wait till all threads are finised
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
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