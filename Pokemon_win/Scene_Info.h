#pragma once
#include "Scene.h"

enum PokeType
{
	TYPE_NORMAL = 0,
	TYPE_FIGHT,
	TYPE_FLYING,
	TYPE_POISON,
	TYPE_GROUND,
	TYPE_ROCK,
	TYPE_BUG,
	TYPE_GHOST,
	TYPE_STEEL,
	TYPE_DARK,
	TYPE_FIRE,
	TYPE_WATER,
	TYPE_GRASS,
	TYPE_ELECTR,
	TYPE_PSYCHC,
	TYPE_ICE,
	TYPE_DRAGON,
	TYPE_RANDOM
};

class Scene_Info :
	public Scene
{
private:
	BoxUI	m_Box;
	TextUI	m_Txt;
	
	int		m_Ani = 0;
	float	m_time = 0;
	int		m_InfoPage = 0;
	int		m_pokemonIndex = 0;
	int		m_PokemonCount = 0;
	Pokemon m_Pokemon;

	//	지닌 포케몬 개수만큼의 배열변수
	//	포켓몬 정보
	int			m_Num = 34176;			//	트레이너Number

	//	포켓몬 능력
	int		m_Atk;			//	공격력
	int		m_Def;			//	방어력
	int		m_sAtk;			//	특수 공격력
	int		m_sDef;			//	특수 방어력
	int		m_Speed;		//	민첩성
	const char* m_Special[6];		//	특성

public:
	Scene_Info();
	~Scene_Info();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};

