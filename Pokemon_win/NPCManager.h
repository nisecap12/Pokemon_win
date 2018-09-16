#pragma once
#include "ImgClass.h"
#include "NPC.h"

//NPC Ÿ�� (NPC ��� �̹��� ���ù�ȣ)
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

//NPC ������ ���� ����ü
struct NPCData
{
	int m_number;			//NPC ��ȣ
	int m_mapNumber;		//map ��ȣ
	int m_function;			//���
	int m_direction;
	int m_pattern;			//NPC ����
	int m_searchDistance;	//Ž���Ÿ�
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