#include "RapidXMLParser.h"
#include <sstream>
#include <iostream>

std::string RapidXMLParser::getValue(const std::string path)
{
    std::vector<std::string> tags = splitPath(path);
    rapidxml::file<> xmlFile(filename.data());
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* element = findElement(path);
    return element->value();
}

std::string RapidXMLParser::getAttributeValue(const std::string path, const std::string name)
{
    rapidxml::file<> xmlFile(filename.data());
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* element = findElement(path);
    rapidxml::xml_attribute<>* attribute = element->first_attribute(name.c_str());
    return attribute->value();
}

rapidxml::xml_node<>* RapidXMLParser::findElement(std::string path)
{
    rapidxml::xml_node<>* element = nullptr;
    std::vector<std::string> tags = splitPath(path);
    for (std::vector<std::string>::iterator it = tags.begin(); it != tags.end(); ++it)
    {
        if (element == nullptr)
            element = doc.first_node((*it).data());
        else
            element = element->first_node((*it).data());
    }
    return element;
}

std::vector<std::string> RapidXMLParser::splitPath(std::string path)
{
    std::vector<std::string> elements;
    std::istringstream f(path);
    std::string s;
    while (std::getline(f, s, '/'))
    {
        elements.push_back(s);
    }
    return elements;
}