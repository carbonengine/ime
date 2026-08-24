// Copyright © 2014 CCP ehf.

#pragma once

#include "ImeWrapper.h"

#include <string>

BLUE_CLASS( Ime ) : public IRoot
{
public:
	EXPOSE_TO_BLUE();

	Ime( IRoot* lockobj = nullptr );
	~Ime();
	
#if __APPLE__
	std::wstring GetKeyboardLayout();

#elif _WIN32

	void SetHWND( uintptr_t handle );
	void AssociateContext( bool show );
	int32_t GetCursorPos();
	std::wstring GetCompositionString( DWORD mask );
	size_t GetKeyboardLayout();
	bool NotifyIME( DWORD dwAction, DWORD dwIndex, DWORD dwValue );
	bool SimulateHotKey( DWORD hotkeyID );
	bool GetOpenStatus();
	bool SetOpenStatus( bool show );

private:
	HWND m_window = nullptr;
	HIMC m_imc = nullptr;
#endif
};

TYPEDEF_BLUECLASS( Ime );
