#include "DialogPlayersearch.h"


DialogPlayersearch::DialogPlayersearch(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
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

    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer23 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Auswahl")), wxVERTICAL);

    boxSizer21->Add(staticBoxSizer23, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_radioSearchPerson = new wxRadioButton(this, wxID_ANY, _("Person suchen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioSearchPerson->SetValue(1);

    staticBoxSizer23->Add(m_radioSearchPerson, 0, wxALL, WXC_FROM_DIP(5));

    m_radioCheckData = new wxRadioButton(this, wxID_ANY, _("Daten prüfen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_radioCheckData->SetValue(1);

    staticBoxSizer23->Add(m_radioCheckData, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonStart = new wxButton(this, wxID_ANY, _("START"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer23->Add(m_buttonStart, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer25 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Person")), wxVERTICAL);

    boxSizer21->Add(staticBoxSizer25, 2, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticFirstname = new wxStaticText(this, wxID_ANY, _("Vorname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer25->Add(m_staticFirstname, 0, wxALL, WXC_FROM_DIP(0));

    m_textFirstname = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textFirstname->SetHint(wxT(""));
#endif

    staticBoxSizer25->Add(m_textFirstname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticLastname = new wxStaticText(this, wxID_ANY, _("Nachname"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer25->Add(m_staticLastname, 0, wxALL, WXC_FROM_DIP(0));

    m_textLastname = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textLastname->SetHint(wxT(""));
#endif

    staticBoxSizer25->Add(m_textLastname, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Bisher durchsucht...")), wxVERTICAL);

    mainSizer->Add(staticBoxSizer27, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_gaugeProgress = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxGA_HORIZONTAL);
    m_gaugeProgress->SetValue(0);

    staticBoxSizer27->Add(m_gaugeProgress, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticProgressText = new wxStaticText(this, wxID_ANY, _("Erstelle Liste...."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    staticBoxSizer27->Add(m_staticProgressText, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer33 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Gefundene Einträge...")), wxVERTICAL);

    mainSizer->Add(staticBoxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textSearchResult = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, 300)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textSearchResult->SetHint(wxT(""));
#endif

    staticBoxSizer33->Add(m_textSearchResult, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer12, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonCancel = new wxButton(this, wxID_CANCEL, _("Verlassen"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer12->Add(m_buttonCancel, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("DialogPlayersearch"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 700)));
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

DialogPlayersearch::~DialogPlayersearch()
{
}
