#include "stdafx.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
	m_itemList.clear();
}

void ItemManager::Init()
{
	SaveItem();
	LoadItem();
}

Item ItemManager::GetItem(short _itemNumber)
{
	return m_itemList[_itemNumber];
}

void ItemManager::SaveItem()
{
	Item* item = new Item[ITEM_TOTAL_NUMBER];
	short i = 0;

	/*
	{ number, name, type, function, value }
	번호 : 아이템 고유번호
	이름 : 아이템 이름
	타입 : 어떤 종류의 아이템인지 (중요한 0 , 도구 1 , 포켓볼 2 )
	기능 : 아이템 기능 ( 치료약 0, 상태약 1, 부활 2, 진화돌 3, 렙업돌 4) //중요한 물건일시, 어떤 아이템인지 저장
	수치 : 아이템 능력 수치 (예 : 상처약은 수치가 50이면 체력회복을 50시켜준다.)
	
	포켓볼 / 상처약 /진화의돌 / 상태회복약
	*/

	item[i++] = { i, "상처약",		1, 0, 20 };
	item[i++] = { i, "좋은상처약",	1, 0, 50 };
	item[i++] = { i, "고급상처약",	1, 0, 200 };
	item[i++] = { i, "풀회복약",		1, 0, }; //HP 모두 회복
	item[i++] = { i, "회복약",		1, 0, }; //HP와 상태이상 모두 회복

	item[i++] = { i, "해독제",		1, 1, }; //독, 맹독상태 회복
	item[i++] = { i, "마비치료제",	1, 1, }; //마비 상태 회복
	item[i++] = { i, "화상치료제",	1, 1, }; //화상 상태 회복
	item[i++] = { i, "얼음상태치료제", 1, 1, }; //얼음 상태 회복
	item[i++] = { i, "잠깨는약",		1, 1, };	//잠듦 상태 회복

	item[i++] = { i, "만병통치제",	1, 1, }; //모든 상태이상 회복
	item[i++] = { i, "기력의조각",	1, 2, 50 }; // 기절 상태에서 HP절반 회복
	item[i++] = { i, "기력의덩어리", 1, 2, 100 }; //기절 상태에서 HP모두 회복
	item[i++] = { i, "불꽃의돌",		1, 3, };
	item[i++] = { i, "물의돌",		1, 3, };

	item[i++] = { i, "천둥의돌",		1, 3, };
	item[i++] = { i, "리프의돌",		1, 3, };
	item[i++] = { i, "달의돌",		1, 3, };
	item[i++] = { i, "태양의돌",		1, 3, };
	item[i++] = { i, "변함없는돌",	1, 3, };

	item[i++] = { i, "몬스터볼",		2, 0, 25 };
	item[i++] = { i, "수퍼볼",		2, 0, 50 };
	item[i++] = { i, "하이퍼볼",		2, 0, 75 };
	item[i++] = { i, "마스터볼",		2, 0, 100 };
	item[i++] = { i, "사파리볼",		2, 0, 50 };

	item[i++] = { i, "좋은낚시대",	0, 0, }; // 수역에서 낚시를 할 수 있게된다
	item[i++] = { i, "자전거",		0, 0, }; //걷는 속도보다 빠름
	item[i++] = { i, "타운맵",		0, 0, }; //지도
	item[i++] = { i, "러닝슈즈",		0, 0, }; // 걷는거*2 = 러닝슈즈 < 자전거

	std::ofstream fout("DB/Item.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.write((const char *)item, sizeof(Item) * ITEM_TOTAL_NUMBER);
		fout.close();
	}

	delete[] item;
	item = nullptr;
}

void ItemManager::LoadItem()
{
	Item *data = new Item[ITEM_TOTAL_NUMBER];
	std::ifstream fout;

	//NPC.db 파일 열기
	fout.open("DB/Item.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.read((char*)data, sizeof(Item) * ITEM_TOTAL_NUMBER);
		fout.close();

		for (int i = 0; i < ITEM_TOTAL_NUMBER; i++)
		{
			Item temp = data[i];
			m_itemList.push_back(temp);
		}
	}

	delete[] data;
}

//포켓몬에게 아이템을 사용하면 효과를 적용시킴
void ItemManager::UseItem(short _itemNumber, Pokemon * _pokemon)
{
	switch (m_itemList[_itemNumber].m_type)
	{
	case SPECIAL:
	{
		
	}break;
	case TOOL:
	{
		if (BAG_MANAGER.GetSelectedItem().m_function == ItemFunction::POTION)
		{
			POKEMON_MANAGER.GetSelectedMyPokemon()->m_hp += m_itemList[_itemNumber].m_value;
			if (POKEMON_MANAGER.GetSelectedMyPokemon()->m_hp > POKEMON_MANAGER.GetSelectedMyPokemon()->m_hpMax)
			{
				POKEMON_MANAGER.GetSelectedMyPokemon()->m_hp = POKEMON_MANAGER.GetSelectedMyPokemon()->m_hpMax;
			}
		}
	}break;
	case BALL:
	{
		
	}break;
	}
}
