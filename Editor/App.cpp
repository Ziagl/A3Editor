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
	editor = new Editor(nullptr);
	SetTopWindow(editor);
	return GetTopWindow()->Show();
}