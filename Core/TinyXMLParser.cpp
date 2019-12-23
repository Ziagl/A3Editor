#include "TinyXMLParser.h"
#include <sstream>
#include <iostream>

std::string TinyXMLParser::getValue(const std::string path)
{
    tinyxml2::XMLElement* element = findElement(path);
    if (element)
        return element->GetText();
    else
        return "";
}

std::string TinyXMLParser::getAttributeValue(const std::string path, const std::string name)
{
    tinyxml2::XMLElement* element = findElement(path);
    if (!element)
        return "";
    const tinyxml2::XMLAttribute* attribute = element->FindAttribute(name.c_str()); 
    return attribute->Value();
}

tinyxml2::XMLElement* TinyXMLParser::findElement(std::string path)
{
    tinyxml2::XMLElement* element = nullptr;
    std::vector<std::string> tags = splitPath(path);

    for (std::vector<std::string>::iterator it = tags.begin(); it != tags.end(); ++it)
    {
        if (element == nullptr)
            element = doc.FirstChildElement((*it).data());
        else
            element = element->FirstChildElement((*it).data());
    }
    return element;
}

std::vector<std::string> TinyXMLParser::splitPath(std::string path)
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