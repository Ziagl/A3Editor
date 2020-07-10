#include "DialogCompetition.h"

DialogCompetition::DialogCompetition(wxWindow* parent, 
    Toolset* const tools, 
    CompetitionType type,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_type(type)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    m_competition = tools->getCompetition();
    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        m_teams = m_competition->getChampionsLeague();
    }
    else if (m_type == CompetitionType::COMP_EM)
    {
        m_teams = m_competition->getEM();
    }

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("selectGroup")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer31 = new wxBoxSizer(wxVERTICAL);

    staticBoxSizer19->Add(boxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        for (int i = 0; i < 8; ++i)
        {
            wxToggleButton* button = new wxToggleButton(this, wxID_ANY, std::to_string(i + 1), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
            boxSizer31->Add(button, 0, wxALL | wxEXPAND, WXC_FROM_DIP(3));

            m_buttonGroup.push_back(button);
        }
    }
    else if (m_type == CompetitionType::COMP_EM)
    {
        for (int i = 0; i < 4; ++i)
        {
            wxToggleButton* button = new wxToggleButton(this, wxID_ANY, tools->translate("group") + " " + std::to_string(i + 1), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
            boxSizer31->Add(button, 0, wxALL | wxEXPAND, WXC_FROM_DIP(3));

            m_buttonGroup.push_back(button);
        }
    }

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("menuTeams")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer25, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer51 = new wxFlexGridSizer(8, 2, 0, 0);
    flexGridSizer51->SetFlexibleDirection(wxBOTH);
    flexGridSizer51->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer25->Add(flexGridSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        for (int i = 0; i < 4; ++i)
        {
            wchar_t buffer[100];
            swprintf(buffer, 100, tools->translate("enumerateClub").c_str(), tools->translate("enumerator" + std::to_string(i + 1)).c_str());
            wxStaticText* m_staticText = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

            flexGridSizer51->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));

            wxArrayString m_choiceTeam1Arr;
            wxChoice* choiceTeam = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceTeam1Arr, 0);
            choiceTeam->SetLabel("choiceTeam" + std::to_string(i));

            flexGridSizer51->Add(choiceTeam, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

            m_staticText = new wxStaticText(this, wxID_ANY, tools->translate("country"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

            flexGridSizer51->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));

            wxArrayString m_choiceCountry1Arr;
            wxChoice* choiceCountry = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry1Arr, 0);
            choiceCountry->SetLabel("choiceCountry" + std::to_string(i));

            flexGridSizer51->Add(choiceCountry, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

            m_choiceTeam.push_back(choiceTeam);
            m_choiceCountry.push_back(choiceCountry);
        }
    }
    else if (m_type == CompetitionType::COMP_EM)
    {
        for (int i = 0; i < 4; ++i)
        {
            wchar_t buffer[100];
            swprintf(buffer, 100, tools->translate("enumerateCountry").c_str(), tools->translate("enumeratorCountry" + std::to_string(i + 1)).c_str());
            wxStaticText* m_staticText = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

            flexGridSizer51->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));

            wxArrayString m_choiceCountry1Arr;
            wxChoice* choiceCountry = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry1Arr, 0);
            choiceCountry->SetLabel("choiceCountry" + std::to_string(i));

            flexGridSizer51->Add(choiceCountry, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

            m_staticText = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
            flexGridSizer51->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));
            m_staticText = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
            flexGridSizer51->Add(m_staticText, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

            m_choiceCountry.push_back(choiceCountry);
        }
    }

    wxBoxSizer* boxSizer23 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer23->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer23->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    // connect events
    // button events
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnAbort), NULL, this);
    for(auto button : m_buttonGroup)
        this->Connect(button->GetId(), wxEVT_TOGGLEBUTTON, wxCommandEventHandler(DialogCompetition::OnGroup), NULL, this);
    // choice event
    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        for (auto choice : m_choiceCountry)
            this->Connect(choice->GetId(), wxEVT_CHOICE, wxCommandEventHandler(DialogCompetition::OnCountry), NULL, this);
    }

    // first toggle button is active
    m_buttonGroup.at(0)->SetValue(true);
    loadGroupData();

    SetName(wxT("DialogCompetition"));
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

DialogCompetition::~DialogCompetition()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnAbort), NULL, this);
    for (auto button : m_buttonGroup)
        this->Disconnect(button->GetId(), wxEVT_TOGGLEBUTTON, wxCommandEventHandler(DialogCompetition::OnGroup), NULL, this);
    // choice event
    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        for (auto choice : m_choiceCountry)
            this->Disconnect(choice->GetId(), wxEVT_CHOICE, wxCommandEventHandler(DialogCompetition::OnCountry), NULL, this);
    }
}

void DialogCompetition::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogCompetition::OnOk(wxCommandEvent& event)
{
    saveGroupData();
    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        m_competition->setChampionsLeague(m_teams);
    }
    else if (m_type == CompetitionType::COMP_EM)
    {
        m_competition->setEM(m_teams);
    }
    wxUnusedVar(event);
    Close();
}

void DialogCompetition::OnGroup(wxCommandEvent& event)
{
    // save last group settings
    saveGroupData();
    // load next selected group
    wxToggleButton* button = static_cast<wxToggleButton*>(FindWindowById(event.GetId()));
    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        m_selectedGroup = std::stoi(std::string(button->GetLabel().c_str())) - 1;
    }
    else if (m_type == CompetitionType::COMP_EM)
    {
        std::string label = std::string(button->GetLabel().c_str());
        m_selectedGroup = std::stoi(label.substr(std::string("group").size() + 1, label.size())) - 1;
    }
    for (int i = 0; i < m_buttonGroup.size(); ++i)
    {
        if (i != m_selectedGroup)
            m_buttonGroup.at(i)->SetValue(false);
    }
    loadGroupData();
}

void DialogCompetition::OnCountry(wxCommandEvent& event)
{
    wxChoice* choice = static_cast<wxChoice*>(FindWindowById(event.GetId()));
    std::string label = std::string(choice->GetLabel().c_str());
    int choiceIndex = std::stoi(label.substr(std::string("choiceCountry").size(), label.size()));
    int selectedIndex = event.GetSelection();
    m_countries = tools->getCLeagueCountries();
    std::string shortname = m_countries.at(event.GetSelection());
    auto countryId = tools->getCountryIdByShortname(shortname);
    auto nationId = tools->getNationIdByCountryId(countryId);
    auto nation = tools->getNationById(nationId);
    updateTeamList(choiceIndex, nation->getCountryId(), 0);
}

/*
 * initialize choice fields for current selected group
 */
void DialogCompetition::loadGroupData()
{
    if (m_type == CompetitionType::COMP_CLEAGUE || m_type == CompetitionType::COMP_EM)
    {
        m_countries = tools->getCLeagueCountries();
        // loop all country choice fileds = team choice fileds (same index)
        for (int i = 0; i < m_choiceCountry.size(); ++i)
        {
            // add all countries to choice control
            m_choiceCountry.at(i)->Clear();
            wxArrayString choices;
            for (auto country : m_countries)
                choices.Add(tools->translate(country));
            m_choiceCountry.at(i)->Append(choices);

            auto countryIndex = std::get<0>(m_teams.at(m_selectedGroup).at(i));
            m_choiceCountry.at(i)->SetSelection(getCountryListIndexByCountryIndex(countryIndex));

            if (m_type == CompetitionType::COMP_CLEAGUE)
            {
                updateTeamList(i, countryIndex, std::get<1>(m_teams.at(m_selectedGroup).at(i)));
            }
        }
    }
}

/*
 * save current selected group
 */
void DialogCompetition::saveGroupData()
{
    // loop all country choice fileds = team choice fileds (same index)
    for (int i = 0; i < m_choiceCountry.size(); ++i)
    {
        short c = 0, t = 0;
        // find country value
        auto countryIndex = m_choiceCountry.at(i)->GetSelection();
        auto shortname = m_countries.at(countryIndex);
        auto countryId = tools->getCountryIdByShortname(shortname);
        if (countryId == 0)  // skip not loaded countries for debug mode
            continue;
        auto nationId = tools->getNationIdByCountryId(countryId);
        auto nation = tools->getNationById(nationId);
        c = nation->getCountryId();
        if (m_type == CompetitionType::COMP_CLEAGUE)
        {
            // find team value
            auto teamIndex = m_choiceTeam.at(i)->GetSelection();
            auto teamName = m_choiceTeam.at(i)->GetString(teamIndex);
            auto teamIds = tools->getTeamIdsByCountryId(countryId);
            for (auto teamId : teamIds)
            {
                auto team = tools->getTeamById(teamId);
                if (team->getName() == teamName)
                {
                    t = team->getTeamId();
                    break;
                }
            }
        }
        // set both values
        m_teams.at(m_selectedGroup).at(i) = std::make_tuple(c, t);
    }
}

/*
 * updates one team choice control with data based on selected country and selected team
 */
void DialogCompetition::updateTeamList(int controlIndex, short countryIndex, short teamId)
{
    // get control and remove all elements
    auto control = m_choiceTeam.at(controlIndex);
    control->Clear();

    // get all teams of given country
    auto nationId = tools->getNationIdByIndex(countryIndex);
    auto nation = tools->getNationById(nationId);
    auto countryId = tools->getCountryIdByShortname(nation->getShortname());
    auto country = tools->getCountryById(countryId);

    wxArrayString teams;
    int selectedTeam = 0;
    // get teams for playable countries from first league
    auto playableCountries = tools->GetPlayableCountries();
    if (std::find(playableCountries.begin(), playableCountries.end(), nation->getShortname()) != playableCountries.end())
    {
        auto leagueIds = tools->getLeagueIdsByCountryId(countryId);
        
        // get highest league
        for (auto leagueId : leagueIds)
        {
            auto league = tools->getLeagueById(leagueId);
            if (league->getHierarchy() == 1)
            {
                auto teamIds = tools->getTeamIdsByLeagueId(leagueId);
                for (auto id : teamIds)
                {
                    auto team = tools->getTeamById(id);
                    if (team->getTeamId() == teamId)
                        selectedTeam = teams.size();
                    teams.Add(team->getName());
                }
                break;
            }
        }
    }
    // get teams for non playable countries of all known teams
    else
    {
        auto teamIds = tools->getTeamIdsByCountryId(countryId);
        for (auto id : teamIds)
        {
            auto team = tools->getTeamById(id);
            if (team->getTeamId() == teamId)
                selectedTeam = teams.size();
            teams.Add(team->getName());
        }
    }
    control->Append(teams);
    // select team
    control->SetSelection(selectedTeam);
}

/*
 * translates country index from data source to index of coice list of countries
 */
int DialogCompetition::getCountryListIndexByCountryIndex(short countryIndex)
{
    auto nationId = tools->getNationIdByIndex(countryIndex);
    auto nation = tools->getNationById(nationId);
    for (int i = 0; i < m_countries.size(); ++i)
        if (m_countries.at(i) == nation->getShortname())
            return i;
    return 0;
}