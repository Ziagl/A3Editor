#pragma once

#include <string>
#include <vector>

namespace Core
{
	class Eurowinner
	{
	public:
		Eurowinner() {}
		~Eurowinner() {}

		// getter / setter
		void addValue(std::vector<short> value) { this->value.push_back(value); }
		auto getValue() { return value; }

	private:
		std::vector<std::vector<short>> value;
	};
}