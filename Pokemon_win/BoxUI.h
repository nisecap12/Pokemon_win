#pragma once
#include "stdafx.h"

class BoxUI
{
private:
	SIZE	m_CellSize = { 32, 32 };	//	한칸의 사이즈
	int		m_nx = 30;					//	가로 최대치
	int		m_ny = 20;					//	세로 최대치
		
public:
	int		m_Select = 0;
	bool	m_isClick = false;
public:
	BoxUI();
	~BoxUI();
	void	Init(HWND _hWnd);
	void	BoxImg(HDC _hdc, int _posX, int _posY, int _tileX, int _tileY);
	//	시작좌표와 끝좌표 입력시 Box 생성
	//	Select 옵션 true, false
	void	BoxCreate(HDC _hdc, int _startPosX, int _startPosY, int _endPosX, int _endPosY, int _MaxNum = 0, bool _select = false);
};

