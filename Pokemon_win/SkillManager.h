#pragma once
#include "Skill.h"

enum Type
{
	NORMAL,
	FIGHT,
	FLY,
	POISON,
	GROUND,
	ROCK,
	BUG,
	GHOST,
	STEEL,
	EVIL,
	FIRE,
	WATER,
	GRASS,
	THUNDER,
	ESPER,
	ICE,
	DRAGON,
	FAIRY,
};

class SkillManager
{
private:
	std::vector<Skill> m_skillList;

private:
	SkillManager();
	~SkillManager();
	void SaveSkill();
	void LoadSkill();

public:
	static SkillManager& GetInstance()
	{
		static SkillManager Instance;
		return Instance;
	}

	void Init();
	Skill GetSkill(int _skillNumber);
	Skill GetSkillByType(int _type1, int _type2);
	float GetDamageRate(int _typeA, int _typeB);
};

#define SKILL_MANAGER SkillManager::GetInstance()