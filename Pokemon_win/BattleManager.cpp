#include "stdafx.h"
#include "BattleManager.h"


BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
}

void BattleManager::StartBattle(int _number, bool _isTrainer)
{
	m_isTrainer = _isTrainer;
	//��ȯ �ִϸ��̼�
	if (_isTrainer)		//Ʈ���̳� �����϶�,
	{
		m_BattleTrainerNum = _number;
		POKEMON_MANAGER.GetEnemyPokemonList(_number);
		SCENE_MGR.SetMsg((void*)true);
	}
	else				//�߻� �����϶�,
	{
		POKEMON_MANAGER.GeneratePokemon(_number);
		SCENE_MGR.SetMsg((void*)false);
	}
	POKEMON_MANAGER.SetSelectedMyPokemon(0);

	//��Ʋ������ ��ȯ
	SCENE_MGR.OpenScene(SCENE_BATTLE);
}

void BattleManager::EndBattle(bool _isWin)
{
	if (m_isTrainer)
	{
		//���� ����
		if (_isWin)
		{
			PLAYER_MANAGER.SetMoney(PLAYER_MANAGER.GetMoney() + 20000000);
			PLAYER_MANAGER.IncreaseBadge();
		}
		else
		{
			PLAYER_MANAGER.SetMoney(PLAYER_MANAGER.GetMoney() - 500);
		}
	}

	//��ȯ �ִϸ��̼�
	//�ʵ�ȭ������ ��ȯ
	SCENE_MGR.SetEnter(true);
	SCENE_MGR.SetBattle(false);
}

void BattleManager::AttackEnemy(Pokemon * _enemy)
{
	POKEMON_MANAGER.GetSelectedEnemyPokemon()->m_hp -= m_selectedSkill.m_damage;
}

bool BattleManager::TryCatch()
{
	if (m_selectedItem.m_value > (rand() % 100))
	{
		POKEMON_MANAGER.CatchPokemon();
		return true;
	}

	return false;
}

void BattleManager::UseItem(int _itemNumber)
{
	
}
