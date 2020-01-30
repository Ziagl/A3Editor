#include "DialogCountryselect.h"

DialogCountryselect::DialogCountryselect(wxWindow* parent,
    Toolset* const tools,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style)
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

    mainSizer->Add(boxSizerLeft, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerCountryList = new wxBoxSizer(wxVERTICAL);

    boxSizerLeft->Add(boxSizerCountryList, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerCountryList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseCountry")), wxVERTICAL);

    boxSizerCountryList->Add(staticBoxSizerCountryList, 0, wxALL, WXC_FROM_DIP(5));

    m_countryList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);

    m_countryList->InsertColumn(0, wxT("Col1"), wxLIST_FORMAT_LEFT, 50);
    m_countryList->InsertColumn(1, wxT("Col2"), wxLIST_FORMAT_LEFT, 50);
    ////GUI Items Creation End

    // to speed up inserting we hide the control temporarily
    m_countryList->Hide();

    for (int i = 0; i < 100; ++i)
    {
        wxListItem item;
        item.SetId(i);

        m_countryList->InsertItem(item);
        m_countryList->SetItem(i, 0, wxString::Format("Item %d", i));
        m_countryList->SetItem(i, 1, wxString::Format("Item1 %d", i));
    }

    m_countryList->Show();

    m_countryList->SetMinSize(wxSize(150, 300));

    staticBoxSizerCountryList->Add(m_countryList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerRight = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizerRight, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDefaultSize, 0);

    boxSizerRight->Add(m_buttonEdit, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ABORT, tools->translate("buttonAbort"), wxDefaultPosition, wxDefaultSize, 0);

    boxSizerRight->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));


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

    // Connect events
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCountryselect::OnAbort), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCountryselect::OnEdit), NULL, this);
}

DialogCountryselect::~DialogCountryselect()
{
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCountryselect::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCountryselect::OnEdit), NULL, this);
}

void DialogCountryselect::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogCountryselect::OnEdit(wxCommandEvent& event)
{

}