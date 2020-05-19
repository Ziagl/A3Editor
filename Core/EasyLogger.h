#pragma once

#include "easylogging++.h"

namespace Core
{
	class EasyLogger
	{
	public:
		void writeInfoEntry(std::string_view entry)
		{
			LOG(INFO) << entry;
		}
		void writeWarnEntry(std::string_view entry)
		{
			LOG(WARNING) << entry;
		}
		void writeErrorEntry(std::string_view entry)
		{
			LOG(ERROR) << entry;
		}
	};

	//class LoggingFacilityWrapper : public std::shared_ptr<LoggingFacility> {};	// warning C4251 fix
	using Logger = std::shared_ptr<EasyLogger>;
}