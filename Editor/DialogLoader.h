#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/gauge.h>
#include <wx/stattext.h>

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogLoader : public wxDialog
{
public:
    DialogLoader(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Loader"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = 0);
    virtual ~DialogLoader();

protected:
    wxGauge* m_gauge;
    wxStaticText* m_staticText;

protected:

public:
    void setProgress(int percent, std::string text);
    wxGauge* GetGauge() { return m_gauge; }
    wxStaticText* GetStaticText() { return m_staticText; }
};

