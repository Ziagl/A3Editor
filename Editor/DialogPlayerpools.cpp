#include "DialogPlayerpools.h"

DialogPlayerpools::DialogPlayerpools(wxWindow* parent, 
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

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("pleaseSelectThePoolYouWant")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer27 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer27->SetFlexibleDirection(wxBOTH);
    flexGridSizer27->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer19->Add(flexGridSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioButtonAfrica = new wxRadioButton(this, wxID_ANY, tools->translate("africa"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxRB_GROUP);
    m_radioButtonAfrica->SetValue(1);

    flexGridSizer27->Add(m_radioButtonAfrica, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonNorway = new wxRadioButton(this, wxID_ANY, tools->translate("NOR"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonNorway->SetValue(1);

    flexGridSizer27->Add(m_radioButtonNorway, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonArabia = new wxRadioButton(this, wxID_ANY, tools->translate("arabia"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonArabia->SetValue(1);

    flexGridSizer27->Add(m_radioButtonArabia, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonPoland = new wxRadioButton(this, wxID_ANY, tools->translate("POL"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonPoland->SetValue(1);

    flexGridSizer27->Add(m_radioButtonPoland, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonAsia = new wxRadioButton(this, wxID_ANY, tools->translate("asia"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonAsia->SetValue(1);

    flexGridSizer27->Add(m_radioButtonAsia, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonRomania = new wxRadioButton(this, wxID_ANY, tools->translate("ROM"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonRomania->SetValue(1);

    flexGridSizer27->Add(m_radioButtonRomania, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonBelgium = new wxRadioButton(this, wxID_ANY, tools->translate("BEL"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonBelgium->SetValue(1);

    flexGridSizer27->Add(m_radioButtonBelgium, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonRussia = new wxRadioButton(this, wxID_ANY, tools->translate("RUS"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonRussia->SetValue(1);

    flexGridSizer27->Add(m_radioButtonRussia, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonBulgaria = new wxRadioButton(this, wxID_ANY, tools->translate("BUL"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonBulgaria->SetValue(1);

    flexGridSizer27->Add(m_radioButtonBulgaria, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonSweden = new wxRadioButton(this, wxID_ANY, tools->translate("SWE"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonSweden->SetValue(1);

    flexGridSizer27->Add(m_radioButtonSweden, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonDenmark = new wxRadioButton(this, wxID_ANY, tools->translate("DEN"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonDenmark->SetValue(1);

    flexGridSizer27->Add(m_radioButtonDenmark, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonOtherBalkanCountries = new wxRadioButton(this, wxID_ANY, tools->translate("otherBalkanCountries"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonOtherBalkanCountries->SetValue(1);

    flexGridSizer27->Add(m_radioButtonOtherBalkanCountries, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonFinland = new wxRadioButton(this, wxID_ANY, tools->translate("FIN"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonFinland->SetValue(1);

    flexGridSizer27->Add(m_radioButtonFinland, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonSlovakiaAndTheCzechRepublic = new wxRadioButton(this, wxID_ANY, tools->translate("SVK") + " & " + tools->translate("CZE"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonSlovakiaAndTheCzechRepublic->SetValue(1);

    flexGridSizer27->Add(m_radioButtonSlovakiaAndTheCzechRepublic, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonGreek = new wxRadioButton(this, wxID_ANY, tools->translate("GRE"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonGreek->SetValue(1);

    flexGridSizer27->Add(m_radioButtonGreek, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonHungary = new wxRadioButton(this, wxID_ANY, tools->translate("HUN"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonHungary->SetValue(1);

    flexGridSizer27->Add(m_radioButtonHungary, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButtonIsrael = new wxRadioButton(this, wxID_ANY, tools->translate("ISR"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButtonIsrael->SetValue(1);

    flexGridSizer27->Add(m_radioButtonIsrael, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpools::OnAbort), NULL, this);
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpools::OnOk), NULL, this);
}

DialogPlayerpools::~DialogPlayerpools()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpools::OnAbort), NULL, this);
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpools::OnOk), NULL, this);
}

void DialogPlayerpools::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogPlayerpools::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}