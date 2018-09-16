#pragma once
#include "stdafx.h"

class BoxUI
{
private:
	SIZE	m_CellSize = { 32, 32 };	//	��ĭ�� ������
	int		m_nx = 30;					//	���� �ִ�ġ
	int		m_ny = 20;					//	���� �ִ�ġ
		
public:
	int		m_Select = 0;
	bool	m_isClick = false;
public:
	BoxUI();
	~BoxUI();
	void	Init(HWND _hWnd);
	void	BoxImg(HDC _hdc, int _posX, int _posY, int _tileX, int _tileY);
	//	������ǥ�� ����ǥ �Է½� Box ����
	//	Select �ɼ� true, false
	void	BoxCreate(HDC _hdc, int _startPosX, int _startPosY, int _endPosX, int _endPosY, int _MaxNum = 0, bool _select = false);
};

