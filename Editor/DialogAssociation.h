#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinbutt.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/panel.h>
#include <wx/button.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogAssociation : public wxDialog
{
public:
    DialogAssociation(wxWindow* parent, Toolset* const tools, std::string const selectedCountry, wxWindowID id = wxID_ANY, const wxString& title = _("Verband"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogAssociation();

protected:
    wxStaticText* m_staticText41;
    wxTextCtrl* m_textCtrl43;
    wxStaticText* m_staticText45;
    wxTextCtrl* m_textCtrl47;
    wxStaticText* m_staticText49;
    wxStaticText* m_staticText53;
    wxSpinButton* m_spinButton55;
    wxStaticText* m_staticText57;
    wxSpinButton* m_spinButton59;
    wxStaticText* m_staticText61;
    wxSpinButton* m_spinButton63;
    wxStaticText* m_staticText99;
    wxStaticText* m_staticText103;
    wxSpinButton* m_spinButton105;
    wxStaticText* m_staticText107;
    wxStaticText* m_staticText65;
    wxChoice* m_choiceReputation;
    wxStaticText* m_staticText71;
    wxTextCtrl* m_textCtrl73;
    wxStaticText* m_staticText75;
    wxTextCtrl* m_textCtrl77;
    wxStaticText* m_staticText79;
    wxStaticText* m_staticText83;
    wxSpinButton* m_spinButton85;
    wxStaticText* m_staticText87;
    wxSpinButton* m_spinButton89;
    wxStaticText* m_staticText91;
    wxSpinButton* m_spinButton93;
    wxPanel* m_panel97;
    wxStaticText* m_staticText95;
    wxStaticText* m_staticText35;
    wxTextCtrl* m_textCtrl37;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

protected:

public:
    wxStaticText* GetStaticText41() { return m_staticText41; }
    wxTextCtrl* GetTextCtrl43() { return m_textCtrl43; }
    wxStaticText* GetStaticText45() { return m_staticText45; }
    wxTextCtrl* GetTextCtrl47() { return m_textCtrl47; }
    wxStaticText* GetStaticText49() { return m_staticText49; }
    wxStaticText* GetStaticText53() { return m_staticText53; }
    wxSpinButton* GetSpinButton55() { return m_spinButton55; }
    wxStaticText* GetStaticText57() { return m_staticText57; }
    wxSpinButton* GetSpinButton59() { return m_spinButton59; }
    wxStaticText* GetStaticText61() { return m_staticText61; }
    wxSpinButton* GetSpinButton63() { return m_spinButton63; }
    wxStaticText* GetStaticText99() { return m_staticText99; }
    wxStaticText* GetStaticText103() { return m_staticText103; }
    wxSpinButton* GetSpinButton105() { return m_spinButton105; }
    wxStaticText* GetStaticText107() { return m_staticText107; }
    wxStaticText* GetStaticText65() { return m_staticText65; }
    wxChoice* GetChoiceReputation() { return m_choiceReputation; }
    wxStaticText* GetStaticText71() { return m_staticText71; }
    wxTextCtrl* GetTextCtrl73() { return m_textCtrl73; }
    wxStaticText* GetStaticText75() { return m_staticText75; }
    wxTextCtrl* GetTextCtrl77() { return m_textCtrl77; }
    wxStaticText* GetStaticText79() { return m_staticText79; }
    wxStaticText* GetStaticText83() { return m_staticText83; }
    wxSpinButton* GetSpinButton85() { return m_spinButton85; }
    wxStaticText* GetStaticText87() { return m_staticText87; }
    wxSpinButton* GetSpinButton89() { return m_spinButton89; }
    wxStaticText* GetStaticText91() { return m_staticText91; }
    wxSpinButton* GetSpinButton93() { return m_spinButton93; }
    wxPanel* GetPanel97() { return m_panel97; }
    wxStaticText* GetStaticText95() { return m_staticText95; }
    wxStaticText* GetStaticText35() { return m_staticText35; }
    wxTextCtrl* GetTextCtrl37() { return m_textCtrl37; }
    wxButton* GetButtonOk() { return m_buttonOk; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }

private:
    Toolset* tools = nullptr;
    std::string selectedCountry;
    Core::Trainer nationalTrainer;
    Core::Person president;
    std::shared_ptr<Core::Country> country = nullptr;
};

