#pragma once

#include <memory>
#include <vector>
#include <string>

class XMLParserFacility 
{
public:
	virtual ~XMLParserFacility() = default;
	
	// read XML
	virtual void loadFile(const std::string filename) = 0;
	virtual std::string getValue(const std::string path) = 0;
	virtual std::string getAttributeValue(const std::string path, const std::string name) = 0;
	virtual std::vector<std::string> getChildren(const std::string path) = 0;

	// write XML
	// currently not needed
};

using XMLParser = std::shared_ptr<XMLParserFacility>;