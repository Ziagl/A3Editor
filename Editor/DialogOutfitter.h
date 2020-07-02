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

class DialogOutfitter : public wxDialog
{
public:
    DialogOutfitter(wxWindow* parent, Toolset* const tools, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogOutfitter();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnSelectOutfitter(wxListEvent& event);
    void OnSelectOutfitterActivated(wxListEvent& event);

protected:
    wxListCtrl* m_listCtrlOutfitter;
    wxButton* m_buttonEdit;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    void initializeOutfitterList(wxListCtrl* control);

    Toolset* tools = nullptr;
    wxWindow* parent = nullptr;
    std::shared_ptr<Core::Additional> m_additional;
    std::vector<std::string> m_outfitterList;
    int m_selectedOutfitter = -1;
};

