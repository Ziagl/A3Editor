#include "DialogTrainer.h"

DialogTrainer::DialogTrainer(wxWindow* parent,
    Toolset* const tools,
    std::string const selectedCountry,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxBoxSizer* boxSizer31 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer29 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Bitte Trainer auswählen")), wxHORIZONTAL);

    boxSizer31->Add(staticBoxSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString m_listBox35Arr;
    m_trainerList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);

    initializeTrainerList(m_trainerList);

    staticBoxSizer29->Add(m_trainerList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer33 = new wxBoxSizer(wxVERTICAL);

    boxSizer31->Add(boxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, _("Editieren"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonEdit, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, _("Übernehmen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonApply, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, _("Abbrechen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

    /*SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
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
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnAbort), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnApply), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnEdit), NULL, this);
}

DialogTrainer::~DialogTrainer()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnEdit), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainer::OnApply), NULL, this);
}

void DialogTrainer::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogTrainer::OnApply(wxCommandEvent& event)
{

}

void DialogTrainer::OnEdit(wxCommandEvent& event)
{
}

void DialogTrainer::initializeTrainerList(wxListCtrl* control)
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
    //control->SortItems(SortCountryList, (wxIntPtr)m_countryList);

    control->Show();

    control->SetMinSize(wxSize(180, 400));
}