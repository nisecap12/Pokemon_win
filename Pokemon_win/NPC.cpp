#include "stdafx.h"
#include "NPC.h"


void NPC::GoLeft()
{
	if (m_position.x > 0)
	{
		m_position.x--;
	}		
}

void NPC::GoRight()
{
	if (m_position.x < m_x_max)
	{
		m_position.x++;
	}
}

void NPC::GoUp()
{
	if (m_position.y > 0)
	{
		m_position.y--;
	}	
}

void NPC::GoDown()
{
	if (m_position.y < m_y_max)
	{
		m_position.y++;
	}
}

void NPC::TurnUp()
{
	m_direction = NPC_DIRECTION::UP;
}

void NPC::TurnDown()
{
	m_direction = NPC_DIRECTION::DOWN;
}

void NPC::TurnLeft()
{
	m_direction = NPC_DIRECTION::LEFT;
}

void NPC::TurnRight()
{
	m_direction = NPC_DIRECTION::RIGHT;
}

void NPC::DoPattern()
{
	switch (m_pattern)
	{
	//한방향 주시
	case NPC_PATTERN::STARRING:
	{

	}break;

	//왔다갔다
	case NPC_PATTERN::BACK_AND_FORTH:
	{

	}break;

	//빙글빙글
	case NPC_PATTERN::TURNING:
	{

	}break;

	//시계방향 배회
	case NPC_PATTERN::TURN_ARROUND_CLOCKWISE:
	{

	}break;

	//반시계방향 배회
	case NPC_PATTERN::TURN_ARROUND_COUNTER_CLOCKWISE:
	{

	}break;

	//유저 쫓아감
	case NPC_PATTERN::CHASE:
	{

	}break;
	}
}

void NPC::DoScript()
{
}

NPC::NPC()
{
}


NPC::~NPC()
{
}

void NPC::DoAction()
{
	switch (m_function)
	{
	case NPC_FUNCTION::NONE:
	{
		//대사출력
	}break;
	case NPC_FUNCTION::SHOP:
	{
		//상점UI 호출
	}break;
	case NPC_FUNCTION::HEAL:
	{
		//상호작용 중이라면, 포켓몬 치료
		if (m_state == NPC_STATE::INTERACT)
		{

		}
	}break;
	case NPC_FUNCTION::TRAINER:
	{
		//트레이너 행동
		//평상시
		if (m_state == NPC_STATE::NONE)
		{
			//가만히 서있거나 왔다갔다
		}
		//유저 조우
		else if (m_state == NPC_STATE::ENCOUNTER)
		{
			//유저한테 달려옴
		}
		//상호작용 중
		else
		{
			//대사치고 배틀 시작
		}
	}break;
	case NPC_FUNCTION::CHAMP:
	{}break;
	}
}
