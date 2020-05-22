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

void Toolset::reinitializeGraph()
{
    reinitializeGraph(nullptr);
}

// reinitialize default data
void Toolset::reinitializeGraph(DialogLoader *dlg)
{
    // load graph data from Data.org folder
    InitializeGraph();
    if (dlg)dlg->setProgress(10, "initilize");
    Core::A3LegacyReader reader(logger);
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandDeut.sav");
    if (dlg) dlg->setProgress(20, "load LandDeut.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandEngl.sav");
    if (dlg) dlg->setProgress(30, "load LandEngl.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandFran.sav");
    if (dlg) dlg->setProgress(40, "load LandFran.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandHoll.sav");
    if (dlg) dlg->setProgress(50, "load LandHoll.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandItal.sav");
    if (dlg) dlg->setProgress(60, "load LandItal.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandOest.sav");
    if (dlg) dlg->setProgress(70, "load LandOest.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandPort.sav");
    if (dlg) dlg->setProgress(80, "load LandPort.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandScho.sav");
    if (dlg) dlg->setProgress(85, "load LandScho.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandSchw.sav");
    if (dlg) dlg->setProgress(90, "load LandSchw.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandSpan.sav");
    if (dlg) dlg->setProgress(95, "load LandSpan.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.org/LandTuer.sav");
    if (dlg) dlg->setProgress(100, "load LandTuer.sav");
}

void Toolset::loadGraph()
{
    loadGraph(nullptr);
}

// load current user defined data from filesystem
void Toolset::loadGraph(DialogLoader *dlg)
{
    // load graph data from Data.org folder
    InitializeGraph();
    if (dlg)dlg->setProgress(10, "initilize");
    Core::A3LegacyReader reader(logger);
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandDeut.sav");
    if (dlg) dlg->setProgress(20, "load LandDeut.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandEngl.sav");
    if (dlg) dlg->setProgress(30, "load LandEngl.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandFran.sav");
    if (dlg) dlg->setProgress(40, "load LandFran.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandHoll.sav");
    if (dlg) dlg->setProgress(50, "load LandHoll.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandItal.sav");
    if (dlg) dlg->setProgress(60, "load LandItal.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandOest.sav");
    if (dlg) dlg->setProgress(70, "load LandOest.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandPort.sav");
    if (dlg) dlg->setProgress(80, "load LandPort.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandScho.sav");
    if (dlg) dlg->setProgress(85, "load LandScho.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandSchw.sav");
    if (dlg) dlg->setProgress(90, "load LandSchw.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandSpan.sav");
    if (dlg) dlg->setProgress(95, "load LandSpan.sav");
    reader.loadCountryFile(graph, "../Game/data/Data.a3/LandTuer.sav");
    if (dlg) dlg->setProgress(100, "load LandTuer.sav");

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