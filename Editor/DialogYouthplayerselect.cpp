#include "DialogYouthplayerselect.h"

DialogYouthplayerselect::DialogYouthplayerselect(wxWindow* parent, 
    Toolset* const tools,
    const std::string selectedCountry,
    wxWindowID id,
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    m_country = tools->getCountryById(countryId);
    m_youthPlayers = m_country->getYouthPlayer();

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    this->SetSizer(flexGridSizer17);

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseYouthplayer")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlYouthplayer = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT);
    initializeYouthplayerList(m_listCtrlYouthplayer);

    staticBoxSizer19->Add(m_listCtrlYouthplayer, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonApply, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayerselect::OnEdit), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayerselect::OnAbort), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayerselect::OnApply), NULL, this);
}

DialogYouthplayerselect::~DialogYouthplayerselect()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayerselect::OnEdit), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayerselect::OnAbort), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogYouthplayerselect::OnApply), NULL, this);
}

void DialogYouthplayerselect::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogYouthplayerselect::OnApply(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogYouthplayerselect::OnEdit(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogYouthplayerselect::initializeYouthplayerList(wxListCtrl* control)
{
    control->Hide();

    control->InsertColumn(0, tools->translate("pos"), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(1, tools->translate("name"), wxLIST_FORMAT_LEFT, 180);
    control->InsertColumn(2, wxT(""), wxLIST_FORMAT_LEFT, 150);
    control->InsertColumn(3, tools->translate("club"), wxLIST_FORMAT_LEFT, 140);

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    auto teamIds = tools->getTeamIdsByCoutryId(countryId);

    long index = 0; 
    for (auto player : m_youthPlayers)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, positionToString(player.getMainPosition()));
        control->SetItem(result, 1, player.getLastname());
        control->SetItem(result, 2, player.getFirstname());
        if (player.getTeamId() > 0)
        {
            for (auto teamId : teamIds)
            {
                auto team = tools->getTeamById(teamId);
                if (team->getTeamId() == player.getTeamId())
                {
                    control->SetItem(result, 3, team->getName());
                    break;
                }
            }
        }
        else
        {
            control->SetItem(result, 3, wxT(""));
        }
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(520, 300));
}

std::string DialogYouthplayerselect::positionToString(short position)
{
    switch (position)
    {
        case 0: return "T";
        case 1: return "L";
        case 2: return "IV";
        case 3: return "LV";
        case 4: return "RV";
        case 5: return "DM";
        case 6: return "LM";
        case 7: return "RM";
        case 8: return "OM";
        case 9: return "S";
    }

    return "";
}