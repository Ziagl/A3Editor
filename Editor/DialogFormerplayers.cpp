#include "DialogFormerplayers.h"

DialogFormerplayers::DialogFormerplayers(wxWindow* parent, 
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

    formerPlayerIds = tools->getFormerPlayerIds();

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    this->SetSizer(flexGridSizer17);

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("choosePlayer")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPlayer = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT);
    initializePlayerList(m_listCtrlPlayer);

    staticBoxSizer19->Add(m_listCtrlPlayer, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("DialogFormerplayers"));
    SetTitle(tools->translate("player"));
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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogFormerplayers::OnAbort), NULL, this);
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogFormerplayers::OnOk), NULL, this);
    // list events
    this->Connect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogFormerplayers::OnSelectPlayer), NULL, this);

    // init
    m_listCtrlPlayer->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);    // select first item
}

DialogFormerplayers::~DialogFormerplayers()
{
    // disconnect events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogFormerplayers::OnAbort), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogFormerplayers::OnOk), NULL, this);
    // list events
    this->Disconnect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogFormerplayers::OnSelectPlayer), NULL, this);
}

void DialogFormerplayers::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogFormerplayers::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogFormerplayers::OnSelectPlayer(wxListEvent& event)
{
    m_selectedPlayer = event.m_itemIndex;
    auto player = tools->getFormerPlayerById(formerPlayerIds.at(m_selectedPlayer));
    SetTitle(tools->translate("player") + " - " + player->getFirstname() + " " + player->getLastname());
}

void DialogFormerplayers::initializePlayerList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, tools->translate("name"), wxLIST_FORMAT_LEFT, 150);
    control->InsertColumn(1, tools->translate("skill"), wxLIST_FORMAT_CENTER, 50);
    control->InsertColumn(2, tools->translate("age"), wxLIST_FORMAT_CENTER, 40);
    control->InsertColumn(3, tools->translate("lastClub"), wxLIST_FORMAT_LEFT, 150);

    long index = 0;
    for (auto formerPlayerId : formerPlayerIds)
    {
        auto formerPlayer = tools->getFormerPlayerById(formerPlayerId);
        auto teamId = tools->getTeamIdByFormerPlayerId(formerPlayerId);
        auto team = tools->getTeamById(teamId);

        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, formerPlayer->getLastname() + "," + formerPlayer->getFirstname());
        control->SetItem(result, 1, std::to_string(formerPlayer->getSkill()));
        control->SetItem(result, 2, std::to_string(formerPlayer->getAge()));
        control->SetItem(result, 3, team->getName());
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }

    control->Show();

    control->SetMinSize(wxSize(410, 320));
}