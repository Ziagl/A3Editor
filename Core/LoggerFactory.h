#pragma once

#include "EasyLogger.h"

class LoggerFactory 
{
public:
	static Logger create()
	{
		// read config file from filesystem
		std::string filename = "logger.conf";
		std::ifstream filestream(filename);
		// if configuration file exists
		if (filestream.good())
		{
			el::Configurations conf(filename);
			el::Loggers::reconfigureAllLoggers(conf);
		}
		return std::make_shared<EasyLogger>();
	}
};