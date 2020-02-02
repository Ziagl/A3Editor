#include "DialogClubselect.h"

DialogClubselect::DialogClubselect(wxWindow* parent,
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

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainSizer);

    wxBoxSizer* boxSizerLeft = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizerLeft, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerCountryList = new wxBoxSizer(wxVERTICAL);

    boxSizerLeft->Add(boxSizerCountryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerCountryList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseCountry")), wxVERTICAL);

    boxSizerCountryList->Add(staticBoxSizerCountryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_countryList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);

    initializeCountryList(m_countryList);

    staticBoxSizerCountryList->Add(m_countryList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerClubList = new wxBoxSizer(wxVERTICAL);

    boxSizerLeft->Add(boxSizerClubList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerClubList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseClub")), wxVERTICAL);

    boxSizerClubList->Add(staticBoxSizerClubList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_clubList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);

    initializeClubList(m_clubList);

    staticBoxSizerClubList->Add(m_clubList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerRight = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizerRight, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    int buttonWidth = 150;

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(buttonWidth, -1)), 0);

    boxSizerRight->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(buttonWidth, -1)), 0);

    boxSizerRight->Add(m_buttonApply, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ABORT, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(buttonWidth, -1)), 0);

    boxSizerRight->Add(m_buttonAbort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonSearchPlayer = new wxButton(this, wxID_ANY, tools->translate("buttonSearchPlayer"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(buttonWidth, -1)), 0);

    boxSizerRight->Add(m_buttonSearchPlayer, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticBitmapClubImage = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizerRight->Add(m_staticBitmapClubImage, 0, wxALL | wxALIGN_CENTER, WXC_FROM_DIP(5));

/*   SetName(wxT("MainDialogBaseClass"));
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
#if wxVERSION_NUMBER >= 2900
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
    this->Connect(m_countryList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogClubselect::OnSelectClub), NULL, this);
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
    this->Disconnect(m_countryList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogClubselect::OnSelectClub), NULL, this);
}

void DialogClubselect::OnSelectClub(wxListEvent& event)
{
    m_selectedCountry = m_countryList->GetItemText(event.m_itemIndex, 1);
}

void DialogClubselect::OnSearchPlayer(wxCommandEvent& event)
{

}

void DialogClubselect::OnApply(wxCommandEvent& event)
{

}

void DialogClubselect::OnEdit(wxCommandEvent& event)
{
    long itemIndex = -1;
    bool found = false;

    while ((itemIndex = m_clubList->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
    {
        m_selectedClub = m_clubList->GetItemText(itemIndex, 1);
        found = true;
    }

    if (found)
    {
        m_selectedCountry = std::string();
        m_selectedClub = std::string();
        wxUnusedVar(event);
        Close();
    }
    else
    {
        wxMessageBox(tools->translate("clubselectwarning"),
            tools->translate("warning"),
            wxOK | wxICON_WARNING, this);
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
    m_clubList->Hide();

    m_clubList->InsertColumn(0, tools->translate("name"), wxLIST_FORMAT_LEFT, 150);
    m_clubList->InsertColumn(1, tools->translate("averagestrength"), wxLIST_FORMAT_LEFT, 50);
    m_clubList->InsertColumn(2, tools->translate("league"), wxLIST_FORMAT_LEFT, 100);

    m_clubList->Show();

    m_clubList->SetMinSize(wxSize(300, 400));
}

// initialize ListCtrl with columns and rows depending on input data
void DialogClubselect::initializeCountryList(wxListCtrl* control)
{
    m_countryList->Hide();

    m_countryList->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 100);
    m_countryList->InsertColumn(1, wxT(""), wxLIST_FORMAT_LEFT, 50);

    std::vector<std::string> list = tools->GetCountriesWithLeagues();
    std::reverse(list.begin(), list.end());

    for (std::string country : list)
    {
        long index = m_countryList->InsertItem(0, tools->translate(country));
        m_countryList->SetItem(index, 1, country);
    }

    m_countryList->Show();

    m_countryList->SetMinSize(wxSize(180, 400));
}