#include "DialogUefarankingEdit.h"

DialogUefarankingEdit::DialogUefarankingEdit(wxWindow* parent,
    Toolset* const tools,
    Core::UefaTeam &team,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), team(team)
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

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("setNewScore")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer27 = new wxFlexGridSizer(7, 6, 0, 0);
    flexGridSizer27->SetFlexibleDirection(wxBOTH);
    flexGridSizer27->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer19->Add(flexGridSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wchar_t buffer[100];
    swprintf(buffer, 100, tools->translate("seasonYearsAgo").c_str(), 6);
    m_staticText29 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText29, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText31 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText31, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText6YearOld = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(0)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText6YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText35 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText35, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText6YearNew = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(0)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText6YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButtonYear6 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear6->SetRange(0, 100);
    m_spinButtonYear6->SetValue(team.years.at(0));

    flexGridSizer27->Add(m_spinButtonYear6, 0, wxALL, WXC_FROM_DIP(3));

    swprintf(buffer, 100, tools->translate("seasonYearsAgo").c_str(), 5);
    m_staticText43 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText43, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText45 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText5YearOld = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(1)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText5YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText49 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText49, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText5YearNew = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(1)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText5YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButtonYear5 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear5->SetRange(0, 100);
    m_spinButtonYear5->SetValue(team.years.at(1));

    flexGridSizer27->Add(m_spinButtonYear5, 0, wxALL, WXC_FROM_DIP(3));

    swprintf(buffer, 100, tools->translate("seasonYearsAgo").c_str(), 4);
    m_staticText55 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText57 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText4YearOld = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(2)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText4YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText61 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText61, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText4YearNew = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(2)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText4YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButtonYear4 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear4->SetRange(0, 100);
    m_spinButtonYear4->SetValue(team.years.at(2));

    flexGridSizer27->Add(m_spinButtonYear4, 0, wxALL, WXC_FROM_DIP(3));

    swprintf(buffer, 100, tools->translate("seasonYearsAgo").c_str(), 3);
    m_staticText67 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText69 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText69, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText3YearOld = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(3)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText3YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText73 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText73, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText3YearNew = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(3)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText3YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButtonYear3 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear3->SetRange(0, 100);
    m_spinButtonYear3->SetValue(team.years.at(3));

    flexGridSizer27->Add(m_spinButtonYear3, 0, wxALL, WXC_FROM_DIP(3));

    swprintf(buffer, 100, tools->translate("seasonYearsAgo").c_str(), 2);
    m_staticText79 = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText81 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText81, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText2YearOld = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(4)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText2YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText85 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText85, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText2YearNew = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(4)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText2YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButtonYear2 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear2->SetRange(0, 100);
    m_spinButtonYear2->SetValue(team.years.at(4));

    flexGridSizer27->Add(m_spinButtonYear2, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText91 = new wxStaticText(this, wxID_ANY, tools->translate("lastSeason"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText93 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText93, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextLastYearOld = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(5)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextLastYearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText97 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText97, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextLastYearNew = new wxStaticText(this, wxID_ANY, std::to_string(team.years.at(5)), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextLastYearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButtonYear1 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButtonYear1->SetRange(0, 100);
    m_spinButtonYear1->SetValue(team.years.at(5));

    flexGridSizer27->Add(m_spinButtonYear1, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText103 = new wxStaticText(this, wxID_ANY, tools->translate("totalExcludingLastSeason"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText103, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText105 = new wxStaticText(this, wxID_ANY, tools->translate("previous"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText105, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextSumOld = new wxStaticText(this, wxID_ANY, std::to_string(team.sum), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextSumOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText109 = new wxStaticText(this, wxID_ANY, "," + tools->translate("now"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText109, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextSumNew = new wxStaticText(this, wxID_ANY, std::to_string(team.sum), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextSumNew, 0, wxALL, WXC_FROM_DIP(3));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefarankingEdit::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefarankingEdit::OnAbort), NULL, this);
    // spin events
    this->Connect(m_spinButtonYear6->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear6), NULL, this);
    this->Connect(m_spinButtonYear5->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear5), NULL, this);
    this->Connect(m_spinButtonYear4->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear4), NULL, this);
    this->Connect(m_spinButtonYear3->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear3), NULL, this);
    this->Connect(m_spinButtonYear2->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear2), NULL, this);
    this->Connect(m_spinButtonYear1->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear1), NULL, this);
}

DialogUefarankingEdit::~DialogUefarankingEdit()
{
    // connect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefarankingEdit::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogUefarankingEdit::OnAbort), NULL, this);
    // spin events
    this->Disconnect(m_spinButtonYear6->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear6), NULL, this);
    this->Disconnect(m_spinButtonYear5->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear5), NULL, this);
    this->Disconnect(m_spinButtonYear4->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear4), NULL, this);
    this->Disconnect(m_spinButtonYear3->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear3), NULL, this);
    this->Disconnect(m_spinButtonYear2->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear2), NULL, this);
    this->Disconnect(m_spinButtonYear1->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogUefarankingEdit::OnYear1), NULL, this);
}

void DialogUefarankingEdit::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogUefarankingEdit::OnOk(wxCommandEvent& event)
{
    team.years.at(0) = m_spinButtonYear6->GetValue();
    team.years.at(1) = m_spinButtonYear5->GetValue();
    team.years.at(2) = m_spinButtonYear4->GetValue();
    team.years.at(3) = m_spinButtonYear3->GetValue();
    team.years.at(4) = m_spinButtonYear2->GetValue();
    team.years.at(5) = m_spinButtonYear1->GetValue();
    team.sum = team.years.at(0) + team.years.at(1) + team.years.at(2) + team.years.at(3) + team.years.at(4);
    wxUnusedVar(event);
    Close();
}

void DialogUefarankingEdit::OnYear6(wxSpinEvent& event)
{
    m_staticText6YearNew->SetLabel(std::to_string(m_spinButtonYear6->GetValue()).c_str());
    updateSum();
}

void DialogUefarankingEdit::OnYear5(wxSpinEvent& event)
{
    m_staticText5YearNew->SetLabel(std::to_string(m_spinButtonYear5->GetValue()).c_str());
    updateSum();
}

void DialogUefarankingEdit::OnYear4(wxSpinEvent& event)
{
    m_staticText4YearNew->SetLabel(std::to_string(m_spinButtonYear4->GetValue()).c_str());
    updateSum();
}

void DialogUefarankingEdit::OnYear3(wxSpinEvent& event)
{
    m_staticText3YearNew->SetLabel(std::to_string(m_spinButtonYear3->GetValue()).c_str());
    updateSum();
}

void DialogUefarankingEdit::OnYear2(wxSpinEvent& event)
{
    m_staticText2YearNew->SetLabel(std::to_string(m_spinButtonYear2->GetValue()).c_str());
    updateSum();
}

void DialogUefarankingEdit::OnYear1(wxSpinEvent& event)
{
    m_staticTextLastYearNew->SetLabel(std::to_string(m_spinButtonYear1->GetValue()).c_str());
    updateSum();
}

void DialogUefarankingEdit::updateSum()
{
    short sum = 0;
    sum += m_spinButtonYear6->GetValue();
    sum += m_spinButtonYear5->GetValue();
    sum += m_spinButtonYear4->GetValue();
    sum += m_spinButtonYear3->GetValue();
    sum += m_spinButtonYear2->GetValue();
    m_staticTextSumNew->SetLabel(std::to_string(sum));
}
