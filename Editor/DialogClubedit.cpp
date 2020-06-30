#include "DialogClubedit.h"

DialogClubedit::DialogClubedit(wxWindow* parent, Toolset* const tools, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainSizer);

    wxBoxSizer* boxSizer23 = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_notebook25 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBK_DEFAULT);
    m_notebook25->SetName(wxT("m_notebook25"));

    boxSizer23->Add(m_notebook25, 0, wxALL, WXC_FROM_DIP(5));

    m_panelClub = new wxPanel(m_notebook25, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook25, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook25->AddPage(m_panelClub, _("Verein"), false);

    wxBoxSizer* boxSizer39 = new wxBoxSizer(wxVERTICAL);
    m_panelClub->SetSizer(boxSizer39);

    wxStaticBoxSizer* staticBoxSizer41 = new wxStaticBoxSizer(new wxStaticBox(m_panelClub, wxID_ANY, _("Einstellungen")), wxVERTICAL);

    boxSizer39->Add(staticBoxSizer41, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer45 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer41->Add(boxSizer45, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticClubName = new wxStaticText(m_panelClub, wxID_ANY, _("Vereinsname"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    boxSizer45->Add(m_staticClubName, 0, wxALL, WXC_FROM_DIP(5));

    m_textClubName = new wxTextCtrl(m_panelClub, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textClubName->SetHint(wxT(""));
#endif

    boxSizer45->Add(m_textClubName, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonClubname1 = new wxButton(m_panelClub, wxID_ANY, _("...kann der KV Brügge..."), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    staticBoxSizer41->Add(m_buttonClubname1, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonClubname2 = new wxButton(m_panelClub, wxID_ANY, _("...vom KV Brügge kam..."), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    staticBoxSizer41->Add(m_buttonClubname2, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer55 = new wxBoxSizer(wxHORIZONTAL);

    staticBoxSizer41->Add(boxSizer55, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticFanCaption = new wxStaticText(m_panelClub, wxID_ANY, _("Fanbezeichnung"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    boxSizer55->Add(m_staticFanCaption, 0, wxALL, WXC_FROM_DIP(5));

    m_textFanCaption = new wxTextCtrl(m_panelClub, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFanCaption->SetHint(wxT(""));
#endif

    boxSizer55->Add(m_textFanCaption, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer43 = new wxStaticBoxSizer(new wxStaticBox(m_panelClub, wxID_ANY, _("Ewige Tabelle 1. Liga")), wxVERTICAL);

    boxSizer39->Add(staticBoxSizer43, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxGridSizer* gridSizer61 = new wxGridSizer(4, 3, 0, 0);

    staticBoxSizer43->Add(gridSizer61, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText63 = new wxStaticText(m_panelClub, wxID_ANY, _("Punkte"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText63, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText65 = new wxStaticText(m_panelClub, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText65, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton67 = new wxSpinButton(m_panelClub, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton67->SetRange(0, 100);
    m_spinButton67->SetValue(0);

    gridSizer61->Add(m_spinButton67, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText69 = new wxStaticText(m_panelClub, wxID_ANY, _("Spiele"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText69, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText71 = new wxStaticText(m_panelClub, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText71, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton73 = new wxSpinButton(m_panelClub, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton73->SetRange(0, 100);
    m_spinButton73->SetValue(0);

    gridSizer61->Add(m_spinButton73, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText75 = new wxStaticText(m_panelClub, wxID_ANY, _("Erzielte Tore"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText75, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText77 = new wxStaticText(m_panelClub, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText77, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton79 = new wxSpinButton(m_panelClub, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton79->SetRange(0, 100);
    m_spinButton79->SetValue(0);

    gridSizer61->Add(m_spinButton79, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText81 = new wxStaticText(m_panelClub, wxID_ANY, _("Kassierte Tore"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText81, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText83 = new wxStaticText(m_panelClub, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(-1, -1)), 0);

    gridSizer61->Add(m_staticText83, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton85 = new wxSpinButton(m_panelClub, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelClub, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton85->SetRange(0, 100);
    m_spinButton85->SetValue(0);

    gridSizer61->Add(m_spinButton85, 0, wxALL, WXC_FROM_DIP(5));

    m_panelGeneral = new wxPanel(m_notebook25, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook25, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook25->AddPage(m_panelGeneral, _("Allgemein"), false);

    wxBoxSizer* boxSizer87 = new wxBoxSizer(wxHORIZONTAL);
    m_panelGeneral->SetSizer(boxSizer87);

    m_panel89 = new wxPanel(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer87->Add(m_panel89, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer133 = new wxBoxSizer(wxVERTICAL);
    m_panel89->SetSizer(boxSizer133);

    wxBoxSizer* boxSizer169 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer133->Add(boxSizer169, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer135 = new wxBoxSizer(wxVERTICAL);

    boxSizer169->Add(boxSizer135, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer145 = new wxBoxSizer(wxVERTICAL);

    boxSizer135->Add(boxSizer145, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer147 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer145->Add(boxSizer147, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText149 = new wxStaticText(m_panel89, wxID_ANY, _("Kürzel"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    boxSizer147->Add(m_staticText149, 0, wxALL, WXC_FROM_DIP(5));

    m_button151 = new wxButton(m_panel89, wxID_ANY, _("der"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    boxSizer147->Add(m_button151, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl153 = new wxTextCtrl(m_panel89, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl153->SetHint(wxT(""));
#endif

    boxSizer147->Add(m_textCtrl153, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer155 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer145->Add(boxSizer155, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText157 = new wxStaticText(m_panel89, wxID_ANY, _("Gründungsjahr"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    boxSizer155->Add(m_staticText157, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText159 = new wxStaticText(m_panel89, wxID_ANY, _("1984"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    boxSizer155->Add(m_staticText159, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton161 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton161->SetRange(0, 100);
    m_spinButton161->SetValue(0);

    boxSizer155->Add(m_spinButton161, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer137 = new wxBoxSizer(wxVERTICAL);

    boxSizer169->Add(boxSizer137, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkBox139 = new wxCheckBox(m_panel89, wxID_ANY, _("Pokalmannschaft"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);
    m_checkBox139->SetValue(false);

    boxSizer137->Add(m_checkBox139, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox141 = new wxCheckBox(m_panel89, wxID_ANY, _("Medienstadt"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);
    m_checkBox141->SetValue(false);

    boxSizer137->Add(m_checkBox141, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox143 = new wxCheckBox(m_panel89, wxID_ANY, _("Aktiengesellschaft"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);
    m_checkBox143->SetValue(false);

    boxSizer137->Add(m_checkBox143, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer171 = new wxFlexGridSizer(4, 2, 0, 0);
    flexGridSizer171->SetFlexibleDirection(wxBOTH);
    flexGridSizer171->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    boxSizer133->Add(flexGridSizer171, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText173 = new wxStaticText(m_panel89, wxID_ANY, _("Amateurabteilung von"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer171->Add(m_staticText173, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice175Arr;
    m_choice175 = new wxChoice(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), m_choice175Arr, 0);

    flexGridSizer171->Add(m_choice175, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText177 = new wxStaticText(m_panel89, wxID_ANY, _("Anfeuerung"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer171->Add(m_staticText177, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice179Arr;
    m_choice179 = new wxChoice(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), m_choice179Arr, 0);

    flexGridSizer171->Add(m_choice179, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText181 = new wxStaticText(m_panel89, wxID_ANY, _("Fanfreundschaft mit"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer171->Add(m_staticText181, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice183Arr;
    m_choice183 = new wxChoice(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), m_choice183Arr, 0);

    flexGridSizer171->Add(m_choice183, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText185 = new wxStaticText(m_panel89, wxID_ANY, _("Erzrivale"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer171->Add(m_staticText185, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice187Arr;
    m_choice187 = new wxChoice(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), m_choice187Arr, 0);

    flexGridSizer171->Add(m_choice187, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer191 = new wxFlexGridSizer(7, 3, 0, 0);
    flexGridSizer191->SetFlexibleDirection(wxBOTH);
    flexGridSizer191->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    boxSizer133->Add(flexGridSizer191, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText193 = new wxStaticText(m_panel89, wxID_ANY, _("Stärkedurchschnitt aller Spieler:"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText193, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText195 = new wxStaticText(m_panel89, wxID_ANY, _("8.71"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText195, 0, wxALL, WXC_FROM_DIP(5));

    flexGridSizer191->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_staticText199 = new wxStaticText(m_panel89, wxID_ANY, _("Fanaufkommen"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText199, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText201 = new wxStaticText(m_panel89, wxID_ANY, _("durchschnittlich"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText201, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton203 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), wxSP_HORIZONTAL);
    m_spinButton203->SetRange(0, 100);
    m_spinButton203->SetValue(0);

    flexGridSizer191->Add(m_spinButton203, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText205 = new wxStaticText(m_panel89, wxID_ANY, _("Max. Fanaufk. (Einzugsgebiet)"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText205, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText207 = new wxStaticText(m_panel89, wxID_ANY, _("hoch"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText207, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton209 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), wxSP_HORIZONTAL);
    m_spinButton209->SetRange(0, 100);
    m_spinButton209->SetValue(0);

    flexGridSizer191->Add(m_spinButton209, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText211 = new wxStaticText(m_panel89, wxID_ANY, _("Art der Fans"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText211, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText213 = new wxStaticText(m_panel89, wxID_ANY, _("lautstark"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText213, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton215 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), wxSP_HORIZONTAL);
    m_spinButton215->SetRange(0, 100);
    m_spinButton215->SetValue(0);

    flexGridSizer191->Add(m_spinButton215, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText217 = new wxStaticText(m_panel89, wxID_ANY, _("Hooligans"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText217, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText219 = new wxStaticText(m_panel89, wxID_ANY, _("viele und schlimme"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText219, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton221 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), wxSP_HORIZONTAL);
    m_spinButton221->SetRange(0, 100);
    m_spinButton221->SetValue(0);

    flexGridSizer191->Add(m_spinButton221, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText223 = new wxStaticText(m_panel89, wxID_ANY, _("Guthaben bei Spielbeginn"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText223, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText225 = new wxStaticText(m_panel89, wxID_ANY, _("0.40 Million(en)"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText225, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton227 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), wxSP_HORIZONTAL);
    m_spinButton227->SetRange(0, 100);
    m_spinButton227->SetValue(0);

    flexGridSizer191->Add(m_spinButton227, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText229 = new wxStaticText(m_panel89, wxID_ANY, _("Finanzkraft"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText229, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText231 = new wxStaticText(m_panel89, wxID_ANY, _("solide"), wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), 0);

    flexGridSizer191->Add(m_staticText231, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton233 = new wxSpinButton(m_panel89, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel89, wxSize(-1, -1)), wxSP_HORIZONTAL);
    m_spinButton233->SetRange(0, 100);
    m_spinButton233->SetValue(0);

    flexGridSizer191->Add(m_spinButton233, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer91 = new wxStaticBoxSizer(new wxStaticBox(m_panelGeneral, wxID_ANY, _("Titel")), wxVERTICAL);

    boxSizer87->Add(staticBoxSizer91, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer131 = new wxFlexGridSizer(6, 3, 0, 0);
    flexGridSizer131->SetFlexibleDirection(wxBOTH);
    flexGridSizer131->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer91->Add(flexGridSizer131, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText95 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Meisterschaft"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText95, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText97 = new wxStaticText(m_panelGeneral, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText97, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton99 = new wxSpinButton(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton99->SetRange(0, 100);
    m_spinButton99->SetValue(0);

    flexGridSizer131->Add(m_spinButton99, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText101 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Pokal"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText101, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText103 = new wxStaticText(m_panelGeneral, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText103, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton105 = new wxSpinButton(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton105->SetRange(0, 100);
    m_spinButton105->SetValue(0);

    flexGridSizer131->Add(m_spinButton105, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText107 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Ligapokal/Supercup"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText107, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText109 = new wxStaticText(m_panelGeneral, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText109, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton111 = new wxSpinButton(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton111->SetRange(0, 100);
    m_spinButton111->SetValue(0);

    flexGridSizer131->Add(m_spinButton111, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText113 = new wxStaticText(m_panelGeneral, wxID_ANY, _("europ. Verbandspokal"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText113, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText115 = new wxStaticText(m_panelGeneral, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText115, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton117 = new wxSpinButton(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton117->SetRange(0, 100);
    m_spinButton117->SetValue(0);

    flexGridSizer131->Add(m_spinButton117, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText119 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Pokal der Meister"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText119, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText121 = new wxStaticText(m_panelGeneral, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText121, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton123 = new wxSpinButton(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton123->SetRange(0, 100);
    m_spinButton123->SetValue(0);

    flexGridSizer131->Add(m_spinButton123, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText125 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Weltpokal"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText125, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText127 = new wxStaticText(m_panelGeneral, wxID_ANY, _("0"), wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer131->Add(m_staticText127, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton129 = new wxSpinButton(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton129->SetRange(0, 100);
    m_spinButton129->SetValue(0);

    flexGridSizer131->Add(m_spinButton129, 0, wxALL, WXC_FROM_DIP(5));

    m_panelJersey = new wxPanel(m_notebook25, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook25, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook25->AddPage(m_panelJersey, _("Trikotsätze"), false);

    wxBoxSizer* boxSizer239 = new wxBoxSizer(wxHORIZONTAL);
    m_panelJersey->SetSizer(boxSizer239);

    m_staticBitmap303 = new wxStaticBitmap(m_panelJersey, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);

    boxSizer239->Add(m_staticBitmap303, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer243 = new wxBoxSizer(wxVERTICAL);

    boxSizer239->Add(boxSizer243, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer245 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer243->Add(boxSizer245, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_toggleButton299 = new wxToggleButton(m_panelJersey, wxID_ANY, _("Heimtrikot"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_toggleButton299->SetValue(true);

    boxSizer245->Add(m_toggleButton299, 0, wxALL, WXC_FROM_DIP(5));

    m_toggleButton301 = new wxToggleButton(m_panelJersey, wxID_ANY, _("Auswärtstrikot"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_toggleButton301->SetValue(true);

    boxSizer245->Add(m_toggleButton301, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer247 = new wxStaticBoxSizer(new wxStaticBox(m_panelJersey, wxID_ANY, _("Trikot Eigenschaften")), wxVERTICAL);

    boxSizer243->Add(staticBoxSizer247, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer253 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer253->SetFlexibleDirection(wxBOTH);
    flexGridSizer253->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer247->Add(flexGridSizer253, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText279 = new wxStaticText(m_panelJersey, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);

    flexGridSizer253->Add(m_staticText279, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice287Arr;
    m_choice287 = new wxChoice(m_panelJersey, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), m_choice287Arr, 0);

    flexGridSizer253->Add(m_choice287, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText283 = new wxStaticText(m_panelJersey, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);

    flexGridSizer253->Add(m_staticText283, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice285Arr;
    m_choice285 = new wxChoice(m_panelJersey, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), m_choice285Arr, 0);

    flexGridSizer253->Add(m_choice285, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText289 = new wxStaticText(m_panelJersey, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);

    flexGridSizer253->Add(m_staticText289, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice291Arr;
    m_choice291 = new wxChoice(m_panelJersey, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), m_choice291Arr, 0);

    flexGridSizer253->Add(m_choice291, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText293 = new wxStaticText(m_panelJersey, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);

    flexGridSizer253->Add(m_staticText293, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choice295Arr;
    m_choice295 = new wxChoice(m_panelJersey, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), m_choice295Arr, 0);

    flexGridSizer253->Add(m_choice295, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer255 = new wxFlexGridSizer(5, 2, 0, 0);
    flexGridSizer255->SetFlexibleDirection(wxBOTH);
    flexGridSizer255->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer247->Add(flexGridSizer255, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioButton259 = new wxRadioButton(m_panelJersey, wxID_ANY, _("neutral"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton259->SetValue(1);

    flexGridSizer255->Add(m_radioButton259, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton261 = new wxRadioButton(m_panelJersey, wxID_ANY, _("Brustring"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton261->SetValue(1);

    flexGridSizer255->Add(m_radioButton261, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton263 = new wxRadioButton(m_panelJersey, wxID_ANY, _("längs"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton263->SetValue(1);

    flexGridSizer255->Add(m_radioButton263, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton265 = new wxRadioButton(m_panelJersey, wxID_ANY, _("Ärmel"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton265->SetValue(1);

    flexGridSizer255->Add(m_radioButton265, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton267 = new wxRadioButton(m_panelJersey, wxID_ANY, _("quer"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton267->SetValue(1);

    flexGridSizer255->Add(m_radioButton267, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton269 = new wxRadioButton(m_panelJersey, wxID_ANY, _("Mittelstr."), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton269->SetValue(1);

    flexGridSizer255->Add(m_radioButton269, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton271 = new wxRadioButton(m_panelJersey, wxID_ANY, _("Halb/Halb"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton271->SetValue(1);

    flexGridSizer255->Add(m_radioButton271, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton273 = new wxRadioButton(m_panelJersey, wxID_ANY, _("kariert"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton273->SetValue(1);

    flexGridSizer255->Add(m_radioButton273, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton275 = new wxRadioButton(m_panelJersey, wxID_ANY, _("Schulter"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton275->SetValue(1);

    flexGridSizer255->Add(m_radioButton275, 0, wxALL, WXC_FROM_DIP(5));

    m_radioButton277 = new wxRadioButton(m_panelJersey, wxID_ANY, _("schräg"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_radioButton277->SetValue(1);

    flexGridSizer255->Add(m_radioButton277, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBox257 = new wxCheckBox(m_panelJersey, wxID_ANY, _("Ringelsocken"), wxDefaultPosition, wxDLG_UNIT(m_panelJersey, wxSize(-1, -1)), 0);
    m_checkBox257->SetValue(false);

    staticBoxSizer247->Add(m_checkBox257, 0, wxALL, WXC_FROM_DIP(5));

    m_panelIcon = new wxPanel(m_notebook25, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook25, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook25->AddPage(m_panelIcon, _("Wappen"), false);

    m_panelMap = new wxPanel(m_notebook25, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook25, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook25->AddPage(m_panelMap, _("Landkarte"), false);

    m_panelChairman = new wxPanel(m_notebook25, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook25, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook25->AddPage(m_panelChairman, _("Vorsitzender"), false);

    wxBoxSizer* boxSizer307 = new wxBoxSizer(wxVERTICAL);
    m_panelChairman->SetSizer(boxSizer307);

    wxBoxSizer* boxSizer309 = new wxBoxSizer(wxVERTICAL);

    boxSizer307->Add(boxSizer309, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer313 = new wxFlexGridSizer(2, 2, 0, 0);
    flexGridSizer313->SetFlexibleDirection(wxBOTH);
    flexGridSizer313->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    boxSizer309->Add(flexGridSizer313, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText315 = new wxStaticText(m_panelChairman, wxID_ANY, _("Name"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    flexGridSizer313->Add(m_staticText315, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl317 = new wxTextCtrl(m_panelChairman, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl317->SetHint(wxT(""));
#endif

    flexGridSizer313->Add(m_textCtrl317, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText319 = new wxStaticText(m_panelChairman, wxID_ANY, _("Vorname"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    flexGridSizer313->Add(m_staticText319, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrl321 = new wxTextCtrl(m_panelChairman, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrl321->SetHint(wxT(""));
#endif

    flexGridSizer313->Add(m_textCtrl321, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer311 = new wxFlexGridSizer(3, 2, 0, 0);
    flexGridSizer311->SetFlexibleDirection(wxBOTH);
    flexGridSizer311->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    boxSizer307->Add(flexGridSizer311, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText323 = new wxStaticText(m_panelChairman, wxID_ANY, _("Geburtsdatum"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    flexGridSizer311->Add(m_staticText323, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer325 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer311->Add(boxSizer325, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText327 = new wxStaticText(m_panelChairman, wxID_ANY, _("24"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    boxSizer325->Add(m_staticText327, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton329 = new wxSpinButton(m_panelChairman, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton329->SetRange(0, 100);
    m_spinButton329->SetValue(0);

    boxSizer325->Add(m_spinButton329, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText331 = new wxStaticText(m_panelChairman, wxID_ANY, _("6"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    boxSizer325->Add(m_staticText331, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton333 = new wxSpinButton(m_panelChairman, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton333->SetRange(0, 100);
    m_spinButton333->SetValue(0);

    boxSizer325->Add(m_spinButton333, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText335 = new wxStaticText(m_panelChairman, wxID_ANY, _("1939"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    boxSizer325->Add(m_staticText335, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton337 = new wxSpinButton(m_panelChairman, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButton337->SetRange(0, 100);
    m_spinButton337->SetValue(0);

    boxSizer325->Add(m_spinButton337, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText339 = new wxStaticText(m_panelChairman, wxID_ANY, _("Vorstand"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    flexGridSizer311->Add(m_staticText339, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer341 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer311->Add(boxSizer341, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText343 = new wxStaticText(m_panelChairman, wxID_ANY, _("souverän"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    boxSizer341->Add(m_staticText343, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton345 = new wxSpinButton(m_panelChairman, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(15, 15)), wxSP_HORIZONTAL);
    m_spinButton345->SetRange(0, 100);
    m_spinButton345->SetValue(0);

    boxSizer341->Add(m_spinButton345, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText347 = new wxStaticText(m_panelChairman, wxID_ANY, _("Opposition"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    flexGridSizer311->Add(m_staticText347, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer349 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer311->Add(boxSizer349, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText351 = new wxStaticText(m_panelChairman, wxID_ANY, _("durchaus vorhanden"), wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(-1, -1)), 0);

    boxSizer349->Add(m_staticText351, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButton353 = new wxSpinButton(m_panelChairman, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelChairman, wxSize(15, 15)), wxSP_HORIZONTAL);
    m_spinButton353->SetRange(0, 100);
    m_spinButton353->SetValue(0);

    boxSizer349->Add(m_spinButton353, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();

    boxSizer12->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonCancel = new wxButton(this, wxID_CANCEL, _("Abbrechen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonCancel, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonClubSave = new wxButton(this, wxID_ANY, _("Verein speichern"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonClubSave, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonClubLoad = new wxButton(this, wxID_ANY, _("Verein einlesen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonClubLoad, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonStadion = new wxButton(this, wxID_ANY, _("Stadion"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonStadion, 0, wxALL, WXC_FROM_DIP(5));


/*#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(m_notebook25)) {
        wxPersistenceManager::Get().RegisterAndRestore(m_notebook25);
    }
    else {
        wxPersistenceManager::Get().Restore(m_notebook25);
    }
#endif*/

    SetName(wxT("DialogClubedit"));
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

DialogClubedit::~DialogClubedit()
{
}
