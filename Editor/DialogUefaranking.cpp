#include "DialogUefaranking.h"
#include "DialogUefarankingEdit.h"

DialogUefaranking::DialogUefaranking(wxWindow* parent, 
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

    uefaRanking = tools->getUefaRanking();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer21 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("standAtTheStartOfTheGame")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_countryList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    initializeCountryList(m_countryList);

    staticBoxSizer21->Add(m_countryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer23 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer23->Add(m_buttonApply, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY,tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer23->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefaranking::OnApply), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefaranking::OnAbort), NULL, this);
    // list events
    this->Connect(m_countryList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogUefaranking::OnSelectCountryActivated), NULL, this);
}

DialogUefaranking::~DialogUefaranking()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefaranking::OnApply), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefaranking::OnAbort), NULL, this);
    // list events
    this->Disconnect(m_countryList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogUefaranking::OnSelectCountryActivated), NULL, this);
}

void DialogUefaranking::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogUefaranking::OnApply(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogUefaranking::OnSelectCountryActivated(wxListEvent& event)
{
    auto team = uefaRanking->getValue().at(event.m_itemIndex);
    DialogUefarankingEdit dlg(this, tools, team, wxID_ANY, m_countryList->GetItemText(event.m_itemIndex, 1));
    dlg.ShowModal();
    uefaRanking->setValue(team, event.m_itemIndex);
    initializeCountryList(m_countryList);
}

void DialogUefaranking::initializeCountryList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, tools->translate("rank"), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(1, tools->translate("country"), wxLIST_FORMAT_LEFT, 85);
    control->InsertColumn(2, tools->translate("points"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(3, tools->translate("lastSeason"), wxLIST_FORMAT_LEFT, 50);

    auto teams = uefaRanking->getValue();

    long index = 0;
    for (auto team : teams)
    {
        // skip last 2 lines because they contain nonsense and bonus land
        if (index >= teams.size() - 2)
            continue;

        auto nationId = tools->getNationIdByIndex(team.countryId);
        auto nation = tools->getNationById(nationId);

        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, std::to_string(index + 1));
        control->SetItem(result, 1, tools->translate(nation->getShortname()));
        control->SetItem(result, 2, std::to_string(team.sum)); 
        control->SetItem(result, 3, std::to_string(team.years.at(team.years.size() - 1)));
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }

    control->Show();

    control->SetMinSize(wxSize(250, 300));
}