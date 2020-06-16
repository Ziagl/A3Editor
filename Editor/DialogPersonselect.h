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
#include <wx/listctrl.h>

#include "Toolset.h"

class DialogPersonselect : public wxDialog
{
public:
    DialogPersonselect(wxWindow* parent,
        Toolset* const tools,
        std::string const selectedCountry,
        short type,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Trainer & CO-Trainer"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(630, 450),
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPersonselect();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnApply(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnSelectPerson(wxListEvent& event);
    void OnSelectPersonActivated(wxListEvent& event);
   
private:
    void initializePersonList(wxListCtrl* control);

protected:
    wxListCtrl* m_personList;
    wxButton* m_buttonEdit;
    wxButton* m_buttonApply;
    wxButton* m_buttonAbort;

public:
    wxListCtrl* GetPersonList() { return m_personList; }
    wxButton* GetButtonEdit() { return m_buttonEdit; }
    wxButton* GetButtonApply() { return m_buttonApply; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }
    
private:
    void callRefereeDialog();
    void callPersonDialog();

    std::string m_selectedCountry;
    std::string m_selectedPerson;
    Toolset* tools = nullptr;
    wxWindow* parent = nullptr;
    short type = 0;                 // type of display (0...co-trainer or 1...goalkeeper trainer9
    std::shared_ptr<Core::International> m_international;
    std::vector<Core::Referee> m_referees;
    std::vector<Core::Manager> m_managers;
    std::vector<Core::Trainer> m_trainer;
    std::shared_ptr<Core::Country> m_country;
};

