#pragma once

#include "XMLParserFacility.h"
#include "TinyXMLParser.h"
#include "RapidXMLParser.h"

namespace Core
{
	class XMLParserFactory {
	public:
		static XMLParser create()
		{
			// create needed XML Parser
			return std::make_shared<RapidXMLParser>();
		}
	};
}