#include "stdafx.h"
#include "Scene_Intro.h"
#include "SceneMgr.h"

#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

Scene_Intro::Scene_Intro()
{
}
Scene_Intro::~Scene_Intro()
{
}
void Scene_Intro::Init(HWND _hWnd)
{
	HINSTANCE g_hInst = 0;

	if (m_hWnd)
	{
		MCIWndClose(m_hWnd);
		MCIWndDestroy(m_hWnd);
		m_hWnd = 0;
	}

	m_hWnd = MCIWndCreate(_hWnd, g_hInst, MCIWNDF_NOTIFYMODE, "Intro_Cam.avi");

	if (m_hWnd)
	{
		MCIWndPlay(m_hWnd);
	}
}

void Scene_Intro::Update(float _elapseTime)
{
	m_time += _elapseTime;

	if (m_time >= 2.0f)
	{
		if (!flag && !flag2)
		{
			SOUND_MGR.PlaySoundTrack(5);
			flag = true;
		}
	}
	if (m_time >= 10.0f)
	{
		if (!flag2)
		{
			SOUND_MGR.PlaySoundTrack(1);
			flag2 = true;
			m_time -= 10.0f;
		}
	}
	
	if (m_time >= 5.0f && flag2)
	{
		if (!flag3)
		{
			flag3 = true;
		}
	}
}

void Scene_Intro::Render(HDC _hdc)
{
	HDC videoDC = GetDC(m_hWnd);
	
	if (flag3)
	{
		m_Txt.TextBox(videoDC, 380, 40, "z키를 눌러주세요", 25, WHITE);
	}

	SCENE_MGR.SetScreen(videoDC);
}

bool Scene_Intro::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case MCIWNDM_NOTIFYMODE:
	{
		if (_lParam == MCI_MODE_STOP)
		{
			MCIWndPlayFrom(m_hWnd, 0);
			m_time = 0.0f;
			flag = false;
			flag2 = false;
			flag3 = false;
			SOUND_MGR.StopSoundTrack();
		}
	}break;
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case	'Z':
		{
			if (flag2)
			{
				MCIWndClose(m_hWnd);
				MCIWndDestroy(m_hWnd);

				SCENE_MGR.SetMsg((void *)true);
				SCENE_MGR.SetScene();
			}
			else
			{
				SOUND_MGR.PlaySoundTrack(1);
				flag2 = true;
				MCIWndPlayFrom(m_hWnd, 340);
			}
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}

	return false;
}
