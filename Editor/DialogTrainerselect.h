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

class DialogTrainerselect : public wxDialog
{
public:
    DialogTrainerselect(wxWindow* parent,
        Toolset* const tools,
        std::string const selectedCountry,
        short type,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Trainer & CO-Trainer"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(630, 450),
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogTrainerselect();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnApply(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnSelectTrainer(wxListEvent& event);
    void OnSelectTrainerActivated(wxListEvent& event);
   
private:
    void initializeTrainerList(wxListCtrl* control);

protected:
    wxListCtrl* m_trainerList;
    wxButton* m_buttonEdit;
    wxButton* m_buttonApply;
    wxButton* m_buttonAbort;

public:
    wxListCtrl* GetTrainerList() { return m_trainerList; }
    wxButton* GetButtonEdit() { return m_buttonEdit; }
    wxButton* GetButtonApply() { return m_buttonApply; }
    wxButton* GetButtonAbort() { return m_buttonAbort; }
    
private:
    std::string m_selectedCountry;
    std::string m_selectedTrainer;
    Toolset* tools = nullptr;
    wxWindow* parent = nullptr;
    short type = 0;                 // type of display (0...co-trainer or 1...goalkeeper trainer9
};

