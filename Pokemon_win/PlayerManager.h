#pragma once

enum PLAYER_STATE
{
	WALK,
	RUN,
	RIDE_BIKE,
};

class PlayerManager
{
private:
	bool m_sex;
	std::string m_name;
	short m_badgeCount;
	int m_money;
	short m_state;
	short m_direction = 3;
	short m_step;
	short m_prevStep;
	float m_animationTime = 0.0f;
	ImgClass m_image;
	bool m_isMoving = false;
	bool m_controlActivated = true;
	POINT m_renderPosition;
	POINT m_currentPosition;
	POINT m_nextPosition;
	bool m_wildEncountered = false;

private:
	PlayerManager();
	~PlayerManager();
	void Release();
	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();

public:
	static PlayerManager& GetInstance()
	{
		static PlayerManager Instance;
		return Instance;
	}

	std::string GetName();
	void SetName(std::string _name);
	bool GetSex();
	void SetSex(bool _sex);
	short GetBadgeCount();
	void IncreaseBadge();
	int GetMoney();
	void SetMoney(int _money);
	
	short GetDirection()
	{
		return m_direction;
	}
	void SetDirection(short _direction);
	bool isMoving();
	void SetIsMoving(bool _isMoving);
	void SetPlayerState(short _state);
	short GetPlayerState();
	POINT GetPosition();
	void SetPosition(POINT _position);
	POINT GetRenderPosition()
	{
		return m_renderPosition;
	}

	void SetData(POINT _pos, short _direction, short _badge, int _money);

	bool IsControlActivated();
	void SetControlActivate(bool _isActivated)
	{
		m_controlActivated = _isActivated;
	}

	ImgClass* GetPlayerImage();

	void Init(HWND _hWnd);
	void Update(float _elapseTime);
	void Render(HDC _hdc);
	
};

#define PLAYER_MANAGER PlayerManager::GetInstance()