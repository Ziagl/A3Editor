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
    p.loadFile("test.xml");
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
    p.loadFile("test.xml");
    std::vector<std::string> list = p.getChildren("root");
    EXPECT_EQ(list.size(), 5);
    EXPECT_STREQ(p.getValue("root/testsettingint").data(), "17");
    EXPECT_STREQ(p.getValue("root/testsettingstring").data(), "version 1.1.2");
    EXPECT_STREQ(p.getValue("root/samplecategory/testsettingfloat").data(), "8.98273");
    EXPECT_STREQ(p.getAttributeValue("root/tree1/tree2/tree3/deepdata", "name").data(), "test123");
}

#include "Translator.h"
// Test Translator
TEST(Translator, init)
{
    Core::Translator t("test.xml", "en");
    EXPECT_STREQ(t.translate("elementToTranslate").data(), "english Text");
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
    g->addCountry(country);
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
    std::shared_ptr<Core::Country> country = reader.loadCountryFile(g, "../Game/data/data.a3/LandOest.sav");
    EXPECT_STREQ(country->getCupName().data(), "�FB-Pokal");
}