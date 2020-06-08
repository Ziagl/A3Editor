#include "DialogAssociation.h"

DialogAssociation::DialogAssociation(wxWindow* parent, 
    Toolset* const tools,
    std::string const selectedCountry,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    // get country and trainer based on given strings
    auto countryId = tools->getCountryIdByShortname(selectedCountry);
    country = tools->getCountryById(countryId);
    nationalTrainer = country->getNationalTrainer();
    president = country->getPresident();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("nationaltrainer")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer39 = new wxFlexGridSizer(5, 2, 0, 0);
    flexGridSizer39->SetFlexibleDirection(wxBOTH);
    flexGridSizer39->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer39->AddGrowableCol(1);

    staticBoxSizer19->Add(flexGridSizer39, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText41 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText41, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl43 = new wxTextCtrl(this, wxID_ANY, nationalTrainer.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl43->SetHint(wxT(""));
#endif

    flexGridSizer39->Add(m_textCtrl43, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText45 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl47 = new wxTextCtrl(this, wxID_ANY, nationalTrainer.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl47->SetHint(wxT(""));
#endif

    flexGridSizer39->Add(m_textCtrl47, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText49 = new wxStaticText(this, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText49, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer51 = new wxFlexGridSizer(0, 6, 0, 0);
    flexGridSizer51->SetFlexibleDirection(wxBOTH);
    flexGridSizer51->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer39->Add(flexGridSizer51, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText53 = new wxStaticText(this, wxID_ANY, _("10"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText53, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton55 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton55->SetRange(0, 100);
    m_spinButton55->SetValue(0);

    flexGridSizer51->Add(m_spinButton55, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText57 = new wxStaticText(this, wxID_ANY, _("10"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton59 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton59->SetRange(0, 100);
    m_spinButton59->SetValue(0);

    flexGridSizer51->Add(m_spinButton59, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText61 = new wxStaticText(this, wxID_ANY, _("1990"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer51->Add(m_staticText61, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton63 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton63->SetRange(0, 100);
    m_spinButton63->SetValue(0);

    flexGridSizer51->Add(m_spinButton63, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText99 = new wxStaticText(this, wxID_ANY, tools->translate("competence"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText99, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer101 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer101->SetFlexibleDirection(wxBOTH);
    flexGridSizer101->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer101->AddGrowableCol(1);

    flexGridSizer39->Add(flexGridSizer101, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText103 = new wxStaticText(this, wxID_ANY, std::to_string(nationalTrainer.getCompetence()), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer101->Add(m_staticText103, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton105 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton105->SetRange(0, tools->getMaxSkillPerson());
    m_spinButton105->SetValue(nationalTrainer.getCompetence());

    flexGridSizer101->Add(m_spinButton105, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText107 = new wxStaticText(this, wxID_ANY, _("Alter 65"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer101->Add(m_staticText107, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText65 = new wxStaticText(this, wxID_ANY, tools->translate("reputation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer39->Add(m_staticText65, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString choiceArray;
    for (int i = 0; i < 7; ++i)
        choiceArray.Add(tools->translate("trainertype" + std::to_string(i)));
    m_choiceReputation = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), choiceArray, 0);
    m_choiceReputation->SetSelection(nationalTrainer.getReputation());

    flexGridSizer39->Add(m_choiceReputation, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer21 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("associationpresident")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer69 = new wxFlexGridSizer(4, 2, 0, 0);
    flexGridSizer69->SetFlexibleDirection(wxBOTH);
    flexGridSizer69->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer69->AddGrowableCol(1);

    staticBoxSizer21->Add(flexGridSizer69, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText71 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText71, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl73 = new wxTextCtrl(this, wxID_ANY, president.getLastname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl73->SetHint(wxT(""));
#endif

    flexGridSizer69->Add(m_textCtrl73, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText75 = new wxStaticText(this, wxID_ANY, tools->translate("firstname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText75, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl77 = new wxTextCtrl(this, wxID_ANY, president.getFirstname(), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl77->SetHint(wxT(""));
#endif

    flexGridSizer69->Add(m_textCtrl77, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText79 = new wxStaticText(this, wxID_ANY, tools->translate("birthday"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer81 = new wxFlexGridSizer(0, 6, 0, 0);
    flexGridSizer81->SetFlexibleDirection(wxBOTH);
    flexGridSizer81->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer69->Add(flexGridSizer81, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText83 = new wxStaticText(this, wxID_ANY, _("10"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer81->Add(m_staticText83, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton85 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton85->SetRange(0, 100);
    m_spinButton85->SetValue(0);

    flexGridSizer81->Add(m_spinButton85, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText87 = new wxStaticText(this, wxID_ANY, _("10"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer81->Add(m_staticText87, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton89 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton89->SetRange(0, 100);
    m_spinButton89->SetValue(0);

    flexGridSizer81->Add(m_spinButton89, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText91 = new wxStaticText(this, wxID_ANY, _("1990"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer81->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton93 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton93->SetRange(0, 100);
    m_spinButton93->SetValue(0);

    flexGridSizer81->Add(m_spinButton93, 0, wxALL, WXC_FROM_DIP(5));

    m_panel97 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    flexGridSizer69->Add(m_panel97, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText95 = new wxStaticText(this, wxID_ANY, tools->translate("age") + " " + std::to_string(99), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer69->Add(m_staticText95, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer23 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer23->SetFlexibleDirection(wxBOTH);
    flexGridSizer23->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("association")), wxVERTICAL);

    flexGridSizer23->Add(staticBoxSizer25, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer33 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer25->Add(boxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText35 = new wxStaticText(this, wxID_ANY, tools->translate("abbreviation"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_staticText35, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl37 = new wxTextCtrl(this, wxID_ANY, /*####TODO#### steht in Kleinig.sav!!!!!*/"", wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl37->SetHint(wxT(""));
#endif

    boxSizer33->Add(m_textCtrl37, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer27 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer23->Add(boxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_ANY, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer27->Add(m_buttonOk, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer27->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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
}

DialogAssociation::~DialogAssociation()
{
}
