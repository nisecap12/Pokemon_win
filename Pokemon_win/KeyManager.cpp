#include "stdafx.h"
#include "KeyManager.h"

KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{
}

bool KeyManager::StayKeyDown(int _key)
{
	return (isFocus && GetAsyncKeyState(_key) & 0x8000);
}

bool KeyManager::OnceKeyDown(int _key)
{
	if (isFocus && GetAsyncKeyState(_key) & 0x8000)
	{
		if (isDown[_key] == false)
		{
			isDown[_key] = true;
			return true;
		}
	}
	else
	{
		isDown[_key] = false;
	}
	return false;
}

bool KeyManager::OnceKeyUp(int _key)
{
	if (isFocus && GetAsyncKeyState(_key) & 0x8000)
	{
		isUp[_key] = true;
	}
	else
	{
		if (isUp[_key] == true)
		{
			isUp[_key] = false;
			return true;
		}
	}
	return false;
}

bool KeyManager::IsToggleKey(int _key)
{
	if (OnceKeyUp(_key))
	{
		isToggle[_key] = !isToggle[_key];
	}
	return isToggle[_key];
}

void KeyManager::CheckKey()
{
	//상하좌우 이동
	if (StayKeyDown(VK_UP))
	{
		if (!PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.SetDirection(DIRECTION::UP);
		}
	}
	if (StayKeyDown(VK_DOWN))
	{
		if (!PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.SetDirection(DIRECTION::DOWN);
		}
	}
	if (StayKeyDown(VK_LEFT))
	{
		if (!PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.SetDirection(DIRECTION::LEFT);
		}
	}
	if (StayKeyDown(VK_RIGHT))
	{
		if (!PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.SetDirection(DIRECTION::RIGHT);
		}
	}

	// 달리기
	if (StayKeyDown('X'))
	{
		if (!PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.SetPlayerState(PLAYER_STATE::RUN);
			TIMER.SetTimeUnit(0.25f);
		}
	}
	// 자전거 타기/내리기
	else if (IsToggleKey('Z'))
	{
		PLAYER_MANAGER.SetPlayerState(PLAYER_STATE::RIDE_BIKE);
		TIMER.SetTimeUnit(0.2f);
	}
	else
	{
		if(!PLAYER_MANAGER.isMoving())
		{
			PLAYER_MANAGER.SetPlayerState(PLAYER_STATE::WALK);
			TIMER.SetTimeUnit(0.5f);
		}
	}
	
	if (OnceKeyDown('U'))
	{
		MAP_MANAGER.ToggleGrid();
	}
	if (OnceKeyDown('I'))
	{
		NPC_MANAGER.SwitchAreaRender();
	}

	if (IsToggleKey('P'))
	{
		SCENE_MGR.SetScene(SCENE_MENU);
	}
	else
	{
		SCENE_MGR.SetScene(SCENE_INTRO);
	}
	
	if (OnceKeyDown(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}

}
