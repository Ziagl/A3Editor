#include "DialogStatistics.h"
#include <list>
#include <algorithm>

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

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(1, 3, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer19 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer19->SetFlexibleDirection(wxBOTH);
    flexGridSizer19->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("totalNumberOfPlayers")), wxVERTICAL);

    flexGridSizer19->Add(staticBoxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPlayerSum = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializePlayerList(m_listCtrlPlayerSum);

    staticBoxSizer27->Add(m_listCtrlPlayerSum, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer29 = new wxFlexGridSizer(1, 2, 0, 0);
    flexGridSizer29->SetFlexibleDirection(wxBOTH);
    flexGridSizer29->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer19->Add(flexGridSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer31 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("skills")), wxVERTICAL);

    flexGridSizer29->Add(staticBoxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlStrength = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER);
    initializeStrengthList(m_listCtrlStrength);

    staticBoxSizer31->Add(m_listCtrlStrength, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer35 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("positions")), wxVERTICAL);

    flexGridSizer29->Add(staticBoxSizer35, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPositions = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER);
    initializePositionList(m_listCtrlPositions);

    staticBoxSizer35->Add(m_listCtrlPositions, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer43 = new wxFlexGridSizer(5, 1, 0, 0);
    flexGridSizer43->SetFlexibleDirection(wxBOTH);
    flexGridSizer43->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer43, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer45 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("numberOfPlayersPerTeam")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer45, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer111 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer111->SetFlexibleDirection(wxBOTH);
    flexGridSizer111->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer45->Add(flexGridSizer111, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText113 = new wxStaticText(this, wxID_ANY, tools->translate("mostPlayers"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer111->Add(m_staticText113, 0, wxALL, WXC_FROM_DIP(5));

    auto teamMostPlayer = tools->getTeamById(m_teamMostPlayersId);
    m_textCtrlMostPlayersName = new wxTextCtrl(this, wxID_ANY, teamMostPlayer->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlMostPlayersName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlMostPlayersName->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlMostPlayersName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlMostPlayersValue = new wxTextCtrl(this, wxID_ANY, std::to_string(m_teamMostPlayersValue), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlMostPlayersValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlMostPlayersValue->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlMostPlayersValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText119 = new wxStaticText(this, wxID_ANY, tools->translate("leastPlayers"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer111->Add(m_staticText119, 0, wxALL, WXC_FROM_DIP(5));

    auto teamLeastPlayer = tools->getTeamById(m_teamLeastPlayersId);
    m_textCtrlLeastPlayerName = new wxTextCtrl(this, wxID_ANY, teamLeastPlayer->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlLeastPlayerName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlLeastPlayerName->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlLeastPlayerName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlLeastPlayerValue = new wxTextCtrl(this, wxID_ANY, std::to_string(m_teamLeastPlayersValue), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlLeastPlayerValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlLeastPlayerValue->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlLeastPlayerValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText125 = new wxStaticText(this, wxID_ANY, tools->translate("average"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer111->Add(m_staticText125, 0, wxALL, WXC_FROM_DIP(5));

    m_panel127 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer111->Add(m_panel127, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlPlayerAverage = new wxTextCtrl(this, wxID_ANY, std::to_string(m_teamPlayersAverage), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlPlayerAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPlayerAverage->SetHint(wxT(""));
#endif

    flexGridSizer111->Add(m_textCtrlPlayerAverage, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer47 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("oldie")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer47, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer103 = new wxFlexGridSizer(1, 3, 0, 0);
    flexGridSizer103->SetFlexibleDirection(wxBOTH);
    flexGridSizer103->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer47->Add(flexGridSizer103, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    auto oldiePlayer = tools->getPlayerById(m_oldiePlayerId);
    m_textCtrlOldieName = new wxTextCtrl(this, wxID_ANY, oldiePlayer->getFirstname() + " " + oldiePlayer->getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlOldieName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlOldieName->SetHint(wxT(""));
#endif

    flexGridSizer103->Add(m_textCtrlOldieName, 0, wxALL, WXC_FROM_DIP(5));

    auto oldiePlayerTeam = tools->getTeamById(m_oldiePlayerTeamId);
    m_textCtrlOldieTeam = new wxTextCtrl(this, wxID_ANY, oldiePlayerTeam->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlOldieTeam->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlOldieTeam->SetHint(wxT(""));
#endif

    flexGridSizer103->Add(m_textCtrlOldieTeam, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlOldieValue = new wxTextCtrl(this, wxID_ANY, std::to_string(oldiePlayer->getAge()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlOldieValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlOldieValue->SetHint(wxT(""));
#endif

    flexGridSizer103->Add(m_textCtrlOldieValue, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer49 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("teams")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer49, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer83 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer83->SetFlexibleDirection(wxBOTH);
    flexGridSizer83->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer49->Add(flexGridSizer83, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText85 = new wxStaticText(this, wxID_ANY, tools->translate("strongest"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer83->Add(m_staticText85, 0, wxALL, WXC_FROM_DIP(5));

    auto teamStrongest = tools->getTeamById(m_teamStrongestId);
    m_textCtrlstrongestTeamName = new wxTextCtrl(this, wxID_ANY, teamStrongest->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlstrongestTeamName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlstrongestTeamName->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlstrongestTeamName, 0, wxALL, WXC_FROM_DIP(5));

    wchar_t buffer[100];
    swprintf(buffer, 100, L"%.2f", m_teamStrongestValue);
    m_textCtrlStrongestTeamValue = new wxTextCtrl(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStrongestTeamValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStrongestTeamValue->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlStrongestTeamValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText91 = new wxStaticText(this, wxID_ANY, tools->translate("weakest"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer83->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(5));

    auto teamWeakest = tools->getTeamById(m_teamWeakestId);
    m_textCtrlWeakestTeamName = new wxTextCtrl(this, wxID_ANY, teamWeakest->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlWeakestTeamName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlWeakestTeamName->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlWeakestTeamName, 0, wxALL, WXC_FROM_DIP(5));

    swprintf(buffer, 100, L"%.2f", m_teamWeakestValue);
    m_textCtrlWeakestTeamValue = new wxTextCtrl(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlWeakestTeamValue->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlWeakestTeamValue->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlWeakestTeamValue, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText97 = new wxStaticText(this, wxID_ANY, tools->translate("average"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer83->Add(m_staticText97, 0, wxALL, WXC_FROM_DIP(5));

    m_panel99 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer83->Add(m_panel99, 0, wxALL, WXC_FROM_DIP(5));

    swprintf(buffer, 100, L"%.2f", m_teamStrengthAverage);
    m_textCtrlTeamAverage = new wxTextCtrl(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlTeamAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlTeamAverage->SetHint(wxT(""));
#endif

    flexGridSizer83->Add(m_textCtrlTeamAverage, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer51 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("strongestLeague")), wxVERTICAL);

    flexGridSizer43->Add(staticBoxSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer75 = new wxFlexGridSizer(1, 3, 0, 0);
    flexGridSizer75->SetFlexibleDirection(wxBOTH);
    flexGridSizer75->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer51->Add(flexGridSizer75, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    auto leagueStrongest = tools->getLeagueById(m_leagueStrongestId);
    m_textCtrlStrongestLeagueName = new wxTextCtrl(this, wxID_ANY, leagueStrongest->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStrongestLeagueName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStrongestLeagueName->SetHint(wxT(""));
#endif

    flexGridSizer75->Add(m_textCtrlStrongestLeagueName, 0, wxALL, WXC_FROM_DIP(5));
    
    m_staticText79 = new wxStaticText(this, wxID_ANY, tools->translate("average"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer75->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(5));
    
    swprintf(buffer, 100, L"%.2f", m_leagueStrongestValue);
    m_textCtrlStrongestLeagueAverage = new wxTextCtrl(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
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

    m_staticText57 = new wxStaticText(this, wxID_ANY, tools->translate("biggest"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer55->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(5));

    auto teamBiggestStadium = tools->getTeamById(m_teamBiggestStadiumId);
    m_textCtrlStadiumGreatestName = new wxTextCtrl(this, wxID_ANY, teamBiggestStadium->getStadium().getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumGreatestName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumGreatestName->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumGreatestName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumGreatestSize = new wxTextCtrl(this, wxID_ANY, std::to_string(m_teamBiggestStadiumValue), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumGreatestSize->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumGreatestSize->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumGreatestSize, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText63 = new wxStaticText(this, wxID_ANY, tools->translate("smallest"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer55->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(5));

    auto teamSmallestStadium = tools->getTeamById(m_teamSmallestStadiumId);
    m_textCtrlStadiumSmallestName = new wxTextCtrl(this, wxID_ANY, teamSmallestStadium->getStadium().getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumSmallestName->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumSmallestName->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumSmallestName, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumSmallestSize = new wxTextCtrl(this, wxID_ANY, std::to_string(m_teamSmallestStadiumValue), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumSmallestSize->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumSmallestSize->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumSmallestSize, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText69 = new wxStaticText(this, wxID_ANY, tools->translate("average"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer55->Add(m_staticText69, 0, wxALL, WXC_FROM_DIP(5));

    m_panel71 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer55->Add(m_panel71, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStadiumAverage = new wxTextCtrl(this, wxID_ANY, std::to_string(m_teamStadiumAverage), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlStadiumAverage->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStadiumAverage->SetHint(wxT(""));
#endif

    flexGridSizer55->Add(m_textCtrlStadiumAverage, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

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
    // connect events
    // button events
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogStatistics::OnOk), NULL, this);
}

DialogStatistics::~DialogStatistics()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogStatistics::OnOk), NULL, this);
}

void DialogStatistics::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogStatistics::initializePlayerList(wxListCtrl* control)
{
    struct Item {
        std::string country;
        std::string league;
        int value;
    };

    std::vector<Item> leagues;
    int total = 0;
    int totalNonEU = 0;
    int totalEU = 0;
    auto playableCountries = tools->GetPlayableCountries();

    int teamPlayersAverageSum = 0;
    int teamPlayersAverageCount = 0;
    int oldestPlayerAge = 0;

    float teamStrengthAverageSum = 0.0f;
    int teamStrengthAverageCount = 0;

    long stadiumAverageSum = 0;
    int stadiumAverageCount = 0;

    for (auto countryShortname : playableCountries)
    {
        auto countryId = tools->getCountryIdByShortname(countryShortname);
        auto leagueIds = tools->getLeagueIdsByCountryId(countryId);
        for (auto leagueId : leagueIds)
        {
            auto league = tools->getLeagueById(leagueId);

            float leagueStrengthAverageSum = 0.0f;
            int leagueStrengthAverageCount = 0;

            // sum players for this league
            int sum = 0;
            auto teamIds = tools->getTeamIdsByLeagueId(leagueId);
            for (auto teamId : teamIds)
            {
                float playerStrengthAverageSum = 0.0f;
                int playerStrengthAverageCount = 0;

                auto playerIds = tools->getPlayerIdsByTeamId(teamId);
                sum += playerIds.size();
                // most players
                if (playerIds.size() > m_teamMostPlayersValue)
                {
                    m_teamMostPlayersValue = playerIds.size();
                    m_teamMostPlayersId = teamId;
                }
                // least players
                if (playerIds.size() < m_teamLeastPlayersValue)
                {
                    m_teamLeastPlayersValue = playerIds.size();
                    m_teamLeastPlayersId = teamId;
                }
                // average players
                teamPlayersAverageSum += playerIds.size();
                ++teamPlayersAverageCount;
                for (auto playerId : playerIds)
                {
                    auto player = tools->getPlayerById(playerId);
                    auto nationId = tools->getNationIdByIndex(player->getNationalityFirst());
                    auto nation = tools->getNationById(nationId);
                    if (nation->getContinent() == Core::Continent::EUROPE)
                        ++totalEU;
                    else
                        ++totalNonEU;

                    if (player->getAge() > oldestPlayerAge)
                    {
                        oldestPlayerAge = player->getAge();
                        m_oldiePlayerId = playerId;
                        m_oldiePlayerTeamId = teamId;
                    }

                    playerStrengthAverageSum += player->getSkill();
                    ++playerStrengthAverageCount;
                }// player

                float teamAverageStrength = playerStrengthAverageSum / playerStrengthAverageCount;
                if (teamAverageStrength > m_teamStrongestValue)
                {
                    m_teamStrongestValue = teamAverageStrength;
                    m_teamStrongestId = teamId;
                }
                if (teamAverageStrength < m_teamWeakestValue)
                {
                    m_teamWeakestValue = teamAverageStrength;
                    m_teamWeakestId = teamId;
                }
                teamStrengthAverageSum+= teamAverageStrength;
                ++teamStrengthAverageCount;

                leagueStrengthAverageSum += teamAverageStrength;
                ++leagueStrengthAverageCount;

                // stadium statistics
                auto team = tools->getTeamById(teamId);
                auto stadium = team->getStadium();
                int stadiumSize = stadium.getLeftStandSeatings() + stadium.getLeftStandStandPlaces() +
                                  stadium.getRightStandSeatings() + stadium.getRightStandStandPlaces() +
                                  stadium.getMainStandSeatings() + stadium.getMainStandStandPlaces() +
                                  stadium.getOppositeStandSeatings() + stadium.getOppositeStandStandPlaces();
                stadiumAverageSum += stadiumSize;
                ++stadiumAverageCount;
                if (stadiumSize > m_teamBiggestStadiumValue)
                {
                    m_teamBiggestStadiumValue = stadiumSize;
                    m_teamBiggestStadiumId = teamId;
                }
                if (stadiumSize < m_teamSmallestStadiumValue)
                {
                    m_teamSmallestStadiumValue = stadiumSize;
                    m_teamSmallestStadiumId = teamId;
                }
            }// team

            float leagueStrengthAverage = leagueStrengthAverageSum / leagueStrengthAverageCount;
            if (leagueStrengthAverage > m_leagueStrongestValue)
            {
                m_leagueStrongestValue = leagueStrengthAverage;
                m_leagueStrongestId = leagueId;
            }

            // add entry
            Item i;
            i.country = countryShortname;
            i.league = league->getName();
            i.value = sum;
            leagues.push_back(i);

            total += sum;
        }// league
    }

    m_teamStrengthAverage = teamStrengthAverageSum / teamStrengthAverageCount;
    m_teamStadiumAverage = stadiumAverageSum / stadiumAverageCount;

    auto countriesWithLeagues = tools->GetCountriesWithLeagues();
    for (auto countryShortname : countriesWithLeagues)
    {
        // if this country was already counted move to the next one
        if (std::find(playableCountries.begin(), playableCountries.end(), countryShortname) != playableCountries.end())
        {
            continue;
        }

        auto countryId = tools->getCountryIdByShortname(countryShortname);
        auto teamIds = tools->getTeamIdsByCountryId(countryId);

        // sum players for this league
        int sum = 0;
        for (auto teamId : teamIds)
        {
            auto playerIds = tools->getPlayerIdsByTeamId(teamId);
            sum += playerIds.size();
            for (auto playerId : playerIds)
            {
                auto player = tools->getPlayerById(playerId);
                auto nationId = tools->getNationIdByIndex(player->getNationalityFirst());
                auto nation = tools->getNationById(nationId);
                if (nation->getContinent() == Core::Continent::EUROPE)
                    ++totalEU;
                else
                    ++totalNonEU;
            }
        }
        total += sum;
    }

    m_teamPlayersAverage = teamPlayersAverageSum / teamPlayersAverageCount;

    // non EU
    Item i;
    std::wstring countryString = tools->translate("foreigncountries");
    i.country = std::string(countryString.begin(), countryString.end());
    i.league = "";
    i.value = totalNonEU;
    leagues.push_back(i);
    // EU
    countryString = tools->translate("euro");
    i.country = std::string(countryString.begin(), countryString.end());
    i.value = totalEU;
    leagues.push_back(i);
    // all
    countryString = tools->translate("total");
    i.country = std::string(countryString.begin(), countryString.end());
    i.value = total;
    leagues.push_back(i);

    control->Hide();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 140);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_RIGHT, 50);

    long index = 0;
    for (auto it : leagues)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, it.country + " " + it.league);
        control->SetItem(result, 1, std::to_string(it.value));
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work
        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(210, 350));
}

void DialogStatistics::initializeStrengthList(wxListCtrl* control)
{
    // loop over all players and add strength to list or update its counter
    std::map<short,int,std::less<short>> strengths;
    auto allPlayers = tools->getPlayerIds();
    for (auto playerId : allPlayers)
    {
        auto player = tools->getPlayerById(playerId);
        auto it = strengths.find(player->getSkill());
        if (it != strengths.end())
        {
            ++it->second;   // update counter
        }
        else
        {
            strengths.insert(std::pair<short, int>(player->getSkill(), 1));  // add new skill to list
        }
    }

    control->Hide();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 30);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_RIGHT, 50);

    long index = 0;
    for (auto it : strengths)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, std::to_string(it.first));
        control->SetItem(result, 1, std::to_string(it.second));
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work
        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(100, 200));
}

void DialogStatistics::initializePositionList(wxListCtrl* control)
{
    // loop over all players and add position to list or update its counter
    std::map<short, int, std::less<short>> positions;
    auto allPlayers = tools->getPlayerIds();
    for (auto playerId : allPlayers)
    {
        auto player = tools->getPlayerById(playerId);
        auto it = positions.find(player->getMainPosition());
        if (it != positions.end())
        {
            ++it->second;   // update counter
        }
        else
        {
            positions.insert(std::pair<short, int>(player->getMainPosition(), 1));  // add new skill to list
        }
    }

    control->Hide();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 30);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_RIGHT, 50);

    long index = 0;
    for (auto it : positions)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, tools->positionToString(it.first));
        control->SetItem(result, 1, std::to_string(it.second));
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work
        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(100, 200));
}