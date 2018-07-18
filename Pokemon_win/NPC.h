#pragma once

enum NPC_FUNCTION
{
	NONE,		//일반
	HEAL,		//포켓몬센터
	SHOP,		//상점
	TRAINER,	//일반 트레이너
	CHAMP,		//체육관 관장
};

enum NPC_STATE
{
	NONE,		//일반
	ENCOUNTER,	//조우
	INTERACT,	//상호작용
};

class NPC
{
private:
	int m_number;			//NPC 번호
	int m_function;			//기능
	int m_searchDistance;	//탐색거리
	int m_state;			//상태

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

