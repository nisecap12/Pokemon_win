#undef UNICODE
#include <Windows.h>
#include <windowsx.h>
#include "TimerManager.h"

#define CLASS_NAME "SampleWindow"
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

void Update(float _elapseTime)
{
	
}

void Render(HDC _hdc)
{
	TIMER.Render(_hdc, 100, 100);
	
}

LRESULT	CALLBACK WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
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
			HDC backDC = GetDC(hWnd);
			HBITMAP newBit = CreateCompatibleBitmap(backDC, WIN_WIDTH, WIN_HEIGHT);
			HBITMAP oldBit = SelectBitmap(backDC, newBit);

			Render(backDC);

			SelectBitmap(backDC, oldBit);
			ReleaseDC(hWnd, backDC);
		}
	}
	return msg.wParam;
}