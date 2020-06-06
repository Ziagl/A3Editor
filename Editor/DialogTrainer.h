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

class DialogTrainer : public wxDialog
{
public:
    DialogTrainer(wxWindow* parent, Toolset* const tools, std::string selectedCountry, std::string selectedTrainer, short type,  wxWindowID id = wxID_ANY, const wxString& title = _("Trainer ändern"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogTrainer();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnTextName(wxCommandEvent& event);
    void OnTextLastname(wxCommandEvent& event);
    void OnChangeReputation(wxListEvent& event);
    void OnDay(wxSpinEvent& event);
    void OnMonth(wxSpinEvent& event);
    void OnYear(wxSpinEvent& event);
    void OnCompetence(wxSpinEvent& event);

    wxStaticText* m_staticText31;
    wxTextCtrl* m_textName;
    wxStaticText* m_staticText37;
    wxTextCtrl* m_textFirstname;
    wxStaticText* m_staticText51;
    wxStaticText* m_staticTextDay;
    wxSpinButton* m_spinButtonDay;
    wxStaticText* m_staticTextMonth;
    wxSpinButton* m_spinButtonMonth;
    wxStaticText* m_staticTextYear;
    wxSpinButton* m_spinButtonYear;
    wxStaticText* m_staticText53;
    wxStaticText* m_staticTextCompetence;
    wxSpinButton* m_spinButtonCompetence;
    wxStaticText* m_staticTextAge;
    wxStaticText* m_staticText47;
    wxChoice* m_reputationChoice;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

public:
    wxStaticText* GetStaticText31() { return m_staticText31; }
    wxTextCtrl* GetTextName() { return m_textName; }
    wxStaticText* GetStaticText37() { return m_staticText37; }
    wxTextCtrl* GetTextFirstname() { return m_textFirstname; }
    wxStaticText* GetStaticText51() { return m_staticText51; }
    wxStaticText* GetStaticTextDay() { return m_staticTextDay; }
    wxSpinButton* GetSpinButtonDay() { return m_spinButtonDay; }
    wxStaticText* GetStaticTextMonth() { return m_staticTextMonth; }
    wxSpinButton* GetSpinButtonMonth() { return m_spinButtonMonth; }
    wxStaticText* GetStaticTextYear() { return m_staticTextYear; }
    wxSpinButton* GetSpinButtonYear() { return m_spinButtonYear; }
    wxStaticText* GetStaticText53() { return m_staticText53; }
    wxStaticText* GetStaticTextCompetence() { return m_staticTextCompetence; }
    wxSpinButton* GetSpinButtonCompetence() { return m_spinButtonCompetence; }
    wxStaticText* GetStaticTextAge() { return m_staticTextAge; }
    wxStaticText* GetStaticText47() { return m_staticText47; }
    wxChoice* GetReputationChoice() { return m_reputationChoice; }
    wxButton* GetButtonOk() { return m_buttonOk; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }

private:
    void updateBithday();

    Toolset* tools = nullptr;
    Core::Trainer trainer;
    size_t trainerIndex = 0;
    std::shared_ptr<Core::Country> country = nullptr;
    short type = 0;
};

