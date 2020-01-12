#pragma once

#include <map>
#include <string>

class Translator
{
public:
	Translator(std::string filename, std::string language);
	
	std::string translate(std::string);

private:
	std::map<std::string, std::string> list;
};