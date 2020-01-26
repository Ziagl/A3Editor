#include "DialogCountryselect.h"

DialogCountryselect::DialogCountryselect(wxWindow* parent,
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

    wxStaticBoxSizer* staticBoxSizerCountryList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Bitte Land auswählen")), wxVERTICAL);

    boxSizerCountryList->Add(staticBoxSizerCountryList, 0, wxALL, WXC_FROM_DIP(5));

    m_listCtrl79 = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);

    m_listCtrl79->InsertColumn(0, wxT("Col1"), wxLIST_FORMAT_LEFT, 50);
    m_listCtrl79->InsertColumn(1, wxT("Col2"), wxLIST_FORMAT_LEFT, 50);
    ////GUI Items Creation End

    // to speed up inserting we hide the control temporarily
    m_listCtrl79->Hide();

    for (int i = 0; i < 100; ++i)
    {
        wxListItem item;
        item.SetId(i);

        m_listCtrl79->InsertItem(item);
        m_listCtrl79->SetItem(i, 0, wxString::Format("Item %d", i));
        m_listCtrl79->SetItem(i, 1, wxString::Format("Item1 %d", i));
    }

    m_listCtrl79->Show();

    m_listCtrl79->SetMinSize(wxSize(150, 300));

    // test SetItemFont too
    //m_listCtrl79->SetItemFont(0, *wxITALIC_FONT);

    staticBoxSizerCountryList->Add(m_listCtrl79, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerRight = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizerRight, 0, wxALL, WXC_FROM_DIP(5));

    //int buttonWidth = 150;

    m_buttonEdit = new wxButton(this, wxID_ANY, _("Editieren"), wxDefaultPosition, wxDefaultSize/*wxDLG_UNIT(this, wxSize(buttonWidth, -1))*/, 0);

    boxSizerRight->Add(m_buttonEdit, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ABORT, _("Abbrechen"), wxDefaultPosition, wxDefaultSize/*wxDLG_UNIT(this, wxSize(buttonWidth, -1))*/, 0);

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
}

DialogCountryselect::~DialogCountryselect()
{
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogCountryselect::OnAbort), NULL, this);
}

void DialogCountryselect::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}