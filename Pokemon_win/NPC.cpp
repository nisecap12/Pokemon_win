#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{
}

void NPC::DoAction()
{
	switch (m_function)
	{
	case NPC_FUNCTION::NONE:
	{
		//대사출력
	}break;
	case NPC_FUNCTION::SHOP:
	{
		//상점UI 호출
	}break;
	case NPC_FUNCTION::HEAL:
	{
		//포켓몬 치료
		if(m_state == NPC_STATE::INTERACT)
	}break;
	case NPC_FUNCTION::TRAINER:
	{
		//
	}break;
	case NPC_FUNCTION::CHAMP:
	{}break;
	}
}
