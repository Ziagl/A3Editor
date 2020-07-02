#include "DialogOutfitter.h"
#include "DialogStringEdit.h"

DialogOutfitter::DialogOutfitter(wxWindow* parent, 
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
    m_outfitterList = m_additional->getOutfitter();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseOutfitter")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlOutfitter = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializeOutfitterList(m_listCtrlOutfitter);

    staticBoxSizer19->Add(m_listCtrlOutfitter, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk") , wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogOutfitter::OnAbort), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogOutfitter::OnEdit), NULL, this);
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogOutfitter::OnOk), NULL, this);
    // list events
    this->Connect(m_listCtrlOutfitter->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogOutfitter::OnSelectOutfitter), NULL, this);
    this->Connect(m_listCtrlOutfitter->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogOutfitter::OnSelectOutfitterActivated), NULL, this);
}

DialogOutfitter::~DialogOutfitter()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogOutfitter::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogOutfitter::OnEdit), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogOutfitter::OnOk), NULL, this);
    // list events
    this->Disconnect(m_listCtrlOutfitter->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogOutfitter::OnSelectOutfitter), NULL, this);
    this->Disconnect(m_listCtrlOutfitter->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogOutfitter::OnSelectOutfitterActivated), NULL, this);
}

void DialogOutfitter::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogOutfitter::OnOk(wxCommandEvent& event)
{
    m_additional->setOutfitter(m_outfitterList);
    wxUnusedVar(event);
    Close();
}

void DialogOutfitter::OnEdit(wxCommandEvent& event)
{
    if (m_selectedOutfitter >= 0)
    {
        DialogStringEdit dlg(parent, tools, m_outfitterList.at(m_selectedOutfitter));
        dlg.ShowModal();
        initializeOutfitterList(m_listCtrlOutfitter);
    }
}

void DialogOutfitter::OnSelectOutfitter(wxListEvent& event)
{
    m_selectedOutfitter = event.m_itemIndex;
}

void DialogOutfitter::OnSelectOutfitterActivated(wxListEvent& event)
{
    m_selectedOutfitter = event.m_itemIndex;

    DialogStringEdit dlg(parent, tools, m_outfitterList.at(m_selectedOutfitter), wxID_ANY, tools->translate("newOutfitterName"));
    dlg.ShowModal();
    initializeOutfitterList(m_listCtrlOutfitter);
}

void DialogOutfitter::initializeOutfitterList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 150);

    long index = 0;
    for (auto outfitter : m_outfitterList)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, outfitter);
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work
        index++;
    }

    control->Show();

    control->SetMinSize(wxSize(170, 200));
}