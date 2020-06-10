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
    auto country = tools->getCountryById(countryId);
    auto leagues = tools->getLeagueIdsByCountryId(countryId);
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

    m_textCtrl33 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl33->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl33, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText35 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText35, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl37 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl37->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl37, 0, wxALL, WXC_FROM_DIP(5));

    if(leagues.size() > 1)
        league = tools->getLeagueById(leagues.at(1));
    m_staticText39 = new wxStaticText(this, wxID_ANY, _("Name der zweiten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText39, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl41 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl41->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl41, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText43 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText43, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl45 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl45->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl45, 0, wxALL, WXC_FROM_DIP(5));
    if (leagues.size() <= 1)
    {
        m_staticText39->Hide();
        m_textCtrl41->Hide();
        m_staticText43->Hide();
        m_textCtrl45->Hide();
    }

    if (leagues.size() > 2 && selectedCountry != "GER")
        league = tools->getLeagueById(leagues.at(2));
    m_staticText47 = new wxStaticText(this, wxID_ANY, _("Name der dritten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText47, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl49 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl49->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl49, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText51 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText51, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl53 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl53->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl53, 0, wxALL, WXC_FROM_DIP(5));
    if (leagues.size() <= 2 || selectedCountry == "GER")
    {
        m_staticText47->Hide();
        m_textCtrl49->Hide();
        m_staticText51->Hide();
        m_textCtrl53->Hide();
    }

    if (leagues.size() > 3 && selectedCountry != "GER")
        league = tools->getLeagueById(leagues.at(3));
    m_staticText55 = new wxStaticText(this, wxID_ANY, _("Name der vierten Liga"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl57 = new wxTextCtrl(this, wxID_ANY, league->getName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl57->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl57, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText59 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText59, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl61 = new wxTextCtrl(this, wxID_ANY, league->getShortname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl61->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrl61, 0, wxALL, WXC_FROM_DIP(5));
    if (leagues.size() <= 3 || selectedCountry == "GER")
    {
        m_staticText55->Hide();
        m_textCtrl57->Hide();
        m_staticText59->Hide();
        m_textCtrl61->Hide();
    }

    m_staticLine71 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLI_HORIZONTAL);

    flexGridSizer69->Add(m_staticLine71, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer73 = new wxFlexGridSizer(0, 4, 0, 0);
    flexGridSizer73->SetFlexibleDirection(wxBOTH);
    flexGridSizer73->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer69->Add(flexGridSizer73, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText27 = new wxStaticText(this, wxID_ANY, tools->translate("cupName"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer73->Add(m_staticText27, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl29 = new wxTextCtrl(this, wxID_ANY, country->getCupName(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl29->SetHint(wxT(""));
#endif

    flexGridSizer73->Add(m_textCtrl29, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();

    boxSizer12->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_CANCEL,tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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
}

DialogNationalcompetitions::~DialogNationalcompetitions()
{
}
