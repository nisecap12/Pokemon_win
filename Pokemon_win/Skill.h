#pragma once

class Skill
{
public:
	unsigned short m_number;		//기술 번호
	char  m_name[30];	//기술 이름
	short m_type;		//타입
	short m_damage;		//위력
	short m_accuracy;	//명중률
	short m_PP;			//PP 스킬 시전횟수
};