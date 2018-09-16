#pragma once
#include "Scene.h"

class Scene_Trainer :
	public Scene
{
private:
	TextUI		TrainerText;
	int			TrainerNowTime;
	int			TrainerOldTime;

	//테스팅용 변수
	int ID_Num = 34176;
	int Money = 100000;
	int Poketmon = 8;
	float m_PlayTime = 200;
	int LeagueBadge = 5;


public:
	Scene_Trainer();
	~Scene_Trainer();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};