#include "DialogUefarankingEdit.h"

UefarankingEdit::UefarankingEdit(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
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

    wxStaticBoxSizer* staticBoxSizer19 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Bitte neue Punktzahl einstellen")), wxVERTICAL);

    flexGridSizer17->Add(staticBoxSizer19, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer27 = new wxFlexGridSizer(7, 6, 0, 0);
    flexGridSizer27->SetFlexibleDirection(wxBOTH);
    flexGridSizer27->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer19->Add(flexGridSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText29 = new wxStaticText(this, wxID_ANY, _("Saison vor 6 Jahren"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText29, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText31 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText31, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText6YearOld = new wxStaticText(this, wxID_ANY, _("11"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText6YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText35 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText35, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText6YearNew = new wxStaticText(this, wxID_ANY, _("11"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText6YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButton37 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton37->SetRange(0, 100);
    m_spinButton37->SetValue(0);

    flexGridSizer27->Add(m_spinButton37, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText43 = new wxStaticText(this, wxID_ANY, _("Saison vor 5 Jahren"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText43, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText45 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText45, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText5YearOld = new wxStaticText(this, wxID_ANY, _("10"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText5YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText49 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText49, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText5YearNew = new wxStaticText(this, wxID_ANY, _("10"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText5YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButton53 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton53->SetRange(0, 100);
    m_spinButton53->SetValue(0);

    flexGridSizer27->Add(m_spinButton53, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText55 = new wxStaticText(this, wxID_ANY, _("Saison vor 4 Jahren"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText55, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText57 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText4YearOld = new wxStaticText(this, wxID_ANY, _("9"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText4YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText61 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText61, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText4YearNew = new wxStaticText(this, wxID_ANY, _("9"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText4YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButton65 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton65->SetRange(0, 100);
    m_spinButton65->SetValue(0);

    flexGridSizer27->Add(m_spinButton65, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText67 = new wxStaticText(this, wxID_ANY, _("Saison vor 3 Jahren"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText69 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText69, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText3YearOld = new wxStaticText(this, wxID_ANY, _("9"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText3YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText73 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText73, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText3YearNew = new wxStaticText(this, wxID_ANY, _("9"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText3YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButton77 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton77->SetRange(0, 100);
    m_spinButton77->SetValue(0);

    flexGridSizer27->Add(m_spinButton77, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText79 = new wxStaticText(this, wxID_ANY, _("Saison vor 2 Jahren"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText79, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText81 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText81, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText2YearOld = new wxStaticText(this, wxID_ANY, _("11"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText2YearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText85 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText85, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText2YearNew = new wxStaticText(this, wxID_ANY, _("11"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText2YearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButton89 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton89->SetRange(0, 100);
    m_spinButton89->SetValue(0);

    flexGridSizer27->Add(m_spinButton89, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText91 = new wxStaticText(this, wxID_ANY, _("Letzte Saison"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText93 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText93, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextLastYearOld = new wxStaticText(this, wxID_ANY, _("7"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextLastYearOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText97 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText97, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextLastYearNew = new wxStaticText(this, wxID_ANY, _("7"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextLastYearNew, 0, wxALL, WXC_FROM_DIP(3));

    m_spinButton101 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_VERTICAL);
    m_spinButton101->SetRange(0, 100);
    m_spinButton101->SetValue(0);

    flexGridSizer27->Add(m_spinButton101, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText103 = new wxStaticText(this, wxID_ANY, _("Gesamt(ohne letzte Saison)"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText103, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText105 = new wxStaticText(this, wxID_ANY, _("Bisher"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText105, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextSumOld = new wxStaticText(this, wxID_ANY, _("50"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextSumOld, 0, wxALL, WXC_FROM_DIP(3));

    m_staticText109 = new wxStaticText(this, wxID_ANY, _(",jetzt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticText109, 0, wxALL, WXC_FROM_DIP(3));

    m_staticTextSumNew = new wxStaticText(this, wxID_ANY, _("50"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer27->Add(m_staticTextSumNew, 0, wxALL, WXC_FROM_DIP(3));

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);

    flexGridSizer17->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, _("Abbrechen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer21->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

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

UefarankingEdit::~UefarankingEdit()
{
}
