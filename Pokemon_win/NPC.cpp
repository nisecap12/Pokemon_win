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
	//�ѹ��� �ֽ�
	case NPC_PATTERN::STARRING:
	{

	}break;

	//�Դٰ���
	case NPC_PATTERN::BACK_AND_FORTH:
	{

	}break;

	//���ۺ���
	case NPC_PATTERN::TURNING:
	{

	}break;

	//�ð���� ��ȸ
	case NPC_PATTERN::TURN_ARROUND_CLOCKWISE:
	{

	}break;

	//�ݽð���� ��ȸ
	case NPC_PATTERN::TURN_ARROUND_COUNTER_CLOCKWISE:
	{

	}break;

	//���� �Ѿư�
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
		//������
	}break;
	case NPC_FUNCTION::SHOP:
	{
		//����UI ȣ��
	}break;
	case NPC_FUNCTION::HEAL:
	{
		//��ȣ�ۿ� ���̶��, ���ϸ� ġ��
		if (m_state == NPC_STATE::INTERACT)
		{

		}
	}break;
	case NPC_FUNCTION::TRAINER:
	{
		//Ʈ���̳� �ൿ
		//����
		if (m_state == NPC_STATE::NONE)
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
	case NPC_FUNCTION::CHAMP:
	{}break;
	}
}
