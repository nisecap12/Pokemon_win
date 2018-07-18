#pragma once

/*
NPC �ൿ
1. �Ϲ� NPC
�� ���� �ֽ��ϴٰ� ���ɸ� ĳ���͸� �Ĵٺ��� ��ũ��Ʈ ���
*/

//NPC ���
enum NPC_FUNCTION 
{
	NONE,		//�Ϲ�
	HEAL,		//���ϸ���
	SHOP,		//����
	TRAINER,	//�Ϲ� Ʈ���̳�
	CHAMP,		//ü���� ����
};

//NPC ����
enum NPC_STATE
{
	NORMAL,		//�Ϲ�
	ENCOUNTER,	//����
	INTERACT,	//��ȣ�ۿ�
};

//NPC ����
enum NPC_DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

//NPC �ൿ����
enum NPC_PATTERN
{
	STARRING, //�ֽ�
	TURN_ARROUND_CLOCKWISE, //�ֺ� �ð���� ���ۺ��� ��ȸ
	TURN_ARROUND_COUNTER_CLOCKWISE, //�ݽð���� ��ȸ
	TURNING, //���ڸ� ���ۺ���
	CHASE, //�Ѿƿ�
};

class NPC
{
private:
	int m_number;			//NPC ��ȣ
	int m_function;			//���
	int m_searchDistance;	//Ž���Ÿ�
	int m_state;			//����
	POINT m_rootPosition;	 //NPC ����ġ (NPC�� ���� ������ �ǵ��ư������� �ʿ���, �ʿ������������)
	POINT m_position;		//NPC ��ġ��ǥ
	int m_direction;
	int m_pattern;			//NPC ����
	SIZE m_moveBox;			//NPC �ൿ �ڽ�ũ��
	POINT m_moveBoxPosition; //�ൿ�ڽ� ��ǥ
	int m_actionDelay;
	int m_actionCount;

	int m_x_max; //�� width
	int m_y_max; //�� height

private:
	void GoLeft();
	void GoRight();
	void GoUp();
	void GoDown();
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
	void DoPattern();
	void DoScript();

public:
	NPC();
	NPC(int _function, int _direction, int _pattern, int _searchDistance, POINT _position, SIZE _moveBoxSize);
	~NPC();

	int GetState()
	{
		return m_state;
	}
	void SetState(int _state)
	{
		m_state = _state;
	}

	POINT GetPosition()
	{
		return m_position;
	}

	void SetPosition(POINT _position)
	{
		m_position = _position;
	}

	void SetActionDelay(int _delay)
	{
		m_actionDelay = _delay;
	}

	void DoAction();

	void Render(HDC _hdc)
	{
		Rectangle(_hdc, (m_position.x * 64), (m_position.y * 64), (m_position.x * 64) + 64, (m_position.y * 64) + 64);
		std::stringstream s;
		s << m_direction;
		TextOut(_hdc, (m_position.x * 64)+12, (m_position.y * 64)+12, s.str().c_str(), s.str().length());
	}
};

