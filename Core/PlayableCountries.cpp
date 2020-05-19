#include "PlayableCountries.h"
#include "RapidXMLParser.h"

using namespace Core;

PlayableCountries::PlayableCountries(std::string filename)
{
	RapidXMLParser xml;
	xml.loadFile(filename);
	std::vector<std::string> elements = xml.getChildren("root");
	for (std::vector<std::string>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		list.push_back((*it));
	}
}