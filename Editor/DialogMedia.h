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
#include <wx/scrolbar.h>
#include <wx/panel.h>
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

class DialogMedia : public wxDialog
{
public:
    DialogMedia(wxWindow* parent, Toolset* const tools, const std::string selectedCountry, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogMedia();

protected:
    wxStaticText* m_staticText75;
    wxTextCtrl* m_textCtrlNameReporter1;
    wxStaticText* m_staticText115;
    wxStaticText* m_staticText79;
    wxTextCtrl* m_textCtrlFirstnameReporter1;
    wxScrollBar* m_scrollBar117;
    wxStaticText* m_staticText83;
    wxTextCtrl* m_textCtrlNameReporter2;
    wxPanel* m_panel119;
    wxStaticText* m_staticText87;
    wxTextCtrl* m_textCtrlFirstnameReporter2;
    wxScrollBar* m_scrollBar121;
    wxStaticText* m_staticText91;
    wxTextCtrl* m_textCtrlNameReporter3;
    wxPanel* m_panel123;
    wxStaticText* m_staticText95;
    wxTextCtrl* m_textCtrlFirstnameReporter3;
    wxScrollBar* m_scrollBar125;
    wxStaticText* m_staticText51;
    wxTextCtrl* m_textCtrlNameCritic1;
    wxStaticText* m_staticText55;
    wxTextCtrl* m_textCtrlFirstnameCritic1;
    wxStaticText* m_staticText59;
    wxTextCtrl* m_textCtrlNameCritic2;
    wxStaticText* m_staticText63;
    wxTextCtrl* m_textCtrlFirstnameCritic2;
    wxStaticText* m_staticText37;
    wxTextCtrl* m_textCtrlStation1;
    wxStaticText* m_staticText41;
    wxTextCtrl* m_textCtrlStation2;
    wxStaticText* m_staticText45;
    wxTextCtrl* Station3;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
    std::string m_selectedCountry;
    std::shared_ptr<Core::Country> m_country = nullptr;
};

