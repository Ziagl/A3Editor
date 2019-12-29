#pragma once

#include "XMLParserFacility.h"
#include "TinyXMLParser.h"
#include "RapidXMLParser.h"

class XMLParserFactory {
public:
	static XMLParser create()
	{
		// create needed XML Parser
		return std::make_shared<RapidXMLParser>();
	}
};