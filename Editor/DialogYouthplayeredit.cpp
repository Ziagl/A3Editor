#include "DialogYouthplayeredit.h"

DialogYouthplayeredit::DialogYouthplayeredit(wxWindow* parent, 
    Toolset* const tools, 
    const std::string selectedCountry,
    Core::YouthPlayer& youthplayer,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_youthplayer(youthplayer), m_selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    auto teamIds = tools->getTeamIdsByCoutryId(countryId);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer19 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("lastname")), wxVERTICAL);

    boxSizer19->Add(staticBoxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlName = new wxTextCtrl(this, wxID_ANY, m_youthplayer.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlName->SetHint(wxT(""));
#endif

    staticBoxSizer27->Add(m_textCtrlName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer29 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("firstname")), wxVERTICAL);

    boxSizer19->Add(staticBoxSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlFirstname = new wxTextCtrl(this, wxID_ANY, m_youthplayer.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstname->SetHint(wxT(""));
#endif

    staticBoxSizer29->Add(m_textCtrlFirstname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer31 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("club")), wxVERTICAL);

    boxSizer19->Add(staticBoxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString choiceClubArray;
    choiceClubArray.Add(tools->translate("none"));
    for (auto teamId : teamIds)
    {
        auto team = tools->getTeamById(teamId);
        choiceClubArray.Add(team->getName());
    }
    m_choiceClub = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), choiceClubArray, 0);
    m_choiceClub->SetSelection(m_youthplayer.getTeamId());

    staticBoxSizer31->Add(m_choiceClub, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOK, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayeredit::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayeredit::OnAbort), NULL, this);
}

DialogYouthplayeredit::~DialogYouthplayeredit()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayeredit::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayeredit::OnAbort), NULL, this);
}

void DialogYouthplayeredit::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogYouthplayeredit::OnOk(wxCommandEvent& event)
{
    m_youthplayer.setFirstname(std::string(m_textCtrlName->GetValue().mb_str()));
    m_youthplayer.setLastname(std::string(m_textCtrlFirstname->GetValue().mb_str()));
    m_youthplayer.setTeamId(m_choiceClub->GetSelection());
    wxUnusedVar(event);
    Close();
}
