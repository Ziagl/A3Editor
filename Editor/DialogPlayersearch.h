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
#include <wx/stattext.h>
#include <wx/listctrl.h>
#include <wx/gauge.h>
#include <wx/msgdlg.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogPlayersearch : public wxDialog
{
public:
    DialogPlayersearch(wxWindow* parent, 
        Toolset* const tools,
        wxWindowID id = wxID_ANY, 
        const wxString& title = _("Playersearch"), 
        const wxPoint& pos = wxDefaultPosition, 
        const wxSize& size = wxSize(500, 700), 
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPlayersearch();

protected:
    // Event Handler
    void OnCancel(wxCommandEvent& event);
    void OnStart(wxCommandEvent& event);

protected:
    wxRadioButton* m_radioSearchPerson;
    wxRadioButton* m_radioCheckData;
    wxButton* m_buttonStart;
    wxStaticText* m_staticFirstname;
    wxTextCtrl* m_textFirstname;
    wxStaticText* m_staticLastname;
    wxTextCtrl* m_textLastname;
    wxGauge* m_gaugeProgress;
    wxStaticText* m_staticProgressText;
    wxListCtrl* m_listSearchResult;
    wxButton* m_buttonCancel;

private:
    void searchPerson();
    void checkData();

    Toolset* tools = nullptr;
};

