#pragma once

class Timer
{
	bool m_isHighTimer = false;
	float m_timeResolution = 0.0f;
	float m_timeElapsed = 0.0f;
	__int64 m_lastTime = 0;
	__int64 m_currentTime = 0;

	unsigned long m_FPS = 0; 
	unsigned long m_TickCount = 0;
	float m_FPSTimeElapsed;

	unsigned long FPS_LIMIT = 60;
	float m_OneTickTime = 1.0f / FPS_LIMIT;
	float m_playTime = 0.0f;

private:
	void Initialize();
	void Release();

public:
	Timer();
	~Timer();

	float DoTick();
	unsigned long ShowFPS()
	{
		return m_FPS;
	}
	void SetFPS(unsigned long _FPS);
	float GetPlayTime()
	{
		return m_playTime;
	}
};

