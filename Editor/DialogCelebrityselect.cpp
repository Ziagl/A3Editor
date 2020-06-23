#include "DialogCelebrityselect.h"
#include "DialogCelebrityedit.h"

DialogCelebrityselect::DialogCelebrityselect(wxWindow* parent, 
    Toolset* const tools, 
    const std::string selectedCountry,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry), m_selectedCelebrityIndex(-1)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    m_country = tools->getCountryById(countryId);
    m_celebrities = m_country->getCelebrities();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseCelebrity")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlCelebrities = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_SINGLE_SEL);
    initializeCelebritiesList(m_listCtrlCelebrities);

    staticBoxSizer19->Add(m_listCtrlCelebrities, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonApply, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCelebrityselect::OnApply), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCelebrityselect::OnAbort), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCelebrityselect::OnEdit), NULL, this);
    // list events
    this->Connect(m_listCtrlCelebrities->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogCelebrityselect::OnSelectCelebrity), NULL, this);
    this->Connect(m_listCtrlCelebrities->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogCelebrityselect::OnSelectCelebrityActivated), NULL, this);
}

DialogCelebrityselect::~DialogCelebrityselect()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCelebrityselect::OnApply), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCelebrityselect::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCelebrityselect::OnEdit), NULL, this);
    // list events
    this->Disconnect(m_listCtrlCelebrities->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogCelebrityselect::OnSelectCelebrity), NULL, this);
    this->Disconnect(m_listCtrlCelebrities->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogCelebrityselect::OnSelectCelebrityActivated), NULL, this);
}

void DialogCelebrityselect::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogCelebrityselect::OnApply(wxCommandEvent& event)
{
    m_country->setCelebrity(m_celebrities);
    wxUnusedVar(event);
    Close();
}

void DialogCelebrityselect::OnEdit(wxCommandEvent& event)
{
    if (m_selectedCelebrityIndex > 0)
    {
        DialogCelebrityedit dlg(parent, tools, m_selectedCountry, m_celebrities.at(m_selectedCelebrityIndex), wxID_ANY, tools->translate("changeCelebrity"));
        dlg.ShowModal();
        initializeCelebritiesList(m_listCtrlCelebrities);
    }
}

void DialogCelebrityselect::OnSelectCelebrity(wxListEvent& event)
{
    m_selectedCelebrityIndex = event.m_itemIndex;
}

void DialogCelebrityselect::OnSelectCelebrityActivated(wxListEvent& event)
{
    m_selectedCelebrityIndex = event.m_itemIndex;

    DialogCelebrityedit dlg(parent, tools, m_selectedCountry, m_celebrities.at(m_selectedCelebrityIndex), wxID_ANY, tools->translate("changeCelebrity"));
    dlg.ShowModal();
    initializeCelebritiesList(m_listCtrlCelebrities);
}

void DialogCelebrityselect::initializeCelebritiesList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, tools->translate("name"), wxLIST_FORMAT_LEFT, 200);
    control->InsertColumn(1, tools->translate("favouriteClub"), wxLIST_FORMAT_LEFT, 180);

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    auto teamIds = tools->getTeamIdsByCountryId(countryId);

    long index = 0;
    for (auto celebrity : m_celebrities)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, celebrity.getLastname() + ", " + celebrity.getFirstname());
        if (celebrity.getFavoriteTeam() > 0)
        {
            for (auto teamId : teamIds)
            {
                auto team = tools->getTeamById(teamId);
                if (team->getTeamId() == celebrity.getFavoriteTeam())
                {
                    control->SetItem(result, 1, team->getName());
                }
            }
        }
        else
        {
            control->SetItem(result, 1, tools->translate("none"));
        }
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        ++index;
    }

    control->Show();

    control->SetMinSize(wxSize(400, 280));
}