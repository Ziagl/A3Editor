#pragma once

#include <string>
#include <vector>
#include "EasyLogger.h"

namespace Core
{
	enum Pool
	{
		POOL_AFRICA,
		POOL_ARABIA,
		POOL_ASIA,
		POOL_BELGIUM,
		POOL_BULGARIA,
		POOL_DENMARK,
		POOL_FINLAND,
		POOL_GREEK,
		POOL_ISRAEL,
		POOL_NORWAY,
		POOL_POLAND,
		POOL_RUMANIA,
		POOL_RUSSIA,
		POOL_SWEDEN,
		POOL_BALKAN_COUNRIES,
		POOL_SLOVAKIA_CZECH_REPUBLIC,
		POOL_HUNGARY
	};

	class Playerpool
	{
	public:
		Playerpool() { }
		~Playerpool() {}

		// getter
		std::vector<std::tuple<std::string, std::string>> getPool(short type) { if (type < data.size()) return data.at(type); else return std::vector< std::tuple<std::string, std::string>>(); }
		// setter
		void setPool(std::vector<std::vector<std::tuple<std::string, std::string>>> data) { this->data = data; }

	private:
		std::vector<std::vector<std::tuple<std::string, std::string>>> data;
	};
}