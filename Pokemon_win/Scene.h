#pragma once

#include <Windows.h>

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void	Init(HWND _hWnd)			= 0;
	virtual void	Update(float _elapseTime)	= 0;
	virtual void	Render(HDC _hdc)			= 0;
	virtual bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam) = 0;
};