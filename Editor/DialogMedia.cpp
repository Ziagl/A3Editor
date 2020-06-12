#include "DialogMedia.h"

DialogMedia::DialogMedia(wxWindow* parent, 
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

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    m_country = tools->getCountryById(countryId);
    m_reporter = m_country->getReporter();
    m_critics = m_country->getCritics();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer126 = new wxFlexGridSizer(0, 1, 0, 0);
    flexGridSizer126->SetFlexibleDirection(wxBOTH);
    flexGridSizer126->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer126, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("reporter")), wxVERTICAL);

    flexGridSizer126->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer67 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer67->SetFlexibleDirection(wxBOTH);
    flexGridSizer67->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer67->AddGrowableCol(1);

    staticBoxSizer19->Add(flexGridSizer67, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText75 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText75, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameReporter1 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(0).getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameReporter1->SetHint(wxT(""));
#endif

    flexGridSizer67->Add(m_textCtrlNameReporter1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wchar_t buffer[100];
    _snwprintf(buffer, 100, tools->translate("mediaMood").c_str(), L"                          ");
    m_staticText115 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText115, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText79 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFirstnameReporter1 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(0).getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstnameReporter1->SetHint(wxT(""));
#endif

    flexGridSizer67->Add(m_textCtrlFirstnameReporter1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_scrollBarReporter1 = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSB_HORIZONTAL);
    m_scrollBarReporter1->SetScrollbar(0, 1, 3, 1);
    m_scrollBarReporter1->SetThumbPosition(m_reporter.at(0).getCharacter());

    flexGridSizer67->Add(m_scrollBarReporter1, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText83 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText83, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameReporter2 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(1).getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameReporter2->SetHint(wxT(""));
#endif

    flexGridSizer67->Add(m_textCtrlNameReporter2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panel119 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer67->Add(m_panel119, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText87 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText87, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFirstnameReporter2 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(1).getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstnameReporter2->SetHint(wxT(""));
#endif

    flexGridSizer67->Add(m_textCtrlFirstnameReporter2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_scrollBarReporter2 = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSB_HORIZONTAL);
    m_scrollBarReporter2->SetScrollbar(0, 1, 3, 1);
    m_scrollBarReporter2->SetThumbPosition(m_reporter.at(1).getCharacter());

    flexGridSizer67->Add(m_scrollBarReporter2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText91 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameReporter3 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(2).getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameReporter3->SetHint(wxT(""));
#endif

    flexGridSizer67->Add(m_textCtrlNameReporter3, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panel123 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer67->Add(m_panel123, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText95 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer67->Add(m_staticText95, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFirstnameReporter3 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(2).getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstnameReporter3->SetHint(wxT(""));
#endif

    flexGridSizer67->Add(m_textCtrlFirstnameReporter3, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_scrollBarReporter3 = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSB_HORIZONTAL);
    m_scrollBarReporter3->SetScrollbar(0, 1, 3, 1);
    m_scrollBarReporter3->SetThumbPosition(m_reporter.at(2).getCharacter());

    flexGridSizer67->Add(m_scrollBarReporter3, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer29 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer29->SetFlexibleDirection(wxBOTH);
    flexGridSizer29->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer126->Add(flexGridSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer31 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("critic")), wxVERTICAL);

    flexGridSizer29->Add(staticBoxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer49 = new wxFlexGridSizer(4, 2, 0, 0);
    flexGridSizer49->SetFlexibleDirection(wxBOTH);
    flexGridSizer49->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer31->Add(flexGridSizer49, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText51 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer49->Add(m_staticText51, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameCritic1 = new wxTextCtrl(this, wxID_ANY, m_critics.at(0).getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameCritic1->SetHint(wxT(""));
#endif

    flexGridSizer49->Add(m_textCtrlNameCritic1, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText55 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer49->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFirstnameCritic1 = new wxTextCtrl(this, wxID_ANY, m_critics.at(0).getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstnameCritic1->SetHint(wxT(""));
#endif

    flexGridSizer49->Add(m_textCtrlFirstnameCritic1, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText59 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer49->Add(m_staticText59, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameCritic2 = new wxTextCtrl(this, wxID_ANY, m_critics.at(1).getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameCritic2->SetHint(wxT(""));
#endif

    flexGridSizer49->Add(m_textCtrlNameCritic2, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText63 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer49->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFirstnameCritic2 = new wxTextCtrl(this, wxID_ANY, m_critics.at(1).getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstnameCritic2->SetHint(wxT(""));
#endif

    flexGridSizer49->Add(m_textCtrlFirstnameCritic2, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer33 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("tvStation")), wxVERTICAL);

    flexGridSizer29->Add(staticBoxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer35 = new wxFlexGridSizer(3, 2, 0, 0);
    flexGridSizer35->SetFlexibleDirection(wxBOTH);
    flexGridSizer35->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer33->Add(flexGridSizer35, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    _snwprintf(buffer, 100, tools->translate("number").c_str(), 1);
    m_staticText37 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText37, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStation1 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(0).getChannel(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStation1->SetHint(wxT(""));
#endif

    flexGridSizer35->Add(m_textCtrlStation1, 0, wxALL, WXC_FROM_DIP(5));

    _snwprintf(buffer, 100, tools->translate("number").c_str(), 2);
    m_staticText41 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText41, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStation2 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(1).getChannel(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStation2->SetHint(wxT(""));
#endif

    flexGridSizer35->Add(m_textCtrlStation2, 0, wxALL, WXC_FROM_DIP(5));

    _snwprintf(buffer, 100, tools->translate("number").c_str(), 3);
    m_staticText45 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlStation3 = new wxTextCtrl(this, wxID_ANY, m_reporter.at(2).getChannel(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStation3->SetHint(wxT(""));
#endif

    flexGridSizer35->Add(m_textCtrlStation3, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOK, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogMedia::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogMedia::OnAbort), NULL, this);
}

DialogMedia::~DialogMedia()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogMedia::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogMedia::OnAbort), NULL, this);
}

void DialogMedia::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogMedia::OnOk(wxCommandEvent& event)
{
    // set reporter
    m_reporter.at(0).setLastname(std::string(m_textCtrlNameReporter1->GetValue().mb_str()));
    m_reporter.at(0).setFirstname(std::string(m_textCtrlFirstnameReporter1->GetValue().mb_str()));
    m_reporter.at(0).setCharacter(m_scrollBarReporter1->GetThumbPosition());
    m_reporter.at(0).setChannel(std::string(m_textCtrlStation1->GetValue().mb_str()));
    m_reporter.at(1).setLastname(std::string(m_textCtrlNameReporter2->GetValue().mb_str()));
    m_reporter.at(1).setFirstname(std::string(m_textCtrlFirstnameReporter2->GetValue().mb_str()));
    m_reporter.at(1).setCharacter(m_scrollBarReporter2->GetThumbPosition());
    m_reporter.at(1).setChannel(std::string(m_textCtrlStation2->GetValue().mb_str()));
    m_reporter.at(2).setLastname(std::string(m_textCtrlNameReporter3->GetValue().mb_str()));
    m_reporter.at(2).setFirstname(std::string(m_textCtrlFirstnameReporter3->GetValue().mb_str()));
    m_reporter.at(2).setCharacter(m_scrollBarReporter3->GetThumbPosition());
    m_reporter.at(2).setChannel(std::string(m_textCtrlStation3->GetValue().mb_str()));
    // set critics
    m_critics.at(0).setLastname(std::string(m_textCtrlNameCritic1->GetValue().mb_str()));
    m_critics.at(0).setFirstname(std::string(m_textCtrlFirstnameCritic1->GetValue().mb_str()));
    m_critics.at(1).setLastname(std::string(m_textCtrlNameCritic2->GetValue().mb_str()));
    m_critics.at(1).setFirstname(std::string(m_textCtrlFirstnameCritic2->GetValue().mb_str()));
    // copy back to country object
    m_country->setReporter(m_reporter);
    m_country->setCritics(m_critics);
    wxUnusedVar(event);
    Close();
}