#include "A3LegacyWriter.h"
#include <fstream>
#include <sstream>

void A3LegacyWriter::saveCountryFile(std::shared_ptr<Country> country, std::string filename)
{
	std::ofstream stream;

	stream.open(filename, std::ios::out);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while writing " + filename);
		stream.close();
		return;
	}

	// write file "header"
	stream << "17373592\n";

	

	stream.flush();
	stream.close();

	return;
}