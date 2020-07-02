#include "DialogEuropeanWorldChampionship.h"
#include "DialogEuropeanWorldChampionshipEdit.h"

DialogEuropeanWorldChampionship::DialogEuropeanWorldChampionship(wxWindow* parent,
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

    m_additional = tools->getAdditional();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("hostCountries")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlEmwm = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializeChampionshipList(m_listCtrlEmwm);

    staticBoxSizer19->Add(m_listCtrlEmwm, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionship::OnAbort), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionship::OnEdit), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionship::OnApply), NULL, this);
    // list events
    this->Connect(m_listCtrlEmwm->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogEuropeanWorldChampionship::OnSelectChampionship), NULL, this);
    this->Connect(m_listCtrlEmwm->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogEuropeanWorldChampionship::OnSelectChampionshipActivated), NULL, this);
}

DialogEuropeanWorldChampionship::~DialogEuropeanWorldChampionship()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionship::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionship::OnEdit), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionship::OnApply), NULL, this);
    // list events
    this->Disconnect(m_listCtrlEmwm->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogEuropeanWorldChampionship::OnSelectChampionship), NULL, this);
    this->Disconnect(m_listCtrlEmwm->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogEuropeanWorldChampionship::OnSelectChampionshipActivated), NULL, this);
}

void DialogEuropeanWorldChampionship::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogEuropeanWorldChampionship::OnEdit(wxCommandEvent& event)
{
    if (m_selectedChampionship >= 0)
    {
        DialogEuropeanWorldChampionshipEdit dlg(parent, tools);
        dlg.ShowModal();
    }
}

void DialogEuropeanWorldChampionship::OnApply(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogEuropeanWorldChampionship::OnSelectChampionship(wxListEvent& event)
{
    m_selectedChampionship = event.m_itemIndex;
}

void DialogEuropeanWorldChampionship::OnSelectChampionshipActivated(wxListEvent& event)
{
    m_selectedChampionship = event.m_itemIndex;

    DialogEuropeanWorldChampionshipEdit dlg(parent, tools);
    dlg.ShowModal();
}

void DialogEuropeanWorldChampionship::initializeChampionshipList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(2, wxT(""), wxLIST_FORMAT_LEFT, 100);

    auto emwmList = m_additional->getEMWM();

    long index = 0;
    for (auto emwm : emwmList)
    {
        auto nationId = tools->getNationIdByIndex(emwm.nationIndex);
        auto nation = tools->getNationById(nationId);

        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, tools->translate(emwm.type==0?"EC":"WC"));
        control->SetItem(result, 1, std::to_string(emwm.year));
        control->SetItem(result, 2, tools->translate(nation->getShortname()));

        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }

    control->Show();

    control->SetMinSize(wxSize(200, 300));
}