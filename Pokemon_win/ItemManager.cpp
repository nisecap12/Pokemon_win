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
	��ȣ : ������ ������ȣ
	�̸� : ������ �̸�
	Ÿ�� : � ������ ���������� (�߿��� 0 , ���� 1 , ���Ϻ� 2 )
	��� : ������ ��� ( ġ��� 0, ���¾� 1, ��Ȱ 2, ��ȭ�� 3, ������ 4) //�߿��� �����Ͻ�, � ���������� ����
	��ġ : ������ �ɷ� ��ġ (�� : ��ó���� ��ġ�� 50�̸� ü��ȸ���� 50�����ش�.)
	
	���Ϻ� / ��ó�� /��ȭ�ǵ� / ����ȸ����
	*/

	item[i++] = { i, "��ó��",		1, 0, 20 };
	item[i++] = { i, "������ó��",	1, 0, 50 };
	item[i++] = { i, "��޻�ó��",	1, 0, 200 };
	item[i++] = { i, "Ǯȸ����",		1, 0, }; //HP ��� ȸ��
	item[i++] = { i, "ȸ����",		1, 0, }; //HP�� �����̻� ��� ȸ��

	item[i++] = { i, "�ص���",		1, 1, }; //��, �͵����� ȸ��
	item[i++] = { i, "����ġ����",	1, 1, }; //���� ���� ȸ��
	item[i++] = { i, "ȭ��ġ����",	1, 1, }; //ȭ�� ���� ȸ��
	item[i++] = { i, "��������ġ����", 1, 1, }; //���� ���� ȸ��
	item[i++] = { i, "����¾�",		1, 1, };	//��� ���� ȸ��

	item[i++] = { i, "������ġ��",	1, 1, }; //��� �����̻� ȸ��
	item[i++] = { i, "���������",	1, 2, 50 }; // ���� ���¿��� HP���� ȸ��
	item[i++] = { i, "����ǵ��", 1, 2, 100 }; //���� ���¿��� HP��� ȸ��
	item[i++] = { i, "�Ҳ��ǵ�",		1, 3, };
	item[i++] = { i, "���ǵ�",		1, 3, };

	item[i++] = { i, "õ���ǵ�",		1, 3, };
	item[i++] = { i, "�����ǵ�",		1, 3, };
	item[i++] = { i, "���ǵ�",		1, 3, };
	item[i++] = { i, "�¾��ǵ�",		1, 3, };
	item[i++] = { i, "���Ծ��µ�",	1, 3, };

	item[i++] = { i, "���ͺ�",		2, 0, 25 };
	item[i++] = { i, "���ۺ�",		2, 0, 50 };
	item[i++] = { i, "�����ۺ�",		2, 0, 75 };
	item[i++] = { i, "�����ͺ�",		2, 0, 100 };
	item[i++] = { i, "���ĸ���",		2, 0, 50 };

	item[i++] = { i, "�������ô�",	0, 0, }; // �������� ���ø� �� �� �ְԵȴ�
	item[i++] = { i, "������",		0, 0, }; //�ȴ� �ӵ����� ����
	item[i++] = { i, "Ÿ���",		0, 0, }; //����
	item[i++] = { i, "���׽���",		0, 0, }; // �ȴ°�*2 = ���׽��� < ������

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

	//NPC.db ���� ����
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

//���ϸ󿡰� �������� ����ϸ� ȿ���� �����Ŵ
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
