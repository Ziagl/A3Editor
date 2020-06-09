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

class DialogUefaranking : public wxDialog
{
public:
    DialogUefaranking(wxWindow* parent, Toolset* const tools, wxWindowID id = wxID_ANY, const wxString& title = _("EP-5-Jahres-Wertung"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogUefaranking();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnApply(wxCommandEvent& event);
    void OnSelectCountryActivated(wxListEvent& event);

protected:
    wxListCtrl* m_countryList;
    wxButton* m_buttonApply;
    wxButton* m_buttonAbort;

private:
    void initializeCountryList(wxListCtrl* control);

    Toolset* tools = nullptr;
};

