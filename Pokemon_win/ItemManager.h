#pragma once
#include "Item.h"

class ItemManager
{
private:
	std::vector<Item> m_itemList;
	

private:
	ItemManager();
	~ItemManager();
	void SaveItem();
	void LoadItem();
	
public:
	static ItemManager& GetInstance()
	{
		static ItemManager Instance;
		return Instance;
	}

	void Init();
	Item GetItem(short _itemNumber);
	void UseItem(short _itemNumber, Pokemon* _pokemon);
};

#define ITEM_MANAGER ItemManager::GetInstance()