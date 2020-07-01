#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinbutt.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/msgdlg.h>

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
enum PlayereditType
{
    PET_PLAYER,
    PET_TRAINER,
    PET_MANAGER
};

// this dialog can be called from different places to display different
// data sources
enum DialogPlayereditType
{
    DPT_PLAYER,        // standard for player of team of playable country
    DPT_OTHERPLAYER    // other player for all players from non playable countries that are used for national teams
};

class DialogPlayeredit : public wxDialog
{
public:
    DialogPlayeredit(wxWindow* parent, Toolset* const tools, std::string selectedCountry, std::string selectedClub, int type, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPlayeredit();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnList(wxCommandEvent& event);
    void OnShirtNumberReset(wxCommandEvent& event);
    void OnSelectPerson(wxListEvent& event);
    void OnDay(wxSpinEvent& event);
    void OnMonth(wxSpinEvent& event);
    void OnYear(wxSpinEvent& event);
    void OnSkill(wxSpinEvent& event);
    void OnTalent(wxSpinEvent& event);
    void OnFoot(wxSpinEvent& event);
    void OnShirtNumber(wxSpinEvent& event);
    void OnDayTrainer(wxSpinEvent& event);
    void OnMonthTrainer(wxSpinEvent& event);
    void OnYearTrainer(wxSpinEvent& event);
    void OnCompetenceTrainer(wxSpinEvent& event);
    void OnDayManager(wxSpinEvent& event);
    void OnMonthManager(wxSpinEvent& event);
    void OnYearManager(wxSpinEvent& event);
    void OnCompetenceManager(wxSpinEvent& event);

protected:
    wxListCtrl* m_listCtrlPlayer;
    wxButton* m_buttonList;
    wxPanel* m_panel494;
    wxButton* m_buttonShirtNumbers;
    wxNotebook* m_notebook21;
    wxPanel* m_panelData1;
    wxStaticText* m_staticText37;
    wxTextCtrl* m_textCtrlName;
    wxStaticText* m_staticText41;
    wxTextCtrl* m_textCtrlStagename;
    wxStaticText* m_staticText45;
    wxTextCtrl* m_textCtrlFirstname;
    wxStaticText* m_staticText455;
    wxStaticText* m_staticTextDay;
    wxSpinButton* m_spinButtonDay;
    wxStaticText* m_staticTextMonth;
    wxSpinButton* m_spinButtonMonth;
    wxStaticText* m_staticTextYear;
    wxSpinButton* m_spinButtonYear;
    wxStaticText* m_staticText469;
    wxStaticText* m_staticTextSkill;
    wxSpinButton* m_spinButtonSkill;
    wxStaticText* m_staticTextAge;
    wxButton* m_button445;
    wxStaticText* m_staticText425;
    wxStaticText* m_staticTextTalent;
    wxSpinButton* m_spinButtonTalent;
    wxStaticText* m_staticText431;
    wxStaticText* m_staticTextStrongFoot;
    wxSpinButton* m_spinButtonFoot;
    wxStaticText* m_staticText437;
    wxStaticText* m_staticTextShirtNumber;
    wxSpinButton* m_spinButtonShirtNumber;
    wxStaticText* m_staticText55;
    wxStaticText* m_staticTextAverageSkill;
    wxPanel* m_panelData2;
    wxStaticText* m_staticText59;
    wxChoice* m_choiceNationality;
    wxStaticText* m_staticText63;
    wxChoice* m_choiceSecondNationality;
    wxCheckBox* m_checkNational;
    wxCheckBox* m_checkNationalplayer;
    wxCheckBox* m_checkNationalresigned;
    wxCheckBox* m_checkCaptainresigned;
    wxRadioButton* m_radioBright;
    wxRadioButton* m_radioDark;
    wxRadioButton* m_radioAfrikan;
    wxRadioButton* m_radioAsian;
    wxRadioButton* m_radioExtremelyshort;
    wxRadioButton* m_radioShort;
    wxRadioButton* m_radioCurly;
    wxRadioButton* m_radioLong;
    wxCheckBox* m_checkUnshaved;
    wxCheckBox* m_checkBeard;
    wxCheckBox* m_checkMoustache;
    wxCheckBox* m_checkGoatee;
    wxRadioButton* m_radioLightblonde;
    wxRadioButton* m_radioRed;
    wxRadioButton* m_radioGrey;
    wxRadioButton* m_radioBlond;
    wxRadioButton* m_radioBlack;
    wxRadioButton* m_radioBrown;
    wxRadioButton* m_radioBald;
    wxPanel* m_panelPositions;
    wxRadioButton* m_radioButtonMainGoalkeeper;
    wxRadioButton* m_radioButtonMainSweeper;
    wxRadioButton* m_radioMainCenterback;
    wxRadioButton* m_radioMainLeftdefender;
    wxRadioButton* m_radioMainRightdefender;
    wxRadioButton* m_radioMainDefensivemidfielder;
    wxRadioButton* m_radioMainLeftmidfielder;
    wxRadioButton* m_radioMainRightmidfielder;
    wxRadioButton* m_radioMainAttackingmidfielder;
    wxRadioButton* m_radioMainForward;
    wxPanel* m_panel523;
    wxCheckBox* m_checkBoxSecondarySweeper;
    wxCheckBox* m_checkBoxSecondaryCenterback;
    wxCheckBox* m_checkBoxSecondaryLeftdefender;
    wxCheckBox* m_checkBoxSecondaryRightdefender;
    wxCheckBox* m_checkBoxSecondaryDefensivemidfielder;
    wxCheckBox* m_checkBoxSecondaryLeftmidfielder;
    wxCheckBox* m_checkBoxSecondaryRightmidfielder;
    wxCheckBox* m_checkBoxSecondaryAttackingmidfielder;
    wxCheckBox* m_checkBoxSecondaryForward;
    wxPanel* m_panelSkills;
    wxStaticText* m_staticText279;
    wxStaticText* m_staticText281;
    std::vector<wxCheckBox*> m_fieldPlayerPlus;
    std::vector<wxCheckBox*> m_fieldPlayerMinus;
    wxStaticText* m_staticText285;
    wxStaticText* m_staticText287;
    std::vector<wxCheckBox*> m_goalkeeperPlus;
    std::vector<wxCheckBox*> m_goalkeeperMinus;
    wxPanel* m_panelCharacteristics1;
    std::vector<wxCheckBox*> m_properties;
    std::vector<wxCheckBox*> m_personality;
    wxPanel* m_panelCharacteristics2;
    wxRadioButton* m_radioButtonNormal;
    wxRadioButton* m_radioButtonRobust;
    wxRadioButton* m_radioButtonSusceptible;
    wxRadioButton* m_radioButtonKneeproblems;
    wxRadioButton* m_radioButtonQuicklyfitagain;
    wxRadioButton* m_radioButtonLastsuntilfitagain;
    wxRadioButton* m_radioButtonSnivelling;
    wxRadioButton* m_radioButtonAudiencenormal;
    wxRadioButton* m_radioButtonAudiencefavorite;
    wxRadioButton* m_radioButtonAudiencehatefigure;
    wxPanel* m_panelTrainer;
    wxStaticText* m_staticText537;
    wxTextCtrl* m_textCtrlTrainerName;
    wxStaticText* m_staticText541;
    wxTextCtrl* m_textCtrlTrainerFirstname;
    wxStaticText* m_staticText545;
    wxStaticText* m_staticTextTrainerDay;
    wxSpinButton* m_spinButtonTrainerDay;
    wxStaticText* m_staticTextTrainerMonth;
    wxSpinButton* m_spinButtonTrainerMonth;
    wxStaticText* m_staticTextTrainerYear;
    wxSpinButton* m_spinButtonTrainerYear;
    wxStaticText* m_staticText549;
    wxStaticText* m_staticTextTrainerCompetence;
    wxSpinButton* m_spinButtonTrainerCompetence;
    wxStaticText* m_staticTextTrainerAge;
    wxStaticText* m_staticText553;
    wxChoice* m_choiceTrainerReputation;
    wxPanel* m_panelManager;
    wxStaticText* m_staticText581;
    wxTextCtrl* m_textCtrlManagerName;
    wxStaticText* m_staticText583;
    wxTextCtrl* m_textCtrlManagerFirstname;
    wxStaticText* m_staticText587;
    wxStaticText* m_staticTextManagerDay;
    wxSpinButton* m_spinButtonManagerDay;
    wxStaticText* m_staticTextManagerMonth;
    wxSpinButton* m_spinButtonManagerMonth;
    wxStaticText* m_staticTextManagerYear;
    wxSpinButton* m_spinButtonManagerYear;
    wxStaticText* m_staticText593;
    wxStaticText* m_staticTextManagerCompetence;
    wxSpinButton* m_spinButtonManagerCompetence;
    wxStaticText* m_staticTextManagerAge;
    wxStaticText* m_staticText155;
    wxPanel* m_panel;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    void initializePlayerList(wxListCtrl* control);
    void populatePerson();
    void populatePlayer(std::shared_ptr<Core::Player> player);
    void populateTrainer();
    void populateManager();
    void computeAverageSkill();
    void savePlayer(std::shared_ptr<Core::Player> player);
    void saveTrainer();
    void saveManager();
    void recomputeShirtNumbers();
    void updateListItem();

    void enableGoalkeeperCapabilities();
    void disableGoalkeeperCapabilities();
    void enableFieldPlayerCapabilities();
    void disableFieldPlayerCapabilities();
    int findNextShirtNumber(int start, bool higher);
    short getMainPosition();
    void saveLastSelectedPlayer();

    Toolset* tools = nullptr;
    wxWindow* parent = nullptr;
    std::string m_selectedCountry;
    std::shared_ptr<Core::Country> m_country;
    std::string m_selectedClub;
    std::shared_ptr<Core::Team> m_team;
    std::vector<std::shared_ptr<Core::Player>> m_players;
    std::string m_selectedPerson;
    int m_lastSelectedItem = -1;
    float m_averageSkill = 0.0f;
    int m_lastType = -1;
    int m_type = 0;
};
