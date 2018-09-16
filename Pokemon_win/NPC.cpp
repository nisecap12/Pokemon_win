#include "stdafx.h"
#include "NPC.h"

NPC::NPC()
{
}

NPC::~NPC()
{
}

NPC::NPC(int _number, int _mapNumber, int _function, int _direction, int _pattern, int _searchDistance, POINT _position, SIZE _moveBoxSize)
{
	m_number = _number;
	m_function = _function;
	m_searchDistance = _searchDistance;
	m_direction = _direction;
	m_mapNumber = _mapNumber;

	m_step = STEP::R_FEET;
	m_position = _position;
	m_prevPosition = _position;
	m_rootPosition.x = _position.x * MAP_TILE_SIZE;
	m_rootPosition.y = _position.y * MAP_TILE_SIZE;
	m_realPosition.x = _position.x * MAP_TILE_SIZE;
	m_realPosition.y = _position.y * MAP_TILE_SIZE;
	m_moveBox = _moveBoxSize;
	m_moveBoxPosition = { 0,0 };
	m_state = NPC_STATE::NPC_NORMAL;
	m_pattern = _pattern;
	m_animationTime = 0.0f;
	m_scriptListSize = SCRIPT_MANAGER.GetScript(m_number).size();
	for (int i = 0; i < m_scriptListSize; i++)
	{
		m_scriptList[i] = SCRIPT_MANAGER.GetScript(m_number)[i];
	}
}

void NPC::GoLeft()
{
	POINT playerPos = PLAYER_MANAGER.GetPosition();
	if (playerPos.x != m_position.x - 1 || playerPos.y != m_position.y)
	{
		if (m_step == STEP::L_FEET)
		{
			m_step = STEP::R_FEET;
		}
		else
		{
			m_step = STEP::L_FEET;
		}
		m_isMoving = true;
		m_position.x--;
		m_moveBoxPosition.x--;
	}
	else if (playerPos.y == m_position.y && playerPos.x == m_position.x - 1)
	{
		if (m_state == NPC_STATE::COMING)
		{
			m_state = NPC_STATE::INTERACT;
		}
	}
	m_realPosition.x = m_position.x * MAP_TILE_SIZE;
	m_realPosition.y = m_position.y * MAP_TILE_SIZE;
}

void NPC::GoRight()
{
	POINT playerPos = PLAYER_MANAGER.GetPosition();
	if (playerPos.x != m_position.x + 1 || playerPos.y != m_position.y)
	{
		if (m_step == STEP::L_FEET)
		{
			m_step = STEP::R_FEET;
		}
		else
		{
			m_step = STEP::L_FEET;
		}
		m_isMoving = true;
		m_position.x++;
		m_moveBoxPosition.x++;
	}
	else if (playerPos.x == m_position.x + 1 && playerPos.y == m_position.y)
	{
		if (m_state == NPC_STATE::COMING)
		{
			m_state = NPC_STATE::INTERACT;
		}
	}
	m_realPosition.x = m_position.x * MAP_TILE_SIZE;
	m_realPosition.y = m_position.y * MAP_TILE_SIZE;
}

void NPC::GoUp()
{
	POINT playerPos = PLAYER_MANAGER.GetPosition();
	if (playerPos.x != m_position.x || playerPos.y != m_position.y - 1)
	{
		if (m_step == STEP::L_FEET)
		{
			m_step = STEP::R_FEET;
		}
		else
		{
			m_step = STEP::L_FEET;
		}
		m_isMoving = true;
		m_position.y--;
		m_moveBoxPosition.y--;
	}
	else if(playerPos.x == m_position.x && playerPos.y == m_position.y - 1)
	{
		if (m_state == NPC_STATE::COMING)
		{
			m_state = NPC_STATE::INTERACT;
		}
	}
	m_realPosition.x = m_position.x * MAP_TILE_SIZE;
	m_realPosition.y = m_position.y * MAP_TILE_SIZE;
}

void NPC::GoDown()
{
	POINT playerPos = PLAYER_MANAGER.GetPosition();
	if (playerPos.x != m_position.x || playerPos.y != m_position.y + 1)
	{
		if (m_step == STEP::L_FEET)
		{
			m_step = STEP::R_FEET;
		}
		else
		{
			m_step = STEP::L_FEET;
		}
		m_isMoving = true;
		m_position.y++;
		m_moveBoxPosition.y++;
	}
	else if (playerPos.x == m_position.x && playerPos.y == m_position.y + 1)
	{
		if (m_state == NPC_STATE::COMING)
		{
			m_state = NPC_STATE::INTERACT;
		}
	}
	m_realPosition.x = m_position.x * MAP_TILE_SIZE;
	m_realPosition.y = m_position.y * MAP_TILE_SIZE;
}

void NPC::TurnUp()
{
	m_direction = DIRECTION::UP;
}

void NPC::TurnDown()
{
	m_direction = DIRECTION::DOWN;
}

void NPC::TurnLeft()
{
	m_direction = DIRECTION::LEFT;
}

void NPC::TurnRight()
{
	m_direction = DIRECTION::RIGHT;
}

void NPC::DoPattern()
{
	m_prevPosition = m_position;

	switch (m_pattern)
	{

	//�ѹ��� �ֽ�
	case NPC_PATTERN::STARRING:
	{
		switch (m_direction)
		{
		case DIRECTION::UP:
		{
			//������ �̹��� ���
			TurnUp();
		}break;

		case DIRECTION::DOWN:
		{
			//�Ʒ����� �̹��� ���
			TurnDown();
		}break;

		case DIRECTION::LEFT:
		{
			//�޹��� �̹��� ���
			TurnLeft();
		}break;

		case DIRECTION::RIGHT:
		{
			//�������� �̹��� ���
			TurnRight();
		}break;
		}
	}break;

	//�ð���� ��ȸ
	case NPC_PATTERN::TURN_ARROUND_CLOCKWISE:
	{
		switch (m_direction)
		{
		case DIRECTION::UP:
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

		case DIRECTION::DOWN:
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

		case DIRECTION::LEFT:
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

		case DIRECTION::RIGHT:
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
		case DIRECTION::UP:
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

		case DIRECTION::DOWN:
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

		case DIRECTION::LEFT:
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

		case DIRECTION::RIGHT:
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
		case DIRECTION::UP:
			TurnUp();
			break;
		case DIRECTION::DOWN:
			TurnDown();
			break;
		case DIRECTION::LEFT:
			TurnLeft();
			break;
		case DIRECTION::RIGHT:
			TurnRight();
			break;
		}
	}break;

	case NPC_PATTERN::RANDOM:
	{
		int direction = rand() % 4;
		switch (direction)
		{
		case DIRECTION::UP:
		{
			if (m_moveBoxPosition.y > 0)
			{
				TurnUp();
				GoUp();
			}
		}break;
		case DIRECTION::DOWN:
		{
			if(m_moveBoxPosition.y < m_moveBox.cy - 1)
			{ 
				TurnDown();
				GoDown();
			}
		}break;
		case DIRECTION::LEFT:
		{
			if (m_moveBoxPosition.x > 0)
			{
				TurnLeft();
				GoLeft();
			}
		}break;
		case DIRECTION::RIGHT:
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

void NPC::DoScript(std::string _text)
{
	//��ȭâ UIȣ��
	//��ȭâ�� ��� ���
	SCENE_MGR.CreateDialogBox(_text);
	//onHandler(_text);
	isTalking = true;
}

void NPC::StopScript()
{
	SCENE_MGR.RemoveDialogBox();
	//stopHandler();
	m_currentScript = 0;
}

void NPC::GoNextScript()
{
	if (isTalking)
	{
		m_currentScript++;
	}
}

bool NPC::CheckPlayer()
{
	POINT playerPos = PLAYER_MANAGER.GetPosition();
	int dist;
	switch (m_direction)
	{
	case DIRECTION::UP:
	{
		dist = m_position.y - playerPos.y;
		if (playerPos.x == m_position.x &&  dist <= m_searchDistance && dist > 0)
		{
			return true;
		}
	}break;
	case DIRECTION::DOWN:
	{
		dist = playerPos.y - m_position.y;
		if (playerPos.x == m_position.x &&  dist <= m_searchDistance && dist > 0)
		{
			return true;
		}
	}break;
	case DIRECTION::LEFT:
	{
		dist = m_position.x - playerPos.x;
		if (playerPos.y == m_position.y &&  dist <= m_searchDistance && dist > 0)
		{
			return true;
		}
	}break;
	case DIRECTION::RIGHT:
	{
		dist = playerPos.x - m_position.x;
		if (playerPos.y == m_position.y &&  dist <= m_searchDistance && dist > 0)
		{
			return true;
		}
	}break;

	}
	
	return false;
}

void NPC::StopNPC()
{
	m_prevPosition = m_position;
	NPC_MANAGER.SetActiveNPC(m_number);
	PLAYER_MANAGER.SetControlActivate(false);
}

bool bgmPlaying = false;
void NPC::DoAction(float _elapseTime)
{
	m_animationTime += _elapseTime;
	
	
	if (m_animationTime >= 0.5f)
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
				if (m_currentScript < m_scriptListSize)
				{
					DoScript(m_scriptList[m_currentScript]);
				}
				else
				{
					//��������
					StopScript();

					//Ȱ��ȭ �ڵ�
					NPC_MANAGER.RestartNPC();
					PLAYER_MANAGER.SetControlActivate(true);
					m_state = NPC_STATE::NPC_NORMAL;
				}
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
			if (m_state == NPC_STATE::NPC_NORMAL)
			{
				//������ ���ְų� �Դٰ���
				if (!hasBattled)
				{
					if (CheckPlayer())
					{
						m_state = NPC_STATE::ENCOUNTER;
						m_prevPosition = m_position;
						NPC_MANAGER.SetActiveNPC(m_number);
						PLAYER_MANAGER.SetControlActivate(false);
					}
					else
					{
						DoPattern();
					}
				}
			}
			//���� ����
			else if (m_state == NPC_STATE::ENCOUNTER)
			{
				m_state = NPC_STATE::COMING;
				SOUND_MGR.StopSoundTrack();
				SOUND_MGR.PlaySoundTrack(9);
			}
			//������ ������
			else if (m_state == NPC_STATE::COMING)
			{
				if (!bgmPlaying)
				{
					SOUND_MGR.PlaySoundTrack(8);
					bgmPlaying = true;
				}
				
				m_prevPosition = m_position;
				//�������� �޷���
				switch (m_direction)
				{
				case DIRECTION::UP:
				{
					GoUp();
				}break;
				case DIRECTION::DOWN:
				{
					GoDown();
				}break;
				case DIRECTION::LEFT:
				{
					GoLeft();
				}break;
				case DIRECTION::RIGHT:
				{
					GoRight();
				}break;
				}
			}
			//��ȣ�ۿ� ��
			else if (m_state == NPC_STATE::INTERACT)
			{
				if (hasBattled)
				{
					if (m_currentScript < 1)
					{
						DoScript("���� ���� ���ٴ�....");
					}
					else
					{
						StopScript();
						m_state = NPC_STATE::NPC_NORMAL;
						NPC_MANAGER.RestartNPC();
						PLAYER_MANAGER.SetControlActivate(true);
					}
				}
				else
				{
					//���ġ�� 
					if (m_currentScript < m_scriptListSize)
					{
						DoScript(m_scriptList[m_currentScript]);
					}
					else
					{
						//��������
						StopScript();

						//��Ʋ ����
						BATTLE_MANAGER.StartBattle(m_number, true);
						hasBattled = true;

						//Ȱ��ȭ �ڵ�
						NPC_MANAGER.RestartNPC();
						PLAYER_MANAGER.SetControlActivate(true);
						m_state = NPC_STATE::FINISHED;
					}
				}
			}
		}break;

		//ü���� ����
		case NPC_FUNCTION::CHAMP:
		{}break;
		}

		m_animationTime -= 0.5f;

	}
	else if (m_animationTime >= 0.25f)
	{
		m_isMoving = false;
	}
	
	
	float value = m_animationTime / 0.5f;

	if (m_direction < 2)
	{
		if (m_prevPosition.y != m_position.y)
		{
			if (m_direction == DIRECTION::UP)
				m_realPosition.y = (LONG)((m_prevPosition.y - value) * MAP_TILE_SIZE);
			else
				m_realPosition.y = (LONG)((m_prevPosition.y + value) * MAP_TILE_SIZE);
		}
	}
	else
	{
		if (m_prevPosition.x != m_position.x)
		{
			if (m_direction == DIRECTION::LEFT)
				m_realPosition.x = (LONG)((m_prevPosition.x - value) * MAP_TILE_SIZE);
			else
				m_realPosition.x = (LONG)((m_prevPosition.x + value) * MAP_TILE_SIZE);
		}
	}
}
