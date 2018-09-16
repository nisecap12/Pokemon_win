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
	번호		- 스킬 고유번호
	스킬명	- 스킬 이름
	속성		- 스킬 속성
	위력		- 스킬 위력(데미지)
	명중률	- 스킬 명중률 n%
	PP		- 스킬 시전가능 횟수
	*/

	unsigned short i = 0;
	skill[i++] = { i, "막치기", NORMAL, 40, 100, 35 };
	skill[i++] = { i, "태권당수", FIGHT, 50, 100, 25 };
	skill[i++] = { i, "연속뺨치기", NORMAL, 15, 85, 10 };
	skill[i++] = { i, "연속펀치", NORMAL, 18, 85, 15 };
	skill[i++] = { i, "메가톤펀치", NORMAL, 80, 85, 20 };
	skill[i++] = { i, "고양이돈받기", NORMAL, 40, 100, 20 };
	skill[i++] = { i, "불꽃펀치", FIRE, 75, 100, 15 };
	skill[i++] = { i, "냉동펀치", ICE, 75, 100, 15 };
	skill[i++] = { i, "번개펀치", THUNDER, 75, 100, 15 };
	skill[i++] = { i, "할퀴기", NORMAL, 40, 100, 35 };
	skill[i++] = { i, "찝기", NORMAL, 55, 100, 30 };
	skill[i++] = { i, "가위자르기", NORMAL, 0, 0, 5 };
	skill[i++] = { i, "칼바람", NORMAL, 80, 100, 10 };
	skill[i++] = { i, "칼춤", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "풀베기", NORMAL, 50, 95, 30 };
	skill[i++] = { i, "바람일으키기", FLY, 40, 100, 35 };
	skill[i++] = { i, "날개치기", FLY, 60, 100, 35 };
	skill[i++] = { i, "날려버리기", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "공중날기", FLY, 90, 95, 15 };
	skill[i++] = { i, "조이기", NORMAL, 15, 85, 20 };
	skill[i++] = { i, "힘껏치기", NORMAL, 80, 75, 20 };
	skill[i++] = { i, "덩굴채찍", GRASS, 45, 100, 25 };
	skill[i++] = { i, "짓밟기", NORMAL, 65, 100, 20 };
	skill[i++] = { i, "두번치기", FIGHT, 30, 100, 30 };
	skill[i++] = { i, "메가톤킥", NORMAL, 120, 75, 5 };
	skill[i++] = { i, "점프킥", FIGHT, 100, 95, 10 };
	skill[i++] = { i, "돌려차기", FIGHT, 60, 85, 15 };
	skill[i++] = { i, "모래뿌리기", GROUND, 0, 100, 15 };
	skill[i++] = { i, "박치기", NORMAL, 70, 100, 15 };
	skill[i++] = { i, "뿔찌르기", NORMAL, 65, 100, 25 };
	skill[i++] = { i, "마구찌르기", NORMAL, 15, 85, 20 };
	skill[i++] = { i, "뿔드릴", NORMAL, 0, 0, 5 };
	skill[i++] = { i, "몸통박치기", NORMAL, 50, 100, 35 };
	skill[i++] = { i, "누르기", NORMAL, 85, 100, 15 };
	skill[i++] = { i, "김밥말이", NORMAL, 15, 90, 20 };
	skill[i++] = { i, "돌진", NORMAL, 90, 85, 20 };
	skill[i++] = { i, "난동부리기", NORMAL, 120, 100, 10 };
	skill[i++] = { i, "이판사판태클", NORMAL, 120, 100, 15 };
	skill[i++] = { i, "꼬리흔들기", NORMAL, 0, 100, 30 };
	skill[i++] = { i, "독침", POISON, 15, 100, 35 };
	skill[i++] = { i, "더블니들", BUG, 25, 100, 20 };
	skill[i++] = { i, "바늘미사일", BUG, 14, 85, 20 };
	skill[i++] = { i, "째려보기", NORMAL, 0, 100, 30 };
	skill[i++] = { i, "물기", EVIL, 60, 100, 25 };
	skill[i++] = { i, "울음소리", NORMAL, 0, 100, 40 };
	skill[i++] = { i, "울부짖기", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "노래하기", NORMAL, 0, 55, 15 };
	skill[i++] = { i, "초음파", NORMAL, 0, 55, 20 };
	skill[i++] = { i, "소닉붐", NORMAL, 0, 90, 20 };
	skill[i++] = { i, "사슬묶기", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "용해액", POISON, 40, 100, 30 };
	skill[i++] = { i, "불꽃세례", FIRE, 40, 100, 25 };
	skill[i++] = { i, "화염방사", FIRE, 90, 100, 15 };
	skill[i++] = { i, "흰안개", ICE, 0, 0, 30 };
	skill[i++] = { i, "물대포", WATER, 40, 100, 25 };
	skill[i++] = { i, "하이드로펌프", WATER, 110, 80, 5 };
	skill[i++] = { i, "파도타기", WATER, 90, 100, 15 };
	skill[i++] = { i, "냉동빔", ICE, 90, 100, 10 };
	skill[i++] = { i, "눈보라", ICE, 110, 70, 5 };
	skill[i++] = { i, "환상빔", ESPER, 65, 100, 20 };
	skill[i++] = { i, "거품광선", WATER, 65, 100, 20 };
	skill[i++] = { i, "오로라빔", ICE, 65, 100, 20 };
	skill[i++] = { i, "파괴광선", NORMAL, 150, 90, 5 };
	skill[i++] = { i, "쪼기", FLY, 35, 100, 35 };
	skill[i++] = { i, "회전부리", FLY, 80, 100, 20 };
	skill[i++] = { i, "지옥의바퀴", FIGHT, 80, 80, 25 };
	skill[i++] = { i, "안다리걸기", FIGHT, 0, 100, 20 };
	skill[i++] = { i, "카운터", FIGHT, 0, 100, 20 };
	skill[i++] = { i, "지구던지기", FIGHT, 0, 100, 20 };
	skill[i++] = { i, "괴력", NORMAL, 80, 100, 15 };
	skill[i++] = { i, "흡수", GRASS, 20, 100, 25 };
	skill[i++] = { i, "메가드레인", GRASS, 40, 100, 15 };
	skill[i++] = { i, "씨뿌리기", GRASS, 0, 90, 10 };
	skill[i++] = { i, "성장", NORMAL, 0, 0, 40 };
	skill[i++] = { i, "잎날가르기", GRASS, 55, 95, 25 };
	skill[i++] = { i, "솔라빔", GRASS, 120, 100, 10 };
	skill[i++] = { i, "독가루", POISON, 0, 75, 35 };
	skill[i++] = { i, "저리가루", GRASS, 0, 75, 30 };
	skill[i++] = { i, "수면가루", GRASS, 0, 75, 15 };
	skill[i++] = { i, "꽃잎댄스", GRASS, 120, 100, 10 };
	skill[i++] = { i, "실뿜기", BUG, 0, 95, 40 };
	skill[i++] = { i, "용의분노", DRAGON, 0, 100, 10 };
	skill[i++] = { i, "회오리불꽃", FIRE, 35, 85, 15 };
	skill[i++] = { i, "전기쇼크", THUNDER, 40, 100, 30 };
	skill[i++] = { i, "10만볼트", THUNDER, 90, 100, 15 };
	skill[i++] = { i, "전기자석파", THUNDER, 0, 100, 20 };
	skill[i++] = { i, "번개", THUNDER, 100, 70, 10 };
	skill[i++] = { i, "돌떨구기", ROCK, 50, 90, 15 };
	skill[i++] = { i, "지진", GROUND, 100, 100, 10 };
	skill[i++] = { i, "땅가르기", GROUND, 0, 0, 5 };
	skill[i++] = { i, "구멍파기", GROUND, 80, 100, 10 };
	skill[i++] = { i, "맹독", POISON, 0, 90, 10 };
	skill[i++] = { i, "염동력", ESPER, 50, 100, 25 };
	skill[i++] = { i, "사이코키네시스", ESPER, 90, 100, 10 };
	skill[i++] = { i, "최면술", ESPER, 0, 60, 20 };
	skill[i++] = { i, "요가포즈", ESPER, 0, 0, 40 };
	skill[i++] = { i, "고속이동", ESPER, 0, 0, 30 };
	skill[i++] = { i, "전광석화", NORMAL, 40, 100, 30 };
	skill[i++] = { i, "분노", NORMAL, 20, 100, 20 };
	skill[i++] = { i, "순간이동", ESPER, 0, 0, 20 };
	skill[i++] = { i, "나이트헤드", GHOST, 0, 100, 15 };
	skill[i++] = { i, "흉내내기", NORMAL, 0, 100, 10 };
	skill[i++] = { i, "싫은소리", NORMAL, 0, 85, 40 };
	skill[i++] = { i, "그림자분신", NORMAL, 0, 0, 15 };
	skill[i++] = { i, "HP회복", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "단단해지기", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "작아지기", NORMAL, 0, 0, 20 };
	skill[i++] = { i, "연막", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "이상한빛", GHOST, 0, 100, 10 };
	skill[i++] = { i, "껍질에숨기", WATER, 0, 0, 40 };
	skill[i++] = { i, "웅크리기", NORMAL, 0, 0, 40 };
	skill[i++] = { i, "배리어", ESPER, 0, 0, 30 };
	skill[i++] = { i, "빛의장막", ESPER, 0, 0, 30 };
	skill[i++] = { i, "흑안개", ICE, 0, 0, 30 };
	skill[i++] = { i, "리플렉터", ESPER, 0, 0, 20 };
	skill[i++] = { i, "기충전", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "참기", NORMAL, 0, 100, 10 };
	skill[i++] = { i, "손가락흔들기", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "따라하기", FLY, 0, 0, 20 };
	skill[i++] = { i, "자폭", NORMAL, 200, 100, 5 };
	skill[i++] = { i, "알폭탄", NORMAL, 100, 75, 10 };
	skill[i++] = { i, "핥기", GHOST, 20, 100, 30 };
	skill[i++] = { i, "스모그", POISON, 20, 70, 20 };
	skill[i++] = { i, "오물공격", POISON, 65, 100, 20 };
	skill[i++] = { i, "뼈다귀치기", GROUND, 65, 85, 20 };
	skill[i++] = { i, "불대문자", FIRE, 110, 85, 5 };
	skill[i++] = { i, "폭포오르기", WATER, 80, 100, 15 };
	skill[i++] = { i, "껍질끼우기", WATER, 35, 85, 10 };
	skill[i++] = { i, "스피드스타", NORMAL, 60, 0, 20 };
	skill[i++] = { i, "로케트박치기", NORMAL, 100, 100, 15 };
	skill[i++] = { i, "가시대포", NORMAL, 20, 100, 15 };
	skill[i++] = { i, "휘감기", NORMAL, 10, 100, 35 };
	skill[i++] = { i, "망각술", ESPER, 0, 0, 20 };
	skill[i++] = { i, "숟가락휘기", ESPER, 0, 80, 15 };
	skill[i++] = { i, "알낳기", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "무릎차기", FIGHT, 130, 90, 10 };
	skill[i++] = { i, "뱀눈초리", NORMAL, 0, 90, 30 };
	skill[i++] = { i, "꿈먹기", ESPER, 100, 100, 15 };
	skill[i++] = { i, "독가스", POISON, 0, 80, 40 };
	skill[i++] = { i, "구슬던지기", NORMAL, 15, 85, 40 };
	skill[i++] = { i, "흡혈", BUG, 20, 100, 15 };
	skill[i++] = { i, "악마의키스", NORMAL, 0, 75, 10 };
	skill[i++] = { i, "불새", FLY, 140, 90, 5 };
	skill[i++] = { i, "변신", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "거품", WATER, 20, 100, 30 };
	skill[i++] = { i, "잼잼펀치", NORMAL, 70, 100, 10 };
	skill[i++] = { i, "버섯포자", GRASS, 0, 100, 15 };
	skill[i++] = { i, "플래시", NORMAL, 0, 100, 20 };
	skill[i++] = { i, "사이코웨이브", ESPER, 0, 80, 15 };
	skill[i++] = { i, "튀어오르기", NORMAL, 0, 0, 40 };
	skill[i++] = { i, "녹기", POISON, 0, 0, 40 };
	skill[i++] = { i, "찝게햄머", WATER, 90, 90, 10 };
	skill[i++] = { i, "대폭발", NORMAL, 250, 100, 5 };
	skill[i++] = { i, "마구할퀴기", NORMAL, 18, 80, 15 };
	skill[i++] = { i, "뼈다귀부메랑", GROUND, 50, 90, 10 };
	skill[i++] = { i, "잠자기", ESPER, 0, 0, 10 };
	skill[i++] = { i, "스톤샤워", ROCK, 75, 90, 10 };
	skill[i++] = { i, "필살앞니", NORMAL, 80, 90, 15 };
	skill[i++] = { i, "각지기", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "텍스처", NORMAL, 0, 0, 30 };
	skill[i++] = { i, "트라이어택", NORMAL, 80, 100, 10 };
	skill[i++] = { i, "분노의앞니", NORMAL, 0, 90, 10 };
	skill[i++] = { i, "베어가르기", NORMAL, 70, 100, 20 };
	skill[i++] = { i, "대타출동", NORMAL, 0, 0, 10 };
	skill[i++] = { i, "발버둥", NORMAL, 50, 100, 1 };

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
스킬 번호를 받아서 해당 스킬의 정보를 넘겨준다.
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
