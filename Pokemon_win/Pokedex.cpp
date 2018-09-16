#include "stdafx.h"
#include "Pokedex.h"

Pokedex::Pokedex()
{
}


Pokedex::~Pokedex()
{
	m_pokemonList.clear();
}

void Pokedex::SavePokemon()
{
	PokedexData* pokemon = new PokedexData[POKEMON_TOTAL_NUMBER];
	short i = 0;

	/*
	short m_number;			//���ϸ� ��ȣ
	char m_name[20];		//�� �̸�
	short m_type_1;			//Ÿ��1
	short m_type_2;			//Ÿ��2
	short m_evolutionLevel;	// �� ��ȭ �ܰ�
	short m_evolvedLevel;	// ��ȭ �ܰ�
	*/

	pokemon[i++] = { i, "�̻��ؾ�", Type::GRASS, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "�̻���Ǯ", Type::GRASS, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "�̻��ز�", Type::GRASS, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "���̸�", Type::FIRE, Type::FIRE, 3, 1 };
	pokemon[i++] = { i, "���ڵ�", Type::FIRE, Type::FIRE, 3, 2 };
	pokemon[i++] = { i, "���ڸ�", Type::FIRE, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "���α�", Type::WATER, Type::WATER, 3, 1 };
	pokemon[i++] = { i, "��Ϻα�", Type::WATER, Type::WATER, 3, 2 };
	pokemon[i++] = { i, "�źϿ�", Type::WATER, Type::WATER, 3, 3 };
	pokemon[i++] = { i, "ĳ����", Type::BUG, Type::BUG, 3, 1 };
	pokemon[i++] = { i, "�ܵ���", Type::BUG, Type::BUG, 3, 2 };
	pokemon[i++] = { i, "������", Type::BUG, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "������", Type::BUG, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "������", Type::BUG, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "��ħ��", Type::BUG, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "����", Type::NORMAL, Type::FLY, 3, 1 };
	pokemon[i++] = { i, "����", Type::NORMAL, Type::FLY, 3, 2 };
	pokemon[i++] = { i, "������", Type::NORMAL, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "����", Type::NORMAL, Type::NORMAL, 2, 1 };
	pokemon[i++] = { i, "��Ʈ��", Type::NORMAL, Type::NORMAL, 2, 2 };
	pokemon[i++] = { i, "������", Type::NORMAL, Type::FLY, 2, 1 };
	pokemon[i++] = { i, "����帱��", Type::NORMAL, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "�ƺ�", Type::POISON, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "�ƺ�ũ", Type::POISON, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "��ī��", Type::THUNDER, Type::THUNDER, 2, 1 };
	pokemon[i++] = { i, "������", Type::THUNDER, Type::THUNDER, 2, 2 };
	pokemon[i++] = { i, "�𷡵���", Type::GROUND, Type::GROUND, 2, 1 };
	pokemon[i++] = { i, "����", Type::GROUND, Type::GROUND, 2, 2 };
	pokemon[i++] = { i, "�ϵ己��", Type::POISON, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "�ϵ帮��", Type::POISON, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "�ϵ���", Type::POISON, Type::GROUND, 3, 3 };
	pokemon[i++] = { i, "�ϵ己��", Type::POISON, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "�ϵ帮��", Type::POISON, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "�ϵ�ŷ", Type::POISON, Type::GROUND, 3, 3 };
	pokemon[i++] = { i, "�߻�", Type::FAIRY, Type::FAIRY, 2, 1 };
	pokemon[i++] = { i, "�Ƚ�", Type::FAIRY, Type::FAIRY, 2, 2 };
	pokemon[i++] = { i, "�Ľ�����", Type::FIRE, Type::FIRE, 2, 1 };
	pokemon[i++] = { i, "��������", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "Ǫ��", Type::NORMAL, Type::FAIRY, 2, 1 };
	pokemon[i++] = { i, "Ǫũ��", Type::NORMAL, Type::FAIRY, 2, 2 };
	pokemon[i++] = { i, "�ֹ�", Type::POISON, Type::FLY, 2, 1 };
	pokemon[i++] = { i, "���", Type::POISON, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "�ѹ���", Type::GRASS, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "������", Type::GRASS, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "���÷��þ�", Type::GRASS, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "�Ķ�", Type::BUG, Type::GRASS, 2, 1 };
	pokemon[i++] = { i, "�Ķ�Ʈ", Type::BUG, Type::GRASS, 2, 2 };
	pokemon[i++] = { i, "����", Type::BUG, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "������", Type::BUG, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "��״�", Type::GROUND, Type::GROUND, 2, 1 };
	pokemon[i++] = { i, "��Ʈ����", Type::GROUND, Type::GROUND, 2, 2 };
	pokemon[i++] = { i, "����", Type::NORMAL, Type::NORMAL, 2, 1 };
	pokemon[i++] = { i, "�丣�ÿ�", Type::NORMAL, Type::NORMAL, 2, 2 };
	pokemon[i++] = { i, "����Ĵ�", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "���", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "��Ű", Type::FIGHT, Type::FIGHT, 2, 1 };
	pokemon[i++] = { i, "������", Type::FIGHT, Type::FIGHT, 2, 2 };
	pokemon[i++] = { i, "����", Type::FIRE, Type::FIRE, 2, 1 };
	pokemon[i++] = { i, "����", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "��ì��", Type::WATER, Type::WATER, 3, 1 };
	pokemon[i++] = { i, "����ì��", Type::WATER, Type::WATER, 3, 2 };
	pokemon[i++] = { i, "��ì��", Type::WATER, Type::FIGHT, 3, 3 };
	pokemon[i++] = { i, "���̽�", Type::ESPER, Type::ESPER, 3, 1 };
	pokemon[i++] = { i, "���ֶ�", Type::ESPER, Type::ESPER, 3, 2 };
	pokemon[i++] = { i, "�ĵ�", Type::ESPER, Type::ESPER, 3, 3 };
	pokemon[i++] = { i, "�����", Type::FIGHT, Type::FIGHT, 3, 1 };
	pokemon[i++] = { i, "������", Type::FIGHT, Type::FIGHT, 3, 2 };
	pokemon[i++] = { i, "���¸�", Type::FIGHT, Type::FIGHT, 3, 3 };
	pokemon[i++] = { i, "�����", Type::GRASS, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "������", Type::GRASS, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "������Ʈ", Type::GRASS, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "�մ���", Type::WATER, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "���ĸ�", Type::WATER, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "������", Type::ROCK, Type::GROUND, 3, 1 };
	pokemon[i++] = { i, "������", Type::ROCK, Type::GROUND, 3, 2 };
	pokemon[i++] = { i, "������", Type::ROCK, Type::GROUND, 3, 3 };
	pokemon[i++] = { i, "����Ÿ", Type::FIRE, Type::FIRE, 2, 1 };
	pokemon[i++] = { i, "���߸�", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "�ߵ�", Type::WATER, Type::ESPER, 2, 1 };
	pokemon[i++] = { i, "�ߵ���", Type::WATER, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "����", Type::THUNDER, Type::STEEL, 2, 1 };
	pokemon[i++] = { i, "��������", Type::THUNDER, Type::STEEL, 2, 2 };
	pokemon[i++] = { i, "�Ŀ���", Type::NORMAL, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "�ε�", Type::NORMAL, Type::FLY, 2, 1 };
	pokemon[i++] = { i, "��Ʈ����", Type::NORMAL, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "����", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "�극��", Type::WATER, Type::ICE, 2, 2 };
	pokemon[i++] = { i, "������", Type::POISON, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "������", Type::POISON, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "����", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "�ĸ���", Type::WATER, Type::ICE, 2, 2 };
	pokemon[i++] = { i, "�����", Type::GHOST, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "��콺Ʈ", Type::GHOST, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "����", Type::GHOST, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "�ս���", Type::ROCK, Type::GROUND, 1, 1 };
	pokemon[i++] = { i, "������", Type::ESPER, Type::ESPER, 2, 1 };
	pokemon[i++] = { i, "������", Type::ESPER, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "ũ��", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "ŷũ��", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "�����", Type::THUNDER, Type::THUNDER, 2, 1 };
	pokemon[i++] = { i, "�պ�", Type::THUNDER, Type::THUNDER, 2, 2 };
	pokemon[i++] = { i, "�ƶ�", Type::GRASS, Type::ESPER, 2, 1 };
	pokemon[i++] = { i, "����", Type::GRASS, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "������", Type::GROUND, Type::GROUND, 2, 1 };
	pokemon[i++] = { i, "�ֱ���", Type::GROUND, Type::GROUND, 2, 2 };
	pokemon[i++] = { i, "�ö�Ҹ�", Type::FIGHT, Type::FIGHT, 2, 1 };
	pokemon[i++] = { i, "ȫ����", Type::FIGHT, Type::FIGHT, 2, 2 };
	pokemon[i++] = { i, "�����", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "�ǰ���", Type::POISON, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "�ǵ�����", Type::POISON, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "��ī��", Type::GROUND, Type::ROCK, 2, 1 };
	pokemon[i++] = { i, "�ڻѸ�", Type::GROUND, Type::ROCK, 2, 2 };
	pokemon[i++] = { i, "��Ű", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "����", Type::GRASS, Type::GRASS, 1, 1 };
	pokemon[i++] = { i, "Ļī", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "����", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "�õ��", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "��ġ", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "����ġ", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "�����縮", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "����Ÿ", Type::WATER, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "���Ӹ�", Type::ESPER, Type::FAIRY, 1, 1 };
	pokemon[i++] = { i, "����ũ", Type::BUG, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "���ֶ�", Type::ICE, Type::ESPER, 1, 1 };
	pokemon[i++] = { i, "������", Type::THUNDER, Type::THUNDER, 1, 1 };
	pokemon[i++] = { i, "���׸�", Type::FIRE, Type::FIRE, 1, 1 };
	pokemon[i++] = { i, "�ڻ�����", Type::BUG, Type::BUG, 1, 1 };
	pokemon[i++] = { i, "��Ÿ�ν�", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "�׾�ŷ", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "���󵵽�", Type::WATER, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "������", Type::WATER, Type::ICE, 1, 1 };
	pokemon[i++] = { i, "��Ÿ��", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "�̺���", Type::NORMAL, Type::NORMAL, 2, 1 };
	pokemon[i++] = { i, "���̵�", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "���ǽ��", Type::THUNDER, Type::THUNDER, 2, 2 };
	pokemon[i++] = { i, "�ν���", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "������", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "�ϳ���Ʈ", Type::ROCK, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "�Ͻ�Ÿ", Type::ROCK, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "����", Type::ROCK, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "����Ǫ��", Type::ROCK, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "���׶�", Type::ROCK, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "�Ḹ��", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "������", Type::ICE, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "���", Type::THUNDER, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "���̾�", Type::FIRE, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "�̴�", Type::DRAGON, Type::DRAGON, 3, 1 };
	pokemon[i++] = { i, "�Ŵ�", Type::DRAGON, Type::DRAGON, 3, 2 };
	pokemon[i++] = { i, "������", Type::DRAGON, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "����", Type::ESPER, Type::ESPER, 1, 1 };
	pokemon[i++] = { i, "��", Type::ESPER, Type::ESPER, 1, 1 };

	std::ofstream fout("DB/Pokedex.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < POKEMON_TOTAL_NUMBER; i++)
		{
			fout << pokemon[i].m_number << " "
				<< pokemon[i].m_name << " "
				<< pokemon[i].m_type_1 << " "
				<< pokemon[i].m_type_2 << " "
				<< pokemon[i].m_evolutionLevel << " "
				<< pokemon[i].m_evolvedLevel << std::endl;
		}
		fout.close();
	}

	delete[] pokemon;
}

void Pokedex::LoadPokemon()
{
	std::ifstream fout;

	//NPC.db ���� ����
	fout.open("DB/Pokedex.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < POKEMON_TOTAL_NUMBER; i++)
		{
			PokedexData temp;
			fout >> temp.m_number
				>> temp.m_name
				>> temp.m_type_1
				>> temp.m_type_2
				>> temp.m_evolutionLevel
				>> temp.m_evolvedLevel;
			m_pokemonList.push_back(temp);
		}
		fout.close();
	}
}

void Pokedex::Init()
{
	SavePokemon();
	LoadPokemon();
}

PokedexData Pokedex::GetPokemonData(short _number)
{
	if (_number >= 0)
	{
		return m_pokemonList[_number];
	}
	else
	{
		return PokedexData();
	}
}

const char * Pokedex::GetType(short _type)
{
	switch (_type)
	{
	case Type::NORMAL: return "�븻";
	case Type::FIRE: return "��";
	case Type::WATER:	return "��";
	case Type::GRASS:	return "Ǯ";
	case Type::THUNDER:	return "����";
	case Type::ICE:	return "����";
	case Type::FIGHT:	return "����";
	case Type::POISON:	return "��";
	case Type::GROUND:	return "��";
	case Type::FLY:	return "����";
	case Type::ESPER: return "������";
	case Type::BUG: return "����";
	case Type::ROCK: return "����";
	case Type::GHOST: return "��Ʈ";
	case Type::DRAGON: return "�巡��";
	case Type::EVIL: return "��";
	case Type::STEEL: return "��ö";
	case Type::FAIRY: return "��";
	}
}

const char * Pokedex::GetSpecial()
{
	const char* list[20] =
	{ "�˰���", "����", "����", "����", "������",
	"����", "�а�", "�������̽�", "�κ�", "����",
	"��ĥ���Ǻ�", "������", "�ڷ�", "���ŷ�", "Ʈ���̽�",
	"�𷡳���", "���Ӹ�", "��������", "�ɷ�", "����" };

	return list[rand() % 20];
}
