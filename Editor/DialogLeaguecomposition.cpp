#include "DialogLeaguecomposition.h"

DialogLeaguecomposition::DialogLeaguecomposition(wxWindow* parent, 
    Toolset* const tools, 
    const std::string selectedCountry,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry)
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

    wxFlexGridSizer* flexGridSizer19 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer19->SetFlexibleDirection(wxBOTH);
    flexGridSizer19->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer27 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer27->SetFlexibleDirection(wxBOTH);
    flexGridSizer27->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer19->Add(flexGridSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer45 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("clubsInThisLeague")), wxVERTICAL);

    flexGridSizer27->Add(staticBoxSizer45, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlClubs = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(150, 250)), wxLC_REPORT);

    staticBoxSizer45->Add(m_listCtrlClubs, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText93 = new wxStaticText(this, wxID_ANY, tools->translate("dragAndDropMessage"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_staticText93->Wrap(150);

    staticBoxSizer45->Add(m_staticText93, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer47 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer27->Add(boxSizer47, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_panel95 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, 100)), wxTAB_TRAVERSAL);

    boxSizer47->Add(m_panel95, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonRemove = new wxButton(this, wxID_ANY, _(">>"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(30, -1)), 0);

    boxSizer47->Add(m_buttonRemove, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAdd = new wxButton(this, wxID_ANY, _("<<"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(30, -1)), 0);

    boxSizer47->Add(m_buttonAdd, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer49 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer49->SetFlexibleDirection(wxBOTH);
    flexGridSizer49->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer27->Add(flexGridSizer49, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer51 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("otherClubs")), wxVERTICAL);

    flexGridSizer49->Add(staticBoxSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlOtherClubs = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(150, -1)), wxLC_REPORT);

    staticBoxSizer51->Add(m_listCtrlOtherClubs, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer53 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("legend")), wxVERTICAL);

    flexGridSizer49->Add(staticBoxSizer53, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer59 = new wxFlexGridSizer(7, 2, 0, 0);
    flexGridSizer59->SetFlexibleDirection(wxBOTH);
    flexGridSizer59->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer53->Add(flexGridSizer59, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticBitmap61 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap61, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText63 = new wxStaticText(this, wxID_ANY, tools->translate("champion"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(0));

    m_staticBitmap65 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap65, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText67 = new wxStaticText(this, wxID_ANY, tools->translate("runnerUp"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(0));

    m_staticBitmap69 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap69, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText71 = new wxStaticText(this, wxID_ANY, tools->translate("cupWinner"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText71, 0, wxALL, WXC_FROM_DIP(0));

    m_staticBitmap73 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap73, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText75 = new wxStaticText(this, wxID_ANY, tools->translate("cupFinalist"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText75, 0, wxALL, WXC_FROM_DIP(0));

    m_staticBitmap77 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap77, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText79 = new wxStaticText(this, wxID_ANY, tools->translate("relegatedTeam"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(0));

    m_staticBitmap81 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap81, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText83 = new wxStaticText(this, wxID_ANY, tools->translate("leagueClimber"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText83, 0, wxALL, WXC_FROM_DIP(0));

    m_staticBitmap85 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticBitmap85, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText87 = new wxStaticText(this, wxID_ANY, tools->translate("cupParticipant"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer59->Add(m_staticText87, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer29 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("currentLeague")), wxVERTICAL);

    flexGridSizer19->Add(staticBoxSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer31 = new wxFlexGridSizer(2, 3, 0, 0);
    flexGridSizer31->SetFlexibleDirection(wxBOTH);
    flexGridSizer31->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer29->Add(flexGridSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButtonLeague1 = new wxToggleButton(this, wxID_ANY, _("1. Liga AUS"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButtonLeague1->SetValue(true);

    flexGridSizer31->Add(m_toggleButtonLeague1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButtonLeague2 = new wxToggleButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButtonLeague2->SetValue(false);

    flexGridSizer31->Add(m_toggleButtonLeague2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButtonLeague3 = new wxToggleButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButtonLeague3->SetValue(false);

    flexGridSizer31->Add(m_toggleButtonLeague3, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButtonLeague4 = new wxToggleButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButtonLeague4->SetValue(false);

    flexGridSizer31->Add(m_toggleButtonLeague4, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButtonLeague5 = new wxToggleButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButtonLeague5->SetValue(false);

    flexGridSizer31->Add(m_toggleButtonLeague5, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButtonLeague6 = new wxToggleButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButtonLeague6->SetValue(false);

    flexGridSizer31->Add(m_toggleButtonLeague6, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("DialogLeaguecomposition"));
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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogLeaguecomposition::OnAbort), NULL, this);
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogLeaguecomposition::OnOk), NULL, this);
}

DialogLeaguecomposition::~DialogLeaguecomposition()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogLeaguecomposition::OnAbort), NULL, this);
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogLeaguecomposition::OnOk), NULL, this);
}

void DialogLeaguecomposition::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogLeaguecomposition::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}