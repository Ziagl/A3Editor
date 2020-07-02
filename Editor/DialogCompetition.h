#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogCompetition : public wxDialog
{
public:
    DialogCompetition(wxWindow* parent, Toolset* const tools, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogCompetition();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

protected:
    std::vector<wxButton*> m_buttonGroup;
    wxStaticText* m_staticText53;
    wxChoice* m_choiceTeam1;
    wxStaticText* m_staticText57;
    wxChoice* m_choiceCountry1;
    wxStaticText* m_staticText61;
    wxChoice* m_choiceTeam2;
    wxStaticText* m_staticText65;
    wxChoice* m_choiceCountry2;
    wxStaticText* m_staticText69;
    wxChoice* m_choiceTeam3;
    wxStaticText* m_staticText73;
    wxChoice* m_choiceCountry3;
    wxStaticText* m_staticText77;
    wxChoice* m_choiceTeam4;
    wxStaticText* m_staticText81;
    wxChoice* m_choiceCountry4;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
};

