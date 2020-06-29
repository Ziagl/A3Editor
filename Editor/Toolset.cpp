#include "Toolset.h"
#include "A3LegacyReader.h"
#include "A3LegacyWriter.h"
#include "XMLParserFactory.h"
#include "boost/locale/encoding_utf.hpp"
#include <thread>
#include <wx/dcmemory.h>

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

void Toolset::InitializeGlobals(std::string filename)
{
    Core::XMLParser xml = Core::XMLParserFactory::create();
    xml->loadFile(filename);
    language = xml->getValue("root/language");
    startingYear = std::stoi(xml->getValue("root/startingYear"));
    minAge = std::stoi(xml->getValue("root/minAge"));
    minAgeYouth = std::stoi(xml->getValue("root/minAgeYouth"));
    maxSkill = std::stoi(xml->getValue("root/maxSkill"));
    maxSkillPerson = std::stoi(xml->getValue("root/maxSkillPerson"));
    for (int i = 1; i <= 16; ++i)
    {
        RGBColor color;
        color.r = std::stoi(xml->getAttributeValue("root/sponsorColors/color" + std::to_string(i), "r"));
        color.g = std::stoi(xml->getAttributeValue("root/sponsorColors/color" + std::to_string(i), "g"));
        color.b = std::stoi(xml->getAttributeValue("root/sponsorColors/color" + std::to_string(i), "b"));
        sponsorColors.push_back(color);
    }
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

    // save additional file
    writer.saveAdditionalFile(graph, path + "Kleinig.sav");

    // save international files
    writer.saveInternationalFiles(graph, path + "AVereine.sav", path + "ISchiris.sav");

    // save youth files
    writer.saveYouthFiles(graph, path + "Jugend.sav");
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
            short hierarchy = std::stoi(xml->getAttributeValue(xmlPath + "/" + filename, "hierarchy"));
            // now load each individual league file
            std::thread t(&Core::A3LegacyReader::loadLeagueFile, &reader, graph, countryId, path + filename + ".sav", hierarchy);
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
    // load additional file
    std::thread t13(&Core::A3LegacyReader::loadAdditionalFile, &reader, graph, path + "Kleinig.sav");
    // load international files
    std::thread t14(&Core::A3LegacyReader::loadInternationalFiles, &reader, graph, path + "AVereine.sav", path + "ISchiris.sav");
    // load youth files
    std::thread t15(&Core::A3LegacyReader::loadYouthFiles, &reader, graph, path + "Jugend.sav");    // it is only necessary to pass base name, method loads every single JugendX.sav file
    t13.join();
    t14.join();
    t15.join();
}

std::wstring Toolset::translateTrainerCompetence(short type)
{
    return translate("trainertype" + std::to_string(type));
}

/*
 * returns string repesentation of skill value from data files
 * for players it starts with 1 for goalkeeper, for youth and amateur players it starts with 0 for goalkeeper
 * zeroBased = true for youth and amateur players!
 */
std::string Toolset::positionToString(short position, bool zeroBased)
{
    if (!zeroBased)
        --position;
    switch (position)
    {
        // ###TODO### translation?
    case 0: return "T";
    case 1: return "L";
    case 2: return "IV";
    case 3: return "LV";
    case 4: return "RV";
    case 5: return "DM";
    case 6: return "LM";
    case 7: return "RM";
    case 8: return "OM";
    case 9: return "S";
    }

    return "";
}

/*
 * returns a 3 character wide shortname of nation by a given nationId from data files
 */
std::string Toolset::nationIndexToNationShortname(short nationIndex)
{
    auto nationId = getNationIdByIndex(nationIndex);
    auto nation = getNationById(nationId);
    return nation->getShortname();
}

/*
 * converts player property bitmask to a translated string
 */
std::string Toolset::propertiesToString(int properties)
{
    std::string result = "";
    std::vector<std::string> propertiesArray{"fighter", "trainingWorldChamption", "trainingLazyPlayer", "violator", "fairPlayer", "mimosa", "slyfox", "specialist", "allrounder", "flexiblePlayer", "refereeFavorite", "homePlayer", "fairWeatherPlayer", "joker", "egoist", "brotherLightFooted"};
    long bitmask = 0b00000000000000000010;
    for (auto property : propertiesArray)
    {
        if ((bitmask & properties) > 0)
        {
            if (!result.empty())
                result = result + ", ";
            result = result + translate(property);
        }
        bitmask = bitmask << 1;
    }
    return result;
}

/*
 * converts player personality bitmask to a translated string
 */
std::string Toolset::personalityToString(int personality)
{
    std::string result = "";
    std::vector<std::string> personalityArray{ "leader", "hotHead", "happyNature", "manWithoutNerves", "bundleOfNerves", "phlegmatic", "moneyVolture", "clubSupporter", "professionalPattern", "scandalNoodle", "sensitive", "airsAndGraces", "teenStar", "troublemaker", "liverwurst", "unifyingFigure" };
    long bitmask = 0b00000000000000000010;
    for (auto property : personalityArray)
    {
        if ((bitmask & personality) > 0)
        {
            if (!result.empty())
                result = result + ", ";
            result = result + translate(property);
        }
        bitmask = bitmask << 1;
    }
    return result;
}

std::string Toolset::getImagePath()
{
#ifdef __LINUX__
    std::string path = "../data/";
#else
    std::string path = "data/";
#endif
    return path;
}

std::string Toolset::getConfigPath()
{
#ifdef __LINUX__
    std::string path = "../config/";
#else
    std::string path = "config/";
#endif
    return path;
}

std::string Toolset::getAdImagePath()
{
#ifdef __LINUX__
    std::string path = "../../Game/data/Banden/";
#else
    std::string path = "../Game/data/Banden/";
#endif
    return path;
}

/*
 * recreates all sponsor images for all countries and saves them to disc
 */
void Toolset::saveAllSponsorImages()
{
    auto playableCountries = GetPlayableCountries();
    for (auto countryShortname : playableCountries)
    {
        auto countryId = getCountryIdByShortname(countryShortname);
        auto country = getCountryById(countryId);
        auto sponsors = country->getSponsors();
        auto imageStartIndex = getSponsorImageStartIndex(countryShortname);

        for (int i = 0; i < sponsors.size(); ++i)
        {
            std::string filename = "kom" + std::to_string(i + imageStartIndex) + ".bmp";
            auto sponsor = sponsors.at(i);

            short backgroundColorIndex = getColorIndex(sponsor.getBackgroundColorSize());
            short textColorIndex = getColorIndex(sponsor.getTextColor());
            short overlayIndex = sponsor.getAdImage();
            std::string fontName = sponsor.getFont();
            std::string text = sponsor.getName();
            int fontSize = sponsor.getFontSize();
            int fontWeight = sponsor.getFontWeight();
            bool italic = sponsor.getFontType()>0?true:false;
            auto image = redrawSponsorImage(filename, backgroundColorIndex, textColorIndex, overlayIndex, 
                                            fontName, fontSize, fontWeight, italic, text);
            image.SaveFile(getAdImagePath() + filename);
        }
    }
}

/*
 * creates a sponsor image with given settings and returns image object
 */
wxImage Toolset::redrawSponsorImage(std::string filename, short backgroundColorIndex, short textColorIndex, short overlayIndex,
                                    std::string fontName, int fontSize, int fontWeight, bool italic, std::string text)
{
    // load base image
    wxImage image;
    image.LoadFile(getAdImagePath() + filename, wxBITMAP_TYPE_BMP);

    // modify it
    auto color = getSponsorColors().at(backgroundColorIndex);
    wxColor backgroundColor(color.r, color.g, color.b);     //create wxColor with given RGB values
    color = getSponsorColors().at(textColorIndex);
    wxColor textColor(color.r, color.g, color.b);
    wxBrush backgroundColorBrush(backgroundColor);
    wxFontInfo fontinfo(convertFontSize(fontSize));
    if (!fontName.empty())
        fontinfo.FaceName(fontName);
    fontinfo.Weight(fontWeight);
    fontinfo.Italic(italic);
    wxFont font(fontinfo);      // create font based on fontinfo from data or dialog

    wxBitmap bitmap(image);
    wxMemoryDC memdc;
    memdc.SelectObject(bitmap);
    memdc.SetBackground(backgroundColorBrush);
    memdc.SetTextBackground(backgroundColor);
    memdc.SetTextForeground(textColor);
    memdc.Clear();          //fills the entire bitmap with given color
    memdc.SetFont(font);
    auto size = memdc.GetTextExtent(text);    // get dimensions of text
    memdc.DrawText(text, (image.GetWidth() / 2) - (size.GetWidth() / 2), (image.GetHeight() / 2) - (size.GetHeight() / 2));   // draw text into the middle of image
    memdc.SelectObject(wxNullBitmap);
    image = wxBitmap(bitmap).ConvertToImage();

    // add current overlay image
    wxImage overlay;
    std::string overlayFilename = "Bande";
    if (overlayIndex + 1 < 10)
        overlayFilename = "Bande0";
    overlayFilename = overlayFilename + std::to_string(overlayIndex + 1) + ".bmp";
    overlay.LoadFile(getAdImagePath() + overlayFilename);

    image.Paste(overlay, 0, 0);
    image.Paste(overlay, image.GetWidth() - overlay.GetWidth(), 0);

    return image;
}

/*
 * all sponsor images are labeld with an incrementing filename. Each playable country has 40 sponsors
 * they are ordered in a special unique ordering -> hardcoded!
 */
int Toolset::getSponsorImageStartIndex(std::string selectedCountry)
{
    // hard coded sorting of country images - every country has 40 images in to following (strange) order
    std::vector<std::string> sponsorGraphics = { "GER", "ENG", "FRA", "ITA", "ESP", "POR", "HOL", "AUT", "SCO", "SUI", "TUR" };
    int startIndex = 1;
    for (int i = 0; i < sponsorGraphics.size(); ++i)
    {
        if (selectedCountry == sponsorGraphics.at(i))
        {
            startIndex += i * 40;
            break;
        }
    }
    return startIndex;
}

/*
 * font size is stored as negative numbers. Looks like some kind of bitmask. For the font dialog we need font size in points
 * -27 corresponds to 20pt, -13 to 10 pt and -48 to 36pt...I assume a factor of 0.75 to compute between those rounded values.
 */
double Toolset::convertFontSize(int size)
{
    return round((abs(size) * 0.75f));
}

int Toolset::backConvertFontSize(int size)
{
    return (-1) * round(size / 0.75);
}

/*
 * simple helper to get the index of used color bitmask from original data
 * if index = false this method returns bitmask of given index
 */
short Toolset::getColorIndex(long data, bool index)
{
    // hard coded color table. Values are from export file and are used for text and background color of ad image
    std::vector<short> colorTable = { 0b00000000, 0b00101000, 0b00010010, 0b01001100, 0b00111010, 0b01010111, 0b01100001, 0b01100011, 
                                      0b01001111, 0b01011101, 0b01001110, 0b01111111, 0b01101111, 0b01101000, 0b01111101, 0b00000001 };

    if (index)
    {
        // we only want last 16 bits
        // this masks out size from BackgroundColorSize field
        long bitmask = data & 0b1111111111111111;
        // compare with known color bitmasks
        for (int i = 0; i < colorTable.size(); ++i)
        {
            if (colorTable.at(i) == bitmask)
                return i;
        }
    }
    else
    {
        if(data < colorTable.size())
            return colorTable.at(data);
    }
    return 0;
}

