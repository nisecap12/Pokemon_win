#pragma once
#include "Scene.h"

class Scene_Intro :
	public Scene
{
private:
	TextUI	m_Txt;

	HWND m_hWnd;
	float m_time;
	bool flag = false;
	bool flag2 = false;
	bool flag3 = false;
	LONG pos;

	bool isStop = false;

public:
	Scene_Intro();
	~Scene_Intro();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};

