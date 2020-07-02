#include "DialogEuropeanWorldChampionshipEdit.h"

DialogEuropeanWorldChampionshipEdit::DialogEuropeanWorldChampionshipEdit(wxWindow* parent,
    Toolset* const tools,
    Core::EMWM& emwm,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_emwm(emwm)
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

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseVenue")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wchar_t buffer[100];
    if(m_emwm.type == 0)
        swprintf(buffer, 100, tools->translate("europeanChampionshipIn").c_str(), m_emwm.year);
    else if (m_emwm.type == 1)
        swprintf(buffer, 100, tools->translate("worldCupIn").c_str(), m_emwm.year);
    m_staticText = new wxStaticText(this, wxID_ANY, buffer, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer19->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString choiceCountryArr;
    if (m_emwm.type == 0)
        m_countryList = tools->getEuropeanChampionshipCountries();
    else if (m_emwm.type == 1)
        m_countryList = tools->getWorldCupCountries();
    auto nationId = tools->getNationIdByIndex(m_emwm.nationIndex);
    auto nation = tools->getNationById(nationId);
    int index = 0;
    for (auto country : m_countryList)
    {
        if (nation->getShortname() == country)
            m_selectedCountry = index;
        choiceCountryArr.Add(tools->translate(country));
        ++index;
    }
    m_choiceCountry = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), choiceCountryArr, 0);
    m_choiceCountry->SetSelection(m_selectedCountry);

    staticBoxSizer19->Add(m_choiceCountry, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOk, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionshipEdit::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionshipEdit::OnAbort), NULL, this);
}

DialogEuropeanWorldChampionshipEdit::~DialogEuropeanWorldChampionshipEdit()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOk->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionshipEdit::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogEuropeanWorldChampionshipEdit::OnAbort), NULL, this);
}

void DialogEuropeanWorldChampionshipEdit::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogEuropeanWorldChampionshipEdit::OnOk(wxCommandEvent& event)
{
    int index = m_choiceCountry->GetSelection();
    std::string shortname = m_countryList.at(index);
    auto nationIds = tools->getNationIds();
    for (auto nationId : nationIds)
    {
        auto nation = tools->getNationById(nationId);
        if (nation->getShortname() == shortname)
        {
            m_emwm.nationIndex = nation->getCountryId();
            break;
        }
    }
    wxUnusedVar(event);
    Close();
}