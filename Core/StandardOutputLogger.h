#pragma once

#include <iostream>
#include "LoggingFacility.h"

class StandardOutputLogger : public LoggingFacility {
public:
	virtual void writeInfoEntry(std::string_view entry) override 
	{
		std::cout << "[INFO] " << entry << std::endl;
	}
	virtual void writeWarnEntry(std::string_view entry) override 
	{
		std::cout << "[WARNING] " << entry << std::endl;
	}
	virtual void writeErrorEntry(std::string_view entry) override 
	{
		std::cout << "[ERROR] " << entry << std::endl;
	}
};