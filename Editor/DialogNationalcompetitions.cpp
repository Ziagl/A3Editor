#include "DialogNationalcompetitions.h"
#include <algorithm>

DialogNationalcompetitions::DialogNationalcompetitions(wxWindow* parent, 
    Toolset* const tools, 
    const std::string selectedCountry,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(selectedCountry);
    country = tools->getCountryById(countryId);
    leagues = tools->getLeagueIdsByCountryId(countryId);
    std::sort(leagues.begin(), leagues.end(), [tools](const vertex_t aId, const vertex_t bId) -> bool
    {
        auto a = tools->getLeagueById(aId);
        auto b = tools->getLeagueById(bId);
        return a->getHierarchy() < b->getHierarchy();
    });

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("nationalCompetitions")), wxVERTICAL);

    mainSizer->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer69 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer69->SetFlexibleDirection(wxBOTH);
    flexGridSizer69->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer19->Add(flexGridSizer69, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer21 = new wxFlexGridSizer(4, 4, 0, 0);
    flexGridSizer21->SetFlexibleDirection(wxBOTH);
    flexGridSizer21->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer69->Add(flexGridSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    auto league = tools->getLeagueById(leagues.at(0));
    m_staticText31 = new wxStaticText(this, wxID_ANY, _("Name der ersten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText31, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameLeague1 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameLeague1->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlNameLeague1, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText35 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText35, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlShortnameLeague1 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlShortnameLeague1->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlShortnameLeague1, 0, wxALL, WXC_FROM_DIP(5));

    if(leagues.size() > 1)
        league = tools->getLeagueById(leagues.at(1));
    m_staticText39 = new wxStaticText(this, wxID_ANY, _("Name der zweiten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText39, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameLeague2 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameLeague2->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlNameLeague2, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText43 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText43, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlShortnameLeague2 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlShortnameLeague2->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlShortnameLeague2, 0, wxALL, WXC_FROM_DIP(5));
    if (leagues.size() <= 1)
    {
        m_staticText39->Hide();
        m_textCtrlNameLeague2->Hide();
        m_staticText43->Hide();
        m_textCtrlShortnameLeague2->Hide();
    }

    if (leagues.size() > 2 && selectedCountry != "GER")
        league = tools->getLeagueById(leagues.at(2));
    m_staticText47 = new wxStaticText(this, wxID_ANY, _("Name der dritten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText47, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameLeague3 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameLeague3->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlNameLeague3, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText51 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText51, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlShortnameLeague3 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlShortnameLeague3->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlShortnameLeague3, 0, wxALL, WXC_FROM_DIP(5));
    if (leagues.size() <= 2 || selectedCountry == "GER")
    {
        m_staticText47->Hide();
        m_textCtrlNameLeague3->Hide();
        m_staticText51->Hide();
        m_textCtrlShortnameLeague3->Hide();
    }

    if (leagues.size() > 3 && selectedCountry != "GER")
        league = tools->getLeagueById(leagues.at(3));
    m_staticText55 = new wxStaticText(this, wxID_ANY, _("Name der vierten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlNameLeague4 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlNameLeague4->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlNameLeague4, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText59 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText59, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlShortnameLeague4 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlShortnameLeague4->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlShortnameLeague4, 0, wxALL, WXC_FROM_DIP(5));
    if (leagues.size() <= 3 || selectedCountry == "GER")
    {
        m_staticText55->Hide();
        m_textCtrlNameLeague4->Hide();
        m_staticText59->Hide();
        m_textCtrlShortnameLeague4->Hide();
    }

    m_staticLine71 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLI_HORIZONTAL);

    flexGridSizer69->Add(m_staticLine71, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer73 = new wxFlexGridSizer(0, 4, 0, 0);
    flexGridSizer73->SetFlexibleDirection(wxBOTH);
    flexGridSizer73->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer69->Add(flexGridSizer73, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText27 = new wxStaticText(this, wxID_ANY, tools->translate("cupName"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer73->Add(m_staticText27, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlCupName = new wxTextCtrl(this, wxID_ANY, country->getCupName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlCupName->SetHint(wxT(""));
#endif

    flexGridSizer73->Add(m_textCtrlCupName, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY,tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("DialogNationalcompetitions"));
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
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogNationalcompetitions::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogNationalcompetitions::OnAbort), NULL, this);
}

DialogNationalcompetitions::~DialogNationalcompetitions()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogNationalcompetitions::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogNationalcompetitions::OnAbort), NULL, this);
}

void DialogNationalcompetitions::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogNationalcompetitions::OnOk(wxCommandEvent& event)
{
    country->setCupName(std::string(m_textCtrlCupName->GetValue().mb_str()));
    auto league1 = tools->getLeagueById(leagues.at(0));
    league1->setName(std::string(m_textCtrlNameLeague1->GetValue().mb_str()));
    league1->setShortname(std::string(m_textCtrlShortnameLeague1->GetValue().mb_str()));
    if (leagues.size() > 1)
    {
        auto league2 = tools->getLeagueById(leagues.at(1));
        league2->setName(std::string(m_textCtrlNameLeague2->GetValue().mb_str()));
        league2->setShortname(std::string(m_textCtrlShortnameLeague2->GetValue().mb_str()));
    }
    if (leagues.size() > 2 && selectedCountry != "GER")
    {
        auto league3 = tools->getLeagueById(leagues.at(2));
        league3->setName(std::string(m_textCtrlNameLeague3->GetValue().mb_str()));
        league3->setShortname(std::string(m_textCtrlShortnameLeague3->GetValue().mb_str()));
        if (leagues.size() > 3)
        {
            auto league4 = tools->getLeagueById(leagues.at(3));
            league4->setName(std::string(m_textCtrlNameLeague4->GetValue().mb_str()));
            league4->setShortname(std::string(m_textCtrlShortnameLeague4->GetValue().mb_str()));
        }
    }
    wxUnusedVar(event);
    Close();
}
