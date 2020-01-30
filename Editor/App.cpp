#include "App.h"

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
	tools->SetTranslator(std::make_shared<Editor::Translator>("data/translation.xml", "en"));		//#TODO xml Pfad in Konfiguration, aktuelle Sprache in Konfiguration			
	// create frame
	editor = new FrameEditor(nullptr, tools);
	SetTopWindow(editor);
	return GetTopWindow()->Show();
}