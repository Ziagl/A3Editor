#pragma once

#include <memory>
#include "Translator.h"
#include "PlayableCountries.h"

class Toolset
{
public:
    // initializers
    virtual void SetTranslator(std::shared_ptr<Editor::Translator> translator)
    {
        this->translator = translator;
    }
    virtual void SetPlayableCountries(std::shared_ptr<Editor::PlayableCountries> playableCountries)
    {
        this->playableCountries = playableCountries;
    }

    // actions
    std::string translate(std::string value);
    std::vector<std::string> GetPlayableCountries();

protected:
    std::shared_ptr<Editor::Translator> translator = nullptr;
    std::shared_ptr<Editor::PlayableCountries> playableCountries = nullptr;
};