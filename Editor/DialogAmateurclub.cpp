#include "DialogAmateurclub.h"
#include "DialogStringEdit.h"

DialogAmateurclub::DialogAmateurclub(wxWindow* parent, 
    Toolset* const tools,
    const std::string selectedCountry,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), parent(parent), tools(tools), m_selectedCountry(selectedCountry), m_selectedClubIndex(-1)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    m_country = tools->getCountryById(countryId);
    m_amateurClubs = m_country->getAmateurTeams();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseClub") + "!"), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_clubList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializeClubList(m_clubList);

    staticBoxSizer19->Add(m_clubList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonEdit, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAmateurclub::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAmateurclub::OnAbort), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAmateurclub::OnEdit), NULL, this);
    // list events
    this->Connect(m_clubList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogAmateurclub::OnSelectClub), NULL, this);
    this->Connect(m_clubList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogAmateurclub::OnSelectClubActivated), NULL, this);
}

DialogAmateurclub::~DialogAmateurclub()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAmateurclub::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAmateurclub::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogAmateurclub::OnEdit), NULL, this);
    // list events
    this->Disconnect(m_clubList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogAmateurclub::OnSelectClub), NULL, this);
    this->Disconnect(m_clubList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogAmateurclub::OnSelectClubActivated), NULL, this);
}

void DialogAmateurclub::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogAmateurclub::OnOk(wxCommandEvent& event)
{
    m_country->setAmateurTeams(m_amateurClubs);
    wxUnusedVar(event);
    Close();
}

void DialogAmateurclub::OnEdit(wxCommandEvent& event)
{
    if (m_selectedClubIndex > 0)
    {
        DialogStringEdit dlg(parent, tools, m_amateurClubs.at(m_selectedClubIndex), wxID_ANY, tools->translate("newClubName"));
        dlg.ShowModal();
        initializeClubList(m_clubList);
    }
}

void DialogAmateurclub::OnSelectClub(wxListEvent& event)
{
    m_selectedClubIndex = event.m_itemIndex;
}

void DialogAmateurclub::OnSelectClubActivated(wxListEvent& event)
{
    m_selectedClubIndex = event.m_itemIndex;

    DialogStringEdit dlg(parent, tools, m_amateurClubs.at(m_selectedClubIndex), wxID_ANY, tools->translate("newClubName"));
    dlg.ShowModal();
    initializeClubList(m_clubList);
}

void DialogAmateurclub::initializeClubList(wxListCtrl* control)
{
    control->Hide();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 200);

    long index = 0;
    for (auto team : m_amateurClubs)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, team);
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(200, 300));
}