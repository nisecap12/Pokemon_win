#include "stdafx.h"
#include "BagManager.h"


BagManager::BagManager()
{
}


BagManager::~BagManager()
{
}

void BagManager::SaveBag()
{
	ItemData* bag = new ItemData[ITEM_TOTAL_NUMBER - 1];
	std::ofstream fout("DB/Bag.db", std::ios::binary);
	
	int i = 0;
	bag[i++] = { i, 1	, "HP + 20"};
	bag[i++] = { i, 20	, "HP + 50"};
	bag[i++] = { i, 10	, "HP + 200"};
	bag[i++] = { i, 132	, "HP 전부 회복"};
	bag[i++] = { i, 15	, "HP, 상태이상 회복 "};
	bag[i++] = { i, 6	, "독 상태이상 회복"};
	bag[i++] = { i, 7	, "마비 상태이상 회복"};
	bag[i++] = { i, 1	, "화상 상태이상 회복"};
	bag[i++] = { i, 33	, "얼음 상태이상 회복"};
	bag[i++] = { i, 35	, "수면 상태이상 회복"};
	bag[i++] = { i, 132 , "모든 상태이상 회복"};
	bag[i++] = { i, 25	, "기절한 포켓몬 HP절반 회복"};
	bag[i++] = { i, 22	, "기절한 포켓몬 HP모두 회복"};
	bag[i++] = { i, 23	, "불 포켓몬 진화"};
	bag[i++] = { i, 71	, "물 포켓몬 진화"};
	bag[i++] = { i, 1	, "번개 포켓몬 진화"};
	bag[i++] = { i, 2	, "풀 포켓몬 진화"};
	bag[i++] = { i, 5	, "요정 포켓몬 진화"};
	bag[i++] = { i, 3	, "특정 포켓몬 진화"};
	bag[i++] = { i, 1	, "포켓몬을 진화시키지 않는 돌"};

	//ball
	bag[i++] = { i, 90 , "기본 포켓볼"};
	bag[i++] = { i, 46 , "조금 더 잘 잡히는 볼"};
	bag[i++] = { i, 33 , "더욱 잘 잡히는 볼"};
	bag[i++] = { i, 5  , "무조건 잡히는 볼"};
	bag[i++] = { i, 11 , "사파리존 전용 볼"};

	//special
	bag[i++] = { i, 1 , "성능이 아주 좋은 낚시대"};
	bag[i++] = { i, 1 , "탈것은 다리보다 빠르다."};
	bag[i++] = { i, 1 , "여행의 필수품"};

	if (fout.fail() == false)
	{
		fout.write((const char*)bag, sizeof(ItemData) * (ITEM_TOTAL_NUMBER - 1));
		fout.close();
	}

	delete[] bag;
}

void BagManager::LoadBag()
{
	ItemData* bag = new ItemData[ITEM_TOTAL_NUMBER - 1];
	std::ifstream fout;

	fout.open("DB/Bag.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.read((char*)bag, sizeof(ItemData) * (ITEM_TOTAL_NUMBER - 1));
		fout.close();
	}

	for (int i = 0; i < ITEM_TOTAL_NUMBER - 1; i++)
	{
		switch (ITEM_MANAGER.GetItem(bag[i].m_itemNumber).m_type)
		{
		case ItemType::SPECIAL:
			m_specialList.push_back(bag[i]);
			break;
		case ItemType::TOOL:
			m_toolList.push_back(bag[i]);
			break;
		case ItemType::BALL:
			m_ballList.push_back(bag[i]);
			break;
		}
	}

	delete[] bag;
}

void BagManager::Init()
{
	SaveBag();
	LoadBag();
}

std::vector<ItemData> BagManager::GetToolList()
{
	return m_toolList;
}

std::vector<ItemData> BagManager::GetSpecialList()
{
	return m_specialList;
}

std::vector<ItemData> BagManager::GetBallList()
{
	return m_ballList;
}

Item BagManager::GetSelectedItem()
{
	return m_selectedItem;
}

void BagManager::SetSelectedItem(int _index)
{
	m_selectedItem = ITEM_MANAGER.GetItem(m_toolList[_index].m_itemNumber);
}

void BagManager::DiscardItem(int _type, int _index, int _count)
{
	switch (_type)
	{
	case ItemType::SPECIAL:
	{
		m_specialList[_index].m_count -= _count;
		if (m_specialList[_index].m_count - _count <= 0)
		{
			m_specialList.erase(m_specialList.begin() + _index);
		}
	}break;
	case ItemType::TOOL:
	{
		m_toolList[_index].m_count -= _count;
		if (m_toolList[_index].m_count - _count <= 0)
		{
			m_toolList.erase(m_toolList.begin() + _index);
		}
			
	}break;
	case ItemType::BALL:
	{
		m_ballList[_index].m_count -= _count;
		if (m_ballList[_index].m_count - _count <= 0)
		{
			m_ballList.erase(m_ballList.begin() + _index);
		}
	}break;
	}
}

//void BagManager::UseItem(short _itemNumber)
//{
//	switch (m_selectedItem.m_type)
//	{
//	case SPECIAL:
//	{
//
//	}break;
//	case TOOL:
//	{
//		if (SCENE_MGR.GetFrom() == SCENE_BATTLE)
//		{
//			switch (m_selectedItem.m_function)
//			{
//			case ItemFunction::POTION:
//			{
//				
//			}break;
//			case ItemFunction::REVIVE:
//			{
//				SCENE_MGR.SetScene(SCENE_POKEMON);
//			}
//			}
//		}
//
//	}break;
//	case BALL:
//	{
//		BATTLE_MANAGER.TryCatch();
//	}break;
//	}
//}
