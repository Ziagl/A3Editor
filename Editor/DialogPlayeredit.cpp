#include "DialogPlayeredit.h"
#include "DialogPlayeroverview.h"
#include <iomanip>
#include <algorithm>

DialogPlayeredit::DialogPlayeredit(wxWindow* parent,
    Toolset* const tools,
    std::string selectedCountry,
    std::string selectedClub,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), parent(parent), m_selectedCountry(selectedCountry), m_selectedClub(selectedClub)
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

    m_buttonList = new wxButton(this, wxID_ANY, tools->translate("list"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer488->Add(m_buttonList, 0, wxALL, WXC_FROM_DIP(0));

    m_panel494 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer488->Add(m_panel494, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonShirtNumbers = new wxButton(this, wxID_ANY, tools->translate("redistributeShirtNumbers"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer488->Add(m_buttonShirtNumbers, 0, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer485 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer485->SetFlexibleDirection(wxBOTH);
    flexGridSizer485->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer487->Add(flexGridSizer485, 1, wxALL, WXC_FROM_DIP(0));

    m_notebook21 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBK_DEFAULT);
    m_notebook21->SetName(wxT("m_notebook21"));

    flexGridSizer485->Add(m_notebook21, 0, wxALL, WXC_FROM_DIP(0));

    m_panelData1 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelData1, tools->translate("data") + " 1", false);
    
    wxFlexGridSizer* flexGridSizer495 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer495->SetFlexibleDirection(wxBOTH);
    flexGridSizer495->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    m_panelData1->SetSizer(flexGridSizer495);

    wxStaticBoxSizer* staticBoxSizer35 = new wxStaticBoxSizer(new wxStaticBox(m_panelData1, wxID_ANY, tools->translate("personalData") + " 1"), wxVERTICAL);

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

    m_staticTextAge = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("age") + _(" 34"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    gridSizer443->Add(m_staticTextAge, 0, wxALL, WXC_FROM_DIP(0));

    m_button445 = new wxButton(m_panelData1, wxID_ANY, _("Spieler\ndoppelt?"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer421->Add(m_button445, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer423 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer423->SetFlexibleDirection(wxBOTH);
    flexGridSizer423->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer35->Add(flexGridSizer423, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText425 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("talent"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticText425, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextTalent = new wxStaticText(m_panelData1, wxID_ANY, _("Normal begabt"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticTextTalent, 0, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_spinButtonTalent = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonTalent->SetRange(0, 4);
    m_spinButtonTalent->SetValue(0);

    flexGridSizer423->Add(m_spinButtonTalent, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText431 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("strongFoot"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticText431, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextStrongFoot = new wxStaticText(m_panelData1, wxID_ANY, _("Beidfüßig"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticTextStrongFoot, 0, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_spinButtonFoot = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonFoot->SetRange(1, 3);
    m_spinButtonFoot->SetValue(0);

    flexGridSizer423->Add(m_spinButtonFoot, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText437 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("shirtNumber"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticText437, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextShirtNumber = new wxStaticText(m_panelData1, wxID_ANY, _("99"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    flexGridSizer423->Add(m_staticTextShirtNumber, 0, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_spinButtonShirtNumber = new wxSpinButton(m_panelData1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonShirtNumber->SetRange(0, 100);
    m_spinButtonShirtNumber->SetValue(0);

    flexGridSizer423->Add(m_spinButtonShirtNumber, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer479 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer495->Add(boxSizer479, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText55 = new wxStaticText(m_panelData1, wxID_ANY, tools->translate("averageStrengthOfAllPlayers"), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer479->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextAverageSkill = new wxStaticText(m_panelData1, wxID_ANY, std::to_string(m_averageSkill), wxDefaultPosition, wxDLG_UNIT(m_panelData1, wxSize(-1, -1)), 0);

    boxSizer479->Add(m_staticTextAverageSkill, 0, wxALL, WXC_FROM_DIP(5));

    m_panelData2 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelData2, tools->translate("data") + " 2", false);

    wxStaticBoxSizer* staticBoxSizer514 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, tools->translate("personalData") + " 2"), wxVERTICAL);
    m_panelData2->SetSizer(staticBoxSizer514);

    m_staticText59 = new wxStaticText(m_panelData2, wxID_ANY, tools->translate("nationality"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);

    staticBoxSizer514->Add(m_staticText59, 0, wxALL, WXC_FROM_DIP(0));

    wxArrayString choiceArray;
    auto nationIds = tools->getNationIds();
    for (auto nationId : nationIds)
    {
        auto nation = tools->getNationById(nationId);
        choiceArray.Add(nation->getName());
    }
    m_choiceNationality = new wxChoice(m_panelData2, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), choiceArray, 0);

    staticBoxSizer514->Add(m_choiceNationality, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText63 = new wxStaticText(m_panelData2, wxID_ANY, tools->translate("secondNationality"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);

    staticBoxSizer514->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(0));

    choiceArray.Clear();
    choiceArray.Add(tools->translate("none"));
    for (auto nationId : nationIds)
    {
        auto nation = tools->getNationById(nationId);
        choiceArray.Add(nation->getName());
    }
    m_choiceSecondNationality = new wxChoice(m_panelData2, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), choiceArray, 0);

    staticBoxSizer514->Add(m_choiceSecondNationality, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer519 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer514->Add(boxSizer519, 0, wxALL, WXC_FROM_DIP(5));

    m_checkNational = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("soccerNational"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkNational->SetValue(false);

    boxSizer519->Add(m_checkNational, 0, wxALL, WXC_FROM_DIP(5));

    m_checkNationalplayer = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("international"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkNationalplayer->SetValue(false);

    boxSizer519->Add(m_checkNationalplayer, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer521 = new wxBoxSizer(wxVERTICAL);

    staticBoxSizer514->Add(boxSizer521, 0, wxALL, WXC_FROM_DIP(5));

    m_checkNationalresigned = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("resignedFromTheNationalTeam"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkNationalresigned->SetValue(false);

    boxSizer521->Add(m_checkNationalresigned, 0, wxALL, WXC_FROM_DIP(5));

    m_checkCaptainresigned = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("resignedAsCaptain"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkCaptainresigned->SetValue(false);

    boxSizer521->Add(m_checkCaptainresigned, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer520 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer514->Add(boxSizer520, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer93 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, tools->translate("skinColor")), wxVERTICAL);

    boxSizer520->Add(staticBoxSizer93, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioBright = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("bright"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), wxRB_GROUP);
    m_radioBright->SetValue(1);

    staticBoxSizer93->Add(m_radioBright, 0, wxALL, WXC_FROM_DIP(0));

    m_radioDark = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("dark"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioDark->SetValue(1);

    staticBoxSizer93->Add(m_radioDark, 0, wxALL, WXC_FROM_DIP(0));

    m_radioAfrikan = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("afrikan"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioAfrikan->SetValue(1);

    staticBoxSizer93->Add(m_radioAfrikan, 0, wxALL, WXC_FROM_DIP(0));

    m_radioAsian = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("asian"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioAsian->SetValue(1);

    staticBoxSizer93->Add(m_radioAsian, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer95 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, tools->translate("hairtype")), wxVERTICAL);

    boxSizer520->Add(staticBoxSizer95, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioExtremelyshort = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("extremlyShort"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), wxRB_GROUP);
    m_radioExtremelyshort->SetValue(1);

    staticBoxSizer95->Add(m_radioExtremelyshort, 0, wxALL, WXC_FROM_DIP(0));

    m_radioShort = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("short"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioShort->SetValue(1);

    staticBoxSizer95->Add(m_radioShort, 0, wxALL, WXC_FROM_DIP(0));

    m_radioCurly = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("curlyHead"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioCurly->SetValue(1);

    staticBoxSizer95->Add(m_radioCurly, 0, wxALL, WXC_FROM_DIP(0));

    m_radioLong = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("long"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioLong->SetValue(1);

    staticBoxSizer95->Add(m_radioLong, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer97 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, tools->translate("beard")), wxVERTICAL);

    boxSizer520->Add(staticBoxSizer97, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkUnshaved = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("unshaven"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkUnshaved->SetValue(false);

    staticBoxSizer97->Add(m_checkUnshaved, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBeard = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("beard"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkBeard->SetValue(false);

    staticBoxSizer97->Add(m_checkBeard, 0, wxALL, WXC_FROM_DIP(0));

    m_checkMoustache = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("moustache"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkMoustache->SetValue(false);

    staticBoxSizer97->Add(m_checkMoustache, 0, wxALL, WXC_FROM_DIP(0));

    m_checkGoatee = new wxCheckBox(m_panelData2, wxID_ANY, tools->translate("goatee"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_checkGoatee->SetValue(false);

    staticBoxSizer97->Add(m_checkGoatee, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer99 = new wxStaticBoxSizer(new wxStaticBox(m_panelData2, wxID_ANY, tools->translate("hairColor")), wxVERTICAL);

    staticBoxSizer514->Add(staticBoxSizer99, 1, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer125 = new wxFlexGridSizer(3, 3, 0, 0);
    flexGridSizer125->SetFlexibleDirection(wxBOTH);
    flexGridSizer125->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer99->Add(flexGridSizer125, 1, wxALL, WXC_FROM_DIP(5));

    m_radioLightblonde = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("lightBlonde"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), wxRB_GROUP);
    m_radioLightblonde->SetValue(1);

    flexGridSizer125->Add(m_radioLightblonde, 0, wxALL, WXC_FROM_DIP(0));

    m_radioRed = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("red"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioRed->SetValue(1);

    flexGridSizer125->Add(m_radioRed, 0, wxALL, WXC_FROM_DIP(0));

    m_radioGrey = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("grey"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioGrey->SetValue(1);

    flexGridSizer125->Add(m_radioGrey, 0, wxALL, WXC_FROM_DIP(0));

    m_radioBlond = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("blonde"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBlond->SetValue(1);

    flexGridSizer125->Add(m_radioBlond, 0, wxALL, WXC_FROM_DIP(0));

    m_radioBlack = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("black"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBlack->SetValue(1);

    flexGridSizer125->Add(m_radioBlack, 0, wxALL, WXC_FROM_DIP(0));

    flexGridSizer125->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_radioBrown = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("brown"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBrown->SetValue(1);

    flexGridSizer125->Add(m_radioBrown, 0, wxALL, WXC_FROM_DIP(0));

    m_radioBald = new wxRadioButton(m_panelData2, wxID_ANY, tools->translate("bald"), wxDefaultPosition, wxDLG_UNIT(m_panelData2, wxSize(-1, -1)), 0);
    m_radioBald->SetValue(1);

    flexGridSizer125->Add(m_radioBald, 0, wxALL, WXC_FROM_DIP(0));

    m_panelPositions = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelPositions, tools->translate("positions"), false);

    wxBoxSizer* boxSizer157 = new wxBoxSizer(wxHORIZONTAL);
    m_panelPositions->SetSizer(boxSizer157);

    wxStaticBoxSizer* staticBoxSizer159 = new wxStaticBoxSizer(new wxStaticBox(m_panelPositions, wxID_ANY, tools->translate("mainPosition")), wxVERTICAL);

    boxSizer157->Add(staticBoxSizer159, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioButtonMainGoalkeeper = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("goalkeeper"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), wxRB_GROUP);
    m_radioButtonMainGoalkeeper->SetValue(1);

    staticBoxSizer159->Add(m_radioButtonMainGoalkeeper, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonMainSweeper = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("sweeper"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioButtonMainSweeper->SetValue(1);

    staticBoxSizer159->Add(m_radioButtonMainSweeper, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainCenterback = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("centerback"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainCenterback->SetValue(1);

    staticBoxSizer159->Add(m_radioMainCenterback, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainLeftdefender = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("leftDefender"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainLeftdefender->SetValue(1);

    staticBoxSizer159->Add(m_radioMainLeftdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainRightdefender = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("rightDefender"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainRightdefender->SetValue(1);

    staticBoxSizer159->Add(m_radioMainRightdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainDefensivemidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("defensiveMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainDefensivemidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainDefensivemidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainLeftmidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("leftMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainLeftmidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainLeftmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainRightmidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("rightMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainRightmidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainRightmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainAttackingmidfielder = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("attackingMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainAttackingmidfielder->SetValue(1);

    staticBoxSizer159->Add(m_radioMainAttackingmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_radioMainForward = new wxRadioButton(m_panelPositions, wxID_ANY, tools->translate("forward"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_radioMainForward->SetValue(1);

    staticBoxSizer159->Add(m_radioMainForward, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer161 = new wxStaticBoxSizer(new wxStaticBox(m_panelPositions, wxID_ANY, tools->translate("additionaPosition")), wxVERTICAL);

    boxSizer157->Add(staticBoxSizer161, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panel523 = new wxPanel(m_panelPositions, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    staticBoxSizer161->Add(m_panel523, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBoxSecondarySweeper = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("sweeper"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondarySweeper->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondarySweeper, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryCenterback = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("centerback"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryCenterback->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryCenterback, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryLeftdefender = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("leftDefender"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryLeftdefender->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryLeftdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryRightdefender = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("rightDefender"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryRightdefender->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryRightdefender, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryDefensivemidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("defensiveMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryDefensivemidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryDefensivemidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryLeftmidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("leftMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryLeftmidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryLeftmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryRightmidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("rightMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryRightmidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryRightmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryAttackingmidfielder = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("attackingMidfielder"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryAttackingmidfielder->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryAttackingmidfielder, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBoxSecondaryForward = new wxCheckBox(m_panelPositions, wxID_ANY, tools->translate("forward"), wxDefaultPosition, wxDLG_UNIT(m_panelPositions, wxSize(-1, -1)), 0);
    m_checkBoxSecondaryForward->SetValue(false);

    staticBoxSizer161->Add(m_checkBoxSecondaryForward, 0, wxALL, WXC_FROM_DIP(0));

    m_panelSkills = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelSkills, tools->translate("capabilities"), false);

    wxBoxSizer* boxSizer207 = new wxBoxSizer(wxHORIZONTAL);
    m_panelSkills->SetSizer(boxSizer207);

    wxStaticBoxSizer* staticBoxSizer209 = new wxStaticBoxSizer(new wxStaticBox(m_panelSkills, wxID_ANY, tools->translate("fieldPlayer")), wxVERTICAL);

    boxSizer207->Add(staticBoxSizer209, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer213 = new wxFlexGridSizer(17, 2, 0, 0);
    flexGridSizer213->SetFlexibleDirection(wxBOTH);
    flexGridSizer213->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer209->Add(flexGridSizer213, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText279 = new wxStaticText(m_panelSkills, wxID_ANY, _("+"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer213->Add(m_staticText279, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText281 = new wxStaticText(m_panelSkills, wxID_ANY, _("-"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer213->Add(m_staticText281, 0, wxALL, WXC_FROM_DIP(0));

    std::vector<std::string> fieldPlayerCapabilities = { "header", "duel", "speed", "firingPower", "penalty", "freeKicks", "flanks", "goalInstict", "runner", "technique", "ballMagic", "playmaker", "quadChain", "gameOverview", "holdBall", "dribbling" };

    for (auto capability : fieldPlayerCapabilities)
    {
        wxCheckBox* controlPlus = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
        flexGridSizer213->Add(controlPlus, 0, wxALL, WXC_FROM_DIP(0));
        m_fieldPlayerPlus.push_back(controlPlus);
        wxCheckBox* controlMinus = new wxCheckBox(m_panelSkills, wxID_ANY, tools->translate(capability), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
        flexGridSizer213->Add(controlMinus, 0, wxALL, WXC_FROM_DIP(0));
        m_fieldPlayerMinus .push_back(controlMinus);
    }

    wxStaticBoxSizer* staticBoxSizer211 = new wxStaticBoxSizer(new wxStaticBox(m_panelSkills, wxID_ANY, tools->translate("goalkeeper")), wxVERTICAL);

    boxSizer207->Add(staticBoxSizer211, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer283 = new wxFlexGridSizer(10, 2, 0, 0);
    flexGridSizer283->SetFlexibleDirection(wxBOTH);
    flexGridSizer283->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer211->Add(flexGridSizer283, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText285 = new wxStaticText(m_panelSkills, wxID_ANY, _("+"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer283->Add(m_staticText285, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText287 = new wxStaticText(m_panelSkills, wxID_ANY, _("-"), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);

    flexGridSizer283->Add(m_staticText287, 0, wxALL, WXC_FROM_DIP(0));

    std::vector<std::string> goalkeeperCapabilities = { "penaltyKiller", "strongReflexes", "comingOut", "flanks", "fist", "ballControl", "speed", "longPunts", "wideDrops" };

    for (auto capability : goalkeeperCapabilities)
    {
        wxCheckBox* controlPlus = new wxCheckBox(m_panelSkills, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
        flexGridSizer283->Add(controlPlus, 0, wxALL, WXC_FROM_DIP(0));
        m_goalkeeperPlus.push_back(controlPlus);
        wxCheckBox* controlMinus = new wxCheckBox(m_panelSkills, wxID_ANY, tools->translate(capability), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
        flexGridSizer283->Add(controlMinus, 0, wxALL, WXC_FROM_DIP(0));
        m_goalkeeperMinus.push_back(controlMinus);
    }

    m_panelCharacteristics1 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelCharacteristics1, tools->translate("prop") + " 1", false);

    wxBoxSizer* boxSizer351 = new wxBoxSizer(wxHORIZONTAL);
    m_panelCharacteristics1->SetSizer(boxSizer351);

    wxStaticBoxSizer* staticBoxSizer353 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics1, wxID_ANY, tools->translate("properties")), wxVERTICAL);

    boxSizer351->Add(staticBoxSizer353, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    std::vector<std::string> properties = { "fighter", "trainingWorldChamption", "trainingLazyPlayer", "violator", "fairPlayer", "mimosa", "slyfox", "specialist", "allrounder", "flexiblePlayer", "refereeFavorite", "homePlayer" , "fairWeatherPlayer", "joker", "egoist", "brotherLightFooted"};

    for (auto property : properties)
    {
        wxCheckBox* controlProperty = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, tools->translate(property), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
        staticBoxSizer353->Add(controlProperty, 0, wxALL, WXC_FROM_DIP(0));
        m_properties.push_back(controlProperty);
    }

    wxStaticBoxSizer* staticBoxSizer355 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics1, wxID_ANY, tools->translate("personality")), wxVERTICAL);

    boxSizer351->Add(staticBoxSizer355, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    std::vector<std::string> personalities = { "leader", "hotHead", "happyNature", "manWithoutNerves", "bundleOfNerves", "phlegmatic", "moneyVolture", "clubSupporter", "professionalPattern", "scandalNoodle", "sensitive", "airsAndGraces", "teenStar", "troublemaker", "liverwurst", "unifyingFigure" };

    for (auto personality : personalities)
    {
        wxCheckBox* controlPersonality = new wxCheckBox(m_panelCharacteristics1, wxID_ANY, tools->translate(personality), wxDefaultPosition, wxDLG_UNIT(m_panelSkills, wxSize(-1, -1)), 0);
        staticBoxSizer355->Add(controlPersonality, 0, wxALL, WXC_FROM_DIP(0));
        m_personality.push_back(controlPersonality);
    }

    m_panelCharacteristics2 = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelCharacteristics2, tools->translate("prop") + " 2", false);

    wxBoxSizer* boxSizer325 = new wxBoxSizer(wxHORIZONTAL);
    m_panelCharacteristics2->SetSizer(boxSizer325);

    wxStaticBoxSizer* staticBoxSizer327 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics2, wxID_ANY, tools->translate("healthStatus")), wxVERTICAL);

    boxSizer325->Add(staticBoxSizer327, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioButtonNormal = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("normal"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), wxRB_GROUP);
    m_radioButtonNormal->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonNormal, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonRobust = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("robust"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonRobust->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonRobust, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonSusceptible = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("susceptible"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonSusceptible->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonSusceptible, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonKneeproblems = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("kneeProblems"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonKneeproblems->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonKneeproblems, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonQuicklyfitagain = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("quicklyFitAtain"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonQuicklyfitagain->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonQuicklyfitagain, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonLastsuntilfitagain = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("lastsUntilFitAgain"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonLastsuntilfitagain->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonLastsuntilfitagain, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonSnivelling = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("snivelling"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonSnivelling->SetValue(1);

    staticBoxSizer327->Add(m_radioButtonSnivelling, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer329 = new wxStaticBoxSizer(new wxStaticBox(m_panelCharacteristics2, wxID_ANY, tools->translate("audience")), wxVERTICAL);

    boxSizer325->Add(staticBoxSizer329, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioButtonAudiencenormal = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("normal"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), wxRB_GROUP);
    m_radioButtonAudiencenormal->SetValue(1);

    staticBoxSizer329->Add(m_radioButtonAudiencenormal, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonAudiencefavorite = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("favorite"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonAudiencefavorite->SetValue(1);

    staticBoxSizer329->Add(m_radioButtonAudiencefavorite, 0, wxALL, WXC_FROM_DIP(0));

    m_radioButtonAudiencehatefigure = new wxRadioButton(m_panelCharacteristics2, wxID_ANY, tools->translate("hateFigure"), wxDefaultPosition, wxDLG_UNIT(m_panelCharacteristics2, wxSize(-1, -1)), 0);
    m_radioButtonAudiencehatefigure->SetValue(1);

    staticBoxSizer329->Add(m_radioButtonAudiencehatefigure, 0, wxALL, WXC_FROM_DIP(0));

    // TRAINER
    m_panelTrainer = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelTrainer, tools->translate("trainer"), false);

    wxStaticBoxSizer* staticBoxSizer531 = new wxStaticBoxSizer(new wxStaticBox(m_panelTrainer, wxID_ANY, tools->translate("trainerProperties")), wxVERTICAL);
    m_panelTrainer->SetSizer(staticBoxSizer531);

    wxFlexGridSizer* flexGridSizer535 = new wxFlexGridSizer(5, 2, 0, 0);
    flexGridSizer535->SetFlexibleDirection(wxBOTH);
    flexGridSizer535->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer531->Add(flexGridSizer535, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText537 = new wxStaticText(m_panelTrainer, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    flexGridSizer535->Add(m_staticText537, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlTrainerName = new wxTextCtrl(m_panelTrainer, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlTrainerName->SetHint(wxT(""));
#endif

    flexGridSizer535->Add(m_textCtrlTrainerName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText541 = new wxStaticText(m_panelTrainer, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    flexGridSizer535->Add(m_staticText541, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlTrainerFirstname = new wxTextCtrl(m_panelTrainer, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlTrainerFirstname->SetHint(wxT(""));
#endif

    flexGridSizer535->Add(m_textCtrlTrainerFirstname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText545 = new wxStaticText(m_panelTrainer, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    flexGridSizer535->Add(m_staticText545, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer547 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer535->Add(boxSizer547, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextTrainerDay = new wxStaticText(m_panelTrainer, wxID_ANY, _("01"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    boxSizer547->Add(m_staticTextTrainerDay, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonTrainerDay = new wxSpinButton(m_panelTrainer, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonTrainerDay->SetRange(1, 31);
    m_spinButtonTrainerDay->SetValue(1);

    boxSizer547->Add(m_spinButtonTrainerDay, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextTrainerMonth = new wxStaticText(m_panelTrainer, wxID_ANY, _("01"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    boxSizer547->Add(m_staticTextTrainerMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonTrainerMonth = new wxSpinButton(m_panelTrainer, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonTrainerMonth->SetRange(1, 12);
    m_spinButtonTrainerMonth->SetValue(1);

    boxSizer547->Add(m_spinButtonTrainerMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextTrainerYear = new wxStaticText(m_panelTrainer, wxID_ANY, _("1900"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    boxSizer547->Add(m_staticTextTrainerYear, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonTrainerYear = new wxSpinButton(m_panelTrainer, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonTrainerYear->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonTrainerYear->SetValue(1900);

    boxSizer547->Add(m_spinButtonTrainerYear, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText549 = new wxStaticText(m_panelTrainer, wxID_ANY, tools->translate("competence"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    flexGridSizer535->Add(m_staticText549, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer551 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer535->Add(boxSizer551, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextTrainerCompetence = new wxStaticText(m_panelTrainer, wxID_ANY, _("12"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    boxSizer551->Add(m_staticTextTrainerCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonTrainerCompetence = new wxSpinButton(m_panelTrainer, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonTrainerCompetence->SetRange(1, tools->getMaxSkillPerson());
    m_spinButtonTrainerCompetence->SetValue(0);

    boxSizer551->Add(m_spinButtonTrainerCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextTrainerAge = new wxStaticText(m_panelTrainer, wxID_ANY, _("Alter 89"), wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    boxSizer551->Add(m_staticTextTrainerAge, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText553 = new wxStaticText(m_panelTrainer, wxID_ANY, tools->translate("reputation") , wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), 0);

    flexGridSizer535->Add(m_staticText553, 0, wxALL, WXC_FROM_DIP(5));

    choiceArray.clear();
    for (int i = 0; i < 7; ++i)
        choiceArray.Add(tools->translate("trainertype" + std::to_string(i)));
    m_choiceTrainerReputation = new wxChoice(m_panelTrainer, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelTrainer, wxSize(-1, -1)), choiceArray, 0);

    flexGridSizer535->Add(m_choiceTrainerReputation, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    // Manager
    m_panelManager = new wxPanel(m_notebook21, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook21, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook21->AddPage(m_panelManager, tools->translate("manager"), false);

    wxStaticBoxSizer* staticBoxSizer575 = new wxStaticBoxSizer(new wxStaticBox(m_panelManager, wxID_ANY, tools->translate("managerProperties")), wxVERTICAL);
    m_panelManager->SetSizer(staticBoxSizer575);

    wxFlexGridSizer* flexGridSizer577 = new wxFlexGridSizer(4, 2, 0, 0);
    flexGridSizer577->SetFlexibleDirection(wxBOTH);
    flexGridSizer577->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer575->Add(flexGridSizer577, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText581 = new wxStaticText(m_panelManager, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    flexGridSizer577->Add(m_staticText581, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlManagerName = new wxTextCtrl(m_panelManager, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlManagerName->SetHint(wxT(""));
#endif

    flexGridSizer577->Add(m_textCtrlManagerName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText583 = new wxStaticText(m_panelManager, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    flexGridSizer577->Add(m_staticText583, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlManagerFirstname = new wxTextCtrl(m_panelManager, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlManagerFirstname->SetHint(wxT(""));
#endif

    flexGridSizer577->Add(m_textCtrlManagerFirstname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText587 = new wxStaticText(m_panelManager, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    flexGridSizer577->Add(m_staticText587, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer589 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer577->Add(boxSizer589, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextManagerDay = new wxStaticText(m_panelManager, wxID_ANY, _("01"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    boxSizer589->Add(m_staticTextManagerDay, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonManagerDay = new wxSpinButton(m_panelManager, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonManagerDay->SetRange(1, 31);
    m_spinButtonManagerDay->SetValue(0);

    boxSizer589->Add(m_spinButtonManagerDay, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextManagerMonth = new wxStaticText(m_panelManager, wxID_ANY, _("01"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    boxSizer589->Add(m_staticTextManagerMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonManagerMonth = new wxSpinButton(m_panelManager, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonManagerMonth->SetRange(1, 12);
    m_spinButtonManagerMonth->SetValue(0);

    boxSizer589->Add(m_spinButtonManagerMonth, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextManagerYear = new wxStaticText(m_panelManager, wxID_ANY, _("1990"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    boxSizer589->Add(m_staticTextManagerYear, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonManagerYear = new wxSpinButton(m_panelManager, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonManagerYear->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonManagerYear->SetValue(1900);

    boxSizer589->Add(m_spinButtonManagerYear, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText593 = new wxStaticText(m_panelManager, wxID_ANY, tools->translate("competence"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    flexGridSizer577->Add(m_staticText593, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer595 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer577->Add(boxSizer595, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextManagerCompetence = new wxStaticText(m_panelManager, wxID_ANY, _("12"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    boxSizer595->Add(m_staticTextManagerCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonManagerCompetence = new wxSpinButton(m_panelManager, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonManagerCompetence->SetRange(1, tools->getMaxSkillPerson());
    m_spinButtonManagerCompetence->SetValue(1);

    boxSizer595->Add(m_spinButtonManagerCompetence, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextManagerAge = new wxStaticText(m_panelManager, wxID_ANY, _("Alter 23"), wxDefaultPosition, wxDLG_UNIT(m_panelManager, wxSize(-1, -1)), 0);

    boxSizer595->Add(m_staticTextManagerAge, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonList->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnList), NULL, this);
    this->Connect(m_buttonShirtNumbers->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnShirtNumberReset), NULL, this);
    // list events
    this->Connect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPlayeredit::OnSelectPerson), NULL, this);
    // spin events
    this->Connect(m_spinButtonDay->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnDay), NULL, this);
    this->Connect(m_spinButtonMonth->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnMonth), NULL, this);
    this->Connect(m_spinButtonYear->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnYear), NULL, this);
    this->Connect(m_spinButtonSkill->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnSkill), NULL, this);
    this->Connect(m_spinButtonTalent->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnTalent), NULL, this);
    this->Connect(m_spinButtonFoot->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnFoot), NULL, this);
    this->Connect(m_spinButtonShirtNumber->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnShirtNumber), NULL, this);

    // init
    computeAverageSkill();
    m_listCtrlPlayer->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);    // select first item
}

DialogPlayeredit::~DialogPlayeredit()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnAbort), NULL, this);
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnOk), NULL, this);
    this->Disconnect(m_buttonList->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnList), NULL, this);
    this->Disconnect(m_buttonShirtNumbers->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayeredit::OnShirtNumberReset), NULL, this);
    // list events
    this->Disconnect(m_listCtrlPlayer->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPlayeredit::OnSelectPerson), NULL, this);
    // spin events
    this->Disconnect(m_spinButtonDay->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnDay), NULL, this);
    this->Disconnect(m_spinButtonMonth->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnMonth), NULL, this);
    this->Disconnect(m_spinButtonYear->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnYear), NULL, this);
    this->Disconnect(m_spinButtonSkill->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnSkill), NULL, this);
    this->Disconnect(m_spinButtonTalent->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnTalent), NULL, this);
    this->Disconnect(m_spinButtonFoot->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnFoot), NULL, this);
    this->Disconnect(m_spinButtonShirtNumber->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogPlayeredit::OnShirtNumber), NULL, this);
}


void DialogPlayeredit::OnList(wxCommandEvent& event)
{
    DialogPlayeroverview dlg(parent, tools, m_players);
    dlg.ShowModal();
}

void DialogPlayeredit::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogPlayeredit::OnOk(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogPlayeredit::OnShirtNumberReset(wxCommandEvent& event)
{
    if (wxMessageBox(wxT("Wollen Sie wirklich die Rückennummern komplett neu vergeben? Auch vorhandene Spieler erhalten dann evtl. eine neue Rückennummer!"), wxT("EDITOR"), wxYES_NO | wxICON_INFORMATION, this) == wxYES)
    {
        recomputeShirtNumbers();
        initializePlayerList(m_listCtrlPlayer);
    }
}


void DialogPlayeredit::OnSelectPerson(wxListEvent& event)
{
    bool reinitializeList = false;
    // save last selected player if there is one
    if(m_lastType == PlayereditType::PET_PLAYER)
    {
        if (!m_selectedPerson.empty())
        {
            for (auto player : m_players)
            {
                if (player->getLastname() + ", " + player->getFirstname() == m_selectedPerson)
                {
                    savePlayer(player);
                    reinitializeList = true;
                    break;
                }
            }
        }
    }
    else if (m_lastType == PlayereditType::PET_TRAINER)
    {
        saveTrainer();
        reinitializeList = true;
    }
    else if (m_lastType == PlayereditType::PET_MANAGER)
    {
        saveManager();
        reinitializeList = true;
    }
    if(reinitializeList)
        initializePlayerList(m_listCtrlPlayer);
    std::string type = std::string(m_listCtrlPlayer->GetItemText(event.m_itemIndex, 0));
    int pageCount = m_notebook21->GetPageCount();
    if (type == "TRA")
    {
        if (m_lastType != PlayereditType::PET_TRAINER)
        {
            m_notebook21->Hide();
            while (m_notebook21->GetPageCount() > 0)
                m_notebook21->RemovePage(0);
            m_notebook21->AddPage(m_panelTrainer, tools->translate("trainer"), false);
            m_notebook21->Show();
        }
        m_lastType = PlayereditType::PET_TRAINER;
    }
    else if (type == "MA")
    {
        if (m_lastType != PlayereditType::PET_MANAGER)
        {
            m_notebook21->Hide();
            while (m_notebook21->GetPageCount() > 0)
                m_notebook21->RemovePage(0);
            m_notebook21->AddPage(m_panelManager, tools->translate("manager"), false);
            m_notebook21->Show();
        }
        m_lastType = PlayereditType::PET_MANAGER;
    }
    else
    {
        if (m_lastType != PlayereditType::PET_PLAYER)
        {
            m_notebook21->Hide();
            while (m_notebook21->GetPageCount() > 0)
                m_notebook21->RemovePage(0);
            m_notebook21->AddPage(m_panelData1, tools->translate("data") + " 1", false);
            m_notebook21->AddPage(m_panelData2, tools->translate("data") + " 2", false);
            m_notebook21->AddPage(m_panelPositions, tools->translate("positions"), false);
            m_notebook21->AddPage(m_panelSkills, tools->translate("capabilities"), false);
            m_notebook21->AddPage(m_panelCharacteristics1, tools->translate("prop") + " 1", false);
            m_notebook21->AddPage(m_panelCharacteristics2, tools->translate("prop") + " 2", false);
            m_notebook21->Show();
        }
        m_lastType = PlayereditType::PET_PLAYER;
    }

    // select new item and show values
    m_selectedPerson = m_listCtrlPlayer->GetItemText(event.m_itemIndex, 1);
    populatePerson();
}

// fill all controls of current selected person
void DialogPlayeredit::populatePerson()
{
    if (m_lastType == PlayereditType::PET_PLAYER)
    {
        // which person is currently selected?
        for (auto player : m_players)
        {
            if (player->getLastname() + ", " + player->getFirstname() == m_selectedPerson)
            {
                populatePlayer(player);
                break;
            }
        }
    }
    else if (m_lastType == PlayereditType::PET_TRAINER)
    {
        populateTrainer();
    }
    else if (m_lastType == PlayereditType::PET_MANAGER)
    {
        populateManager();
    }
}

void DialogPlayeredit::populatePlayer(std::shared_ptr<Core::Player> player)
{
    // Data 1
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
    m_staticTextAge->SetLabel(tools->translate("age") + " " + std::to_string(player->getAge()));
    m_staticTextSkill->SetLabel(std::to_string(player->getSkill()));
    m_spinButtonSkill->SetValue(player->getSkill());
    m_staticTextTalent->SetLabel(tools->translate("playertalent" + std::to_string(player->getTalent())));
    m_spinButtonTalent->SetValue(player->getTalent());
    m_staticTextStrongFoot->SetLabel(tools->translate("playerfoot" + std::to_string(player->getFoot())));
    m_spinButtonFoot->SetValue(player->getFoot());
    m_staticTextShirtNumber->SetLabel(std::to_string(player->getShirtNumber()));
    m_spinButtonShirtNumber->SetValue(player->getShirtNumber());
    // Data 2
    if (player->getNationalTeam())
        m_choiceNationality->Disable();
    else
        m_choiceNationality->Enable();
    m_choiceNationality->SetSelection(player->getNationalityFirst());
    m_choiceSecondNationality->SetSelection(player->getNationalitySecond());
    m_checkNational->SetValue(player->getResidient());
    m_checkNationalplayer->SetValue(player->getNationalPlayer());
    if (player->getNationalTeam())
        m_checkNationalresigned->Disable();
    else
        m_checkNationalresigned->Enable();
    m_checkNationalresigned->SetValue(player->getNationalPlayerResigned());
    m_checkCaptainresigned->SetValue(player->getCaptainResigned());
    switch (player->getSkinColor())
    {
        case 0: m_radioBright->SetValue(true); break;
        case 1: m_radioDark->SetValue(true); break;
        case 2: m_radioAfrikan->SetValue(true); break;
        case 3: m_radioAsian->SetValue(true); break;
    }
    m_radioExtremelyshort->Enable();
    m_radioShort->Enable();
    m_radioCurly->Enable();
    m_radioLong->Enable();
    switch (player->getAppearence() >> 16)
    {
        case 0: m_radioExtremelyshort->SetValue(true); break;
        case 1: m_radioShort->SetValue(true); break;
        case 2: m_radioCurly->SetValue(true); break;
        case 3: m_radioLong->SetValue(true); break;
    }
    switch (player->getHairColor())
    {
        case 0: m_radioLightblonde->SetValue(true); break;
        case 1: m_radioBlond->SetValue(true); break;
        case 2: m_radioBrown->SetValue(true); break;
        case 3: m_radioRed->SetValue(true); break;
        case 4: m_radioBlack->SetValue(true); break;
        case 5: m_radioBald->SetValue(true); 
                m_radioExtremelyshort->Disable();
                m_radioShort->Disable();
                m_radioCurly->Disable();
                m_radioLong->Disable();
                break;
        case 6: m_radioGrey->SetValue(true); break;
    }
    m_checkUnshaved->SetValue(false);
    m_checkUnshaved->Enable();
    m_checkBeard->SetValue(false);
    m_checkBeard->Enable();
    m_checkMoustache->SetValue(false);
    m_checkMoustache->Enable();
    m_checkGoatee->SetValue(false);
    m_checkGoatee->Enable();
    switch (player->getAppearence() & 15)
    {
        case 1: m_checkUnshaved->SetValue(true); 
                m_checkBeard->Disable();
                break;
        case 2: m_checkBeard->SetValue(true); 
                m_checkUnshaved->Disable();
                m_checkGoatee->Disable();
                break;
        case 4: m_checkMoustache->SetValue(true); break;
        case 8: m_checkGoatee->SetValue(true); 
                m_checkBeard->Disable();
                break;
    }
    // positions
    m_checkBoxSecondarySweeper->SetValue(false);
    m_checkBoxSecondarySweeper->Enable();
    m_checkBoxSecondaryCenterback->SetValue(false);
    m_checkBoxSecondaryCenterback->Enable();
    m_checkBoxSecondaryLeftdefender->SetValue(false);
    m_checkBoxSecondaryLeftdefender->Enable();
    m_checkBoxSecondaryRightdefender->SetValue(false);
    m_checkBoxSecondaryRightdefender->Enable();
    m_checkBoxSecondaryDefensivemidfielder->SetValue(false);
    m_checkBoxSecondaryDefensivemidfielder->Enable();
    m_checkBoxSecondaryLeftmidfielder->SetValue(false);
    m_checkBoxSecondaryLeftmidfielder->Enable();
    m_checkBoxSecondaryRightmidfielder->SetValue(false);
    m_checkBoxSecondaryRightmidfielder->Enable();
    m_checkBoxSecondaryAttackingmidfielder->SetValue(false);
    m_checkBoxSecondaryAttackingmidfielder->Enable(); 
    m_checkBoxSecondaryForward->SetValue(false);
    m_checkBoxSecondaryForward->Enable();
    switch(player->getMainPosition())
    {
        case 1: m_radioButtonMainGoalkeeper->SetValue(true); 
                m_checkBoxSecondarySweeper->Disable();
                m_checkBoxSecondaryCenterback->Disable();
                m_checkBoxSecondaryLeftdefender->Disable();
                m_checkBoxSecondaryRightdefender->Disable();
                m_checkBoxSecondaryDefensivemidfielder->Disable();
                m_checkBoxSecondaryLeftmidfielder->Disable();
                m_checkBoxSecondaryRightmidfielder->Disable();
                m_checkBoxSecondaryAttackingmidfielder->Disable();
                m_checkBoxSecondaryForward->Disable();
                break;
        case 2: m_radioButtonMainSweeper->SetValue(true); 
                m_checkBoxSecondarySweeper->Disable();
                break;
        case 3: m_radioMainCenterback->SetValue(true); 
                m_checkBoxSecondaryCenterback->Disable();
                break;
        case 4: m_radioMainLeftdefender->SetValue(true); 
                m_checkBoxSecondaryLeftdefender->Disable();
                break;
        case 5: m_radioMainRightdefender->SetValue(true); 
                m_checkBoxSecondaryRightdefender->Disable();
                break;
        case 6: m_radioMainDefensivemidfielder->SetValue(true); 
                m_checkBoxSecondaryDefensivemidfielder->Disable();
                break;
        case 7: m_radioMainLeftmidfielder->SetValue(true); 
                m_checkBoxSecondaryLeftmidfielder->Disable();
                break;
        case 8: m_radioMainRightmidfielder->SetValue(true); 
                m_checkBoxSecondaryRightmidfielder->Disable();
                break;
        case 9: m_radioMainAttackingmidfielder->SetValue(true); 
                m_checkBoxSecondaryAttackingmidfielder->Disable();
                break;
        case 10: m_radioMainForward->SetValue(true); 
                m_checkBoxSecondaryForward->Disable();
                break;
    }
    std::vector<short> secondaryPositions;
    secondaryPositions.push_back(player->getAlternativeFirstPosition());
    secondaryPositions.push_back(player->getAlternativeSecondPosition());
    for (auto position : secondaryPositions)
    {
        switch (position)
        {
            case 2: m_checkBoxSecondarySweeper->SetValue(true); break;
            case 3: m_checkBoxSecondaryCenterback->SetValue(true); break;
            case 4: m_checkBoxSecondaryLeftdefender->SetValue(true); break;
            case 5: m_checkBoxSecondaryRightdefender->SetValue(true); break;
            case 6: m_checkBoxSecondaryDefensivemidfielder->SetValue(true); break;
            case 7: m_checkBoxSecondaryLeftmidfielder->SetValue(true); break;
            case 8: m_checkBoxSecondaryRightmidfielder->SetValue(true); break;
            case 9: m_checkBoxSecondaryAttackingmidfielder->SetValue(true); break;
            case 10: m_checkBoxSecondaryForward->SetValue(true); break;
        }
    }
    // capabilities
    for (auto control : m_fieldPlayerPlus)
        control->SetValue(false);
    for (auto control : m_fieldPlayerMinus)
        control->SetValue(false);
    enableFieldPlayerCapabilities();

    for (auto control : m_goalkeeperPlus)
        control->SetValue(false);
    for (auto control : m_goalkeeperMinus)
        control->SetValue(false);
    enableGoalkeeperCapabilities();

    if (player->getMainPosition() == 1)      // goalkeeper
    {
        enableGoalkeeperCapabilities();
        disableFieldPlayerCapabilities();
        long bitmask = 0b00000000000000000010;
        for (int i = 0; i < m_goalkeeperPlus.size(); ++i)
        {
            if (player->getPlayerSkillPositive() & bitmask)
                m_goalkeeperPlus.at(i)->SetValue(true);
            if (player->getPlayerSkillNegative() & bitmask)
                m_goalkeeperMinus.at(i)->SetValue(true);
            bitmask = bitmask << 1;
        }
    }
    else                                     // field player
    {
        disableGoalkeeperCapabilities();
        enableFieldPlayerCapabilities();
        long bitmask = 0b00000000000000000010;
        for (int i = 0; i < m_fieldPlayerPlus.size(); ++i)
        {
            if (player->getPlayerSkillPositive() & bitmask)
                m_fieldPlayerPlus.at(i)->SetValue(true);
            if (player->getPlayerSkillNegative() & bitmask)
                m_fieldPlayerMinus.at(i)->SetValue(true);
            bitmask = bitmask << 1;
        }
    }
    // Prop. 1
    for (auto property : m_properties)
    {
        property->SetValue(false);
        property->Enable();
    }
    long bitmask = 0b00000000000000000010;
    std::vector<short> disabledProperties = { 5, 7, 8, 9, 10, 11, 12, 13, 14 };
    for (int i = 0; i < m_properties.size(); ++i)
    {
        if (player->getPlayerProperties() & bitmask)
            m_properties.at(i)->SetValue(true);
        if (player->getMainPosition() == 1)      // goalkeeper
        {
            if (std::find(disabledProperties.begin(), disabledProperties.end(), i) != disabledProperties.end())
                m_properties.at(i)->Disable();
        }
        bitmask = bitmask << 1;
    }
    
    for (auto personality : m_personality)
    {
        personality->SetValue(false);
        personality->Enable();
    }
    bitmask = 0b00000000000000000010;
    for (int i = 0; i < m_personality.size(); ++i)
    {
        if (player->getPlayerPersonality() & bitmask)
            m_personality.at(i)->SetValue(true);
        bitmask = bitmask << 1;
    }
    // Prop. 2
    switch (player->getHealth())
    {
        case 1: m_radioButtonNormal->SetValue(true); break;
        case 2: m_radioButtonRobust->SetValue(true); break;
        case 3: m_radioButtonSusceptible->SetValue(true); break;
        case 4: m_radioButtonKneeproblems->SetValue(true); break;
        case 5: m_radioButtonQuicklyfitagain->SetValue(true); break;
        case 6: m_radioButtonLastsuntilfitagain->SetValue(true); break;
        case 7: m_radioButtonSnivelling->SetValue(true); break;
    }
    switch (player->getAudience())
    {
        case 1: m_radioButtonAudiencenormal->SetValue(true); break;
        case 2: m_radioButtonAudiencefavorite->SetValue(true); break;
        case 3: m_radioButtonAudiencehatefigure->SetValue(true); break;
    }
}

void DialogPlayeredit::populateTrainer()
{
    auto trainer = m_team->getTrainer();
    m_textCtrlTrainerName->SetValue(trainer.getLastname());
    m_textCtrlTrainerFirstname->SetValue(trainer.getFirstname());
    // convert birthday string to chrono
    std::tm tm = {};
    std::stringstream ss(trainer.getBirthday());
    ss >> std::get_time(&tm, "%d.%m.%Y");
    m_staticTextTrainerDay->SetLabel(std::to_string(tm.tm_mday));
    m_spinButtonTrainerDay->SetValue(tm.tm_mday);
    m_staticTextTrainerMonth->SetLabel(std::to_string(tm.tm_mon + 1));
    m_spinButtonTrainerMonth->SetValue(tm.tm_mon + 1);
    m_staticTextTrainerYear->SetLabel(std::to_string(tm.tm_year + 1900));
    m_spinButtonTrainerYear->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonTrainerYear->SetValue(tm.tm_year + 1900);
    m_staticTextTrainerAge->SetLabel(tools->translate("age") + " " + std::to_string(trainer.getAge()));
    m_staticTextTrainerCompetence->SetLabel(std::to_string(trainer.getCompetence()));
    m_spinButtonTrainerCompetence->SetValue(trainer.getCompetence());
    m_choiceTrainerReputation->SetSelection(trainer.getReputation());
}

void DialogPlayeredit::populateManager()
{
    auto manager = m_team->getManager();
    m_textCtrlManagerName->SetValue(manager.getLastname());
    m_textCtrlManagerFirstname->SetValue(manager.getFirstname());
    // convert birthday string to chrono
    std::tm tm = {};
    std::stringstream ss(manager.getBirthday());
    ss >> std::get_time(&tm, "%d.%m.%Y");
    m_staticTextManagerDay->SetLabel(std::to_string(tm.tm_mday));
    m_spinButtonManagerDay->SetValue(tm.tm_mday);
    m_staticTextManagerMonth->SetLabel(std::to_string(tm.tm_mon + 1));
    m_spinButtonManagerMonth->SetValue(tm.tm_mon + 1);
    m_staticTextManagerYear->SetLabel(std::to_string(tm.tm_year + 1900));
    m_spinButtonManagerYear->SetRange(1900, tools->getStartingYear() - tools->getMinAge());
    m_spinButtonManagerYear->SetValue(tm.tm_year + 1900);
    m_staticTextManagerAge->SetLabel(tools->translate("age") + " " + std::to_string(manager.getAge()));
    m_staticTextManagerCompetence->SetLabel(std::to_string(manager.getCompetence()));
    m_spinButtonManagerCompetence->SetValue(manager.getCompetence());
}

void DialogPlayeredit::enableGoalkeeperCapabilities()
{
    for (auto control : m_goalkeeperPlus)
        control->Enable();
    for (auto control : m_goalkeeperMinus)
        control->Enable();
}
void DialogPlayeredit::disableGoalkeeperCapabilities()
{
    for (auto control : m_goalkeeperPlus)
        control->Disable();
    for (auto control : m_goalkeeperMinus)
        control->Disable();
}
void DialogPlayeredit::enableFieldPlayerCapabilities()
{
    for (auto control : m_fieldPlayerPlus)
        control->Enable();
    for (auto control : m_fieldPlayerMinus)
        control->Enable();
}

void DialogPlayeredit::disableFieldPlayerCapabilities()
{
    for (auto control : m_fieldPlayerPlus)
        control->Disable();
    for (auto control : m_fieldPlayerMinus)
        control->Disable();
}

/*
 * this saves the fields of last selected person to data
 */
void DialogPlayeredit::savePlayer(std::shared_ptr<Core::Player> player)
{
    // Data 1
    player->setLastname(std::string(m_textCtrlName->GetValue().mb_str()));
    player->setArtistName(std::string(m_textCtrlStagename->GetValue().mb_str()));
    player->setHasArtistName(!player->getArtistName().empty());
    player->setFirstname(std::string(m_textCtrlFirstname->GetValue().mb_str()));
    player->setBirthday(std::to_string(m_spinButtonDay->GetValue()) + "." +
                        std::to_string(m_spinButtonMonth->GetValue()) + "." +
                        std::to_string(m_spinButtonYear->GetValue()));
    player->setAge(1900 + m_spinButtonYear->GetValue());
    player->setSkill(m_spinButtonSkill->GetValue());
    player->setTalent(m_spinButtonTalent->GetValue());
    player->setFoot(m_spinButtonFoot->GetValue());
    player->setShirtNumber(m_spinButtonShirtNumber->GetValue());
    // Data 2
    player->setNationalityFirst(m_choiceNationality->GetSelection());
    player->setNationalitySecond(m_choiceSecondNationality->GetSelection());
    player->setResidient(m_checkNational->GetValue());
    player->setNationalPlayer(m_checkNationalplayer->GetValue());
    player->setNationalPlayerResigned(m_checkNationalresigned->GetValue());
    player->setCaptainResigned(m_checkCaptainresigned->GetValue());
    if (m_radioBright->GetValue()) player->setSkinColor(0);
    else if (m_radioDark->GetValue()) player->setSkinColor(1);
    else if (m_radioAfrikan->GetValue()) player->setSkinColor(2);
    else if (m_radioAsian->GetValue()) player->setSkinColor(3);
    int hair = 0;
    if (m_radioExtremelyshort->GetValue()) hair = 0;
    else if (m_radioShort->GetValue()) hair = 1;
    else if (m_radioCurly->GetValue()) hair = 2;
    else if (m_radioLong->GetValue()) hair = 3;
    if (m_radioLightblonde->GetValue())player->setHairColor(0);
    else if (m_radioBlond->GetValue())player->setHairColor(1);
    else if (m_radioBrown->GetValue())player->setHairColor(2);
    else if (m_radioRed->GetValue())player->setHairColor(3);
    else if (m_radioBlack->GetValue())player->setHairColor(4);
    else if (m_radioBald->GetValue())player->setHairColor(5);
    else if (m_radioGrey->GetValue())player->setHairColor(6);
    int beard = 0;
    if (m_checkUnshaved->GetValue()) beard+= 1;
    if (m_checkBeard->GetValue()) beard+= 2;
    if (m_checkMoustache->GetValue()) beard += 4;
    if (m_checkGoatee->GetValue()) beard += 8;
    player->setAppearence((hair << 16) + beard);
    // positions
    if (m_radioButtonMainGoalkeeper->GetValue()) player->setMainPosition(1);
    if (m_radioButtonMainSweeper->GetValue()) player->setMainPosition(2);
    if (m_radioMainCenterback->GetValue()) player->setMainPosition(3);
    if (m_radioMainLeftdefender->GetValue()) player->setMainPosition(4);
    if (m_radioMainRightdefender->GetValue()) player->setMainPosition(5);
    if (m_radioMainDefensivemidfielder->GetValue()) player->setMainPosition(6);
    if (m_radioMainLeftmidfielder->GetValue()) player->setMainPosition(7);
    if (m_radioMainRightmidfielder->GetValue()) player->setMainPosition(8);
    if (m_radioMainAttackingmidfielder->GetValue()) player->setMainPosition(9);
    if (m_radioMainForward->GetValue()) player->setMainPosition(10);
    std::vector<short> secondaryPositions;
    if (m_checkBoxSecondarySweeper->GetValue()) secondaryPositions.push_back(2);
    if (m_checkBoxSecondaryCenterback->GetValue()) secondaryPositions.push_back(3);
    if (m_checkBoxSecondaryLeftdefender->GetValue()) secondaryPositions.push_back(4);
    if (m_checkBoxSecondaryRightdefender->GetValue()) secondaryPositions.push_back(5);
    if (m_checkBoxSecondaryDefensivemidfielder->GetValue()) secondaryPositions.push_back(6);
    if (m_checkBoxSecondaryLeftmidfielder->GetValue()) secondaryPositions.push_back(7);
    if (m_checkBoxSecondaryRightmidfielder->GetValue()) secondaryPositions.push_back(8);
    if (m_checkBoxSecondaryAttackingmidfielder->GetValue()) secondaryPositions.push_back(9);
    if (m_checkBoxSecondaryForward->GetValue()) secondaryPositions.push_back(10);
    if (secondaryPositions.size() > 1)
        player->setAlternativeSecondPosition(secondaryPositions.at(1));
    if(secondaryPositions.size() > 0)
        player->setAlternativeFirstPosition(secondaryPositions.at(0));
    // capabilities
    player->setPlayerSkillPositive(0);
    player->setPlayerSkillNegative(0);
    if (player->getMainPosition() == 1)      // goalkeeper
    {
        long bitmask = 0b00000000000000000010;
        for (int i = 0; i < m_goalkeeperPlus.size(); ++i)
        {
            if (m_goalkeeperPlus.at(i)->GetValue())
                player->setPlayerSkillPositive(player->getPlayerSkillPositive() | bitmask);
            if(m_goalkeeperMinus.at(i)->GetValue())
                player->setPlayerSkillNegative(player->getPlayerSkillNegative() | bitmask);
            bitmask = bitmask << 1;
        }
    }
    else                                     // field player
    {
        long bitmask = 0b00000000000000000010;
        for (int i = 0; i < m_fieldPlayerPlus.size(); ++i)
        {
            if (m_fieldPlayerPlus.at(i)->GetValue())
                player->setPlayerSkillPositive(player->getPlayerSkillPositive() | bitmask);
            if (m_fieldPlayerMinus.at(i)->GetValue())
                player->setPlayerSkillNegative(player->getPlayerSkillNegative() | bitmask);
            bitmask = bitmask << 1;
        }
    }
    // Prop. 1
    player->setPlayerProperties(0);
    long bitmask = 0b00000000000000000010;
    for (int i = 0; i < m_properties.size(); ++i)
    {
        if(m_properties.at(i)->GetValue())
            player->setPlayerProperties(player->getPlayerProperties() | bitmask);
        bitmask = bitmask << 1;
    }
    player->setPlayerPersonality(0);
    bitmask = 0b00000000000000000010;
    for (int i = 0; i < m_personality.size(); ++i)
    {
        if (m_personality.at(i)->GetValue())
            player->setPlayerPersonality(player->getPlayerPersonality() | bitmask);
        bitmask = bitmask << 1;
    }
    // Prop. 2
    if (m_radioButtonNormal->GetValue()) player->setHealth(1);
    else if (m_radioButtonRobust->GetValue()) player->setHealth(2);
    else if (m_radioButtonSusceptible->GetValue()) player->setHealth(3);
    else if (m_radioButtonKneeproblems->GetValue()) player->setHealth(4);
    else if (m_radioButtonQuicklyfitagain->GetValue()) player->setHealth(5);
    else if (m_radioButtonLastsuntilfitagain->GetValue()) player->setHealth(6);
    else if (m_radioButtonSnivelling->GetValue()) player->setHealth(7);
    if (m_radioButtonAudiencenormal->GetValue()) player->setAudience(1);
    else if (m_radioButtonAudiencefavorite->GetValue()) player->setAudience(2);
    else if (m_radioButtonAudiencehatefigure->GetValue()) player->setAudience(3);
}

void DialogPlayeredit::saveTrainer()
{
    auto trainer = m_team->getTrainer();
    trainer.setLastname(std::string(m_textCtrlTrainerName->GetValue().mb_str()));
    trainer.setFirstname(std::string(m_textCtrlTrainerFirstname->GetValue()));
    trainer.setBirthday(std::to_string(m_spinButtonTrainerDay->GetValue()) + "." +
        std::to_string(m_spinButtonTrainerMonth->GetValue()) + "." +
        std::to_string(m_spinButtonTrainerYear->GetValue()));
    trainer.setAge(1900 + m_spinButtonTrainerYear->GetValue());
    trainer.setCompetence(m_spinButtonTrainerCompetence->GetValue());
    trainer.setReputation(m_choiceTrainerReputation->GetSelection());
    m_team->setTrainer(trainer);
}

void DialogPlayeredit::saveManager()
{
    auto manager = m_team->getManager();
    manager.setLastname(std::string(m_textCtrlManagerName->GetValue().mb_str()));
    manager.setFirstname(std::string(m_textCtrlManagerFirstname->GetValue().mb_str()));
    manager.setBirthday(std::to_string(m_spinButtonManagerDay->GetValue()) + "." +
        std::to_string(m_spinButtonManagerMonth->GetValue()) + "." +
        std::to_string(m_spinButtonManagerYear->GetValue()));
    manager.setAge(1900 + m_spinButtonManagerYear->GetValue());
    manager.setCompetence(m_spinButtonManagerCompetence->GetValue());
    m_team->setManager(manager);
}

void DialogPlayeredit::initializePlayerList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

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

    wchar_t buffer[100];
    swprintf(buffer, 100, L"%.3f", m_averageSkill);
    m_staticTextAverageSkill->SetLabel(buffer);
}

/*
 * this method tries to do the recomputation of shirt numbers the exact way the original editor does
 * as far as testet, the logic is:
 * 1 T, 2 LV, 3 RV, 4 IV, 5 L, 6 IV, 7 LM, 8 DM, 9 S, 10 OM, 11 S, 12 RV, 13 S, 14 IV, 15 IV,
 * 16 S, 17 LM, 18 DM, 19 RM, 20 OM, 21 T, 22 L/T, 23 OM, 24 LM/S, 25 DM, 26 OM, 27 S, 28 RM, 29 RM, 30 T
 */
void DialogPlayeredit::recomputeShirtNumbers()
{
    // position values for the first 30 known positions
    std::vector<int> defaultShirtNumbers = {1, 4, 5, 3, 2, 3, 7, 6, 10, 9, 10, 5, 10, 3, 3, 10, 7, 6, 8, 9, 1, 2, 9, 7, 6, 9, 10, 8, 8, 1};
    // reset all shirt numbers
    for (auto player : m_players)
    {
        player->setShirtNumber(0);
    }
    // set those numbers to first 30 best players
    for (int i = 0; i < defaultShirtNumbers.size(); ++i)
    {
        auto result = std::find_if(m_players.begin(), m_players.end(), [&](std::shared_ptr<Core::Player> const& p) { return (p->getMainPosition() == defaultShirtNumbers.at(i)) && (p->getShirtNumber() == 0); });
        if (result != m_players.end())
            (*result)->setShirtNumber(i+1);
    }
    // all other players with following numbers
    int lastNumber = 30;
    for (auto player : m_players)
    {
        if (player->getShirtNumber() == 0)
        {
            player->setShirtNumber(++lastNumber);
        }
    }
}

void DialogPlayeredit::OnDay(wxSpinEvent& event)
{
    m_staticTextDay->SetLabel(std::to_string(m_spinButtonDay->GetValue()));
}

void DialogPlayeredit::OnMonth(wxSpinEvent& event)
{
    m_staticTextMonth->SetLabel(std::to_string(m_spinButtonMonth->GetValue()));
}

void DialogPlayeredit::OnYear(wxSpinEvent& event)
{
    m_staticTextYear->SetLabel(std::to_string(m_spinButtonYear->GetValue()));
    m_staticTextAge->SetLabel(tools->translate("age") + " " + std::to_string(tools->getStartingYear() - m_spinButtonYear->GetValue()));
}

void DialogPlayeredit::OnSkill(wxSpinEvent& event)
{
    m_staticTextSkill->SetLabel(std::to_string(m_spinButtonSkill->GetValue()));
}

void DialogPlayeredit::OnTalent(wxSpinEvent& event)
{
    m_staticTextTalent->SetLabel(tools->translate("playertalent" + std::to_string(m_spinButtonTalent->GetValue())));
}

void DialogPlayeredit::OnFoot(wxSpinEvent& event)
{
    m_staticTextStrongFoot->SetLabel(tools->translate("playerfoot" + std::to_string(m_spinButtonFoot->GetValue())));
}

void DialogPlayeredit::OnShirtNumber(wxSpinEvent& event)
{
    int lastValue = std::stoi(std::string(m_staticTextShirtNumber->GetLabel().mb_str()));
    int nextValue = m_spinButtonShirtNumber->GetValue();
    int oldValue = nextValue;
    
    //check if next value is possible
    if (lastValue < oldValue)
    {
        // up (find higher free shirt number)
        nextValue = findNextShirtNumber(oldValue, true);
    }
    else
    {
        // down
        nextValue = findNextShirtNumber(oldValue, false);
    }
    if (lastValue != nextValue)
        m_spinButtonShirtNumber->SetValue(nextValue);
    m_staticTextShirtNumber->SetLabel(std::to_string(m_spinButtonShirtNumber->GetValue()));
}

int DialogPlayeredit::findNextShirtNumber(int start, bool higher)
{
    int result = -1;
    for (int i = start; higher?i < 100:i > 0; higher?++i:--i)
    {
        bool found = false;
        for (auto player : m_players)
        {
            if (player->getShirtNumber() == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            result = i;
            break;
        }
    }
    if (result < 0)
    {
        for (int i = higher?1:99; higher?i < start:i > 0; higher?++i:--i)
        {
            bool found = false;
            for (auto player : m_players)
            {
                if (player->getShirtNumber() == i)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}