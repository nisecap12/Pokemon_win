#include "stdafx.h"
#include "Scene_Battle.h"
#include "SceneMgr.h"
#include "PokemonManager.h"

bool battleFlag = false;
int randomIndex = 0;
int tempHP = 0;
float hpAniValue = 0;
float hpPerTick = 0;
bool enemyDown = false;
bool lose = false;

Scene_Battle::Scene_Battle()
{
	m_BGDC = IMG_MGR->GetImg("Battle_bg")->GetImgDC();
	m_BGDC1 = IMG_MGR->GetImg("Dialog_02")->GetImgDC();
}

Scene_Battle::~Scene_Battle()
{
}

void Scene_Battle::Init(HWND _hWnd)
{
	m_BattleTrainer = (bool)SCENE_MGR.GetMsg();
	POKEMON_MANAGER.SettingBattleList();
	if (m_BattleTrainer)
	{
		POKEMON_MANAGER.SetEnemyPokemonList(BATTLE_MANAGER.GetTrainerNumber());
	}
	else
	{
		POKEMON_MANAGER.GeneratePokemon(0);
	}
	
	BATTLE_MANAGER.Lock();
	SOUND_MGR.PlaySoundTrack(4);
	SCENE_MGR.SetMsg((void*)false);
}

int GetAlpha(float _time)
{
	double pi = acos(-1);
	return (255 * sin((pi / 8) * _time));
}

void Scene_Battle::Update(float _elapseTime)
{
	switch (m_Type)
	{
	case ENTERANI:
	{
		m_time += _elapseTime;

		if (m_time >= 2.0f)
		{
			m_Type = INTRO;
			m_time -= 2.0f;
		}

		switch (m_direction)
		{
		case DIRECTION::UP:
		{
			if (y > yMIN)
			{
				y--;
			}
			else
			{
				x++;
				yMIN++;
				m_direction = RIGHT;
			}
		}break;
		case DIRECTION::DOWN:
		{
			if (y < yMAX)
			{
				y++;
			}
			else
			{
				x--;
				yMAX--;
				m_direction = LEFT;
			}
		}break;
		case DIRECTION::LEFT:
		{
			if (x > xMIN)
			{
				x--;
			}
			else
			{
				y--;
				xMIN++;
				m_direction = UP;
			}
		}break;
		case DIRECTION::RIGHT:
		{
			if (x < xMAX)
			{
				x++;
			}
			else
			{
				y++;
				xMAX--;
				m_direction = DOWN;
			}
		}break;
		}

		m_blackRect = { x,y };
	}break;
	case INTRO:
	{
		//	�߻� ��Ʋ
		if (m_BattleTrainer == false)
		{
			m_time += _elapseTime;
			m_ballTime += _elapseTime;

			if (0.3f <= m_time)
			{
				m_time -= 0.3f;
				//	ball������ ���
				if (m_playerAni > 0 && m_playerAni < 4)
					m_playerAni++;
			}
			//	�������� ball
			if (0.1f <= m_ballTime)
			{
				m_ballTime -= 0.1f;
				if (m_playerAni > 2 && m_ballAni != 8)
					m_ballAni++;
			}
			//	ball �� �������� ��������
			//	�� ���ϸ� ����
			if (m_ballAni == 8)
			{
				m_myPokemon = true;
				m_dialogIndex = 0;
				m_Type = BATTLE;
				return;
			}

			//	�÷��̾� , �� ����
			if (m_dialogIndex == 0)
			{
				//	���ϸ� �� �ܵ� ����
				if (m_EnemyMoveX < 448)
					m_EnemyMoveX += 8;
				else if (m_EnemyMoveX > 448)
					m_EnemyMoveX = 448;

				if (m_MyMoveX > 0)
					m_MyMoveX -= 8;
				else if (m_MyMoveX < 0)
					m_MyMoveX = 0;

				//	�� ü�� ���
				if (m_EnemyMoveX == 448)
				{
					if (m_EnemyInfo < 52)
						m_EnemyInfo += 16;
					else if (m_EnemyInfo > 52)
						m_EnemyInfo = 52;

				}

				//	������ �����ٸ� ��������
				if (m_EnemyInfo == 52)
				{
					m_dialogIndex++;
					BATTLE_MANAGER.Unlock();
				}
					
			}
			else if (m_dialogIndex == 3)
			{
				if (m_playerExit > -450)
					m_playerExit -= 8;
				else if (m_playerExit < -450)
					m_playerExit = -450;
			}
		}
		//	Ʈ���̳ʿ� ��Ʋ
		else if (m_BattleTrainer == true)
		{
			m_time += _elapseTime;
			m_ballTime += _elapseTime;

			if (0.3f <= m_time)
			{
				m_time -= 0.3f;
				//	ball������ ���
				if (m_playerAni > 0 && m_playerAni < 4)
					m_playerAni++;
			}
			//	�������� ball
			if (0.1f <= m_ballTime)
			{
				m_ballTime -= 0.1f;
				if (m_playerAni > 2 && m_ballAni != 8)
					m_ballAni++;
			}
			//	ball �� �������� ��������
			//	�� ���ϸ� ����
			if (m_ballAni == 8)
			{
				m_myPokemon = true;
				m_dialogIndex = 0;
				m_Type = BATTLE;
				return;
			}

			//	�÷��̾� , �� ����
			if (m_dialogIndex == 0)
			{
				//	���ϸ� �� �ܵ� ����
				if (m_EnemyMoveX < 448)
					m_EnemyMoveX += 8;
				else if (m_EnemyMoveX > 448)
					m_EnemyMoveX = 448;

				if (m_MyMoveX > 0)
					m_MyMoveX -= 8;
				else if (m_MyMoveX < 0)
					m_MyMoveX = 0;


				//	������ �����ٸ� ��������
				if (m_EnemyMoveX == 448)
				{
					m_dialogIndex++;
					BATTLE_MANAGER.Unlock();
				}
			}
			else if (m_dialogIndex == 2)
			{
				if (m_enemyExit < 460)
					m_enemyExit += 8;
				else if (m_enemyExit > 460)
					m_enemyExit = 460;

				if (m_enemyExit == 460)
					m_enemyPokemon = true;

				//	�� ü�� ���
				if (m_enemyPokemon)
				{
					if (m_EnemyInfo < 52)
						m_EnemyInfo += 16;
					else if (m_EnemyInfo > 52)
						m_EnemyInfo = 52;
				}

				if (m_EnemyInfo == 52)
				{
					m_dialogIndex++;
					m_playerAni = 1;
				}
			}
			else if (m_dialogIndex == 3)
			{
				if (m_playerExit > -450)
					m_playerExit -= 8;
				else if (m_playerExit < -450)
					m_playerExit = -450;
			}
		}
	}break;
	case BATTLE:
	{
		if (SCENE_MGR.GetMsg()) //���Ϻ� ����
		{
			m_Type = CATCH;
			m_dialogIndex = 0;
			m_playerAni = 0;
			m_ballAni = 0;
			BATTLE_MANAGER.Lock();
		}
		m_time += _elapseTime;
		if (0.3f <= m_time)
		{
			m_time -= 0.3f;
			m_Ani++;

			if (m_Ani > 1)
			{
				m_Ani = 0;
			}
		}
		
		if (m_dialogIndex == 3 || m_dialogIndex == 5)
		{
			hpAniValue -= hpPerTick;
		}
		
	}break;

	case CATCH:
	{
		m_time += _elapseTime;
		m_ballTime += _elapseTime;
		
		switch (m_dialogIndex)
		{
		
		//���Ϻ� ��ô
		case 0:
		{
			//	�������� ball
			if (0.2f <= m_ballTime)
			{
				m_ballTime -= 0.2f;
				if (m_ballAni != 8)
				{
					m_ballAni++;
				}
			}
			if (m_ballMoveX < 372)
			{
				m_ballMoveX += 8;
			}
			if(m_ballAni == 8)
			{
				m_dialogIndex++;
				m_ballMoveY = 0;
			}
		}break;

		// �����ϸ� ����� ��ƨ���
		case 1:
		{
			if (!isEffectPlaying)
			{
				SOUND_MGR.PlaySoundTrack(16);
				isEffectPlaying = true;
			}
			if (m_ballbounce >= 0)
			{
				if (!m_ballDirection)
				{
					if (m_ballPitch < m_ballMoveY)
					{
						m_ballMoveY -= 8;
					}
					else
					{
						m_ballDirection = true;
						m_ballPitch += pow(2, m_ballbounce) * 10;
						m_ballbounce--;
					}
				}
				else
				{
					if (0 > m_ballMoveY)
					{
						m_ballMoveY += 8;
					}
					else
					{
						m_ballDirection = false;
					}
				}
			}
			else
			{
				m_time = 0.0f;
				m_ballbounce = 3;
				isEffectPlaying = false;
				m_dialogIndex++;
			}
			
		}break;

		//���Ϻ� ��鸲
		case 2:
		{
			
			if (m_time >= 0.4f)
			{
				m_time -= 0.4f;
				
				if (m_ballLeft)
				{
					if (m_ballFrame == 0)
					{
						if (m_ballbounce < 0)
						{
							m_dialogIndex++;
						}
						else
						{
							m_ballFrame = 2;
							m_ballLeft = false;
						}
					}
					else
					{
						m_ballFrame = 0;
						m_ballbounce--;
					}
				}
				else
				{
					if (m_ballFrame == 0)
					{
						if (m_ballbounce < 0)
						{
							m_dialogIndex++;
						}
						else
						{
							m_ballFrame = 3;
							m_ballLeft = true;
						}
					}
					else
					{
						m_ballFrame = 0;
						m_ballbounce--;
					}
				}
			}
			
		}break;

		//��ȹ �޽��� �߰� ��Ʋ����
		case 3:
		{
			if (!isEffectPlaying)
			{
				SOUND_MGR.PlaySoundTrack(11);
			}
			isCatch = true;
			m_Type = ENDBATTLE;
			m_dialogIndex = 0;
			BATTLE_MANAGER.Unlock();
		}break;
		}
	}break;

	case SUMMARY:
	{
		m_time += _elapseTime;
		if (0.3f <= m_time)
		{
			m_time -= 0.3f;
			m_Ani++;

			if (m_Ani > 1)
			{
				m_Ani = 0;
			}
		}

		if (!lose)
		{
			m_EnemyMoveY += 4;
		}
		else
		{
			m_MyMoveY += 4;
		}
	}break;
	}
}

void Scene_Battle::Render(HDC _hdc)
{
	if (m_Type == ENTERANI)
	{
		//��ũ����
		BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, SCENE_MGR.GetScreen(), 0, 0, SRCCOPY);

		HBRUSH brush = CreateSolidBrush(BLACK);
		HBRUSH oldbrush = SelectBrush(_hdc, brush);

		Rectangle(_hdc, m_blackRect.x * 96, m_blackRect.y * 64, (m_blackRect.x + 1) * 96, (m_blackRect.y + 1) * 64);

		DeleteBrush(SelectBrush(_hdc, oldbrush));
		
		SCENE_MGR.SetScreen(_hdc);
	}
	else
	{
		auto	field1 = IMG_MGR->GetImg("Battle_grass");
		auto	field2 = field1;
		auto	myInfo = IMG_MGR->GetImg("BattleInfo_01");
		auto	enemyInfo = IMG_MGR->GetImg("BattleInfo_02");
		auto	playerImg = IMG_MGR->GetImg("Player");
		auto	ballImg = IMG_MGR->GetImg("ThrowBall");
		//auto	battleChoice = IMG_MGR->GetImg("Battle_Choice");
		//auto	battleAttack = IMG_MGR->GetImg("Battle_Attack");
		auto	blackBg = IMG_MGR->GetImg("SettingMenuBlack");
		auto	battleSelect = IMG_MGR->GetImg("Battle_Select");
		auto	enemyImg = IMG_MGR->GetImg("pokemonImg_01");
		auto	myImg = IMG_MGR->GetImg("pokemonImg_02");
		auto	trainerImg = IMG_MGR->GetImg("Trainer_01");
		auto	openBall = IMG_MGR->GetImg("openBall");

		//	���
		BitBlt(_hdc, 0, 0, WIN_WIDTH, 448, m_BGDC, 0, 0, SRCCOPY);
		//	�ܵ�
		field1->AniRender(_hdc, 0, m_EnemyMoveX, 184);
		field2->AniRender(_hdc, 0, m_MyMoveX, 392);

		std::stringstream	enemy;
		std::stringstream	my;

		Pokemon* enemyPokemon = new Pokemon;

		//	�߻�
		if (m_BattleTrainer == false)
		{
			enemyPokemon = POKEMON_MANAGER.GetWildPokemon();
			//	�� ���ϸ�
			HDC backDC = CreateCompatibleDC(_hdc);
			HBITMAP bit = CreateCompatibleBitmap(_hdc, WIN_WIDTH, WIN_HEIGHT);
			HBITMAP oldbit = SelectBitmap(backDC, bit);

			BitBlt(backDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, _hdc, 0, 0, SRCCOPY);
			if (m_Type != CATCH || m_ballAni != 8)
			{
				if (m_Type != ENDBATTLE || !isCatch)
				{
					enemyImg->AniRender(backDC, enemyPokemon->m_data.m_number, m_EnemyMoveX + 128, m_EnemyMoveY + 32);
				}
			}
			
			SIZE s = enemyImg->GetSize();
			BitBlt(_hdc, m_EnemyMoveX + 128, 32, s.cx, s.cy, backDC, m_EnemyMoveX + 128, 32, SRCCOPY);
			DeleteObject(SelectBitmap(backDC, oldbit));
			DeleteDC(backDC);

			//	ü��â
			enemyInfo->AniRender(_hdc, 0, m_EnemyInfo, 64);
			if (m_Type == BATTLE)
				myInfo->AniRender(_hdc, m_Ani, 504, 296);

			//	�� ���ϸ� (�̹���, ����â, �̸�, lv, hp, hpMax)
			enemyInfo->AniRender(_hdc, 0, m_EnemyInfo, 64);
			//	�̸�
			enemy.str("");
			enemy << enemyPokemon->m_data.m_name;
			m_Txt.TextBox(_hdc, m_EnemyInfo + 28, 88, enemy.str().c_str(), 30);
			//	Lv
			enemy.str("");
			enemy << enemyPokemon->m_level;
			m_Txt.TextBox(_hdc, m_EnemyInfo + 284, 88, enemy.str().c_str(), 30);
			enemy.str("");

			//	HP
			if (enemyPokemon->m_hp > 0)
			{
				float hp_perc = (float)enemyPokemon->m_hp / (float)enemyPokemon->m_hpMax;
				if (hp_perc > 0.5f)
				{
					IMG_MGR->GetImg("greenbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
				}
				else if (hp_perc > 0.2f)
				{
					IMG_MGR->GetImg("yellowbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
				}
				else
				{
					IMG_MGR->GetImg("redbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
				}
			}
			else
			{
				IMG_MGR->GetImg("redbar")->Render(_hdc, m_EnemyInfo + 156, 132, -1, 12);
			}
		}
		//	Ʈ���̳�
		else if (m_BattleTrainer == true)
		{
			int trainerNum = BATTLE_MANAGER.GetTrainerNumber();
			enemyPokemon = &POKEMON_MANAGER.GetEnemyPokemonList(trainerNum)[0];
			
			//	�� Ʈ���̳� ����
			if (m_Type == INTRO)
				trainerImg->Render(_hdc, m_EnemyMoveX + 152 + m_enemyExit, 32);

			//	��������
			if (m_dialogIndex == 2 && m_enemyExit < 200)
				openBall->AniRender(_hdc, 0, 680, 236);
			else if (m_dialogIndex == 2 && m_enemyPokemon == false)
				openBall->AniRender(_hdc, 1, 680, 236);		//	�� ������

			if (m_enemyPokemon)
			{
				HDC backDC = CreateCompatibleDC(_hdc);
				HBITMAP bit = CreateCompatibleBitmap(_hdc, WIN_WIDTH, WIN_HEIGHT);
				HBITMAP oldbit = SelectBitmap(backDC, bit);

				BitBlt(backDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, _hdc, 0, 0, SRCCOPY);
				enemyImg->AniRender(backDC, enemyPokemon->m_data.m_number, m_EnemyMoveX + 128, m_EnemyMoveY + 32);
				SIZE s = enemyImg->GetSize();
				BitBlt(_hdc, m_EnemyMoveX + 128, 32, s.cx, s.cy, backDC, m_EnemyMoveX + 128, 32, SRCCOPY);
				DeleteObject(SelectBitmap(backDC, oldbit));
				DeleteDC(backDC);
			}
				

			//	ü��â
			enemyInfo->AniRender(_hdc, 0, m_EnemyInfo, 64);

			if (m_Type == BATTLE)
				myInfo->AniRender(_hdc, m_Ani, 504, 296);

			//	�� ���ϸ� (�̹���, ����â, �̸�, lv, hp, hpMax)
			enemyInfo->AniRender(_hdc, 0, m_EnemyInfo, 64);
			//	�̸�
			enemy.str("");
			enemy << enemyPokemon->m_data.m_name;
			m_Txt.TextBox(_hdc, m_EnemyInfo + 28, 88, enemy.str().c_str(), 30);
			//	Lv
			enemy.str("");
			enemy << enemyPokemon->m_level;
			m_Txt.TextBox(_hdc, m_EnemyInfo + 284, 88, enemy.str().c_str(), 30);
			enemy.str("");

			//	HP
			if (enemyPokemon->m_hp > 0)
			{
				float hp_perc = (float)enemyPokemon->m_hp / (float)enemyPokemon->m_hpMax;
				if (hp_perc > 0.5f)
				{
					IMG_MGR->GetImg("greenbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
				}
				else if (hp_perc > 0.2f)
				{
					IMG_MGR->GetImg("yellowbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
				}
				else
				{
					IMG_MGR->GetImg("redbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
				}
			}
			else
			{
				IMG_MGR->GetImg("redbar")->Render(_hdc, m_EnemyInfo + 156, 132, -1, 12);
			}
		}

		if (m_Type == INTRO)
		{
			//	�÷��̾�
			playerImg->AniRender(_hdc, m_playerAni, m_MyMoveX + 192 + m_playerExit, 192);
			//	���ͺ�
			if (m_playerAni > 2)
				ballImg->AniRender(_hdc, m_ballAni, 192, 192);
		}

		//	�� ���ϸ� (�̹���, ����â, �̸�, lv, hp, hpMax)
		int	PosY_My = 0;
		int	PosY_Name = 0;
		int	PosY_Hp = 0;

		if (m_myPokemon)
		{
			if (m_Ani == 1)
			{
				PosY_My = 192;
				PosY_Name = 324;
				PosY_Hp = 384;
			}
			else
			{
				PosY_My = 204;
				PosY_Name = 328;
				PosY_Hp = 388;
			}
			myInfo->AniRender(_hdc, m_Ani, 504, 296);

			myImg->AniRender(_hdc, POKEMON_MANAGER.GetSelectedBattlePokemon()->m_data.m_number, 160, PosY_My + m_MyMoveY);
			
			//	�̸�
			my.str("");
			my << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_data.m_name;
			m_Txt.TextBox(_hdc, 568, PosY_Name, my.str().c_str(), 30);
			//	Lv
			my.str("");
			my << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_level;
			m_Txt.TextBox(_hdc, 824, PosY_Name, my.str().c_str(), 30);
			//	Hp
			my.str("");
			my << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hp;
			m_Txt.TextBox(_hdc, 668, PosY_Hp, my.str().c_str(), 30);
			//	HpMax
			my.str("");
			my << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hpMax;
			m_Txt.TextBox(_hdc, 792, PosY_Hp, my.str().c_str(), 30);

			//	HP
			Pokemon tempPokemon;
			tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(0);
			if (tempPokemon.m_hp > 0)
			{
				float hp_perc = (float)tempPokemon.m_hp / (float)tempPokemon.m_hpMax;
				if (hp_perc > 0.5f)
				{
					IMG_MGR->GetImg("greenbar")->Render(_hdc, 696, PosY_Hp - 20, (hp_perc * 192), 12);
				}
				else if (hp_perc > 0.2f)
				{
					IMG_MGR->GetImg("yellowbar")->Render(_hdc, 696, PosY_Hp - 20, (hp_perc * 192), 12);
				}
				else
				{
					IMG_MGR->GetImg("redbar")->Render(_hdc, 696, PosY_Hp - 20, (hp_perc * 192), 12);
				}
			}
			else
			{
				IMG_MGR->GetImg("redbar")->Render(_hdc, 696, PosY_Hp - 20, -1, 12);
			}
		}

		//	���â
		BitBlt(_hdc, 0, 448, WIN_WIDTH, 192, m_BGDC1, 0, 0, SRCCOPY);

		std::stringstream	buf_1;
		std::stringstream	buf_2;
		std::stringstream	skillname;

		switch (m_Type)
		{
		case INTRO:
		{
			switch (m_dialogIndex)
			{
			case 0:
			{
			}break;
			case 1:
			{
				if (m_BattleTrainer == true)	// Ʈ���̳�
				{
					m_InputState = true;
					buf_1 << "���ڻ簡";
					buf_2 << "�ºθ� �ɾ�Դ�!";
				}
				else	// �߻�
				{
					m_InputState = true;
					buf_1 << "��! �߻���";
					buf_2 << POKEMON_MANAGER.GetWildPokemon()->m_data.m_name << "(��)��";
				}
			}break;
			case 2:
			{
				if (m_BattleTrainer == true)	// Ʈ���̳�
				{
					m_InputState = false;
					buf_1 << "���ڻ��";
					buf_2 << POKEMON_MANAGER.GetSelectedEnemyPokemon()->m_data.m_name << "��(��) ���´�";
				}
				else	// �߻�
				{
					m_InputState = true;
					buf_1 << POKEMON_MANAGER.GetWildPokemon()->m_data.m_name << "(��)��";
					buf_2 << "Ƣ��Դ�!";
				}
			}break;
			case 3:
			{
				//m_enemyPokemon = true;
				m_InputState = false;
				buf_1 << "����! " << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_data.m_name;
				buf_2 << "";
			}break;
			}
		}break;

		case BATTLE:
		{
			switch (m_dialogIndex)
			{
			case 0:
			{
				tempHP = 0;
				POKEMON_MANAGER.Unlock();
				m_InputState = true;
				buf_1 << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_data.m_name << "��(��)";
				buf_2 << "������ �ұ�?";

				//battleChoice->Render(_hdc, 544, 448);
				m_Box.BoxCreate(_hdc, 17, 14, 29, 19);
				m_Txt.TextBox(_hdc, 610, 490, "�ο��", 35);
				m_Txt.TextBox(_hdc, 770, 490, "����", 35);
				m_Txt.TextBox(_hdc, 610, 554, "���ϸ�", 35);
				m_Txt.TextBox(_hdc, 770, 554, "��������", 35);

				//	Ŀ�� �׸���
				switch (m_BattleCursor)
				{
				case 0: {	battleSelect->Render(_hdc, 580, 496); }break;
				case 1: {	battleSelect->Render(_hdc, 742, 496); }break;
				case 2: {	battleSelect->Render(_hdc, 580, 560); }break;
				case 3: {	battleSelect->Render(_hdc, 742, 560); }break;
				}
			}break;

			case 1:
			{
				m_InputState = true;
				//battleAttack->Render(_hdc, 0, 448);
				//	�޹�� �������� ���
				blackBg->Render(_hdc, 0, 452, WIN_WIDTH, 187);
				m_Box.BoxCreate(_hdc, 0, 14, 17, 19);
				m_Box.BoxCreate(_hdc, 18, 14, 29, 19);
				m_Txt.TextBox(_hdc, 608, 491, "PP", 35);
				m_Txt.TextBox(_hdc, 823, 499, "/", 35);
				m_Txt.TextBox(_hdc, 608, 555, "���Ÿ��", 35);
				m_Txt.TextBox(_hdc, 768, 563, "/", 35);

				//	��ų �̸�
				skillname.str("");
				skillname << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[0].m_name;
				m_Txt.TextBox(_hdc, 64, 490, skillname.str().c_str(), 40);

				skillname.str("");
				skillname << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[1].m_name;
				m_Txt.TextBox(_hdc, 320, 490, skillname.str().c_str(), 40);

				skillname.str("");
				skillname << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[2].m_name;
				m_Txt.TextBox(_hdc, 64, 554, skillname.str().c_str(), 40);

				skillname.str("");
				skillname << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[3].m_name;
				m_Txt.TextBox(_hdc, 320, 554, skillname.str().c_str(), 40);

				//	Ŀ�� �׸���
				switch (m_BattleCursor)
				{
				case 0: { battleSelect->Render(_hdc, 36, 496);	}break;
				case 1: { battleSelect->Render(_hdc, 292, 496); }break;
				case 2: { battleSelect->Render(_hdc, 36, 560); 	}break;
				case 3: { battleSelect->Render(_hdc, 292, 560); }break;
				}

				//	��ų ����
				//	���� PP
				skillname.str("");
				skillname << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[m_BattleCursor].m_PP;
				m_Txt.TextBox(_hdc, 768, 492, skillname.str().c_str(), 40);
				//	�ִ� PP
				skillname.str("");
				skillname << POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[m_BattleCursor].m_PP;
				m_Txt.TextBox(_hdc, 864, 492, skillname.str().c_str(), 40);
				//	���� TYPE
				skillname.str("");
				skillname << POKEDEX.GetType(POKEMON_MANAGER.GetSelectedBattlePokemon()->m_skill[m_BattleCursor].m_type);
				m_Txt.TextBox(_hdc, 800, 556, skillname.str().c_str(), 40);
			}break;

			case 2:
			{
				Pokemon* tmp = POKEMON_MANAGER.GetSelectedBattlePokemon();
				//	�� ���ϸ��� ����
				buf_1 << tmp->m_data.m_name << "��";
				buf_2 << tmp->m_skill[m_BattleCursor].m_name << "����!";

				if (!POKEMON_MANAGER.isLocked())
				{
					//	�󼺿� ���� ���������� ������
					float dmg = SKILL_MANAGER.GetDamageRate(tmp->m_skill[m_BattleCursor].m_type, enemyPokemon->m_data.m_type_1);	//	�ϴ� �����غ�
					if (enemyPokemon->m_data.m_type_1 != enemyPokemon->m_data.m_type_2)
						dmg *= SKILL_MANAGER.GetDamageRate(tmp->m_skill[m_BattleCursor].m_type, enemyPokemon->m_data.m_type_2);	//	�ϴ� �����غ�

					if (rand() % 1000 > 700)
					{
						m_Reaction = REACTION_CRITICAL;
						dmg *= 2;
						break;
					}
					if (dmg >= 2.0f)
					{
						m_Reaction = REACTION_GOOD;
					}
					else if (dmg >= 1.0f)
					{
						m_Reaction = REACTION_NORMAL;
					}
					else if (dmg <= 0.5f)
					{
						m_Reaction = REACTION_BAD;
					}
					else if ((int)dmg <= 0)
					{
						m_Reaction = REACTION_NO;
					}

					hpAniValue = enemyPokemon->m_hp;
					tempHP = enemyPokemon->m_hp;
					tempHP -= dmg * tmp->m_skill[m_BattleCursor].m_damage * 4;
					if (tempHP <= 0)
					{
						tempHP = 0;
					}
					if (tempHP > enemyPokemon->m_hpMax)
					{
						tempHP = enemyPokemon->m_hpMax;
					}

					hpPerTick = hpAniValue / 120;

					if (!m_effectPlaying)
					{
						SOUND_MGR.PlaySoundTrack(18);
						m_effectPlaying = true;
					}
					if(hpPerTick > 0)
					{
						POKEMON_MANAGER.Lock();
					}
				}				
			}break;

			//HP Animation
			case 3:
			{
				enemyPokemon->m_hp = tempHP;
				m_effectPlaying = false;
				if (hpAniValue >= enemyPokemon->m_hp)
				{
					BATTLE_MANAGER.Lock();
					float hp_perc = (float)hpAniValue / (float)enemyPokemon->m_hpMax;

					if (hp_perc > 0.5f)
					{
					IMG_MGR->GetImg("greenbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
					}
					else if (hp_perc > 0.2f)
					{
					IMG_MGR->GetImg("yellowbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
					}
					else
					{
					IMG_MGR->GetImg("redbar")->Render(_hdc, m_EnemyInfo + 156, 132, (hp_perc * 192), 12);
					}
				}
				else
				{
					BATTLE_MANAGER.Unlock();
				}
				
			}break;

			case 4:
			{
				
				//	�� ���ϸ��� ����ִٸ�
				if (enemyPokemon->m_hp > 0)
				{
					POKEMON_MANAGER.Unlock();
					//	�� ���ϸ��� ����
					buf_1 << enemyPokemon->m_data.m_name << "��";
					buf_2 << enemyPokemon->m_skill[m_BattleCursor].m_name << "����!";

					if (!POKEMON_MANAGER.isLocked())
					{
						//	�󼺿� ���� ���������� ������
						float dmg = SKILL_MANAGER.GetDamageRate(enemyPokemon->m_skill[m_BattleCursor].m_type, POKEMON_MANAGER.GetMyBattlePokemon(0).m_data.m_type_1);	//	�ϴ� �����غ�
						if (POKEMON_MANAGER.GetMyBattlePokemon(0).m_data.m_type_1 != POKEMON_MANAGER.GetMyBattlePokemon(0).m_data.m_type_2)
							dmg *= SKILL_MANAGER.GetDamageRate(enemyPokemon->m_skill[m_BattleCursor].m_type, POKEMON_MANAGER.GetMyBattlePokemon(0).m_data.m_type_2);	//	�ϴ� �����غ�

						if (rand() % 1000 > 700)
						{
							m_Reaction = REACTION_CRITICAL;
							dmg *= 2;
							break;
						}
						if (dmg >= 2.0f)
						{
							m_Reaction = REACTION_GOOD;
						}
						else if (dmg >= 1.0f)
						{
							m_Reaction = REACTION_NORMAL;
						}
						else if (dmg <= 0.5f)
						{
							m_Reaction = REACTION_BAD;
						}
						else if ((int) dmg <= 0)
						{
							m_Reaction = REACTION_NO;
						}

						hpAniValue = POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hp;
						tempHP = POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hp;
						//tempHP -= dmg * enemyPokemon->m_skill[m_BattleCursor].m_damage * 4;
						tempHP -= 200;

						if (tempHP <= 0)
						{
							tempHP = 0;
							m_Type = ENDBATTLE;
							lose = true;
						}

						hpPerTick = hpAniValue / 120;

						if (!m_effectPlaying)
						{
							SOUND_MGR.PlaySoundTrack(17);
							m_effectPlaying = true;
						}
						if (hpPerTick > 0)
						{
							POKEMON_MANAGER.Lock();
						}
					}
				}
				// �� ���ϸ��� �׾��ٸ�
				else 
				{
					SOUND_MGR.PlaySoundTrack(13);
					m_Type = SUMMARY;
				}
			}break;

			//HP Animation
			case 5:
			{
				m_effectPlaying = false;
				POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hp = tempHP;
				if (hpAniValue >= POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hp)
				{
					BATTLE_MANAGER.Lock();
					//	HP
					float hp_perc = (float)hpAniValue / (float)POKEMON_MANAGER.GetSelectedBattlePokemon()->m_hpMax;
					if (hp_perc > 0.5f)
					{
						IMG_MGR->GetImg("greenbar")->Render(_hdc, 696, PosY_Hp - 20, (hp_perc * 192), 12);
					}
					else if (hp_perc > 0.2f)
					{
						IMG_MGR->GetImg("yellowbar")->Render(_hdc, 696, PosY_Hp - 20, (hp_perc * 192), 12);
					}
					else
					{
						IMG_MGR->GetImg("redbar")->Render(_hdc, 696, PosY_Hp - 20, (hp_perc * 192), 12);
					}
				}
				else
				{
					BATTLE_MANAGER.Unlock();
				}
				
			}break;

			default:
			{
				m_dialogIndex = 0;
				BATTLE_MANAGER.Unlock();
			}break;
			}
		}break;

		case REACTION:
		{
			switch (m_Reaction)
			{
			case REACTION_CRITICAL:
			{
				buf_1 << "�޼ҿ� �¾Ҵ�!";
				buf_2 << "";
			}break;
			case REACTION_GOOD:
			{
				buf_1 << "ȿ���� �����ߴ�";
				buf_2 << "";
			}break;
			case REACTION_NORMAL:
			{
				buf_1 << "ȿ���� �־���";
				buf_2 << "";
			}break;
			case REACTION_BAD:
			{
				buf_1 << "ȿ���� ���ο���";
				buf_2 << "";
			}break;
			case REACTION_NO:
			{
				buf_1 << "ȿ���� ����";
				buf_2 << "";
			}break;
			}
			battleFlag = false;
			BATTLE_MANAGER.Unlock();
		}break;

		case CATCH:
		{
			if (m_ballAni == 8)
			{
				openBall->AniRender(_hdc, m_ballFrame, 676, m_ballMoveY + 204);
			}
			else
			{
				ballImg->AniRender(_hdc, m_ballAni, m_ballMoveX + 192, m_ballMoveY + 192);
			}
				
		}break;

		case SUMMARY:
		{
			BATTLE_MANAGER.Lock();
			if (m_EnemyMoveY > 200)
			{
				BATTLE_MANAGER.Unlock();
			}
		}break;
		case ENDBATTLE:
		{
			if (isCatch)
			{
				openBall->AniRender(_hdc, m_ballFrame, 676, m_ballMoveY + 204);
			}
			switch (m_dialogIndex)
			{
			case 1:
			{
				if (m_BattleTrainer)
				{
					buf_1.str("");
					buf_1 << "���ڻ���� �ο򿡼� �̰��!";
				}
				else
				{
					if (isCatch)
					{
						buf_1.str("");
						buf_1 << enemyPokemon->m_data.m_name << "��(��) ��Ҵ�!";
					}
					else
					{
						buf_1.str("");
						buf_1 << enemyPokemon->m_data.m_name << "��(��) �����߷ȴ�!";
					}
				}
			}break;

			case 2:
			{
				if (m_BattleTrainer)
				{
					buf_1.str("");
					buf_1 << "����� 2õ������ �����и� �����!";
				}
				else
				{
					if (isCatch)
					{
						POKEMON_MANAGER.CatchPokemon();
					}
					SCENE_MGR.SetMsg((void *)false);
					SCENE_MGR.CloseScene();
					BATTLE_MANAGER.EndBattle(!lose);
				}
			}break;

			case 3:
			{
				SCENE_MGR.SetMsg((void *)false);
				SCENE_MGR.CloseScene();
				BATTLE_MANAGER.EndBattle(!lose);
			}break;
			}
		}break;
		}

		m_Txt.TextBox(_hdc, 50, 490, buf_1.str().c_str(), 40, WHITE);
		m_Txt.TextBox(_hdc, 50, 550, buf_2.str().c_str(), 40, WHITE);
	}
}

bool Scene_Battle::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			if (m_Type == BATTLE)
			{
				if (m_dialogIndex <= 1)
				{
					if (m_BattleCursor == 2)
						m_BattleCursor = 0;
					else if (m_BattleCursor == 3)
						m_BattleCursor = 1;
				}
			}
		}break;
		case VK_DOWN:
		{
			if (m_Type == BATTLE)
			{
				if (m_dialogIndex <= 1)
				{
					if (m_BattleCursor == 0)
						m_BattleCursor = 2;
					else if (m_BattleCursor == 1)
						m_BattleCursor = 3;
				}
			}
		}break;
		case VK_LEFT:
		{
			if (m_Type == BATTLE)
			{
				if (m_dialogIndex <= 1)
				{
					if (m_BattleCursor == 1)
						m_BattleCursor = 0;
					else if (m_BattleCursor == 3)
						m_BattleCursor = 2;
				}
			}
		}break;
		case VK_RIGHT:
		{
			if (m_Type == BATTLE)
			{
				if (m_dialogIndex <= 1)
				{
					if (m_BattleCursor == 0)
						m_BattleCursor = 1;
					else if (m_BattleCursor == 2)
						m_BattleCursor = 3;
				}
			}
		}break;

		case 'z':
		case 'Z':
		{
			if (!BATTLE_MANAGER.isLocked())
			{
				SOUND_MGR.PlaySoundTrack(12);
				if (m_InputState)
				{
					if (m_Type == INTRO)
					{
						if (m_dialogIndex == 2)	m_playerAni = 1;
					}
					else if (m_Type == BATTLE)
					{
						if (m_dialogIndex == 0)
						{
							if (m_BattleCursor == 0)
							{
								m_dialogIndex++;
							}
							else if (m_BattleCursor == 1)
							{
								SCENE_MGR.OpenScene(SCENE_BAG);
							}								
							else if (m_BattleCursor == 2)
							{
								SCENE_MGR.SetBattle(true);
								SCENE_MGR.OpenScene(SCENE_POKEMON);
							}								
							else if (m_BattleCursor == 3)
							{
								SCENE_MGR.SetMsg((void *)false);
								SCENE_MGR.CloseScene();
								BATTLE_MANAGER.EndBattle(false);
							}
							break;
						}
						else if (m_dialogIndex == 3 || m_dialogIndex == 5)
						{
							m_BattleCursor = 0;
							m_Type = REACTION;
							break;
						}
					}
					else if (m_Type == REACTION)
					{
						m_Type = BATTLE;
					}
					else if (m_Type == SUMMARY)
					{
						m_dialogIndex = 0;
						m_Type = ENDBATTLE;
					}

					m_dialogIndex++;
				}
			}
		}break;

		case 'x':
		case 'X':
		{
			if (m_Type == BATTLE && m_dialogIndex != 0)
				m_dialogIndex--;
		}break;

		case 'b':
		case 'B': 
		{	
			SCENE_MGR.SetMsg((void *)false);
			SCENE_MGR.CloseScene();
			BATTLE_MANAGER.EndBattle(false);
		}break;

		case 'r':
		case 'R': {	POKEMON_MANAGER.GeneratePokemon(0); }break;

		case 'e':
		case 'E': {; }break;


		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}