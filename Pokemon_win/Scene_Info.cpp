#include "stdafx.h"
#include "Scene_Info.h"
#include "SceneMgr.h"


Scene_Info::Scene_Info()
{
	m_pokemonIndex = (int)(SCENE_MGR.GetMsg());
	if (SCENE_MGR.IsOnBattle())
	{
		m_Pokemon = POKEMON_MANAGER.GetMyBattlePokemon(m_pokemonIndex);
	}
	else
	{
		m_Pokemon = POKEMON_MANAGER.GetMyPokemon(m_pokemonIndex);
	}
	m_Atk = rand() % 100;
	m_Def = rand() % 100;
	m_sAtk = rand() % 100;
	m_sDef = rand() % 100;
	m_Speed = rand() % 100;
	m_Special[0] = POKEDEX.GetSpecial();
	m_Special[1] = POKEDEX.GetSpecial();
	m_Special[2] = POKEDEX.GetSpecial();
	m_Special[3] = POKEDEX.GetSpecial();
	m_Special[4] = POKEDEX.GetSpecial();
	m_Special[5] = POKEDEX.GetSpecial();
}


Scene_Info::~Scene_Info()
{
}

void Scene_Info::Init(HWND _hWnd)
{
}

void Scene_Info::Update(float _elapseTime)
{
}

void Scene_Info::Render(HDC _hdc)
{
	m_PokemonCount = POKEMON_MANAGER.GetPokemonCount();

	switch (m_InfoPage)
	{
	case 0:		//	포켓몬 정보
	{
		auto	backgroundImg = IMG_MGR->GetImg("Info_01");
		backgroundImg->Render(_hdc);
		
		std::stringstream	buf;
		
		//level
		buf << m_Pokemon.m_level;
		m_Txt.TextBox(_hdc, 60, 80, buf.str().c_str(), 40, WHITE);

		//name
		buf.str("");
		buf << m_Pokemon.m_nickname;
		m_Txt.TextBox(_hdc, 200, 80, buf.str().c_str(), 40, WHITE);
		m_Txt.TextBox(_hdc, 670, 140, buf.str().c_str(), 40);

		//poke num
		buf.str("");
		buf << m_Pokemon.m_data.m_number;
		m_Txt.TextBox(_hdc, 670, 84, buf.str().c_str(), 40);
		
		//type
		buf.str("");
		buf << POKEDEX.GetType(m_Pokemon.m_data.m_type_1);
		m_Txt.TextBox(_hdc, 670, 194, buf.str().c_str(), 40);

		buf.str("");
		buf << PLAYER_MANAGER.GetName();
		m_Txt.TextBox(_hdc, 670, 244, buf.str().c_str(), 40);

		buf.str("");
		buf << m_Num;
		m_Txt.TextBox(_hdc, 670, 294, buf.str().c_str(), 40);

		buf.str("");
		buf << "없음";
		m_Txt.TextBox(_hdc, 580, 394, buf.str().c_str(), 40);

	}break;

	case 1:		//	포켓몬 능력
	{
		auto	backgroundImg = IMG_MGR->GetImg("Info_02");
		backgroundImg->Render(_hdc);

		std::stringstream	buf;

		buf << m_Pokemon.m_level;
		m_Txt.TextBox(_hdc, 60, 80, buf.str().c_str(), 40, WHITE);

		buf.str("");
		buf << m_Pokemon.m_nickname;
		m_Txt.TextBox(_hdc, 200, 80, buf.str().c_str(), 40, WHITE);

		buf.str("");
		buf << m_Pokemon.m_hp;
		m_Txt.TextBox(_hdc, 710, 84, buf.str().c_str(), 40);

		buf.str("");
		buf << m_Pokemon.m_hpMax;
		m_Txt.TextBox(_hdc, 830, 84, buf.str().c_str(), 40);
				
		buf.str("");
		buf << m_Atk;
		m_Txt.TextBox(_hdc, 835, 158, buf.str().c_str(), 40);

		buf.str("");
		buf << m_Def;
		m_Txt.TextBox(_hdc, 835, 208, buf.str().c_str(), 40);

		buf.str("");
		buf << m_sAtk;
		m_Txt.TextBox(_hdc, 835, 262, buf.str().c_str(), 40);

		buf.str("");
		buf << m_sDef;
		m_Txt.TextBox(_hdc, 835, 312, buf.str().c_str(), 40);

		buf.str("");
		buf << m_Speed;
		m_Txt.TextBox(_hdc, 835, 364, buf.str().c_str(), 40);

		buf.str("");
		buf << m_Pokemon.m_currentExp;
		m_Txt.TextBox(_hdc, 720, 420, buf.str().c_str(), 40);

		buf.str("");
		buf << (m_Pokemon.m_requiredExp - m_Pokemon.m_currentExp);
		m_Txt.TextBox(_hdc, 720, 470, buf.str().c_str(), 40);

		buf.str("");
		buf << m_Special[m_pokemonIndex];
		m_Txt.TextBox(_hdc, 200, 534, buf.str().c_str(), 40);
	}break;

	case 2:		//	싸울 기술
	{
		auto	backgroundImg = IMG_MGR->GetImg("Info_03");
		auto	typeImg = IMG_MGR->GetImg("Type_01");
		backgroundImg->Render(_hdc);

		std::stringstream	buf;

		buf << m_Pokemon.m_level;
		m_Txt.TextBox(_hdc, 60, 80, buf.str().c_str(), 40, WHITE);

		buf.str("");
		buf << m_Pokemon.m_nickname;
		m_Txt.TextBox(_hdc, 200, 80, buf.str().c_str(), 40, WHITE);

		buf.str("");
		typeImg->AniRender(_hdc, m_Pokemon.m_skill[0].m_type, 492, 84); //atk type
		buf << m_Pokemon.m_skill[0].m_name;
		m_Txt.TextBox(_hdc, 646, 84, buf.str().c_str(), 40);
		buf.str("pp");
		m_Txt.TextBox(_hdc, 726, 138, buf.str().c_str(), 36);
		buf.str("");
		buf << m_Pokemon.m_skill[0].m_PP << " / " << m_Pokemon.m_skill[0].m_PP;
		m_Txt.TextBox(_hdc, 770, 140, buf.str().c_str(), 40);
		
		buf.str("");
		typeImg->AniRender(_hdc, m_Pokemon.m_skill[1].m_type, 492, 196);
		buf << m_Pokemon.m_skill[1].m_name;
		m_Txt.TextBox(_hdc, 646, 196, buf.str().c_str(), 40);
		buf.str("pp");
		m_Txt.TextBox(_hdc, 726, 250, buf.str().c_str(), 36);
		buf.str("");
		buf << m_Pokemon.m_skill[1].m_PP << " / " << m_Pokemon.m_skill[1].m_PP;
		m_Txt.TextBox(_hdc, 770, 252, buf.str().c_str(), 40);
		
		buf.str("");
		typeImg->AniRender(_hdc, m_Pokemon.m_skill[2].m_type, 492, 308);
		buf << m_Pokemon.m_skill[2].m_name;
		m_Txt.TextBox(_hdc, 646, 308, buf.str().c_str(), 40);
		buf.str("pp");
		m_Txt.TextBox(_hdc, 726, 362, buf.str().c_str(), 36);
		buf.str("");
		buf <<m_Pokemon.m_skill[2].m_PP << " / " << m_Pokemon.m_skill[2].m_PP;
		m_Txt.TextBox(_hdc, 770, 364, buf.str().c_str(), 40);
		
		buf.str("");
		typeImg->AniRender(_hdc, m_Pokemon.m_skill[3].m_type, 492, 420);
		buf << m_Pokemon.m_skill[3].m_name;
		m_Txt.TextBox(_hdc, 646, 420, buf.str().c_str(), 40);
		buf.str("pp");
		m_Txt.TextBox(_hdc, 726, 474, buf.str().c_str(), 36);
		buf.str("");
		buf << m_Pokemon.m_skill[3].m_PP << " / " << m_Pokemon.m_skill[3].m_PP;
		m_Txt.TextBox(_hdc, 770, 476, buf.str().c_str(), 40);

	}break;
	}

	auto pokemonImg = IMG_MGR->GetImg("pokemonImg_01");
	pokemonImg->AniRender(_hdc, m_Pokemon.m_data.m_number, 110, 110);
}

bool Scene_Info::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			if (m_pokemonIndex > 0)
			{
				m_pokemonIndex--;
			}
			else
			{
				m_pokemonIndex = m_PokemonCount - 1;
			}
			m_Pokemon = POKEMON_MANAGER.GetMyPokemon(m_pokemonIndex);
		}break;

		case VK_DOWN:
		{
			if (m_pokemonIndex < m_PokemonCount - 1)
			{
				m_pokemonIndex++;
			}
			else
			{
				m_pokemonIndex = 0;
			}
			m_Pokemon = POKEMON_MANAGER.GetMyPokemon(m_pokemonIndex);
		}break;

		case VK_LEFT:
		{
			m_InfoPage--;
			if (m_InfoPage < 0)
				m_InfoPage = 0;
		}break;

		case VK_RIGHT:
		{
			m_InfoPage++;
			if (m_InfoPage > 2)
				m_InfoPage = 2;
		}break;

		case 'x':
		case 'X': 
		{	
			SCENE_MGR.CloseScene();
			/*if(SCENE_MGR.IsOnBattle())
			{
				SCENE_MGR.CloseScene();
			}
			else
			{
				SCENE_MGR.SetScene(SCENE_POKEMON);
			}*/
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}
