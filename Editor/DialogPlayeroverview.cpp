#include "DialogPlayeroverview.h"

DialogPlayeroverview::DialogPlayeroverview(wxWindow* parent, 
    Toolset* const tools,
    std::vector<std::shared_ptr<Core::Player>> players,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_players(players)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxStaticBoxSizer* staticBoxSizer17 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("overview")), wxVERTICAL);

    mainSizer->Add(staticBoxSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPlayer = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_SINGLE_SEL | wxLC_REPORT);
    initializePlayerList(m_listCtrlPlayer);

    staticBoxSizer17->Add(m_listCtrlPlayer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonType = new wxButton(this, wxID_CANCEL, tools->translate("personality"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonType, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();

    boxSizer12->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonType->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeroverview::OnType), NULL, this);
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeroverview::OnOk), NULL, this);
}

DialogPlayeroverview::~DialogPlayeroverview()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonType->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeroverview::OnType), NULL, this);
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeroverview::OnOk), NULL, this);
}

void DialogPlayeroverview::OnType(wxCommandEvent& event)
{
    m_typeProperties = !m_typeProperties;
    if (m_typeProperties)
    {
        m_buttonType->SetLabel(tools->translate("personality"));
    }
    else
    {
        m_buttonType->SetLabel(tools->translate("properties"));
    }
    initializePlayerList(m_listCtrlPlayer);
}

void DialogPlayeroverview::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogPlayeroverview::initializePlayerList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, tools->translate("capab"), wxLIST_FORMAT_LEFT, 70);
    control->InsertColumn(1, tools->translate("pos"), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(2, tools->translate("apos") + "1", wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(3, tools->translate("apos") + "2", wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(4, tools->translate("name"), wxLIST_FORMAT_LEFT, 150);
    control->InsertColumn(5, tools->translate("age"), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(6, tools->translate("skill"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(7, tools->translate(m_typeProperties ? "properties":"personality"), wxLIST_FORMAT_LEFT, 200);

    long index = 0;
    for (auto player : m_players)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, "");
        control->SetItem(result, 1, tools->positionToString(player->getMainPosition()));
        control->SetItem(result, 2, tools->positionToString(player->getAlternativeFirstPosition()));
        control->SetItem(result, 3, tools->positionToString(player->getAlternativeSecondPosition()));
        control->SetItem(result, 4, player->getLastname() + ", " + player->getFirstname());
        control->SetItem(result, 5, std::to_string(player->getAge()));
        control->SetItem(result, 6, std::to_string(player->getSkill()));
        control->SetItem(result, 7, m_typeProperties ? tools->propertiesToString(player->getPlayerProperties()) : tools->personalityToString(player->getPlayerPersonality()));
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work
        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(650, 300));
}