#include "DialogStatistics.h"

DialogStatistics::DialogStatistics(wxWindow* parent, 
    Toolset* const tools,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer19 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer19->SetFlexibleDirection(wxBOTH);
    flexGridSizer19->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer19->AddGrowableCol(1);

    flexGridSizer17->Add(flexGridSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Anzahl Spieler gesamt")), wxVERTICAL);

    flexGridSizer19->Add(staticBoxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPlayerSum = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT);

    staticBoxSizer27->Add(m_listCtrlPlayerSum, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer29 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer29->SetFlexibleDirection(wxBOTH);
    flexGridSizer29->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer19->Add(flexGridSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer31 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Stärken")), wxVERTICAL);

    flexGridSizer29->Add(staticBoxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlStrength = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT);

    staticBoxSizer31->Add(m_listCtrlStrength, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer35 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Positionen")), wxVERTICAL);

    flexGridSizer29->Add(staticBoxSizer35, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPositions = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT);

    staticBoxSizer35->Add(m_listCtrlPositions, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer21 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer21->SetFlexibleDirection(wxBOTH);
    flexGridSizer21->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer43 = new wxFlexGridSizer(5, 1, 0, 0);
    flexGridSizer43->SetFlexibleDirection(wxBOTH);
    flexGridSizer43->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer21->Add(flexGridSizer43, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer45 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Anzahl Spieler pro Team")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer45, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer111 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer111->SetFlexibleDirection(wxBOTH);
    flexGridSizer111->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer45->Add(flexGridSizer111, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText113 = new wxStaticText(this, wxID_ANY, _("Meiste Spieler"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer111->Add(m_staticText113, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlMostPlayersName = new wxTextCtrl(this, wxID_ANY, wxT("Cambridge Albion"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlMostPlayersName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlMostPlayersName->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlMostPlayersName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlMostPlayersValue = new wxTextCtrl(this, wxID_ANY, wxT("34"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlMostPlayersValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlMostPlayersValue->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlMostPlayersValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText119 = new wxStaticText(this, wxID_ANY, _("Wenigste Spieler"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer111->Add(m_staticText119, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlLeastPlayerName = new wxTextCtrl(this, wxID_ANY, wxT("1.FC Spandau"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlLeastPlayerName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlLeastPlayerName->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlLeastPlayerName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlLeastPlayerValue = new wxTextCtrl(this, wxID_ANY, wxT("16"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlLeastPlayerValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlLeastPlayerValue->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlLeastPlayerValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText125 = new wxStaticText(this, wxID_ANY, _("Durchschnitt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer111->Add(m_staticText125, 0, wxALL, WXC_FROM_DIP(5));

    m_panel127 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer111->Add(m_panel127, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlPlayerAverage = new wxTextCtrl(this, wxID_ANY, wxT("23"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlPlayerAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPlayerAverage->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlPlayerAverage, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer47 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Oldie")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer47, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer103 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer103->SetFlexibleDirection(wxBOTH);
    flexGridSizer103->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer47->Add(flexGridSizer103, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlOldieName = new wxTextCtrl(this, wxID_ANY, wxT("Anatoli Mevydov"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlOldieName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlOldieName->SetHint(wxT(""));
#endif

    flexGridSizer103->Add(m_textCtrlOldieName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlOldieTeam = new wxTextCtrl(this, wxID_ANY, wxT("Torpedo Petersburg"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlOldieTeam->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlOldieTeam->SetHint(wxT(""));
#endif

    flexGridSizer103->Add(m_textCtrlOldieTeam, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlOldieValue = new wxTextCtrl(this, wxID_ANY, wxT("45"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlOldieValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlOldieValue->SetHint(wxT(""));
#endif

    flexGridSizer103->Add(m_textCtrlOldieValue, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer49 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Mannschaften")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer49, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer83 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer83->SetFlexibleDirection(wxBOTH);
    flexGridSizer83->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer49->Add(flexGridSizer83, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText85 = new wxStaticText(this, wxID_ANY, _("Stärkste"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer83->Add(m_staticText85, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlstrongestTeamName = new wxTextCtrl(this, wxID_ANY, wxT("Manchester Town"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlstrongestTeamName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlstrongestTeamName->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlstrongestTeamName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStrongestTeamValue = new wxTextCtrl(this, wxID_ANY, wxT("10.35"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStrongestTeamValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStrongestTeamValue->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlStrongestTeamValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText91 = new wxStaticText(this, wxID_ANY, _("Schwächste"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer83->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlWeakestTeamName = new wxTextCtrl(this, wxID_ANY, wxT("Yeovil City"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlWeakestTeamName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlWeakestTeamName->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlWeakestTeamName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlWeakestTeamValue = new wxTextCtrl(this, wxID_ANY, wxT("2.38"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlWeakestTeamValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlWeakestTeamValue->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlWeakestTeamValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText97 = new wxStaticText(this, wxID_ANY, _("Durchschnitt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer83->Add(m_staticText97, 0, wxALL, WXC_FROM_DIP(5));

    m_panel99 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer83->Add(m_panel99, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlTeamAverage = new wxTextCtrl(this, wxID_ANY, wxT("5.38"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlTeamAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlTeamAverage->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlTeamAverage, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer51 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Stärkste Liga")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer75 = new wxFlexGridSizer(1, 3, 0, 0);
    flexGridSizer75->SetFlexibleDirection(wxBOTH);
    flexGridSizer75->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer51->Add(flexGridSizer75, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlStrongestLeagueName = new wxTextCtrl(this, wxID_ANY, wxT("Italien - 1. Liga ITA"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStrongestLeagueName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStrongestLeagueName->SetHint(wxT(""));
#endif

    flexGridSizer75->Add(m_textCtrlStrongestLeagueName, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText79 = new wxStaticText(this, wxID_ANY, _("Durchschnitt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer75->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStrongestLeagueAverage = new wxTextCtrl(this, wxID_ANY, wxT("8.53"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStrongestLeagueAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStrongestLeagueAverage->SetHint(wxT(""));
#endif

    flexGridSizer75->Add(m_textCtrlStrongestLeagueAverage, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer53 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Stadien")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer53, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer55 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer55->SetFlexibleDirection(wxBOTH);
    flexGridSizer55->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer53->Add(flexGridSizer55, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText57 = new wxStaticText(this, wxID_ANY, _("Größtes"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer55->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumGreatestName = new wxTextCtrl(this, wxID_ANY, wxT("RCD Barcelona"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumGreatestName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumGreatestName->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumGreatestName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumGreatestSize = new wxTextCtrl(this, wxID_ANY, wxT("112.000"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumGreatestSize->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumGreatestSize->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumGreatestSize, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText63 = new wxStaticText(this, wxID_ANY, _("Kleinstes"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer55->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumSmallestName = new wxTextCtrl(this, wxID_ANY, wxT("UDL Jerez"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumSmallestName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumSmallestName->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumSmallestName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumSmallestSize = new wxTextCtrl(this, wxID_ANY, wxT("2.000"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumSmallestSize->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumSmallestSize->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumSmallestSize, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText69 = new wxStaticText(this, wxID_ANY, _("Durchschnitt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer55->Add(m_staticText69, 0, wxALL, WXC_FROM_DIP(5));

    m_panel71 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer55->Add(m_panel71, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumAverage = new wxTextCtrl(this, wxID_ANY, wxT("20.695"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumAverage->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumAverage, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer17->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    }
    else {
        CentreOnScreen(wxBOTH);
    }
/*#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    }
    else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif*/
}

DialogStatistics::~DialogStatistics()
{
}
