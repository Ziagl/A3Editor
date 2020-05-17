#pragma once

#include "LoggingFacility.h"
#include "StandardOutputLogger.h"
#include "FilesystemLogger.h"

class __declspec(dllexport) LoggerFactory {
public:
	static Logger create()
	{
		// read config file from filesystem
		std::string filename = "logger.conf";
		std::ifstream filestream(filename);
		// if configuration file exists - use FilesystemLogger
		if (filestream.good())
		{
			el::Configurations conf(filename);
			el::Loggers::reconfigureAllLoggers(conf);
			return std::make_shared<FilesystemLogger>();
		}
		// if not available use StandardOutputLogger
		return std::make_shared<StandardOutputLogger>();
	}
};