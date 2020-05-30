#include "DialogStadion.h"

DialogStadion::DialogStadion(wxWindow* parent, 
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

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(0));

    wxBoxSizer* boxSizer17 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer12->Add(boxSizer17, 2, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxStaticBoxSizer* Allgemeines = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("general")), wxVERTICAL);

    boxSizer17->Add(Allgemeines, 3, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer45 = new wxBoxSizer(wxHORIZONTAL);

    Allgemeines->Add(boxSizer45, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxBoxSizer* boxSizer47 = new wxBoxSizer(wxVERTICAL);

    boxSizer45->Add(boxSizer47, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_staticText51 = new wxStaticText(this, wxID_ANY, tools->translate("name"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer47->Add(m_staticText51, 0, wxALL, WXC_FROM_DIP(0));

    m_textCtrl49 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl49->SetHint(wxT(""));
#endif

    boxSizer47->Add(m_textCtrl49, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText53 = new wxStaticText(this, wxID_ANY, tools->translate("place"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer47->Add(m_staticText53, 0, wxALL, WXC_FROM_DIP(0));

    m_textCtrl55 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl55->SetHint(wxT(""));
#endif

    boxSizer47->Add(m_textCtrl55, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText57 = new wxStaticText(this, wxID_ANY, tools->translate("scoreboard"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer47->Add(m_staticText57, 0, wxALL, WXC_FROM_DIP(0));

    wxArrayString m_choice59Arr;
    m_choice59 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choice59Arr, 0);

    boxSizer47->Add(m_choice59, 0, wxALL, WXC_FROM_DIP(0));

    wxGridSizer* gridSizer61 = new wxGridSizer(6, 2, 0, 0);

    boxSizer45->Add(gridSizer61, 2, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_checkBox63 = new wxCheckBox(this, wxID_ANY, tools->translate("turfheating"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox63->SetValue(false);

    gridSizer61->Add(m_checkBox63, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBox65 = new wxCheckBox(this, wxID_ANY, tools->translate("seatcushions"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox65->SetValue(false);

    gridSizer61->Add(m_checkBox65, 0, wxALL, WXC_FROM_DIP(0));

    m_checkBox67 = new wxCheckBox(this, wxID_ANY, tools->translate("floodlight"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox67->SetValue(false);

    gridSizer61->Add(m_checkBox67, 0, wxALL, WXC_FROM_DIP(0));

    gridSizer61->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBox69 = new wxCheckBox(this, wxID_ANY, tools->translate("heatedseats"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox69->SetValue(false);

    gridSizer61->Add(m_checkBox69, 0, wxALL, WXC_FROM_DIP(0));

    gridSizer61->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBox71 = new wxCheckBox(this, wxID_ANY, tools->translate("luxurycabins"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox71->SetValue(false);

    gridSizer61->Add(m_checkBox71, 0, wxALL, WXC_FROM_DIP(0));

    gridSizer61->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBox73 = new wxCheckBox(this, wxID_ANY, tools->translate("track"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox73->SetValue(false);

    gridSizer61->Add(m_checkBox73, 0, wxALL, WXC_FROM_DIP(0));

    gridSizer61->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBox75 = new wxCheckBox(this, wxID_ANY, tools->translate("extendableplayingfield"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox75->SetValue(false);

    gridSizer61->Add(m_checkBox75, 0, wxALL, WXC_FROM_DIP(0));

    wxStaticBoxSizer* boxSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("generaloverview")), wxVERTICAL);

    boxSizer17->Add(boxSizer, 2, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxGridSizer* gridSizer85 = new wxGridSizer(6, 2, 0, 0);

    boxSizer->Add(gridSizer85, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText87 = new wxStaticText(this, wxID_ANY, tools->translate("standingroomuncovered"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText87, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText89 = new wxStaticText(this, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText89, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    m_staticText91 = new wxStaticText(this, wxID_ANY, _("Stehplätze überdacht"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText91, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText93 = new wxStaticText(this, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText93, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    m_staticText95 = new wxStaticText(this, wxID_ANY, _("Sitzplätze unüberdacht"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText95, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText97 = new wxStaticText(this, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText97, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    m_staticText99 = new wxStaticText(this, wxID_ANY, _("Sitzplätze überdacht"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText99, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText101 = new wxStaticText(this, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText101, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    m_staticText103 = new wxStaticText(this, wxID_ANY, _("VIP-Plätze"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText103, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText105 = new wxStaticText(this, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText105, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    m_staticText107 = new wxStaticText(this, wxID_ANY, _("Kapazität gesamt"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText107, 0, wxALL, WXC_FROM_DIP(0));

    m_staticText109 = new wxStaticText(this, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer85->Add(m_staticText109, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(0));

    wxBoxSizer* boxSizer29 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer12->Add(boxSizer29, 3, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxStaticBoxSizer* boxSizer1 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Tribünenbeschreibung")), wxVERTICAL);

    boxSizer29->Add(boxSizer1, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxGridSizer* gridSizer111 = new wxGridSizer(5, 8, 0, 0);

    boxSizer1->Add(gridSizer111, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    gridSizer111->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_staticText115 = new wxStaticText(this, wxID_ANY, _("VIP-Plätze"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText115, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText117 = new wxStaticText(this, wxID_ANY, _("Sitzplätze"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText117, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText119 = new wxStaticText(this, wxID_ANY, _("Stehplätze"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText119, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText121 = new wxStaticText(this, wxID_ANY, _("Wärmestrahler"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText121, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText123 = new wxStaticText(this, wxID_ANY, _("Dach"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText123, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText125 = new wxStaticText(this, wxID_ANY, _("Zustand"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText125, 0, wxALL, WXC_FROM_DIP(5));

    gridSizer111->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_staticText129 = new wxStaticText(this, wxID_ANY, _("Haupttribüne"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText129, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl137 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl137->SetRange(0, 100);
    m_spinCtrl137->SetValue(0);

    gridSizer111->Add(m_spinCtrl137, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl139 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl139->SetRange(0, 100);
    m_spinCtrl139->SetValue(0);

    gridSizer111->Add(m_spinCtrl139, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl141 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl141->SetRange(0, 100);
    m_spinCtrl141->SetValue(0);

    gridSizer111->Add(m_spinCtrl141, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox143 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox143->SetValue(false);

    gridSizer111->Add(m_checkBox143, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox145 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox145->SetValue(false);

    gridSizer111->Add(m_checkBox145, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText147 = new wxStaticText(this, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText147, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton149 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(20, 25)), wxSP_VERTICAL);
    m_spinButton149->SetRange(0, 100);
    m_spinButton149->SetValue(0);

    gridSizer111->Add(m_spinButton149, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText151 = new wxStaticText(this, wxID_ANY, _("Gegentribüne"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText151, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl153 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl153->SetRange(0, 100);
    m_spinCtrl153->SetValue(0);

    gridSizer111->Add(m_spinCtrl153, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl155 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl155->SetRange(0, 100);
    m_spinCtrl155->SetValue(0);

    gridSizer111->Add(m_spinCtrl155, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl157 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl157->SetRange(0, 100);
    m_spinCtrl157->SetValue(0);

    gridSizer111->Add(m_spinCtrl157, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox159 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox159->SetValue(false);

    gridSizer111->Add(m_checkBox159, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox161 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox161->SetValue(false);

    gridSizer111->Add(m_checkBox161, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText163 = new wxStaticText(this, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText163, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton165 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(20, 25)), wxSP_VERTICAL);
    m_spinButton165->SetRange(0, 100);
    m_spinButton165->SetValue(0);

    gridSizer111->Add(m_spinButton165, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText167 = new wxStaticText(this, wxID_ANY, _("Trib. links der Haupttr."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText167, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl169 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl169->SetRange(0, 100);
    m_spinCtrl169->SetValue(0);

    gridSizer111->Add(m_spinCtrl169, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl171 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl171->SetRange(0, 100);
    m_spinCtrl171->SetValue(0);

    gridSizer111->Add(m_spinCtrl171, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl173 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl173->SetRange(0, 100);
    m_spinCtrl173->SetValue(0);

    gridSizer111->Add(m_spinCtrl173, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox175 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox175->SetValue(false);

    gridSizer111->Add(m_checkBox175, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox177 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox177->SetValue(false);

    gridSizer111->Add(m_checkBox177, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText179 = new wxStaticText(this, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText179, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton181 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(20, 25)), wxSP_VERTICAL);
    m_spinButton181->SetRange(0, 100);
    m_spinButton181->SetValue(0);

    gridSizer111->Add(m_spinButton181, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText183 = new wxStaticText(this, wxID_ANY, _("Trib. rechts der Haupttr."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText183, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl185 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl185->SetRange(0, 100);
    m_spinCtrl185->SetValue(0);

    gridSizer111->Add(m_spinCtrl185, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl187 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl187->SetRange(0, 100);
    m_spinCtrl187->SetValue(0);

    gridSizer111->Add(m_spinCtrl187, 0, wxALL, WXC_FROM_DIP(5));

    m_spinCtrl189 = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(60, 20)), wxSP_ARROW_KEYS);
    m_spinCtrl189->SetRange(0, 100);
    m_spinCtrl189->SetValue(0);

    gridSizer111->Add(m_spinCtrl189, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox191 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox191->SetValue(false);

    gridSizer111->Add(m_checkBox191, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox193 = new wxCheckBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox193->SetValue(false);

    gridSizer111->Add(m_checkBox193, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText195 = new wxStaticText(this, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer111->Add(m_staticText195, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton201 = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(20, 25)), wxSP_VERTICAL);
    m_spinButton201->SetRange(0, 100);
    m_spinButton201->SetValue(0);

    gridSizer111->Add(m_spinButton201, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer31 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer12->Add(boxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxBoxSizer* boxSizer35 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer31->Add(boxSizer35, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* FanundGaestetribuene = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Fan- und Gästetribüne")), wxVERTICAL);

    boxSizer35->Add(FanundGaestetribuene, 2, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxGridSizer* gridSizer203 = new wxGridSizer(2, 2, 0, 0);

    FanundGaestetribuene->Add(gridSizer203, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText205 = new wxStaticText(this, wxID_ANY, _("Heimtribüne"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer203->Add(m_staticText205, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_comboBox207Arr;
    m_comboBox207 = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_comboBox207Arr, 0);
#if wxVERSION_NUMBER >= 3000
    m_comboBox207->SetHint(wxT(""));
#endif

    gridSizer203->Add(m_comboBox207, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText209 = new wxStaticText(this, wxID_ANY, _("Gasttribüne"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    gridSizer203->Add(m_staticText209, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_comboBox211Arr;
    m_comboBox211 = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_comboBox211Arr, 0);
#if wxVERSION_NUMBER >= 3000
    m_comboBox211->SetHint(wxT(""));
#endif

    gridSizer203->Add(m_comboBox211, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* Sonstiges = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Sonstiges")), wxVERTICAL);

    boxSizer35->Add(Sonstiges, 3, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxGridSizer* gridSizer213 = new wxGridSizer(3, 3, 0, 0);

    Sonstiges->Add(gridSizer213, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkBox215 = new wxCheckBox(this, wxID_ANY, _("Citylage"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox215->SetValue(false);

    gridSizer213->Add(m_checkBox215, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox217 = new wxCheckBox(this, wxID_ANY, _("Burg"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox217->SetValue(false);

    gridSizer213->Add(m_checkBox217, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox219 = new wxCheckBox(this, wxID_ANY, _("Fernsehturm"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox219->SetValue(false);

    gridSizer213->Add(m_checkBox219, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox221 = new wxCheckBox(this, wxID_ANY, _("Im Besitz des Vereins"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox221->SetValue(false);

    gridSizer213->Add(m_checkBox221, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox223 = new wxCheckBox(this, wxID_ANY, _("Schloß"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox223->SetValue(false);

    gridSizer213->Add(m_checkBox223, 0, wxALL, WXC_FROM_DIP(5));

    gridSizer213->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBox227 = new wxCheckBox(this, wxID_ANY, _("Autobahnanbindung"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox227->SetValue(false);

    gridSizer213->Add(m_checkBox227, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox229 = new wxCheckBox(this, wxID_ANY, _("Berge"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBox229->SetValue(false);

    gridSizer213->Add(m_checkBox229, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer43 = new wxBoxSizer(wxVERTICAL);

    boxSizer35->Add(boxSizer43, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();

    boxSizer43->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonCancel = new wxButton(this, wxID_CANCEL, _("Abbrechen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer43->Add(m_buttonCancel, 0, wxALL, WXC_FROM_DIP(5));

/*  SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(630, 450)));
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

}

DialogStadion::~DialogStadion()
{
}
