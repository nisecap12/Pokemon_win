#include "stdafx.h"
#include "Scene_Menu.h"
#include "SceneMgr.h"

Scene_Menu::Scene_Menu()
{
}

Scene_Menu::~Scene_Menu()
{
}

void Scene_Menu::Init(HWND _hWnd)
{
}

void Scene_Menu::Update(float _elapseTime)
{
}

void Scene_Menu::Render(HDC _hdc)
{
	//스크린샷
	BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, SCENE_MGR.GetScreen(), 0, 0, SRCCOPY);

	//	메뉴
	m_Box.BoxCreate(_hdc, 21, 0, 29, 14, 7, true);
	m_Txt.TextBox(_hdc, 723, (64 * 0) + 30, "도감", 40);
	m_Txt.TextBox(_hdc, 723, (64 * 1) + 30, "포켓몬", 40);
	m_Txt.TextBox(_hdc, 723, (64 * 2) + 30, "가방", 40);
	m_Txt.TextBox(_hdc, 723, (64 * 3) + 30, "트레이너", 40);
	m_Txt.TextBox(_hdc, 723, (64 * 4) + 30, "리포트", 40);
	m_Txt.TextBox(_hdc, 723, (64 * 5) + 30, "설정", 40);
	m_Txt.TextBox(_hdc, 723, (64 * 6) + 30, "닫기", 40);

	//	메뉴 설명 박스
	HDC _BGDC = IMG_MGR->GetImg("Dialog_00")->GetImgDC();
	BitBlt(_hdc, 0, 15 * 32, WIN_WIDTH, WIN_HEIGHT, _BGDC, 0, 0, SRCCOPY);

	switch (m_Box.m_Select)
	{
	case 0:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "도감에 기록된 포켓몬의", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "상세 정보를 확인합니다.", 44, WHITE);
	} break;
	case 1:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "같이 있는 포켓몬의 상태를", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "확인하고 관리합니다.", 44, WHITE);
	} break;

	case 2:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "도구를 확인하고", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "사용할 수 있습니다.", 44, WHITE);
	} break;

	case 3:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "당신의 트레이너 카드를", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "확인합니다.", 44, WHITE);
	} break;

	case 4:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "지금까지의 모험을", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "리포트로 기록합니다.", 44, WHITE);
	} break;

	case 5:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "사운드, 속도등의 설정을", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "변경합니다.", 44, WHITE);
	} break;

	case 6:
	{
		m_Txt.TextBox(_hdc, 1 * 32, 16 * 32, "이 메뉴를 닫고", 44, WHITE);
		m_Txt.TextBox(_hdc, 1 * 32, 18 * 32, "게임을 계속 합니다.", 44, WHITE);
	} break;
	}
}

bool Scene_Menu::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{

	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			m_Select--;
			if (m_Select < 0)
				m_Select = 5;
		}break;

		case VK_DOWN:
		{
			m_Select++;
			if (m_Select > 5)
				m_Select = 0;
		}break;

		case 'z':
		case 'Z':
		{
			SOUND_MGR.PlaySoundTrack(12);
			switch (m_Box.m_Select)
			{
			case 0: {SCENE_MGR.OpenScene(SCENE_DIC); }break;
			case 1: {SCENE_MGR.OpenScene(SCENE_POKEMON); }break;
			case 2: {SCENE_MGR.OpenScene(SCENE_BAG); }break;
			case 3: {SCENE_MGR.OpenScene(SCENE_TRAINER); }break;
			case 4: {SCENE_MGR.OpenScene(SCENE_REPORT); }break;
			case 5: {SCENE_MGR.OpenScene(SCENE_SETTING); }break;
			case 6: 
			{
				SCENE_MGR.SetMsg((void *)false);
				//SCENE_MGR.SetScene(SCENE_MAIN); 
				SCENE_MGR.CloseScene();
			}break;	//	닫기
			}
		}break;

		case 'x':
		case 'X': 
		{
			SCENE_MGR.SetMsg((void *)false);
			//SCENE_MGR.SetScene(SCENE_MAIN); 
			SCENE_MGR.CloseScene();
		}break;

		case VK_RETURN: 
		{
			SCENE_MGR.SetMsg((void *)false);
			//SCENE_MGR.SetScene(SCENE_MAIN); 
			SCENE_MGR.CloseScene();
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}