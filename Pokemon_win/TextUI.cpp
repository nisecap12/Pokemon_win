#include "stdafx.h"
#include "TextUI.h"

TextUI::TextUI()
{
}


TextUI::~TextUI()
{
}

void TextUI::TextBox(HDC _hdc, int _PosX, int _PosY, LPCSTR _Str, int _Size, COLORREF _Color, COLORREF _Color2)
{
	//HFONT	hFont = CreateFont(_Size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±¼¸²"));
	//HFONT	hFont = CreateFont(_Size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("HYÇìµå¶óÀÎM"));
	HFONT	hFont = CreateFont(_Size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("³ª´®°íµñÄÚµù"));
	HFONT	OldFont = (HFONT)SelectObject(_hdc, hFont);

	SetTextColor(_hdc, _Color2);
	SetBkMode(_hdc, TRANSPARENT);
	TextOut(_hdc, _PosX + 2, _PosY + 2, _Str, strlen(_Str));

	SetTextColor(_hdc, _Color);
	SetBkMode(_hdc, TRANSPARENT);
	TextOut(_hdc, _PosX, _PosY, _Str, strlen(_Str));
	SelectObject(_hdc, OldFont);
	DeleteObject(hFont);
}
