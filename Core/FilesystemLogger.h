#pragma once

#include "LoggingFacility.h"
#include "easylogging++.h"

class FilesystemLogger : public LoggingFacility {
public:
	virtual void writeInfoEntry(std::string_view entry) override 
	{
		LOG(INFO) << entry;
	}
	virtual void writeWarnEntry(std::string_view entry) override 
	{
		LOG(WARNING) << entry;
	}
	virtual void writeErrorEntry(std::string_view entry) override 
	{
		LOG(ERROR) << entry;
	}
};