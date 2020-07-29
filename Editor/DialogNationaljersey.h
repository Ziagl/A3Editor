#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/tglbtn.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogNationaljersey : public wxDialog
{
public:
    DialogNationaljersey(wxWindow* parent, Toolset* const tools, const std::string selectedCountry, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogNationaljersey();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

protected:
    wxStaticBitmap* m_staticBitmap19;
    wxToggleButton* m_toggleButton29;
    wxToggleButton* m_toggleButton31;
    wxStaticText* m_staticText37;
    wxChoice* m_choice39;
    wxStaticText* m_staticText41;
    wxChoice* m_choice43;
    wxStaticText* m_staticText45;
    wxChoice* m_choice47;
    wxStaticText* m_staticText49;
    wxChoice* m_choice51;
    wxRadioButton* m_radioButton57;
    wxRadioButton* m_radioButton59;
    wxRadioButton* m_radioButton61;
    wxRadioButton* m_radioButton63;
    wxRadioButton* m_radioButton65;
    wxRadioButton* m_radioButton67;
    wxRadioButton* m_radioButton69;
    wxRadioButton* m_radioButton71;
    wxRadioButton* m_radioButton73;
    wxRadioButton* m_radioButton75;
    wxCheckBox* m_checkBox81;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
    std::string m_selectedCountry;

};

