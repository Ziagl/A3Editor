#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/radiobut.h>
#include <wx/button.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogPlayerpools : public wxDialog
{
public:
    DialogPlayerpools(wxWindow* parent, Toolset* const tools, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPlayerpools();

protected:
    wxRadioButton* m_radioButtonAfrica;
    wxRadioButton* m_radioButtonNorway;
    wxRadioButton* m_radioButtonArabia;
    wxRadioButton* m_radioButtonPoland;
    wxRadioButton* m_radioButtonAsia;
    wxRadioButton* m_radioButtonRomania;
    wxRadioButton* m_radioButtonBelgium;
    wxRadioButton* m_radioButtonRussia;
    wxRadioButton* m_radioButtonBulgaria;
    wxRadioButton* m_radioButtonSweden;
    wxRadioButton* m_radioButtonDenmark;
    wxRadioButton* m_radioButtonOtherBalkanCountries;;
    wxRadioButton* m_radioButtonFinland;
    wxRadioButton* m_radioButtonSlovakiaAndTheCzechRepublic;
    wxRadioButton* m_radioButtonGreek;
    wxRadioButton* m_radioButtonHungary;
    wxRadioButton* m_radioButtonIsrael;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
};

