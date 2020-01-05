#include "App.h"

wxIMPLEMENT_APP(App);

App::App()
{

}

App::~App()
{

}

bool App::OnInit()
{
	editor = std::make_shared <Editor>();
	editor->Show();

	return true;
}