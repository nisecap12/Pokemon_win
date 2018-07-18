#include "stdafx.h"
#include "Timer.h"
#pragma comment(lib, "winmm.lib")

Timer::Timer()
{
	Initialize();
}
Timer::~Timer()
{
	Release();
}

void Timer::Initialize()
{
	LARGE_INTEGER periodFrequency = {};
	m_isHighTimer = QueryPerformanceFrequency(&periodFrequency);

	if (m_isHighTimer == true)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&m_lastTime);
		m_timeResolution = 1.0f / periodFrequency.QuadPart;
	}
	else
	{
		timeBeginPeriod(1);

		m_lastTime = timeGetTime();
		m_timeResolution = 0.001f;
	}
}

void Timer::Release()
{
	timeEndPeriod(1);
}

float Timer::DoTick()
{
	do
	{
		if (m_isHighTimer)
			QueryPerformanceCounter((LARGE_INTEGER*)&m_currentTime);
		else
			m_currentTime = timeGetTime();

		m_timeElapsed = (m_currentTime - m_lastTime) * m_timeResolution;

	} while (m_timeElapsed <= m_OneTickTime);

	m_lastTime = m_currentTime;
	m_TickCount++;
	m_FPSTimeElapsed += m_timeElapsed;
	m_playTime += m_timeElapsed;

	if (m_FPSTimeElapsed > 1.00f)
	{
		m_FPS = m_TickCount;
		m_TickCount = 0;
		m_FPSTimeElapsed -= 1.0f;
	}

	return m_timeElapsed;
}

void Timer::SetFPS(unsigned long _FPS)
{
	if (_FPS == 0 || _FPS == FPS_LIMIT)
		return;

	FPS_LIMIT = _FPS;
	m_OneTickTime = 1.0f / FPS_LIMIT;
}
