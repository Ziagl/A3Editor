#include "DialogReferee.h"
#include <iomanip>

DialogReferee::DialogReferee(wxWindow* parent,
    Toolset* const tools,
    std::string selectedCountry,
    Core::Referee& referee,
    short type,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), type(type), m_referee(referee)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(selectedCountry);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("changeReferee")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer18 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer18->SetFlexibleDirection(wxBOTH);
    flexGridSizer18->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer19->Add(flexGridSizer18, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    wxGridSizer* gridSizer27 = new wxGridSizer(4, 2, 0, 0);

    flexGridSizer18->Add(gridSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticText29 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer27->Add(m_staticText29, 0, wxALL, WXC_FROM_DIP(5));

    m_textName = new wxTextCtrl(this, wxID_ANY, m_referee.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textName->SetHint(wxT(""));
#endif

    gridSizer27->Add(m_textName, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText33 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer27->Add(m_staticText33, 0, wxALL, WXC_FROM_DIP(5));

    m_textFirstname = new wxTextCtrl(this, wxID_ANY, m_referee.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstname->SetHint(wxT(""));
#endif

    gridSizer27->Add(m_textFirstname, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer41 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer41->SetFlexibleDirection(wxBOTH);
    flexGridSizer41->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    gridSizer27->Add(flexGridSizer41, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText61 = new wxStaticText(this, wxID_ANY, tools->translate("competence"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer41->Add(m_staticText61, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextCompetence = new wxStaticText(this, wxID_ANY, std::to_string(m_referee.getCompetence()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer41->Add(m_staticTextCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonCompetence = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonCompetence->SetRange(0, 10);
    m_spinButtonCompetence->SetValue(m_referee.getCompetence());

    flexGridSizer41->Add(m_spinButtonCompetence, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer43 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer43->SetFlexibleDirection(wxBOTH);
    flexGridSizer43->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    gridSizer27->Add(flexGridSizer43, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText67 = new wxStaticText(this, wxID_ANY, tools->translate("severity"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer43->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextHardness = new wxStaticText(this, wxID_ANY, std::to_string(m_referee.getHardness()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer43->Add(m_staticTextHardness, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonHardness = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonHardness->SetRange(0, 10);
    m_spinButtonHardness->SetValue(m_referee.getHardness());

    flexGridSizer43->Add(m_spinButtonHardness, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText45 = new wxStaticText(this, wxID_ANY, type==PersonType::INTERNATIONALREFEREE?tools->translate("nationality"):tools->translate("unpopularclub"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer27->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString choiceArray;
    if (type == PersonType::REFEREE)
    {
        choiceArray.Add(tools->translate("none"));
        auto teamIds = tools->getTeamIdsByCountryId(countryId);
        for (auto teamId : teamIds)
        {
            auto team = tools->getTeamById(teamId);
            choiceArray.Add(team->getName());
        }
    }
    else if (type == PersonType::INTERNATIONALREFEREE)
    {
        auto nationIds = tools->getNationIds();
        for (auto nationId : nationIds)
        {
            auto nation = tools->getNationById(nationId);
            choiceArray.Add(nation->getName());
        }
    }
    
    m_teamChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), choiceArray, 0);
    m_teamChoice->SetSelection(referee.getUnpopularTeamNationality());

    gridSizer27->Add(m_teamChoice, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer49 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("refereecharacteristics")), wxVERTICAL);

    flexGridSizer18->Add(staticBoxSizer49, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_checkBoxHomeReferee = new wxCheckBox(this, wxID_ANY, tools->translate("homereferee"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxHomeReferee->SetValue(referee.getHomeReferee());

    staticBoxSizer49->Add(m_checkBoxHomeReferee, 0, wxALL, WXC_FROM_DIP(1));

    m_checkBoxGuestReferee = new wxCheckBox(this, wxID_ANY, tools->translate("guestreferee"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxGuestReferee->SetValue(referee.getGuestReferee());

    staticBoxSizer49->Add(m_checkBoxGuestReferee, 0, wxALL, WXC_FROM_DIP(1));

    m_checkBoxHatesTimeGame = new wxCheckBox(this, wxID_ANY, tools->translate("hatestimegame"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxHatesTimeGame->SetValue(referee.getHatesTimeGame());

    staticBoxSizer49->Add(m_checkBoxHatesTimeGame, 0, wxALL, WXC_FROM_DIP(1));

    m_checkBoxHatesGripe = new wxCheckBox(this, wxID_ANY, tools->translate("hatesgripe"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxHatesGripe->SetValue(referee.getHatesGripe());

    staticBoxSizer49->Add(m_checkBoxHatesGripe, 0, wxALL, WXC_FROM_DIP(1));

    m_checkBoxHatesCoaching = new wxCheckBox(this, wxID_ANY, tools->translate("hatescoaching"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxHatesCoaching->SetValue(referee.getHatesCoaching());

    staticBoxSizer49->Add(m_checkBoxHatesCoaching, 0, wxALL, WXC_FROM_DIP(1));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogReferee::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogReferee::OnAbort), NULL, this);
    // spin events
    this->Connect(m_spinButtonCompetence->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogReferee::OnCompetence), NULL, this);
    this->Connect(m_spinButtonHardness->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogReferee::OnHardness), NULL, this);
}

DialogReferee::~DialogReferee()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogReferee::OnAbort), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogReferee::OnOk), NULL, this);
    // spin events
    this->Disconnect(m_spinButtonCompetence->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogReferee::OnCompetence), NULL, this);
    this->Disconnect(m_spinButtonHardness->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogReferee::OnHardness), NULL, this);
}

void DialogReferee::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogReferee::OnOk(wxCommandEvent& event)
{
    // update edited trainer object for country
    m_referee.setHomeReferee(m_checkBoxHomeReferee->GetValue());
    m_referee.setGuestReferee(m_checkBoxGuestReferee->GetValue());
    m_referee.setHatesTimeGame(m_checkBoxHatesTimeGame->GetValue());
    m_referee.setHatesGripe(m_checkBoxHatesGripe->GetValue());
    m_referee.setHatesCoaching(m_checkBoxHatesCoaching->GetValue());
    m_referee.setFirstname(std::string(m_textFirstname->GetValue().mb_str()));
    m_referee.setLastname(std::string(m_textName->GetValue().mb_str()));
    m_referee.setUnpopularTeamNationality(m_teamChoice->GetSelection());
    m_referee.setCompetence(m_spinButtonCompetence->GetValue());
    m_referee.setHardness(m_spinButtonHardness->GetValue());
    wxUnusedVar(event);
    Close();
}

void DialogReferee::OnCompetence(wxSpinEvent& event)
{
    m_staticTextCompetence->SetLabel(std::to_string(m_spinButtonCompetence->GetValue()).c_str());
}

void DialogReferee::OnHardness(wxSpinEvent& event)
{
    m_staticTextHardness->SetLabel(std::to_string(m_spinButtonHardness->GetValue()).c_str());
}
