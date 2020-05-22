#include "App.h"
#include "DialogLoader.h"

wxIMPLEMENT_APP(App);

App::App()
{
	tools = new Toolset();
}

App::~App()
{
	if (tools)
	{
		delete tools;
		tools = nullptr;
	}
}

bool App::OnInit()
{
	// initialize toolset
	tools->SetTranslator(std::make_shared<Editor::Translator>("config/translation.xml", "en"));		//#TODO xml Pfad in Konfiguration, aktuelle Sprache in Konfiguration
	tools->SetPlayableCountries(std::make_shared<Editor::PlayableCountries>("config/playablecountries.xml"));
	tools->SetCountriesWithLeagues(std::make_shared<Editor::CountriesWithLeagues>("config/countrieswithleagues.xml"));

	// load data
	DialogLoader dlg(nullptr);
	dlg.Show();
	tools->loadGraph(&dlg);

	// create frame
	editor = new FrameEditor(nullptr, tools);
	SetTopWindow(editor);
	return GetTopWindow()->Show();
}