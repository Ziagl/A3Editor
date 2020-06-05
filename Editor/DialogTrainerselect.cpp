#include "DialogTrainerselect.h"
#include "DialogTrainer.h"
#include "Sorting.h"

DialogTrainerselect::DialogTrainerselect(wxWindow* parent,
    Toolset* const tools,
    std::string const selectedCountry,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style), tools(tools), m_selectedCountry(selectedCountry), parent(parent)
{
    /*if (!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }*/

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxBoxSizer* boxSizer31 = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(boxSizer31, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxStaticBoxSizer* staticBoxSizer29 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, tools->translate("chooseTrainer")), wxHORIZONTAL);

    boxSizer31->Add(staticBoxSizer29, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString m_listBox35Arr;
    m_trainerList = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);

    initializeTrainerList(m_trainerList);

    staticBoxSizer29->Add(m_trainerList, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer33 = new wxBoxSizer(wxVERTICAL);

    boxSizer31->Add(boxSizer33, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_ANY, tools->translate("buttonEdit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonEdit, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonApply = new wxButton(this, wxID_ANY, tools->translate("buttonApply"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonApply, 0, wxALL, WXC_FROM_DIP(5));

    m_buttonAbort = new wxButton(this, wxID_ANY, tools->translate("buttonAbort"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer33->Add(m_buttonAbort, 0, wxALL, WXC_FROM_DIP(5));

    /*SetName(wxT("MainDialogBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
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

    // connect events
    // button events
    this->Connect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainerselect::OnAbort), NULL, this);
    this->Connect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainerselect::OnApply), NULL, this);
    this->Connect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainerselect::OnEdit), NULL, this);
    // list events
    this->Connect(m_trainerList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogTrainerselect::OnSelectTrainer), NULL, this);
    this->Connect(m_trainerList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogTrainerselect::OnSelectTrainerActivated), NULL, this);
}

DialogTrainerselect::~DialogTrainerselect()
{
    // disconnect events
    // button events
    this->Disconnect(m_buttonAbort->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainerselect::OnAbort), NULL, this);
    this->Disconnect(m_buttonEdit->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainerselect::OnEdit), NULL, this);
    this->Disconnect(m_buttonApply->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DialogTrainerselect::OnApply), NULL, this);
    // list events
    this->Disconnect(m_trainerList->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(DialogTrainerselect::OnSelectTrainer), NULL, this);
    this->Disconnect(m_trainerList->GetId(), wxEVT_LIST_ITEM_ACTIVATED, wxListEventHandler(DialogTrainerselect::OnSelectTrainerActivated), NULL, this);
}

void DialogTrainerselect::OnAbort(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void DialogTrainerselect::OnApply(wxCommandEvent& event)
{

}

void DialogTrainerselect::OnEdit(wxCommandEvent& event)
{
    if (!m_selectedTrainer.empty())
    {
        DialogTrainer dlg(parent, tools, m_selectedCountry, m_selectedTrainer);
        dlg.ShowModal();
    }
}

void DialogTrainerselect::OnSelectTrainer(wxListEvent& event)
{
    m_selectedTrainer = m_trainerList->GetItemText(event.m_itemIndex, 0);
}

void DialogTrainerselect::OnSelectTrainerActivated(wxListEvent& event)
{
    m_selectedTrainer = m_trainerList->GetItemText(event.m_itemIndex, 0);

    DialogTrainer dlg(parent, tools, m_selectedCountry, m_selectedTrainer);
    dlg.ShowModal();
}

/*
 * sort list so that order is the same as in original game
 */
int wxCALLBACK SortTrainerList(wxIntPtr item1, wxIntPtr item2, wxIntPtr sortData)
{
    wxListCtrl* control = (wxListCtrl*)sortData;
    wxString str1 = control->GetItemText(item1, 0);
    wxString str2 = control->GetItemText(item2, 0);
    Sorting::replaceUmlauts(str1);
    Sorting::replaceUmlauts(str2);
    if (str1 > str2)
        return 1;
    else if (str2 > str1)
        return -1;
    else
        return 0;
}

void DialogTrainerselect::initializeTrainerList(wxListCtrl* control)
{
    control->Hide();

    control->InsertColumn(0, tools->translate("name"), wxLIST_FORMAT_LEFT, 200);
    control->InsertColumn(1, tools->translate("comp"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(2, tools->translate("age"), wxLIST_FORMAT_LEFT, 50);
    control->InsertColumn(3, tools->translate("type"), wxLIST_FORMAT_LEFT, 75);

    auto countryId = tools->getCountryIdByShortname(m_selectedCountry);
    auto country = tools->getCountryById(countryId);

    long index = 0;
    for (auto trainer : country->getCoTrainer())
    {
        long result = control->InsertItem(index, wxString::Format("Item %d", index));
        control->SetItem(result, 0, trainer.getLastname() + ", " + trainer.getFirstname());         // set text column 1
        control->SetItem(result, 1, std::to_string(trainer.getCompetence()));                       // set text column 2
        control->SetItem(result, 2, std::to_string(trainer.getAge()));                              // set text column 3
        control->SetItem(result, 3, tools->translateTrainerCompetence(trainer.getReputation()));    // set text column 4
        control->SetItemData(result, index);      // needed, otherwise SortItems does not work

        index++;
    }

    // sort list
    control->SortItems(SortTrainerList, (wxIntPtr)control);

    control->Show();

    control->SetMinSize(wxSize(375, 400));
}