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
#include <wx/textctrl.h>
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

class DialogStatistics : public wxDialog
{
public:
    DialogStatistics(wxWindow* parent, Toolset* const tools, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogStatistics();

protected:
    // Event Handler
    void OnOk(wxCommandEvent& event);

protected:
    wxListCtrl* m_listCtrlPlayerSum;
    wxListCtrl* m_listCtrlStrength;
    wxListCtrl* m_listCtrlPositions;
    wxStaticText* m_staticText113;
    wxTextCtrl* m_textCtrlMostPlayersName;
    wxTextCtrl* m_textCtrlMostPlayersValue;
    wxStaticText* m_staticText119;
    wxTextCtrl* m_textCtrlLeastPlayerName;
    wxTextCtrl* m_textCtrlLeastPlayerValue;
    wxStaticText* m_staticText125;
    wxPanel* m_panel127;
    wxTextCtrl* m_textCtrlPlayerAverage;
    wxTextCtrl* m_textCtrlOldieName;
    wxTextCtrl* m_textCtrlOldieTeam;
    wxTextCtrl* m_textCtrlOldieValue;
    wxStaticText* m_staticText85;
    wxTextCtrl* m_textCtrlstrongestTeamName;
    wxTextCtrl* m_textCtrlStrongestTeamValue;
    wxStaticText* m_staticText91;
    wxTextCtrl* m_textCtrlWeakestTeamName;
    wxTextCtrl* m_textCtrlWeakestTeamValue;
    wxStaticText* m_staticText97;
    wxPanel* m_panel99;
    wxTextCtrl* m_textCtrlTeamAverage;
    wxTextCtrl* m_textCtrlStrongestLeagueName;
    wxStaticText* m_staticText79;
    wxTextCtrl* m_textCtrlStrongestLeagueAverage;
    wxStaticText* m_staticText57;
    wxTextCtrl* m_textCtrlStadiumGreatestName;
    wxTextCtrl* m_textCtrlStadiumGreatestSize;
    wxStaticText* m_staticText63;
    wxTextCtrl* m_textCtrlStadiumSmallestName;
    wxTextCtrl* m_textCtrlStadiumSmallestSize;
    wxStaticText* m_staticText69;
    wxPanel* m_panel71;
    wxTextCtrl* m_textCtrlStadiumAverage;
    wxButton* m_buttonOk;

private:
    void initializePlayerList(wxListCtrl* control);
    void initializeStrengthList(wxListCtrl* control);
    void initializePositionList(wxListCtrl* control);

    // player
    vertex_t m_teamMostPlayersId;
    short m_teamMostPlayersValue = 0;
    vertex_t m_teamLeastPlayersId;
    int m_teamLeastPlayersValue = 99999;
    short m_teamPlayersAverage = 0;
    vertex_t m_oldiePlayerId;
    vertex_t m_oldiePlayerTeamId;
    // team
    vertex_t m_teamStrongestId;
    float m_teamStrongestValue = 0.0f;
    vertex_t m_teamWeakestId;
    float m_teamWeakestValue = 99.9f;
    float m_teamStrengthAverage = 0.0f;
    // league
    vertex_t m_leagueStrongestId;
    float m_leagueStrongestValue = 0.0f;
    // stadium
    vertex_t m_teamBiggestStadiumId;
    int m_teamBiggestStadiumValue = 0;
    vertex_t m_teamSmallestStadiumId;
    int m_teamSmallestStadiumValue = 999999999;
    int m_teamStadiumAverage = 0;

    Toolset* tools = nullptr;
};

