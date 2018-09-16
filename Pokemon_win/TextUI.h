#pragma once
#include "stdafx.h"

class TextUI
{
private:
	LPCSTR		m_str = nullptr;	//	���� ����
	COLORREF	m_TextColor = {};	//	���� ����
	int			m_TextPosX = 0;		//	���� ��ġ x
	int			m_TextPosY = 0;		//	���� ��ġ y
	int			m_TextSize = 25;	//	���� ũ�� �⺻(25)

public:
	TextUI();
	~TextUI();

	void	TextBox(HDC _hdc, int _PosX, int _PosY, LPCSTR _Str, int _Size = 25, COLORREF _Color = RGB(0, 0, 0), COLORREF _Color2 = RGB(96, 96, 96));
	//void	TextBox(HDC _hdc, int _PosX, int _PosY, LPCSTR _Str, int _Size = 25, COLORREF _Color = BLACK, COLORREF _Color2 = LGRAY);
};

