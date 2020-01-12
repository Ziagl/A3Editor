#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class Editor : public wxFrame
{
public:
    Editor(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("ANSTOSS 3 - Dateneditor"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(634, 476),
        long style = wxCAPTION | wxCLOSE_BOX);
    virtual ~Editor();

    wxPanel* GetMainPanel()
    {
        return m_mainPanel;
    }
    wxMenuBar* GetMenuBar()
    {
        return m_menuBar;
    }

protected:
    // Event Handler
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnLoad(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);

protected:
    wxPanel* m_mainPanel;
    wxMenuBar* m_menuBar;
    wxMenu* m_menuFile;
    wxMenuItem* m_menuReinitialize;
    wxMenuItem* m_menuLoad;
    wxMenuItem* m_menuDatacheck;
    wxMenuItem* m_menuSave;
    wxMenuItem* m_menuExit;
    wxMenu* m_menuNational;
    wxMenuItem* m_menuTeams;
    wxMenuItem* m_menuPlayer;
    wxMenuItem* m_menuPlayerList;
    wxMenuItem* m_menuAmateurClubs;
    wxMenuItem* m_menuAmateurPlayer;
    wxMenuItem* m_menuTrainer;
    wxMenuItem* m_menuGoalkeeperTrainer;
    wxMenuItem* m_menuManager;
    wxMenuItem* m_menuReferee;
    wxMenuItem* m_menuAssociation;
    wxMenuItem* m_menuNationalCup;
    wxMenuItem* m_menuMedia;
    wxMenuItem* m_menuCelebrity;
    wxMenuItem* m_menuSponsors;
    wxMenu* m_menuInternational;
    wxMenuItem* m_menuNonEuropeanClubs;
    wxMenuItem* m_menuPlayerpool;
    wxMenuItem* m_menuOtherPlayer;
    wxMenuItem* m_menuFormerPlayer;
    wxMenuItem* m_menuEuropeanReferees;
    wxMenuItem* m_menuInternationalCups;
    wxMenuItem* m_menuEuropeanCupGroups;
    wxMenuItem* m_menuEuropeanChampionshipGroups;
    wxMenuItem* m_menuWorldChampionshipGroups;
    wxMenuItem* m_menuEuropeanWorldChampionship;
    wxMenuItem* m_menuNationalJerseys;
    wxMenuItem* m_menuNationalSquad;
    wxMenuItem* m_menuBestPlayers;
    wxMenuItem* m_menuOutfitter;
    wxMenu* m_menuSpecial;
    wxMenuItem* m_menuTextChants;
    wxMenuItem* m_menuAudioChants;
    wxMenuItem* m_menuHalftimeSpeeches;
    wxMenuItem* m_menuCountryStartingPositions;
    wxMenuItem* m_menuGamePlans;
    wxMenuItem* m_menu5YearRating;
    wxMenuItem* m_menuLittleThings;
    wxMenuItem* m_menuStatistic;
    wxMenuItem* m_menuNewBonusCountry;
    wxMenu* m_nameHelp;
    wxMenuItem* m_menuAbout;
};