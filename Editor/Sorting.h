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
        std::replace(input.begin(), input.end(), '�', 'a');
        std::replace(input.begin(), input.end(), '�', 'o');
        std::replace(input.begin(), input.end(), '�', 'u');
        std::replace(input.begin(), input.end(), '�', 'A');
        std::replace(input.begin(), input.end(), '�', 'O');
        std::replace(input.begin(), input.end(), '�', 'U');
    }
};
