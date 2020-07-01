#include "DialogInternationalcups.h"

DialogInternationalcups::DialogInternationalcups(wxWindow* parent, 
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

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxStaticBoxSizer* staticBoxSizer17 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("menuInternationalCups")), wxVERTICAL);

    mainSizer->Add(staticBoxSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer19 = new wxFlexGridSizer(2, 2, 0, 0);
    flexGridSizer19->SetFlexibleDirection(wxBOTH);
    flexGridSizer19->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer19->AddGrowableCol(1);

    staticBoxSizer17->Add(flexGridSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText21 = new wxStaticText(this, wxID_ANY, tools->translate("championsCup"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer19->Add(m_staticText21, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlChampionsLeagueName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlChampionsLeagueName->SetHint(wxT(""));
#endif

    flexGridSizer19->Add(m_textCtrlChampionsLeagueName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText25 = new wxStaticText(this, wxID_ANY, tools->translate("europeAssociationCup"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer19->Add(m_staticText25, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlEuropeLeagueName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlEuropeLeagueName->SetHint(wxT(""));
#endif

    flexGridSizer19->Add(m_textCtrlEuropeLeagueName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(500, -1)));
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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalcups::OnAbort), NULL, this);
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalcups::OnOk), NULL, this);
}

DialogInternationalcups::~DialogInternationalcups()
{
    // disconnect events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalcups::OnAbort), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogInternationalcups::OnOk), NULL, this);
}

void DialogInternationalcups::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogInternationalcups::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}