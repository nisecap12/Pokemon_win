#include "stdafx.h"
#include "NPCRenderManager.h"
#include "NPC.h"

NPCRenderManager::NPCRenderManager()
{
}


NPCRenderManager::~NPCRenderManager()
{
	m_npcList.clear();
}

void NPCRenderManager::Init(HWND _hWnd)
{
	//NPC 수만큼 리스트에 이미지 추가
	ImgClass* newImage = new ImgClass;
	newImage->LoadImg(_hWnd, "policesprite.bmp", 0, 0);
	newImage->SetTrans(true, RGB(255, 119, 251));
	m_npcList.insert(std::make_pair(0, newImage));
}

void NPCRenderManager::Render(HDC _hdc, NPC* _npc)
{
	auto find = m_npcList.find(_npc->GetNumber());

	HDC imgDC = find->second->GetImgDC();
	SIZE imgSize = find->second->GetSize();
	POINT position = _npc->GetPosition();
	
	GdiTransparentBlt(_hdc, 
		position.x * MAP_TILE_SIZE,
		((position.y + 1) * MAP_TILE_SIZE) - imgSize.cy,
		MAP_TILE_SIZE,
		imgSize.cy,
		imgDC,
		MAP_TILE_SIZE * _npc->GetDirection(),
		0,
		MAP_TILE_SIZE,
		imgSize.cy,
		TRANS_COLOR);
}
