#include "Translator.h"
#include "XMLParserFactory.h"

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
	return list[search];
}