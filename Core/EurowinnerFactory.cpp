#include "EurowinnerFactory.h"

using namespace Core;

Eurowinner EurowinnerFactory::createFromSAV(std::vector<std::string> data)
{
	Eurowinner eurowinner;

	if (data.empty())
	{
		logger->writeErrorEntry("Eurowinner data is empty.");
		return eurowinner;
	}

	int count = std::stoi(data[0]);
	// every 3 lines
	for (int i = 0, index = 0; i < count; ++i, index = i * 3)
	{
		std::vector<short> value;
		value.push_back(std::stoi(data[index + 1]));
		value.push_back(std::stoi(data[index + 2]));
		value.push_back(std::stoi(data[index + 3]));
		eurowinner.addValue(value);
	}

	return eurowinner;
}

void EurowinnerFactory::writeToSAV(Eurowinner& eurowinner, std::ofstream& out)
{
	auto values = eurowinner.getValue();

	// count
	out << std::to_string(values.size()) << "\n";
	for (std::vector<std::vector<short>>::iterator it = values.begin(); it < values.end(); ++it)
	{
		auto value = *it;
		out << value[0] << "\n";
		out << value[1] << "\n";
		out << value[2] << "\n";
	}
}