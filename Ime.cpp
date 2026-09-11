// Copyright © 2014 CCP ehf.

#include "StdAfx.h"
#include "Ime.h"
#include "KeyboardLayoutMac.h"

#if __APPLE__

Ime::Ime( IRoot* lockobj )
{
	
}

Ime::~Ime()
{
	
}

std::wstring Ime::GetKeyboardLayout()
{
    return GetKeyboardLayoutMac();
}

#elif _WIN32

Ime::Ime( IRoot* lockobj )
{
	ImeWrapper::InitializeImm();
}

Ime::~Ime()
{
	ImeWrapper::UninitializeImm();
}

void Ime::SetHWND( uintptr_t handle )
{
	auto window = reinterpret_cast<HWND>( handle );
	if( window != m_window )
	{
		if( m_window )
		{
			ImeWrapper::ImmReleaseContext( m_window, m_imc );
		}

		m_window = window;
		m_imc = ImeWrapper::ImmGetContext( m_window );
	}
}

void Ime::AssociateContext( bool show )
{
	ImeWrapper::ImmAssociateContext( m_window, show ? m_imc : nullptr );
}

int32_t Ime::GetCursorPos()
{
	return ImeWrapper::ImmGetCompositionStringW( m_imc, GCS_CURSORPOS, nullptr, 0 );
}

std::wstring Ime::GetCompositionString( DWORD mask )
{
	wchar_t str[256] = {};
	long size = ImeWrapper::ImmGetCompositionStringW( m_imc, mask, str, sizeof( str ) );
	return std::wstring( std::begin( str ), std::begin( str ) + size / 2 );
}

size_t Ime::GetKeyboardLayout()
{
	return reinterpret_cast<size_t>( ::GetKeyboardLayout( GetCurrentThreadId() ) );
}

bool Ime::NotifyIME( DWORD dwAction, DWORD dwIndex, DWORD dwValue )
{
	return ImeWrapper::ImmNotifyIME( m_imc, dwAction, dwIndex, dwValue );
}

bool Ime::SimulateHotKey( DWORD hotkeyID )
{
	return ImeWrapper::ImmSimulateHotKey( m_window, hotkeyID );
}

bool Ime::GetOpenStatus()
{
	return ImeWrapper::ImmGetOpenStatus( m_imc );
}

bool Ime::SetOpenStatus( bool show )
{
	return ImeWrapper::ImmSetOpenStatus( m_imc, show );
}

#endif
