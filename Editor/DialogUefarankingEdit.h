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
#include <wx/spinbutt.h>
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

class DialogUefarankingEdit : public wxDialog
{
public:
    DialogUefarankingEdit(wxWindow* parent, Toolset* const tools, Core::UefaCountry &country, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogUefarankingEdit();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnYear6(wxSpinEvent& event);
    void OnYear5(wxSpinEvent& event);
    void OnYear4(wxSpinEvent& event);
    void OnYear3(wxSpinEvent& event);
    void OnYear2(wxSpinEvent& event);
    void OnYear1(wxSpinEvent& event);

protected:
    wxStaticText* m_staticText29;
    wxStaticText* m_staticText31;
    wxStaticText* m_staticText6YearOld;
    wxStaticText* m_staticText35;
    wxStaticText* m_staticText6YearNew;
    wxSpinButton* m_spinButtonYear6;
    wxStaticText* m_staticText43;
    wxStaticText* m_staticText45;
    wxStaticText* m_staticText5YearOld;
    wxStaticText* m_staticText49;
    wxStaticText* m_staticText5YearNew;
    wxSpinButton* m_spinButtonYear5;
    wxStaticText* m_staticText55;
    wxStaticText* m_staticText57;
    wxStaticText* m_staticText4YearOld;
    wxStaticText* m_staticText61;
    wxStaticText* m_staticText4YearNew;
    wxSpinButton* m_spinButtonYear4;
    wxStaticText* m_staticText67;
    wxStaticText* m_staticText69;
    wxStaticText* m_staticText3YearOld;
    wxStaticText* m_staticText73;
    wxStaticText* m_staticText3YearNew;
    wxSpinButton* m_spinButtonYear3;
    wxStaticText* m_staticText79;
    wxStaticText* m_staticText81;
    wxStaticText* m_staticText2YearOld;
    wxStaticText* m_staticText85;
    wxStaticText* m_staticText2YearNew;
    wxSpinButton* m_spinButtonYear2;
    wxStaticText* m_staticText91;
    wxStaticText* m_staticText93;
    wxStaticText* m_staticTextLastYearOld;
    wxStaticText* m_staticText97;
    wxStaticText* m_staticTextLastYearNew;
    wxSpinButton* m_spinButtonYear1;
    wxStaticText* m_staticText103;
    wxStaticText* m_staticText105;
    wxStaticText* m_staticTextSumOld;
    wxStaticText* m_staticText109;
    wxStaticText* m_staticTextSumNew;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    void updateSum();

    Toolset* tools = nullptr;
    short selectedIndex;
    Core::UefaCountry& country;
};

