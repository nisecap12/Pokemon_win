#pragma once

enum NPC_FUNCTION
{
	NONE,		//�Ϲ�
	HEAL,		//���ϸ���
	SHOP,		//����
	TRAINER,	//�Ϲ� Ʈ���̳�
	CHAMP,		//ü���� ����
};

enum NPC_STATE
{
	NONE,		//�Ϲ�
	ENCOUNTER,	//����
	INTERACT,	//��ȣ�ۿ�
};

class NPC
{
private:
	int m_number;			//NPC ��ȣ
	int m_function;			//���
	int m_searchDistance;	//Ž���Ÿ�
	int m_state;			//����

public:
	NPC();
	~NPC();

public:
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

