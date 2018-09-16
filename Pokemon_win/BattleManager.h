#pragma once
#include "Pokemon.h"
#include "Skill.h"
#include "Item.h"

class BattleManager
{
private:
	Skill m_selectedSkill;
	Item m_selectedItem;
	int m_BattleTrainerNum = 0;
	bool isLock = false;
	bool m_isTrainer = false;
	
private:
	BattleManager();
	~BattleManager();
	

public:
	static BattleManager& GetInstance()
	{
		static BattleManager Instance;
		return Instance;
	}

	//��Ʋ ���� + �� ��ȯ ȣ�� + ���� ��������
	void StartBattle(int _number, bool _isTrainer);
	//��Ʋ ���� + �� ��ȯ ȣ�� + ���� ��������
	void EndBattle(bool _isWin);

	void AttackEnemy(Pokemon* _enemy);
	void UseItem(int _itemNumber);
	bool TryCatch();
	int GetTrainerNumber()
	{
		return m_BattleTrainerNum;
	}

	bool isLocked()
	{
		return isLock;
	}
	void Lock()
	{
		isLock = true;
	}
	void Unlock()
	{
		isLock = false;
	}
};

#define BATTLE_MANAGER BattleManager::GetInstance()