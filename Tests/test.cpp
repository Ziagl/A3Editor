#include "pch.h"

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#include "RandomNumberGenerator.h"
// Test RandomNumberGenerator
TEST(RandomNumberGenerator, randomNumber)
{
    EXPECT_LT(Core::RandomNumberGenerator::randomNumber(14, 15), 15);
}

#include "TinyXMLParser.h"
#include "RapidXMLParser.h"
// Test XML Parser
TEST(TinyXMLParser, init)
{
    TinyXMLParser p;
#ifdef __LINUX__
    p.loadFile("../test.xml");
#else
    p.loadFile("test.xml");
#endif
    std::vector<std::string> list = p.getChildren("root");
    EXPECT_EQ(list.size(), 5);
    EXPECT_STREQ(p.getValue("root/testsettingint").data(), "17");
    EXPECT_STREQ(p.getValue("root/testsettingstring").data(), "version 1.1.2");
    EXPECT_STREQ(p.getValue("root/samplecategory/testsettingfloat").data(), "8.98273");
    EXPECT_STREQ(p.getAttributeValue("root/tree1/tree2/tree3/deepdata", "name").data(), "test123");
}
TEST(RapidXMLParser, init)
{
    RapidXMLParser p;
#ifdef __LINUX__
    p.loadFile("../test.xml");
#else
    p.loadFile("test.xml");
#endif
    std::vector<std::string> list = p.getChildren("root");
    EXPECT_EQ(list.size(), 5);
    EXPECT_STREQ(p.getValue("root/testsettingint").data(), "17");
    EXPECT_STREQ(p.getValue("root/testsettingstring").data(), "version 1.1.2");
    EXPECT_STREQ(p.getValue("root/samplecategory/testsettingfloat").data(), "8.98273");
    EXPECT_STREQ(p.getAttributeValue("root/tree1/tree2/tree3/deepdata", "name").data(), "test123");
}

#include "Translator.h"
// Test Translator
TEST(Translator, en)
{
#ifdef __LINUX__
    Core::Translator t("../test.xml", "en");
#else
    Core::Translator t("test.xml", "en");
#endif
    EXPECT_STREQ(t.translate("elementToTranslate").data(), "english Text");
    EXPECT_STREQ(t.translate("nonsense").data(), "MISSING TRANSLATION (nonsense)");
}
TEST(Translator, de)
{
#ifdef __LINUX__
    Core::Translator t("../test.xml", "de");
#else
    Core::Translator t("test.xml", "de");
#endif
    EXPECT_STREQ(t.translate("elementToTranslate").data(), "deutscher Text \xC3\x96\xC3\x84\xC3\x9C");//ÖÄÜ
    EXPECT_STREQ(t.translate("nonsense").data(), "MISSING TRANSLATION (nonsense)");
}

#include "GraphFactory.h"
// Test Graph
TEST(Graph, init)
{
    auto g = Core::GraphFactory::create();
    EXPECT_EQ(g->numberVertices(), 1);
    EXPECT_EQ(g->numberEdges(), 0);
}
TEST(Graph, addCountry)
{
    auto g = Core::GraphFactory::create();
    auto country = std::make_shared<Core::Country>();
    g->addCountry(country, 0);
    EXPECT_EQ(g->numberVertices(), 2);
    EXPECT_EQ(g->numberEdges(), 1);
}

#include "A3LegacyReader.h"
#include "LoggerFactory.h"
// Test A3LegacyReader/Writer
TEST(A3LegacyReader, readAndWrite)
{
    Core::A3LegacyReader reader(Core::LoggerFactory::create());
    auto g = Core::GraphFactory::create();
#ifdef __LINUX__
    std::string path = "../../Game/data/Data.a3/";
#else
    std::string path = "../Game/data/Data.a3/";
#endif
    reader.loadNationFile(g, path + "Laender.sav");
    auto country = reader.loadCountryFile(g, path + "LandOest.sav");
    EXPECT_STREQ(country->getCupName().data(), "Pokal AUS");
}