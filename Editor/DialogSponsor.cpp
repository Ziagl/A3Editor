#include "DialogSponsor.h"

DialogSponsor::DialogSponsor(wxWindow* parent, 
    Toolset* const tools,
    const std::string selectedCountry,
    wxWindowID id, 
    const wxString& title, 
    const wxPoint& pos, 
    const wxSize& size, 
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), parent(parent), m_selectedCountry(selectedCountry)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    m_country = tools->getCountryById(countryId);
    m_sponsors = m_country->getSponsors();
    m_imageStartIndex = tools->getSponsorImageStartIndex(m_selectedCountry);    // get starting index of images for this country

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxFlexGridSizer* flexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer17->SetFlexibleDirection(wxBOTH);
    flexGridSizer17->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    mainSizer->Add(flexGridSizer17, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listCtrlSponsors = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL);
    initializeSponsorsList(m_listCtrlSponsors);

    flexGridSizer17->Add(m_listCtrlSponsors, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer21 = new wxFlexGridSizer(0, 1, 0, 0);
    flexGridSizer21->SetFlexibleDirection(wxBOTH);
    flexGridSizer21->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer17->Add(flexGridSizer21, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlText->SetHint(wxT(""));
#endif

    flexGridSizer21->Add(m_textCtrlText, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer25 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer25, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    m_buttonFont = new wxButton(this, wxID_ANY, tools->translate("font"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer25->Add(m_buttonFont, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlFont = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlFont->Enable(false);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFont->SetHint(wxT(""));
#endif

    boxSizer25->Add(m_textCtrlFont, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer31 = new wxFlexGridSizer(2, 8, 0, 0);
    flexGridSizer31->SetFlexibleDirection(wxBOTH);
    flexGridSizer31->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    flexGridSizer21->Add(flexGridSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    for (int i = 0; i < 16; ++i)
    {
        wxButton* button = new wxButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBU_EXACTFIT | wxBORDER_NONE);
#if wxVERSION_NUMBER >= 2904
        wxBitmap image;
        std::string filename = "color"; 
        if (i + 1 < 10)
            filename = filename + "0";
        filename = filename + std::to_string(i + 1) + ".bmp";
        image.LoadFile(tools->getImagePath() + filename, wxBITMAP_TYPE_BMP);
        button->SetBitmap(image);
#endif
        m_button.push_back(button);
        
        flexGridSizer31->Add(button, 0, wxALL, WXC_FROM_DIP(0));
    }

    wxBitmap image;
    m_staticBitmapSponsor = new wxStaticBitmap(this, wxID_ANY, image, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticBitmapSponsor, 0, wxALL, WXC_FROM_DIP(5));

    m_staticText67 = new wxStaticText(this, wxID_ANY, tools->translate("companySize"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer21->Add(m_staticText67, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer69 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer69, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextSize = new wxStaticText(this, wxID_ANY, tools->translate("size0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer69->Add(m_staticTextSize, 0, wxALL, WXC_FROM_DIP(5));

    m_spinButtonSize = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(15, 15)), wxSP_VERTICAL);
    m_spinButtonSize->SetRange(0, 2);
    m_spinButtonSize->SetValue(0);

    boxSizer69->Add(m_spinButtonSize, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer75 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer21->Add(boxSizer75, 1, wxALL | wxEXPAND | wxALIGN_RIGHT, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_ANY | wxEXPAND, tools->translate("buttonOk"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer75->Add(m_buttonOK, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY | wxEXPAND, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer75->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    }
    else {
        CentreOnScreen(wxBOTH);
    }
/*#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    }
    else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif*/

    // connect events
    // button events
    this->Connect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnOk), NULL, this);
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnAbort), NULL, this);
    this->Connect(m_buttonFont->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnFont), NULL, this);
    // mouse events
    for (auto button : m_button)
    {
        button->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(DialogSponsor::OnColorButtonLeft), NULL, this);
        button->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(DialogSponsor::OnColorButtonRight), NULL, this);
    }
    m_staticBitmapSponsor->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(DialogSponsor::OnBitmapButtonLeft), NULL, this);
    m_staticBitmapSponsor->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(DialogSponsor::OnBitmapButtonRight), NULL, this);
    // spin events
    this->Connect(m_spinButtonSize->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogSponsor::OnSize), NULL, this);
    // list events
    this->Connect(m_listCtrlSponsors->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogSponsor::OnSelectSponsor), NULL, this);

    // init
    m_listCtrlSponsors->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);    // select first item
}

DialogSponsor::~DialogSponsor()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonOK->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnOk), NULL, this);
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnAbort), NULL, this);
    this->Disconnect(m_buttonFont->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogSponsor::OnFont), NULL, this);
    // mouse events
    for (auto button : m_button)
    {
        button->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(DialogSponsor::OnColorButtonLeft), NULL, this);
        button->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(DialogSponsor::OnColorButtonRight), NULL, this);
    }
    m_staticBitmapSponsor->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(DialogSponsor::OnBitmapButtonLeft), NULL, this);
    m_staticBitmapSponsor->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(DialogSponsor::OnBitmapButtonRight), NULL, this);
    // spin events
    this->Disconnect(m_spinButtonSize->GetId(), wxEVT_SPIN, wxSpinEventHandler(DialogSponsor::OnSize), NULL, this);
    // list events
    this->Disconnect(m_listCtrlSponsors->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogSponsor::OnSelectSponsor), NULL, this);
}

void DialogSponsor::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Destroy();
}

void DialogSponsor::OnOk(wxCommandEvent& event)
{
    saveSponsor();
    m_country->setSponsors(m_sponsors);
    Close();
}

void DialogSponsor::OnSelectSponsor(wxListEvent& event)
{
    if(m_selectedSponsor >= 0)
        saveSponsor();
    m_selectedSponsor = event.m_itemIndex;
    loadSponsor();
    redrawBitmap();
}

void DialogSponsor::OnFont(wxCommandEvent& event)
{
    wxFontData data;
    wxFontInfo fontinfo(tools->convertFontSize(m_fontSize));
    fontinfo.FaceName(m_fontName);
    fontinfo.Weight(m_fontWeight);
    fontinfo.Italic(m_italic);
    wxFont font(fontinfo);
    data.SetInitialFont(font);
    data.SetAllowSymbols(false);
    //data.SetColour(canvasTextColor);
    wxFontDialog dialog(parent, data);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxFontData retData = dialog.GetFontData();
        auto fontData = retData.GetChosenFont();
        m_fontWeight = fontData.GetWeight();
        m_fontName = fontData.GetFaceName();
        m_fontSize = tools->backConvertFontSize(fontData.GetPointSize());
        auto fontStyle = fontData.GetStyle();
        m_italic = fontStyle == wxFONTSTYLE_ITALIC;
        //auto canvasTextColour = retData.GetColour();

        m_textCtrlFont->SetLabel(m_fontName);
    }

    redrawBitmap();
}

void DialogSponsor::OnColorButtonLeft(wxMouseEvent& event)
{
    auto id = event.GetId();
    short index = 0;
    for (auto button : m_button)
    {
        if (id == button->GetId())
        {
            break;
        }
        ++index;
    }
    m_textColorIndex = index;

    redrawBitmap();
}

void DialogSponsor::OnColorButtonRight(wxMouseEvent& event)
{
    auto id = event.GetId();
    short index = 0;
    for (auto button : m_button)
    {
        if (id == button->GetId())
        {
            break;
        }
        ++index;
    }
    m_backgroundColorIndex = index;

    redrawBitmap();
}

void DialogSponsor::OnBitmapButtonLeft(wxMouseEvent& event)
{
    ++m_selectedOverlayIndex;
    if (m_selectedOverlayIndex > 35)
        m_selectedOverlayIndex = 0;

    redrawBitmap();
}

void DialogSponsor::OnBitmapButtonRight(wxMouseEvent& event)
{
    --m_selectedOverlayIndex;
    if (m_selectedOverlayIndex < 0)
        m_selectedOverlayIndex = 35;

    redrawBitmap();
}

void DialogSponsor::OnSize(wxSpinEvent& event)
{
    m_staticTextSize->SetLabel(tools->translate("size" + std::to_string(m_spinButtonSize->GetValue())));
}

/*
 * save sponsor data to graph
 */
void DialogSponsor::saveSponsor()
{
    auto sponsor = m_sponsors.at(m_selectedSponsor);
    sponsor.setName(std::string(m_textCtrlText->GetLabel().mb_str()));
    sponsor.setFont(m_fontName);
    sponsor.setAdImage(m_selectedOverlayIndex);
    sponsor.setBackgroundColorSize((m_spinButtonSize->GetValue() << 16) + tools->getColorIndex(m_backgroundColorIndex, false));
    sponsor.setTextColor(tools->getColorIndex(m_textColorIndex, false));
    sponsor.setFontSize(m_fontSize);
    sponsor.setFontWeight(m_fontWeight);
    sponsor.setFontType(m_italic ? 255 : 0);
    m_sponsors.at(m_selectedSponsor) = sponsor;
}

/*
 * load sponsor data from graph
 */
void DialogSponsor::loadSponsor()
{
    auto sponsor = m_sponsors.at(m_selectedSponsor);
    m_textCtrlText->SetLabel(sponsor.getName());
    m_textCtrlFont->SetLabel(sponsor.getFont());

    // load bitmap
    wxBitmap image;
    std::string filename = "kom" + std::to_string(m_selectedSponsor + m_imageStartIndex) + ".bmp";
    image.LoadFile(tools->getAdImagePath() + filename, wxBITMAP_TYPE_BMP);
    m_staticBitmapSponsor->SetBitmap(image);

    short size = sponsor.getBackgroundColorSize() >> 16;
    m_spinButtonSize->SetValue(size);
    m_staticTextSize->SetLabel(tools->translate("size" + std::to_string(size)));
    m_selectedOverlayIndex = sponsor.getAdImage();
    m_textColorIndex = tools->getColorIndex(sponsor.getTextColor());
    m_backgroundColorIndex = tools->getColorIndex(sponsor.getBackgroundColorSize());
    m_fontSize = sponsor.getFontSize();
    m_fontWeight = sponsor.getFontWeight();
    m_italic = sponsor.getFontType()>0?true:false;
    m_fontName = sponsor.getFont();
}

/*
 * this method creates a new bitmap based on loaded or changed settings
 * it sets a background color, draws a text in a given font an color
 * and adds 2 bitmaps on both sides
 */
void DialogSponsor::redrawBitmap()
{
    std::string filename = "kom" + std::to_string(m_selectedSponsor + m_imageStartIndex) + ".bmp";
    wxImage image = tools->redrawSponsorImage(filename, m_backgroundColorIndex, m_textColorIndex, m_selectedOverlayIndex,
                                              m_fontName, m_fontSize, m_fontWeight, m_italic, std::string(m_textCtrlText->GetLabel()));
    m_staticBitmapSponsor->SetBitmap(image);
}

void DialogSponsor::initializeSponsorsList(wxListCtrl* control)
{
    control->Hide();
    control->ClearAll();

    control->InsertColumn(0, wxT(""), wxLIST_FORMAT_LEFT, 150);

    long index = 0;
    for (auto sponsor : m_sponsors)
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, sponsor.getName());   // set text column 1
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }

    control->Show();

    control->SetMinSize(wxSize(180, 320));
}