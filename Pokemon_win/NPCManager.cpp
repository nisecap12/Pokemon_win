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

	NPC 추가하는 코드
	{ NPC 번호, map 번호, 기능, 초기방향, NPC 패턴, 탐색거리, 위치{x,y}, 이동영역{w,h} } 순으로 설정해주면 됨

	NPC 이미지 번호	- NPC 이미지 번호
	map 번호			- 아직 만든 맵이 없으므로 0
	기능				- 없음 0, 포켓몬센터 1, 상점 2, 트레이너 3, 관장 4
	방향				- 위 0, 아래 1, 왼쪽 2, 오른쪽 3
	NPC 패턴			- 가만히 0, 시계방향 돌기 1, 반시계 2, 제자리 빙글 3, 랜덤 4
	탐색거리			- n 칸 앞에 플레이어가 있으면 쫒아감, 0~6칸으로 설정
	NPC 지정위치		- NPC가 위치한 타일의 좌표. {x, y} 위치의 타일
	지정 영역		- NPC가 움직일 영역의 크기 {가로, 세로}

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

	//NPC.db 파일 열기
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
	//NPC 종류만큼 리스트에 이미지 추가
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
