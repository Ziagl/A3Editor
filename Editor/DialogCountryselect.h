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
#include <wx/statbmp.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogCountryselect : public wxDialog
{
public:
    DialogCountryselect(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Countryselect"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(326, 228),
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogCountryselect();

    wxListCtrl* GetListCtrl79()
    {
        return m_listCtrl79;
    }
    wxListCtrl* GetListCtrl81()
    {
        return m_listCtrl81;
    }
    wxButton* GetButtonEdit()
    {
        return m_buttonEdit;
    }
    wxButton* GetButtonApply()
    {
        return m_buttonApply;
    }
    wxButton* GetButtonAbort()
    {
        return m_buttonAbort;
    }
    wxButton* GetButtonSearchPlayer()
    {
        return m_buttonSearchPlayer;
    }
    wxStaticBitmap* GetStaticBitmapClubImage()
    {
        return m_staticBitmapClubImage;
    }

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);

protected:
    wxListCtrl* m_listCtrl79;
    wxListCtrl* m_listCtrl81;
    wxButton* m_buttonEdit;
    wxButton* m_buttonApply;
    wxButton* m_buttonAbort;
    wxButton* m_buttonSearchPlayer;
    wxStaticBitmap* m_staticBitmapClubImage;
};