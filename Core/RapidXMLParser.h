#pragma once

#include <vector>
#include <iostream>
#include "XMLParserFacility.h"
#include "rapidxml_utils.hpp"

class RapidXMLParser : public XMLParserFacility
{
public:
	RapidXMLParser() : doc() {}
	virtual void loadFile(const std::string filename) override
	{
		this->filename = filename;
	}
	virtual std::string getValue(const std::string path) override;
	virtual std::string getAttributeValue(const std::string path, const std::string name) override;

private:
	std::vector<std::string> splitPath(std::string path);
	rapidxml::xml_node<>* findElement(std::string path);

	rapidxml::xml_document<> doc;
	std::string filename;
};
