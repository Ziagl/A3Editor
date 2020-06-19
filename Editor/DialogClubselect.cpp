#include "DialogClubselect.h"
#include "DialogClubedit.h"
#include "DialogPlayeredit.h"
#include "Sorting.h"

DialogClubselect::DialogClubselect(wxWindow* parent,
    Toolset* const tools,
    const ClubselectType type,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), parent(parent), type(type)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer->SetFlexibleDirection(wxBOTH);
    flexGridSizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerCountryList = new wxBoxSizer(wxVERTICAL);

    flexGridSizer->Add(boxSizerCountryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerCountryList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseCountry")), wxVERTICAL);

    boxSizerCountryList->Add(staticBoxSizerCountryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_countryList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);

    initializeCountryList(m_countryList);

    staticBoxSizerCountryList->Add(m_countryList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerClubList = new wxBoxSizer(wxVERTICAL);

    flexGridSizer->Add(boxSizerClubList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerClubList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseClub")), wxVERTICAL);

    boxSizerClubList->Add(staticBoxSizerClubList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_clubList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);

    initializeClubList(m_clubList);

    staticBoxSizerClubList->Add(m_clubList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerRight = new wxBoxSizer(wxVERTICAL);

    flexGridSizer->Add(boxSizerRight, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizerRight->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizerRight->Add(m_buttonApply, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ABORT, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizerRight->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonSearchPlayer = new wxButton(this, wxID_ANY, tools->translate("buttonSearchPlayer"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizerRight->Add(m_buttonSearchPlayer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticBitmapClubImage = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizerRight->Add(m_staticBitmapClubImage, 0, wxALL | wxALIGN_CENTER, WXC_FROM_DIP(5));

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
#endif
*/

    // connect events
    // button events
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnAbort), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnEdit), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnApply), NULL, this);
    this->Connect(m_buttonSearchPlayer->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnSearchPlayer), NULL, this);
    // list events
    this->Connect(m_countryList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogClubselect::OnSelectCountry), NULL, this);
    this->Connect(m_clubList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogClubselect::OnSelectClub), NULL, this);
    this->Connect(m_clubList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogClubselect::OnSelectClubActivated), NULL, this);
}

DialogClubselect::~DialogClubselect()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnEdit), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnApply), NULL, this);
    this->Disconnect(m_buttonSearchPlayer->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnSearchPlayer), NULL, this);
    // list events
    this->Disconnect(m_countryList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogClubselect::OnSelectCountry), NULL, this);
    this->Disconnect(m_clubList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogClubselect::OnSelectClub), NULL, this);
    this->Disconnect(m_clubList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogClubselect::OnSelectClubActivated), NULL, this);
}

void DialogClubselect::OnSelectCountry(wxListEvent& event)
{
    m_selectedCountry = m_countryList->GetItemText(event.m_itemIndex, 1);

    // get a local copy of thet country to edit
    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    assert(countryId >= 0);
    m_country = std::make_shared<Core::Country>(*tools->getCountryById(countryId));

    updateClubList();
}

void DialogClubselect::OnSelectClub(wxListEvent& event)
{
    m_selectedClub = m_clubList->GetItemText(event.m_itemIndex, 0);
}

void DialogClubselect::OnSelectClubActivated(wxListEvent& event)
{
    m_selectedClub = m_clubList->GetItemText(event.m_itemIndex, 0);

    if (type == ClubselectType::TEAM)
    {
        DialogClubedit dlg(parent, tools);
        dlg.ShowModal();
    }
    if (type == ClubselectType::PLAYER)
    {
        DialogPlayeredit dlg(parent, tools, m_country);
        dlg.ShowModal();
    }
}

void DialogClubselect::OnSearchPlayer(wxCommandEvent& event)
{

}

void DialogClubselect::OnApply(wxCommandEvent& event)
{
    // change country object in graph
    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    auto country = tools->getCountryById(countryId);
    country = m_country;

    m_selectedCountry = std::string();
    m_selectedClub = std::string();
    wxUnusedVar(event);
    Close();
}

void DialogClubselect::OnEdit(wxCommandEvent& event)
{
    if (m_selectedClub.empty())
    {
        wxMessageBox(tools->translate("clubselectwarning"),
            tools->translate("warning"),
            wxOK | wxICON_WARNING, this);
    }
    else
    {
        if (type == ClubselectType::TEAM)
        {
            DialogClubedit dlg(parent, tools);
            dlg.ShowModal();
        }
        if (type == ClubselectType::PLAYER)
        {
            DialogPlayeredit dlg(parent, tools, m_country);
            dlg.ShowModal();
        }
    }
}

void DialogClubselect::OnAbort(wxCommandEvent& event)
{
    m_selectedCountry = std::string();
    m_selectedClub = std::string();
    wxUnusedVar(event);
    Close();
}

// initialize ListCtrl with columns and rows depending on input data
void DialogClubselect::initializeClubList(wxListCtrl* control)
{
    control->Hide();

    control->InsertColumn(0, tools->translate("name"), wxLIST_FORMAT_LEFT, 150);
    control->InsertColumn(1, tools->translate("averagestrength"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(2, tools->translate("league"), wxLIST_FORMAT_LEFT, 100);

    control->Show();

    control->SetMinSize(wxSize(300, 400));
}


/*
 * sort list so that order is the same as in original game
 */
int wxCALLBACK SortCountryList(wxIntPtr item1, wxIntPtr item2, wxIntPtr sortData)
{
    wxListCtrl* control = (wxListCtrl*)sortData;
    wxString str1 = control->GetItemText(item1, 0);
    wxString str2 = control->GetItemText(item2, 0);
    Sorting::replaceUmlauts(str1);
    Sorting::replaceUmlauts(str2);
    if (str1 > str2)
        return 1;
    else if (str2 > str1)
        return -1;
    else 
        return 0;
}

// initialize ListCtrl with columns and rows depending on input data
void DialogClubselect::initializeCountryList(wxListCtrl* control)
{
    control->Hide();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 100);
    control->InsertColumn(1, wxT(""), wxLIST_FORMAT_LEFT, 50);

    std::vector<std::string> list = tools->GetCountriesWithLeagues();

    long index = 0;
    for (std::string country : list)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, tools->translate(country));   // set text column 1
        control->SetItem(result, 1, country);                     // set text column 2
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }
    
    // sort list
    control->SortItems(SortCountryList, (wxIntPtr)control);
    
    control->Show();

    control->SetMinSize(wxSize(180, 400));
}

/*
 * sort list so that order is the same as in original game
 */
int wxCALLBACK SortClubList(wxIntPtr item1, wxIntPtr item2, wxIntPtr sortData)
{
    wxListCtrl* control = (wxListCtrl*)sortData;
    wxString str1 = control->GetItemText(item1, 1);
    wxString str2 = control->GetItemText(item2, 1);
    float value1 = std::stof(std::string(str1.c_str()));
    float value2 = std::stof(std::string(str2.c_str()));
    if (value1 < value2)
        return 1;
    else if (value2 < value1)
        return -1;
    else
        return 0;
}

// update list of clubs based on current selected country
void DialogClubselect::updateClubList()
{
    // m_selectedCountry holds 3 charcter country code of selected line
    // get country
    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    assert(countryId>=0);
    auto country = tools->getCountryById(countryId);

    // if there is a country (which should)
    if (countryId >= 0)
    {
        // get all connected teams
        auto teamIds = tools->getTeamIdsByCountryId(countryId);

        m_clubList->Hide();
        m_clubList->DeleteAllItems();

        long index = 0;
        for (auto teamId : teamIds)
        {
            auto team = tools->getTeamById(teamId);
            // get all connected players
            auto playerIds = tools->getPlayerIdsByTeamId(teamId);
            // get connected league
            std::string leagueName = "-";
            auto leagueId = tools->getLeagueIdByTeamId(teamId);
            if (leagueId != 0)
            {
                auto league = tools->getLeagueById(leagueId);
                leagueName = league->getShortname();
            }
            // compute average skill of players
            float averageSkill = 0.0;
            for (auto playerId : playerIds)
            {
                auto player = tools->getPlayerById(playerId);
                averageSkill += player->getSkill();
            }
            averageSkill /= playerIds.size();

            long result = m_clubList->InsertItem(index, wxString::Format("Item %d", index));
            m_clubList->SetItem(result, 0, team->getName());                            // set text column 1
            m_clubList->SetItem(result, 1, wxString::Format("%.2f", averageSkill));     // set text column 2
            m_clubList->SetItem(result, 2, leagueName);                                 // set text column 3
            m_clubList->SetItemData(result, index);      // needed, otherwise SortItems does not work

            index++;
        }

        // sort list
        m_clubList->SortItems(SortClubList, (wxIntPtr)m_clubList);

        m_clubList->Show();
    }
}