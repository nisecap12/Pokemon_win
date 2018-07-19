#include "stdafx.h"
#include "NPC.h"

NPC::NPC()
{
}

NPC::~NPC()
{
}

NPC::NPC(int _function, int _direction, int _pattern, int _searchDistance, POINT _position, SIZE _moveBoxSize)
{
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

	//�ѹ��� �ֽ�
	case NPC_PATTERN::STARRING:
	{
		switch (m_direction)
		{
		case NPC_DIRECTION::UP:
		{
			//������ �̹��� ���
		}break;

		case NPC_DIRECTION::DOWN:
		{
			//�Ʒ����� �̹��� ���
		}break;

		case NPC_DIRECTION::LEFT:
		{
			//�޹��� �̹��� ���
		}break;

		case NPC_DIRECTION::RIGHT:
		{
			//�������� �̹��� ���
		}break;
		}
	}break;

	//�ð���� ��ȸ
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� �Ʒ���
				if (m_moveBox.cx == 1)
				{
					TurnDown();
				}
				//1�� �ƴ϶�� ����������
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� ����
				if (m_moveBox.cx == 1)
				{
					TurnUp();
				}
				//�ƴ϶�� ��������
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� ����������
				if (m_moveBox.cy == 1)
				{
					TurnRight();
				}
				//1�� �ƴ϶�� �����̵�
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� ��������
				if (m_moveBox.cy == 1)
				{
					TurnLeft();
				}
				//1�� �ƴ϶�� �Ʒ��� �̵�
				else
				{
					TurnDown();
					GoDown();
				}
			}
		}break;
		}
	}break;

	//�ݽð���� ��ȸ
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� �Ʒ���
				if (m_moveBox.cx == 1)
				{
					TurnDown();
				}
				//1�� �ƴ϶�� ��������
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� ����
				if (m_moveBox.cx == 1)
				{
					TurnUp();
				}
				//�ƴ϶�� ����������
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� ����������
				if (m_moveBox.cy == 1)
				{
					TurnRight();
				}
				//1�� �ƴ϶�� �Ʒ����̵�
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
				//���� �ൿ�ݰ��� ���� 1�϶��� �ٷ� ��������
				if (m_moveBox.cy == 1)
				{
					TurnLeft();
				}
				//1�� �ƴ϶�� ���� �̵�
				else
				{
					TurnUp();
					GoUp();
				}
			}
		}break;
		}
	}break;

	//���ۺ���
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
	//���ġ��
	//�ϴ��� ���
}

void NPC::DoAction()
{
	switch (m_function)
	{
	//�Ϲ� NPC
	case NPC_FUNCTION::NONE:
	{
		//������
		if (m_state == NPC_STATE::INTERACT)
		{
			//��ȭ UIȣ��
			DoScript();
		}
		else
		{
			DoPattern();
		}
	}break;

	//����NPC
	case NPC_FUNCTION::SHOP:
	{
		//����UI ȣ��
	}break;

	//���ϸ���
	case NPC_FUNCTION::HEAL:
	{
		//��ȣ�ۿ� ���̶��, ���ϸ� ġ��
		if (m_state == NPC_STATE::INTERACT)
		{

		}
	}break;

	//Ʈ���̳�
	case NPC_FUNCTION::TRAINER:
	{
		//Ʈ���̳� �ൿ
		//����
		if (m_state == NPC_STATE::NORMAL)
		{
			//������ ���ְų� �Դٰ���
		}
		//���� ����
		else if (m_state == NPC_STATE::ENCOUNTER)
		{
			//�������� �޷���
		}
		//��ȣ�ۿ� ��
		else
		{
			//���ġ�� ��Ʋ ����
		}
	}break;

	//ü���� ����
	case NPC_FUNCTION::CHAMP:
	{}break;
	}
}
