#include "DialogNationaljersey.h"

DialogNationaljersey::DialogNationaljersey(wxWindow* parent, 
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

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticBitmap19 = new wxStaticBitmap(this, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("player")), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer17->Add(m_staticBitmap19, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer21 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer21->SetFlexibleDirection(wxBOTH);
    flexGridSizer21->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer23 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_toggleButton29 = new wxToggleButton(this, wxID_ANY, tools->translate("homeJersey"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButton29->SetValue(true);

    boxSizer23->Add(m_toggleButton29, 0, wxALL, WXC_FROM_DIP(5));

    m_toggleButton31 = new wxToggleButton(this, wxID_ANY, tools->translate("awayJersey"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_toggleButton31->SetValue(false);

    boxSizer23->Add(m_toggleButton31, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer33 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("jerseyProperties")), wxVERTICAL);

    flexGridSizer21->Add(staticBoxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxFlexGridSizer* flexGridSizer53 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer53->SetFlexibleDirection(wxBOTH);
    flexGridSizer53->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer33->Add(flexGridSizer53, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer35 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer35->SetFlexibleDirection(wxBOTH);
    flexGridSizer35->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer53->Add(flexGridSizer35, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText37 = new wxStaticText(this, wxID_ANY, tools->translate("jerseyColor") + " 1", wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText37, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice39Arr;
    m_choice39 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choice39Arr, 0);

    flexGridSizer35->Add(m_choice39, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText41 = new wxStaticText(this, wxID_ANY, tools->translate("jerseyColor") + " 2", wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText41, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice43Arr;
    m_choice43 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choice43Arr, 0);

    flexGridSizer35->Add(m_choice43, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText45 = new wxStaticText(this, wxID_ANY, tools->translate("pantsColor"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice47Arr;
    m_choice47 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choice47Arr, 0);

    flexGridSizer35->Add(m_choice47, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText49 = new wxStaticText(this, wxID_ANY, tools->translate("socksColor"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer35->Add(m_staticText49, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice51Arr;
    m_choice51 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choice51Arr, 0);

    flexGridSizer35->Add(m_choice51, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer55 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer55->SetFlexibleDirection(wxBOTH);
    flexGridSizer55->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer53->Add(flexGridSizer55, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_radioButton57 = new wxRadioButton(this, wxID_ANY, tools->translate("neutral"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton57->SetValue(1);

    flexGridSizer55->Add(m_radioButton57, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton59 = new wxRadioButton(this, wxID_ANY, tools->translate("chestRing"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton59->SetValue(1);

    flexGridSizer55->Add(m_radioButton59, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton61 = new wxRadioButton(this, wxID_ANY, tools->translate("lengthwise"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton61->SetValue(1);

    flexGridSizer55->Add(m_radioButton61, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton63 = new wxRadioButton(this, wxID_ANY, tools->translate("sleeve"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton63->SetValue(1);

    flexGridSizer55->Add(m_radioButton63, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton65 = new wxRadioButton(this, wxID_ANY, tools->translate("crosswise"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton65->SetValue(1);

    flexGridSizer55->Add(m_radioButton65, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton67 = new wxRadioButton(this, wxID_ANY, tools->translate("medianStrip"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton67->SetValue(1);

    flexGridSizer55->Add(m_radioButton67, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton69 = new wxRadioButton(this, wxID_ANY, tools->translate("fiftyFifty"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton69->SetValue(1);

    flexGridSizer55->Add(m_radioButton69, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton71 = new wxRadioButton(this, wxID_ANY, tools->translate("checkered"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton71->SetValue(1);

    flexGridSizer55->Add(m_radioButton71, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton73 = new wxRadioButton(this, wxID_ANY, tools->translate("shoulder"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton73->SetValue(1);

    flexGridSizer55->Add(m_radioButton73, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton75 = new wxRadioButton(this, wxID_ANY, tools->translate("diagonally"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioButton75->SetValue(1);

    flexGridSizer55->Add(m_radioButton75, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer79 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer79->SetFlexibleDirection(wxBOTH);
    flexGridSizer79->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer53->Add(flexGridSizer79, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_checkBox81 = new wxCheckBox(this, wxID_ANY, tools->translate("hoopedSocks"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox81->SetValue(false);

    flexGridSizer79->Add(m_checkBox81, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer96 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer21->Add(boxSizer96, 1, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer96->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(1));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer96->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(1));

    SetName(wxT("DialogNationaljersey"));
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
}

DialogNationaljersey::~DialogNationaljersey()
{
}
