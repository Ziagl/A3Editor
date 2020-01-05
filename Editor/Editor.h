#pragma once

#include "wx/wx.h"

class Editor : public wxFrame
{
public:
	Editor();
	~Editor();

private:
	// wxWidgets Objects overwrite delete operator for cleaning up (for example child objects)
	// this causes ane error with smart pointers for wxFrame objects. If this method is overwritten
	// empty, smart pointer takes control over cleanup for this object.
	void __CRTDECL operator delete(void* const block) noexcept {}
};

