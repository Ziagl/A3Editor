#pragma once

#include "wx/wx.h"
#include "FrameEditor.h"
#include "Toolset.h"

class App : public wxApp
{
public:
	App();
	~App();

	virtual bool OnInit();

private:
	FrameEditor* editor = nullptr;
	Toolset* tools = nullptr;
};
