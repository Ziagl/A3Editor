#include "pch.h"

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#include "../Core/RandomNumberGenerator.h"
// Test RandomNumberGenerator
TEST(RandomNumberGenerator, randomNumber)
{
    EXPECT_LT(RandomNumberGenerator::randomNumber(14, 15), 15);
}

#include "../Core/TinyXMLParser.h"
#include "../Core/RapidXMLParser.h"
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

#include "../Core/Translator.h"
// Test Translator
TEST(Translator, init)
{
    Core::Translator t("test.xml", "en");
    EXPECT_STREQ(t.translate("elementToTranslate").data(), "english Text");
    EXPECT_STREQ(t.translate("nonsense").data(), "MISSING TRANSLATION (nonsense)");
}