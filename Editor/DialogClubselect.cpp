#include "DialogClubselect.h"

DialogClubselect::DialogClubselect(wxWindow* parent,
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

    mainSizer->Add(boxSizerLeft, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizerCountryList = new wxBoxSizer(wxVERTICAL);

    boxSizerLeft->Add(boxSizerCountryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerCountryList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseCountry")), wxVERTICAL);

    boxSizerCountryList->Add(staticBoxSizerCountryList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

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

    wxBoxSizer* boxSizerClubList = new wxBoxSizer(wxVERTICAL);

    boxSizerLeft->Add(boxSizerClubList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizerClubList = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseTeam")), wxVERTICAL);

    boxSizerClubList->Add(staticBoxSizerClubList, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrl81 = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);

    m_listCtrl81->InsertColumn(0, wxT("Col1"), wxLIST_FORMAT_LEFT, 50);
    m_listCtrl81->InsertColumn(1, wxT("Col2"), wxLIST_FORMAT_LEFT, 180);
    m_listCtrl81->InsertColumn(2, wxT("Col3"), wxLIST_FORMAT_LEFT, 50);
    ////GUI Items Creation End

    // to speed up inserting we hide the control temporarily
    m_listCtrl81->Hide();

    for (int i = 0; i < 100; ++i)
    {
        wxListItem item;
        item.SetId(i);

        m_listCtrl81->InsertItem(item);
        m_listCtrl81->SetItem(i, 0, wxString::Format("Item %d", i));
        m_listCtrl81->SetItem(i, 1, "Some very long string to display");
        m_listCtrl81->SetItem(i, 2, wxString::Format("Item2 %d", i));
    }

    m_listCtrl81->Show();

    m_listCtrl81->SetMinSize(wxSize(300,300));

    staticBoxSizerClubList->Add(m_listCtrl81, 0, wxALL, WXC_FROM_DIP(5));

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

    // Connect events
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnAbort), NULL, this);
}

DialogClubselect::~DialogClubselect()
{
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogClubselect::OnAbort), NULL, this);
}

void DialogClubselect::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}