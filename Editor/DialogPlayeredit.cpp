#include "DialogPlayeredit.h"
#include <iomanip>

DialogPlayeredit::DialogPlayeredit(wxWindow* parent,
    Toolset* const tools,
    std::string selectedCountry,
    std::string selectedClub,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry), m_selectedClub(selectedClub)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    // get pointers to graph data for country, team and players
    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    auto teamIds = tools->getTeamIdsByCountryId(countryId);
    for (auto teamId : teamIds)
    {
        auto team = tools->getTeamById(teamId);
        if (team->getName() == m_selectedClub)
        {
            m_team = team;
            auto playerIds = tools->getPlayerIdsByTeamId(teamId);
            for (auto playerId : playerIds)
            {
                auto player = tools->getPlayerById(playerId);
                m_players.push_back(player);
            }
            break;
        }
    }
    computeAverageSkill();

    wxBoxSizer* boxSizer484 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer484);

    wxFlexGridSizer* flexGridSizer487 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer487->SetFlexibleDirection(wxBOTH);
    flexGridSizer487->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    boxSizer484->Add(flexGridSizer487, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer483 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer483->SetFlexibleDirection(wxBOTH);
    flexGridSizer483->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer483->AddGrowableCol(0);

    flexGridSizer487->Add(flexGridSizer483, 1, wxALL, WXC_FROM_DIP(0));

    m_listCtrlPlayer = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT);

    flexGridSizer483->Add(m_listCtrlPlayer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(0));
    m_listCtrlPlayer->SetMinSize(wxSize(-1, 500));
    initializePlayerList(m_listCtrlPlayer);

    wxFlexGridSizer* flexGridSizer488 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer488->SetFlexibleDirection(wxBOTH);
    flexGridSizer488->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer488->AddGrowableCol(1);

    flexGridSizer483->Add(flexGridSizer488, 1, wxALL | wxEXPAND | wxALIGN_LEFT, WXC_FROM_DIP(0));

    m_button147 = new wxButton(this, wxID_ANY, tools->translate("list"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer488->Add(m_button147, 0, wxALL, WXC_FROM_DIP(0));

    m_panel494 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer488->Add(m_panel494, 0, wxALL, WXC_FROM_DIP(5));

    m_button149 = new wxButton(this, wxID_ANY, tools->translate("redistributeShirtNumbers"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer488->Add(m_button149, 0, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer485 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer485->SetFlexibleDirection(wxBOTH);
    flexGridSizer485->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer487->Add(flexGridSizer485, 1, wxALL, WXC_FROM_DIP(0));

    m_notebook21 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBK_DEFAULT);
    m_notebook21->SetName(wxT("m_notebook21"));

    flexGridSizer485->Add(m_notebook21, 0, wxALL, WXC_FROM_DIP(0));

    m_panelData1 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelData1, _("Daten 1"), false);

    wxFlexGridSizer* flexGridSizer495 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer495->SetFlexibleDirection(wxBOTH);
    flexGridSizer495->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    m_panelData1->SetSizer(flexGridSizer495);

    wxStaticBoxSizer* staticBoxSizer35 = new wxStaticBoxSizer(new wxStaticBox(m_panelData1, wxID_ANY, _("Persönliche Daten 1")), wxVERTICAL);

    flexGridSizer495->Add(staticBoxSizer35, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText37 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    staticBoxSizer35->Add(m_staticText37, 0, wxALL, WXC_FROM_DIP(0));

    m_textCtrlName = new wxTextCtrl(m_panelData1, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlName->SetHint(wxT(""));
#endif

    staticBoxSizer35->Add(m_textCtrlName, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText41 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("stagename"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    staticBoxSizer35->Add(m_staticText41, 0, wxALL, WXC_FROM_DIP(0));

    m_textCtrlStagename = new wxTextCtrl(m_panelData1, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlStagename->SetHint(wxT(""));
#endif

    staticBoxSizer35->Add(m_textCtrlStagename, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText45 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    staticBoxSizer35->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(0));

    m_textCtrlFirstname = new wxTextCtrl(m_panelData1, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFirstname->SetHint(wxT(""));
#endif

    staticBoxSizer35->Add(m_textCtrlFirstname, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer421 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer35->Add(boxSizer421, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxGridSizer* gridSizer443 = new wxGridSizer(2, 2, 0, 0);

    boxSizer421->Add(gridSizer443, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxBoxSizer* boxSizer447 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer443->Add(boxSizer447, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText455 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer447->Add(m_staticText455, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextDay = new wxStaticText(m_panelData1, wxID_ANY, _("5"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer447->Add(m_staticTextDay, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonDay = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonDay->SetRange(1, 31);
    m_spinButtonDay->SetValue(1);

    boxSizer447->Add(m_spinButtonDay, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer449 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer443->Add(boxSizer449, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticTextMonth = new wxStaticText(m_panelData1, wxID_ANY, _("7"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer449->Add(m_staticTextMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonMonth = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonMonth->SetRange(1, 12);
    m_spinButtonMonth->SetValue(1);

    boxSizer449->Add(m_spinButtonMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextYear = new wxStaticText(m_panelData1, wxID_ANY, _("1964"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer449->Add(m_staticTextYear, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonYear = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonYear->SetRange(0, 100);
    m_spinButtonYear->SetValue(0);

    boxSizer449->Add(m_spinButtonYear, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer451 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer443->Add(boxSizer451, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText469 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("skill"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer451->Add(m_staticText469, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextSkill = new wxStaticText(m_panelData1, wxID_ANY, _("11"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer451->Add(m_staticTextSkill, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonSkill = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonSkill->SetRange(1, tools->getMaxSkill());
    m_spinButtonSkill->SetValue(1);

    boxSizer451->Add(m_spinButtonSkill, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer453 = new wxBoxSizer(wxHORIZONTAL);

    gridSizer443->Add(boxSizer453, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText475 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("age"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer453->Add(m_staticText475, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextAge = new wxStaticText(m_panelData1, wxID_ANY, _("34"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer453->Add(m_staticTextAge, 0, wxALL, WXC_FROM_DIP(5));

    m_button445 = new wxButton(m_panelData1, wxID_ANY, _("Spieler\ndoppelt?"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer421->Add(m_button445, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer423 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer423->SetFlexibleDirection(wxBOTH);
    flexGridSizer423->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer35->Add(flexGridSizer423, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText425 = new wxStaticText(m_panelData1, wxID_ANY, _("Talent"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticText425, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextTalent = new wxStaticText(m_panelData1, wxID_ANY, _("Normal begabt"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticTextTalent, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_spinButton429 = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton429->SetRange(0, 100);
    m_spinButton429->SetValue(0);

    flexGridSizer423->Add(m_spinButton429, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText431 = new wxStaticText(m_panelData1, wxID_ANY, _("Starker Fuß"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticText431, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextStrongFoot = new wxStaticText(m_panelData1, wxID_ANY, _("Links"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticTextStrongFoot, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_spinButton435 = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton435->SetRange(0, 100);
    m_spinButton435->SetValue(0);

    flexGridSizer423->Add(m_spinButton435, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText437 = new wxStaticText(m_panelData1, wxID_ANY, _("Rückennummer"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticText437, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextShirtNumber = new wxStaticText(m_panelData1, wxID_ANY, _("99"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticTextShirtNumber, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_spinButton441 = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton441->SetRange(0, 100);
    m_spinButton441->SetValue(0);

    flexGridSizer423->Add(m_spinButton441, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer479 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer495->Add(boxSizer479, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText55 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("averageStrengthOfAllPlayers"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer479->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText481 = new wxStaticText(m_panelData1, wxID_ANY, std::to_string(m_averageSkill), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer479->Add(m_staticText481, 0, wxALL, WXC_FROM_DIP(5));

    m_panelData2 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelData2, _("Daten 2"), false);

    wxStaticBoxSizer* staticBoxSizer514 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, _("Persönliche Daten 2")), wxVERTICAL);
    m_panelData2->SetSizer(staticBoxSizer514);

    m_staticText59 = new wxStaticText(m_panelData2, wxID_ANY, _("Nationalität"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);

    staticBoxSizer514->Add(m_staticText59, 0, wxALL, WXC_FROM_DIP(0));

    wxArrayString m_choice61Arr;
    m_choice61 = new wxChoice(m_panelData2, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), m_choice61Arr, 0);

    staticBoxSizer514->Add(m_choice61, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText63 = new wxStaticText(m_panelData2, wxID_ANY, _("Zweite Nationalität"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);

    staticBoxSizer514->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(0));

    wxArrayString m_choice65Arr;
    m_choice65 = new wxChoice(m_panelData2, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), m_choice65Arr, 0);

    staticBoxSizer514->Add(m_choice65, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer519 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer514->Add(boxSizer519, 0, wxALL, WXC_FROM_DIP(5));

    m_checkNational = new wxCheckBox(m_panelData2, wxID_ANY, _("Fußballinländer"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkNational->SetValue(false);

    boxSizer519->Add(m_checkNational, 0, wxALL, WXC_FROM_DIP(5));

    m_checkNationalplayer = new wxCheckBox(m_panelData2, wxID_ANY, _("Nationalspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkNationalplayer->SetValue(false);

    boxSizer519->Add(m_checkNationalplayer, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer521 = new wxBoxSizer(wxVERTICAL);

    staticBoxSizer514->Add(boxSizer521, 0, wxALL, WXC_FROM_DIP(5));

    m_checkNationalresigned = new wxCheckBox(m_panelData2, wxID_ANY, _("Aus Nationalmannschaft zurückgetreten"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkNationalresigned->SetValue(false);

    boxSizer521->Add(m_checkNationalresigned, 0, wxALL, WXC_FROM_DIP(5));

    m_checkCaptainresigned = new wxCheckBox(m_panelData2, wxID_ANY, _("Als Kapitän zurückgetreten"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkCaptainresigned->SetValue(false);

    boxSizer521->Add(m_checkCaptainresigned, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer520 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer514->Add(boxSizer520, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer93 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, _("Hautfarbe")), wxVERTICAL);

    boxSizer520->Add(staticBoxSizer93, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioBright = new wxRadioButton(m_panelData2, wxID_ANY, _("hell"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBright->SetValue(1);

    staticBoxSizer93->Add(m_radioBright, 0, wxALL, WXC_FROM_DIP(0));

    m_radioDark = new wxRadioButton(m_panelData2, wxID_ANY, _("dunkel"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioDark->SetValue(1);

    staticBoxSizer93->Add(m_radioDark, 0, wxALL, WXC_FROM_DIP(0));

    m_radioAfrikan = new wxRadioButton(m_panelData2, wxID_ANY, _("schwarz"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioAfrikan->SetValue(1);

    staticBoxSizer93->Add(m_radioAfrikan, 0, wxALL, WXC_FROM_DIP(0));

    m_radioAsian = new wxRadioButton(m_panelData2, wxID_ANY, _("asiatisch"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioAsian->SetValue(1);

    staticBoxSizer93->Add(m_radioAsian, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer95 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, _("Haartyp")), wxVERTICAL);

    boxSizer520->Add(staticBoxSizer95, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioExtremelyshort = new wxRadioButton(m_panelData2, wxID_ANY, _("extrem kurz"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioExtremelyshort->SetValue(1);

    staticBoxSizer95->Add(m_radioExtremelyshort, 0, wxALL, WXC_FROM_DIP(0));

    m_radioShort = new wxRadioButton(m_panelData2, wxID_ANY, _("kurz"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioShort->SetValue(1);

    staticBoxSizer95->Add(m_radioShort, 0, wxALL, WXC_FROM_DIP(0));

    m_radioCurly = new wxRadioButton(m_panelData2, wxID_ANY, _("Wuschelkopf"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioCurly->SetValue(1);

    staticBoxSizer95->Add(m_radioCurly, 0, wxALL, WXC_FROM_DIP(0));

    m_radioLong = new wxRadioButton(m_panelData2, wxID_ANY, _("lang"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioLong->SetValue(1);

    staticBoxSizer95->Add(m_radioLong, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer97 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, _("Bart")), wxVERTICAL);

    boxSizer520->Add(staticBoxSizer97, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkUnshaved = new wxCheckBox(m_panelData2, wxID_ANY, _("unrasiert"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkUnshaved->SetValue(false);

    staticBoxSizer97->Add(m_checkUnshaved, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBeard = new wxCheckBox(m_panelData2, wxID_ANY, _("Bart"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkBeard->SetValue(false);

    staticBoxSizer97->Add(m_checkBeard, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMoustache = new wxCheckBox(m_panelData2, wxID_ANY, _("Schnurrbart"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkMoustache->SetValue(false);

    staticBoxSizer97->Add(m_checkMoustache, 0, wxALL, WXC_FROM_DIP(0));

    m_checkGoatee = new wxCheckBox(m_panelData2, wxID_ANY, _("Ziegenbart"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkGoatee->SetValue(false);

    staticBoxSizer97->Add(m_checkGoatee, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer99 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, _("Haarfarbe")), wxVERTICAL);

    staticBoxSizer514->Add(staticBoxSizer99, 1, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer125 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer125->SetFlexibleDirection(wxBOTH);
    flexGridSizer125->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer99->Add(flexGridSizer125, 1, wxALL, WXC_FROM_DIP(5));

    m_radioLightblonde = new wxRadioButton(m_panelData2, wxID_ANY, _("hellblond"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioLightblonde->SetValue(1);

    flexGridSizer125->Add(m_radioLightblonde, 0, wxALL, WXC_FROM_DIP(0));

    m_radioRed = new wxRadioButton(m_panelData2, wxID_ANY, _("rot"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioRed->SetValue(1);

    flexGridSizer125->Add(m_radioRed, 0, wxALL, WXC_FROM_DIP(0));

    m_radioGrey = new wxRadioButton(m_panelData2, wxID_ANY, _("grau"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioGrey->SetValue(1);

    flexGridSizer125->Add(m_radioGrey, 0, wxALL, WXC_FROM_DIP(0));

    m_radioBlond = new wxRadioButton(m_panelData2, wxID_ANY, _("blond"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBlond->SetValue(1);

    flexGridSizer125->Add(m_radioBlond, 0, wxALL, WXC_FROM_DIP(0));

    m_radioBlack = new wxRadioButton(m_panelData2, wxID_ANY, _("schwarz"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBlack->SetValue(1);

    flexGridSizer125->Add(m_radioBlack, 0, wxALL, WXC_FROM_DIP(0));

    flexGridSizer125->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_radioBrown = new wxRadioButton(m_panelData2, wxID_ANY, _("braun"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBrown->SetValue(1);

    flexGridSizer125->Add(m_radioBrown, 0, wxALL, WXC_FROM_DIP(0));

    m_radioBald = new wxRadioButton(m_panelData2, wxID_ANY, _("Glatze"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBald->SetValue(1);

    flexGridSizer125->Add(m_radioBald, 0, wxALL, WXC_FROM_DIP(0));

    m_panelPositions = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelPositions, _("Positionen"), false);

    wxBoxSizer* boxSizer157 = new wxBoxSizer(wxHORIZONTAL);
    m_panelPositions->SetSizer(boxSizer157);

    wxStaticBoxSizer* staticBoxSizer159 = new wxStaticBoxSizer(new wxStaticBox(m_panelPositions, wxID_ANY, _("Hauptpositionen")), wxVERTICAL);

    boxSizer157->Add(staticBoxSizer159, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioButtonMainGoalkeeper = new wxRadioButton(m_panelPositions, wxID_ANY, _("Torwart"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioButtonMainGoalkeeper->SetValue(1);

    staticBoxSizer159->Add(m_radioButtonMainGoalkeeper, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonMainSweeper = new wxRadioButton(m_panelPositions, wxID_ANY, _("Libero"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioButtonMainSweeper->SetValue(1);

    staticBoxSizer159->Add(m_radioButtonMainSweeper, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainCenterback = new wxRadioButton(m_panelPositions, wxID_ANY, _("Innenverteidiger"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainCenterback->SetValue(1);

    staticBoxSizer159->Add(m_radioMainCenterback, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainLeftdefender = new wxRadioButton(m_panelPositions, wxID_ANY, _("linker Verteidiger"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainLeftdefender->SetValue(1);

    staticBoxSizer159->Add(m_radioMainLeftdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainRightdefender = new wxRadioButton(m_panelPositions, wxID_ANY, _("rechter Verteidiger"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainRightdefender->SetValue(1);

    staticBoxSizer159->Add(m_radioMainRightdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainDefensivemidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, _("defensiver Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainDefensivemidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainDefensivemidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainLeftmidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, _("linker Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainLeftmidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainLeftmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainRightmidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, _("rechter Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainRightmidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainRightmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainAttackingmidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, _("offensiver Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainAttackingmidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainAttackingmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainForward = new wxRadioButton(m_panelPositions, wxID_ANY, _("Stürmer"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainForward->SetValue(1);

    staticBoxSizer159->Add(m_radioMainForward, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer161 = new wxStaticBoxSizer(new wxStaticBox(m_panelPositions, wxID_ANY, _("Nebenpositionen")), wxVERTICAL);

    boxSizer157->Add(staticBoxSizer161, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkBoxSecondarySweeper = new wxCheckBox(m_panelPositions, wxID_ANY, _("Libero"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondarySweeper->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondarySweeper, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryCenterback = new wxCheckBox(m_panelPositions, wxID_ANY, _("Innenverteidiger"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryCenterback->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryCenterback, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryLeftdefender = new wxCheckBox(m_panelPositions, wxID_ANY, _("linker Verteidiger"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryLeftdefender->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryLeftdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryRightdefender = new wxCheckBox(m_panelPositions, wxID_ANY, _("rechter Verteidiger"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryRightdefender->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryRightdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryDefensivemidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, _("defensiver Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryDefensivemidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryDefensivemidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryLeftmidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, _("linker Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryLeftmidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryLeftmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryRightmidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, _("rechter Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryRightmidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryRightmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryAttackingmidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, _("offensiver Mittelfeldspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryAttackingmidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryAttackingmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSecondaryForward = new wxCheckBox(m_panelPositions, wxID_ANY, _("Stürmer"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkSecondaryForward->SetValue(false);

    staticBoxSizer161->Add(m_checkSecondaryForward, 0, wxALL, WXC_FROM_DIP(0));

    m_panelSkills = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelSkills, _("Fähigkeiten"), false);

    wxBoxSizer* boxSizer207 = new wxBoxSizer(wxHORIZONTAL);
    m_panelSkills->SetSizer(boxSizer207);

    wxStaticBoxSizer* staticBoxSizer209 = new wxStaticBoxSizer(new wxStaticBox(m_panelSkills, wxID_ANY, _("Feldspieler")), wxVERTICAL);

    boxSizer207->Add(staticBoxSizer209, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer213 = new wxFlexGridSizer(17, 2, 0, 0);
    flexGridSizer213->SetFlexibleDirection(wxBOTH);
    flexGridSizer213->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer209->Add(flexGridSizer213, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText279 = new wxStaticText(m_panelSkills, wxID_ANY, _("+"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer213->Add(m_staticText279, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText281 = new wxStaticText(m_panelSkills, wxID_ANY, _("-"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer213->Add(m_staticText281, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusHeader = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusHeader->SetValue(false);

    flexGridSizer213->Add(m_checkPlusHeader, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusHeader = new wxCheckBox(m_panelSkills, wxID_ANY, _("Kopfball"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusHeader->SetValue(false);

    flexGridSizer213->Add(m_checkMinusHeader, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusDuel = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusDuel->SetValue(false);

    flexGridSizer213->Add(m_checkPlusDuel, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusDuel = new wxCheckBox(m_panelSkills, wxID_ANY, _("Zweikampf"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusDuel->SetValue(false);

    flexGridSizer213->Add(m_checkMinusDuel, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusSpeed = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusSpeed->SetValue(false);

    flexGridSizer213->Add(m_checkPlusSpeed, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusSpeed = new wxCheckBox(m_panelSkills, wxID_ANY, _("Schnelligkeit"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusSpeed->SetValue(false);

    flexGridSizer213->Add(m_checkMinusSpeed, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusSurpluspower = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusSurpluspower->SetValue(false);

    flexGridSizer213->Add(m_checkPlusSurpluspower, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusSurpluspower = new wxCheckBox(m_panelSkills, wxID_ANY, _("Schußkraft"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusSurpluspower->SetValue(false);

    flexGridSizer213->Add(m_checkMinusSurpluspower, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusPenalty = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusPenalty->SetValue(false);

    flexGridSizer213->Add(m_checkPlusPenalty, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusPenalty = new wxCheckBox(m_panelSkills, wxID_ANY, _("Elfmeter"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusPenalty->SetValue(false);

    flexGridSizer213->Add(m_checkMinusPenalty, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusFreekicks = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusFreekicks->SetValue(false);

    flexGridSizer213->Add(m_checkPlusFreekicks, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusFreekicks = new wxCheckBox(m_panelSkills, wxID_ANY, _("Freistöße"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusFreekicks->SetValue(false);

    flexGridSizer213->Add(m_checkMinusFreekicks, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusFlanks = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusFlanks->SetValue(false);

    flexGridSizer213->Add(m_checkPlusFlanks, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusFlanks = new wxCheckBox(m_panelSkills, wxID_ANY, _("Flanken"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusFlanks->SetValue(false);

    flexGridSizer213->Add(m_checkMinusFlanks, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusGoalinstincts = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusGoalinstincts->SetValue(false);

    flexGridSizer213->Add(m_checkPlusGoalinstincts, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusGoalinstinkts = new wxCheckBox(m_panelSkills, wxID_ANY, _("Torinstinkt"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusGoalinstinkts->SetValue(false);

    flexGridSizer213->Add(m_checkMinusGoalinstinkts, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusWorkrate = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusWorkrate->SetValue(false);

    flexGridSizer213->Add(m_checkPlusWorkrate, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusWorkrate = new wxCheckBox(m_panelSkills, wxID_ANY, _("Laufstärke"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusWorkrate->SetValue(false);

    flexGridSizer213->Add(m_checkMinusWorkrate, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusTechnique = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusTechnique->SetValue(false);

    flexGridSizer213->Add(m_checkPlusTechnique, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusTechnique = new wxCheckBox(m_panelSkills, wxID_ANY, _("Technik"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusTechnique->SetValue(false);

    flexGridSizer213->Add(m_checkMinusTechnique, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusBallmagic = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusBallmagic->SetValue(false);

    flexGridSizer213->Add(m_checkPlusBallmagic, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusBallmagic = new wxCheckBox(m_panelSkills, wxID_ANY, _("Ballzauber"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusBallmagic->SetValue(false);

    flexGridSizer213->Add(m_checkMinusBallmagic, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusPlaymaker = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusPlaymaker->SetValue(false);

    flexGridSizer213->Add(m_checkPlusPlaymaker, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusPlaymaker = new wxCheckBox(m_panelSkills, wxID_ANY, _("Spielmacher"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusPlaymaker->SetValue(false);

    flexGridSizer213->Add(m_checkMinusPlaymaker, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusFoursomechain = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusFoursomechain->SetValue(false);

    flexGridSizer213->Add(m_checkPlusFoursomechain, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusFoursomechain = new wxCheckBox(m_panelSkills, wxID_ANY, _("Viererkette"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusFoursomechain->SetValue(false);

    flexGridSizer213->Add(m_checkMinusFoursomechain, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusGamesummary = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusGamesummary->SetValue(false);

    flexGridSizer213->Add(m_checkPlusGamesummary, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusGamesummary = new wxCheckBox(m_panelSkills, wxID_ANY, _("Spielübersicht"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusGamesummary->SetValue(false);

    flexGridSizer213->Add(m_checkMinusGamesummary, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusHoldball = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusHoldball->SetValue(false);

    flexGridSizer213->Add(m_checkPlusHoldball, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusHoldball = new wxCheckBox(m_panelSkills, wxID_ANY, _("Ball halten"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusHoldball->SetValue(false);

    flexGridSizer213->Add(m_checkMinusHoldball, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusDribbling = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusDribbling->SetValue(false);

    flexGridSizer213->Add(m_checkPlusDribbling, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusDribbling = new wxCheckBox(m_panelSkills, wxID_ANY, _("Dribbling"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusDribbling->SetValue(false);

    flexGridSizer213->Add(m_checkMinusDribbling, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer211 = new wxStaticBoxSizer(new wxStaticBox(m_panelSkills, wxID_ANY, _("Torwart")), wxVERTICAL);

    boxSizer207->Add(staticBoxSizer211, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer283 = new wxFlexGridSizer(10, 2, 0, 0);
    flexGridSizer283->SetFlexibleDirection(wxBOTH);
    flexGridSizer283->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer211->Add(flexGridSizer283, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText285 = new wxStaticText(m_panelSkills, wxID_ANY, _("+"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer283->Add(m_staticText285, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText287 = new wxStaticText(m_panelSkills, wxID_ANY, _("-"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer283->Add(m_staticText287, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusPenaltykiller = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusPenaltykiller->SetValue(false);

    flexGridSizer283->Add(m_checkPlusPenaltykiller, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusPenaltykiller = new wxCheckBox(m_panelSkills, wxID_ANY, _("Elfmetertöter"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusPenaltykiller->SetValue(false);

    flexGridSizer283->Add(m_checkMinusPenaltykiller, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusStrongreflexes = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusStrongreflexes->SetValue(false);

    flexGridSizer283->Add(m_checkPlusStrongreflexes, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusStrongreflexes = new wxCheckBox(m_panelSkills, wxID_ANY, _("starke Reflexe"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusStrongreflexes->SetValue(false);

    flexGridSizer283->Add(m_checkMinusStrongreflexes, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusRunningout = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusRunningout->SetValue(false);

    flexGridSizer283->Add(m_checkPlusRunningout, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusRunningout = new wxCheckBox(m_panelSkills, wxID_ANY, _("Herauslaufen"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusRunningout->SetValue(false);

    flexGridSizer283->Add(m_checkMinusRunningout, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusFlanksGoalkeeper = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusFlanksGoalkeeper->SetValue(false);

    flexGridSizer283->Add(m_checkPlusFlanksGoalkeeper, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusFlanksGoalkeeper = new wxCheckBox(m_panelSkills, wxID_ANY, _("Flanken"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusFlanksGoalkeeper->SetValue(false);

    flexGridSizer283->Add(m_checkMinusFlanksGoalkeeper, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusFist = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusFist->SetValue(false);

    flexGridSizer283->Add(m_checkPlusFist, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusFist = new wxCheckBox(m_panelSkills, wxID_ANY, _("Fausten"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusFist->SetValue(false);

    flexGridSizer283->Add(m_checkMinusFist, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusBallsecurity = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusBallsecurity->SetValue(false);

    flexGridSizer283->Add(m_checkPlusBallsecurity, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusBallsecurity = new wxCheckBox(m_panelSkills, wxID_ANY, _("Ballsicherheit"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusBallsecurity->SetValue(false);

    flexGridSizer283->Add(m_checkMinusBallsecurity, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusSpeedGoalkeeper = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusSpeedGoalkeeper->SetValue(false);

    flexGridSizer283->Add(m_checkPlusSpeedGoalkeeper, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusSpeedGoalkeeper = new wxCheckBox(m_panelSkills, wxID_ANY, _("Schnelligkeit"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusSpeedGoalkeeper->SetValue(false);

    flexGridSizer283->Add(m_checkMinusSpeedGoalkeeper, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusLongpunts = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusLongpunts->SetValue(false);

    flexGridSizer283->Add(m_checkPlusLongpunts, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusLongpunts = new wxCheckBox(m_panelSkills, wxID_ANY, _("weite Abschläge"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusLongpunts->SetValue(false);

    flexGridSizer283->Add(m_checkMinusLongpunts, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPlusLongdrops = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkPlusLongdrops->SetValue(false);

    flexGridSizer283->Add(m_checkPlusLongdrops, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMinusLongdrops = new wxCheckBox(m_panelSkills, wxID_ANY, _("weite Abwürfe"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
    m_checkMinusLongdrops->SetValue(false);

    flexGridSizer283->Add(m_checkMinusLongdrops, 0, wxALL, WXC_FROM_DIP(0));

    m_panelCharacteristics1 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelCharacteristics1, _("Eig. 1"), false);

    wxBoxSizer* boxSizer351 = new wxBoxSizer(wxHORIZONTAL);
    m_panelCharacteristics1->SetSizer(boxSizer351);

    wxStaticBoxSizer* staticBoxSizer353 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics1, wxID_ANY, _("Eigenschaften")), wxVERTICAL);

    boxSizer351->Add(staticBoxSizer353, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkFighter = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Kämpfernatur"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkFighter->SetValue(false);

    staticBoxSizer353->Add(m_checkFighter, 0, wxALL, WXC_FROM_DIP(0));

    m_checkTrainingworldchampion = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Trainingsweltmeister"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkTrainingworldchampion->SetValue(false);

    staticBoxSizer353->Add(m_checkTrainingworldchampion, 0, wxALL, WXC_FROM_DIP(0));

    m_checkTraininglazyplayer = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("trainingsfauler Spieler"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkTraininglazyplayer->SetValue(false);

    staticBoxSizer353->Add(m_checkTraininglazyplayer, 0, wxALL, WXC_FROM_DIP(0));

    m_checkViolator = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Treter"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkViolator->SetValue(false);

    staticBoxSizer353->Add(m_checkViolator, 0, wxALL, WXC_FROM_DIP(0));

    m_checkFairplayer = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("fairer Spieler"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkFairplayer->SetValue(false);

    staticBoxSizer353->Add(m_checkFairplayer, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMimosa = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Mimose"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkMimosa->SetValue(false);

    staticBoxSizer353->Add(m_checkMimosa, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSlyfox = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Schlitzohr"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkSlyfox->SetValue(false);

    staticBoxSizer353->Add(m_checkSlyfox, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSpecialist = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Spezialist"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkSpecialist->SetValue(false);

    staticBoxSizer353->Add(m_checkSpecialist, 0, wxALL, WXC_FROM_DIP(0));

    m_checkAllrounder = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Allrounder"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkAllrounder->SetValue(false);

    staticBoxSizer353->Add(m_checkAllrounder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkFlexibleplayer = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("flexibler Spieler"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkFlexibleplayer->SetValue(false);

    staticBoxSizer353->Add(m_checkFlexibleplayer, 0, wxALL, WXC_FROM_DIP(0));

    m_checkRefereefavorite = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Schiriliebling"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkRefereefavorite->SetValue(false);

    staticBoxSizer353->Add(m_checkRefereefavorite, 0, wxALL, WXC_FROM_DIP(0));

    m_checkHomeplayer = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Heimspieler"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkHomeplayer->SetValue(false);

    staticBoxSizer353->Add(m_checkHomeplayer, 0, wxALL, WXC_FROM_DIP(0));

    m_checkFairweatherplayer = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Schönwetterfußballer"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkFairweatherplayer->SetValue(false);

    staticBoxSizer353->Add(m_checkFairweatherplayer, 0, wxALL, WXC_FROM_DIP(0));

    m_checkJoker = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Joker"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkJoker->SetValue(false);

    staticBoxSizer353->Add(m_checkJoker, 0, wxALL, WXC_FROM_DIP(0));

    m_checkEgoist = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Egoist"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkEgoist->SetValue(false);

    staticBoxSizer353->Add(m_checkEgoist, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBrotherlightfooted = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Bruder Leichtfuß"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkBrotherlightfooted->SetValue(false);

    staticBoxSizer353->Add(m_checkBrotherlightfooted, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer355 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics1, wxID_ANY, _("Charakter")), wxVERTICAL);

    boxSizer351->Add(staticBoxSizer355, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkLeader = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Führungsperson"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkLeader->SetValue(false);

    staticBoxSizer355->Add(m_checkLeader, 0, wxALL, WXC_FROM_DIP(0));

    m_checkHothead = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Hitzkopf"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkHothead->SetValue(false);

    staticBoxSizer355->Add(m_checkHothead, 0, wxALL, WXC_FROM_DIP(0));

    m_checkHappynature = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Frohnatur"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkHappynature->SetValue(false);

    staticBoxSizer355->Add(m_checkHappynature, 0, wxALL, WXC_FROM_DIP(0));

    m_checkManwithoutnerves = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Mann ohne Nerven"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkManwithoutnerves->SetValue(false);

    staticBoxSizer355->Add(m_checkManwithoutnerves, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBundleofnerves = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Nervenbündel"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkBundleofnerves->SetValue(false);

    staticBoxSizer355->Add(m_checkBundleofnerves, 0, wxALL, WXC_FROM_DIP(0));

    m_checkPhlegmatic = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Phlegmatiker"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkPhlegmatic->SetValue(false);

    staticBoxSizer355->Add(m_checkPhlegmatic, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMoneyvolture = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Geldgeier"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkMoneyvolture->SetValue(false);

    staticBoxSizer355->Add(m_checkMoneyvolture, 0, wxALL, WXC_FROM_DIP(0));

    m_checkClubsupporter = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Vereinsanhänger"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkClubsupporter->SetValue(false);

    staticBoxSizer355->Add(m_checkClubsupporter, 0, wxALL, WXC_FROM_DIP(0));

    m_checkProfessionalpattern = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Musterprofi"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkProfessionalpattern->SetValue(false);

    staticBoxSizer355->Add(m_checkProfessionalpattern, 0, wxALL, WXC_FROM_DIP(0));

    m_checkScandalnoodle = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Skandalnudel"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkScandalnoodle->SetValue(false);

    staticBoxSizer355->Add(m_checkScandalnoodle, 0, wxALL, WXC_FROM_DIP(0));

    m_checkSensitive = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Sensibelchen"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkSensitive->SetValue(false);

    staticBoxSizer355->Add(m_checkSensitive, 0, wxALL, WXC_FROM_DIP(0));

    m_checkAirsandgraces = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Starallüren"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkAirsandgraces->SetValue(false);

    staticBoxSizer355->Add(m_checkAirsandgraces, 0, wxALL, WXC_FROM_DIP(0));

    m_checkTeenstar = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Teenie-Star"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkTeenstar->SetValue(false);

    staticBoxSizer355->Add(m_checkTeenstar, 0, wxALL, WXC_FROM_DIP(0));

    m_checkTroublemaker = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Unruhestifter"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkTroublemaker->SetValue(false);

    staticBoxSizer355->Add(m_checkTroublemaker, 0, wxALL, WXC_FROM_DIP(0));

    m_checkLiverwurst = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Leberwurst"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkLiverwurst->SetValue(false);

    staticBoxSizer355->Add(m_checkLiverwurst, 0, wxALL, WXC_FROM_DIP(0));

    m_checkUnifyingfigure = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, _("Integrationsfigur"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics1, wxSize(-1, -1)), 0);
    m_checkUnifyingfigure->SetValue(false);

    staticBoxSizer355->Add(m_checkUnifyingfigure, 0, wxALL, WXC_FROM_DIP(0));

    m_panelCharacteristics2 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelCharacteristics2, _("Eig. 2"), false);

    wxBoxSizer* boxSizer325 = new wxBoxSizer(wxHORIZONTAL);
    m_panelCharacteristics2->SetSizer(boxSizer325);

    wxStaticBoxSizer* staticBoxSizer327 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics2, wxID_ANY, _("Gesundheitszustand")), wxVERTICAL);

    boxSizer325->Add(staticBoxSizer327, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioNormal = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("normal"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioNormal->SetValue(1);

    staticBoxSizer327->Add(m_radioNormal, 0, wxALL, WXC_FROM_DIP(0));

    m_radioRobust = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("robust"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioRobust->SetValue(1);

    staticBoxSizer327->Add(m_radioRobust, 0, wxALL, WXC_FROM_DIP(0));

    m_radioSusceptible = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("anfällig"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioSusceptible->SetValue(1);

    staticBoxSizer327->Add(m_radioSusceptible, 0, wxALL, WXC_FROM_DIP(0));

    m_radioKneeproblems = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("Knieprobleme"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioKneeproblems->SetValue(1);

    staticBoxSizer327->Add(m_radioKneeproblems, 0, wxALL, WXC_FROM_DIP(0));

    m_radioQuicklyfitagain = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("schnell wieder fit"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioQuicklyfitagain->SetValue(1);

    staticBoxSizer327->Add(m_radioQuicklyfitagain, 0, wxALL, WXC_FROM_DIP(0));

    m_radioLastsuntilfitagain = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("dauert bis wieder fit"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioLastsuntilfitagain->SetValue(1);

    staticBoxSizer327->Add(m_radioLastsuntilfitagain, 0, wxALL, WXC_FROM_DIP(0));

    m_radioSnivelling = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("wehleidig"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioSnivelling->SetValue(1);

    staticBoxSizer327->Add(m_radioSnivelling, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer329 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics2, wxID_ANY, _("Publikum")), wxVERTICAL);

    boxSizer325->Add(staticBoxSizer329, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioAudiencenormal = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("normal"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioAudiencenormal->SetValue(1);

    staticBoxSizer329->Add(m_radioAudiencenormal, 0, wxALL, WXC_FROM_DIP(0));

    m_radioAudiencefavorite = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("Liebling"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioAudiencefavorite->SetValue(1);

    staticBoxSizer329->Add(m_radioAudiencefavorite, 0, wxALL, WXC_FROM_DIP(0));

    m_radioAudiencehatefigure = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, _("Hassfigur"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioAudiencehatefigure->SetValue(1);

    staticBoxSizer329->Add(m_radioAudiencehatefigure, 0, wxALL, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer511 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer511->SetFlexibleDirection(wxBOTH);
    flexGridSizer511->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer485->Add(flexGridSizer511, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText155 = new wxStaticText(this, wxID_ANY, _("Klicken Sie mit der rechten Maustaste\nin die Spielerliste, um Spieler neu\neinzugeben oder zu löschen!"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer511->Add(m_staticText155, 0, wxALL, WXC_FROM_DIP(0));

    wxBoxSizer* boxSizer145 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer511->Add(boxSizer145, 1, wxALL | wxEXPAND | wxALIGN_BOTTOM, WXC_FROM_DIP(0));

    m_buttonOK = new wxButton(this, wxID_OK, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();

    boxSizer145->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_CANCEL, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer145->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));


    /*#if wxVERSION_NUMBER >= 2900
        if (!wxPersistenceManager::Get().Find(m_notebook21)) {
            wxPersistenceManager::Get().RegisterAndRestore(m_notebook21);
        }
        else {
            wxPersistenceManager::Get().Restore(m_notebook21);
        }
    #endif*/

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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnAbort), NULL, this);
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnOk), NULL, this);
    // list events
    this->Connect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPlayeredit::OnSelectPerson), NULL, this);
}

DialogPlayeredit::~DialogPlayeredit()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnAbort), NULL, this);
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnOk), NULL, this);
    // list events
    this->Disconnect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPlayeredit::OnSelectPerson), NULL, this);
}

void DialogPlayeredit::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogPlayeredit::OnOk(wxCommandEvent& event)
{
    //###TODO###
    wxUnusedVar(event);
    Close();
}

void DialogPlayeredit::OnSelectPerson(wxListEvent& event)
{
    m_selectedPerson = m_listCtrlPlayer->GetItemText(event.m_itemIndex, 1);
    populatePerson();
}

// fill all controls of current selected person
void DialogPlayeredit::populatePerson()
{
    // which person is currently selected?
    for(auto player : m_players)
    { 
        if (player->getLastname() + ", " + player->getFirstname() == m_selectedPerson)
        {
            populatePlayer(player);
            break;
        }
    }
}

void DialogPlayeredit::populatePlayer(std::shared_ptr<Core::Player> player)
{
    m_textCtrlName->SetValue(player->getLastname());
    m_textCtrlStagename->SetValue(player->getArtistName());
    m_textCtrlFirstname->SetValue(player->getFirstname());
    // convert birthday string to chrono
    std::tm tm = {};
    std::stringstream ss(player->getBirthday());
    ss >> std::get_time(&tm, "%d.%m.%Y");
    m_staticTextDay->SetLabel(std::to_string(tm.tm_mday));
    m_spinButtonDay->SetValue(tm.tm_mday);
    m_staticTextMonth->SetLabel(std::to_string(tm.tm_mon + 1));
    m_spinButtonMonth->SetValue(tm.tm_mon + 1);
    m_staticTextYear->SetLabel(std::to_string(tm.tm_year + 1900));
    m_spinButtonYear->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonYear->SetValue(tm.tm_year + 1900);
    m_staticTextAge->SetLabel(std::to_string(player->getAge()));
    m_staticTextSkill->SetLabel(std::to_string(player->getSkill()));
    m_spinButtonSkill->SetValue(player->getSkill());
    m_staticTextTalent->SetLabel(tools->translate("playertalent" + std::to_string(player->getTalent())));
    m_staticTextStrongFoot->SetLabel(tools->translate("playerfoot" + std::to_string(player->getFoot())));
    m_staticTextShirtNumber->SetLabel(std::to_string(player->getShirtNumber()));
}

void DialogPlayeredit::initializePlayerList(wxListCtrl* control)
{
    control->Hide();
    control->DeleteAllItems();

    control->InsertColumn(0, tools->translate("pos"), wxLIST_FORMAT_LEFT, 40);
    control->InsertColumn(1, tools->translate("menuPlayer"), wxLIST_FORMAT_LEFT, 150);
    control->InsertColumn(2, tools->translate("skill"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(3, tools->translate("country"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(4, tools->translate("no."), wxLIST_FORMAT_LEFT, 50);

    long index = 0;
    long result = 0;
    for (auto player : m_players)
    {
        result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, tools->positionToString(player->getMainPosition()));
        control->SetItem(result, 1, player->getLastname() + ", " + player->getFirstname());
        control->SetItem(result, 2, std::to_string(player->getSkill()));
        control->SetItem(result, 3, tools->nationIndexToNationShortname(player->getNationalityFirst()));
        control->SetItem(result, 4, std::to_string(player->getShirtNumber()));
        control->SetItemData(result, index);
        ++index;
    }

    // trainer 
    auto trainer = m_team->getTrainer();
    result = control->InsertItem(index, wxString::Format("Item %d", index));
    control->SetItem(result, 0, "TRA");
    control->SetItem(result, 1, trainer.getLastname() + ", " + trainer.getFirstname());
    control->SetItem(result, 2, std::to_string(trainer.getCompetence()));
    control->SetItem(result, 3, wxT(""));
    control->SetItem(result, 4, wxT(""));
    control->SetItemData(result, index);
    ++index;

    // manager
    auto manager = m_team->getManager();
    result = control->InsertItem(index, wxString::Format("Item %d", index));
    control->SetItem(result, 0, "MA");
    control->SetItem(result, 1, manager.getLastname() + ", " + manager.getFirstname());
    control->SetItem(result, 2, std::to_string(manager.getCompetence()));
    control->SetItem(result, 3, wxT(""));
    control->SetItem(result, 4, wxT(""));
    control->SetItemData(result, index);
    ++index;

    // sort list
    //control->SortItems(SortClubList, (wxIntPtr)m_clubList);

    control->Show();
}

void DialogPlayeredit::computeAverageSkill()
{
    float sum = 0.0f;
    for (auto player : m_players)
    {
        sum += player->getSkill();
    }
    m_averageSkill = sum / m_players.size();
}