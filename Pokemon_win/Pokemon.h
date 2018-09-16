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
	short m_number;			//포켓몬 번호
	char m_name[20];		//종 이름
	short m_type_1;			//타입1
	short m_type_2;			//타입2
	short m_evolutionLevel;	// 총 진화 단계
	short m_evolvedLevel;	// 진화 단계
};

class Pokemon
{
	friend class PokemonManager;

public:
	PokedexData m_data;				//포켓몬 데이터
	char m_nickname[20];			//닉네임
	bool m_sex;						//성별
	Skill m_skill[4] = {};			//보유 스킬
	short m_level;					//레벨
	short m_hp;						//체력
	short m_hpMax;					//최대 체력 
	short m_condition;				//상태이상
	unsigned short m_giveExp;		//주는경험치
	unsigned short m_currentExp;	//현재경험치
	unsigned short m_requiredExp;	//필요경험치

public:
	Pokemon();
	~Pokemon();
};