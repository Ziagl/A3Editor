#pragma once

#include "easylogging++.h"
#include <mutex>

namespace Core
{
	class EasyLogger
	{
	public:
		void writeInfoEntry(std::string_view entry)
		{
			std::lock_guard<std::mutex> lockguard(mutex);

			LOG(INFO) << entry;
		}
		void writeWarnEntry(std::string_view entry)
		{
			std::lock_guard<std::mutex> lockguard(mutex);

			LOG(WARNING) << entry;
		}
		void writeErrorEntry(std::string_view entry)
		{
			std::lock_guard<std::mutex> lockguard(mutex);

			LOG(ERROR) << entry;
		}
	private:
		std::mutex mutex;
	};

	//class LoggingFacilityWrapper : public std::shared_ptr<LoggingFacility> {};	// warning C4251 fix
	using Logger = std::shared_ptr<EasyLogger>;
}