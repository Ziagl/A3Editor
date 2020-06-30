#include "DialogPlayerpoolsedit.h"
#include "DialogYouthplayeredit.h"

DialogPlayerpoolsedit::DialogPlayerpoolsedit(wxWindow* parent, 
    Toolset* const tools,
    const short poolIndex,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_poolIndex(poolIndex), parent(parent)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto playerpool = tools->getPlayerpool();
    m_countrypool = playerpool->getPool(m_poolIndex);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseYouthplayer")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlPlayer = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializePlayerList(m_listCtrlPlayer);

    staticBoxSizer19->Add(m_listCtrlPlayer, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonApply, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("DialogPlayerpoolsedit"));
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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpoolsedit::OnAbort), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpoolsedit::OnApply), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpoolsedit::OnEdit), NULL, this);
    // list events
    this->Connect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPlayerpoolsedit::OnSelectPerson), NULL, this);
    this->Connect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogPlayerpoolsedit::OnSelectPersonActivated), NULL, this);
}

DialogPlayerpoolsedit::~DialogPlayerpoolsedit()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpoolsedit::OnAbort), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpoolsedit::OnApply), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayerpoolsedit::OnEdit), NULL, this);
    // list events
    this->Disconnect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPlayerpoolsedit::OnSelectPerson), NULL, this);
    this->Disconnect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogPlayerpoolsedit::OnSelectPersonActivated), NULL, this);
}

void DialogPlayerpoolsedit::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogPlayerpoolsedit::OnApply(wxCommandEvent& event)
{
    auto playerpool = tools->getPlayerpool();
    playerpool->setPool(m_countrypool, m_poolIndex);

    wxUnusedVar(event);
    Close();
}

void DialogPlayerpoolsedit::OnEdit(wxCommandEvent& event)
{
    if (m_selectedIndex >= 0)
    {
        callYouthPlayerEditDialog();
    }
}

void DialogPlayerpoolsedit::OnSelectPerson(wxListEvent& event)
{
    m_selectedIndex = event.m_itemIndex;
}

void DialogPlayerpoolsedit::OnSelectPersonActivated(wxListEvent& event)
{
    m_selectedIndex = event.m_itemIndex;

    callYouthPlayerEditDialog();
}

void DialogPlayerpoolsedit::callYouthPlayerEditDialog()
{
    Core::YouthPlayer youthPlayer;
    youthPlayer.setFirstname(std::get<0>(m_countrypool.at(m_selectedIndex)));
    youthPlayer.setLastname(std::get<1>(m_countrypool.at(m_selectedIndex)));

    std::string empty;
    DialogYouthplayeredit dlg(parent, tools, empty, youthPlayer);
    dlg.ShowModal();

    auto player = std::make_tuple(youthPlayer.getLastname(), youthPlayer.getFirstname());
    m_countrypool.at(m_selectedIndex) = player;

    initializePlayerList(m_listCtrlPlayer);
}

void DialogPlayerpoolsedit::initializePlayerList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 80);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_LEFT, 80);

    long index = 0;
    for (auto player : m_countrypool)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, std::get<1>(player));
        control->SetItem(result, 1, std::get<0>(player));
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(180, 300));
}