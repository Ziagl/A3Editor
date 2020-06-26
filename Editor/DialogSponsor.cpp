#include "DialogSponsor.h"

DialogSponsor::DialogSponsor(wxWindow* parent, 
    Toolset* const tools,
    const std::string selectedCountry,
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

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    m_country = tools->getCountryById(countryId);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlSponsors = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializeSponsorsList(m_listCtrlSponsors);

    flexGridSizer17->Add(m_listCtrlSponsors, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer21 = new wxFlexGridSizer(0, 1, 0, 0);
    flexGridSizer21->SetFlexibleDirection(wxBOTH);
    flexGridSizer21->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlText->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlText, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer25 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer25, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_buttonFont = new wxButton(this, wxID_ANY, _("Font"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer25->Add(m_buttonFont, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFont = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlFont->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFont->SetHint(wxT(""));
#endif

    boxSizer25->Add(m_textCtrlFont, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer31 = new wxFlexGridSizer(2, 8, 0, 0);
    flexGridSizer31->SetFlexibleDirection(wxBOTH);
    flexGridSizer31->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer21->Add(flexGridSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    for (int i = 0; i < 16; ++i)
    {
        wxButton* button = new wxButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBU_EXACTFIT | wxBORDER_NONE);
#if wxVERSION_NUMBER >= 2904
        wxBitmap image;
        std::string filename = "color"; 
        if (i + 1 < 10)
            filename = filename + "0";
        filename = filename + std::to_string(i + 1) + ".bmp";
        image.LoadFile(tools->getImagePath() + filename, wxBITMAP_TYPE_BMP);
        button->SetBitmap(image);
        //m_button33->SetBitmapMargins(2, 2);
#endif
        m_button.push_back(button);
        
        flexGridSizer31->Add(button, 0, wxALL, WXC_FROM_DIP(0));
    }

    m_staticBitmapSponsor = new wxStaticBitmap(this, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("kom1")), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticBitmapSponsor, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText67 = new wxStaticText(this, wxID_ANY, _("Größe des Unternehmens"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer69 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer69, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextSize = new wxStaticText(this, wxID_ANY, _("klein"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer69->Add(m_staticTextSize, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonSize = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonSize->SetRange(0, 2);
    m_spinButtonSize->SetValue(0);

    boxSizer69->Add(m_spinButtonSize, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer75 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer75, 1, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer75->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer75->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnAbort), NULL, this);
}

DialogSponsor::~DialogSponsor()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnAbort), NULL, this);
}

void DialogSponsor::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogSponsor::OnOk(wxCommandEvent& event)
{

}

void DialogSponsor::initializeSponsorsList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 150);

    auto sponsors = m_country->getSponsors();

    long index = 0;
    for (auto sponsor : sponsors)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, sponsor.getName());   // set text column 1
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }

    // sort list
    //control->SortItems(SortCountryList, (wxIntPtr)control);

    control->Show();

    control->SetMinSize(wxSize(180, -1));
}