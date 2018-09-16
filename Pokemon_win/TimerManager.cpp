#undef UNICODE
#include "stdafx.h"
#include "TimerManager.h"
#include "Timer.h"

TimerManager::TimerManager()
{
	m_timer = new Timer();
}

TimerManager::~TimerManager()
{
	delete m_timer;
	m_timer = nullptr;
}

float TimerManager::DoTick()
{
	return m_timer->DoTick();
}

unsigned long TimerManager::GetFPS()
{
	return m_timer->ShowFPS();
}

void TimerManager::SetFPS(unsigned long _FPS)
{
	m_timer->SetFPS(_FPS);
}

void TimerManager::SetTimeUnit(float _time)
{
	m_time_unit = _time;
}

float TimerManager::GetTimeUnit()
{
	return m_time_unit;
}

float TimerManager::GetPlayTime()
{
	return m_timer->GetPlayTime();
}

void TimerManager::Render(HDC _hdc, int _x, int _y)
{
	std::stringstream text;

	text << "FPS - " << m_timer->ShowFPS();
	TextOut(_hdc, _x, _y, text.str().c_str(), text.str().length());
}
