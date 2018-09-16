#include "stdafx.h"
#include "Scene_Trainer.h"
#include "SceneMgr.h"

Scene_Trainer::Scene_Trainer()
{
}


Scene_Trainer::~Scene_Trainer()
{
}

void Scene_Trainer::Init(HWND _hWnd)
{
	ID_Num = 34176;
	Money = PLAYER_MANAGER.GetMoney();
	Poketmon = 151;
	m_PlayTime = 200;
	LeagueBadge = PLAYER_MANAGER.GetBadgeCount();
}

void Scene_Trainer::Update(float _elapseTime)
{
	m_PlayTime += _elapseTime;

	if (KEY_MANAGER.OnceKeyDown(VK_LEFT))
	{
		LeagueBadge--;
		if (LeagueBadge < 0)
		{
			LeagueBadge = 0;
		}
	}
	if (KEY_MANAGER.OnceKeyDown(VK_RIGHT))
	{
		LeagueBadge++;
		if (LeagueBadge >= 9)
		{
			LeagueBadge = 8;
		}
	}

	TrainerNowTime = (int)TIMER.GetPlayTime();
}

void Scene_Trainer::Render(HDC _hdc)
{
	//���� �޴�
	IMG_MGR->GetImg("TrainerCard")->Render(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT);

	TrainerText.TextBox(_hdc, 110, 150, "�̸�", 50, GRAY, LGRAY);
	TrainerText.TextBox(_hdc, 110, 265, "��", 50, GRAY, LGRAY);
	TrainerText.TextBox(_hdc, 110, 325, "���ϸ� ����", 50, GRAY, LGRAY);
	TrainerText.TextBox(_hdc, 110, 388, "�÷��� �ð�", 50, GRAY, LGRAY);

	//���� �޴�
	std::stringstream buf;
	buf << ID_Num;
	std::string IntToCharTemp = std::to_string(ID_Num);
	//-----TextBox�� _Str�� ���ڿ� �̱⶧���� int�� ���ڷ� �ٲٴ� to_string��
	TrainerText.TextBox(_hdc, 700, 72, buf.str().c_str(), 50, GRAY, LGRAY);
	TrainerText.TextBox(_hdc, 430, 150, PLAYER_MANAGER.GetName().c_str(), 50, GRAY, LGRAY);

	int money = PLAYER_MANAGER.GetMoney();
	int numA = money / 1000;
	int numB = numA / 1000;
	
	buf.str("");
	buf << money << "��";
	TrainerText.TextBox(_hdc, 430, 265, buf.str().c_str(), 50, GRAY, LGRAY);
	IntToCharTemp = std::to_string(Poketmon);
	TrainerText.TextBox(_hdc, 430, 325, IntToCharTemp.c_str(), 50, GRAY, LGRAY);


	//�����޴��� �ð�
	//int playtime�� �ð��� ������ �����
	int TimeHour = TIMER.GetPlayTime() / 60;
	int TimSecond = (int)TIMER.GetPlayTime() % 60;
	/*int TimeHour = m_PlayTime / 60;
	int TimSecond = (int)(m_PlayTime) % 60;*/
	IntToCharTemp = std::to_string(TimeHour);

	HDC HdcOldTemp = _hdc;
	SetTextAlign(_hdc, TA_RIGHT);
	//�ð��� ���� ���� ��Ŵ
	TrainerText.TextBox(_hdc, 500, 388, IntToCharTemp.c_str(), 50, GRAY, LGRAY);
	_hdc = HdcOldTemp;
	IntToCharTemp = std::to_string(TimSecond);
	TrainerText.TextBox(_hdc, 595, 388, IntToCharTemp.c_str(), 50, GRAY, LGRAY);
	//�ð��� �����̴°�
	if ((TrainerNowTime % 2) == 0)
	{
		TrainerText.TextBox(_hdc, 530, 388, ":", 50, GRAY, LGRAY);
	}


	//���� �̹��� (���� 1~8 ���� int)
	HDC tempDC = IMG_MGR->GetImg("League")->GetImgDC();
	if (LeagueBadge != 0 && LeagueBadge <= 8)
		for (int i = 0; i < LeagueBadge; i++)
		{
			GdiTransparentBlt(_hdc, 132 + (96 * i), 517, 55, 55, tempDC, 0 + (17 * i), 0, 16, 16, RGB(0, 128, 0));
		}

}


bool Scene_Trainer::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_wParam)
	{

	case 'x':
	case 'X': 
	{	
		//SCENE_MGR.SetScene(SCENE_MENU); 
		SCENE_MGR.CloseScene();
	}break;

	case VK_ESCAPE: return true;	break;
	}
	return false;
}
