#pragma once
#include <Windows.h>
class Timer;

class TimerManager
{
private:
	Timer * m_timer = nullptr;

private:
	TimerManager();
	~TimerManager();

public:
	static TimerManager& GetInstance()
	{
		static TimerManager instance;
		return instance;
	}

	float DoTick();
	unsigned long GetFPS();
	void SetFPS(unsigned long _FPS);

	float GetPlayTime();
	void Render(HDC _hdc, int _x, int _y);
};

#define TIMER TimerManager::GetInstance()

