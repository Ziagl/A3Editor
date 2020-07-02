#include "DialogCompetition.h"

DialogCompetition::DialogCompetition(wxWindow* parent, 
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

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Gruppe auswählen")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer31 = new wxBoxSizer(wxVERTICAL);

    staticBoxSizer19->Add(boxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    for (int i = 0; i < 8; ++i)
    {
        wxButton* button =new wxButton(this, wxID_ANY, std::to_string(i+1), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
        boxSizer31->Add(button, 0, wxALL | wxEXPAND, WXC_FROM_DIP(3));

        m_buttonGroup.push_back(button);
    }

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Vereine")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer25, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer51 = new wxFlexGridSizer(8, 2, 0, 0);
    flexGridSizer51->SetFlexibleDirection(wxBOTH);
    flexGridSizer51->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer25->Add(flexGridSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText53 = new wxStaticText(this, wxID_ANY, _("Erster Verein"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText53, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceTeam1Arr;
    m_choiceTeam1 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceTeam1Arr, 0);

    flexGridSizer51->Add(m_choiceTeam1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText57 = new wxStaticText(this, wxID_ANY, tools->translate("country"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceCountry1Arr;
    m_choiceCountry1 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry1Arr, 0);

    flexGridSizer51->Add(m_choiceCountry1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText61 = new wxStaticText(this, wxID_ANY, _("Zweiter Verein"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText61, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceTeam2Arr;
    m_choiceTeam2 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceTeam2Arr, 0);

    flexGridSizer51->Add(m_choiceTeam2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText65 = new wxStaticText(this, wxID_ANY, tools->translate("country"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText65, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceCountry2Arr;
    m_choiceCountry2 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry2Arr, 0);

    flexGridSizer51->Add(m_choiceCountry2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText69 = new wxStaticText(this, wxID_ANY, _("Dritter Verein"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText69, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceTeam3Arr;
    m_choiceTeam3 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceTeam3Arr, 0);

    flexGridSizer51->Add(m_choiceTeam3, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText73 = new wxStaticText(this, wxID_ANY, tools->translate("country"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText73, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceCountry3Arr;
    m_choiceCountry3 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry3Arr, 0);

    flexGridSizer51->Add(m_choiceCountry3, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText77 = new wxStaticText(this, wxID_ANY, _("Vierter Verein"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText77, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceTeam4Arr;
    m_choiceTeam4 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceTeam4Arr, 0);

    flexGridSizer51->Add(m_choiceTeam4, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText81 = new wxStaticText(this, wxID_ANY, tools->translate("country"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText81, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceCountry4Arr;
    m_choiceCountry4 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCountry4Arr, 0);

    flexGridSizer51->Add(m_choiceCountry4, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
}

DialogCompetition::~DialogCompetition()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCompetition::OnAbort), NULL, this);
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