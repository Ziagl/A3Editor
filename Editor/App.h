#pragma once

#include "wx/wx.h"
#include "Editor.h"

class App : public wxApp
{
public:
	App();
	~App();

	virtual bool OnInit();

private:
	Editor* editor = nullptr;
};
