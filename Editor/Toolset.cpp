#include "Toolset.h"
#include "A3LegacyReader.h"
#include "A3LegacyWriter.h"
#include "XMLParserFactory.h"
#include "boost/locale/encoding_utf.hpp"
#include <thread>

std::wstring Toolset::translate(const std::string value)
{
    if (translator == nullptr)
        return std::wstring();
    else
    {
        std::string result = translator->translate(value);
        return boost::locale::conv::utf_to_utf<wchar_t>(result.c_str(), result.c_str() + result.size());
    }
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
#ifdef __LINUX__
    std::string path = "../../Game/data/Data.org/";
#else
    std::string path = "../Game/data/Data.org/";
#endif

    // load graph data from Data.org folder
    loadSAVFiles(path, dlg);
}

void Toolset::loadGraph()
{
    loadGraph(nullptr);
}

// load current user defined data from filesystem
void Toolset::loadGraph(DialogLoader *dlg)
{
#ifdef __LINUX__
    std::string path = "../../Game/data/Data.a3/";
#else
    std::string path = "../Game/data/Data.a3/";
#endif

    // load graph data from Data.a3 folder
    loadSAVFiles(path, dlg);                 // ###Todo####

    // initialize lists
    playableCountries = std::make_shared<Editor::PlayableCountries>(graph);
    countriesWithLeagues = std::make_shared<Editor::CountriesWithLeagues>(graph);
}

// save current user defined data to filesystem
void Toolset::saveGraph()
{
#ifdef __LINUX__
    std::string path = "../../Game/data/Data.a3/";// ###Todo####
#else
    std::string path = "../Game/data/Data.a3/";
#endif                

    // save all loaded countries to filesystem
    Core::A3LegacyWriter writer(logger);
    // save nations
    writer.saveNationFile(graph, path + "Laender.sav");

    // save not playable countries
    writer.saveNotPlayableCountryFile(graph, path + "Internat.sav");

    // save playable countries
    auto countries = graph->getCountryIds();
    for (auto country : countries)
    {
        writer.saveCountryFile(graph, country);
    }

    // save leagues
    auto leagues = graph->getLeagueIds();
    for (auto league : leagues)
    {
        writer.saveLeagueFile(graph, league);
    }

}

void Toolset::loadSAVFiles(std::string path, DialogLoader* dlg)
{
    // load graph data from Data.org folder
    InitializeGraph();
    if (dlg)dlg->setProgress(5, "initilize");
    Core::A3LegacyReader reader(logger);
    // load nations file
    std::thread t0(&Core::A3LegacyReader::loadNationFile, &reader, graph, path + "Laender.sav");
    t0.join();
    if (dlg) dlg->setProgress(10, "load Laender.sav");
    // to speed up debugging only load 2 countries
    std::thread t1(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandDeut.sav");
#ifndef _DEBUG
    std::thread t2(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandEngl.sav");
    std::thread t3(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandFran.sav");
    std::thread t4(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandHoll.sav");
#endif
    t1.join();
    if (dlg) dlg->setProgress(20, "load LandDeut.sav");
#ifndef _DEBUG
    t2.join();
    if (dlg) dlg->setProgress(20, "load LandEngl.sav");
    t3.join();
    if (dlg) dlg->setProgress(20, "load LandFran.sav");
    t4.join();
    if (dlg) dlg->setProgress(20, "load LandHoll.sav");
#endif
#ifndef _DEBUG
    std::thread t5(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandItal.sav");
#endif
    std::thread t6(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandOest.sav");
#ifndef _DEBUG
    std::thread t7(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandPort.sav");
    std::thread t8(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandScho.sav");
    t5.join();
    if (dlg) dlg->setProgress(60, "load LandItal.sav");
#endif
    t6.join();
    if (dlg) dlg->setProgress(70, "load LandOest.sav");
#ifndef _DEBUG
    t7.join();
    if (dlg) dlg->setProgress(75, "load LandPort.sav");
    t8.join();
    if (dlg) dlg->setProgress(80, "load LandScho.sav");
    std::thread t9(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandSchw.sav");
    std::thread t10(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandSpan.sav");
    std::thread t11(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandTuer.sav");
#endif
    // load non playable countries
    std::thread t12(&Core::A3LegacyReader::loadNotPlayableCountryFile, &reader, graph, path + "Internat.sav");
#ifndef _DEBUG
    t9.join();
    if (dlg) dlg->setProgress(85, "load LandSchw.sav");
    t10.join();
    if (dlg) dlg->setProgress(90, "load LandSpan.sav");
    t11.join();
    if (dlg) dlg->setProgress(95, "load LandTuer.sav");
#endif
    t12.join();
    if (dlg) dlg->setProgress(100, "load Internat.sav");
    // load league files
    // get list of available league files from xml
    Core::XMLParser xml = Core::XMLParserFactory::create();
    xml->loadFile(path + "../leagues.xml");
    std::vector<std::string> elements = xml->getChildren("root");
    // for each country defined in xml
    for (std::vector<std::string>::iterator it = elements.begin(); it != elements.end(); ++it)
    {
        std::vector<std::thread> threads;
        std::string xmlPath = "root/" + (*it);
        auto filenames = xml->getChildren(xmlPath);
        auto countryId = graph->getCountryIdByShortname(*it);
        // if country was not loaded, we cannot load league file
        // should only happen in debugging version
        if (countryId == 0)
            continue;
        // for each file per country
        for (auto filename : filenames)
        {
            // now load each individual league file
            std::thread t(&Core::A3LegacyReader::loadLeagueFile, &reader, graph, countryId, path + filename + ".sav");
            threads.push_back(std::move(t));
        }
        // wait for threads to finish
        for (auto& thread : threads)
        {
            if(thread.joinable())
                thread.join();
        }
    }
    if (dlg) dlg->setProgress(100, "load league");

}


std::wstring Toolset::translateTrainerCompetence(short type)
{
    return translate("trainertype" + std::to_string(type));
}