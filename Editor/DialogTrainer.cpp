#include "DialogTrainer.h"
#include <iomanip>

DialogTrainer::DialogTrainer(wxWindow* parent, 
    Toolset* const tools, 
    std::string selectedCountry, 
    std::string selectedTrainer,
    short type,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), trainerIndex(0), type(type)
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
    auto trainers = type==TrainerType::COTRAINER?country->getCoTrainer():country->getGoalKeeperTrainer();
    for (auto t : trainers)
    {
        if (t.getLastname() + ", " + t.getFirstname() == selectedTrainer)
        {
            trainer = t;
            break; // break outer for loop, trainer was found
        }
        ++trainerIndex;
    }
    // convert birthday string to chrono
    std::tm tm = {};
    std::stringstream ss(trainer.getBirthday());
    ss >> std::get_time(&tm, "%d.%m.%Y");

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("changeTrainer")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    wxGridSizer* gridSizer87 = new wxGridSizer(5, 2, 0, 0);

    staticBoxSizer19->Add(gridSizer87, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticText31 = new wxStaticText(this, wxID_ANY, tools->translate("name") , wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText31, 0, wxALL, WXC_FROM_DIP(5));

    m_textFirstname = new wxTextCtrl(this, wxID_ANY, trainer.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstname->SetHint(wxT(""));
#endif

    gridSizer87->Add(m_textFirstname, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText37 = new wxStaticText(this, wxID_ANY, tools->translate("firstname") , wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText37, 0, wxALL, WXC_FROM_DIP(5));

    m_textName = new wxTextCtrl(this, wxID_ANY, trainer.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textName->SetHint(wxT(""));
#endif

    gridSizer87->Add(m_textName, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText51 = new wxStaticText(this, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText51, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer73 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer87->Add(boxSizer73, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticTextDay = new wxStaticText(this, wxID_ANY, std::to_string(tm.tm_mday), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer73->Add(m_staticTextDay, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonDay = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonDay->SetRange(1, 31);
    m_spinButtonDay->SetValue(tm.tm_mday);

    boxSizer73->Add(m_spinButtonDay, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextMonth = new wxStaticText(this, wxID_ANY, std::to_string(tm.tm_mon + 1), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer73->Add(m_staticTextMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonMonth = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonMonth->SetRange(1, 12);
    m_spinButtonMonth->SetValue(tm.tm_mon + 1);

    boxSizer73->Add(m_spinButtonMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextYear = new wxStaticText(this, wxID_ANY, std::to_string(tm.tm_year + 1900), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer73->Add(m_staticTextYear, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonYear = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonYear->SetValue(tm.tm_year + 1900);

    boxSizer73->Add(m_spinButtonYear, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText53 = new wxStaticText(this, wxID_ANY, tools->translate("competence"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText53, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer65 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer87->Add(boxSizer65, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticTextCompetence = new wxStaticText(this, wxID_ANY, std::to_string(trainer.getCompetence()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer65->Add(m_staticTextCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonCompetence = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonCompetence->SetRange(1, tools->getMaxSkill());
    m_spinButtonCompetence->SetValue(trainer.getCompetence());

    boxSizer65->Add(m_spinButtonCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextAge = new wxStaticText(this, wxID_ANY,  tools->translate("age") + " " + std::to_string(trainer.getAge()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer65->Add(m_staticTextAge, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText47 = new wxStaticText(this, wxID_ANY, tools->translate("reputation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText47, 0, wxALL, WXC_FROM_DIP(5));

    if (type == TrainerType::COTRAINER)
    {
        wxArrayString choiceArray;
        for (int i = 0; i < 7; ++i)
            choiceArray.Add(tools->translate("trainertype" + std::to_string(i)));
        m_reputationChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), choiceArray, 0);
        m_reputationChoice->SetSelection(trainer.getReputation());

        gridSizer87->Add(m_reputationChoice, 0, wxALL, WXC_FROM_DIP(5));
    }
    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));
    
    /*SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    }
    else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    }
    else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
*/

    // connect events
    // button events
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnAbort), NULL, this);
    // list events
    if(type == TrainerType::COTRAINER)
        this->Connect(m_reputationChoice->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxListEventHandler(DialogTrainer::OnChangeReputation), NULL, this);
    // text events
    this->Connect(m_textName->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogTrainer::OnTextName), NULL, this);
    this->Connect(m_textFirstname->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogTrainer::OnTextLastname), NULL, this);
    // spin events
    this->Connect(m_spinButtonDay->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnDay), NULL, this);
    this->Connect(m_spinButtonMonth->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnMonth), NULL, this);
    this->Connect(m_spinButtonYear->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnYear), NULL, this);
    this->Connect(m_spinButtonCompetence->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnCompetence), NULL, this);
}

DialogTrainer::~DialogTrainer()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnAbort), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnOk), NULL, this);
    // list events
    if (type == TrainerType::COTRAINER)
        this->Disconnect(m_reputationChoice->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxListEventHandler(DialogTrainer::OnChangeReputation), NULL, this);
    // text events
    this->Disconnect(m_textName->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogTrainer::OnTextName), NULL, this);
    this->Disconnect(m_textFirstname->GetId(), wxEVT_TEXT, wxTextEventHandler(DialogTrainer::OnTextLastname), NULL, this);
    // spin events
    this->Disconnect(m_spinButtonDay->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnDay), NULL, this);
    this->Disconnect(m_spinButtonMonth->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnMonth), NULL, this);
    this->Disconnect(m_spinButtonYear->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnYear), NULL, this);
    this->Disconnect(m_spinButtonCompetence->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogTrainer::OnCompetence), NULL, this);
}

void DialogTrainer::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogTrainer::OnOk(wxCommandEvent& event)
{
    // update edited trainer object for country
    if(type ==  TrainerType::COTRAINER)
        country->setCoTrainer(trainer, trainerIndex);
    if (type == TrainerType::GOALKEEPER)
        country->setGoalKeeperTrainer(trainer, trainerIndex);
    wxUnusedVar(event);
    Close();
}

void DialogTrainer::OnChangeReputation(wxListEvent& event)
{
    trainer.setCompetence(event.m_itemIndex);
}

void DialogTrainer::OnTextName(wxCommandEvent& event)
{
    trainer.setLastname(std::string(m_textName->GetValue().mb_str()));
}

void DialogTrainer::OnTextLastname(wxCommandEvent& event)
{
    trainer.setFirstname(std::string(m_textFirstname->GetValue().mb_str()));
}

void DialogTrainer::OnDay(wxSpinEvent& event)
{
    m_staticTextDay->SetLabel(std::to_string(m_spinButtonDay->GetValue()).c_str());
    updateBithday();
}

void DialogTrainer::OnMonth(wxSpinEvent& event)
{
    m_staticTextMonth->SetLabel(std::to_string(m_spinButtonMonth->GetValue()).c_str());
    updateBithday();
}

void DialogTrainer::OnYear(wxSpinEvent& event)
{
    m_staticTextYear->SetLabel(std::to_string(m_spinButtonYear->GetValue()));
    m_staticTextAge->SetLabel(tools->translate("age") + " " + std::to_string(tools->getStartingYear() - m_spinButtonYear->GetValue()));
    trainer.setAge(tools->getStartingYear() - m_spinButtonYear->GetValue());
    updateBithday();
}

void DialogTrainer::OnCompetence(wxSpinEvent& event)
{
    m_staticTextCompetence->SetLabel(std::to_string(m_spinButtonCompetence->GetValue()).c_str());
    trainer.setCompetence(m_spinButtonCompetence->GetValue());
}

void DialogTrainer::updateBithday()
{
    trainer.setBirthday(
        std::to_string(m_spinButtonDay->GetValue()) + "." +
        std::to_string(m_spinButtonMonth->GetValue()) + "." +
        std::to_string(m_spinButtonYear->GetValue())
    );
}