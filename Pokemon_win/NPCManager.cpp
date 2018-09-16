#include "stdafx.h"
#include "NPCManager.h"

#define NPC_WIDTH 768
#define NPC_HEIGHT 80

NPCManager::NPCManager()
{
}


NPCManager::~NPCManager()
{
	for (auto &i : m_imgList)
	{
		delete i.second;
	}
	m_imgList.clear();
}

void NPCManager::SaveNPC()
{
	NPCData* temp = new NPCData[NPC_TOTAL_NUMBER];

	/*

	NPC �߰��ϴ� �ڵ�
	{ NPC ��ȣ, map ��ȣ, ���, �ʱ����, NPC ����, Ž���Ÿ�, ��ġ{x,y}, �̵�����{w,h} } ������ �������ָ� ��

	NPC �̹��� ��ȣ	- NPC �̹��� ��ȣ
	map ��ȣ			- ���� ���� ���� �����Ƿ� 0
	���				- ���� 0, ���ϸ��� 1, ���� 2, Ʈ���̳� 3, ���� 4
	����				- �� 0, �Ʒ� 1, ���� 2, ������ 3
	NPC ����			- ������ 0, �ð���� ���� 1, �ݽð� 2, ���ڸ� ���� 3, ���� 4
	Ž���Ÿ�			- n ĭ �տ� �÷��̾ ������ �i�ư�, 0~6ĭ���� ����
	NPC ������ġ		- NPC�� ��ġ�� Ÿ���� ��ǥ. {x, y} ��ġ�� Ÿ��
	���� ����		- NPC�� ������ ������ ũ�� {����, ����}

	*/
	temp[0] = { 0,0,0,0,1,0,{ 22, 12 },{ 4,2 } };
	temp[1] = { 1,1,3,1,0,3,{ 7, 3 },{ 1,1 } };
	temp[2] = { 2,0,0,2,4,0,{ 28, 12 },{ 2,2 } };
	temp[3] = { 3,0,0,2,0,0,{ 29, 16 },{ 1,1 } };
	temp[4] = { 4,0,0,1,3,4,{ 29, 15 },{ 1,1 } };
	temp[5] = { 0,0,0,0,2,0,{ 22, 16 },{ 4,2 } };
	temp[6] = { 0,0,0,0,1,0,{ 28, 45 },{ 3,3 } };
	temp[7] = { 0,0,0,0,2,0,{ 47, 36 },{ 3,3 } };

	std::ofstream fout("DB/NPC.db");

	if (fout.fail() == false)
	{
		fout.write((const char *)temp, sizeof(NPCData) * NPC_TOTAL_NUMBER);
		fout.close();
	}

	delete[] temp;
}

void NPCManager::LoadNPC()
{
	NPCData *data = new NPCData[NPC_TOTAL_NUMBER];
	std::ifstream fout;

	//NPC.db ���� ����
	fout.open("DB/NPC.db");

	if (fout.fail() == false)
	{
		fout.read((char*)data, sizeof(NPCData) * NPC_TOTAL_NUMBER);
		fout.close();

		for (int i = 0; i < NPC_TOTAL_NUMBER; i++)
		{
			NPC* npc = new NPC(data[i].m_number,
				data[i].m_mapNumber,
				data[i].m_function,
				data[i].m_direction,
				data[i].m_pattern,
				data[i].m_searchDistance,
				data[i].m_Position,
				data[i].m_moveBox);
			m_npcList.push_back(npc);
		}
	}

	delete[] data;
}

void NPCManager::Init(HWND _hWnd)
{
	//NPC ������ŭ ����Ʈ�� �̹��� �߰�
	for (int i = 0; i <= NPC_TYPE::END; i++)
	{
		ImgClass* newImage = new ImgClass;
		switch (i)
		{
		case NPC_TYPE::POLICE:
			newImage->LoadImg(_hWnd, "Images/police.bmp");
			newImage->SetFrame(12);
			break;
		
		case NPC_TYPE::DOCTOR:
			newImage->LoadImg(_hWnd, "Images/doctor.bmp");
			newImage->SetFrame(12);
			break;
		case NPC_TYPE::WOMAN:
			newImage->LoadImg(_hWnd, "Images/woman.bmp");
			newImage->SetFrame(12);
			break;
		case NPC_TYPE::BOY:
			newImage->LoadImg(_hWnd, "Images/boy.bmp");
			newImage->SetFrame(12);
			break;
		case NPC_TYPE::GIRL:
			newImage->LoadImg(_hWnd, "Images/girl.bmp");
			newImage->SetFrame(12);
			break;
		case NPC_TYPE::NURSE:
			newImage->LoadImg(_hWnd, "Images/nurse.bmp");
			break;
		case NPC_TYPE::END:
			newImage->LoadImg(_hWnd, "Images/encount.bmp");
			break;
		}

		newImage->SetTrans(true, TRANS_COLOR);
		m_imgList.insert(std::make_pair(i, newImage));
	}

	//NPC Save
	SaveNPC();

	//NPC Load
	LoadNPC();
}

void NPCManager::Update(float _elapseTime)
{
	if (m_stopMode)
	{
		for (auto &i : m_npcList)
		{
			if (i->GetNumber() == m_activeNPC)
			{
				i->DoAction(_elapseTime);
			}
		}
	}
	else
	{
		for (auto &i : m_npcList)
		{
			i->DoAction(_elapseTime);
		}
	}
}

void NPCManager::Render(HDC _hdc, int _yPos)
{
	for (auto i : m_npcList)
	{
		if (i->GetMapNumber() == MAP_MANAGER.GetMapNumber())
		{
			if (i->GetPosition().y == _yPos)
			{
				auto find = m_imgList.find(i->GetNumber());

				POINT t = i->GetPosition();
				HDC imgDC = find->second->GetImgDC();
				SIZE imgSize = find->second->GetSize();
				POINT position = i->GetRealPosition();
				position.x -= MAP_MANAGER.GetCamPosition().x;
				position.y -= MAP_MANAGER.GetCamPosition().y;

				int xPoint;
				if (i->IsMoving())
				{
					xPoint = i->GetDirection() + (4 * i->GetStep());
				}
				else
				{
					xPoint = i->GetDirection();
				}
				if (i->GetState() == NPC_STATE::ENCOUNTER)
				{
					m_imgList[NPC_TYPE::END]->Render(_hdc, position.x, position.y - imgSize.cy);
				}
				find->second->AniRender(_hdc, xPoint, position.x, position.y + MAP_TILE_SIZE - imgSize.cy);
			}
		}
	}
}

void NPCManager::AreaRender(HDC _hdc)
{
	if (m_isAreaRender)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = SelectBrush(_hdc, brush);
		HPEN pen = CreatePen(BS_SOLID, 1, RGB(255,255,255));
		HPEN oldPen = SelectPen(_hdc, pen);

		for (auto &i : m_npcList)
		{
			SIZE area = i->GetMoveBox();
			POINT position = i->GetRootPosition();
			position.x -= MAP_MANAGER.GetCamPosition().x;
			position.y -= MAP_MANAGER.GetCamPosition().y;

			Rectangle(_hdc, position.x, position.y, position.x + area.cx * MAP_TILE_SIZE, position.y + area.cy * MAP_TILE_SIZE);

		}
		DeleteBrush(SelectBrush(_hdc, oldBrush));
		DeletePen(SelectPen(_hdc, oldPen));
	}
}

bool NPCManager::CheckNPCPosition(POINT _pos)
{
	for (auto &npc : m_npcList)
	{
		POINT temp = npc->GetPosition();
		if (temp.x == _pos.x && temp.y == _pos.y)
		{
			return true;
		}
	}
	return false;
}

int NPCManager::CheckSelectNPC(POINT _pos)
{
	for (int i = 0; i < m_npcList.size(); i++)
	{
		POINT temp = m_npcList[i]->GetPosition();
		if (temp.x == _pos.x && temp.y == _pos.y)
		{
			return i;
		}
	}

	return -1;
}

void NPCManager::SetActiveNPC(int _npcNumber)
{
	m_activeNPC = _npcNumber;
	m_stopMode = true;
	PLAYER_MANAGER.SetControlActivate(false);
}

void NPCManager::RestartNPC()
{
	m_stopMode = false;
	PLAYER_MANAGER.SetControlActivate(true);
}

ImgClass * NPCManager::GetNPCImage(int _npcNumber)
{
	auto find = m_imgList.find(_npcNumber);
	
	return find->second;
}

NPC NPCManager::GetNPC(int _x, int _y)
{
	for (auto &i : m_npcList)
	{
		POINT pos = i->GetPosition();
		if (pos.x == _x && pos.y == _y)
		{
			return (NPC)*i;
		}
	}
}

NPC * NPCManager::GetNPC(int _npcNum)
{
	for (auto &i : m_npcList)
	{
		if (i->GetNumber() == _npcNum)
		{
			return i;
		}
	}
	return nullptr;
}

std::vector<NPC*> NPCManager::GetNPCList()
{
	return m_npcList;
}
