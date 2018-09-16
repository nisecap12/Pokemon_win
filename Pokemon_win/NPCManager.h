#pragma once
#include "ImgClass.h"
#include "NPC.h"

//NPC 타입 (NPC 출력 이미지 관련번호)
enum NPC_TYPE
{
	POLICE,
	DOCTOR,
	WOMAN,
	BOY,
	GIRL,
	NURSE,
	END,
};

//NPC 데이터 관리 구조체
struct NPCData
{
	int m_number;			//NPC 번호
	int m_mapNumber;		//map 번호
	int m_function;			//기능
	int m_direction;
	int m_pattern;			//NPC 패턴
	int m_searchDistance;	//탐색거리
	POINT m_Position;
	SIZE m_moveBox;
};

class NPCManager
{
private:
	std::vector<NPC*> m_npcList;
	std::map<int, ImgClass*> m_imgList;
	int m_listSize = 0;
	bool m_isAreaRender = false;
	bool m_stopMode = false;
	int m_activeNPC = -1;

private:
	NPCManager();
	~NPCManager();
	void LoadNPC();
	void SaveNPC();

public:
	static NPCManager& GetInstance()
	{
		static NPCManager Instance;
		return Instance;
	}

	void SwitchAreaRender()
	{
		m_isAreaRender = !m_isAreaRender;
	}

	void Init(HWND _hWnd);
	
	void Update(float _elapseTime);
	void Render(HDC _hdc, int _yPos);
	void AreaRender(HDC _hdc);
	bool CheckNPCPosition(POINT _pos);
	int CheckSelectNPC(POINT _pos);
	void SetActiveNPC(int _npcNumber);
	void RestartNPC();
	ImgClass* GetNPCImage(int _npcNumber);
	NPC GetNPC(int _x, int _y);
	NPC* GetNPC(int _npcNum);
	std::vector<NPC*> GetNPCList();
};

#define NPC_MANAGER NPCManager::GetInstance()