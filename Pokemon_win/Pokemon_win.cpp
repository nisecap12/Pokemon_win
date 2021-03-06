#include "stdafx.h"

LPCSTR CLASS_NAME = "POKEMON FIRE RED - (오박사 외전)";

void Init(HWND _hWnd)
{
	TIMER.SetFPS(DEFAULT_FPS);
	SCRIPT_MANAGER.Init();
	MAP_MANAGER.Init(_hWnd);
	PLAYER_MANAGER.Init(_hWnd);
	NPC_MANAGER.Init(_hWnd);
	ITEM_MANAGER.Init();
	SKILL_MANAGER.Init();
	BAG_MANAGER.Init();
	POKEDEX.Init();
	POKEMON_MANAGER.Init();
	SCENE_MGR.Init(_hWnd);
	DATA_MANAGER.Init();
}

void Update(float _elapseTime)
{
	SCENE_MGR.Update(_elapseTime);
	SOUND_MGR.Update();
}

void Render(HDC _hdc)
{
	SCENE_MGR.Render(_hdc);
}

LRESULT	CALLBACK WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	if (SCENE_MGR.WndProc(_hWnd, _message, _wParam, _lParam) == true)
	{
		return 0;
	}

	switch (_message)
	{
	case WM_ACTIVATEAPP:
		KEY_MANAGER.IsFocused( (bool)_wParam);
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
	srand(GetTickCount());
	WNDCLASS wndClass = {};
	wndClass.hInstance = _hInst;
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.hIcon = LoadIcon(_hInst, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClass(&wndClass);
	

	int		wsOption = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN;
	RECT	rt = { 0, 0, WIN_WIDTH, WIN_HEIGHT };

	AdjustWindowRect(&rt, wsOption, FALSE);

	HWND hWnd = CreateWindow(CLASS_NAME, CLASS_NAME, wsOption, 0, 0, rt.right - rt.left, rt.bottom - rt.top, nullptr, nullptr, _hInst, nullptr);

	if (hWnd == 0)
	{
		return 0;
	}

	Init(hWnd);
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
			FillRect(backDC, &rc, GetStockBrush(BLACK_BRUSH));
			Render(backDC);
			BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backDC, 0, 0, SRCCOPY);
			DeleteObject(SelectBitmap(backDC, hOldBit));
			DeleteDC(backDC);

			ReleaseDC(hWnd, hdc);
		}
	}

	IMG_MGR->Destroy();

	return 0;
}