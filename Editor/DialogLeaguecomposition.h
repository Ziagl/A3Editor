#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/listctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/tglbtn.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogLeaguecomposition : public wxDialog
{
public:
    DialogLeaguecomposition(wxWindow* parent, Toolset* const tools, const std::string selectedCountry, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogLeaguecomposition();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnAdd(wxCommandEvent& event);
    void OnRemove(wxCommandEvent& event);
    void OnLeague(wxCommandEvent& event);

protected:
    wxListCtrl* m_listCtrlClubs;
    wxStaticText* m_staticText93;
    wxPanel* m_panel95;
    wxButton* m_buttonRemove;
    wxButton* m_buttonAdd;
    wxListCtrl* m_listCtrlOtherClubs;
    wxStaticBitmap* m_staticBitmap61;
    wxStaticText* m_staticText63;
    wxStaticBitmap* m_staticBitmap65;
    wxStaticText* m_staticText67;
    wxStaticBitmap* m_staticBitmap69;
    wxStaticText* m_staticText71;
    wxStaticBitmap* m_staticBitmap73;
    wxStaticText* m_staticText75;
    wxStaticBitmap* m_staticBitmap77;
    wxStaticText* m_staticText79;
    wxStaticBitmap* m_staticBitmap81;
    wxStaticText* m_staticText83;
    wxStaticBitmap* m_staticBitmap85;
    wxStaticText* m_staticText87;
    std::vector<wxToggleButton*> m_toggleButtonLeague;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    void initializeClubsList(wxListCtrl* control);
    void initializeOtherClubsList(wxListCtrl* control);
    void loadLeague();

    Toolset* tools = nullptr;
    std::string m_selectedCountry;
    std::vector<vertex_t> m_leagueIds;
    std::vector<std::vector<vertex_t>> m_leagueTeamIds;
    std::vector<vertex_t> m_noLeagueTeamIds;
    short m_selectedLeague;
};

