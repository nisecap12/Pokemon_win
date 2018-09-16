#include "stdafx.h"
#include "PokemonManager.h"

PokemonManager::PokemonManager()
{
}


PokemonManager::~PokemonManager()
{
}

void PokemonManager::SaveMyPokemon()
{
	std::ofstream fout("DB/MyPokemon.db", std::ios::binary);
	if (fout.fail() == false)
	{
		fout << m_pokemonCount;
		fout.write((const char*)m_myPokemonList, sizeof(Pokemon) * 6);
	}
}

void PokemonManager::LoadMyPokemon()
{
	Pokemon* table = new Pokemon[6];
	std::ifstream fout;

	fout.open("DB/MyPokemon.db", std::ios::binary);

	if (m_myPokemonList[0].m_level == 0)
	{
		if (fout.fail() == false)
		{
			fout >> m_pokemonCount;
			fout.read((char*)table, sizeof(Pokemon) * 6);
			fout.close();

			for (int i = 0; i < m_pokemonCount; i++)
			{
				m_myPokemonList[i] = table[i];
				strcpy_s(m_myPokemonList[i].m_nickname,20, m_myPokemonList[i].m_data.m_name);
			}
		}
		else
		{
			RootMyPokemon();
		}
	}
}

void PokemonManager::SaveNPCPokemon()
{
	EnemyPokemonTable* table = new EnemyPokemonTable[TRAINER_TOTAL_NUMBER];

	short i = 0;

	/*
	NPC ��ȣ : NPC.db�� �ۼ��� ��ȣ�� ��ġ�ؾ���
	���ϸ� ���� : 
		- ���ϸ�1 ��ȣ
		- ���ϸ�2 ��ȣ
		- ���ϸ�3 ��ȣ
		- ���ϸ�4 ��ȣ
		- ���ϸ�5 ��ȣ
		- ���ϸ�6 ��ȣ
	*/
	table[i++] = { 1,{ {11, } , {15, }, {16, }, {149, }, {127, }, {-1, } } };
	table[i++] = { 4,{ {118, }, {43, }, {106, }, {25, }, {26, }, {32, } } };

	std::ofstream fout("DB/NPC_Pokemon.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.write((const char*)table, sizeof(EnemyPokemonTable) * TRAINER_TOTAL_NUMBER);
	}

	delete[] table;
}

void PokemonManager::LoadNPCPokemon()
{
	EnemyPokemonTable* table = new EnemyPokemonTable[TRAINER_TOTAL_NUMBER];
	std::ifstream fout;

	fout.open("DB/NPC_Pokemon.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.read((char*)table, sizeof(EnemyPokemonTable) * TRAINER_TOTAL_NUMBER);
		fout.close();

		for (int i = 0; i < TRAINER_TOTAL_NUMBER; i++)
		{
			EnemyPokemonTable temp;
			temp.npcNumber = table[i].npcNumber;
			temp.PokemonList[0] = table[i].PokemonList[0];
			temp.PokemonList[1] = table[i].PokemonList[1];
			temp.PokemonList[2] = table[i].PokemonList[2];
			temp.PokemonList[3] = table[i].PokemonList[3];
			temp.PokemonList[4] = table[i].PokemonList[4];
			temp.PokemonList[5] = table[i].PokemonList[5];
			m_enemyTable.push_back(temp);
		}
	}
}

void PokemonManager::SavePokemonTable()
{
	PokemonTable* table = new PokemonTable[POKEMON_TOTAL_NUMBER];
	std::ofstream fout("DB/SkillTable.db");

	short i = 0;

	/*
	���ϸ� ��ȣ
	��� 1 ��ȣ
	��� 2 ��ȣ
	��� 3 ��ȣ
	��� 4 ��ȣ
	��� ������ -1
	*/

	table[i++] = { i, 32, 72, -1, -1 }; //�̻��ؾ� - �����ġ��, ���Ѹ���
	table[i++] = { i, 74, 72, 21, -1 }; //�̻���Ǯ - �ٳ�������, ���Ѹ���, ����ä��
	table[i++] = { i, 74, 72, 21, 75 }; //�̻��ز� - �����ġ��, ���Ѹ���, �ֶ��
	table[i++] = { i, 44, 9, -1, -1 }; //���̸� - �����Ҹ�, ������
	table[i++] = { i, 44, 9, 51, -1 }; //���ڵ� - �����Ҹ�, ������, �Ҳɼ���
	table[i++] = { i, 44, 9, 51, 42 }; //���ڸ� - �����Ҹ�, ������, �Ҳɼ���, °������
	table[i++] = { i, 32, 38, -1, -1 }; //���α� - �����ġ��, ��������
	table[i++] = { i, 32, 38, 144, -1 }; //��Ϻα� - �����ġ��, ��������, ��ǰ
	table[i++] = { i, 32, 38, 144, 54 }; //�źϿ� - �����ġ��, ��������, ��ǰ, ������
	table[i++] = { i, 32, 80, -1, -1 }; //ĳ���� - �����ġ��, �ǻձ�
	table[i++] = { i, 105, -1, -1, -1 }; //�ܵ��� - �ܴ�������
	table[i++] = { i, 92, 76, 77, 78 }; //������ - ������, ������, ��������, ���鰡��
	table[i++] = { i, 39, 80, -1, -1 }; //������ - ��ħ, �ǻձ�
	table[i++] = { i, 105, -1, -1, -1 }; //������ - �ܴ�������
	table[i++] = { i, 30, 115, 98, -1 }; //��ħ�� - �������, ������, �г�
	table[i++] = { i, 15, 27, -1, -1 }; //���� - �ٶ�����Ű��, �𷡻Ѹ���
	table[i++] = { i, 15, 27, 32, -1 }; //���� - �ٶ�����Ű��, �𷡻Ѹ���, �����ġ��
	table[i++] = { i, 15, 27, 32, 97 }; //������ - �ٶ�����Ű��, �𷡻Ѹ���, �����ġ��, ������ȭ
	table[i++] = { i, 32, 38, -1, -1 }; //���� - �����ġ��, ��������
	table[i++] = { i, 32, 38, 97, -1 }; //��Ʈ�� - �����ġ��, ��������, ������ȭ
	table[i++] = { i, 63, 44, -1, -1 }; //������ - �ɱ�, �����Ҹ�
	table[i++] = { i, 63, 44, 42, -1 }; //����帱�� - �ɱ�, �����Ҹ�, °������
	table[i++] = { i, 34, 42, -1, -1 }; //�ƺ� - ��主��, °������
	table[i++] = { i, 34, 42, 39, -1 }; //�ƺ�ũ - ��主��, °������, ��ħ
	table[i++] = { i, 83, 44, -1, -1 }; //��ī�� - �����ũ, �����Ҹ�
	table[i++] = { i, 83, 85, -1, -1 }; //������ - �����ũ, �����Ҹ�, �����ڼ���
	table[i++] = { i, 9, 27, -1, -1 }; //�𷡵��� - ������, �𷡻Ѹ���
	table[i++] = { i, 9, 27, 162, -1 }; //���� - ������, �𷡻Ѹ���, �������
	table[i++] = { i, 44, 32, -1, -1 }; //�ϵ己�� - �����Ҹ�, �����ġ��
	table[i++] = { i, 44, 32, 9, -1 }; //�ϵ帮�� - �����Ҹ�, �����ġ��, ������
	table[i++] = { i, 32, 9, 33, 54 }; //�ϵ��� - �����ġ��, ������, ������, ��ǰ
	table[i++] = { i, 42, 32, -1, -1 }; //�ϵ己�� - °������, �����ġ��
	table[i++] = { i, 42, 32, 29, -1 }; //�ϵ帮�� - °������, �����ġ��, �����
	table[i++] = { i, 39, 42, 29, 23 }; //�ϵ�ŷ - ��ħ, �����ġ��, �����, �ι�ġ��
	table[i++] = { i, 0, 44, -1, -1 }; //�߻� - ��ġ��, �����Ҹ�
	table[i++] = { i, 106, 2, 46, 117 }; //�Ƚ� - �۾�����, ���ӻ�ġ��, �뷡�ϱ�, �հ�������
	table[i++] = { i, 51, 38, -1, -1 }; //�Ľ����� - �Ҳɼ���, ��������
	table[i++] = { i, 51, 38, 97, 45 }; //�������� - �Ҳɼ���, ��������, ������ȭ, ���¢��
	table[i++] = { i, 46, -1, -1, -1 }; //Ǫ�� - �뷡�ϱ�
	table[i++] = { i, 46, 49, 110, 2 }; //Ǫũ�� - �뷡�ϱ�, �罽����, ��ũ����, ���ӻ�ġ��
	table[i++] = { i, 140, -1, -1, -1 }; //�ֹ� - ����
	table[i++] = { i, 102, 140, 47, -1 }; //��� - �����Ҹ�, ����, ������
	table[i++] = { i, 70, -1, -1, -1 }; //�ѹ��� - ���
	table[i++] = { i, 70, 76, 77, 78 }; //������ - ���, ������, ��������, ���鰡��
	table[i++] = { i, 76, 77, 78, -1 }; //���÷��þ� - ������, ��������, ���鰡��
	table[i++] = { i, 9, -1, -1, -1 }; //�Ķ� - ������
	table[i++] = { i, 9, 77, 140, -1 }; //�Ķ�Ʈ - ������, ��������, ����
	table[i++] = { i, 32, 49, -1, -1 }; //���� - �����ġ��, �罽����
	table[i++] = { i, 32, 49, 140, 76 }; //������ - �����ġ��, �罽����, ����, ������
	table[i++] = { i, 9, -1, -1, -1 }; //��״� - ������
	table[i++] = { i, 9, 44, 90, 27 }; //��Ʈ���� - ������, �����Ҹ�, �����ı�, �𷡻Ѹ���
	table[i++] = { i, 9, 44, -1, -1 }; //���� - ������, �����Ҹ�
	table[i++] = { i, 9, 44, 43, 102 }; //�丣�ÿ� - ������, �����Ҹ�, ����, �����Ҹ�
	table[i++] = { i, 9, -1, -1, -1 }; //����Ĵ� - ������
	table[i++] = { i, 9, 38, 43, 102 }; //��� - ������, ��������
	table[i++] = { i, 9, 42, -1, -1 }; //��Ű - ������, °������
	table[i++] = { i, 9, 42, 66, -1 }; //������ - ������, °������, �ȴٸ��ɱ�
	table[i++] = { i, 43, 45, -1, -1 }; //���� - ����, ���¢��
	table[i++] = { i, 45, 51, 42, 35 }; //���� - ���¢��, �Ҳɼ���, °������, ����
	table[i++] = { i, 144, -1, -1, -1 }; //��ì�� - ��ǰ
	table[i++] = { i, 144, 94, 54, 102 }; //����ì�� - ��ǰ, �ָ��, ������
	table[i++] = { i, 94, 102, 2, 33 }; //��ì�� - �ָ��, ������, ���ӻ�ġ��, ������
	table[i++] = { i, 99, -1, -1, -1 }; //���̽� - �����̵�
	table[i++] = { i, 99, 92, 49, 133 }; //���ֶ� - �����̵�, ������, �罽����, �������ֱ�
	table[i++] = { i, 99, 92, 49, 133 }; //�ĵ� - �����̵�, ������, �罽����,�������ֱ�
	table[i++] = { i, 1, -1, -1, -1 }; //����� - �±Ǵ��
	table[i++] = { i, 1, 66, 42, -1 }; //������ - �±Ǵ��, �ȴٸ��ɱ�, °������
	table[i++] = { i, 1, 66, 42, -1 }; //���¸� - �±Ǵ��, �ȴٸ��ɱ�, °������
	table[i++] = { i, 21, 73, -1, -1 }; //����� - ����ä��, ����
	table[i++] = { i, 21, 73, 34, 76 }; //������ - ����ä��, ����, ��主��, ������
	table[i++] = { i, 78, 77, 50, 74 }; //������Ʈ - ���鰡��, ��������, ���ؾ�, �ٳ�������
	table[i++] = { i, 50, -1, -1, -1 }; //�մ��� - ���ؾ�
	table[i++] = { i, 50, 47, 34, 39 }; //���ĸ� - ���ؾ�, ������, ��主��, ��ħ
	table[i++] = { i, 32, 73, -1, -1 }; //������ - �����ġ��
	table[i++] = { i, 32, 110, -1, -1 }; //������ - �����ġ��, ��ũ����
	table[i++] = { i, 32, 110, -1, -1 }; //������ - �����ġ��, ��ũ����
	table[i++] = { i, 51, -1, -1, -1 }; //����Ÿ - �Ҳɼ���
	table[i++] = { i, 51, 38, 22, 44 }; //���߸� - �Ҳɼ���, ��������, �����, �����Ҹ�
	table[i++] = { i, 92, -1, -1, -1 }; //�ߵ� - ������
	table[i++] = { i, 92, 49, 28, -1 }; //�ߵ��� - ������, �罽����, ��ġ��
	table[i++] = { i, 32, 48, -1, -1 }; //���� - �����ġ��, �Ҵк�
	table[i++] = { i, 32, 48, 83, -1 }; //�������� - �����ġ��, �Ҵк�, �����ũ
	table[i++] = { i, 63, 27, -1, -1 }; //�Ŀ��� - �ɱ�, �𷡻Ѹ���
	table[i++] = { i, 63, -1, -1, -1 }; //�ε� - �ɱ�
	table[i++] = { i, 63, 44, 30, -1 }; //��Ʈ���� - �ɱ�, �����Ҹ�, �������
	table[i++] = { i, 28, -1, -1, -1 }; //���� - ��ġ��
	table[i++] = { i, 28, 44, 61, -1 }; //�극�� - ��ġ��, �����Ҹ�, ���ζ��
	table[i++] = { i, 0, 49, -1, -1 }; //������ - ��ġ��, �罽����
	table[i++] = { i, 0, 49, 138, -1 }; //������ - ��ġ��, �罽����, ������
	table[i++] = { i, 32, 109, -1, -1 }; //���� - �����ġ��, ����������
	table[i++] = { i, 109, 47, 127, 61 }; //�ĸ��� - ����������, ������, ���������, ���ζ��
	table[i++] = { i, 121, 108, 100, -1 }; //����� - �ӱ�, �̻��Ѻ�, ����Ʈ���
	table[i++] = { i, 121, 108, 100, -1 }; //��콺Ʈ - �ӱ�, �̻��Ѻ�, ����Ʈ���
	table[i++] = { i, 121, 108, 100, -1 }; //���� - �ӱ�, �̻��Ѻ�, ����Ʈ���
	table[i++] = { i, 32, 102, -1, -1 }; //�ս��� - �����ġ��, �����Ҹ�
	table[i++] = { i, 0, 94, -1, -1 }; //������ - ��ġ��, �ָ��
	table[i++] = { i, 0, 94, 49, 92 }; //������ - ��ġ��, �ָ��, �罽����, ������
	table[i++] = { i, 144, 42, -1, -1 }; //ũ�� - ��ǰ, °������
	table[i++] = { i, 144, 42, 10, 11 }; //ŷũ�� - ��ǰ, °������, ���, �����ڸ���
	table[i++] = { i, 32, 102, -1, -1 }; //����� - �����ġ��, �����Ҹ�
	table[i++] = { i, 32, 102, 48, 119 }; //�պ� - �����ġ��, �����Ҹ�, �Ҵк�, ����
	table[i++] = { i, 139, 94, -1, -1 }; //�ƶ� - ����������, �ָ��
	table[i++] = { i, 139, 94, -1, -1 }; //���� - ����������, �ָ��
	table[i++] = { i, 124, 44, -1, -1 }; //������ - ���ٱ�ġ��, �����Ҹ�
	table[i++] = { i, 124, 44, 42, 115 }; //�ֱ��� - ���ٱ�ġ��, �����Ҹ�, °������, ������
	table[i++] = { i, 23, 95, -1, -1 }; //�ö�Ҹ� - �ι�ġ��, �䰡����
	table[i++] = { i, 3, 96, 49, 92 }; //ȫ���� - ������ġ, ����̵�
	table[i++] = { i, 34, 47, -1, -1 }; //����� - ��主��, ������
	table[i++] = { i, 32, 122, -1, -1 }; //�ǰ��� - �����ġ��, �����
	table[i++] = { i, 32, 122, 123, -1 }; //�ǵ����� - �����ġ��, �����, ��������
	table[i++] = { i, 29, -1, -1, -1 }; //��ī�� - �����
	table[i++] = { i, 29, -1, -1, -1 }; //�ڻѸ� - �����
	table[i++] = { i, 0, 2, 38, -1 }; //��Ű - ��ġ��, ���ӻ�ġ��, ��������
	table[i++] = { i, 131, 19, -1, -1 }; //���� - �ְ���, ���̱�
	table[i++] = { i, 3, 98, -1, -1 }; //ŷī - ������ġ, �г�
	table[i++] = { i, 144, -1, -1, -1 }; //���� - ��ǰ
	table[i++] = { i, 144, 107, 42, 54 }; //�õ�� - ��ǰ, ����, °������, ������
	table[i++] = { i, 63, 38, -1, -1 }; //��ġ - �ɱ�, ��������
	table[i++] = { i, 63, 38, 47, 29 }; //����ġ - �ɱ�, ��������, ������, �����
	table[i++] = { i, 32, -1, -1, -1 }; //�����縮 - �����ġ��
	table[i++] = { i, 32, 105, 54, -1 }; //����Ÿ - �����ġ��, �ܴ�������, ������
	table[i++] = { i, 92, 111, -1, -1 }; //���Ӹ� - ������, �踮��
	table[i++] = { i, 97, 42, 115, -1 }; //����ũ - ������ȭ, °������, ������
	table[i++] = { i, 0, 121, 141, -1 }; //���ֶ� - ��ġ��, �ӱ�, �Ǹ���Ű��
	table[i++] = { i, 97, 42, -1, -1 }; //������ - ������ȭ, °������
	table[i++] = { i, 51, -1, -1, -1 }; //���׸� - �Ҳɼ���
	table[i++] = { i, 10, -1, -1, -1 }; //�ڻ����� - ���
	table[i++] = { i, 32, 22, -1, -1 }; //��Ÿ�ν� - �����ġ��, �����
	table[i++] = { i, 149, -1, -1, -1 }; //�׾�ŷ - Ƣ�������
	table[i++] = { i, 32, -1, -1, -1 }; //���󵵽� - �����ġ��
	table[i++] = { i, 54, 44, -1, -1 }; //������ - ������, �����Ҹ�
	table[i++] = { i, 143, -1, -1, -1 }; //��Ÿ�� - ����
	table[i++] = { i, 32, 27, 44, 97 }; //�̺��� - �����ġ��, �𷡻Ѹ���, �����Ҹ�, ������ȭ
	table[i++] = { i, 32, 27, -1, -1 }; //���̵� - �����ġ��, �𷡻Ѹ���
	table[i++] = { i, 32, 38, 97, 83 }; //���ǽ�� - �����ġ��, ��������, ������ȭ, �����ũ
	table[i++] = { i, 32, 38, 97, 51 }; //�ν��� - �����ġ��, ��������, ������ȭ, �Ҳɼ���
	table[i++] = { i, 32, 158, 159, 59 }; //������ - �����ġ��, ������, �ؽ�ó, ȯ���
	table[i++] = { i, 102, 109, -1, -1 }; //�ϳ���Ʈ - ������, ����������
	table[i++] = { i, 102, 109, 29, 42 }; //�Ͻ�Ÿ - ������, ����������, �����, °������
	table[i++] = { i, 9, 105, -1, -1 }; //���� - ������, �ܴ�������
	table[i++] = { i, 9, 105, 70, 162 }; //����Ǫ�� - ������, �ܴ�������, ���, �������
	table[i++] = { i, 16, 96, -1, -1 }; //���׶� - ����ġ��, ����̵�
	table[i++] = { i, 28, 132, 155, -1 }; //�Ḹ�� - ��ġ��, ������, ���ڱ�
	table[i++] = { i, 63, 57, -1, -1 }; //������ - �ɱ�, �õ���
	table[i++] = { i, 64, 83, -1, -1 }; //��� - ȸ���θ�, �����ũ
	table[i++] = { i, 63, 82, -1, -1 }; //���̾� - �ɱ�, ȸ�����Ҳ�
	table[i++] = { i, 34, 42, -1, -1 }; //�̴� - ��主��, °������
	table[i++] = { i, 34, 42, 85, 96 }; //�Ŵ� - ��主��, °������, �����ڼ���, ����̵�
	table[i++] = { i, 34, 42, 85, 96 }; //������ - ��主��, °������, �����ڼ���, ����̵�
	table[i++] = { i, 92, 49, 128, -1 }; //���� - ������, �罽����, ���ǵ彺Ÿ
	table[i++] = { i, 0, -1, -1, -1 }; //�� - ��ġ��

	if (fout.fail() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			fout << table[i].pokemonIndex << " "
				<< table[i].skill[0] << " "
				<< table[i].skill[1] << " "
				<< table[i].skill[2] << " "
				<< table[i].skill[3] << std::endl;
		}
		fout.close();
	}

	delete[] table;
}

void PokemonManager::LoadPokemonTable()
{
	std::ifstream fout;

	fout.open("DB/SkillTable.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			PokemonTable temp;
			fout >> temp.pokemonIndex
				>> temp.skill[0]
				>> temp.skill[1]
				>> temp.skill[2]
				>> temp.skill[3];
			m_pokemonTable.push_back(temp);
		}
		fout.close();
	}
}

void PokemonManager::RootMyPokemon()
{
	m_pokemonCount = 5;

	m_myPokemonList[0].m_data = POKEDEX.GetPokemonData(36);
	m_myPokemonList[0].m_level = 65;
	m_myPokemonList[0].m_sex =1;
	m_myPokemonList[0].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[0].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[0].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[0].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[0].m_hpMax = 2500;
	m_myPokemonList[0].m_hp = 2500;
	strcpy_s(m_myPokemonList[0].m_nickname, 20, m_myPokemonList[0].m_data.m_name);

	m_myPokemonList[1].m_data = POKEDEX.GetPokemonData(37);
	m_myPokemonList[1].m_level = 55;
	m_myPokemonList[1].m_sex = 0;
	m_myPokemonList[1].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[1].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[1].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[1].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[1].m_hpMax = m_myPokemonList[1].m_level * 50;
	m_myPokemonList[1].m_hp = m_myPokemonList[1].m_level * 40;
	strcpy_s(m_myPokemonList[1].m_nickname, 20, m_myPokemonList[1].m_data.m_name);

	m_myPokemonList[2].m_data = POKEDEX.GetPokemonData(148);
	m_myPokemonList[2].m_level = 48;
	m_myPokemonList[2].m_sex = 0;
	m_myPokemonList[2].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[2].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[2].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[2].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[2].m_hpMax = m_myPokemonList[2].m_level * 50;
	m_myPokemonList[2].m_hp = m_myPokemonList[2].m_level * 25;
	strcpy_s(m_myPokemonList[2].m_nickname, 20, m_myPokemonList[2].m_data.m_name);

	m_myPokemonList[3].m_data = POKEDEX.GetPokemonData(72);
	m_myPokemonList[3].m_level = 92;
	m_myPokemonList[3].m_sex = 1;
	m_myPokemonList[3].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[3].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[3].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[3].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[3].m_hpMax = m_myPokemonList[3].m_level * 50;
	m_myPokemonList[3].m_hp = m_myPokemonList[3].m_level * 10;
	strcpy_s(m_myPokemonList[3].m_nickname, 20, m_myPokemonList[3].m_data.m_name);

	m_myPokemonList[4].m_data = POKEDEX.GetPokemonData(44);
	m_myPokemonList[4].m_level = 82;
	m_myPokemonList[4].m_sex = 1;
	m_myPokemonList[4].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[4].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[4].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[4].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[4].m_hpMax = m_myPokemonList[4].m_level * 50;
	m_myPokemonList[4].m_hp = m_myPokemonList[4].m_hpMax;
	strcpy_s(m_myPokemonList[4].m_nickname, 20, m_myPokemonList[4].m_data.m_name);
}

void PokemonManager::Init()
{
	//SaveMyPokemon();
	LoadMyPokemon();
	SaveNPCPokemon();
	LoadNPCPokemon();
	SavePokemonTable();
	LoadPokemonTable();
}

void PokemonManager::SetMyPokemonList(Pokemon* _pokemonList, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		m_myPokemonList[i] = _pokemonList[i];
	}

	m_pokemonCount = _size;
}

Pokemon* PokemonManager::GetMyPokemonList()
{
	return m_myPokemonList;
}

Pokemon PokemonManager::GetMyPokemon(int _index)
{
	if (_index >= 6) return Pokemon();
	else return m_myPokemonList[_index];
}

Pokemon* PokemonManager::GetSelectedMyPokemon()
{
	return &m_myPokemonList[m_currentMyIndex];
}

int PokemonManager::GetSelectedPokemonNumber()
{
	return m_currentMyIndex;
}

void PokemonManager::SetSelectedMyPokemon(int _index)
{
	m_currentMyIndex = _index;
}

void PokemonManager::SettingBattleList()
{
	for (int i = 0; i < 6; i++)
	{
		m_battleList[i] = m_myPokemonList[i];
	}
}

Pokemon PokemonManager::GetMyBattlePokemon(int _index)
{
	if (_index >= 6) return Pokemon();
	else return m_battleList[_index];
}

Pokemon* PokemonManager::GetSelectedBattlePokemon()
{
	return &m_battleList[m_currentMyIndex];
}

void PokemonManager::SwapPokemon(int _swapIndex)
{
	Pokemon tmp = m_battleList[_swapIndex];
	m_battleList[_swapIndex] = m_battleList[0];
	m_battleList[0] = tmp;
}

void PokemonManager::SetEnemyPokemonList(int _npcNumber)
{
	EnemyPokemonTable* table = new EnemyPokemonTable;
	for (int i = 0; i < m_enemyTable.size(); i++)
	{
		if (m_enemyTable[i].npcNumber == _npcNumber)
		{
			table = &m_enemyTable[i];
		}
	}
	for (int i = 0; i < 6; i++)
	{
		Pokemon* temp = &m_enemyPokemonList[i];
		temp->m_data = POKEDEX.GetPokemonData(table->PokemonList[i].pokemonIndex);
		temp->m_level = 35;
		temp->m_sex = rand() % 2;
		temp->m_skill[0] = SKILL_MANAGER.GetSkill(16);
		temp->m_skill[1] = SKILL_MANAGER.GetSkill(70);
		temp->m_skill[2] = SKILL_MANAGER.GetSkill(93);
		temp->m_skill[3] = SKILL_MANAGER.GetSkill(108);
		temp->m_hpMax = 1200;
		temp->m_hp = temp->m_hpMax;
	}
}

Pokemon* PokemonManager::GetEnemyPokemonList(int _npcNumber)
{
	return m_enemyPokemonList;
}

Pokemon* PokemonManager::GetSelectedEnemyPokemon()
{
	return &m_enemyPokemonList[m_currentEnemyIndex];
}

void PokemonManager::SetSelectedEnemyPokemon(int _index)
{
	m_currentEnemyIndex = _index;
}

void PokemonManager::GeneratePokemon(int _area)
{	
	m_wildPokemon.m_condition = CONDITION::NO_CONDITION;
	m_wildPokemon.m_sex = rand() % 2;

	//������ ���� �����Ǵ� ���ϸ����� �ٸ��� ó��
	switch (_area)
	{
	case 0:
	{
		int indexList[3] = { 12,55,73 }; //���� ���ϸ� ��ȣ
		m_wildPokemon.m_data = POKEDEX.GetPokemonData(indexList[(rand()%3)]);
		m_wildPokemon.m_level = 6;
		m_wildPokemon.m_hpMax = 100 * m_wildPokemon.m_level;
		m_wildPokemon.m_hp = m_wildPokemon.m_hpMax;
		m_wildPokemon.m_giveExp = 50 * m_wildPokemon.m_level;
		m_wildPokemon.m_requiredExp = 300 * m_wildPokemon.m_level;
		m_wildPokemon.m_currentExp = 0;
		for (int i = 0; i < 4; i++)
		{
			m_wildPokemon.m_skill[i] = SKILL_MANAGER.GetSkillByType(m_wildPokemon.m_data.m_type_1, m_wildPokemon.m_data.m_type_2);
		}
	}break;
	}
	
}

Pokemon* PokemonManager::GetWildPokemon()
{
	return &m_wildPokemon;
}

void PokemonManager::CatchPokemon()
{
	//����ִ� ���ϸ��� 6�������, ���Ϲڽ��� ����
	if (m_pokemonCount == 6)
	{

	}
	//�ƴ϶�� ���濡 �߰�
	else
	{
		m_myPokemonList[5].m_data		= m_wildPokemon.m_data;
		m_myPokemonList[5].m_level		= m_wildPokemon.m_level;
		m_myPokemonList[5].m_sex		= m_wildPokemon.m_sex;
		m_myPokemonList[5].m_skill[0]	= m_wildPokemon.m_skill[0];
		m_myPokemonList[5].m_skill[1]	= m_wildPokemon.m_skill[1];
		m_myPokemonList[5].m_skill[2]	= m_wildPokemon.m_skill[2];
		m_myPokemonList[5].m_skill[3]	= m_wildPokemon.m_skill[3];
		m_myPokemonList[5].m_hpMax		= m_wildPokemon.m_hpMax;
		m_myPokemonList[5].m_hp			= m_wildPokemon.m_hp;
		strcpy_s(m_myPokemonList[5].m_nickname, 20, m_myPokemonList[5].m_data.m_name);

		m_wildPokemon = {};
		m_pokemonCount = 6;
	}
}

void PokemonManager::HealPokemon()
{
	for (auto p : m_myPokemonList)
	{
		p.m_hp = p.m_hpMax;
	}
}
