#pragma once

#include "stdafx.h"
#include "Scene.h"

class Scene_Menu :
	public Scene
{
private:
	BoxUI			m_Box;
	TextUI			m_Txt;
		
public:
	int		m_Select = 0;

public:
	Scene_Menu();
	~Scene_Menu();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};

