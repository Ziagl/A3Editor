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

            flexGridSizer51->Add(choiceTeam, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

            m_staticText = new wxStaticText(this, wxID_ANY, tools->translate("country"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

            flexGridSizer51->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));

            wxArrayString m_choiceCountry1Arr;
            wxChoice* choiceCountry = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry1Arr, 0);

            flexGridSizer51->Add(choiceCountry, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

            m_choiceTeam.push_back(choiceTeam);
            m_choiceCountry.push_back(choiceCountry);
        }
    }

    wxBoxSizer* boxSizer23 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer23->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer23->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnAbort), NULL, this);
    for(auto button : m_buttonGroup)
        this->Connect(button->GetId(), wxEVT_TOGGLEBUTTON, wxCommandEventHandler(DialogCompetition::OnGroup), NULL, this);

    // first toggle button is active
    m_buttonGroup.at(0)->SetValue(true);
    loadGroupData();
}

DialogCompetition::~DialogCompetition()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnAbort), NULL, this);
    for (auto button : m_buttonGroup)
        this->Disconnect(button->GetId(), wxEVT_TOGGLEBUTTON, wxCommandEventHandler(DialogCompetition::OnGroup), NULL, this);
}

void DialogCompetition::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogCompetition::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogCompetition::OnGroup(wxCommandEvent& event)
{
    wxToggleButton * button = static_cast<wxToggleButton*>(FindWindowById(event.GetId()));
    m_selectedGroup = std::stoi(std::string(button->GetLabel().c_str())) - 1;
    for (int i = 0; i < m_buttonGroup.size(); ++i)
    {
        if (i != m_selectedGroup)
            m_buttonGroup.at(i)->SetValue(false);
    }
    loadGroupData();
}

/*
 * initialize choice fields for current selected group
 */
void DialogCompetition::loadGroupData()
{
    if (m_type == CompetitionType::COMP_CLEAGUE)
    {
        m_countries = tools->getCLeagueCountries();
        m_teams = m_competition->getChampionsLeague().at(m_selectedGroup);
        for (int i = 0; i < m_choiceTeam.size(); ++i)
        {
            // add all countries to choice control
            m_choiceCountry.at(i)->Clear();
            wxArrayString choices;
            for (auto country : m_countries)
                choices.Add(tools->translate(country));
            m_choiceCountry.at(i)->Append(choices);

            m_choiceCountry.at(i)->SetSelection(std::get<1>(m_teams.at(i)));


        }
    }
}