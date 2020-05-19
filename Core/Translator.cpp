#include "Translator.h"
#include "XMLParserFactory.h"

using namespace Core;

Translator::Translator(std::string filename, std::string language)
{
	RapidXMLParser xml;
	xml.loadFile(filename);
	std::vector<std::string> elements = xml.getChildren("root");
	for (std::vector<std::string>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		std::string path = "root/" + (*it) + "/" + language;
		std::string value = xml.getValue(path);
		if(!value.empty())
			list.insert(std::make_pair(*it, value));
	}
}

std::string Translator::translate(std::string search)
{
	if (list.find(search) == list.end()) 
	{
		return "MISSING TRANSLATION ("+search+")";
	}
	else
	{
		return list[search];
	}
}