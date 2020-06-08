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
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/listctrl.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogReferee : public wxDialog
{
public:
    DialogReferee(wxWindow* parent, Toolset* const tools, std::string selectedCountry, std::string selectedReferee, short type, wxWindowID id = wxID_ANY, const wxString& title = _("Schiedsrichter ändern"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(/*510, 400*/-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogReferee();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnTextName(wxCommandEvent& event);
    void OnTextLastname(wxCommandEvent& event);
    void OnChangeTeam(wxListEvent& event);
    void OnDay(wxSpinEvent& event);
    void OnMonth(wxSpinEvent& event);
    void OnYear(wxSpinEvent& event);
    void OnCompetence(wxSpinEvent& event);
    void OnHardness(wxSpinEvent& event);

    wxStaticText* m_staticText29;
    wxTextCtrl* m_textName;
    wxStaticText* m_staticText33;
    wxTextCtrl* m_textFirstname;
    wxStaticText* m_staticText61;
    wxStaticText* m_staticTextCompetence;
    wxSpinButton* m_spinButtonCompetence;
    wxStaticText* m_staticText67;
    wxStaticText* m_staticTextHardness;
    wxSpinButton* m_spinButtonHardness;
    wxStaticText* m_staticText45;
    wxChoice* m_teamChoice;
    wxCheckBox* m_checkBoxHomeReferee;
    wxCheckBox* m_checkBoxGuestReferee;
    wxCheckBox* m_checkBoxHatesTimeGame;
    wxCheckBox* m_checkBoxHatesGripe;
    wxCheckBox* m_checkBoxHatesCoaching;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

public:
    wxStaticText* GetStaticText29() { return m_staticText29; }
    wxTextCtrl* GetTextCtrlName() { return m_textName; }
    wxStaticText* GetStaticText33() { return m_staticText33; }
    wxTextCtrl* GetTextFirstname() { return m_textFirstname; }
    wxStaticText* GetStaticText61() { return m_staticText61; }
    wxStaticText* GetStaticTextCompetence() { return m_staticTextCompetence; }
    wxSpinButton* GetSpinButtonCompetence() { return m_spinButtonCompetence; }
    wxStaticText* GetStaticText67() { return m_staticText67; }
    wxStaticText* GetStaticTextHardness() { return m_staticTextHardness; }
    wxSpinButton* GetSpinButtonHardness() { return m_spinButtonHardness; }
    wxStaticText* GetStaticText45() { return m_staticText45; }
    wxChoice* GeTeamChoice() { return m_teamChoice; }
    wxCheckBox* GetCheckBoxHomeReferee() { return m_checkBoxHomeReferee; }
    wxCheckBox* GetCheckBoxGuestReferee() { return m_checkBoxGuestReferee; }
    wxCheckBox* GetCheckBoxHatesTimeGame() { return m_checkBoxHatesTimeGame; }
    wxCheckBox* GetCheckBoxHatesGripe() { return m_checkBoxHatesGripe; }
    wxCheckBox* GetCheckBoxHatesCoaching() { return m_checkBoxHatesCoaching; }
    wxButton* GetButtonOk() { return m_buttonOk; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }

private:
    Toolset* tools = nullptr;
    Core::Referee referee;
    size_t personIndex = 0;
    std::shared_ptr<Core::Country> country = nullptr;
    short type = 0;
};

