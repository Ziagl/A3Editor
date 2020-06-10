#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
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

class DialogNationalcompetitions : public wxDialog
{
public:
    DialogNationalcompetitions(wxWindow* parent, Toolset* const tools, const std::string selectedCountry, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogNationalcompetitions();

protected:
    wxStaticText* m_staticText31;
    wxTextCtrl* m_textCtrl33;
    wxStaticText* m_staticText35;
    wxTextCtrl* m_textCtrl37;
    wxStaticText* m_staticText39;
    wxTextCtrl* m_textCtrl41;
    wxStaticText* m_staticText43;
    wxTextCtrl* m_textCtrl45;
    wxStaticText* m_staticText47;
    wxTextCtrl* m_textCtrl49;
    wxStaticText* m_staticText51;
    wxTextCtrl* m_textCtrl53;
    wxStaticText* m_staticText55;
    wxTextCtrl* m_textCtrl57;
    wxStaticText* m_staticText59;
    wxTextCtrl* m_textCtrl61;
    wxStaticLine* m_staticLine71;
    wxStaticText* m_staticText27;
    wxTextCtrl* m_textCtrl29;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
    std::string selectedCountry;
};

