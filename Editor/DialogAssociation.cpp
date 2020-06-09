#include "DialogAssociation.h"
#include <iomanip>

DialogAssociation::DialogAssociation(wxWindow* parent, 
    Toolset* const tools,
    std::string const selectedCountry,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    // get country and trainer based on given strings
    auto countryId = tools->getCountryIdByShortname(selectedCountry);
    country = tools->getCountryById(countryId);
    nationalTrainer = country->getNationalTrainer();
    president = country->getPresident();

    // convert birthday string to chrono for nationalTrainer
    std::tm tmNationalTrainer = {};
    std::stringstream ss(nationalTrainer.getBirthday());
    ss >> std::get_time(&tmNationalTrainer, "%d.%m.%Y");

    // convert birthday string to chrono for president
    std::tm tmPresident = {};
    std::stringstream ss1(president.getBirthday());
    ss1 >> std::get_time(&tmPresident, "%d.%m.%Y");

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("nationaltrainer")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer39 = new wxFlexGridSizer(5, 2, 0, 0);
    flexGridSizer39->SetFlexibleDirection(wxBOTH);
    flexGridSizer39->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer39->AddGrowableCol(1);

    staticBoxSizer19->Add(flexGridSizer39, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText41 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText41, 0, wxALL, WXC_FROM_DIP(5));

    m_textNameNationalTrainer = new wxTextCtrl(this, wxID_ANY, nationalTrainer.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textNameNationalTrainer->SetHint(wxT(""));
#endif

    flexGridSizer39->Add(m_textNameNationalTrainer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText45 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(5));

    m_textFirstnameNationalTrainer = new wxTextCtrl(this, wxID_ANY, nationalTrainer.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstnameNationalTrainer->SetHint(wxT(""));
#endif

    flexGridSizer39->Add(m_textFirstnameNationalTrainer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText49 = new wxStaticText(this, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText49, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer51 = new wxFlexGridSizer(0, 6, 0, 0);
    flexGridSizer51->SetFlexibleDirection(wxBOTH);
    flexGridSizer51->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer39->Add(flexGridSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextDayNationalTrainer = new wxStaticText(this, wxID_ANY, std::to_string(tmNationalTrainer.tm_mday), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticTextDayNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonDayNationalTrainer = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonDayNationalTrainer->SetRange(1, 31);
    m_spinButtonDayNationalTrainer->SetValue(tmNationalTrainer.tm_mday);

    flexGridSizer51->Add(m_spinButtonDayNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextMonthNationalTrainer = new wxStaticText(this, wxID_ANY, std::to_string(tmNationalTrainer.tm_mon + 1), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticTextMonthNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonMonthNationalTrainer = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonMonthNationalTrainer->SetRange(1, 12);
    m_spinButtonMonthNationalTrainer->SetValue(tmNationalTrainer.tm_mon + 1);

    flexGridSizer51->Add(m_spinButtonMonthNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextYearNationalTrainer = new wxStaticText(this, wxID_ANY, std::to_string(tmNationalTrainer.tm_year + 1900), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticTextYearNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonYearNationalTrainer = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYearNationalTrainer->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonYearNationalTrainer->SetValue(tmNationalTrainer.tm_year + 1900);

    flexGridSizer51->Add(m_spinButtonYearNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText99 = new wxStaticText(this, wxID_ANY, tools->translate("competence"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText99, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer101 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer101->SetFlexibleDirection(wxBOTH);
    flexGridSizer101->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer101->AddGrowableCol(1);

    flexGridSizer39->Add(flexGridSizer101, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextCompetence = new wxStaticText(this, wxID_ANY, std::to_string(nationalTrainer.getCompetence()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer101->Add(m_staticTextCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonCompetence = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonCompetence->SetRange(0, tools->getMaxSkillPerson());
    m_spinButtonCompetence->SetValue(nationalTrainer.getCompetence());

    flexGridSizer101->Add(m_spinButtonCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextAgeNationalTrainer = new wxStaticText(this, wxID_ANY, tools->translate("age") + " " + std::to_string(nationalTrainer.getAge()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer101->Add(m_staticTextAgeNationalTrainer, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText65 = new wxStaticText(this, wxID_ANY, tools->translate("reputation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText65, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString choiceArray;
    for (int i = 0; i < 7; ++i)
        choiceArray.Add(tools->translate("trainertype" + std::to_string(i)));
    m_choiceReputation = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), choiceArray, 0);
    m_choiceReputation->SetSelection(nationalTrainer.getReputation());

    flexGridSizer39->Add(m_choiceReputation, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer21 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("associationpresident")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer69 = new wxFlexGridSizer(4, 2, 0, 0);
    flexGridSizer69->SetFlexibleDirection(wxBOTH);
    flexGridSizer69->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer69->AddGrowableCol(1);

    staticBoxSizer21->Add(flexGridSizer69, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText71 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText71, 0, wxALL, WXC_FROM_DIP(5));

    m_textNamePresident = new wxTextCtrl(this, wxID_ANY, president.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textNamePresident->SetHint(wxT(""));
#endif

    flexGridSizer69->Add(m_textNamePresident, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText75 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText75, 0, wxALL, WXC_FROM_DIP(5));

    m_textFirstnamePresident = new wxTextCtrl(this, wxID_ANY, president.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstnamePresident->SetHint(wxT(""));
#endif

    flexGridSizer69->Add(m_textFirstnamePresident, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText79 = new wxStaticText(this, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer81 = new wxFlexGridSizer(0, 6, 0, 0);
    flexGridSizer81->SetFlexibleDirection(wxBOTH);
    flexGridSizer81->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer69->Add(flexGridSizer81, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextDayPresident = new wxStaticText(this, wxID_ANY, std::to_string(tmPresident.tm_mday), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer81->Add(m_staticTextDayPresident, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonDayPresident = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonDayPresident->SetRange(1, 31);
    m_spinButtonDayPresident->SetValue(tmPresident.tm_mday);

    flexGridSizer81->Add(m_spinButtonDayPresident, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextMonthPresident = new wxStaticText(this, wxID_ANY, std::to_string(tmPresident.tm_mon + 1), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer81->Add(m_staticTextMonthPresident, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonMonthPresident = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonMonthPresident->SetRange(1, 12);
    m_spinButtonMonthPresident->SetValue(tmPresident.tm_mon + 1);

    flexGridSizer81->Add(m_spinButtonMonthPresident, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextYearPresident = new wxStaticText(this, wxID_ANY, std::to_string(tmPresident.tm_year + 1900), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer81->Add(m_staticTextYearPresident, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonYearPresident = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYearPresident->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonYearPresident->SetValue(tmPresident.tm_year + 1900);

    flexGridSizer81->Add(m_spinButtonYearPresident, 0, wxALL, WXC_FROM_DIP(5));

    m_panel97 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer69->Add(m_panel97, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextAgePresident = new wxStaticText(this, wxID_ANY, tools->translate("age") + " " + std::to_string(tools->getStartingYear() - (tmPresident.tm_year + 1900)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticTextAgePresident, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer23 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer23->SetFlexibleDirection(wxBOTH);
    flexGridSizer23->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("association")), wxVERTICAL);

    flexGridSizer23->Add(staticBoxSizer25, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer33 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer25->Add(boxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText35 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_staticText35, 0, wxALL, WXC_FROM_DIP(5));

    m_textAssociation = new wxTextCtrl(this, wxID_ANY, country->getAssociationName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textAssociation->SetHint(wxT(""));
#endif

    boxSizer33->Add(m_textAssociation, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer27 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer23->Add(boxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer27->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer27->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAssociation::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAssociation::OnAbort), NULL, this);
    // list events
    this->Connect(m_choiceReputation->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxListEventHandler(DialogAssociation::OnChangeReputation), NULL, this);
    // text events
    this->Connect(m_textNameNationalTrainer->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextNameNationalTrainer), NULL, this);
    this->Connect(m_textFirstnameNationalTrainer->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextFirstnameNationalTrainer), NULL, this);
    this->Connect(m_textNamePresident->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextNamePresident), NULL, this);
    this->Connect(m_textFirstnamePresident->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextFirstnamePresident), NULL, this);
    this->Connect(m_textAssociation->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextAssociation), NULL, this);
    // spin events
    this->Connect(m_spinButtonDayNationalTrainer->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnDayNationalTrainer), NULL, this);
    this->Connect(m_spinButtonMonthNationalTrainer->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnMonthNationalTrainer), NULL, this);
    this->Connect(m_spinButtonYearNationalTrainer->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnYearNationalTrainer), NULL, this);
    this->Connect(m_spinButtonDayPresident->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnDayPresident), NULL, this);
    this->Connect(m_spinButtonMonthPresident->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnMonthPresident), NULL, this);
    this->Connect(m_spinButtonYearPresident->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnYearPresident), NULL, this);
    this->Connect(m_spinButtonCompetence->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnCompetence), NULL, this);
}

DialogAssociation::~DialogAssociation()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAssociation::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAssociation::OnAbort), NULL, this);
    // list events
    this->Disconnect(m_choiceReputation->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxListEventHandler(DialogAssociation::OnChangeReputation), NULL, this);
    // text events
    this->Disconnect(m_textNameNationalTrainer->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextNameNationalTrainer), NULL, this);
    this->Disconnect(m_textFirstnameNationalTrainer->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextFirstnameNationalTrainer), NULL, this);
    this->Disconnect(m_textNamePresident->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextNamePresident), NULL, this);
    this->Disconnect(m_textFirstnamePresident->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextFirstnamePresident), NULL, this);
    this->Disconnect(m_textAssociation->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogAssociation::OnTextAssociation), NULL, this);
    // spin events
    this->Disconnect(m_spinButtonDayNationalTrainer->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnDayNationalTrainer), NULL, this);
    this->Disconnect(m_spinButtonMonthNationalTrainer->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnMonthNationalTrainer), NULL, this);
    this->Disconnect(m_spinButtonYearNationalTrainer->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnYearNationalTrainer), NULL, this);
    this->Disconnect(m_spinButtonDayPresident->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnDayPresident), NULL, this);
    this->Disconnect(m_spinButtonMonthPresident->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnMonthPresident), NULL, this);
    this->Disconnect(m_spinButtonYearPresident->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnYearPresident), NULL, this);
    this->Disconnect(m_spinButtonCompetence->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogAssociation::OnCompetence), NULL, this);
}

void DialogAssociation::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogAssociation::OnOk(wxCommandEvent& event)
{
    country->setNationalTrainer(nationalTrainer);
    country->setPresident(president);
    wxUnusedVar(event);
    Close();
}

void DialogAssociation::OnTextNameNationalTrainer(wxCommandEvent& event)
{
    nationalTrainer.setLastname(std::string(m_textNameNationalTrainer->GetValue().mb_str()));
}

void DialogAssociation::OnTextFirstnameNationalTrainer(wxCommandEvent& event)
{
    nationalTrainer.setFirstname(std::string(m_textFirstnameNationalTrainer->GetValue().mb_str()));
}

void DialogAssociation::OnChangeReputation(wxListEvent& event)
{
    nationalTrainer.setReputation(event.m_itemIndex);
}

void DialogAssociation::OnDayNationalTrainer(wxSpinEvent& event)
{
    m_staticTextDayNationalTrainer->SetLabel(std::to_string(m_spinButtonDayNationalTrainer->GetValue()).c_str());
    updateBirthdayNationalTrainer();
}

void DialogAssociation::OnMonthNationalTrainer(wxSpinEvent& event)
{
    m_staticTextMonthNationalTrainer->SetLabel(std::to_string(m_spinButtonMonthNationalTrainer->GetValue()).c_str());
    updateBirthdayNationalTrainer();
}

void DialogAssociation::OnYearNationalTrainer(wxSpinEvent& event)
{
    m_staticTextYearNationalTrainer->SetLabel(std::to_string(m_spinButtonYearNationalTrainer->GetValue()));
    m_staticTextAgeNationalTrainer->SetLabel(tools->translate("age") + " " + std::to_string(tools->getStartingYear() - m_spinButtonYearNationalTrainer->GetValue()));
    nationalTrainer.setAge(tools->getStartingYear() - m_spinButtonYearNationalTrainer->GetValue());
    updateBirthdayNationalTrainer();
}

void DialogAssociation::OnCompetence(wxSpinEvent& event)
{
    m_staticTextCompetence->SetLabel(std::to_string(m_spinButtonCompetence->GetValue()).c_str());
    nationalTrainer.setCompetence(m_spinButtonCompetence->GetValue());
}

void DialogAssociation::OnTextNamePresident(wxCommandEvent& event)
{
    president.setLastname(std::string(m_textNamePresident->GetValue().mb_str()));
}

void DialogAssociation::OnTextFirstnamePresident(wxCommandEvent& event)
{
    president.setFirstname(std::string(m_textFirstnamePresident->GetValue().mb_str()));
}

void DialogAssociation::OnDayPresident(wxSpinEvent& event)
{
    m_staticTextDayPresident->SetLabel(std::to_string(m_spinButtonDayPresident->GetValue()).c_str());
    updateBirthdayPresident();
}

void DialogAssociation::OnMonthPresident(wxSpinEvent& event)
{
    m_staticTextMonthPresident->SetLabel(std::to_string(m_spinButtonMonthPresident->GetValue()).c_str());
    updateBirthdayPresident();
}

void DialogAssociation::OnYearPresident(wxSpinEvent& event)
{
    m_staticTextYearPresident->SetLabel(std::to_string(m_spinButtonYearPresident->GetValue()));
    m_staticTextAgePresident->SetLabel(tools->translate("age") + " " + std::to_string(tools->getStartingYear() - m_spinButtonYearPresident->GetValue()));
    updateBirthdayPresident();
}

void DialogAssociation::OnTextAssociation(wxCommandEvent& event)
{
    country->setAssociationName(std::string(m_textAssociation->GetValue().mb_str()));
}

void DialogAssociation::updateBirthdayNationalTrainer()
{
    nationalTrainer.setBirthday(
        std::to_string(m_spinButtonDayNationalTrainer->GetValue()) + "." +
        std::to_string(m_spinButtonMonthNationalTrainer->GetValue()) + "." +
        std::to_string(m_spinButtonYearNationalTrainer->GetValue())
    );
}

void DialogAssociation::updateBirthdayPresident()
{
    president.setBirthday(
        std::to_string(m_spinButtonDayPresident->GetValue()) + "." +
        std::to_string(m_spinButtonMonthPresident->GetValue()) + "." +
        std::to_string(m_spinButtonYearPresident->GetValue())
    );
}