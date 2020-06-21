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

#include "Toolset.h"

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogPlayeredit : public wxDialog
{
public:
    DialogPlayeredit(wxWindow* parent, Toolset* const tools, std::string selectedCountry, std::string selectedClub, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPlayeredit();

protected:
    // Event Handler
    void OnAbort(wxCommandEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnSelectPerson(wxListEvent& event);

protected:
    wxListCtrl* m_listCtrlPlayer;
    wxButton* m_button147;
    wxPanel* m_panel494;
    wxButton* m_button149;
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
    wxStaticText* m_staticText475;
    wxStaticText* m_staticTextAge;
    wxButton* m_button445;
    wxStaticText* m_staticText425;
    wxStaticText* m_staticTextTalent;
    wxSpinButton* m_spinButton429;
    wxStaticText* m_staticText431;
    wxStaticText* m_staticTextStrongFoot;
    wxSpinButton* m_spinButton435;
    wxStaticText* m_staticText437;
    wxStaticText* m_staticTextShirtNumber;
    wxSpinButton* m_spinButton441;
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
    /*wxCheckBox* m_checkFighter;
    wxCheckBox* m_checkTrainingworldchampion;
    wxCheckBox* m_checkTraininglazyplayer;
    wxCheckBox* m_checkViolator;
    wxCheckBox* m_checkFairplayer;
    wxCheckBox* m_checkMimosa;
    wxCheckBox* m_checkSlyfox;
    wxCheckBox* m_checkSpecialist;
    wxCheckBox* m_checkAllrounder;
    wxCheckBox* m_checkFlexibleplayer;
    wxCheckBox* m_checkRefereefavorite;
    wxCheckBox* m_checkHomeplayer;
    wxCheckBox* m_checkFairweatherplayer;
    wxCheckBox* m_checkJoker;
    wxCheckBox* m_checkEgoist;
    wxCheckBox* m_checkBrotherlightfooted;*/
    wxCheckBox* m_checkLeader;
    wxCheckBox* m_checkHothead;
    wxCheckBox* m_checkHappynature;
    wxCheckBox* m_checkManwithoutnerves;
    wxCheckBox* m_checkBundleofnerves;
    wxCheckBox* m_checkPhlegmatic;
    wxCheckBox* m_checkMoneyvolture;
    wxCheckBox* m_checkClubsupporter;
    wxCheckBox* m_checkProfessionalpattern;
    wxCheckBox* m_checkScandalnoodle;
    wxCheckBox* m_checkSensitive;
    wxCheckBox* m_checkAirsandgraces;
    wxCheckBox* m_checkTeenstar;
    wxCheckBox* m_checkTroublemaker;
    wxCheckBox* m_checkLiverwurst;
    wxCheckBox* m_checkUnifyingfigure;
    wxPanel* m_panelCharacteristics2;
    wxRadioButton* m_radioNormal;
    wxRadioButton* m_radioRobust;
    wxRadioButton* m_radioSusceptible;
    wxRadioButton* m_radioKneeproblems;
    wxRadioButton* m_radioQuicklyfitagain;
    wxRadioButton* m_radioLastsuntilfitagain;
    wxRadioButton* m_radioSnivelling;
    wxRadioButton* m_radioAudiencenormal;
    wxRadioButton* m_radioAudiencefavorite;
    wxRadioButton* m_radioAudiencehatefigure;
    wxStaticText* m_staticText155;
    wxButton* m_buttonOK;
    wxButton* m_buttonAbort;

private:
    void initializePlayerList(wxListCtrl* control);
    void populatePerson();
    void populatePlayer(std::shared_ptr<Core::Player> player);
    void computeAverageSkill();

    void enableGoalkeeperCapabilities();
    void disableGoalkeeperCapabilities();
    void enableFieldPlayerCapabilities();
    void disableFieldPlayerCapabilities();

    Toolset* tools = nullptr;
    std::string m_selectedCountry;
    std::shared_ptr<Core::Country> m_country;
    std::string m_selectedClub;
    std::shared_ptr<Core::Team> m_team;
    std::vector<std::shared_ptr<Core::Player>> m_players;
    std::string m_selectedPerson;
    float m_averageSkill = 0.0f;
};
