#include "stdafx.h"
#include "PlayerManager.h"
#include "Pokemon.h"

float yOffset = 0.0f;

PlayerManager::PlayerManager()
{
	m_sex = MALE;
	m_name = "ทนตๅ";
	m_money = 100;
	m_badgeCount = 0;
	m_animationTime = 0.0f;
	m_step = STEP::NO_FEET;
	m_prevStep = STEP::R_FEET;
	m_renderPosition = { (WIN_WIDTH / 2) - 40 , (WIN_HEIGHT / 2) + MAP_TILE_SIZE - HERO_HEIGHT };
}

PlayerManager::~PlayerManager()
{
	Release();
}

void PlayerManager::GoUp()
{
	if (m_prevStep == STEP::L_FEET)
	{
		m_step = STEP::R_FEET;
		m_prevStep = STEP::R_FEET;
	}
	else
	{
		m_step = STEP::L_FEET;
		m_prevStep = STEP::L_FEET;
	}
	m_nextPosition.y--;
	m_isMoving = true;
}

void PlayerManager::GoDown()
{
	if (m_prevStep == STEP::L_FEET)
	{
		m_step = STEP::R_FEET;
		m_prevStep = STEP::R_FEET;
	}
	else
	{
		m_step = STEP::L_FEET;
		m_prevStep = STEP::L_FEET;
	}
	m_currentPosition.y++;
	m_nextPosition.y++;
	m_isMoving = true;
}

void PlayerManager::GoLeft()
{
	if (m_prevStep == STEP::L_FEET)
	{
		m_step = STEP::R_FEET;
		m_prevStep = STEP::R_FEET;
	}
	else
	{
		m_step = STEP::L_FEET;
		m_prevStep = STEP::L_FEET;
	}
	m_nextPosition.x--;
	m_isMoving = true;
}

void PlayerManager::GoRight()
{
	if (m_prevStep == STEP::L_FEET)
	{
		m_step = STEP::R_FEET;
		m_prevStep = STEP::R_FEET;
	}
	else
	{
		m_step = STEP::L_FEET;
		m_prevStep = STEP::L_FEET;
	}
	m_nextPosition.x++;
	m_isMoving = true;
}

ImgClass * PlayerManager::GetPlayerImage()
{
	return &m_image;
}

void PlayerManager::Init(HWND _hWnd)
{
	m_image.LoadImg(_hWnd, "Images/player.bmp");
	m_image.SetFrame(12,3);
	m_image.SetTrans(true, TRANS_COLOR);
}

void PlayerManager::Release()
{
}

std::string PlayerManager::GetName()
{
	return m_name;
}

void PlayerManager::SetName(std::string _name)
{
	m_name = _name;
}

bool PlayerManager::GetSex()
{
	return m_sex;
}

void PlayerManager::SetSex(bool _sex)
{
	m_sex = _sex;
}

short PlayerManager::GetBadgeCount()
{
	return m_badgeCount;
}

void PlayerManager::IncreaseBadge()
{
	if (m_badgeCount != 8)
	{
		m_badgeCount++;
	}
}

int PlayerManager::GetMoney()
{
	return m_money;
}

void PlayerManager::SetMoney(int _money)
{
	m_money = _money;
}

void PlayerManager::Update(float _elapseTime)
{
	m_animationTime += _elapseTime;
	float value = m_animationTime / TIMER.GetTimeUnit();

	if (m_animationTime >= TIMER.GetTimeUnit() )
	{
		m_animationTime -= TIMER.GetTimeUnit();
		m_currentPosition = m_nextPosition;
		if (m_wildEncountered)
		{
			BATTLE_MANAGER.StartBattle(0, false);
			m_wildEncountered = false;
		}
	}
	else if (m_animationTime >= TIMER.GetTimeUnit()/2)
	{
		m_step = STEP::NO_FEET;
	}

}

void PlayerManager::Render(HDC _hdc)
{
	short xPoint = m_direction + (4 * m_step);

	m_image.AniRenderXY(_hdc, xPoint, m_state, m_renderPosition.x, m_renderPosition.y);
}

void PlayerManager::SetDirection(short _direction)
{
	m_direction = _direction;
	POINT nextPos;
	switch (_direction)
	{
	case DIRECTION::UP:
	{
		nextPos = { m_currentPosition.x , m_currentPosition.y - 1 };
		if (!NPC_MANAGER.CheckNPCPosition(nextPos))
		{
			if (MAP_MANAGER.IsWalkable(nextPos))
			{
				GoUp();
				MAP_MANAGER.MoveUp();
				MAP_MANAGER.IsPortal(nextPos);
				m_isMoving = true;
			}
		}
	}break;
	case DIRECTION::DOWN:
	{
		nextPos = { m_currentPosition.x , m_currentPosition.y + 1 };
		if (!NPC_MANAGER.CheckNPCPosition(nextPos))
		{
			if (MAP_MANAGER.IsWalkable(nextPos))
			{
				GoDown();
				MAP_MANAGER.MoveDown();
				MAP_MANAGER.IsPortal(nextPos);
				m_isMoving = true;
			}
		}
	}break;
	case DIRECTION::LEFT:
	{
		nextPos = { m_currentPosition.x - 1, m_currentPosition.y };
		if (!NPC_MANAGER.CheckNPCPosition(nextPos))
		{
			if (MAP_MANAGER.IsWalkable(nextPos))
			{
				GoLeft();
				MAP_MANAGER.MoveLeft();
				MAP_MANAGER.IsPortal(nextPos);
				m_isMoving = true;
			}
		}
	}break;
	case DIRECTION::RIGHT:
	{
		nextPos = { m_currentPosition.x + 1, m_currentPosition.y };
		if (!NPC_MANAGER.CheckNPCPosition(nextPos))
		{
			if (MAP_MANAGER.IsWalkable(nextPos))
			{				
				GoRight();
				MAP_MANAGER.MoveRight();
				MAP_MANAGER.IsPortal(nextPos);
				m_isMoving = true;
			}
		}
	}break;
	}

	MAP_MANAGER.SetInteractTile(nextPos);
	if (MAP_MANAGER.IsBush(nextPos))
	{
		if (rand() % 1000 > 900)
		{
			m_wildEncountered = true;
		}
	}
}

bool PlayerManager::isMoving()
{
	return m_isMoving;
}

void PlayerManager::SetIsMoving(bool _isMoving)
{
	m_isMoving = _isMoving;
}

void PlayerManager::SetPlayerState(short _state)
{
	m_state = _state;
}

short PlayerManager::GetPlayerState()
{
	return m_state;
}

POINT PlayerManager::GetPosition()
{
	return m_currentPosition;
}

void PlayerManager::SetPosition(POINT _position)
{
	m_currentPosition = _position;
	m_nextPosition = _position;
}

void PlayerManager::SetData(POINT _pos, short _direction, short _badge, int _money)
{
	m_currentPosition = _pos;
	m_nextPosition = _pos;
	m_direction = _direction;
	if (_badge < 0 || _badge > 8)
	{
		m_badgeCount = 0;
	}
	else
	{
		m_badgeCount = _badge;
	}

	m_money = _money;
}

bool PlayerManager::IsControlActivated()
{
	return m_controlActivated;
}
