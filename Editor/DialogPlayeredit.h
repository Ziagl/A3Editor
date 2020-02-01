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
    DialogPlayeredit(wxWindow* parent, 
        wxWindowID id = wxID_ANY, 
        const wxString& title = _("Playeredit"), 
        const wxPoint& pos = wxDefaultPosition, 
        const wxSize& size = wxSize(1000, 800), 
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogPlayeredit();
protected:
    wxListCtrl* m_listCtrl19;
    wxNotebook* m_notebook21;
    wxPanel* m_panelData1;
    wxStaticText* m_staticText37;
    wxTextCtrl* m_textCtrl39;
    wxStaticText* m_staticText41;
    wxTextCtrl* m_textCtrl43;
    wxStaticText* m_staticText45;
    wxTextCtrl* m_textCtrl47;
    wxStaticText* m_staticText455;
    wxStaticText* m_staticText457;
    wxSpinButton* m_spinButton459;
    wxStaticText* m_staticText461;
    wxSpinButton* m_spinButton463;
    wxStaticText* m_staticText465;
    wxSpinButton* m_spinButton467;
    wxStaticText* m_staticText469;
    wxStaticText* m_staticText473;
    wxSpinButton* m_spinButton471;
    wxStaticText* m_staticText475;
    wxStaticText* m_staticText477;
    wxButton* m_button445;
    wxStaticText* m_staticText425;
    wxStaticText* m_staticText427;
    wxSpinButton* m_spinButton429;
    wxStaticText* m_staticText431;
    wxStaticText* m_staticText433;
    wxSpinButton* m_spinButton435;
    wxStaticText* m_staticText437;
    wxStaticText* m_staticText439;
    wxSpinButton* m_spinButton441;
    wxStaticText* m_staticText55;
    wxStaticText* m_staticText481;
    wxPanel* m_panelData2;
    wxStaticText* m_staticText59;
    wxChoice* m_choice61;
    wxStaticText* m_staticText63;
    wxChoice* m_choice65;
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
    wxCheckBox* m_checkBoxSecondarySweeper;
    wxCheckBox* m_checkBoxSecondaryCenterback;
    wxCheckBox* m_checkSecondaryLeftdefender;
    wxCheckBox* m_checkSecondaryRightdefender;
    wxCheckBox* m_checkSecondaryDefensivemidfielder;
    wxCheckBox* m_checkSecondaryLeftmidfielder;
    wxCheckBox* m_checkSecondaryRightmidfielder;
    wxCheckBox* m_checkSecondaryAttackingmidfielder;
    wxCheckBox* m_checkSecondaryForward;
    wxPanel* m_panelSkills;
    wxStaticText* m_staticText279;
    wxStaticText* m_staticText281;
    wxCheckBox* m_checkPlusHeader;
    wxCheckBox* m_checkMinusHeader;
    wxCheckBox* m_checkPlusDuel;
    wxCheckBox* m_checkMinusDuel;
    wxCheckBox* m_checkPlusSpeed;
    wxCheckBox* m_checkMinusSpeed;
    wxCheckBox* m_checkPlusSurpluspower;
    wxCheckBox* m_checkMinusSurpluspower;
    wxCheckBox* m_checkPlusPenalty;
    wxCheckBox* m_checkMinusPenalty;
    wxCheckBox* m_checkPlusFreekicks;
    wxCheckBox* m_checkMinusFreekicks;
    wxCheckBox* m_checkPlusFlanks;
    wxCheckBox* m_checkMinusFlanks;
    wxCheckBox* m_checkPlusGoalinstincts;
    wxCheckBox* m_checkMinusGoalinstinkts;
    wxCheckBox* m_checkPlusWorkrate;
    wxCheckBox* m_checkMinusWorkrate;
    wxCheckBox* m_checkPlusTechnique;
    wxCheckBox* m_checkMinusTechnique;
    wxCheckBox* m_checkPlusBallmagic;
    wxCheckBox* m_checkMinusBallmagic;
    wxCheckBox* m_checkPlusPlaymaker;
    wxCheckBox* m_checkMinusPlaymaker;
    wxCheckBox* m_checkPlusFoursomechain;
    wxCheckBox* m_checkMinusFoursomechain;
    wxCheckBox* m_checkPlusGamesummary;
    wxCheckBox* m_checkMinusGamesummary;
    wxCheckBox* m_checkPlusHoldball;
    wxCheckBox* m_checkMinusHoldball;
    wxCheckBox* m_checkPlusDribbling;
    wxCheckBox* m_checkMinusDribbling;
    wxStaticText* m_staticText285;
    wxStaticText* m_staticText287;
    wxCheckBox* m_checkPlusPenaltykiller;
    wxCheckBox* m_checkMinusPenaltykiller;
    wxCheckBox* m_checkPlusStrongreflexes;
    wxCheckBox* m_checkMinusStrongreflexes;
    wxCheckBox* m_checkPlusRunningout;
    wxCheckBox* m_checkMinusRunningout;
    wxCheckBox* m_checkPlusFlanksGoalkeeper;
    wxCheckBox* m_checkMinusFlanksGoalkeeper;
    wxCheckBox* m_checkPlusFist;
    wxCheckBox* m_checkMinusFist;
    wxCheckBox* m_checkPlusBallsecurity;
    wxCheckBox* m_checkMinusBallsecurity;
    wxCheckBox* m_checkPlusSpeedGoalkeeper;
    wxCheckBox* m_checkMinusSpeedGoalkeeper;
    wxCheckBox* m_checkPlusLongpunts;
    wxCheckBox* m_checkMinusLongpunts;
    wxCheckBox* m_checkPlusLongdrops;
    wxCheckBox* m_checkMinusLongdrops;
    wxPanel* m_panelCharacteristics1;
    wxCheckBox* m_checkFighter;
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
    wxCheckBox* m_checkBrotherlightfooted;
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
    wxButton* m_button147;
    wxButton* m_button149;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:

public:
    wxListCtrl* GetListCtrl19() { return m_listCtrl19; }
    wxStaticText* GetStaticText37() { return m_staticText37; }
    wxTextCtrl* GetTextCtrl39() { return m_textCtrl39; }
    wxStaticText* GetStaticText41() { return m_staticText41; }
    wxTextCtrl* GetTextCtrl43() { return m_textCtrl43; }
    wxStaticText* GetStaticText45() { return m_staticText45; }
    wxTextCtrl* GetTextCtrl47() { return m_textCtrl47; }
    wxStaticText* GetStaticText455() { return m_staticText455; }
    wxStaticText* GetStaticText457() { return m_staticText457; }
    wxSpinButton* GetSpinButton459() { return m_spinButton459; }
    wxStaticText* GetStaticText461() { return m_staticText461; }
    wxSpinButton* GetSpinButton463() { return m_spinButton463; }
    wxStaticText* GetStaticText465() { return m_staticText465; }
    wxSpinButton* GetSpinButton467() { return m_spinButton467; }
    wxStaticText* GetStaticText469() { return m_staticText469; }
    wxStaticText* GetStaticText473() { return m_staticText473; }
    wxSpinButton* GetSpinButton471() { return m_spinButton471; }
    wxStaticText* GetStaticText475() { return m_staticText475; }
    wxStaticText* GetStaticText477() { return m_staticText477; }
    wxButton* GetButton445() { return m_button445; }
    wxStaticText* GetStaticText425() { return m_staticText425; }
    wxStaticText* GetStaticText427() { return m_staticText427; }
    wxSpinButton* GetSpinButton429() { return m_spinButton429; }
    wxStaticText* GetStaticText431() { return m_staticText431; }
    wxStaticText* GetStaticText433() { return m_staticText433; }
    wxSpinButton* GetSpinButton435() { return m_spinButton435; }
    wxStaticText* GetStaticText437() { return m_staticText437; }
    wxStaticText* GetStaticText439() { return m_staticText439; }
    wxSpinButton* GetSpinButton441() { return m_spinButton441; }
    wxStaticText* GetStaticText55() { return m_staticText55; }
    wxStaticText* GetStaticText481() { return m_staticText481; }
    wxPanel* GetPanelData1() { return m_panelData1; }
    wxStaticText* GetStaticText59() { return m_staticText59; }
    wxChoice* GetChoice61() { return m_choice61; }
    wxStaticText* GetStaticText63() { return m_staticText63; }
    wxChoice* GetChoice65() { return m_choice65; }
    wxCheckBox* GetCheckNational() { return m_checkNational; }
    wxCheckBox* GetCheckNationalplayer() { return m_checkNationalplayer; }
    wxCheckBox* GetCheckNationalresigned() { return m_checkNationalresigned; }
    wxCheckBox* GetCheckCaptainresigned() { return m_checkCaptainresigned; }
    wxRadioButton* GetRadioBright() { return m_radioBright; }
    wxRadioButton* GetRadioDark() { return m_radioDark; }
    wxRadioButton* GetRadioAfrikan() { return m_radioAfrikan; }
    wxRadioButton* GetRadioAsian() { return m_radioAsian; }
    wxRadioButton* GetRadioExtremelyshort() { return m_radioExtremelyshort; }
    wxRadioButton* GetRadioShort() { return m_radioShort; }
    wxRadioButton* GetRadioCurly() { return m_radioCurly; }
    wxRadioButton* GetRadioLong() { return m_radioLong; }
    wxCheckBox* GetCheckUnshaved() { return m_checkUnshaved; }
    wxCheckBox* GetCheckBeard() { return m_checkBeard; }
    wxCheckBox* GetCheckMoustache() { return m_checkMoustache; }
    wxCheckBox* GetCheckGoatee() { return m_checkGoatee; }
    wxRadioButton* GetRadioLightblonde() { return m_radioLightblonde; }
    wxRadioButton* GetRadioRed() { return m_radioRed; }
    wxRadioButton* GetRadioGrey() { return m_radioGrey; }
    wxRadioButton* GetRadioBlond() { return m_radioBlond; }
    wxRadioButton* GetRadioBlack() { return m_radioBlack; }
    wxRadioButton* GetRadioBrown() { return m_radioBrown; }
    wxRadioButton* GetRadioBald() { return m_radioBald; }
    wxPanel* GetPanelData2() { return m_panelData2; }
    wxRadioButton* GetRadioButtonMainGoalkeeper() { return m_radioButtonMainGoalkeeper; }
    wxRadioButton* GetRadioButtonMainSweeper() { return m_radioButtonMainSweeper; }
    wxRadioButton* GetRadioMainCenterback() { return m_radioMainCenterback; }
    wxRadioButton* GetRadioMainLeftdefender() { return m_radioMainLeftdefender; }
    wxRadioButton* GetRadioMainRightdefender() { return m_radioMainRightdefender; }
    wxRadioButton* GetRadioMainDefensivemidfielder() { return m_radioMainDefensivemidfielder; }
    wxRadioButton* GetRadioMainLeftmidfielder() { return m_radioMainLeftmidfielder; }
    wxRadioButton* GetRadioMainRightmidfielder() { return m_radioMainRightmidfielder; }
    wxRadioButton* GetRadioMainAttackingmidfielder() { return m_radioMainAttackingmidfielder; }
    wxRadioButton* GetRadioMainForward() { return m_radioMainForward; }
    wxCheckBox* GetCheckBoxSecondarySweeper() { return m_checkBoxSecondarySweeper; }
    wxCheckBox* GetCheckBoxSecondaryCenterback() { return m_checkBoxSecondaryCenterback; }
    wxCheckBox* GetCheckSecondaryLeftdefender() { return m_checkSecondaryLeftdefender; }
    wxCheckBox* GetCheckSecondaryRightdefender() { return m_checkSecondaryRightdefender; }
    wxCheckBox* GetCheckSecondaryDefensivemidfielder() { return m_checkSecondaryDefensivemidfielder; }
    wxCheckBox* GetCheckSecondaryLeftmidfielder() { return m_checkSecondaryLeftmidfielder; }
    wxCheckBox* GetCheckSecondaryRightmidfielder() { return m_checkSecondaryRightmidfielder; }
    wxCheckBox* GetCheckSecondaryAttackingmidfielder() { return m_checkSecondaryAttackingmidfielder; }
    wxCheckBox* GetCheckSecondaryForward() { return m_checkSecondaryForward; }
    wxPanel* GetPanelPositions() { return m_panelPositions; }
    wxStaticText* GetStaticText279() { return m_staticText279; }
    wxStaticText* GetStaticText281() { return m_staticText281; }
    wxCheckBox* GetCheckPlusHeader() { return m_checkPlusHeader; }
    wxCheckBox* GetCheckMinusHeader() { return m_checkMinusHeader; }
    wxCheckBox* GetCheckPlusDuel() { return m_checkPlusDuel; }
    wxCheckBox* GetCheckMinusDuel() { return m_checkMinusDuel; }
    wxCheckBox* GetCheckPlusSpeed() { return m_checkPlusSpeed; }
    wxCheckBox* GetCheckMinusSpeed() { return m_checkMinusSpeed; }
    wxCheckBox* GetCheckPlusSurpluspower() { return m_checkPlusSurpluspower; }
    wxCheckBox* GetCheckMinusSurpluspower() { return m_checkMinusSurpluspower; }
    wxCheckBox* GetCheckPlusPenalty() { return m_checkPlusPenalty; }
    wxCheckBox* GetCheckMinusPenalty() { return m_checkMinusPenalty; }
    wxCheckBox* GetCheckPlusFreekicks() { return m_checkPlusFreekicks; }
    wxCheckBox* GetCheckMinusFreekicks() { return m_checkMinusFreekicks; }
    wxCheckBox* GetCheckPlusFlanks() { return m_checkPlusFlanks; }
    wxCheckBox* GetCheckMinusFlanks() { return m_checkMinusFlanks; }
    wxCheckBox* GetCheckPlusGoalinstincts() { return m_checkPlusGoalinstincts; }
    wxCheckBox* GetCheckMinusGoalinstinkts() { return m_checkMinusGoalinstinkts; }
    wxCheckBox* GetCheckPlusWorkrate() { return m_checkPlusWorkrate; }
    wxCheckBox* GetCheckMinusWorkrate() { return m_checkMinusWorkrate; }
    wxCheckBox* GetCheckPlusTechnique() { return m_checkPlusTechnique; }
    wxCheckBox* GetCheckMinusTechnique() { return m_checkMinusTechnique; }
    wxCheckBox* GetCheckPlusBallmagic() { return m_checkPlusBallmagic; }
    wxCheckBox* GetCheckMinusBallmagic() { return m_checkMinusBallmagic; }
    wxCheckBox* GetCheckPlusPlaymaker() { return m_checkPlusPlaymaker; }
    wxCheckBox* GetCheckMinusPlaymaker() { return m_checkMinusPlaymaker; }
    wxCheckBox* GetCheckPlusFoursomechain() { return m_checkPlusFoursomechain; }
    wxCheckBox* GetCheckMinusFoursomechain() { return m_checkMinusFoursomechain; }
    wxCheckBox* GetCheckPlusGamesummary() { return m_checkPlusGamesummary; }
    wxCheckBox* GetCheckMinusGamesummary() { return m_checkMinusGamesummary; }
    wxCheckBox* GetCheckPlusHoldball() { return m_checkPlusHoldball; }
    wxCheckBox* GetCheckMinusHoldball() { return m_checkMinusHoldball; }
    wxCheckBox* GetCheckPlusDribbling() { return m_checkPlusDribbling; }
    wxCheckBox* GetCheckMinusDribbling() { return m_checkMinusDribbling; }
    wxStaticText* GetStaticText285() { return m_staticText285; }
    wxStaticText* GetStaticText287() { return m_staticText287; }
    wxCheckBox* GetCheckPlusPenaltykiller() { return m_checkPlusPenaltykiller; }
    wxCheckBox* GetCheckMinusPenaltykiller() { return m_checkMinusPenaltykiller; }
    wxCheckBox* GetCheckPlusStrongreflexes() { return m_checkPlusStrongreflexes; }
    wxCheckBox* GetCheckMinusStrongreflexes() { return m_checkMinusStrongreflexes; }
    wxCheckBox* GetCheckPlusRunningout() { return m_checkPlusRunningout; }
    wxCheckBox* GetCheckMinusRunningout() { return m_checkMinusRunningout; }
    wxCheckBox* GetCheckPlusFlanksGoalkeeper() { return m_checkPlusFlanksGoalkeeper; }
    wxCheckBox* GetCheckMinusFlanksGoalkeeper() { return m_checkMinusFlanksGoalkeeper; }
    wxCheckBox* GetCheckPlusFist() { return m_checkPlusFist; }
    wxCheckBox* GetCheckMinusFist() { return m_checkMinusFist; }
    wxCheckBox* GetCheckPlusBallsecurity() { return m_checkPlusBallsecurity; }
    wxCheckBox* GetCheckMinusBallsecurity() { return m_checkMinusBallsecurity; }
    wxCheckBox* GetCheckPlusSpeedGoalkeeper() { return m_checkPlusSpeedGoalkeeper; }
    wxCheckBox* GetCheckMinusSpeedGoalkeeper() { return m_checkMinusSpeedGoalkeeper; }
    wxCheckBox* GetCheckPlusLongpunts() { return m_checkPlusLongpunts; }
    wxCheckBox* GetCheckMinusLongpunts() { return m_checkMinusLongpunts; }
    wxCheckBox* GetCheckPlusLongdrops() { return m_checkPlusLongdrops; }
    wxCheckBox* GetCheckMinusLongdrops() { return m_checkMinusLongdrops; }
    wxPanel* GetPanelSkills() { return m_panelSkills; }
    wxCheckBox* GetCheckFighter() { return m_checkFighter; }
    wxCheckBox* GetCheckTrainingworldchampion() { return m_checkTrainingworldchampion; }
    wxCheckBox* GetCheckTraininglazyplayer() { return m_checkTraininglazyplayer; }
    wxCheckBox* GetCheckViolator() { return m_checkViolator; }
    wxCheckBox* GetCheckFairplayer() { return m_checkFairplayer; }
    wxCheckBox* GetCheckMimosa() { return m_checkMimosa; }
    wxCheckBox* GetCheckSlyfox() { return m_checkSlyfox; }
    wxCheckBox* GetCheckSpecialist() { return m_checkSpecialist; }
    wxCheckBox* GetCheckAllrounder() { return m_checkAllrounder; }
    wxCheckBox* GetCheckFlexibleplayer() { return m_checkFlexibleplayer; }
    wxCheckBox* GetCheckRefereefavorite() { return m_checkRefereefavorite; }
    wxCheckBox* GetCheckHomeplayer() { return m_checkHomeplayer; }
    wxCheckBox* GetCheckFairweatherplayer() { return m_checkFairweatherplayer; }
    wxCheckBox* GetCheckJoker() { return m_checkJoker; }
    wxCheckBox* GetCheckEgoist() { return m_checkEgoist; }
    wxCheckBox* GetCheckBrotherlightfooted() { return m_checkBrotherlightfooted; }
    wxCheckBox* GetCheckLeader() { return m_checkLeader; }
    wxCheckBox* GetCheckHothead() { return m_checkHothead; }
    wxCheckBox* GetCheckHappynature() { return m_checkHappynature; }
    wxCheckBox* GetCheckManwithoutnerves() { return m_checkManwithoutnerves; }
    wxCheckBox* GetCheckBundleofnerves() { return m_checkBundleofnerves; }
    wxCheckBox* GetCheckPhlegmatic() { return m_checkPhlegmatic; }
    wxCheckBox* GetCheckMoneyvolture() { return m_checkMoneyvolture; }
    wxCheckBox* GetCheckClubsupporter() { return m_checkClubsupporter; }
    wxCheckBox* GetCheckProfessionalpattern() { return m_checkProfessionalpattern; }
    wxCheckBox* GetCheckScandalnoodle() { return m_checkScandalnoodle; }
    wxCheckBox* GetCheckSensitive() { return m_checkSensitive; }
    wxCheckBox* GetCheckAirsandgraces() { return m_checkAirsandgraces; }
    wxCheckBox* GetCheckTeenstar() { return m_checkTeenstar; }
    wxCheckBox* GetCheckTroublemaker() { return m_checkTroublemaker; }
    wxCheckBox* GetCheckLiverwurst() { return m_checkLiverwurst; }
    wxCheckBox* GetCheckUnifyingfigure() { return m_checkUnifyingfigure; }
    wxPanel* GetPanelCharacteristics1() { return m_panelCharacteristics1; }
    wxRadioButton* GetRadioNormal() { return m_radioNormal; }
    wxRadioButton* GetRadioRobust() { return m_radioRobust; }
    wxRadioButton* GetRadioSusceptible() { return m_radioSusceptible; }
    wxRadioButton* GetRadioKneeproblems() { return m_radioKneeproblems; }
    wxRadioButton* GetRadioQuicklyfitagain() { return m_radioQuicklyfitagain; }
    wxRadioButton* GetRadioLastsuntilfitagain() { return m_radioLastsuntilfitagain; }
    wxRadioButton* GetRadioSnivelling() { return m_radioSnivelling; }
    wxRadioButton* GetRadioAudiencenormal() { return m_radioAudiencenormal; }
    wxRadioButton* GetRadioAudiencefavorite() { return m_radioAudiencefavorite; }
    wxRadioButton* GetRadioAudiencehatefigure() { return m_radioAudiencehatefigure; }
    wxPanel* GetPanelCharacteristics2() { return m_panelCharacteristics2; }
    wxNotebook* GetNotebook21() { return m_notebook21; }
    wxStaticText* GetStaticText155() { return m_staticText155; }
    wxButton* GetButton147() { return m_button147; }
    wxButton* GetButton149() { return m_button149; }
    wxButton* GetButtonOK() { return m_buttonOK; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
};

