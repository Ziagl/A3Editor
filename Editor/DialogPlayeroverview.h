#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/listctrl.h>
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

class DialogPlayeroverview : public wxDialog
{
public:
    DialogPlayeroverview(wxWindow* parent, Toolset* const tools, std::vector<std::shared_ptr<Core::Player>> players, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPlayeroverview();

protected:
    // Event Handler
    void OnType(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);

protected:
    wxListCtrl* m_listCtrlPlayer;
    wxButton* m_buttonType;
    wxButton* m_buttonOK;

private:
    void initializePlayerList(wxListCtrl* control);

    Toolset* tools = nullptr;
    std::vector<std::shared_ptr<Core::Player>> m_players;
    bool m_typeProperties = true;   // current display type (properties or personality)
};
