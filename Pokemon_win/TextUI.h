#pragma once
#include "stdafx.h"

class TextUI
{
private:
	LPCSTR		m_str = nullptr;	//	문자 내용
	COLORREF	m_TextColor = {};	//	문자 색상
	int			m_TextPosX = 0;		//	문자 위치 x
	int			m_TextPosY = 0;		//	문자 위치 y
	int			m_TextSize = 25;	//	문자 크기 기본(25)

public:
	TextUI();
	~TextUI();

	void	TextBox(HDC _hdc, int _PosX, int _PosY, LPCSTR _Str, int _Size = 25, COLORREF _Color = RGB(0, 0, 0), COLORREF _Color2 = RGB(96, 96, 96));
	//void	TextBox(HDC _hdc, int _PosX, int _PosY, LPCSTR _Str, int _Size = 25, COLORREF _Color = BLACK, COLORREF _Color2 = LGRAY);
};

