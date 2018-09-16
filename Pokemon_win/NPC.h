#pragma once
#include "ImgClass.h"
#include <functional>

class NPC
{
private:
	typedef std::function<void(std::string)> StartCall;
	typedef std::function<void()> StopCall;
	typedef std::function<void()> NextScript;

private:
	int				m_number;			//NPC ��ȣ
	int				m_function;			//���
	int				m_searchDistance;	//Ž���Ÿ�
	int				m_state;			//����
	int				m_mapNumber;		//�� ��ȣ
	
	POINT			m_prevPosition;
	POINT			m_position;		//NPC ��ġ Ÿ�� ��ǥ
	POINT			m_rootPosition;	//NPC �� ��ġ ��ǥ
	POINT			m_realPosition;   //NPC ���� ��ġ ��ǥ
	int				m_direction;
	int				m_step;
	bool			m_isMoving = false;
	int				m_pattern;			//NPC ����
	SIZE			m_moveBox;			//NPC �ൿ �ڽ�ũ��
	POINT			m_moveBoxPosition; //�ൿ�ڽ� ��ǥ
	float			m_animationTime;		//NPC �ִϸ��̼� �ð�
	std::string		m_scriptList[20];
	int				m_scriptListSize = 0;
	int				m_currentScript = 0;
	int				m_moveCount = 0;
	bool			isTalking = false;
	bool			hasBattled = false;
	bool			hasFinished = false;

	int m_x_max; //�� width
	int m_y_max; //�� height

	StartCall onHandler;
	StopCall stopHandler;
	NextScript scriptHandler;

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
	void DoScript(std::string _text);
	void StopScript();
	bool CheckPlayer();
	
public:
	NPC();
	NPC(int _number,int _mapNumber, int _function, int _direction, int _pattern, int _searchDistance, POINT _position, SIZE _moveBoxSize);
	~NPC();

	void SetHandler(StartCall f)
	{
		onHandler = std::move(f);
	}

	void SetStopHandler(StopCall f)
	{
		stopHandler = std::move(f);
	}

	void SetScriptHandler(NextScript f)
	{
		scriptHandler = std::move(f);
	}

	void GoNextScript();

	int GetState()
	{
		return m_state;
	}
	void SetState(int _state)
	{
		m_state = _state;
	}

	POINT GetRealPosition()
	{
		return m_realPosition;
	}

	POINT GetRootPosition()
	{
		return m_rootPosition;
	}

	POINT GetPosition()
	{
		return m_position;
	}

	SIZE GetMoveBox()
	{
		return m_moveBox;
	}

	void SetPosition(POINT _position)
	{
		m_position = _position;
	}

	int GetNumber()
	{
		return m_number;
	}

	int GetDirection()
	{
		return m_direction;
	}

	void SetDirection(int _direction)
	{
		m_direction = _direction;
	}

	int GetStep()
	{
		return m_step;
	}

	bool IsMoving()
	{
		return m_isMoving;
	}

	int GetMapNumber()
	{
		return m_mapNumber;
	}

	void StopNPC();

	void DoAction(float _elapseTime);
};

