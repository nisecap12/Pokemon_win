#pragma once
#include "ImgClass.h"
#include "NPCRenderManager.h"

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
	RANDOM, //���� �ൿ
};

class NPC
{
private:
	int m_number;			//NPC ��ȣ
	int m_function;			//���
	int m_searchDistance;	//Ž���Ÿ�
	int m_state;			//����
	
	POINT m_position;		//NPC ��ġ��ǥ
	int m_direction;
	int m_pattern;			//NPC ����
	SIZE m_moveBox;			//NPC �ൿ �ڽ�ũ��
	POINT m_moveBoxPosition; //�ൿ�ڽ� ��ǥ
	int m_actionDelay;
	int m_actionCount;

	ImgClass m_image;

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
	NPC(int _number, int _function, int _direction, int _pattern, int _searchDistance, POINT _position, SIZE _moveBoxSize);
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

	int GetNumber()
	{
		return m_number;
	}

	int GetDirection()
	{
		return m_direction;
	}

	void DoAction();

	void Render(HDC _hdc)
	{
		NPC_RENDER_MANAGER.Render(_hdc, this);

		/*HDC imgDC = CreateCompatibleDC(_hdc);
		HBITMAP bit = (HBITMAP)LoadImage(nullptr, "policesprite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP oldbit = SelectBitmap(imgDC, bit);

		BITMAP	bm = {};
		GetObject(bit, sizeof(BITMAP), &bm);

		int width = bm.bmWidth / 4;
		int height = bm.bmHeight;

		GdiTransparentBlt(_hdc, (m_position.x * 64), ((m_position.y + 1) * 64) - height, width, height, imgDC, 64 * m_direction, 0, width, height, RGB(255, 119, 251));*/

		/*Rectangle(_hdc, (m_position.x * 64), (m_position.y * 64), (m_position.x * 64) + 64, (m_position.y * 64) + 64);
		std::stringstream s;
		s << m_direction;
		TextOut(_hdc, (m_position.x * 64)+12, (m_position.y * 64)+12, s.str().c_str(), s.str().length());*/
	}
};

