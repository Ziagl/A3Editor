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
    std::thread t1(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandDeut.sav");
#ifndef _DEBUG
    std::thread t2(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandEngl.sav");
    std::thread t3(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandFran.sav");
    std::thread t4(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandHoll.sav");
#endif
    t1.join();
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandDeut.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandEngl.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandFran.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandHoll.sav");
    if (dlg) dlg->setProgress(20, "load LandDeut.sav");
#ifndef _DEBUG
    t2.join();
    if (dlg) dlg->setProgress(20, "load LandEngl.sav");
    t3.join();
    if (dlg) dlg->setProgress(20, "load LandFran.sav");
    t4.join();
    if (dlg) dlg->setProgress(20, "load LandHoll.sav");
#endif
    // to speed up debugging only load 2 countries
#ifndef _DEBUG
    std::thread t5(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandItal.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandItal.sav");
#endif
    std::thread t6(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandOest.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandOest.sav");
#ifndef _DEBUG
    std::thread t7(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandPort.sav");
    std::thread t8(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandScho.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandPort.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandScho.sav");
    t5.join();
    if (dlg) dlg->setProgress(60, "load LandItal.sav");
#endif
    t6.join();
    if (dlg) dlg->setProgress(70, "load LandOest.sav");
#ifndef _DEBUG
    t7.join();
    if (dlg) dlg->setProgress(80, "load LandPort.sav"); 
    t8.join();
    if (dlg) dlg->setProgress(85, "load LandScho.sav");
    std::thread t9(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandSchw.sav");
    std::thread t10(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandSpan.sav");
    std::thread t11(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.org/LandTuer.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandSchw.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandSpan.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandTuer.sav");
    t9.join();
    if (dlg) dlg->setProgress(90, "load LandSchw.sav");
    t10.join();
    if (dlg) dlg->setProgress(95, "load LandSpan.sav");
    t1.join();
    if (dlg) dlg->setProgress(100, "load LandTuer.sav");
#endif
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
    std::thread t1(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandDeut.sav");
#ifndef _DEBUG
    std::thread t2(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandEngl.sav");
    std::thread t3(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandFran.sav");
    std::thread t4(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandHoll.sav");
#endif
    t1.join();
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandDeut.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandEngl.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandFran.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandHoll.sav");
    if (dlg) dlg->setProgress(20, "load LandDeut.sav");
#ifndef _DEBUG
    t2.join();
    if (dlg) dlg->setProgress(20, "load LandEngl.sav");
    t3.join();
    if (dlg) dlg->setProgress(20, "load LandFran.sav");
    t4.join();
    if (dlg) dlg->setProgress(20, "load LandHoll.sav");
#endif
    // to speed up debugging only load 2 countries
#ifndef _DEBUG
    std::thread t5(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandItal.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandItal.sav");
#endif
    std::thread t6(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandOest.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandOest.sav");
#ifndef _DEBUG
    std::thread t7(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandPort.sav");
    std::thread t8(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandScho.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandPort.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandScho.sav");
    t5.join();
    if (dlg) dlg->setProgress(60, "load LandItal.sav");
#endif
    t6.join();
    if (dlg) dlg->setProgress(70, "load LandOest.sav");
#ifndef _DEBUG
    t7.join();
    if (dlg) dlg->setProgress(80, "load LandPort.sav");
    t8.join();
    if (dlg) dlg->setProgress(85, "load LandScho.sav");
    std::thread t9(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandSchw.sav");
    std::thread t10(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandSpan.sav");
    std::thread t11(&Core::A3LegacyReader::loadCountryFile, &reader, graph, "../Game/data/Data.a3/LandTuer.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandSchw.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandSpan.sav");
    //reader.loadCountryFile(graph, "../Game/data/Data.org/LandTuer.sav");
    t9.join();
    if (dlg) dlg->setProgress(90, "load LandSchw.sav");
    t10.join();
    if (dlg) dlg->setProgress(95, "load LandSpan.sav");
    t1.join();
    if (dlg) dlg->setProgress(100, "load LandTuer.sav");
#endif
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