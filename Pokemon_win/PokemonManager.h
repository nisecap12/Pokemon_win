#pragma once
#include "Pokemon.h"

/*
포켓몬 관리자가 하는것
- 내가 가진 포켓몬 6마리 데이터 저장/불러오기
- 적 트레이너 포켓몬 데이터 저장/불러오기
- 야생포켓몬 출현시키기

*/

class PokemonManager
{
private:
	Pokemon m_myPokemonList[6];		//포켓몬 리스트
	Pokemon m_battleList[6];		//배틀용 리스트
	int m_currentMyIndex = 0;
	Pokemon m_enemyPokemonList[6];	//적 포켓몬 리스트
	int m_currentEnemyIndex = 0;
	int m_pokemonCount = 0;			//보유한 포켓몬 수
	Pokemon m_wildPokemon;			//야생포켓몬
	std::vector<PokemonTable> m_pokemonTable;
	std::vector<EnemyPokemonTable> m_enemyTable;

	bool isLock = false;

private:
	PokemonManager();
	~PokemonManager();
	void LoadMyPokemon();
	void SaveNPCPokemon();
	void LoadNPCPokemon();
	void SavePokemonTable();
	void LoadPokemonTable();
	
public:
	static PokemonManager& GetInstance()
	{
		static PokemonManager Instance;
		return Instance;
	}

	void Init();
	void SaveMyPokemon();
	void RootMyPokemon();

	void		SetMyPokemonList(Pokemon* _pokemonList, int _size);	//포켓몬 리스트 불러오기
	Pokemon*	GetMyPokemonList();									//내 포켓몬 리스트 가져오기
	Pokemon		GetMyPokemon(int _index);							//내 포켓몬 가져오기
	Pokemon*	GetSelectedMyPokemon();
	int			GetSelectedPokemonNumber();
	void		SetSelectedMyPokemon(int _index);

	void		SettingBattleList();
	Pokemon		GetMyBattlePokemon(int _index);
	Pokemon*	GetSelectedBattlePokemon();
	void		SwapPokemon(int _swapIndex);

	int			GetPokemonCount()
	{
		return m_pokemonCount;
	}
	
	//적 트레이너 포켓몬 불러오기
	void		SetEnemyPokemonList(int _npcNumber);
	Pokemon*	GetEnemyPokemonList(int _npcNumber);
	Pokemon*	GetSelectedEnemyPokemon();
	void		SetSelectedEnemyPokemon(int _index);

	//야생포켓몬 출현시키기
	void		GeneratePokemon(int _area);
	Pokemon*	GetWildPokemon();

	//야생포켓몬 잡기 처리
	void		CatchPokemon();
	void		HealPokemon();

	void Lock()
	{
		isLock = true;
	}
	void Unlock()
	{
		isLock = false;
	}
	bool isLocked()
	{
		return isLock;
	}
};

#define POKEMON_MANAGER PokemonManager::GetInstance()