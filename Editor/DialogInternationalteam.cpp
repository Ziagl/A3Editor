#include "DialogInternationalteam.h"
#include "DialogStringEdit.h"

DialogInternationalteam::DialogInternationalteam(wxWindow* parent, 
    Toolset* const tools, 
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), parent(parent)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    m_international = tools->getInternational();
    m_internationalTeams = m_international->getTeams();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseClub")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlTeams = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializeClubList(m_listCtrlTeams);

    staticBoxSizer19->Add(m_listCtrlTeams, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalteam::OnAbort), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalteam::OnApply), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalteam::OnEdit), NULL, this);
    // list events
    this->Connect(m_listCtrlTeams->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogInternationalteam::OnSelectClub), NULL, this);
    this->Connect(m_listCtrlTeams->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogInternationalteam::OnSelectClubActivated), NULL, this);
}

DialogInternationalteam::~DialogInternationalteam()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalteam::OnAbort), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalteam::OnApply), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalteam::OnEdit), NULL, this);
    // list events
    this->Disconnect(m_listCtrlTeams->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogInternationalteam::OnSelectClub), NULL, this);
    this->Disconnect(m_listCtrlTeams->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogInternationalteam::OnSelectClubActivated), NULL, this);
}

void DialogInternationalteam::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogInternationalteam::OnApply(wxCommandEvent& event)
{
    m_international->setTeams(m_internationalTeams);
    wxUnusedVar(event);
    Close();
}

void DialogInternationalteam::OnEdit(wxCommandEvent& event)
{
    if (m_selectedIndex)
    {
        DialogStringEdit dlg(parent, tools, m_internationalTeams.at(m_selectedIndex).name, wxID_ANY, tools->translate("newClubName"));
        dlg.ShowModal();
        initializeClubList(m_listCtrlTeams);
    }
}

void DialogInternationalteam::OnSelectClub(wxListEvent& event)
{
    m_selectedIndex = event.m_itemIndex;
}

void DialogInternationalteam::OnSelectClubActivated(wxListEvent& event)
{
    m_selectedIndex = event.m_itemIndex;
    DialogStringEdit dlg(parent, tools, m_internationalTeams.at(m_selectedIndex).name, wxID_ANY, tools->translate("newClubName"));
    dlg.ShowModal();
    initializeClubList(m_listCtrlTeams);
}

void DialogInternationalteam::initializeClubList(wxListCtrl* control)
{
    // to speed up inserting we hide the control temporarily
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 100);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_LEFT, 130);

    long index = 0;
    short lastNationId = 0;
    for (auto team : m_internationalTeams)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        if (lastNationId != team.nationId)
        {
            auto nationId = tools->getNationIdByIndex(team.nationId);
            auto nation = tools->getNationById(nationId);
            control->SetItem(result, 0, nation->getName() + ":");
        }
        else
            control->SetItem(result, 0, "");
        control->SetItem(result, 1, team.name);
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work
        ++index;
        lastNationId = team.nationId;
    }

    control->Show();

    control->SetMinSize(wxSize(250, -1));
}
