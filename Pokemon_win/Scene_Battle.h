#pragma once
#include "Scene.h"
#include <vector>

enum BATTLE_TYPE
{
	ENTERANI,
	INTRO,
	BATTLE,
	REACTION,
	CATCH,
	SUMMARY,
	ENDBATTLE
};
enum REACTION_TYPE
{
	REACTION_NO,
	REACTION_BAD,
	REACTION_NORMAL,
	REACTION_GOOD,
	REACTION_CRITICAL,
};

class Scene_Battle :
	public Scene
{
private:
	HDC				m_BGDC = nullptr;
	HDC				m_BGDC1 = nullptr;
	BoxUI			m_Box;
	TextUI			m_Txt;
	int				m_dialogIndex = 0;
	int				m_blend = 0;
	bool			m_effectPlaying = false;

	//	POKEMON_MANAGER 연동 필요 변수
	int				m_index = 0;

	//	이미지 이동 및 Ani 변수
	int				m_EnemyMoveX = -512;
	int				m_EnemyMoveY = 0;
	int				m_EnemyInfo = -400;
	int				m_MyMoveX = 960;
	int				m_MyMoveY = 0;
	int				m_ballMoveX = 0;
	int				m_ballMoveY = -192;
	int				m_Ani = 0;
	int				m_playerAni = 0;
	int				m_ballAni = 0;
	int				m_enemyExit = 0;
	int				m_playerExit = 0;
	float			m_time = 0;
	float			m_ballTime = 0;
	int				m_ballbounce = 3;
	int				m_ballPitch = -140;
	bool			m_ballDirection = false;
	int				m_ballFrame = 0;
	bool			m_ballLeft = true;

	int				m_direction = DIRECTION::UP;
	POINT			m_blackRect;
	int x = 0, y = 10, xMAX = 9, yMAX = 9, xMIN = 1, yMIN = 0;
	int				m_rectIndex = 0;

	//	키입력 상태 변수
	bool			m_InputState = false;

	//	포켓몬 등장
	bool			m_myPokemon = false;
	bool			m_enemyPokemon = false;

	//	BATTLE 때 사용될 선택좌표
	int				m_BattleCursor = 0;
	bool			isCatch = false;
	bool			isEffectPlaying = false;

public:
	BATTLE_TYPE		m_Type = ENTERANI;
	bool			m_BattleTrainer = true;
	int				m_Reaction = REACTION_NORMAL;

public:
	Scene_Battle();
	~Scene_Battle();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};

