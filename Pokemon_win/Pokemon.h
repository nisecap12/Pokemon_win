#pragma once
#include "Skill.h"

struct PokemonTable
{
	short pokemonIndex;
	short skill[4];
};

struct EnemyPokemonTable
{
	short npcNumber;
	PokemonTable PokemonList[6];
};

class PokedexData
{
public:
	short m_number;			//���ϸ� ��ȣ
	char m_name[20];		//�� �̸�
	short m_type_1;			//Ÿ��1
	short m_type_2;			//Ÿ��2
	short m_evolutionLevel;	// �� ��ȭ �ܰ�
	short m_evolvedLevel;	// ��ȭ �ܰ�
};

class Pokemon
{
	friend class PokemonManager;

public:
	PokedexData m_data;				//���ϸ� ������
	char m_nickname[20];			//�г���
	bool m_sex;						//����
	Skill m_skill[4] = {};			//���� ��ų
	short m_level;					//����
	short m_hp;						//ü��
	short m_hpMax;					//�ִ� ü�� 
	short m_condition;				//�����̻�
	unsigned short m_giveExp;		//�ִ°���ġ
	unsigned short m_currentExp;	//�������ġ
	unsigned short m_requiredExp;	//�ʿ����ġ

public:
	Pokemon();
	~Pokemon();
};