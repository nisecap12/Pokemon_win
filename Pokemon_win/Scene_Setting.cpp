#include "stdafx.h"
#include "Scene_Setting.h"
#include "SceneMgr.h"

void Scene_Setting::Init(HWND _hWnd)
{
	m_SettingMenu_Frame = SCENE_MGR.GetBoxType();
}

void Scene_Setting::Update(float _elapseTime)
{
}

void Scene_Setting::Render(HDC _hdc)
{
	IMG_MGR->GetImg("SettingMenu")->Render(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT);
	IMG_MGR->GetImg("SettingMenuSBOX")->Render(_hdc, 40, 72);

	SettingMenuText.TextBox(_hdc, 96, 100, "���ϸ���  ���̾��  ȯ�漳��", 50, GRAY, LGRAY);
	SettingMenuBox.BoxCreate(_hdc, 1, 6, 28, 19);


	SettingMenuText.TextBox(_hdc, 96, 240, "�̾߱���  �ӵ�", 50, GRAY, LGRAY);
	SettingMenuText.TextBox(_hdc, 96, 290, "���� �ִϸ��̼�", 50, GRAY, LGRAY);
	SettingMenuText.TextBox(_hdc, 96, 340, "������  ��", 50, GRAY, LGRAY);
	SettingMenuText.TextBox(_hdc, 96, 390, "����", 50, GRAY, LGRAY);
	SettingMenuText.TextBox(_hdc, 96, 440, "��ư  ���", 50, GRAY, LGRAY);
	SettingMenuText.TextBox(_hdc, 96, 490, "������", 50, GRAY, LGRAY);
	SettingMenuText.TextBox(_hdc, 96, 540, "����", 50, GRAY, LGRAY);

	if (m_SettingMenu_TextSpeed == 0)
	{
		SettingMenuText.TextBox(_hdc, 576, 240, "����", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_TextSpeed == 1)
	{
		SettingMenuText.TextBox(_hdc, 576, 240, "������", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_TextSpeed == 2)
	{
		SettingMenuText.TextBox(_hdc, 576, 240, "������", 50, LORANGE, ORANGE);
	}

	if (m_SettingMenu_BattleScene == 0)
	{
		SettingMenuText.TextBox(_hdc, 576, 290, "����", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_BattleScene == 1)
	{
		SettingMenuText.TextBox(_hdc, 576, 290, "�����ʴ´�", 50, LORANGE, ORANGE);
	}

	if (m_SettingMenu_BattleStyle == 0)
	{
		SettingMenuText.TextBox(_hdc, 576, 340, "��ü", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_BattleStyle == 1)
	{
		SettingMenuText.TextBox(_hdc, 576, 340, "��ʸ�Ʈ", 50, LORANGE, ORANGE);
	}

	//���� �ڴ��
	IMG_MGR->GetImg("SB02_02")->Render(_hdc, 638, 395);
	HDC TempDC = IMG_MGR->GetImg("SB02_01")->GetImgDC();
	int TempVol = (int)m_SettingMenu_Sound;
	
	GdiTransparentBlt(_hdc, 638, 395, (TempVol * 20), 40, TempDC, 0, 0, (TempVol * 20), 40, RGB(255, 0, 255));
			
	// + - ǥ��
	IMG_MGR->GetImg("SB01_01")->SetTrans();
	IMG_MGR->GetImg("SB01_01")->Render(_hdc, 610, 400);
	IMG_MGR->GetImg("SB01_02")->SetTrans();
	IMG_MGR->GetImg("SB01_02")->Render(_hdc, 848, 400);

		// ����Ŀ
	if (TempVol > 0)
	{
		IMG_MGR->GetImg("SB03_01")->SetTrans();
		IMG_MGR->GetImg("SB03_01")->Render(_hdc, 576, 395);
	}
	else
	{
		IMG_MGR->GetImg("SB03_02")->SetTrans();
		IMG_MGR->GetImg("SB03_02")->Render(_hdc, 576, 395);
	}


	//������
	if (m_SettingMenu_ButtonMode == 0)
	{
		SettingMenuText.TextBox(_hdc, 576, 440, "�븻", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_ButtonMode == 1)
	{
		SettingMenuText.TextBox(_hdc, 576, 440, "LR", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_ButtonMode == 2)
	{
		SettingMenuText.TextBox(_hdc, 576, 440, "L�� A��", 50, LORANGE, ORANGE);
	}

	if (m_SettingMenu_Frame == 0)
	{
		SettingMenuText.TextBox(_hdc, 576, 490, "Ÿ��  1", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_Frame == 1)
	{
		SettingMenuText.TextBox(_hdc, 576, 490, "Ÿ��  2", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_Frame == 2)
	{
		SettingMenuText.TextBox(_hdc, 576, 490, "Ÿ��  3", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_Frame == 3)
	{
		SettingMenuText.TextBox(_hdc, 576, 490, "Ÿ��  4", 50, LORANGE, ORANGE);
	}
	else if (m_SettingMenu_Frame == 4)
	{
		SettingMenuText.TextBox(_hdc, 576, 490, "Ÿ��  5", 50, LORANGE, ORANGE);
	}


	IMG_MGR->GetImg("SettingMenuBlack")->Render(_hdc, 64, 230, 832, 10);
	IMG_MGR->GetImg("SettingMenuBlack0")->Render(_hdc, 64, 240, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack1")->Render(_hdc, 64, 290, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack2")->Render(_hdc, 64, 340, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack3")->Render(_hdc, 64, 390, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack4")->Render(_hdc, 64, 440, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack5")->Render(_hdc, 64, 490, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack6")->Render(_hdc, 64, 540, 832, 50);
	IMG_MGR->GetImg("SettingMenuBlack")->Render(_hdc, 64, 590, 832, 10);

	IMG_MGR->GetImg("SettingMenuBlack")->SetOpacity(50);

	if (m_SettingMenu_Num == 0)
	{
		IMG_MGR->GetImg("SettingMenuBlack0")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack0")->SetOpacity(50);
	}

	if (m_SettingMenu_Num == 1)
	{
		IMG_MGR->GetImg("SettingMenuBlack1")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack1")->SetOpacity(50);
	}

	if (m_SettingMenu_Num == 2)
	{
		IMG_MGR->GetImg("SettingMenuBlack2")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack2")->SetOpacity(50);
	}

	if (m_SettingMenu_Num == 3)
	{
		IMG_MGR->GetImg("SettingMenuBlack3")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack3")->SetOpacity(50);
	}

	if (m_SettingMenu_Num == 4)
	{
		IMG_MGR->GetImg("SettingMenuBlack4")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack4")->SetOpacity(50);
	}

	if (m_SettingMenu_Num == 5)
	{
		IMG_MGR->GetImg("SettingMenuBlack5")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack5")->SetOpacity(50);
	}

	if (m_SettingMenu_Num == 6)
	{
		IMG_MGR->GetImg("SettingMenuBlack6")->SetOpacity(0);
	}
	else
	{
		IMG_MGR->GetImg("SettingMenuBlack6")->SetOpacity(50);
	}
}

void Scene_Setting::Click_Button(int _key)
{
	if (VK_LEFT == _key)
	{
		if (m_SettingMenu_Num == 0)
		{
			m_SettingMenu_TextSpeed--;
			if (m_SettingMenu_TextSpeed < 0)
				m_SettingMenu_TextSpeed = 2;
		}
		else if (m_SettingMenu_Num == 1)
		{
			m_SettingMenu_BattleScene--;
			if (m_SettingMenu_BattleScene < 0)
				m_SettingMenu_BattleScene = 1;
		}
		else if (m_SettingMenu_Num == 2)
		{
			m_SettingMenu_BattleStyle--;
			if (m_SettingMenu_BattleStyle < 0)
				m_SettingMenu_BattleStyle = 1;
		}
		else if (m_SettingMenu_Num == 3)
		{
			m_SettingMenu_Sound -= 1.0f;
			if (m_SettingMenu_Sound <= 0)
			{
				m_SettingMenu_Sound = 0;
			}
				
			// ����Ʈ���� ����
			SOUND_MGR.SetEffectVolume(m_SettingMenu_Sound / 10);

			// ���� ����(BG)
			SOUND_MGR.SetBGVolume(m_SettingMenu_Sound / 10);
		}
		else if (m_SettingMenu_Num == 4)
		{
			m_SettingMenu_ButtonMode--;
			if (m_SettingMenu_ButtonMode < 0)
				m_SettingMenu_ButtonMode = 2;
		}
		else if (m_SettingMenu_Num == 5)
		{
			m_SettingMenu_Frame--;
			if (m_SettingMenu_Frame < 0)
				m_SettingMenu_Frame = 4;
			SCENE_MGR.SetBoxType(m_SettingMenu_Frame);
		}

	}
	if (VK_RIGHT == _key)
	{
		if (m_SettingMenu_Num == 0)
		{
			m_SettingMenu_TextSpeed++;
			if (m_SettingMenu_TextSpeed > 2)
				m_SettingMenu_TextSpeed = 0;
		}
		else if (m_SettingMenu_Num == 1)
		{
			m_SettingMenu_BattleScene++;
			if (m_SettingMenu_BattleScene > 1)
				m_SettingMenu_BattleScene = 0;
		}
		else if (m_SettingMenu_Num == 2)
		{
			m_SettingMenu_BattleStyle++;
			if (m_SettingMenu_BattleStyle > 1)
				m_SettingMenu_BattleStyle = 0;
		}
		else if (m_SettingMenu_Num == 3)
		{
			m_SettingMenu_Sound += 1.0f;
			if (m_SettingMenu_Sound >= 10)
			{
				m_SettingMenu_Sound = 10;
			}
				
			// ����Ʈ���� ����
			SOUND_MGR.SetEffectVolume(m_SettingMenu_Sound / 10);

			// ���� ����(BG)
			SOUND_MGR.SetBGVolume(m_SettingMenu_Sound / 10);
		}
		else if (m_SettingMenu_Num == 4)
		{
			m_SettingMenu_ButtonMode++;
			if (m_SettingMenu_ButtonMode > 2)
				m_SettingMenu_ButtonMode = 0;
		}
		else if (m_SettingMenu_Num == 5)
		{
			m_SettingMenu_Frame++;
			if (m_SettingMenu_Frame > 4)
				m_SettingMenu_Frame = 0;
			SCENE_MGR.SetBoxType(m_SettingMenu_Frame);
		}
	}
	if (VK_UP == _key)
	{
		m_SettingMenu_Num--;
		if (m_SettingMenu_Num < 0)
		{
			m_SettingMenu_Num = 6;
		}

	}
	if (VK_DOWN == _key)
	{
		m_SettingMenu_Num++;
		if (m_SettingMenu_Num > 6)
		{
			m_SettingMenu_Num = 0;
		}
	}
}

Scene_Setting::Scene_Setting()
{
}


Scene_Setting::~Scene_Setting()
{
}

bool Scene_Setting::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			Click_Button(VK_UP);
		}break;
		case VK_DOWN:
		{
			Click_Button(VK_DOWN);
		}break;
		case VK_LEFT:
		{
			Click_Button(VK_LEFT);
		}break;
		case VK_RIGHT:
		{
			Click_Button(VK_RIGHT);
		}break;
		case 'Z':
		{
			SOUND_MGR.PlaySoundTrack(12);
		}break;
		case 'x':
		case 'X': 
		{	
			//SCENE_MGR.SetScene(SCENE_MENU); 
			SCENE_MGR.CloseScene();
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}