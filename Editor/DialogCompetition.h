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
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

// type of displayed person
// dialog is able to edit players, trainers and managers
enum CompetitionType
{
    COMP_CLEAGUE,
    COMP_EM,
    COMP_WM
};

class DialogCompetition : public wxDialog
{
public:
    DialogCompetition(wxWindow* parent, Toolset* const tools, CompetitionType type, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogCompetition();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnGroup(wxCommandEvent& event);
    void OnCountry(wxCommandEvent& event);

protected:
    std::vector<wxToggleButton*> m_buttonGroup;
    std::vector<wxChoice*> m_choiceTeam;
    std::vector<wxChoice*> m_choiceCountry;
    wxButton* m_buttonOk;
    wxButton* m_buttonAbort;

private:
    void saveGroupData();
    void loadGroupData();
    int getCountryListIndexByCountryIndex(short countryIndex);
    void updateTeamList(int controlIndex, short countryIndex, short teamId);

    Toolset* tools = nullptr;
    CompetitionType m_type;
    int m_selectedGroup = 0;
    std::vector<std::vector<std::tuple<short, short>>> m_teams;
    std::vector<std::string> m_countries;
    std::shared_ptr<Core::Competition> m_competition;
};

