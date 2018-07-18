#pragma once

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
	NONE,		//�Ϲ�
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
	BACK_AND_FORTH, //�Դٰ���
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
	POINT m_rootPosition;	 //NPC ����ġ
	POINT m_position;		//NPC ��ġ��ǥ
	int m_direction;
	int m_pattern;			//NPC ����
	int m_move_point;		//�ൿ ����Ʈ 

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
	~NPC();

	int GetState()
	{
		return m_state;
	}
	void SetState(int _state)
	{
		m_state = _state;
	}
	void DoAction();
};

