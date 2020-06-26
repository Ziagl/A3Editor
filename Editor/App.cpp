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
	std::string path = tools->getConfigPath();
    
	// initialize toolset
	tools->InitializeGlobals(path + "config.xml");
	tools->SetTranslator(std::make_shared<Editor::Translator>(path + "translation.xml", tools->getLanguage()));

	// load data
	DialogLoader dlg(nullptr);
	dlg.Show();
	tools->loadGraph(&dlg);

	// create frame
	editor = new FrameEditor(nullptr, tools);
	SetTopWindow(editor);
	return GetTopWindow()->Show();
}