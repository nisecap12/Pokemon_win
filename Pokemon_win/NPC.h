#pragma once

//NPC 기능
enum NPC_FUNCTION 
{
	NONE,		//일반
	HEAL,		//포켓몬센터
	SHOP,		//상점
	TRAINER,	//일반 트레이너
	CHAMP,		//체육관 관장
};

//NPC 상태
enum NPC_STATE
{
	NONE,		//일반
	ENCOUNTER,	//조우
	INTERACT,	//상호작용
};

//NPC 방향
enum NPC_DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

//NPC 행동패턴
enum NPC_PATTERN
{
	STARRING, //주시
	BACK_AND_FORTH, //왔다갔다
	TURN_ARROUND_CLOCKWISE, //주변 시계방향 빙글빙글 배회
	TURN_ARROUND_COUNTER_CLOCKWISE, //반시계방향 배회
	TURNING, //제자리 빙글빙글
	CHASE, //쫓아옴
};

class NPC
{
private:
	int m_number;			//NPC 번호
	int m_function;			//기능
	int m_searchDistance;	//탐색거리
	int m_state;			//상태
	POINT m_rootPosition;	 //NPC 원위치
	POINT m_position;		//NPC 위치좌표
	int m_direction;
	int m_pattern;			//NPC 패턴
	int m_move_point;		//행동 포인트 

	int m_x_max; //맵 width
	int m_y_max; //맵 height

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

