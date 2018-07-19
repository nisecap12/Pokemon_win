#include "stdafx.h"
#include "NPC.h"

NPC::NPC()
{
}

NPC::~NPC()
{
}

NPC::NPC(int _number, int _function, int _direction, int _pattern, int _searchDistance, POINT _position, SIZE _moveBoxSize)
{
	m_number = _number;
	m_function = _function;
	m_searchDistance = _searchDistance;
	m_direction = _direction;
	m_position = _position;
	m_moveBox = _moveBoxSize;
	m_moveBoxPosition = { 0,0 };
	m_state = NPC_STATE::NORMAL;
	m_pattern = _pattern;
}

void NPC::GoLeft()
{
	m_position.x--;
	m_moveBoxPosition.x--;	
}

void NPC::GoRight()
{
	m_position.x++;
	m_moveBoxPosition.x++;
}

void NPC::GoUp()
{
	m_position.y--;
	m_moveBoxPosition.y--;
}

void NPC::GoDown()
{
	m_position.y++;
	m_moveBoxPosition.y++;
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
		switch (m_direction)
		{
		case NPC_DIRECTION::UP:
		{
			//위방향 이미지 출력
		}break;

		case NPC_DIRECTION::DOWN:
		{
			//아래방향 이미지 출력
		}break;

		case NPC_DIRECTION::LEFT:
		{
			//왼방향 이미지 출력
		}break;

		case NPC_DIRECTION::RIGHT:
		{
			//오른방향 이미지 출력
		}break;
		}
	}break;

	//시계방향 배회
	case NPC_PATTERN::TURN_ARROUND_CLOCKWISE:
	{
		switch (m_direction)
		{
		case NPC_DIRECTION::UP:
		{
			if (m_moveBoxPosition.y > 0)
			{
				GoUp();
			}
			else
			{
				//가로 행동반경이 폭이 1일때는 바로 아래로
				if (m_moveBox.cx == 1)
				{
					TurnDown();
				}
				//1이 아니라면 오른쪽으로
				else
				{
					TurnRight();
					GoRight();
				}
			}
		}break;

		case NPC_DIRECTION::DOWN:
		{
			if (m_moveBoxPosition.y < m_moveBox.cy - 1)
			{
				GoDown();
			}
			else
			{
				//가로 행동반경이 폭이 1일때는 바로 위로
				if (m_moveBox.cx == 1)
				{
					TurnUp();
				}
				//아니라면 왼쪽으로
				else
				{
					TurnLeft();
					GoLeft();
				}
			}
		}break;

		case NPC_DIRECTION::LEFT:
		{
			if (m_moveBoxPosition.x > 0)
			{
				GoLeft();
			}
			else
			{
				//세로 행동반경이 폭이 1일때는 바로 오른쪽으로
				if (m_moveBox.cy == 1)
				{
					TurnRight();
				}
				//1이 아니라면 위로이동
				else
				{
					TurnUp();
					GoUp();
				}
			}
		}break;

		case NPC_DIRECTION::RIGHT:
		{
			if (m_moveBoxPosition.x < m_moveBox.cx - 1)
			{
				GoRight();
			}
			else
			{
				//세로 행동반경이 폭이 1일때는 바로 왼쪽으로
				if (m_moveBox.cy == 1)
				{
					TurnLeft();
				}
				//1이 아니라면 아래로 이동
				else
				{
					TurnDown();
					GoDown();
				}
			}
		}break;
		}
	}break;

	//반시계방향 배회
	case NPC_PATTERN::TURN_ARROUND_COUNTER_CLOCKWISE:
	{
		switch (m_direction)
		{
		case NPC_DIRECTION::UP:
		{
			if (m_moveBoxPosition.y > 0)
			{
				GoUp();
			}
			else
			{
				//가로 행동반경이 폭이 1일때는 바로 아래로
				if (m_moveBox.cx == 1)
				{
					TurnDown();
				}
				//1이 아니라면 왼쪽으로
				else
				{
					TurnLeft();
					GoLeft();
				}
			}
		}break;

		case NPC_DIRECTION::DOWN:
		{
			if (m_moveBoxPosition.y < m_moveBox.cy - 1)
			{
				GoDown();
			}
			else
			{
				//가로 행동반경이 폭이 1일때는 바로 위로
				if (m_moveBox.cx == 1)
				{
					TurnUp();
				}
				//아니라면 오른쪽으로
				else
				{
					TurnRight();
					GoRight();
				}
			}
		}break;

		case NPC_DIRECTION::LEFT:
		{
			if (m_moveBoxPosition.x > 0)
			{
				GoLeft();
			}
			else
			{
				//세로 행동반경이 폭이 1일때는 바로 오른쪽으로
				if (m_moveBox.cy == 1)
				{
					TurnRight();
				}
				//1이 아니라면 아래로이동
				else
				{
					TurnDown();
					GoDown();
				}
			}
		}break;

		case NPC_DIRECTION::RIGHT:
		{
			if (m_moveBoxPosition.x < m_moveBox.cx - 1)
			{
				GoRight();
			}
			else
			{
				//세로 행동반경이 폭이 1일때는 바로 왼쪽으로
				if (m_moveBox.cy == 1)
				{
					TurnLeft();
				}
				//1이 아니라면 위로 이동
				else
				{
					TurnUp();
					GoUp();
				}
			}
		}break;
		}
	}break;

	//빙글빙글
	case NPC_PATTERN::TURNING:
	{
		int direction = rand() % 4;
		switch (direction)
		{
		case NPC_DIRECTION::UP:
			TurnUp();
			break;
		case NPC_DIRECTION::DOWN:
			TurnDown();
			break;
		case NPC_DIRECTION::LEFT:
			TurnLeft();
			break;
		case NPC_DIRECTION::RIGHT:
			TurnRight();
			break;
		}
	}break;

	case NPC_PATTERN::RANDOM:
	{
		int direction = rand() % 4;
		switch (direction)
		{
		case NPC_DIRECTION::UP:
		{
			if (m_moveBoxPosition.y > 0)
			{
				TurnUp();
				GoUp();
			}
		}break;
		case NPC_DIRECTION::DOWN:
		{
			if(m_moveBoxPosition.y < m_moveBox.cy - 1)
			{ 
				TurnDown();
				GoDown();
			}
		}break;
		case NPC_DIRECTION::LEFT:
		{
			if (m_moveBoxPosition.x > 0)
			{
				TurnLeft();
				GoLeft();
			}
		}break;
		case NPC_DIRECTION::RIGHT:
		{
			if (m_moveBoxPosition.x < m_moveBox.cx - 1)
			{
				TurnRight();
				GoRight();
			}
		}break;
		}
	}break;

	}
}

void NPC::DoScript()
{
	//대사치고
	//하던일 계속
}

void NPC::DoAction()
{
	switch (m_function)
	{
	//일반 NPC
	case NPC_FUNCTION::NONE:
	{
		//대사출력
		if (m_state == NPC_STATE::INTERACT)
		{
			//대화 UI호출
			DoScript();
		}
		else
		{
			DoPattern();
		}
	}break;

	//상점NPC
	case NPC_FUNCTION::SHOP:
	{
		//상점UI 호출
	}break;

	//포켓몬센터
	case NPC_FUNCTION::HEAL:
	{
		//상호작용 중이라면, 포켓몬 치료
		if (m_state == NPC_STATE::INTERACT)
		{

		}
	}break;

	//트레이너
	case NPC_FUNCTION::TRAINER:
	{
		//트레이너 행동
		//평상시
		if (m_state == NPC_STATE::NORMAL)
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

	//체육관 관장
	case NPC_FUNCTION::CHAMP:
	{}break;
	}
}
