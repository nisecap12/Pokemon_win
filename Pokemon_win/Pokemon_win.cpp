#include "stdafx.h"
#include "TimerManager.h"
#include "DataManager.h"
#include "NPC.h"

#define WIN_WIDTH 960
#define WIN_HEIGHT 640

LPCSTR CLASS_NAME = "Pokemon_win";

NPC tempNPC; //test
NPC tempNPC2; //test

void Init()
{
	TIMER.SetFPS(20);
}

void Update(float _elapseTime)
{
	tempNPC.DoAction(); //test
	tempNPC2.DoAction();
}

void Render(HDC _hdc)
{
	TIMER.Render(_hdc, 0, 0);
	int halfW = WIN_WIDTH / 2;
	int halfH = WIN_HEIGHT / 2;
	
	tempNPC.Render(_hdc); //test
	tempNPC2.Render(_hdc);
}

LRESULT	CALLBACK WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
		switch (_wParam)
		{
		case VK_UP:
		{
			
		}break;
		case VK_DOWN:
		{
			
		}break;
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}break;

	}

	return DefWindowProc(_hWnd, _message, _wParam, _lParam);
}

int APIENTRY WinMain(HINSTANCE _hInst, HINSTANCE _prevInst, LPSTR _cmdParam, int _cmdShow)
{
	WNDCLASS wndClass = {};
	wndClass.hInstance = _hInst;
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);

	RegisterClass(&wndClass);

	int		wsOption = WS_OVERLAPPEDWINDOW;
	RECT	rt = { 0, 0, WIN_WIDTH, WIN_HEIGHT };

	HWND hWnd = CreateWindow(CLASS_NAME, CLASS_NAME, wsOption, 0, 0, rt.right - rt.left, rt.bottom - rt.top, nullptr, nullptr, _hInst, nullptr);

	if (hWnd == 0)
	{
		return 0;
	}

	tempNPC = NPC(NPC_FUNCTION::NONE, NPC_DIRECTION::UP, NPC_PATTERN::TURN_ARROUND_CLOCKWISE, 0, { 2,2 }, {5,2}); //test
	tempNPC2 = NPC(NPC_FUNCTION::NONE, NPC_DIRECTION::LEFT, NPC_PATTERN::RANDOM, 0, { 5,5 }, { 4,1 });

	Init();
	ShowWindow(hWnd, _cmdShow);

	MSG msg = {};

	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update(TIMER.DoTick());
			HDC			hdc = GetDC(hWnd);

			HDC	backDC = CreateCompatibleDC(hdc);
			HBITMAP hBit = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
			HBITMAP hOldBit = SelectBitmap(backDC, hBit);

			RECT rc = { 0, 0, WIN_WIDTH, WIN_HEIGHT };
			FillRect(backDC, &rc, GetStockBrush(WHITE_BRUSH));

			Render(backDC);

			BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backDC, 0, 0, SRCCOPY);

			DeleteObject(SelectBitmap(backDC, hOldBit));
			DeleteDC(backDC);

			ReleaseDC(hWnd, hdc);
		}
	}
	return 0;
}