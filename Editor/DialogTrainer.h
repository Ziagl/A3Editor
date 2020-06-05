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

class DialogTrainer : public wxDialog
{
public:
    DialogTrainer(wxWindow* parent, Toolset* const tools, std::string country, std::string trainer, wxWindowID id = wxID_ANY, const wxString& title = _("Trainer ändern"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogTrainer();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

    wxStaticText* m_staticText31;
    wxTextCtrl* m_textCtrl33;
    wxStaticText* m_staticText37;
    wxTextCtrl* m_textCtrl39;
    wxStaticText* m_staticText51;
    wxStaticText* m_staticText75;
    wxSpinButton* m_spinButton77;
    wxStaticText* m_staticText79;
    wxSpinButton* m_spinButton81;
    wxStaticText* m_staticText83;
    wxSpinButton* m_spinButton85;
    wxStaticText* m_staticText53;
    wxStaticText* m_staticText67;
    wxSpinButton* m_spinButton69;
    wxStaticText* m_staticText71;
    wxStaticText* m_staticText47;
    wxChoice* m_choice49;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

public:
    wxStaticText* GetStaticText31() { return m_staticText31; }
    wxTextCtrl* GetTextCtrl33() { return m_textCtrl33; }
    wxStaticText* GetStaticText37() { return m_staticText37; }
    wxTextCtrl* GetTextCtrl39() { return m_textCtrl39; }
    wxStaticText* GetStaticText51() { return m_staticText51; }
    wxStaticText* GetStaticText75() { return m_staticText75; }
    wxSpinButton* GetSpinButton77() { return m_spinButton77; }
    wxStaticText* GetStaticText79() { return m_staticText79; }
    wxSpinButton* GetSpinButton81() { return m_spinButton81; }
    wxStaticText* GetStaticText83() { return m_staticText83; }
    wxSpinButton* GetSpinButton85() { return m_spinButton85; }
    wxStaticText* GetStaticText53() { return m_staticText53; }
    wxStaticText* GetStaticText67() { return m_staticText67; }
    wxSpinButton* GetSpinButton69() { return m_spinButton69; }
    wxStaticText* GetStaticText71() { return m_staticText71; }
    wxStaticText* GetStaticText47() { return m_staticText47; }
    wxChoice* GetChoice49() { return m_choice49; }
    wxButton* GetButtonOk() { return m_buttonOk; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }

private:
    Toolset* tools = nullptr;
};

