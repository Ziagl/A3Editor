#pragma once

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/spinbutt.h>
#include <wx/combobox.h>
#include <wx/button.h>

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DialogStadion : public wxDialog
{
public:
    DialogStadion(wxWindow* parent, 
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Stadion"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(630, 450),
        long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DialogStadion();

protected:
    wxStaticText* m_staticText51;
    wxTextCtrl* m_textCtrl49;
    wxStaticText* m_staticText53;
    wxTextCtrl* m_textCtrl55;
    wxStaticText* m_staticText57;
    wxChoice* m_choice59;
    wxCheckBox* m_checkBox63;
    wxCheckBox* m_checkBox65;
    wxCheckBox* m_checkBox67;
    wxCheckBox* m_checkBox69;
    wxCheckBox* m_checkBox71;
    wxCheckBox* m_checkBox73;
    wxCheckBox* m_checkBox75;
    wxStaticText* m_staticText87;
    wxStaticText* m_staticText89;
    wxStaticText* m_staticText91;
    wxStaticText* m_staticText93;
    wxStaticText* m_staticText95;
    wxStaticText* m_staticText97;
    wxStaticText* m_staticText99;
    wxStaticText* m_staticText101;
    wxStaticText* m_staticText103;
    wxStaticText* m_staticText105;
    wxStaticText* m_staticText107;
    wxStaticText* m_staticText109;
    wxStaticText* m_staticText115;
    wxStaticText* m_staticText117;
    wxStaticText* m_staticText119;
    wxStaticText* m_staticText121;
    wxStaticText* m_staticText123;
    wxStaticText* m_staticText125;
    wxStaticText* m_staticText129;
    wxSpinCtrl* m_spinCtrl137;
    wxSpinCtrl* m_spinCtrl139;
    wxSpinCtrl* m_spinCtrl141;
    wxCheckBox* m_checkBox143;
    wxCheckBox* m_checkBox145;
    wxStaticText* m_staticText147;
    wxSpinButton* m_spinButton149;
    wxStaticText* m_staticText151;
    wxSpinCtrl* m_spinCtrl153;
    wxSpinCtrl* m_spinCtrl155;
    wxSpinCtrl* m_spinCtrl157;
    wxCheckBox* m_checkBox159;
    wxCheckBox* m_checkBox161;
    wxStaticText* m_staticText163;
    wxSpinButton* m_spinButton165;
    wxStaticText* m_staticText167;
    wxSpinCtrl* m_spinCtrl169;
    wxSpinCtrl* m_spinCtrl171;
    wxSpinCtrl* m_spinCtrl173;
    wxCheckBox* m_checkBox175;
    wxCheckBox* m_checkBox177;
    wxStaticText* m_staticText179;
    wxSpinButton* m_spinButton181;
    wxStaticText* m_staticText183;
    wxSpinCtrl* m_spinCtrl185;
    wxSpinCtrl* m_spinCtrl187;
    wxSpinCtrl* m_spinCtrl189;
    wxCheckBox* m_checkBox191;
    wxCheckBox* m_checkBox193;
    wxStaticText* m_staticText195;
    wxSpinButton* m_spinButton201;
    wxStaticText* m_staticText205;
    wxComboBox* m_comboBox207;
    wxStaticText* m_staticText209;
    wxComboBox* m_comboBox211;
    wxCheckBox* m_checkBox215;
    wxCheckBox* m_checkBox217;
    wxCheckBox* m_checkBox219;
    wxCheckBox* m_checkBox221;
    wxCheckBox* m_checkBox223;
    wxCheckBox* m_checkBox227;
    wxCheckBox* m_checkBox229;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:

public:
    wxStaticText* GetStaticText51() { return m_staticText51; }
    wxTextCtrl* GetTextCtrl49() { return m_textCtrl49; }
    wxStaticText* GetStaticText53() { return m_staticText53; }
    wxTextCtrl* GetTextCtrl55() { return m_textCtrl55; }
    wxStaticText* GetStaticText57() { return m_staticText57; }
    wxChoice* GetChoice59() { return m_choice59; }
    wxCheckBox* GetCheckBox63() { return m_checkBox63; }
    wxCheckBox* GetCheckBox65() { return m_checkBox65; }
    wxCheckBox* GetCheckBox67() { return m_checkBox67; }
    wxCheckBox* GetCheckBox69() { return m_checkBox69; }
    wxCheckBox* GetCheckBox71() { return m_checkBox71; }
    wxCheckBox* GetCheckBox73() { return m_checkBox73; }
    wxCheckBox* GetCheckBox75() { return m_checkBox75; }
    wxStaticText* GetStaticText87() { return m_staticText87; }
    wxStaticText* GetStaticText89() { return m_staticText89; }
    wxStaticText* GetStaticText91() { return m_staticText91; }
    wxStaticText* GetStaticText93() { return m_staticText93; }
    wxStaticText* GetStaticText95() { return m_staticText95; }
    wxStaticText* GetStaticText97() { return m_staticText97; }
    wxStaticText* GetStaticText99() { return m_staticText99; }
    wxStaticText* GetStaticText101() { return m_staticText101; }
    wxStaticText* GetStaticText103() { return m_staticText103; }
    wxStaticText* GetStaticText105() { return m_staticText105; }
    wxStaticText* GetStaticText107() { return m_staticText107; }
    wxStaticText* GetStaticText109() { return m_staticText109; }
    wxStaticText* GetStaticText115() { return m_staticText115; }
    wxStaticText* GetStaticText117() { return m_staticText117; }
    wxStaticText* GetStaticText119() { return m_staticText119; }
    wxStaticText* GetStaticText121() { return m_staticText121; }
    wxStaticText* GetStaticText123() { return m_staticText123; }
    wxStaticText* GetStaticText125() { return m_staticText125; }
    wxStaticText* GetStaticText129() { return m_staticText129; }
    wxSpinCtrl* GetSpinCtrl137() { return m_spinCtrl137; }
    wxSpinCtrl* GetSpinCtrl139() { return m_spinCtrl139; }
    wxSpinCtrl* GetSpinCtrl141() { return m_spinCtrl141; }
    wxCheckBox* GetCheckBox143() { return m_checkBox143; }
    wxCheckBox* GetCheckBox145() { return m_checkBox145; }
    wxStaticText* GetStaticText147() { return m_staticText147; }
    wxSpinButton* GetSpinButton149() { return m_spinButton149; }
    wxStaticText* GetStaticText151() { return m_staticText151; }
    wxSpinCtrl* GetSpinCtrl153() { return m_spinCtrl153; }
    wxSpinCtrl* GetSpinCtrl155() { return m_spinCtrl155; }
    wxSpinCtrl* GetSpinCtrl157() { return m_spinCtrl157; }
    wxCheckBox* GetCheckBox159() { return m_checkBox159; }
    wxCheckBox* GetCheckBox161() { return m_checkBox161; }
    wxStaticText* GetStaticText163() { return m_staticText163; }
    wxSpinButton* GetSpinButton165() { return m_spinButton165; }
    wxStaticText* GetStaticText167() { return m_staticText167; }
    wxSpinCtrl* GetSpinCtrl169() { return m_spinCtrl169; }
    wxSpinCtrl* GetSpinCtrl171() { return m_spinCtrl171; }
    wxSpinCtrl* GetSpinCtrl173() { return m_spinCtrl173; }
    wxCheckBox* GetCheckBox175() { return m_checkBox175; }
    wxCheckBox* GetCheckBox177() { return m_checkBox177; }
    wxStaticText* GetStaticText179() { return m_staticText179; }
    wxSpinButton* GetSpinButton181() { return m_spinButton181; }
    wxStaticText* GetStaticText183() { return m_staticText183; }
    wxSpinCtrl* GetSpinCtrl185() { return m_spinCtrl185; }
    wxSpinCtrl* GetSpinCtrl187() { return m_spinCtrl187; }
    wxSpinCtrl* GetSpinCtrl189() { return m_spinCtrl189; }
    wxCheckBox* GetCheckBox191() { return m_checkBox191; }
    wxCheckBox* GetCheckBox193() { return m_checkBox193; }
    wxStaticText* GetStaticText195() { return m_staticText195; }
    wxSpinButton* GetSpinButton201() { return m_spinButton201; }
    wxStaticText* GetStaticText205() { return m_staticText205; }
    wxComboBox* GetComboBox207() { return m_comboBox207; }
    wxStaticText* GetStaticText209() { return m_staticText209; }
    wxComboBox* GetComboBox211() { return m_comboBox211; }
    wxCheckBox* GetCheckBox215() { return m_checkBox215; }
    wxCheckBox* GetCheckBox217() { return m_checkBox217; }
    wxCheckBox* GetCheckBox219() { return m_checkBox219; }
    wxCheckBox* GetCheckBox221() { return m_checkBox221; }
    wxCheckBox* GetCheckBox223() { return m_checkBox223; }
    wxCheckBox* GetCheckBox227() { return m_checkBox227; }
    wxCheckBox* GetCheckBox229() { return m_checkBox229; }
    wxButton* GetButtonOK() { return m_buttonOK; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
};
