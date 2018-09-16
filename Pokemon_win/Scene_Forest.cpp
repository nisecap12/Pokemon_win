#include "stdafx.h"
#include "Scene_Forest.h"


Scene_Forest::Scene_Forest()
{
}

Scene_Forest::~Scene_Forest()
{
}

void Scene_Forest::Init(HWND _hWnd)
{
	MAP_MANAGER.SetMapNumber(1);
	PLAYER_MANAGER.SetPosition({ MAP_MANAGER.GetStartTile().x, MAP_MANAGER.GetStartTile().y });
	MAP_MANAGER.SetStart(PLAYER_MANAGER.GetPosition());
}

void Scene_Forest::Update(float _elapseTime)
{
	if (SCENE_MGR.GetEnter())
	{
		SCENE_MGR.SetEnter(false);
		SOUND_MGR.PlaySoundTrack(7);
	}
	if (isEnter)
	{
		m_time += _elapseTime;
		if (m_time >= 2.0f)
		{
			m_time = 0.0f;
			isEnter = false;
			SOUND_MGR.PlaySoundTrack(7);
		}
		else
		{
			fadeAlpha -= 2;
		}
	}
	else
	{
		NPC_MANAGER.Update(_elapseTime);
		MAP_MANAGER.BushUpdate(_elapseTime);

		if (PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.Update(_elapseTime);
			MAP_MANAGER.Update(_elapseTime);
		}

		if (PLAYER_MANAGER.IsControlActivated())
		{
			//상하좌우 이동
			if (KEY_MANAGER.StayKeyDown(VK_UP))
			{
				if (!PLAYER_MANAGER.isMoving())
				{
					PLAYER_MANAGER.SetDirection(DIRECTION::UP);
				}
			}
			if (KEY_MANAGER.StayKeyDown(VK_DOWN))
			{
				if (!PLAYER_MANAGER.isMoving())
				{
					PLAYER_MANAGER.SetDirection(DIRECTION::DOWN);
				}
			}
			if (KEY_MANAGER.StayKeyDown(VK_LEFT))
			{
				if (!PLAYER_MANAGER.isMoving())
				{
					PLAYER_MANAGER.SetDirection(DIRECTION::LEFT);
				}
			}
			if (KEY_MANAGER.StayKeyDown(VK_RIGHT))
			{
				if (!PLAYER_MANAGER.isMoving())
				{
					PLAYER_MANAGER.SetDirection(DIRECTION::RIGHT);
				}
			}

			if (!PLAYER_MANAGER.isMoving())
			{
				// 자전거 타기/내리기
				if (KEY_MANAGER.OnceKeyDown('C'))
				{
					if (!m_rideBike)
					{
						PLAYER_MANAGER.SetPlayerState(PLAYER_STATE::RIDE_BIKE);
						TIMER.SetTimeUnit(0.2f);
						m_rideBike = true;
					}
					else
					{
						m_rideBike = false;
					}
				}
				// 달리기
				else if (KEY_MANAGER.StayKeyDown('X'))
				{
					PLAYER_MANAGER.SetPlayerState(PLAYER_STATE::RUN);
					TIMER.SetTimeUnit(0.25f);
				}
				else
				{
					if (!m_rideBike)
					{
						PLAYER_MANAGER.SetPlayerState(PLAYER_STATE::WALK);
						TIMER.SetTimeUnit(0.5f);
					}
				}
			}

			if (KEY_MANAGER.OnceKeyDown('Z'))
			{
				POINT pos = PLAYER_MANAGER.GetPosition();
				int number;

				switch (PLAYER_MANAGER.GetDirection())
				{
				case DIRECTION::UP:
				{
					number = NPC_MANAGER.CheckSelectNPC({ pos.x, pos.y - 1 });
					if (number >= 0)
					{
						//npc interact
						NPC_MANAGER.GetNPCList()[number]->SetState(NPC_STATE::INTERACT);
						NPC_MANAGER.GetNPCList()[number]->SetDirection(DIRECTION::DOWN);
						NPC_MANAGER.GetNPCList()[number]->StopNPC();
					}
				}break;
				case DIRECTION::DOWN:
				{
					number = NPC_MANAGER.CheckSelectNPC({ pos.x, pos.y + 1 });
					if (number >= 0)
					{
						//npc interact
						NPC_MANAGER.GetNPCList()[number]->SetState(NPC_STATE::INTERACT);
						NPC_MANAGER.GetNPCList()[number]->SetDirection(DIRECTION::UP);
						NPC_MANAGER.GetNPCList()[number]->StopNPC();
					}
				}break;
				case DIRECTION::LEFT:
				{
					number = NPC_MANAGER.CheckSelectNPC({ pos.x - 1, pos.y });
					if (number >= 0)
					{
						//npc interact
						NPC_MANAGER.GetNPCList()[number]->SetState(NPC_STATE::INTERACT);
						NPC_MANAGER.GetNPCList()[number]->SetDirection(DIRECTION::RIGHT);
						NPC_MANAGER.GetNPCList()[number]->StopNPC();
					}
				}break;
				case DIRECTION::RIGHT:
				{
					number = NPC_MANAGER.CheckSelectNPC({ pos.x + 1, pos.y });
					if (number >= 0)
					{
						//npc interact
						NPC_MANAGER.GetNPCList()[number]->SetState(NPC_STATE::INTERACT);
						NPC_MANAGER.GetNPCList()[number]->SetDirection(DIRECTION::LEFT);
						NPC_MANAGER.GetNPCList()[number]->StopNPC();
					}
				}break;
				}
			}
		}
	}
}

bool debugOn = false;
void Scene_Forest::Render(HDC _hdc)
{
	if (isEnter)
	{
		HBRUSH brush = CreateSolidBrush(BLACK);
		HBRUSH oldBrush = SelectBrush(_hdc, brush);
		Rectangle(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT);

		BLENDFUNCTION bf = {};
		bf.SourceConstantAlpha = fadeAlpha;
		GdiAlphaBlend(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, SCENE_MGR.GetScreen(), 0, 0, WIN_WIDTH, WIN_HEIGHT, bf);

		DeleteBrush(SelectBrush(_hdc, oldBrush));
	}
	else
	{
		MAP_MANAGER.Render(_hdc);
		MAP_MANAGER.RoadRender(_hdc);
		NPC_MANAGER.AreaRender(_hdc);
		MAP_MANAGER.DrawGrid(_hdc);

		int halfW = WIN_WIDTH / 2;
		int halfH = WIN_HEIGHT / 2;

		RENDER_MANAGER.Render(_hdc);

		if (debugOn)
		{
			TIMER.Render(_hdc, 0, 0);
			std::stringstream cam;
			POINT camPos = MAP_MANAGER.GetCamPosition();
			cam << "맵넘버 :" << MAP_MANAGER.GetMapNumber() << " = " << camPos.x << ", " << camPos.y;
			TextOut(_hdc, 0, 30, cam.str().c_str(), cam.str().length());

			cam.str("");
			Skill testSkill = SKILL_MANAGER.GetSkill(0);
			cam << testSkill.m_name << " - 위력 : " << testSkill.m_damage << ", 명중률 : " << testSkill.m_accuracy;
			TextOut(_hdc, 0, 50, cam.str().c_str(), cam.str().length());

			cam.str("");
			cam << "player pos : " << PLAYER_MANAGER.GetPosition().x << ", " << PLAYER_MANAGER.GetPosition().y;
			TextOut(_hdc, 0, 70, cam.str().c_str(), cam.str().length());

			cam.str("");
			cam << POKEDEX.GetPokemonData(2).m_name << ", " << POKEDEX.GetPokemonData(2).m_type_1;
			TextOut(_hdc, 0, 90, cam.str().c_str(), cam.str().length());

			Pokemon * tempPoke = POKEMON_MANAGER.GetWildPokemon();
			cam << tempPoke->m_data.m_name << " - " << tempPoke->m_skill[0].m_name
				<< " , " << tempPoke->m_skill[1].m_name
				<< " , " << tempPoke->m_skill[2].m_name
				<< " , " << tempPoke->m_skill[3].m_name;
			TextOut(_hdc, 0, 110, cam.str().c_str(), cam.str().length());

			cam.str("");
			Pokemon* tpoke = &POKEMON_MANAGER.GetMyPokemon(0);
			cam << tpoke->m_data.m_name << " - Lv." << tpoke->m_level
				<< " " << tpoke->m_skill[0].m_name << " " << tpoke->m_skill[1].m_name
				<< " " << tpoke->m_skill[2].m_name << " " << tpoke->m_skill[3].m_name;
			TextOut(_hdc, 0, 130, cam.str().c_str(), cam.str().length());

			TextOut(_hdc, m_mousePos.x, m_mousePos.y, m_posStr.str().c_str(), m_posStr.str().length());

			cam.str("");
			cam << PLAYER_MANAGER.GetRenderPosition().x << ", " << PLAYER_MANAGER.GetRenderPosition().y;
			TextOut(_hdc, 0, 150, cam.str().c_str(), cam.str().length());

			TextOut(_hdc, m_mousePos.x, m_mousePos.y, m_posStr.str().c_str(), m_posStr.str().length());
		}

	}
	SCENE_MGR.SetScreen(_hdc);
}

bool Scene_Forest::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{

	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case 'O':
		{
			if (debugOn)
			{
				debugOn = false;
			}
			else
			{
				debugOn = true;
			}
		}break;
		case VK_RETURN:
		{
			if (PLAYER_MANAGER.IsControlActivated())
			{
				SCENE_MGR.SetScreen(GetDC(_hWnd));
				SCENE_MGR.OpenScene(SCENE_MENU);
			}
		}break;

		case VK_ESCAPE: {PostQuitMessage(0); }break;
		}
	}break;

	}
	return false;
}
