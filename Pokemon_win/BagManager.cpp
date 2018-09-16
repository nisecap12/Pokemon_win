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
	bag[i++] = { i, 132	, "HP ���� ȸ��"};
	bag[i++] = { i, 15	, "HP, �����̻� ȸ�� "};
	bag[i++] = { i, 6	, "�� �����̻� ȸ��"};
	bag[i++] = { i, 7	, "���� �����̻� ȸ��"};
	bag[i++] = { i, 1	, "ȭ�� �����̻� ȸ��"};
	bag[i++] = { i, 33	, "���� �����̻� ȸ��"};
	bag[i++] = { i, 35	, "���� �����̻� ȸ��"};
	bag[i++] = { i, 132 , "��� �����̻� ȸ��"};
	bag[i++] = { i, 25	, "������ ���ϸ� HP���� ȸ��"};
	bag[i++] = { i, 22	, "������ ���ϸ� HP��� ȸ��"};
	bag[i++] = { i, 23	, "�� ���ϸ� ��ȭ"};
	bag[i++] = { i, 71	, "�� ���ϸ� ��ȭ"};
	bag[i++] = { i, 1	, "���� ���ϸ� ��ȭ"};
	bag[i++] = { i, 2	, "Ǯ ���ϸ� ��ȭ"};
	bag[i++] = { i, 5	, "���� ���ϸ� ��ȭ"};
	bag[i++] = { i, 3	, "Ư�� ���ϸ� ��ȭ"};
	bag[i++] = { i, 1	, "���ϸ��� ��ȭ��Ű�� �ʴ� ��"};

	//ball
	bag[i++] = { i, 90 , "�⺻ ���Ϻ�"};
	bag[i++] = { i, 46 , "���� �� �� ������ ��"};
	bag[i++] = { i, 33 , "���� �� ������ ��"};
	bag[i++] = { i, 5  , "������ ������ ��"};
	bag[i++] = { i, 11 , "���ĸ��� ���� ��"};

	//special
	bag[i++] = { i, 1 , "������ ���� ���� ���ô�"};
	bag[i++] = { i, 1 , "Ż���� �ٸ����� ������."};
	bag[i++] = { i, 1 , "������ �ʼ�ǰ"};

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
