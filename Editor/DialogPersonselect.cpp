#include "DialogPersonselect.h"
#include "DialogPerson.h"
#include "DialogReferee.h"
#include "Sorting.h"

DialogPersonselect::DialogPersonselect(wxWindow* parent,
    Toolset* const tools,
    std::string const selectedCountry,
    short type,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry), parent(parent), type(type)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    if (type == PersonType::INTERNATIONALREFEREE)
    {
        m_international = tools->getInternational();
        m_referees = m_international->getReferees();
    }
    else
    {
        auto countryId = tools->getCountryIdByShortname(selectedCountry);
        m_country = tools->getCountryById(countryId);
    }

    if (type == PersonType::REFEREE)
    {
        m_referees = m_country->getReferees();
    }
    if (type == PersonType::MANAGER)
    {
        m_managers = m_country->getUnemployedManager();
    }
    if (type == PersonType::COTRAINER)
    {
        m_trainer = m_country->getCoTrainer();
    }
    if (type == PersonType::GOALKEEPER)
    {
        m_trainer = m_country->getGoalKeeperTrainer();
    }

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer->SetFlexibleDirection(wxBOTH);
    flexGridSizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    std::string staticText = "chooseTrainer";
    if (type == PersonType::GOALKEEPER)
        staticText = "chooseGoalkeeperTrainer";
    if (type == PersonType::MANAGER)
        staticText = "chooseManager";
    if (type == PersonType::REFEREE || type == PersonType::INTERNATIONALREFEREE)
        staticText = "chooseReferee";
    wxStaticBoxSizer* staticBoxSizer29 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate(staticText)), wxHORIZONTAL);

    flexGridSizer->Add(staticBoxSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString m_listBox35Arr;
    m_personList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);

    initializePersonList(m_personList);

    staticBoxSizer29->Add(m_personList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer33 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer->Add(boxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonApply, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPersonselect::OnAbort), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPersonselect::OnApply), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPersonselect::OnEdit), NULL, this);
    // list events
    this->Connect(m_personList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPersonselect::OnSelectPerson), NULL, this);
    this->Connect(m_personList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogPersonselect::OnSelectPersonActivated), NULL, this);
}

DialogPersonselect::~DialogPersonselect()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPersonselect::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPersonselect::OnEdit), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogPersonselect::OnApply), NULL, this);
    // list events
    this->Disconnect(m_personList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogPersonselect::OnSelectPerson), NULL, this);
    this->Disconnect(m_personList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogPersonselect::OnSelectPersonActivated), NULL, this);
}

void DialogPersonselect::OnAbort(wxCommandEvent& event)
{
    m_selectedPerson.clear();
    wxUnusedVar(event);
    Close();
}

void DialogPersonselect::OnApply(wxCommandEvent& event)
{
    if (type == PersonType::REFEREE)
    {
        m_country->setReferees(m_referees);
    }
    if (type == PersonType::INTERNATIONALREFEREE)
    {
        m_international->setReferees(m_referees);
    }

    wxUnusedVar(event);
    Close();
}

void DialogPersonselect::OnEdit(wxCommandEvent& event)
{
    if (!m_selectedPerson.empty())
    {
        if (type == PersonType::REFEREE || type == PersonType::INTERNATIONALREFEREE)
        {
            callRefereeDialog();
        }
        else
        {
            callPersonDialog();
        }
        initializePersonList(m_personList);
    }
}

void DialogPersonselect::OnSelectPerson(wxListEvent& event)
{
    m_selectedPerson = m_personList->GetItemText(event.m_itemIndex, 0);
}

void DialogPersonselect::OnSelectPersonActivated(wxListEvent& event)
{
    m_selectedPerson = m_personList->GetItemText(event.m_itemIndex, 0);

    if (type == PersonType::REFEREE || type == PersonType::INTERNATIONALREFEREE)
    {
        callRefereeDialog();
    }
    else
    {
        callPersonDialog();
    }
    initializePersonList(m_personList);
}

/*
 * sort list so that order is the same as in original game
 */
int wxCALLBACK SortPersonList(wxIntPtr item1, wxIntPtr item2, wxIntPtr sortData)
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

void DialogPersonselect::initializePersonList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, tools->translate("name"), wxLIST_FORMAT_LEFT, type == PersonType::COTRAINER || type == PersonType::REFEREE || type == PersonType::INTERNATIONALREFEREE ? 175 : 250);
    control->InsertColumn(1, tools->translate("comp"), wxLIST_FORMAT_LEFT, 50);
    if(type == PersonType::REFEREE)
        control->InsertColumn(2, tools->translate("severity"), wxLIST_FORMAT_LEFT, 50);
    else
        control->InsertColumn(2, tools->translate("age"), wxLIST_FORMAT_LEFT, 50);
    if (type == PersonType::COTRAINER)
        control->InsertColumn(3, tools->translate("type"), wxLIST_FORMAT_LEFT, 75);
    if (type == PersonType::REFEREE)
        control->InsertColumn(3, tools->translate("unpopularclub"), wxLIST_FORMAT_LEFT, 75);
    if(type==PersonType::INTERNATIONALREFEREE)
        control->InsertColumn(3, tools->translate("country"), wxLIST_FORMAT_LEFT, 75);

    vertex_t countryId;
    std::shared_ptr<Core::Country> country;

    if (type != PersonType::INTERNATIONALREFEREE)
    {
        countryId = tools->getCountryIdByShortname(m_selectedCountry);
        country = tools->getCountryById(countryId);
    }

    long index = 0;
    if (type == PersonType::MANAGER)
    {
        for(auto manager : country->getUnemployedManager())
        {
            long result = control->InsertItem(index, wxString::Format("Item %d", index));
            control->SetItem(result, 0, manager.getLastname() + ", " + manager.getFirstname());         // set text column 1
            control->SetItem(result, 1, std::to_string(manager.getCompetence()));                       // set text column 2
            control->SetItem(result, 2, std::to_string(manager.getAge()));                              // set text column 3
            control->SetItemData(result, index);      // needed, otherwise SortItems does not work
            ++index;
        }
    }
    else if (type == PersonType::REFEREE)
    {
        auto teamIds = tools->getTeamIdsByCountryId(countryId);

        for (auto referee : country->getReferees())
        {
            long result = control->InsertItem(index, wxString::Format("Item %d", index));
            control->SetItem(result, 0, referee.getLastname() + ", " + referee.getFirstname());         // set text column 1
            control->SetItem(result, 1, std::to_string(referee.getCompetence()));                       // set text column 2
            control->SetItem(result, 2, std::to_string(referee.getHardness()));                         // set text column 3
            int unpopularTeam = referee.getUnpopularTeamNationality();
            if(unpopularTeam > 0)
                for (auto teamId : teamIds)
                {
                    auto team = tools->getTeamById(teamId);
                    if (team->getTeamId() == unpopularTeam)
                    {
                        control->SetItem(result, 3, team->getName());      // set text column 4
                        break;
                    }
                }
            else
                control->SetItem(result, 3, tools->translate("none"));     // set text column 4
            control->SetItemData(result, index);        // needed, otherwise SortItems does not work
            index++;
        }
    }
    else if (type == PersonType::INTERNATIONALREFEREE)
    {
        for (auto referee : m_referees)
        {
            long result = control->InsertItem(index, wxString::Format("Item %d", index));
            control->SetItem(result, 0, referee.getLastname() + ", " + referee.getFirstname());         // set text column 1
            control->SetItem(result, 1, std::to_string(referee.getCompetence()));                       // set text column 2
            control->SetItem(result, 2, std::to_string(referee.getHardness()));                         // set text column 3
            int nationIndex = referee.getUnpopularTeamNationality();
            if (nationIndex > 0)
            {
                auto nationId = tools->getNationIdByIndex(nationIndex);
                auto nation = tools->getNationById(nationId);
                control->SetItem(result, 3, nation->getName());
            }
            else
                control->SetItem(result, 3, tools->translate("none"));     // set text column 4
            control->SetItemData(result, index);        // needed, otherwise SortItems does not work
            index++;
        }
    }
    else
    {
        for (auto trainer : type == PersonType::COTRAINER ? country->getCoTrainer() : country->getGoalKeeperTrainer())
        {
            long result = control->InsertItem(index, wxString::Format("Item %d", index));
            control->SetItem(result, 0, trainer.getLastname() + ", " + trainer.getFirstname());         // set text column 1
            control->SetItem(result, 1, std::to_string(trainer.getCompetence()));                       // set text column 2
            control->SetItem(result, 2, std::to_string(trainer.getAge()));                              // set text column 3
            if (type == PersonType::COTRAINER)
                control->SetItem(result, 3, tools->translateTrainerCompetence(trainer.getReputation()));// set text column 4
            control->SetItemData(result, index);      // needed, otherwise SortItems does not work
            index++;
        }
    }

    // sort list
    control->SortItems(SortPersonList, (wxIntPtr)control);

    control->Show();

    control->SetMinSize(wxSize(375, 300));
}

void DialogPersonselect::callRefereeDialog()
{
    int index = 0;
    for (auto referee : m_referees)
    {
        if (referee.getLastname() + ", " + referee.getFirstname() == m_selectedPerson)
        {
            break; // break outer for loop, trainer was found
        }
        ++index;
    }
    
    DialogReferee dlg(parent, tools, m_selectedCountry, m_referees.at(index), type);
    dlg.ShowModal();
}

void DialogPersonselect::callPersonDialog()
{
    int personIndex = 0;
    if (type == PersonType::MANAGER)
    {
        for (auto m : m_managers)
        {
            if (m.getLastname() + ", " + m.getFirstname() == m_selectedPerson)
            {
                break; // break outer for loop, trainer was found
            }
            ++personIndex;
        }
        DialogPerson dlg(parent, tools, m_selectedCountry, m_managers.at(personIndex), type, wxID_ANY, tools->translate("changeManager"));
        dlg.ShowModal();
    }
    if (type == PersonType::COTRAINER || type == PersonType::GOALKEEPER)
    {
        for (auto t : m_trainer)
        {
            if (t.getLastname() + ", " + t.getFirstname() == m_selectedPerson)
            {
                break; // break outer for loop, trainer was found
            }
            ++personIndex;
        }
        DialogPerson dlg(parent, tools, m_selectedCountry, m_trainer.at(personIndex), type, wxID_ANY, type == PersonType::COTRAINER ? tools->translate("changeTrainer") : tools->translate("changeGoalkeeperTrainer"));
        dlg.ShowModal();
    }
}