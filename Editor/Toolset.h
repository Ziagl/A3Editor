#pragma once

#include <memory>
#include "Translator.h"

class Toolset
{
public:
    virtual void SetTranslator(std::shared_ptr<Editor::Translator> translator)
    {
        this->translator = translator;
    }
    std::string translate(std::string value)
    {
        return translator->translate(value);
    }

protected:
    std::shared_ptr<Editor::Translator> translator;
};