#pragma once

#include <vector>
#include "XMLParserFacility.h"
#include "tinyxml2.h"

class TinyXMLParser : public XMLParserFacility 
{
public:
	TinyXMLParser() : doc() {}
	virtual void loadFile(const std::string filename) override
	{
		doc.LoadFile(filename.data());
	}
	virtual std::string getValue(const std::string path) override;
	virtual std::string getAttributeValue(const std::string path, const std::string name) override;
	virtual std::vector<std::string> getChildren(const std::string path) override;

private:
	std::vector<std::string> splitPath(std::string path);
	tinyxml2::XMLElement* findElement(std::string path);

	tinyxml2::XMLDocument doc;
};
