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

#include "Toolset.h"

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
        Toolset* const tools,
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

    private:
        Toolset* tools = nullptr;
};

