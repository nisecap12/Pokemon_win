#pragma once
class KeyManager
{
private:
	bool	isFocus = true;
	bool	isDown[256] = {};
	bool	isUp[256] = {};
	bool	isToggle[256] = {};
	float	m_elapseTime = 0.0f;

private:
	KeyManager();
	~KeyManager();

public:
	bool	StayKeyDown(int _key);
	bool	OnceKeyDown(int _key);
	bool	OnceKeyUp(int _key);
	bool	IsToggleKey(int _key);
	void	IsFocused(bool _focus)
	{
		isFocus = _focus;
	}

public:
	static KeyManager& GetInstance()
	{
		static KeyManager Instance;
		return Instance;
	}
	
	void	CheckKey();
};

#define KEY_MANAGER KeyManager::GetInstance()