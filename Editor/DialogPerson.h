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

class DialogPerson : public wxDialog
{
public:
    DialogPerson(wxWindow* parent, Toolset* const tools, std::string selectedCountry, Core::Person& person, short type,  wxWindowID id = wxID_ANY, const wxString& title = _("Trainer ändern"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPerson();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnDay(wxSpinEvent& event);
    void OnMonth(wxSpinEvent& event);
    void OnYear(wxSpinEvent& event);

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

private:
    void updateBirthday();

    Toolset* tools = nullptr;
    Core::Trainer& m_trainer;
    Core::Manager& m_manager;
    std::shared_ptr<Core::Country> m_country = nullptr;
    short type = 0;
};

