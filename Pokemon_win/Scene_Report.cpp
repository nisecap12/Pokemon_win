#include "stdafx.h"
#include "Scene_Report.h"
#include "SceneMgr.h"


Scene_Report::Scene_Report()
{
}
Scene_Report::~Scene_Report()
{
}

void Scene_Report::Init(HWND _hWnd)
{
	m_SaveExist = DATA_MANAGER.DataExist();
}

void Scene_Report::Update(float _elapseTime)
{
	if (m_SaveExist)
	{
		if (m_SaveMenu_AnswerYes == 2)
		{
			m_time += _elapseTime;
			m_inputLock = true;

			if (m_time >= 2.0f)
			{
				SOUND_MGR.PlaySoundTrack(10);
				m_time = 0.0f;
				m_inputLock = false;
				m_SaveMenu_AnswerYes++;
			}
		}
		else if (m_SaveMenu_AnswerYes == 3)
		{
			m_time += _elapseTime;
			m_inputLock = true;

			if (m_time >= 1.0f)
			{
				DATA_MANAGER.SaveData();
				m_SaveExist = DATA_MANAGER.DataExist();
				SCENE_MGR.CloseScene();
			}
		}
	}
	else
	{
		if (m_SaveMenu_AnswerYes == 1)
		{
			m_time += _elapseTime;
			m_inputLock = true;

			if (m_time >= 2.0f)
			{
				SOUND_MGR.PlaySoundTrack(10);
				m_time = 0.0f;
				m_inputLock = false;
				m_SaveMenu_AnswerYes++;
			}
		}
		else if (m_SaveMenu_AnswerYes == 2)
		{
			m_time += _elapseTime;
			m_inputLock = true;

			if (m_time >= 1.0f)
			{
				DATA_MANAGER.SaveData();
				m_SaveExist = DATA_MANAGER.DataExist();
				SCENE_MGR.CloseScene();
			}
		}
	}
}

void Scene_Report::Render(HDC _hdc)
{
	//��ũ����
	BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, SCENE_MGR.GetScreen(), 0, 0, SRCCOPY);

	IMG_MGR->GetImg("Dialog_01")->Render(_hdc, 20, 460, 920, 170);
	//IMG_MGR->GetImg("SaveBox1")->Render(_hdc, 10, 20, 500, 340);
	SaveBox.BoxCreate(_hdc, 0, 0, 16, 11);

	SaveText.TextBox(_hdc, 30, 110, "���ΰ�", 35, GRAY);
	SaveText.TextBox(_hdc, 30, 170, "���� ����", 35, GRAY);
	SaveText.TextBox(_hdc, 30, 230, "���ϸ� ����", 35, GRAY);
	SaveText.TextBox(_hdc, 30, 290, "�÷��� �ð�", 35, GRAY);

	// �ٲ� �κ�
	SaveText.TextBox(_hdc, 172, 52, "���ʸ���", 45, BLUE, LBLUE);
	SaveText.TextBox(_hdc, 260, 110, PLAYER_MANAGER.GetName().c_str(), 40, GRAY, LGRAY);
	std::stringstream dd;
	dd << PLAYER_MANAGER.GetBadgeCount() << "��";
	SaveText.TextBox(_hdc, 310, 170, dd.str().c_str(), 35, GRAY, LGRAY);

	dd.str("");
	dd << POKEDEX.GetFoundPokemonNum() << "����";
	SaveText.TextBox(_hdc, 310, 230, dd.str().c_str(), 35, GRAY, LGRAY);

	dd.str("");
	dd << (int)TIMER.GetPlayTime() / 60 << " : " << (int)TIMER.GetPlayTime() % 60;
	SaveText.TextBox(_hdc, 310, 290, dd.str().c_str(), 35, GRAY, LGRAY);

	switch (m_SaveMenu_AnswerYes)
	{
	case 0:
	{
		SaveBox.BoxCreate(_hdc, 20, 8, 28, 13);
		SaveText.TextBox(_hdc, 727, 297, "��", 45, GRAY, LGRAY);
		SaveText.TextBox(_hdc, 727, 357, "�ƴϿ�", 45, GRAY, LGRAY);

		if (m_SaveMenu_Num == 0)
		{
			SaveText.TextBox(_hdc, 677, 297, "��", 45, GRAY, LGRAY);
		}

		if (m_SaveMenu_Num == 1)
		{
			SaveText.TextBox(_hdc, 677, 357, "��", 45, GRAY, LGRAY);
		}

		SaveText.TextBox(_hdc, 70, 490, "���ݱ����� Ȱ����", 45, GRAY, LGRAY);

		SaveText.TextBox(_hdc, 70, 550, "���ϸ� ����Ʈ�� �ۼ��ұ��?", 45, GRAY, LGRAY);
	}break;

	case 1:
	{
		if (!m_SaveExist)
		{
			SaveText.TextBox(_hdc, 70, 490, "���ϸ� ����Ʈ�� �ۼ����Դϴ�.", 45, GRAY, LGRAY);

			SaveText.TextBox(_hdc, 70, 550, "������ ���� �ʵ��� ���ֽʽÿ�.", 45, GRAY, LGRAY);

		}
		else
		{
			IMG_MGR->GetImg("SaveBox2")->Render(_hdc, 650, 265, 250, 175);
			SaveText.TextBox(_hdc, 727, 297, "��", 45, GRAY, LGRAY);
			SaveText.TextBox(_hdc, 727, 357, "�ƴϿ�", 45, GRAY, LGRAY);

			if (m_SaveMenu_Num == 0)
			{
				SaveText.TextBox(_hdc, 677, 297, "��", 45, GRAY, LGRAY);
			}

			if (m_SaveMenu_Num == 1)
			{
				SaveText.TextBox(_hdc, 677, 357, "��", 45, GRAY, LGRAY);
			}

			SaveText.TextBox(_hdc, 70, 490, "���� �ۼ��� ����Ʈ��", 45, GRAY, LGRAY);

			SaveText.TextBox(_hdc, 70, 550, "����ᵵ �������ϱ�?", 45, GRAY, LGRAY);
		}
	}break;

	case 2:
	{
		if (m_SaveExist)
		{
			SaveText.TextBox(_hdc, 70, 490, "���ϸ� ����Ʈ�� �ۼ����Դϴ�.", 45, GRAY, LGRAY);

			SaveText.TextBox(_hdc, 70, 550, "������ ���� �ʵ��� ���ֽʽÿ�.", 45, GRAY, LGRAY);
		}
		else
		{
			SaveText.TextBox(_hdc, 70, 490, "����Ʈ�� �ۼ��߽��ϴ�.", 45, GRAY, LGRAY);
		}
	}break;

	case 3:
	{
		if (m_SaveExist)
		{
			SaveText.TextBox(_hdc, 70, 490, "����Ʈ�� �ۼ��߽��ϴ�.", 45, GRAY, LGRAY);
		}
	}break;
	}
}

bool Scene_Report::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			m_SaveMenu_Num--;
			if (m_SaveMenu_Num < 0)
			{
				m_SaveMenu_Num = 1;
			}
		}break;
		case VK_DOWN:
		{
			m_SaveMenu_Num++;
			if (m_SaveMenu_Num > 1)
			{
				m_SaveMenu_Num = 0;
			}
		}break;
		case 'z':
		case 'Z':
		{
			SOUND_MGR.PlaySoundTrack(12);
			if (m_SaveMenu_Num == 0)
			{
				if (!m_inputLock)
				{
					m_SaveMenu_AnswerYes++;
				}
			}

			if (m_SaveMenu_Num == 1)
			{
				m_SaveMenu_AnswerNo--;
				if (m_SaveMenu_AnswerNo < 0)
				{
					m_SaveMenu_AnswerNo = 1;
				}
			}
		}break;
		case 'x':
		case 'X': 
		{	
			SCENE_MGR.CloseScene();
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}