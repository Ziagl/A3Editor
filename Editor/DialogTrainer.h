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

class DialogTrainer : public wxDialog
{
public:
    DialogTrainer(wxWindow* parent,
        Toolset* const tools,
        std::string const selectedCountry,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Trainer & CO-Trainer"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(630, 450),
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogTrainer();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnApply(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
   
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
    Toolset* tools = nullptr;
};

