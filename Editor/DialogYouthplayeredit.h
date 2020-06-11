#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
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

class DialogYouthplayeredit : public wxDialog
{
public:
    DialogYouthplayeredit(wxWindow* parent, Toolset* const tools, const std::string selectedCountry, Core::YouthPlayer& youthplayer, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogYouthplayeredit();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

protected:
    wxTextCtrl* m_textCtrlName;
    wxTextCtrl* m_textCtrlFirstname;
    wxChoice* m_choiceClub;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
    Core::YouthPlayer& m_youthplayer;
    std::string m_selectedCountry;
};

