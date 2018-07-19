#pragma once
#include "ImgClass.h"

class NPC;

class NPCRenderManager
{
private:
	std::map<int, ImgClass*> m_npcList;

private:
	NPCRenderManager();
	~NPCRenderManager();

public:
	static NPCRenderManager& GetInstance()
	{
		static NPCRenderManager Instance;
		return Instance;
	}

	void Init(HWND _hWnd);
	void Render(HDC _hdc, NPC* _npc);
};

#define NPC_RENDER_MANAGER NPCRenderManager::GetInstance()