#include "FrameEditor.h"
#include "DialogClubselect.h"
#include "DialogCountryselect.h"

// Declare the bitmap loading function
//extern void wxC9ED9InitBitmapResources();

//static bool bBitmapLoaded = false;

FrameEditor::FrameEditor(wxWindow* parent,
    Toolset* const tools,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    this->tools = tools;

    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    boxSizer1->SetMinSize(0, 0);
    this->SetSizer(boxSizer1);

    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(634, 476)), wxTAB_TRAVERSAL);
    m_mainPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

    boxSizer1->Add(m_mainPanel, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);

    m_menuFile = new wxMenu();
    m_menuBar->Append(m_menuFile, tools->translate("menuFile"));

    m_menuReinitialize = new wxMenuItem(m_menuFile, wxID_ANY, tools->translate("menuReinitialize"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuReinitialize);

    m_menuFile->AppendSeparator();

    m_menuLoad = new wxMenuItem(m_menuFile, wxID_ANY, tools->translate("menuLoad"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuLoad);

    m_menuDatacheck = new wxMenuItem(m_menuFile, wxID_ANY, tools->translate("menuDatacheck"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuDatacheck);

    m_menuSave = new wxMenuItem(m_menuFile, wxID_ANY, tools->translate("menuSave") , wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuSave);

    m_menuFile->AppendSeparator();

    m_menuExit = new wxMenuItem(m_menuFile, wxID_EXIT, tools->translate("menuExit"), _("Quit"), wxITEM_NORMAL);
    m_menuFile->Append(m_menuExit);

    m_menuNational = new wxMenu();
    m_menuBar->Append(m_menuNational, tools->translate("menuNational"));

    m_menuTeams = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuTeams"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuTeams);

    m_menuPlayer = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuPlayer"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuPlayer);

    m_menuPlayerList = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuPlayerList"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuPlayerList);

    m_menuNational->AppendSeparator();

    m_menuAmateurClubs = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuAmateurClubs"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuAmateurClubs);

    m_menuAmateurPlayer = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuAmateurPlayer"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuAmateurPlayer);

    m_menuNational->AppendSeparator();

    m_menuTrainer = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuTrainer"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuTrainer);

    m_menuGoalkeeperTrainer = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuGoalkeeperTrainer"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuGoalkeeperTrainer);

    m_menuManager = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuManager"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuManager);

    m_menuNational->AppendSeparator();

    m_menuReferee = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuReferee"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuReferee);

    m_menuNational->AppendSeparator();

    m_menuAssociation = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuAssociation"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuAssociation);

    m_menuNationalCup = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuNationalCup"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuNationalCup);

    m_menuNational->AppendSeparator();

    m_menuMedia = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuMedia"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuMedia);

    m_menuCelebrity = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuCelebrity"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuCelebrity);

    m_menuSponsors = new wxMenuItem(m_menuNational, wxID_ANY, tools->translate("menuSponsors"), wxT(""), wxITEM_NORMAL);
    m_menuNational->Append(m_menuSponsors);

    m_menuInternational = new wxMenu();
    m_menuBar->Append(m_menuInternational, tools->translate("menuInternational"));

    m_menuNonEuropeanClubs = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuNonEuropeanClubs"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuNonEuropeanClubs);

    m_menuPlayerpool = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuPlayerpool"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuPlayerpool);

    m_menuInternational->AppendSeparator();

    m_menuOtherPlayer = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuOtherPlayer") , wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuOtherPlayer);

    m_menuFormerPlayer = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuFormerPlayer"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuFormerPlayer);

    m_menuInternational->AppendSeparator();

    m_menuEuropeanReferees = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuEuropeanReferees"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuEuropeanReferees);

    m_menuInternational->AppendSeparator();

    m_menuInternationalCups = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuInternational"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuInternationalCups);

    m_menuEuropeanCupGroups = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuEuropeanCupGroups"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuEuropeanCupGroups);

    m_menuEuropeanChampionshipGroups = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuEuropeanChampionshipGroups"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuEuropeanChampionshipGroups);

    m_menuWorldChampionshipGroups = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuWorldChampionshipGroups"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuWorldChampionshipGroups);

    m_menuInternational->AppendSeparator();

    m_menuEuropeanWorldChampionship = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuEuropeanWorldChampionship") , wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuEuropeanWorldChampionship);

    m_menuNationalJerseys = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuNationalJerseys"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuNationalJerseys);

    m_menuNationalSquad = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuNationalSquad"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuNationalSquad);

    m_menuInternational->AppendSeparator();

    m_menuBestPlayers = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuBestPlayers"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuBestPlayers);

    m_menuInternational->AppendSeparator();

    m_menuOutfitter = new wxMenuItem(m_menuInternational, wxID_ANY, tools->translate("menuOutfitter"), wxT(""), wxITEM_NORMAL);
    m_menuInternational->Append(m_menuOutfitter);

    m_menuSpecial = new wxMenu();
    m_menuBar->Append(m_menuSpecial, tools->translate("menuSpecial"));

    m_menuTextChants = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuTextChants"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuTextChants);

    m_menuAudioChants = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuAudioChants"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuAudioChants);

    m_menuSpecial->AppendSeparator();

    m_menuHalftimeSpeeches = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuHalftimeSpeeches"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuHalftimeSpeeches);

    m_menuSpecial->AppendSeparator();

    m_menuCountryStartingPositions = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuCountryStartingPositions"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuCountryStartingPositions);

    m_menuGamePlans = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuGamePlans"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuGamePlans);

    m_menuSpecial->AppendSeparator();

    m_menu5YearRating = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menu5YearRating"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menu5YearRating);

    m_menuSpecial->AppendSeparator();

    m_menuLittleThings = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuLittleThings"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuLittleThings);

    m_menuSpecial->AppendSeparator();

    m_menuStatistic = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuStatistic"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuStatistic);

    m_menuSpecial->AppendSeparator();

    m_menuNewBonusCountry = new wxMenuItem(m_menuSpecial, wxID_ANY, tools->translate("menuNewBonusCountry"), wxT(""), wxITEM_NORMAL);
    m_menuSpecial->Append(m_menuNewBonusCountry);

    m_nameHelp = new wxMenu();
    m_menuBar->Append(m_nameHelp, _("?"));

    m_menuAbout = new wxMenuItem(m_nameHelp, wxID_ABOUT, tools->translate("menuAbout"), wxT(""), wxITEM_NORMAL);
    m_nameHelp->Append(m_menuAbout);

/*    SetName(wxT("Editor"));
    SetSize(wxDLG_UNIT(this, wxSize(634, 476)));
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    }
    else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if (!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    }
    else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
*/
    // Connect events
    // menu file list
    this->Connect(m_menuExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnExit), NULL, this);
    this->Connect(m_menuAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnAbout), NULL, this);
    this->Connect(m_menuLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnLoad), NULL, this);
    this->Connect(m_menuSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnSave), NULL, this);
    // menu national list
    this->Connect(m_menuTeams->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuTeams), NULL, this);
    this->Connect(m_menuPlayer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuPlayer), NULL, this);
    this->Connect(m_menuPlayerList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuPlayerList), NULL, this);
    this->Connect(m_menuAmateurClubs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuAmateurClubs), NULL, this);
    this->Connect(m_menuAmateurPlayer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuAmateurPlayer), NULL, this);
    this->Connect(m_menuTrainer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuTrainer), NULL, this);
    this->Connect(m_menuGoalkeeperTrainer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuGoalkeeperTrainer), NULL, this);
    this->Connect(m_menuManager->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuManager), NULL, this);
    this->Connect(m_menuReferee->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuReferee), NULL, this);
    this->Connect(m_menuAssociation->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuAssociation), NULL, this);
    this->Connect(m_menuNationalCup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuNationalCup), NULL, this);
    this->Connect(m_menuMedia->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuMedia), NULL, this);
    this->Connect(m_menuCelebrity->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuCelebrity), NULL, this);
    this->Connect(m_menuSponsors->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuSponsors), NULL, this);
}

FrameEditor::~FrameEditor()
{
    // Disconnect events
    // menu file list
    this->Disconnect(m_menuExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnExit), NULL, this);
    this->Disconnect(m_menuAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnAbout), NULL, this);
    this->Disconnect(m_menuLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnLoad), NULL, this);
    this->Disconnect(m_menuSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnSave), NULL, this);
    // menu national list
    this->Disconnect(m_menuTeams->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuTeams), NULL, this);
    this->Disconnect(m_menuPlayer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuPlayer), NULL, this);
    this->Disconnect(m_menuPlayerList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuPlayerList), NULL, this);
    this->Disconnect(m_menuAmateurClubs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuAmateurClubs), NULL, this);
    this->Disconnect(m_menuAmateurPlayer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuAmateurPlayer), NULL, this);
    this->Disconnect(m_menuTrainer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuTrainer), NULL, this);
    this->Disconnect(m_menuGoalkeeperTrainer->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuGoalkeeperTrainer), NULL, this);
    this->Disconnect(m_menuManager->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuManager), NULL, this);
    this->Disconnect(m_menuReferee->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuReferee), NULL, this);
    this->Disconnect(m_menuAssociation->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuAssociation), NULL, this);
    this->Disconnect(m_menuNationalCup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuNationalCup), NULL, this);
    this->Disconnect(m_menuMedia->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuMedia), NULL, this);
    this->Disconnect(m_menuCelebrity->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuCelebrity), NULL, this);
    this->Disconnect(m_menuSponsors->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FrameEditor::OnMenuSponsors), NULL, this);
}

void FrameEditor::OnExit(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void FrameEditor::OnAbout(wxCommandEvent& event)
{
    wxUnusedVar(event);
    wxAboutDialogInfo info;
    info.SetCopyright(_("Copyright (c) 2020"));
    info.SetDescription(_("Ing. Werner Ziegelwanger, MSc"));
    info.SetLicence(_("Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n\nThe above copyright noticeand this permission notice shall be included in all copies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE."));
    ::wxAboutBox(info);
}

void FrameEditor::OnLoad(wxCommandEvent& event)
{
    if (wxMessageBox(wxT("Wollen Sie wirklich die Daten neu laden?"), wxT("EDITOR"), wxYES_NO | wxICON_INFORMATION, this) == wxYES)
    {
        wxMessageBox(wxT("JA!"), wxT(""), wxOK, this);
    }
    else
    {
        wxMessageBox(wxT("NEIN!"), wxT(""), wxOK, this);
    }
}

void FrameEditor::OnSave(wxCommandEvent& event)
{
    wxMessageBox(wxT("Sollen die Bandengrafiken ebenfalls gespeichert werden?"), wxT("EDITOR"), wxYES_NO | wxICON_INFORMATION, this);
}

void FrameEditor::OnMenuTeams(wxCommandEvent& event)
{
    int selectedClub = callDialogClubselect();
}

void FrameEditor::OnMenuPlayer(wxCommandEvent& event)
{
    int selectedClub = callDialogClubselect();
}

void FrameEditor::OnMenuPlayerList(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuAmateurClubs(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuAmateurPlayer(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuTrainer(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuGoalkeeperTrainer(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuManager(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuReferee(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuAssociation(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuNationalCup(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuMedia(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuCelebrity(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}

void FrameEditor::OnMenuSponsors(wxCommandEvent& event)
{
    int selectedCountry = callDialogCountryselect();
}


int FrameEditor::callDialogCountryselect()
{

    DialogCountryselect dlg(this, tools);
    dlg.ShowModal();

    std::string selectedCountry = dlg.GetSelectedCountry();

    //TODO ### return selected country Id

    return 0;
}

int FrameEditor::callDialogClubselect()
{
    DialogClubselect dlg(this, tools);
    dlg.ShowModal();

    //TODO ### return selected team id

    return 0;
}