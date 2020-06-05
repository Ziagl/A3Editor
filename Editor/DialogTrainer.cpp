#include "DialogTrainer.h"

DialogTrainer::DialogTrainer(wxWindow* parent, 
    Toolset* const tools, 
    std::string country, 
    std::string trainer,
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

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Trainer und Co-Trainer ändern")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    wxGridSizer* gridSizer87 = new wxGridSizer(5, 2, 0, 0);

    staticBoxSizer19->Add(gridSizer87, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticText31 = new wxStaticText(this, wxID_ANY, _("Name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText31, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl33 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl33->SetHint(wxT(""));
#endif

    gridSizer87->Add(m_textCtrl33, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText37 = new wxStaticText(this, wxID_ANY, _("Vorname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText37, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl39 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl39->SetHint(wxT(""));
#endif

    gridSizer87->Add(m_textCtrl39, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText51 = new wxStaticText(this, wxID_ANY, _("Geburtsdatum"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText51, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer73 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer87->Add(boxSizer73, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticText75 = new wxStaticText(this, wxID_ANY, _("99"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer73->Add(m_staticText75, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton77 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton77->SetRange(0, 100);
    m_spinButton77->SetValue(0);

    boxSizer73->Add(m_spinButton77, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText79 = new wxStaticText(this, wxID_ANY, _("12"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer73->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton81 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton81->SetRange(0, 100);
    m_spinButton81->SetValue(0);

    boxSizer73->Add(m_spinButton81, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText83 = new wxStaticText(this, wxID_ANY, _("1990"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer73->Add(m_staticText83, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton85 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton85->SetRange(0, 100);
    m_spinButton85->SetValue(0);

    boxSizer73->Add(m_spinButton85, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText53 = new wxStaticText(this, wxID_ANY, _("Kompetenz"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText53, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer65 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer87->Add(boxSizer65, 1, wxALL | wxEXPAND, WXC_FROM_DIP(3));

    m_staticText67 = new wxStaticText(this, wxID_ANY, _("8"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer65->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton69 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton69->SetRange(0, 100);
    m_spinButton69->SetValue(0);

    boxSizer65->Add(m_spinButton69, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText71 = new wxStaticText(this, wxID_ANY, _("Alter 34"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer65->Add(m_staticText71, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText47 = new wxStaticText(this, wxID_ANY, _("Ruf"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer87->Add(m_staticText47, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice49Arr;
    m_choice49 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choice49Arr, 0);

    gridSizer87->Add(m_choice49, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, _("Abbrechen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

    /*SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    }
    else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    }
    else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
*/

    // connect events
    // button events
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnAbort), NULL, this);
}

DialogTrainer::~DialogTrainer()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnAbort), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnOk), NULL, this);
}

void DialogTrainer::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogTrainer::OnOk(wxCommandEvent& event)
{
    /// #### TODO #### save data
    wxUnusedVar(event);
    Close();
}