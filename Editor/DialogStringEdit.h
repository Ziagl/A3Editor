#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/button.h>

#include "Toolset.h"

class DialogStringEdit : public wxDialog
{
public:
    DialogStringEdit(wxWindow* parent, Toolset* const tools, std::string& value, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogStringEdit();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

protected:
    wxTextCtrl* m_textCtrlString;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    Toolset* tools = nullptr;
    std::string& value;
};

