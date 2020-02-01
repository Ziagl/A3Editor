#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/spinbutt.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/statbmp.h>
#include <wx/tglbtn.h>
#include <wx/radiobut.h>

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogClubedit: public wxDialog
{
public:
    DialogClubedit(wxWindow* parent, 
        wxWindowID id = wxID_ANY, 
        const wxString& title = _("Clubedit"), 
        const wxPoint& pos = wxDefaultPosition, 
        const wxSize& size = wxSize(1000, 800), 
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogClubedit();

protected:
    wxNotebook* m_notebook25;
    wxPanel* m_panelClub;
    wxStaticText* m_staticClubName;
    wxTextCtrl* m_textClubName;
    wxButton* m_buttonClubname1;
    wxButton* m_buttonClubname2;
    wxStaticText* m_staticFanCaption;
    wxTextCtrl* m_textFanCaption;
    wxStaticText* m_staticText63;
    wxStaticText* m_staticText65;
    wxSpinButton* m_spinButton67;
    wxStaticText* m_staticText69;
    wxStaticText* m_staticText71;
    wxSpinButton* m_spinButton73;
    wxStaticText* m_staticText75;
    wxStaticText* m_staticText77;
    wxSpinButton* m_spinButton79;
    wxStaticText* m_staticText81;
    wxStaticText* m_staticText83;
    wxSpinButton* m_spinButton85;
    wxPanel* m_panelGeneral;
    wxPanel* m_panel89;
    wxStaticText* m_staticText149;
    wxButton* m_button151;
    wxTextCtrl* m_textCtrl153;
    wxStaticText* m_staticText157;
    wxStaticText* m_staticText159;
    wxSpinButton* m_spinButton161;
    wxCheckBox* m_checkBox139;
    wxCheckBox* m_checkBox141;
    wxCheckBox* m_checkBox143;
    wxStaticText* m_staticText173;
    wxChoice* m_choice175;
    wxStaticText* m_staticText177;
    wxChoice* m_choice179;
    wxStaticText* m_staticText181;
    wxChoice* m_choice183;
    wxStaticText* m_staticText185;
    wxChoice* m_choice187;
    wxStaticText* m_staticText193;
    wxStaticText* m_staticText195;
    wxStaticText* m_staticText199;
    wxStaticText* m_staticText201;
    wxSpinButton* m_spinButton203;
    wxStaticText* m_staticText205;
    wxStaticText* m_staticText207;
    wxSpinButton* m_spinButton209;
    wxStaticText* m_staticText211;
    wxStaticText* m_staticText213;
    wxSpinButton* m_spinButton215;
    wxStaticText* m_staticText217;
    wxStaticText* m_staticText219;
    wxSpinButton* m_spinButton221;
    wxStaticText* m_staticText223;
    wxStaticText* m_staticText225;
    wxSpinButton* m_spinButton227;
    wxStaticText* m_staticText229;
    wxStaticText* m_staticText231;
    wxSpinButton* m_spinButton233;
    wxStaticText* m_staticText95;
    wxStaticText* m_staticText97;
    wxSpinButton* m_spinButton99;
    wxStaticText* m_staticText101;
    wxStaticText* m_staticText103;
    wxSpinButton* m_spinButton105;
    wxStaticText* m_staticText107;
    wxStaticText* m_staticText109;
    wxSpinButton* m_spinButton111;
    wxStaticText* m_staticText113;
    wxStaticText* m_staticText115;
    wxSpinButton* m_spinButton117;
    wxStaticText* m_staticText119;
    wxStaticText* m_staticText121;
    wxSpinButton* m_spinButton123;
    wxStaticText* m_staticText125;
    wxStaticText* m_staticText127;
    wxSpinButton* m_spinButton129;
    wxPanel* m_panelJersey;
    wxStaticBitmap* m_staticBitmap303;
    wxToggleButton* m_toggleButton299;
    wxToggleButton* m_toggleButton301;
    wxStaticText* m_staticText279;
    wxChoice* m_choice287;
    wxStaticText* m_staticText283;
    wxChoice* m_choice285;
    wxStaticText* m_staticText289;
    wxChoice* m_choice291;
    wxStaticText* m_staticText293;
    wxChoice* m_choice295;
    wxRadioButton* m_radioButton259;
    wxRadioButton* m_radioButton261;
    wxRadioButton* m_radioButton263;
    wxRadioButton* m_radioButton265;
    wxRadioButton* m_radioButton267;
    wxRadioButton* m_radioButton269;
    wxRadioButton* m_radioButton271;
    wxRadioButton* m_radioButton273;
    wxRadioButton* m_radioButton275;
    wxRadioButton* m_radioButton277;
    wxCheckBox* m_checkBox257;
    wxPanel* m_panelIcon;
    wxPanel* m_panelMap;
    wxPanel* m_panelChairman;
    wxStaticText* m_staticText315;
    wxTextCtrl* m_textCtrl317;
    wxStaticText* m_staticText319;
    wxTextCtrl* m_textCtrl321;
    wxStaticText* m_staticText323;
    wxStaticText* m_staticText327;
    wxSpinButton* m_spinButton329;
    wxStaticText* m_staticText331;
    wxSpinButton* m_spinButton333;
    wxStaticText* m_staticText335;
    wxSpinButton* m_spinButton337;
    wxStaticText* m_staticText339;
    wxStaticText* m_staticText343;
    wxSpinButton* m_spinButton345;
    wxStaticText* m_staticText347;
    wxStaticText* m_staticText351;
    wxSpinButton* m_spinButton353;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;
    wxButton* m_buttonClubSave;
    wxButton* m_buttonClubLoad;
    wxButton* m_buttonStadion;

protected:

public:
    wxStaticText* GetStaticClubName() { return m_staticClubName; }
    wxTextCtrl* GetTextClubName() { return m_textClubName; }
    wxButton* GetButtonClubname1() { return m_buttonClubname1; }
    wxButton* GetButtonClubname2() { return m_buttonClubname2; }
    wxStaticText* GetStaticFanCaption() { return m_staticFanCaption; }
    wxTextCtrl* GetTextFanCaption() { return m_textFanCaption; }
    wxStaticText* GetStaticText63() { return m_staticText63; }
    wxStaticText* GetStaticText65() { return m_staticText65; }
    wxSpinButton* GetSpinButton67() { return m_spinButton67; }
    wxStaticText* GetStaticText69() { return m_staticText69; }
    wxStaticText* GetStaticText71() { return m_staticText71; }
    wxSpinButton* GetSpinButton73() { return m_spinButton73; }
    wxStaticText* GetStaticText75() { return m_staticText75; }
    wxStaticText* GetStaticText77() { return m_staticText77; }
    wxSpinButton* GetSpinButton79() { return m_spinButton79; }
    wxStaticText* GetStaticText81() { return m_staticText81; }
    wxStaticText* GetStaticText83() { return m_staticText83; }
    wxSpinButton* GetSpinButton85() { return m_spinButton85; }
    wxPanel* GetPanelClub() { return m_panelClub; }
    wxStaticText* GetStaticText149() { return m_staticText149; }
    wxButton* GetButton151() { return m_button151; }
    wxTextCtrl* GetTextCtrl153() { return m_textCtrl153; }
    wxStaticText* GetStaticText157() { return m_staticText157; }
    wxStaticText* GetStaticText159() { return m_staticText159; }
    wxSpinButton* GetSpinButton161() { return m_spinButton161; }
    wxCheckBox* GetCheckBox139() { return m_checkBox139; }
    wxCheckBox* GetCheckBox141() { return m_checkBox141; }
    wxCheckBox* GetCheckBox143() { return m_checkBox143; }
    wxStaticText* GetStaticText173() { return m_staticText173; }
    wxChoice* GetChoice175() { return m_choice175; }
    wxStaticText* GetStaticText177() { return m_staticText177; }
    wxChoice* GetChoice179() { return m_choice179; }
    wxStaticText* GetStaticText181() { return m_staticText181; }
    wxChoice* GetChoice183() { return m_choice183; }
    wxStaticText* GetStaticText185() { return m_staticText185; }
    wxChoice* GetChoice187() { return m_choice187; }
    wxStaticText* GetStaticText193() { return m_staticText193; }
    wxStaticText* GetStaticText195() { return m_staticText195; }
    wxStaticText* GetStaticText199() { return m_staticText199; }
    wxStaticText* GetStaticText201() { return m_staticText201; }
    wxSpinButton* GetSpinButton203() { return m_spinButton203; }
    wxStaticText* GetStaticText205() { return m_staticText205; }
    wxStaticText* GetStaticText207() { return m_staticText207; }
    wxSpinButton* GetSpinButton209() { return m_spinButton209; }
    wxStaticText* GetStaticText211() { return m_staticText211; }
    wxStaticText* GetStaticText213() { return m_staticText213; }
    wxSpinButton* GetSpinButton215() { return m_spinButton215; }
    wxStaticText* GetStaticText217() { return m_staticText217; }
    wxStaticText* GetStaticText219() { return m_staticText219; }
    wxSpinButton* GetSpinButton221() { return m_spinButton221; }
    wxStaticText* GetStaticText223() { return m_staticText223; }
    wxStaticText* GetStaticText225() { return m_staticText225; }
    wxSpinButton* GetSpinButton227() { return m_spinButton227; }
    wxStaticText* GetStaticText229() { return m_staticText229; }
    wxStaticText* GetStaticText231() { return m_staticText231; }
    wxSpinButton* GetSpinButton233() { return m_spinButton233; }
    wxPanel* GetPanel89() { return m_panel89; }
    wxStaticText* GetStaticText95() { return m_staticText95; }
    wxStaticText* GetStaticText97() { return m_staticText97; }
    wxSpinButton* GetSpinButton99() { return m_spinButton99; }
    wxStaticText* GetStaticText101() { return m_staticText101; }
    wxStaticText* GetStaticText103() { return m_staticText103; }
    wxSpinButton* GetSpinButton105() { return m_spinButton105; }
    wxStaticText* GetStaticText107() { return m_staticText107; }
    wxStaticText* GetStaticText109() { return m_staticText109; }
    wxSpinButton* GetSpinButton111() { return m_spinButton111; }
    wxStaticText* GetStaticText113() { return m_staticText113; }
    wxStaticText* GetStaticText115() { return m_staticText115; }
    wxSpinButton* GetSpinButton117() { return m_spinButton117; }
    wxStaticText* GetStaticText119() { return m_staticText119; }
    wxStaticText* GetStaticText121() { return m_staticText121; }
    wxSpinButton* GetSpinButton123() { return m_spinButton123; }
    wxStaticText* GetStaticText125() { return m_staticText125; }
    wxStaticText* GetStaticText127() { return m_staticText127; }
    wxSpinButton* GetSpinButton129() { return m_spinButton129; }
    wxPanel* GetPanelGeneral() { return m_panelGeneral; }
    wxStaticBitmap* GetStaticBitmap303() { return m_staticBitmap303; }
    wxToggleButton* GetToggleButton299() { return m_toggleButton299; }
    wxToggleButton* GetToggleButton301() { return m_toggleButton301; }
    wxStaticText* GetStaticText279() { return m_staticText279; }
    wxChoice* GetChoice287() { return m_choice287; }
    wxStaticText* GetStaticText283() { return m_staticText283; }
    wxChoice* GetChoice285() { return m_choice285; }
    wxStaticText* GetStaticText289() { return m_staticText289; }
    wxChoice* GetChoice291() { return m_choice291; }
    wxStaticText* GetStaticText293() { return m_staticText293; }
    wxChoice* GetChoice295() { return m_choice295; }
    wxRadioButton* GetRadioButton259() { return m_radioButton259; }
    wxRadioButton* GetRadioButton261() { return m_radioButton261; }
    wxRadioButton* GetRadioButton263() { return m_radioButton263; }
    wxRadioButton* GetRadioButton265() { return m_radioButton265; }
    wxRadioButton* GetRadioButton267() { return m_radioButton267; }
    wxRadioButton* GetRadioButton269() { return m_radioButton269; }
    wxRadioButton* GetRadioButton271() { return m_radioButton271; }
    wxRadioButton* GetRadioButton273() { return m_radioButton273; }
    wxRadioButton* GetRadioButton275() { return m_radioButton275; }
    wxRadioButton* GetRadioButton277() { return m_radioButton277; }
    wxCheckBox* GetCheckBox257() { return m_checkBox257; }
    wxPanel* GetPanelJersey() { return m_panelJersey; }
    wxPanel* GetPanelIcon() { return m_panelIcon; }
    wxPanel* GetPanelMap() { return m_panelMap; }
    wxStaticText* GetStaticText315() { return m_staticText315; }
    wxTextCtrl* GetTextCtrl317() { return m_textCtrl317; }
    wxStaticText* GetStaticText319() { return m_staticText319; }
    wxTextCtrl* GetTextCtrl321() { return m_textCtrl321; }
    wxStaticText* GetStaticText323() { return m_staticText323; }
    wxStaticText* GetStaticText327() { return m_staticText327; }
    wxSpinButton* GetSpinButton329() { return m_spinButton329; }
    wxStaticText* GetStaticText331() { return m_staticText331; }
    wxSpinButton* GetSpinButton333() { return m_spinButton333; }
    wxStaticText* GetStaticText335() { return m_staticText335; }
    wxSpinButton* GetSpinButton337() { return m_spinButton337; }
    wxStaticText* GetStaticText339() { return m_staticText339; }
    wxStaticText* GetStaticText343() { return m_staticText343; }
    wxSpinButton* GetSpinButton345() { return m_spinButton345; }
    wxStaticText* GetStaticText347() { return m_staticText347; }
    wxStaticText* GetStaticText351() { return m_staticText351; }
    wxSpinButton* GetSpinButton353() { return m_spinButton353; }
    wxPanel* GetPanelChairman() { return m_panelChairman; }
    wxNotebook* GetNotebook25() { return m_notebook25; }
    wxButton* GetButtonOK() { return m_buttonOK; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
    wxButton* GetButtonClubSave() { return m_buttonClubSave; }
    wxButton* GetButtonClubLoad() { return m_buttonClubLoad; }
    wxButton* GetButtonStadion() { return m_buttonStadion; }
};

