#pragma once

/*
NPC 행동
1. 일반 NPC
한 방향 주시하다가 말걸면 캐릭터를 쳐다보며 스크립트 재생
*/

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
	NORMAL,		//일반
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
	TURN_ARROUND_CLOCKWISE, //주변 시계방향 빙글빙글 배회
	TURN_ARROUND_COUNTER_CLOCKWISE, //반시계방향 배회
	TURNING, //제자리 빙글빙글
	RANDOM, //랜덤 행동
};

class NPC
{
private:
	int m_number;			//NPC 번호
	int m_function;			//기능
	int m_searchDistance;	//탐색거리
	int m_state;			//상태
	POINT m_rootPosition;	 //NPC 원위치 (NPC가 역할 끝나면 되돌아가기위해 필요함, 필요없을수도있음)
	POINT m_position;		//NPC 위치좌표
	int m_direction;
	int m_pattern;			//NPC 패턴
	SIZE m_moveBox;			//NPC 행동 박스크기
	POINT m_moveBoxPosition; //행동박스 좌표
	int m_actionDelay;
	int m_actionCount;

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
		HDC imgDC = CreateCompatibleDC(_hdc);
		HBITMAP bit = (HBITMAP)LoadImage(nullptr, "policesprite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP oldbit = SelectBitmap(imgDC, bit);

		BITMAP	bm = {};
		GetObject(bit, sizeof(BITMAP), &bm);

		int width = bm.bmWidth / 4;
		int height = bm.bmHeight;

		GdiTransparentBlt(_hdc, (m_position.x * 64), ((m_position.y + 1) * 64) - height, width, height, imgDC, 64 * m_direction, 0, width, height, RGB(255, 119, 251));

		/*Rectangle(_hdc, (m_position.x * 64), (m_position.y * 64), (m_position.x * 64) + 64, (m_position.y * 64) + 64);
		std::stringstream s;
		s << m_direction;
		TextOut(_hdc, (m_position.x * 64)+12, (m_position.y * 64)+12, s.str().c_str(), s.str().length());*/
	}
};

