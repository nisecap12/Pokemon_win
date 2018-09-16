#include "stdafx.h"
#include "SkillManager.h"


SkillManager::SkillManager()
{
}


SkillManager::~SkillManager()
{
	m_skillList.clear();
}

void SkillManager::SaveSkill()
{
	Skill* skill = new Skill[SKILL_TOTAL_NUMBER];
	
	/*
	skill - { number, skill name, type, damage, accuracy, PP}
	��ȣ		- ��ų ������ȣ
	��ų��	- ��ų �̸�
	�Ӽ�		- ��ų �Ӽ�
	����		- ��ų ����(������)
	���߷�	- ��ų ���߷� n%
	PP		- ��ų �������� Ƚ��
	*/

	unsigned short i = 0;
	skill[i++] = { i, "��ġ��", NORMAL, 40, 100, 35 };
	skill[i++] = { i, "�±Ǵ��", FIGHT, 50, 100, 25 };
	skill[i++] = { i, "���ӻ�ġ��", NORMAL, 15, 85, 10 };
	skill[i++] = { i, "������ġ", NORMAL, 18, 85, 15 };
	skill[i++] = { i, "�ް�����ġ", NORMAL, 80, 85, 20 };
	skill[i++] = { i, "����̵��ޱ�", NORMAL, 40, 100, 20 };
	skill[i++] = { i, "�Ҳ���ġ", FIRE, 75, 100, 15 };
	skill[i++] = { i, "�õ���ġ", ICE, 75, 100, 15 };
	skill[i++] = { i, "������ġ", THUNDER, 75, 100, 15 };
	skill[i++] = { i, "������", NORMAL, 40, 100, 35 };
	skill[i++] = { i, "���", NORMAL, 55, 100, 30 };
	skill[i++] = { i, "�����ڸ���", NORMAL, 0, 0, 5 };
	skill[i++] = { i, "Į�ٶ�", NORMAL, 80, 100, 10 };
	skill[i++] = { i, "Į��", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "Ǯ����", NORMAL, 50, 95, 30 };
	skill[i++] = { i, "�ٶ�����Ű��", FLY, 40, 100, 35 };
	skill[i++] = { i, "����ġ��", FLY, 60, 100, 35 };
	skill[i++] = { i, "����������", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "���߳���", FLY, 90, 95, 15 };
	skill[i++] = { i, "���̱�", NORMAL, 15, 85, 20 };
	skill[i++] = { i, "����ġ��", NORMAL, 80, 75, 20 };
	skill[i++] = { i, "����ä��", GRASS, 45, 100, 25 };
	skill[i++] = { i, "�����", NORMAL, 65, 100, 20 };
	skill[i++] = { i, "�ι�ġ��", FIGHT, 30, 100, 30 };
	skill[i++] = { i, "�ް���ű", NORMAL, 120, 75, 5 };
	skill[i++] = { i, "����ű", FIGHT, 100, 95, 10 };
	skill[i++] = { i, "��������", FIGHT, 60, 85, 15 };
	skill[i++] = { i, "�𷡻Ѹ���", GROUND, 0, 100, 15 };
	skill[i++] = { i, "��ġ��", NORMAL, 70, 100, 15 };
	skill[i++] = { i, "�����", NORMAL, 65, 100, 25 };
	skill[i++] = { i, "�������", NORMAL, 15, 85, 20 };
	skill[i++] = { i, "�Ե帱", NORMAL, 0, 0, 5 };
	skill[i++] = { i, "�����ġ��", NORMAL, 50, 100, 35 };
	skill[i++] = { i, "������", NORMAL, 85, 100, 15 };
	skill[i++] = { i, "��主��", NORMAL, 15, 90, 20 };
	skill[i++] = { i, "����", NORMAL, 90, 85, 20 };
	skill[i++] = { i, "�����θ���", NORMAL, 120, 100, 10 };
	skill[i++] = { i, "���ǻ�����Ŭ", NORMAL, 120, 100, 15 };
	skill[i++] = { i, "��������", NORMAL, 0, 100, 30 };
	skill[i++] = { i, "��ħ", POISON, 15, 100, 35 };
	skill[i++] = { i, "����ϵ�", BUG, 25, 100, 20 };
	skill[i++] = { i, "�ٴù̻���", BUG, 14, 85, 20 };
	skill[i++] = { i, "°������", NORMAL, 0, 100, 30 };
	skill[i++] = { i, "����", EVIL, 60, 100, 25 };
	skill[i++] = { i, "�����Ҹ�", NORMAL, 0, 100, 40 };
	skill[i++] = { i, "���¢��", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "�뷡�ϱ�", NORMAL, 0, 55, 15 };
	skill[i++] = { i, "������", NORMAL, 0, 55, 20 };
	skill[i++] = { i, "�Ҵк�", NORMAL, 0, 90, 20 };
	skill[i++] = { i, "�罽����", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "���ؾ�", POISON, 40, 100, 30 };
	skill[i++] = { i, "�Ҳɼ���", FIRE, 40, 100, 25 };
	skill[i++] = { i, "ȭ�����", FIRE, 90, 100, 15 };
	skill[i++] = { i, "��Ȱ�", ICE, 0, 0, 30 };
	skill[i++] = { i, "������", WATER, 40, 100, 25 };
	skill[i++] = { i, "���̵������", WATER, 110, 80, 5 };
	skill[i++] = { i, "�ĵ�Ÿ��", WATER, 90, 100, 15 };
	skill[i++] = { i, "�õ���", ICE, 90, 100, 10 };
	skill[i++] = { i, "������", ICE, 110, 70, 5 };
	skill[i++] = { i, "ȯ���", ESPER, 65, 100, 20 };
	skill[i++] = { i, "��ǰ����", WATER, 65, 100, 20 };
	skill[i++] = { i, "���ζ��", ICE, 65, 100, 20 };
	skill[i++] = { i, "�ı�����", NORMAL, 150, 90, 5 };
	skill[i++] = { i, "�ɱ�", FLY, 35, 100, 35 };
	skill[i++] = { i, "ȸ���θ�", FLY, 80, 100, 20 };
	skill[i++] = { i, "�����ǹ���", FIGHT, 80, 80, 25 };
	skill[i++] = { i, "�ȴٸ��ɱ�", FIGHT, 0, 100, 20 };
	skill[i++] = { i, "ī����", FIGHT, 0, 100, 20 };
	skill[i++] = { i, "����������", FIGHT, 0, 100, 20 };
	skill[i++] = { i, "����", NORMAL, 80, 100, 15 };
	skill[i++] = { i, "���", GRASS, 20, 100, 25 };
	skill[i++] = { i, "�ް��巹��", GRASS, 40, 100, 15 };
	skill[i++] = { i, "���Ѹ���", GRASS, 0, 90, 10 };
	skill[i++] = { i, "����", NORMAL, 0, 0, 40 };
	skill[i++] = { i, "�ٳ�������", GRASS, 55, 95, 25 };
	skill[i++] = { i, "�ֶ��", GRASS, 120, 100, 10 };
	skill[i++] = { i, "������", POISON, 0, 75, 35 };
	skill[i++] = { i, "��������", GRASS, 0, 75, 30 };
	skill[i++] = { i, "���鰡��", GRASS, 0, 75, 15 };
	skill[i++] = { i, "���ٴ�", GRASS, 120, 100, 10 };
	skill[i++] = { i, "�ǻձ�", BUG, 0, 95, 40 };
	skill[i++] = { i, "���Ǻг�", DRAGON, 0, 100, 10 };
	skill[i++] = { i, "ȸ�����Ҳ�", FIRE, 35, 85, 15 };
	skill[i++] = { i, "�����ũ", THUNDER, 40, 100, 30 };
	skill[i++] = { i, "10����Ʈ", THUNDER, 90, 100, 15 };
	skill[i++] = { i, "�����ڼ���", THUNDER, 0, 100, 20 };
	skill[i++] = { i, "����", THUNDER, 100, 70, 10 };
	skill[i++] = { i, "��������", ROCK, 50, 90, 15 };
	skill[i++] = { i, "����", GROUND, 100, 100, 10 };
	skill[i++] = { i, "��������", GROUND, 0, 0, 5 };
	skill[i++] = { i, "�����ı�", GROUND, 80, 100, 10 };
	skill[i++] = { i, "�͵�", POISON, 0, 90, 10 };
	skill[i++] = { i, "������", ESPER, 50, 100, 25 };
	skill[i++] = { i, "������Ű�׽ý�", ESPER, 90, 100, 10 };
	skill[i++] = { i, "�ָ��", ESPER, 0, 60, 20 };
	skill[i++] = { i, "�䰡����", ESPER, 0, 0, 40 };
	skill[i++] = { i, "����̵�", ESPER, 0, 0, 30 };
	skill[i++] = { i, "������ȭ", NORMAL, 40, 100, 30 };
	skill[i++] = { i, "�г�", NORMAL, 20, 100, 20 };
	skill[i++] = { i, "�����̵�", ESPER, 0, 0, 20 };
	skill[i++] = { i, "����Ʈ���", GHOST, 0, 100, 15 };
	skill[i++] = { i, "�䳻����", NORMAL, 0, 100, 10 };
	skill[i++] = { i, "�����Ҹ�", NORMAL, 0, 85, 40 };
	skill[i++] = { i, "�׸��ںн�", NORMAL, 0, 0, 15 };
	skill[i++] = { i, "HPȸ��", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "�ܴ�������", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "�۾�����", NORMAL, 0, 0, 20 };
	skill[i++] = { i, "����", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "�̻��Ѻ�", GHOST, 0, 100, 10 };
	skill[i++] = { i, "����������", WATER, 0, 0, 40 };
	skill[i++] = { i, "��ũ����", NORMAL, 0, 0, 40 };
	skill[i++] = { i, "�踮��", ESPER, 0, 0, 30 };
	skill[i++] = { i, "�����帷", ESPER, 0, 0, 30 };
	skill[i++] = { i, "��Ȱ�", ICE, 0, 0, 30 };
	skill[i++] = { i, "���÷���", ESPER, 0, 0, 20 };
	skill[i++] = { i, "������", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "����", NORMAL, 0, 100, 10 };
	skill[i++] = { i, "�հ�������", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "�����ϱ�", FLY, 0, 0, 20 };
	skill[i++] = { i, "����", NORMAL, 200, 100, 5 };
	skill[i++] = { i, "����ź", NORMAL, 100, 75, 10 };
	skill[i++] = { i, "�ӱ�", GHOST, 20, 100, 30 };
	skill[i++] = { i, "�����", POISON, 20, 70, 20 };
	skill[i++] = { i, "��������", POISON, 65, 100, 20 };
	skill[i++] = { i, "���ٱ�ġ��", GROUND, 65, 85, 20 };
	skill[i++] = { i, "�Ҵ빮��", FIRE, 110, 85, 5 };
	skill[i++] = { i, "����������", WATER, 80, 100, 15 };
	skill[i++] = { i, "���������", WATER, 35, 85, 10 };
	skill[i++] = { i, "���ǵ彺Ÿ", NORMAL, 60, 0, 20 };
	skill[i++] = { i, "����Ʈ��ġ��", NORMAL, 100, 100, 15 };
	skill[i++] = { i, "���ô���", NORMAL, 20, 100, 15 };
	skill[i++] = { i, "�ְ���", NORMAL, 10, 100, 35 };
	skill[i++] = { i, "������", ESPER, 0, 0, 20 };
	skill[i++] = { i, "�������ֱ�", ESPER, 0, 80, 15 };
	skill[i++] = { i, "�˳���", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "��������", FIGHT, 130, 90, 10 };
	skill[i++] = { i, "�촫�ʸ�", NORMAL, 0, 90, 30 };
	skill[i++] = { i, "�޸Ա�", ESPER, 100, 100, 15 };
	skill[i++] = { i, "������", POISON, 0, 80, 40 };
	skill[i++] = { i, "����������", NORMAL, 15, 85, 40 };
	skill[i++] = { i, "����", BUG, 20, 100, 15 };
	skill[i++] = { i, "�Ǹ���Ű��", NORMAL, 0, 75, 10 };
	skill[i++] = { i, "�һ�", FLY, 140, 90, 5 };
	skill[i++] = { i, "����", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "��ǰ", WATER, 20, 100, 30 };
	skill[i++] = { i, "������ġ", NORMAL, 70, 100, 10 };
	skill[i++] = { i, "��������", GRASS, 0, 100, 15 };
	skill[i++] = { i, "�÷���", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "�����ڿ��̺�", ESPER, 0, 80, 15 };
	skill[i++] = { i, "Ƣ�������", NORMAL, 0, 0, 40 };
	skill[i++] = { i, "���", POISON, 0, 0, 40 };
	skill[i++] = { i, "����ܸ�", WATER, 90, 90, 10 };
	skill[i++] = { i, "������", NORMAL, 250, 100, 5 };
	skill[i++] = { i, "����������", NORMAL, 18, 80, 15 };
	skill[i++] = { i, "���ٱͺθ޶�", GROUND, 50, 90, 10 };
	skill[i++] = { i, "���ڱ�", ESPER, 0, 0, 10 };
	skill[i++] = { i, "�������", ROCK, 75, 90, 10 };
	skill[i++] = { i, "�ʻ�մ�", NORMAL, 80, 90, 15 };
	skill[i++] = { i, "������", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "�ؽ�ó", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "Ʈ���̾���", NORMAL, 80, 100, 10 };
	skill[i++] = { i, "�г��Ǿմ�", NORMAL, 0, 90, 10 };
	skill[i++] = { i, "�������", NORMAL, 70, 100, 20 };
	skill[i++] = { i, "��Ÿ�⵿", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "�߹���", NORMAL, 50, 100, 1 };

	std::ofstream fout("DB/Skill.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < SKILL_TOTAL_NUMBER; i++)
		{
			fout << skill[i].m_number << " "
				<< skill[i].m_name << " "
				<< skill[i].m_type << " "
				<< skill[i].m_damage << " "
				<< skill[i].m_accuracy << " "
				<< skill[i].m_PP << std::endl;
		}
		fout.close();
	}

	delete[] skill;
}

void SkillManager::LoadSkill()
{
	std::ifstream fout;

	fout.open("DB/Skill.db");

	if (fout.fail() == false)
	{	
		for (int i = 0; i < SKILL_TOTAL_NUMBER; i++)
		{
			Skill temp;
			fout >> temp.m_number
				>> temp.m_name
				>> temp.m_type
				>> temp.m_damage
				>> temp.m_accuracy
				>> temp.m_PP;
			m_skillList.push_back(temp);
		}
		fout.close();
	}
}

void SkillManager::Init()
{
	SaveSkill();
	LoadSkill();
}

/*
��ų ��ȣ�� �޾Ƽ� �ش� ��ų�� ������ �Ѱ��ش�.
*/
Skill SkillManager::GetSkill(int _skillNumber)
{
	if (_skillNumber < 0)
	{
		return Skill();
	}
	return m_skillList[_skillNumber];
}

Skill SkillManager::GetSkillByType(int _type1, int _type2)
{
	int randIndex = rand() % SKILL_TOTAL_NUMBER;

	while (true)
	{
		if (m_skillList[randIndex].m_type == _type1 ||
			m_skillList[randIndex].m_type == _type2)
		{
			break;
		}
		else if (m_skillList[randIndex].m_type == Type::NORMAL)
		{
			if (rand() % 100 < 5)
			{
				break;
			}
		}
		randIndex = rand() % SKILL_TOTAL_NUMBER;
	}

	return m_skillList[randIndex];
}

float SkillManager::GetDamageRate(int _typeA, int _typeB)
{
	float damageRate = 1.0f;

	switch (_typeA)
	{
	case Type::NORMAL:
	{
		if (_typeB == ROCK)
			damageRate *= 0.5f;		
		if (_typeB == STEEL)
			damageRate *= 0.5f;
		if (_typeB == GHOST)
			damageRate *= 0.0f;
	}break;

	case Type::FIRE:
	{
		if (_typeB == FIRE)
			damageRate *= 0.5f;
		if (_typeB == WATER)
			damageRate *= 0.5f;
		if (_typeB == GRASS)
			damageRate *= 2.0f;
		if (_typeB == ICE)
			damageRate *= 2.0f;
		if (_typeB == BUG)
			damageRate *= 2.0f;
		if (_typeB == ROCK)
			damageRate *= 0.5f;
		if (_typeB == DRAGON)
			damageRate *= 0.5f;
		if (_typeB == STEEL)
			damageRate *= 2.0f;
	}break;

	case Type::WATER:
	{
		if (_typeB == FIRE)
			damageRate *= 2.0f;
		if (_typeB == WATER)
			damageRate *= 0.5f;
		if (_typeB == GRASS)
			damageRate *= 0.5f;
		if (_typeB == GROUND)
			damageRate *= 2.0f;
		if (_typeB == ROCK)
			damageRate *= 2.0f;
		if (_typeB == DRAGON)
			damageRate *= 0.5f;
	}break;

	case Type::GRASS:
	{
		if (_typeB == FIRE)
			damageRate *= 0.5f;
		if (_typeB == WATER)
			damageRate *= 2.0f;
		if (_typeB == GRASS)
			damageRate *= 0.5f;
		if (_typeB == POISON)
			damageRate *= 0.5f;
		if (_typeB == GROUND)
			damageRate *= 2.0f;
		if (_typeB == FLY)
			damageRate *= 0.5f;
		if (_typeB == BUG)
			damageRate *= 0.5f;
		if (_typeB == ROCK)
			damageRate *= 2.0f;
		if (_typeB == DRAGON)
			damageRate *= 0.5f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
	}break;

	case Type::THUNDER:
	{
		if (_typeB == WATER)
			damageRate *= 2.0f;
		if (_typeB == GRASS)
			damageRate *= 0.5f;
		if (_typeB == THUNDER)
			damageRate *= 0.5f;
		if (_typeB == GROUND)
			damageRate *= 0.0f;
		if (_typeB == FLY)
			damageRate *= 2.0f;
		if (_typeB == DRAGON)
			damageRate *= 0.5f;
	}break;

	case Type::ICE:
	{
		if (_typeB == FIRE)
			damageRate *= 0.5f;
		if (_typeB == WATER)
			damageRate *= 0.5f;
		if (_typeB == GRASS)
			damageRate *= 2.0f;
		if (_typeB == ICE)
			damageRate *= 0.5f;
		if (_typeB == GROUND)
			damageRate *= 2.0f;
		if (_typeB == FLY)
			damageRate *= 2.0f;
		if (_typeB == DRAGON)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
	}break;

	case Type::FIGHT:
	{
		if (_typeB == NORMAL)
			damageRate *= 2.0f;
		if (_typeB == ICE)
			damageRate *= 2.0f;
		if (_typeB == POISON)
			damageRate *= 0.5f;
		if (_typeB == FLY)
			damageRate *= 0.5f;
		if (_typeB == ESPER)
			damageRate *= 0.5f;
		if (_typeB == BUG)
			damageRate *= 0.5f;
		if (_typeB == ROCK)
			damageRate *= 2.0f;
		if (_typeB == GHOST)
			damageRate *= 0.0f;
		if (_typeB == EVIL)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 2.0f;
		if (_typeB == FAIRY)
			damageRate *= 0.5f;
	}break;

	case Type::POISON:
	{
		if (_typeB == GRASS)
			damageRate *= 2.0f;
		if (_typeB == POISON)
			damageRate *= 0.5f;
		if (_typeB == GROUND)
			damageRate *= 0.5f;
		if (_typeB == ROCK)
			damageRate *= 0.5f;
		if (_typeB == GHOST)
			damageRate *= 0.5f;
		if (_typeB == STEEL)
			damageRate *= 0.0f;
		if (_typeB == FAIRY)
			damageRate *= 2.0f;
	}break;

	case Type::GROUND:
	{
		if (_typeB == FIRE)
			damageRate *= 2.0f;
		if (_typeB == GRASS)
			damageRate *= 0.5f;
		if (_typeB == THUNDER)
			damageRate *= 2.0f;
		if (_typeB == POISON)
			damageRate *= 2.0f;
		if (_typeB == FLY)
			damageRate *= 0.0f;
		if (_typeB == BUG)
			damageRate *= 0.5f;
		if (_typeB == ROCK)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 2.0f;
	}break;

	case Type::FLY:
	{
		if (_typeB == GRASS)
			damageRate *= 2.0f;
		if (_typeB == THUNDER)
			damageRate *= 0.5f;
		if (_typeB == FIGHT)
			damageRate *= 2.0f;
		if (_typeB == BUG)
			damageRate *= 2.0;
		if (_typeB == ROCK)
			damageRate *= 0.5f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
	}break;

	case Type::ESPER:
	{
		if (_typeB == FIGHT)
			damageRate *= 2.0;
		if (_typeB == POISON)
			damageRate *= 2.0f;
		if (_typeB == ESPER)
			damageRate *= 0.5f;
		if (_typeB == EVIL)
			damageRate *= 0.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
	}break;

	case Type::BUG:
	{
		if (_typeB == FIRE)
			damageRate *= 0.5f;
		if (_typeB == GRASS)
			damageRate *= 2.0;
		if (_typeB == FIGHT)
			damageRate *= 0.5f;
		if (_typeB == POISON)
			damageRate *= 0.5f;
		if (_typeB == FLY)
			damageRate *= 0.5f;
		if (_typeB == ESPER)
			damageRate *= 2.0f;
		if (_typeB == GHOST)
			damageRate *= 0.5f;
		if (_typeB == EVIL)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
		if (_typeB == FAIRY)
			damageRate *= 0.5f;
	}break;

	case Type::ROCK:
	{
		if (_typeB == FIRE)
			damageRate *= 2.0f;
		if (_typeB == ICE)
			damageRate *= 2.0f;
		if (_typeB == FIGHT)
			damageRate *= 0.5f;
		if (_typeB == GROUND)
			damageRate *= 0.5f;
		if (_typeB == FLY)
			damageRate *= 2.0f;
		if (_typeB == BUG)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
	}break;

	case Type::GHOST:
	{
		if (_typeB == NORMAL)
			damageRate *= 0.0f;
		if (_typeB == ESPER)
			damageRate *= 2.0f;
		if (_typeB == GHOST)
			damageRate *= 2.0f;
		if (_typeB == EVIL)
			damageRate *= 0.5f;
	}break;

	case Type::DRAGON:
	{
		if (_typeB == DRAGON)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
		if (_typeB == FAIRY)
			damageRate *= 0.0f;
	}break;

	case Type::EVIL:
	{
		if (_typeB == FIGHT)
			damageRate *= 0.5f;
		if (_typeB == ESPER)
			damageRate *= 2.0f;
		if (_typeB == GHOST)
			damageRate *= 0.5f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
		if (_typeB == FAIRY)
			damageRate *= 2.0f;
	}break;

	case Type::STEEL:
	{
		if (_typeB == FIRE)
			damageRate *= 0.5f;
		if (_typeB == WATER)
			damageRate *= 0.5f;
		if (_typeB == THUNDER)
			damageRate *= 0.5f;
		if (_typeB == ICE)
			damageRate *= 0.0f;
		if (_typeB == ROCK)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
		if (_typeB == FAIRY)
			damageRate *= 2.0f;
	}break;

	case Type::FAIRY:
	{
		if (_typeB == FIRE)
			damageRate *= 0.5f;
		if (_typeB == FIGHT)
			damageRate *= 2.0f;
		if (_typeB == POISON)
			damageRate *= 0.5f;
		if (_typeB == DRAGON)
			damageRate *= 2.0f;
		if (_typeB == EVIL)
			damageRate *= 2.0f;
		if (_typeB == STEEL)
			damageRate *= 0.5f;
	}break;
	}

	return damageRate;
}
