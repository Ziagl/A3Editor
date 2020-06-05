#pragma once

#include <wx/string.h>

class Sorting
{
public:
    /*
     * replace Umlauts for sorting
     */
    static void replaceUmlauts(wxString& input)
    {
        std::replace(input.begin(), input.end(), 'ä', 'a');
        std::replace(input.begin(), input.end(), 'ö', 'o');
        std::replace(input.begin(), input.end(), 'ü', 'u');
        std::replace(input.begin(), input.end(), 'Ä', 'A');
        std::replace(input.begin(), input.end(), 'Ö', 'O');
        std::replace(input.begin(), input.end(), 'Ü', 'U');
    }
};
