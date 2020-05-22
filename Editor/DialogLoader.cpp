#include "DialogLoader.h"


DialogLoader::DialogLoader(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
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

    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(boxSizer, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_gauge = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxGA_HORIZONTAL);
    m_gauge->SetValue(0);

    mainSizer->Add(m_gauge, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText = new wxStaticText(this, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxGA_HORIZONTAL);

    mainSizer->Add(m_staticText, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("DialogLoader"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
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

DialogLoader::~DialogLoader()
{
}

void DialogLoader::setProgress(int percent, std::string text)
{
    m_gauge->SetValue(percent);
    m_staticText->SetLabel(text);
    this->Refresh();
}