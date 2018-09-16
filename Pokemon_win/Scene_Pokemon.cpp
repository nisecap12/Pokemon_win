#include "stdafx.h"
#include "Scene_Pokemon.h"
#include "SceneMgr.h"

Scene_Pokemon::Scene_Pokemon()
{
	m_BGDC = IMG_MGR->GetImg("Pokemon_00")->GetImgDC();
}

Scene_Pokemon::~Scene_Pokemon()
{
}

void Scene_Pokemon::Init(HWND _hWnd)
{
	m_isBattle = SCENE_MGR.IsOnBattle();
}

void Scene_Pokemon::Update(float _elapseTime)
{
}

void Scene_Pokemon::Render(HDC _hdc)
{
	BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, m_BGDC, 0, 0, SRCCOPY);
	auto focusImg1	= IMG_MGR->GetImg("Pokemon_01");
	auto focusImg2	= IMG_MGR->GetImg("Pokemon_02");
	auto focusImg3	= IMG_MGR->GetImg("Pokemon_03");
	auto changeImg1	= IMG_MGR->GetImg("PokemonChange_01");
	auto changeImg2 = IMG_MGR->GetImg("PokemonChange_02");

	//	���ϰ� �ִ� ���ϸ� ���� ��Ŀ�̿��� ��°��� �پ��� �ٲٱ�
	m_PokemonCount = POKEMON_MANAGER.GetPokemonCount();

	//	��Ŀ��
	switch (m_PokemonSelect)
	{
	case 0:
	{
		if (m_isChange == false)
			focusImg1->AniRender(_hdc, 1, 8, 72);
		else
			changeImg1->AniRender(_hdc, 1, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (m_isCheck[i] == true)
				changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
			else
				focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 0, 736, 528);
	}break;

	case 1:
	{
		if(m_isCheck[0] == false)
			focusImg1->AniRender(_hdc, 0, 8, 72);
		else
			changeImg1->AniRender(_hdc, 0, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (i == m_PokemonSelect)
				if (m_isChange == false)
					focusImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
				else
					changeImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
			else
				if (m_isCheck[i] == true)
					changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
				else
					focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 0, 736, 528);
	}break;
	
	case 2:
	{
		if (m_isCheck[0] == false)
			focusImg1->AniRender(_hdc, 0, 8, 72);
		else
			changeImg1->AniRender(_hdc, 0, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (i == m_PokemonSelect)
				if (m_isChange == false)
					focusImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
				else
					changeImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
			else
				if (m_isCheck[i] == true)
					changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
				else
					focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 0, 736, 528);
	}break;
	
	case 3:
	{
		if (m_isCheck[0] == false)
			focusImg1->AniRender(_hdc, 0, 8, 72);
		else
			changeImg1->AniRender(_hdc, 0, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (i == m_PokemonSelect)
				if(m_isChange == false)
					focusImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
				else
					changeImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
			else
				if (m_isCheck[i] == true)
					changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
				else
					focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 0, 736, 528);
	}break;
	
	case 4:
	{
		if (m_isCheck[0] == false)
			focusImg1->AniRender(_hdc, 0, 8, 72);
		else
			changeImg1->AniRender(_hdc, 0, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (i == m_PokemonSelect)
				if (m_isChange == false)
					focusImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
				else
					changeImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
			else
				if (m_isCheck[i] == true)
					changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
				else
					focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 0, 736, 528);
	}break;
	
	case 5:
	{
		if (m_isCheck[0] == false)
			focusImg1->AniRender(_hdc, 0, 8, 72);
		else
			changeImg1->AniRender(_hdc, 0, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (i == m_PokemonSelect)
				if (m_isChange == false)
					focusImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
				else
					changeImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
			else
				if (m_isCheck[i] == true)
					changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
				else
					focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 0, 736, 528);
	}break;

	case 6:
	{
		if (m_isCheck[0] == false)
			focusImg1->AniRender(_hdc, 0, 8, 72);
		else
			changeImg1->AniRender(_hdc, 0, 8, 72);

		for (int i = 1; i < m_PokemonCount; i++)
		{
			if (i == m_PokemonSelect)
				if (m_isChange == false)
					focusImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
				else
					changeImg2->AniRender(_hdc, 1, 352, (96 * (i - 1)) + 36);
			else
				if (m_isCheck[i] == true)
					changeImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
				else
					focusImg2->AniRender(_hdc, 0, 352, (96 * (i - 1)) + 36);
		}
		focusImg3->AniRender(_hdc, 1, 736, 528);
	}break;
	}

	Pokemon tempPokemon;

	//���ϸ� �̹��� ��ºκ�

	if (m_isBattle)
	{
		tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(0);
	}
	else
	{
		tempPokemon = POKEMON_MANAGER.GetMyPokemon(0);
	}
	
	auto pokemonImg = IMG_MGR->GetImg("pokemonImg_03");

	pokemonImg->AniRenderXY(_hdc, tempPokemon.m_data.m_number, m_PokemonAnim, 35, 90);

	for (int i = 1; i < m_PokemonCount; i++)
	{
		if (m_isBattle)
		{
			tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(i);
		}
		else
		{
			tempPokemon = POKEMON_MANAGER.GetMyPokemon(i);
		}
		
		pokemonImg->AniRenderXY(_hdc, tempPokemon.m_data.m_number, m_PokemonAnim, 385, 5 + ((i - 1) * 96));
	}

	if (m_animCount > 30)
	{
		if (m_PokemonAnim)
		{
			m_PokemonAnim = 0;
		}
		else
		{
			m_PokemonAnim = 1;
		}
		m_animCount = 0;
	}
	else
	{
		m_animCount++;
	}


	//���ϸ� HP ��� �κ�
	if (m_isBattle)
	{
		tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(0);
	}
	else
	{
		tempPokemon = POKEMON_MANAGER.GetMyPokemon(0);
	}
	
	float hp_perc = (float)tempPokemon.m_hp / (float)tempPokemon.m_hpMax;
	if (hp_perc > 0.5f)
	{
		IMG_MGR->GetImg("greenbar")->Render(_hdc, 128, 236, (hp_perc * 192.0f), 12);
	}
	else if (hp_perc > 0.2f)
	{
		IMG_MGR->GetImg("yellowbar")->Render(_hdc, 128, 236, (hp_perc * 192.0f), 12);
	}
	else
	{
		IMG_MGR->GetImg("redbar")->Render(_hdc, 128, 236, (hp_perc * 192.0f), 12);
	}

	for (int i = 1; i < m_PokemonCount; i++)
	{
		if (m_isBattle)
		{
			tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(i);
		}
		else
		{
			tempPokemon = POKEMON_MANAGER.GetMyPokemon(i);
		}
		hp_perc = (float)tempPokemon.m_hp / (float)tempPokemon.m_hpMax;
		if (hp_perc > 0.5f)
		{
			IMG_MGR->GetImg("greenbar")->Render(_hdc, 736, 72 + ((i - 1) * 96), (hp_perc * 192.0f), 12);
		}
		else if (hp_perc > 0.2f)
		{
			IMG_MGR->GetImg("yellowbar")->Render(_hdc, 736, 72 + ((i - 1) * 96), (hp_perc * 192.0f), 12);
		}
		else
		{
			IMG_MGR->GetImg("redbar")->Render(_hdc, 736, 72 + ((i - 1) * 96), (hp_perc * 192.0f), 12);
		}
	}

	//���ϸ� ���� ��ºκ�
	std::stringstream buf;

	if (m_isBattle)
	{
		tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(0);
	}
	else
	{
		tempPokemon = POKEMON_MANAGER.GetMyPokemon(0);
	}
	buf << tempPokemon.m_level;
	m_Txt.TextBox(_hdc, 200, 185, buf.str().c_str(), 40, WHITE);

	buf.str("");
	buf << tempPokemon.m_hp;
	m_Txt.TextBox(_hdc, 115, 255, buf.str().c_str(), 30, WHITE);

	buf.str("");
	buf << tempPokemon.m_hpMax;
	m_Txt.TextBox(_hdc, 222, 255, buf.str().c_str(), 30, WHITE);

	buf.str("");
	buf << tempPokemon.m_nickname;
	m_Txt.TextBox(_hdc, 150, 130, buf.str().c_str(), 40, WHITE);

	for (int i = 1; i < m_PokemonCount; i++)
	{
		if (m_isBattle)
		{
			tempPokemon = POKEMON_MANAGER.GetMyBattlePokemon(i);
		}
		else
		{
			tempPokemon = POKEMON_MANAGER.GetMyPokemon(i);
		}
		buf.str("");
		buf << tempPokemon.m_level;
		m_Txt.TextBox(_hdc, 550, 89 + ((i - 1) * 96), buf.str().c_str(), 40, WHITE);

		buf.str("");
		buf << tempPokemon.m_hp;
		m_Txt.TextBox(_hdc, 720, 94 + ((i - 1) * 96), buf.str().c_str(), 30, WHITE);

		buf.str("");
		buf << tempPokemon.m_hpMax;
		m_Txt.TextBox(_hdc, 830, 94 + ((i - 1) * 96), buf.str().c_str(), 30, WHITE);

		buf.str("");
		buf << tempPokemon.m_nickname;
		m_Txt.TextBox(_hdc, 510, 50 + ((i - 1) * 96), buf.str().c_str(), 30, WHITE);
	}

	//	���� == false
	if (m_isClick == false && m_isChange == false)
	{
		m_Box.BoxCreate(_hdc, 0, 16, 22, 19);
		m_Txt.TextBox(_hdc, 42, (64 * 8) + 44, "���ϸ��� ������ �ֽʽÿ�", 40);
		m_Txt.TextBox(_hdc, 820, (64 * 8) + 44, "���", 40, WHITE);
	}

	if (m_isChange == true)
	{
		m_Box.BoxCreate(_hdc, 0, 16, 22, 19);
		m_Txt.TextBox(_hdc, 42, (64 * 8) + 44, "���� �̵��ұ�?", 40);
		m_Txt.TextBox(_hdc, 820, (64 * 8) + 44, "���", 40, WHITE);
	}

	//	���� == true
	if (m_isClick == true)
	{
		m_Box.BoxCreate(_hdc, 0, 16, 18, 19);
		std::stringstream name;
		if (m_isBattle)
		{
			name << POKEMON_MANAGER.GetMyBattlePokemon(m_PokemonSelect).m_nickname << " ����ұ�";
		}
		else
		{
			name << POKEMON_MANAGER.GetMyPokemon(m_PokemonSelect).m_nickname << " ����ұ�";
		}
		
		m_Txt.TextBox(_hdc, 42, (64 * 8) + 44, name.str().c_str(), 40);
		//	�������϶��� �ٲ۴�, ���º���, �׸��δ� 3����
		if (m_isBattle == true)
		{
			m_Box.BoxCreate(_hdc, 19, 12, 29, 19, 3, true);
			m_Txt.TextBox(_hdc, 665, (64 * 6) + 30, "�ٲ۴�", 40);
			m_Txt.TextBox(_hdc, 665, (64 * 7) + 30, "���º���", 40);
			m_Txt.TextBox(_hdc, 665, (64 * 8) + 30, "�׸��δ�", 40);
		}
		else
		{
			//	�����ӽ� ��� ��� ���� ũ�� �ٸ�
			m_Box.BoxCreate(_hdc, 19, 10, 29, 19, 4, true);
			m_Txt.TextBox(_hdc, 665, (64 * 5) + 30, "���º���", 40);
			m_Txt.TextBox(_hdc, 665, (64 * 6) + 30, "��������", 40);
			m_Txt.TextBox(_hdc, 665, (64 * 7) + 30, "���ѹ���", 40);
			m_Txt.TextBox(_hdc, 665, (64 * 8) + 30, "�׸��δ�", 40);
		}
	}
}

bool Scene_Pokemon::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			if (m_isClick == false)
			{
				m_PokemonSelect--;
				if (m_PokemonSelect < 0)
					m_PokemonSelect = 6;
				else if (m_PokemonSelect > m_PokemonCount)
					m_PokemonSelect = m_PokemonCount - 1;
			}
			else
			{
				m_isSelect--;
				if (m_isSelect < 1)
					m_isSelect = 4;
			}
		}break;

		case VK_DOWN:
		{
			if (m_isClick == false)
			{
				m_PokemonSelect++;
				if (m_PokemonSelect == m_PokemonCount)
					m_PokemonSelect = 6;
				else if (m_PokemonSelect == 7)
					m_PokemonSelect = 0;
			}
			else
			{
				m_isSelect++;
				if (m_isSelect > 4)
					m_isSelect = 1;
			}
		}break;

		case 'z':
		case 'Z':
		{
			SOUND_MGR.PlaySoundTrack(12);
			if (m_isChange == true)
			{
				m_isChange = false;
				m_isClick = false;
				m_Box.m_Select = 0;

				//	��� ������ �ƴ϶��
				if (m_PokemonSelect != 6)
				{
					int index = 0;
					for (int i = 0; i < 6; i++)
					{
						if (m_isCheck[i] == true)
						{
							index = i;
							//	���� �ٲٴ� �ڵ� �̰���
							//	�迭 ���� ã�Ƽ� true�� ���� ���� ���õ� ��ü�� ���ϸ�
							//	temp�ϳ� ����� ���� �ڸ��� �ٲ��ָ� ��
						}
					}
					Pokemon* list = POKEMON_MANAGER.GetMyPokemonList();
					Pokemon temp = list[index];
					list[index] = list[m_PokemonSelect];
					list[m_PokemonSelect] = temp;
				}
				//	�ʱ�ȭ
				for (int i = 0; i < 6; i++)
				{
					m_isCheck[i] = false;
				}
				break;
			}
			if (m_PokemonSelect == 6)
			{
				if (m_isBattle)
				{
					SCENE_MGR.CloseScene();
				}
				else
				{
					//SCENE_MGR.SetScene(SCENE_MENU);
					SCENE_MGR.CloseScene();
				}
			}
				
			if (m_isClick)
			{
				if (m_isBattle)
				{
					switch (m_isSelect)
					{
					case 1: //�ٲ۴�
					{
						if (m_isDialog)
						{
							SCENE_MGR.RemoveDialogBox();
							m_isDialog = false;
						}
						else
						{
							if (m_PokemonSelect != POKEMON_MANAGER.GetSelectedPokemonNumber())
							{
								POKEMON_MANAGER.SwapPokemon(m_PokemonSelect);
								//POKEMON_MANAGER.SetSelectedMyPokemon(m_PokemonSelect);
								SCENE_MGR.CloseScene();
							}
							else
							{
								std::stringstream buf;
								buf << POKEMON_MANAGER.GetMyBattlePokemon(0).m_nickname << "��(��) �̹� �������̴�!";
								SCENE_MGR.CreateDialogBox(buf.str());
								m_isDialog = true;
							}
						}
					}break;
					case 2: //���º���
					{				
						SCENE_MGR.SetMsg((void *)m_PokemonSelect);
						SCENE_MGR.OpenScene(SCENE_INFO);
						m_Box.m_Select = 0;
						m_isSelect = 1;
						m_isClick = false;
					}break;
					case 3: //�׸��δ�
					{
						m_isClick = false;
						m_Box.m_Select = 0;
					}break;
					}
				}
				else
				{
					if (m_isSelect == 1)	//	���º���
					{
						m_Box.m_Select = 0;
						SCENE_MGR.SetMsg((void *)m_PokemonSelect);
						SCENE_MGR.OpenScene(SCENE_INFO);
					}
					if (m_isSelect == 2)	//	��������
					{
						m_isChange = true;
						m_isClick = false;
						m_isCheck[m_PokemonSelect] = true;
						m_Box.m_Select = 0;
					}
					if (m_isSelect == 3)	//	���ѹ���
					{
						m_Box.m_Select = 0;
					}
					if (m_isSelect == 4)	//	�׸��δ�
					{
						m_isClick = false;
						m_Box.m_Select = 0;
					}
				}
			}
			else
			{
				m_isClick = true;
				m_isSelect = 1;
			}
			
			
		}break;

		case 'x':
		case 'X': 
		{	
			if (m_isBattle)
			{
				if (m_isClick)
				{
					if (!m_isDialog)
					{
						m_isClick = false;
						m_isSelect = 1;
					}
				}
				else
				{
					SCENE_MGR.CloseScene();
				}
			}
			else
			{
				if (m_isClick == true)
				{
					m_isClick = false;
					m_Box.m_Select = 0;
				}
				else
				{
					//SCENE_MGR.SetScene(SCENE_MENU);
					SCENE_MGR.CloseScene();
				}
					
			}
		}break;

		case 'b':
		case 'B': {	m_isBattle = !m_isBattle; }break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}