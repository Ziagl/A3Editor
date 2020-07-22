#include "DialogPlayersearch.h"
#include <locale>
#include <codecvt>

DialogPlayersearch::DialogPlayersearch(wxWindow* parent, 
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

    wxFlexGridSizer* flexGridSizer61 = new wxFlexGridSizer(4, 1, 0, 0);
    flexGridSizer61->SetFlexibleDirection(wxBOTH);
    flexGridSizer61->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer61, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer62 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer62->SetFlexibleDirection(wxBOTH);
    flexGridSizer62->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer62->AddGrowableCol(1);

    flexGridSizer61->Add(flexGridSizer62, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer23 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("selection")), wxVERTICAL);

    flexGridSizer62->Add(staticBoxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioSearchPerson = new wxRadioButton(this, wxID_ANY, tools->translate("searchPerson"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioSearchPerson->SetValue(true);

    staticBoxSizer23->Add(m_radioSearchPerson, 0, wxALL, WXC_FROM_DIP(5));

    m_radioCheckData = new wxRadioButton(this, wxID_ANY, tools->translate("checkData"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioCheckData->SetValue(false);

    staticBoxSizer23->Add(m_radioCheckData, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonStart = new wxButton(this, wxID_ANY, tools->translate("start"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, 25)), 0);

    staticBoxSizer23->Add(m_buttonStart, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("person")), wxVERTICAL);

    flexGridSizer62->Add(staticBoxSizer25, 2, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticFirstname = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer25->Add(m_staticFirstname, 0, wxALL, WXC_FROM_DIP(0));

    m_textFirstname = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstname->SetHint(wxT(""));
#endif

    staticBoxSizer25->Add(m_textFirstname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticLastname = new wxStaticText(this, wxID_ANY, tools->translate("lastname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer25->Add(m_staticLastname, 0, wxALL, WXC_FROM_DIP(0));

    m_textLastname = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textLastname->SetHint(wxT(""));
#endif

    staticBoxSizer25->Add(m_textLastname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("searchedSoFar")), wxVERTICAL);

    flexGridSizer61->Add(staticBoxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer63 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer63->SetFlexibleDirection(wxBOTH);
    flexGridSizer63->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer63->AddGrowableCol(0);

    staticBoxSizer27->Add(flexGridSizer63, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_gaugeProgress = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxGA_HORIZONTAL);
    m_gaugeProgress->SetValue(0);

    flexGridSizer63->Add(m_gaugeProgress, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextPercent = new wxStaticText(this, wxID_ANY, wxT("  0 %"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer63->Add(m_staticTextPercent, 0, wxALL, WXC_FROM_DIP(5));

    m_staticTextProgress = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer27->Add(m_staticTextProgress, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer33 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("entriesFound")), wxVERTICAL);

    flexGridSizer61->Add(staticBoxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listSearchResult = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    m_listSearchResult->SetMinSize(wxSize(400, -1));

    staticBoxSizer33->Add(m_listSearchResult, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer61->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonCancel = new wxButton(this, wxID_ANY, tools->translate("buttonLeaving"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonCancel, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("DialogPlayersearch"));
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
    this->Connect(m_buttonCancel->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnCancel), NULL, this);
    this->Connect(m_buttonStart->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnStart), NULL, this);
}

DialogPlayersearch::~DialogPlayersearch()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonCancel->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnCancel), NULL, this);
    this->Disconnect(m_buttonStart->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPlayersearch::OnStart), NULL, this);
}

void DialogPlayersearch::OnCancel(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogPlayersearch::OnStart(wxCommandEvent& event)
{
    if (m_radioSearchPerson->GetValue())
    {
        searchPerson();
    }
    else if (m_radioCheckData->GetValue())
    {
        checkData();
    }
}

void DialogPlayersearch::searchPerson()
{
    std::vector<std::string> result;
    std::string firstname = std::string(m_textFirstname->GetValue().c_str());
    std::string lastname = std::string(m_textLastname->GetValue().c_str());
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    // search for player
    auto playerIds = tools->getPlayerIds();
    for (auto playerId : playerIds)
    {
        auto player = tools->getPlayerById(playerId);
        auto teamId = tools->getTeamIdByPlayerId(playerId);
        auto team = tools->getTeamById(teamId);
        auto nationId = tools->getNationIdByIndex(team->getCountryId());
        auto nation = tools->getNationById(nationId);
        if (firstname.empty() || player->getFirstname() == firstname)
        {
            if (lastname.empty() || player->getLastname() == lastname)
            {
                if (!(player->getFirstname().empty() && player->getLastname().empty()))
                {
                    result.push_back(converter.to_bytes(tools->translate("player")) + ", " + 
                                     tools->positionToString(player->getMainPosition()) + ", " + converter.to_bytes(tools->translate("skill")) + " " + std::to_string(player->getSkill()) + ", " +
                                     team->getName() + " (" + nation->getShortname() + "), " +
                                     player->getFirstname() + " " + player->getLastname());
                }
            }
        }
    }

    // search for referee trainer / manager
    auto countryIds = tools->getCountryIds();
    int i = 0;
    for (auto countryId : countryIds)
    {
        auto country = tools->getCountryById(countryId);
        auto nationId = tools->getNationIdByCountryId(countryId);
        auto nation = tools->getNationById(nationId);
        // referees
        for (auto referee : country->getReferees())
        {
            if (firstname.empty() || referee.getFirstname() == firstname)
            {
                if (lastname.empty() || referee.getLastname() == lastname)
                {
                    result.push_back(converter.to_bytes(tools->translate("refereePool")) + ", " +
                        nation->getName() + ", " +
                        referee.getFirstname() + " " + referee.getLastname());
                }
            }
        }

        // trainer pool
        for (auto trainer : country->getCoTrainer())
        {
            if (firstname.empty() || trainer.getFirstname() == firstname)
            {
                if (lastname.empty() || trainer.getLastname() == lastname)
                {
                    result.push_back(converter.to_bytes(tools->translate("trainerPool")) + ", " +
                                     nation->getName() + ", " +
                                     trainer.getFirstname() + " " + trainer.getLastname());
                }
            }
        }
        for (auto trainer : country->getGoalKeeperTrainer())
        {
            if (firstname.empty() || trainer.getFirstname() == firstname)
            {
                if (lastname.empty() || trainer.getLastname() == lastname)
                {
                    result.push_back(converter.to_bytes(tools->translate("trainerPool")) + ", " +
                                     nation->getName() + ", " +
                                     trainer.getFirstname() + " " + trainer.getLastname());
                }
            }
        }
        // manager pool
        for (auto manager : country->getUnemployedManager())
        {
            if (firstname.empty() || manager.getFirstname() == firstname)
            {
                if (lastname.empty() || manager.getLastname() == lastname)
                {
                    result.push_back(converter.to_bytes(tools->translate("managerPool")) + ", " +
                                     nation->getName() + ", " +
                                     manager.getFirstname() + " " + manager.getLastname());
                }
            }
        }

        auto teamIds = tools->getTeamIdsByCountryId(countryId);
        // all teams
        for (auto teamId : teamIds)
        {
            auto team = tools->getTeamById(teamId);
            auto trainer = team->getTrainer();
            auto manager = team->getManager();
            if (firstname.empty() || trainer.getFirstname() == firstname)
            {
                if (lastname.empty() || trainer.getLastname() == lastname)
                {
                    result.push_back(converter.to_bytes(tools->translate("clubCoach")) + ", " + 
                                     team->getName() + ", " +
                                     trainer.getFirstname() + " " + trainer.getLastname());
                }
            }
            if (firstname.empty() || manager.getFirstname() == firstname)
            {
                if (lastname.empty() || manager.getLastname() == lastname)
                {
                    result.push_back(converter.to_bytes(tools->translate("clubManager")) + ", " +
                                     team->getName() + ", " +
                                     manager.getFirstname() + " " + manager.getLastname());
                }
            }
        }

        ++i;
        setProgress(((i * 100) / countryIds.size()), tools->translate("createList"));
    }

    // other player
    for (auto playerId : tools->getOtherPlayerIds())
    {
        auto player = tools->getPlayerById(playerId);
        if (firstname.empty() || player->getFirstname() == firstname)
        {
            if (lastname.empty() || player->getLastname() == lastname)
            {
                result.push_back(converter.to_bytes(tools->translate("menuOtherPlayer")) + ", " +
                                 tools->positionToString(player->getMainPosition()) + ", " + converter.to_bytes(tools->translate("skill")) + " " + std::to_string(player->getSkill()) + ", " +
                                 ", " +
                                 player->getFirstname() + " " + player->getLastname());
            }
        }
    }

    setProgress(100, tools->translate("finished"));

    if (result.empty())
    {
        wxMessageBox(tools->translate("noPlayerFound"), wxT("EDITOR"), wxYES_NO | wxICON_INFORMATION, this);
    }
    else
    {
        m_listSearchResult->Hide();
        m_listSearchResult->ClearAll();

        m_listSearchResult->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 400);

        long index = 0;
        for (auto item : result)
        {
            long result = m_listSearchResult->InsertItem(index, wxString::Format("Item %d", index));
            m_listSearchResult->SetItem(result, 0,item);
            m_listSearchResult->SetItemData(result, index);

            index++;
        }

        m_listSearchResult->Show();
    }
}

void DialogPlayersearch::checkData()
{
    std::vector<std::tuple<std::string, vertex_t>> list;
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    m_listSearchResult->Hide();
    m_listSearchResult->ClearAll();

    m_listSearchResult->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 400);

    long index = 0;
    // search for double players
    auto playerIds = tools->getPlayerIds();
    int i = 0;
    int lastPercent = -1;
    for (auto playerId : playerIds)
    {
        auto player = tools->getPlayerById(playerId);
        auto name = player->getFirstname() + " " + player->getLastname();
        // find duplicate in compare list
        for (auto element : list)
        {
            if (std::get<0>(element) == name)
            {
                auto otherplayer = tools->getPlayerById(std::get<1>(element));

                // add to output:
                // player details
                auto teamId = tools->getTeamIdByPlayerId(playerId);
                auto team = tools->getTeamById(teamId);
                auto nationId = tools->getNationIdByIndex(team->getCountryId());
                auto nation = tools->getNationById(nationId);
                std::string output = converter.to_bytes(tools->translate("player")) + ", " +
                                     tools->positionToString(player->getMainPosition()) + ", " + converter.to_bytes(tools->translate("skill")) + " " + std::to_string(player->getSkill()) + ", " +
                                     team->getName() + " (" + nation->getShortname() + "), " +
                                     player->getFirstname() + " " + player->getLastname();
                long result = m_listSearchResult->InsertItem(index, wxString::Format("Item %d", index));
                m_listSearchResult->SetItem(result, 0, output);
                m_listSearchResult->SetItemData(result, index);
                index++;

                // other player details
                teamId = tools->getTeamIdByPlayerId(std::get<1>(element));
                team = tools->getTeamById(teamId);
                nationId = tools->getNationIdByIndex(team->getCountryId());
                nation = tools->getNationById(nationId);
                output = converter.to_bytes(tools->translate("player")) + ", " +
                         tools->positionToString(otherplayer->getMainPosition()) + ", " + converter.to_bytes(tools->translate("skill")) + " " + std::to_string(otherplayer->getSkill()) + ", " +
                         team->getName() + " (" + nation->getShortname() + "), " +
                         otherplayer->getFirstname() + " " + otherplayer->getLastname();
                result = m_listSearchResult->InsertItem(index, wxString::Format("Item %d", index));
                m_listSearchResult->SetItem(result, 0, output);
                m_listSearchResult->SetItemData(result, index);
                index++;

                // empty line
                result = m_listSearchResult->InsertItem(index, wxString::Format("Item %d", index));
                m_listSearchResult->SetItem(result, 0, "");
                m_listSearchResult->SetItemData(result, index);
                index++;
            }
        }
        list.push_back(std::make_tuple(name, playerId));

        ++i;
        int percent = (i * 100) / playerIds.size();
        if (percent != lastPercent)
        {
            setProgress(percent, tools->translate("createList"));
            lastPercent = percent;
        }
    }

    setProgress(100, tools->translate("finished"));

    m_listSearchResult->Show();
}

void DialogPlayersearch::setProgress(int percent, wxString text)
{
    m_gaugeProgress->SetValue(percent);
    m_staticTextPercent->SetLabel(std::to_string(percent) + " %");
    m_staticTextProgress->SetLabel(text);
    this->Refresh();
}