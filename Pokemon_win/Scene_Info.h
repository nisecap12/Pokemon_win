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

	//	���� ���ɸ� ������ŭ�� �迭����
	//	���ϸ� ����
	int			m_Num = 34176;			//	Ʈ���̳�Number

	//	���ϸ� �ɷ�
	int		m_Atk;			//	���ݷ�
	int		m_Def;			//	����
	int		m_sAtk;			//	Ư�� ���ݷ�
	int		m_sDef;			//	Ư�� ����
	int		m_Speed;		//	��ø��
	const char* m_Special[6];		//	Ư��

public:
	Scene_Info();
	~Scene_Info();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
};

