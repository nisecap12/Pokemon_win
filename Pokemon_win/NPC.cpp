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
		//������
	}break;
	case NPC_FUNCTION::SHOP:
	{
		//����UI ȣ��
	}break;
	case NPC_FUNCTION::HEAL:
	{
		//���ϸ� ġ��
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
