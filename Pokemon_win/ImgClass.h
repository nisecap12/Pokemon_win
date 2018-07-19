#pragma once

#include <Windows.h>

#include <vector>
#include <initializer_list>

class AniInfo
{
	float				m_time = 0;		//	���� ��� �ð�
	std::vector<float>	m_frameTime;
public:
	
	bool				m_isAni		= false;	//	�ִϸ��̼� ���� ����
	int					m_nowIndex	= 0;		//	���� ������
	bool				m_isLoop	= false;	//	�ݺ� ����

	void	SetFrameTime(std::initializer_list<float> _list);
	void	Update(float _elapseTime);
	void	Start();
	void	Stop();
};

class ImgClass
{
private:
	HDC			m_imgDC;
	HBITMAP		m_bit, m_oldBit;
	SIZE		m_size;

	BOOL		m_isTrans;
	COLORREF	m_colorkey;

	INT			m_opacity;

public:
	ImgClass() = default;
	ImgClass(HWND _hWnd, int _width, int _height);
	ImgClass(HDC _hdc, int _width, int _height);
	~ImgClass();

	//	����
	bool	CreateImg(HWND _hWnd, int _width, int _height);
	bool	CreateImg(HDC _hdc, int _width, int _height);
	bool	LoadImg(HWND _hWnd, LPCSTR _path, int _width = 0, int _height = 0);

	//	����
	void	SetTrans(BOOL _isTrans = TRUE, COLORREF _colorkey = RGB(255, 0, 255));
	void	SetOpacity(INT _opacity);
	INT		GetOpacity()
	{
		return m_opacity;
	}

	void	SetFrame(int _frameX)
	{
		m_size.cx /= _frameX;
	}

	void	SetFrame(int _frameX, int _frameY)
	{
		m_size.cx /= _frameX;
		m_size.cy /= _frameY;
	}

	//	����
	void	Render(HDC _destDC, int _posX = 0, int _posY = 0, int _width = 0, int _height = 0 );
	void	Render(HWND _hWnd);

	//	ani
	void	AniRender(HDC _destDC, int _frameX, int _posX = 0, int _posY = 0);
	void	AniRenderXY(HDC _destDC, int _frameX, int _frameY, int _posX = 0, int _posY = 0);

	//	Scroll
	void	ScrollRender(HDC _destDC, int _posX, int _posY, int _offset);

	//	����
	void	Clear(COLORREF _color = RGB(255,255,255) );

	//	DC ���
	HDC		GetImgDC()
	{
		return m_imgDC;
	}
	SIZE	GetSize()
	{
		return m_size;
	}
};

