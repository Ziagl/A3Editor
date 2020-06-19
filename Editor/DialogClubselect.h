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
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/msgdlg.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogClubselect : public wxDialog
{
public:
    DialogClubselect(wxWindow* parent,
        Toolset* const tools,
        const ClubselectType type,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Clubselect"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(-1, -1),
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogClubselect();

    wxListCtrl* GetCountryList() { return m_countryList; }
    wxListCtrl* GetClubList() { return m_clubList; }
    wxButton* GetButtonEdit() { return m_buttonEdit; }
    wxButton* GetButtonApply() { return m_buttonApply; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }
    wxButton* GetButtonSearchPlayer() { return m_buttonSearchPlayer; } wxStaticBitmap* GetStaticBitmapClubImage() { return m_staticBitmapClubImage; }

    std::string GetSelectedCountry() { return m_selectedCountry; }
    std::string GetSelectedClub() { return m_selectedClub; }

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnApply(wxCommandEvent& event);
    void OnSearchPlayer(wxCommandEvent& event);
    void OnSelectCountry(wxListEvent& event);
    void OnSelectClub(wxListEvent& event);
    void OnSelectClubActivated(wxListEvent& event);

private:
    void initializeCountryList(wxListCtrl* control);
    void initializeClubList(wxListCtrl* control);
    void updateClubList();

protected:
    wxListCtrl* m_countryList;
    wxListCtrl* m_clubList;
    wxButton* m_buttonEdit;
    wxButton* m_buttonApply;
    wxButton* m_buttonAbort;
    wxButton* m_buttonSearchPlayer;
    wxStaticBitmap* m_staticBitmapClubImage;

private:
    std::vector<std::string> m_countriesWithLeagues;
    std::string m_selectedCountry;
    std::string m_selectedClub;
    Toolset* tools = nullptr;
    ClubselectType type;
    wxWindow* parent = nullptr;
    std::shared_ptr<Core::Country> m_country;
};