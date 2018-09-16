#include "stdafx.h"
#include "RenderManager.h"


RenderManager::RenderManager()
{
}


RenderManager::~RenderManager()
{
}

void RenderManager::InsertImg(int _yPos, int _type)
{
	m_renderList.insert(std::make_pair(_yPos, _type));
}

void RenderManager::Render(HDC _hdc)
{
	for (int i = 0; i < MAP_MANAGER.GetMapSize().cy; i++)
	{
		NPC_MANAGER.Render(_hdc, i);
		
		if (PLAYER_MANAGER.GetPosition().y == i)
		{
			PLAYER_MANAGER.Render(_hdc);
		}
		
		MAP_MANAGER.ObjRender(_hdc, i);
	}
}
