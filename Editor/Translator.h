#pragma once

#include "../Core/Translator.h"

namespace Editor {

	// wrapper class for Core::Translator
	class Translator
	{
	public:
		Translator(std::string filename, std::string language) : translator(filename, language) {}

		std::string translate(std::string value) { return translator.translate(value); }
	private:
		Core::Translator translator;
	};
}