#pragma once
#include "Scene.h"

enum POPUP_MODE
{
	ASK_JOB,
	ASK_COUNT,
	ASK_YES_NO,
};

class Scene_Bag :
	public Scene
{
private:
	HDC		m_BGDC = nullptr;
	BoxUI	m_Box;
	TextUI	m_Txt;
	
	int		m_Ani = 0;
	float	m_time = 0;
	int		m_BagNum = ItemType::TOOL;
	int		m_cursorIndex = 0;
	int		m_topIndex = 0;
	int		m_toolIndex = 0;
	int		m_specialIndex = 0;
	int		m_ballIndex = 0;
	int		m_selectIndex = 0;

	int		MAX_ITEM_VIEW = 6;
	int		m_popupMode;
	bool	isPopup = false;
	int		m_discardCount;
	int		m_maxDiscardCount;
	
public:
	int		m_ItemList = 0;
public:
	Scene_Bag();
	~Scene_Bag();
	
	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};

