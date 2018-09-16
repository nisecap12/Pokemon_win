#pragma once
#include "Scene.h"

class Scene_Setting :
	public Scene
{
private:
	TextUI		SettingMenuText;
	BoxUI		SettingMenuBox;
	AniInfo		SettingMenuAni;

public:
	Scene_Setting();
	~Scene_Setting();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);

	void Click_Button(int _key);

};

