#pragma once
#include "Pokemon.h"

/*
���ϸ� �����ڰ� �ϴ°�
- ���� ���� ���ϸ� 6���� ������ ����/�ҷ�����
- �� Ʈ���̳� ���ϸ� ������ ����/�ҷ�����
- �߻����ϸ� ������Ű��

*/

class PokemonManager
{
private:
	Pokemon m_myPokemonList[6];		//���ϸ� ����Ʈ
	Pokemon m_battleList[6];		//��Ʋ�� ����Ʈ
	int m_currentMyIndex = 0;
	Pokemon m_enemyPokemonList[6];	//�� ���ϸ� ����Ʈ
	int m_currentEnemyIndex = 0;
	int m_pokemonCount = 0;			//������ ���ϸ� ��
	Pokemon m_wildPokemon;			//�߻����ϸ�
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

	void		SetMyPokemonList(Pokemon* _pokemonList, int _size);	//���ϸ� ����Ʈ �ҷ�����
	Pokemon*	GetMyPokemonList();									//�� ���ϸ� ����Ʈ ��������
	Pokemon		GetMyPokemon(int _index);							//�� ���ϸ� ��������
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
	
	//�� Ʈ���̳� ���ϸ� �ҷ�����
	void		SetEnemyPokemonList(int _npcNumber);
	Pokemon*	GetEnemyPokemonList(int _npcNumber);
	Pokemon*	GetSelectedEnemyPokemon();
	void		SetSelectedEnemyPokemon(int _index);

	//�߻����ϸ� ������Ű��
	void		GeneratePokemon(int _area);
	Pokemon*	GetWildPokemon();

	//�߻����ϸ� ��� ó��
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