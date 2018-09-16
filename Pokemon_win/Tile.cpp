#include "stdafx.h"
#include "Tile.h"
#include "ImgMgr.h"
#include "TileMgr.h"
#include <sstream>

CTile::CTile()
{
	
}

CTile::CTile(int _posX, int _posY)
{
	m_tInfo.pos.x = _posX;
	m_tInfo.pos.y = _posY;

	m_tInfo.size.cx = MAP_TILE_SIZE;
	m_tInfo.size.cy = MAP_TILE_SIZE;

	m_tInfo.rc.left = m_tInfo.pos.x - MAP_TILE_SIZE / 2;
	m_tInfo.rc.top = m_tInfo.pos.y - MAP_TILE_SIZE / 2;
	m_tInfo.rc.right = m_tInfo.pos.x + MAP_TILE_SIZE / 2;
	m_tInfo.rc.bottom = m_tInfo.pos.y + MAP_TILE_SIZE / 2;
	m_tInfo.click = false;
	m_tInfo.DrawIDX = 0;
	m_tInfo.DrawIDY = 0;
	m_tInfo.DrawOption = 0;
	m_tInfo.Drag = false;
	m_tInfo.ImageType = IMAGE_END;
	m_tInfo.LayerType = LAYER_END;
}

CTile::~CTile()
{
}

void CTile::Initialize()
{
}

int CTile::Update()
{
	return 0;
}

void CTile::Render(HDC _hdc)
{
	const char* Image = nullptr;
	switch (m_tInfo.ImageType)
	{
	case IMAGE_TILE:
		Image = "bg_tile01";
		
		break;
	case IMAGE_TREE01:
		Image = "bg_tree01";
		
		break;
	case IMAGE_BG01:
		Image = "bg02";
		
		break;
	case IMAGE_BG02:
		Image = "bg03";
		
		break;
	case IMAGE_BG03:
		Image = "bg06";
		
		break;
	case IMAGE_BG04:
		Image = "bg07";
		
		break;
	case IMAGE_BG05:
		Image = "bg08";
		
		break;
	case IMAGE_DOOR01:
		Image = "door01";
		
		break;
	case IMAGE_DOOR02:
		Image = "door02";
		
		break;
	case IMAGE_FENCE:
		Image = "fence01";
		
		break;
	case IMAGE_HOUSE01:
		Image = "house01";
		
		break;
	case IMAGE_HOUSE02:
		Image = "house02";
		
		break;
	case IMAGE_HOUSE03:
		Image = "house03";
		
		break;
	case IMAGE_HOUSE04:
		Image = "house04";
		
		break;
	case IMAGE_HOUSE05:
		Image = "house05";
		
		break;
	case IMAGE_HOUSE06:
		Image = "house06";
		
		break;
	case IMAGE_HOUSE07:
		Image = "house07";
		
		break;
	case IMAGE_HOUSE08:
		Image = "house08";
		
		break;
	case IMAGE_LAWNGRASS01:
		Image = "lawngrass01";
		
		break;
	case IMAGE_LAWNGRASS02:
		Image = "lawngrass02";
		
		break;
	case IMAGE_POST01:
		Image = "post01";
		
		break;
	case IMAGE_POST02:
		Image = "post02";
		
		break;
	case IMAGE_SIGN01:
		Image = "sign01";
		
		break;
	case IMAGE_SIGN02:
		Image = "sign02";
		
		break;
	case IMAGE_STONE01:
		Image = "stone01";
		
		break;
	case IMAGE_STONE02:
		Image = "stone01_01";
		
		break;
	case IMAGE_STONE03:
		Image = "stone02";
		
		break;
	case IMAGE_STONE04:
		Image = "stone02_01";
		
		break;
	case IMAGE_TREE02:
		Image = "tree03";
		
		break;
	case IMAGE_TREE03:
		Image = "tree04";
		
		break;
	case IMAGE_WAVE01:
		Image = "wave01";
		
		break;
	case IMAGE_WAVE02:
		Image = "wave02";
		
		break;
	case IMAGE_BLACK:
		Image = "black";
	case IMAGE_END:
		break;
	}

	
	if (m_tInfo.Drag && m_tInfo.click)
	{
		ImgClass* img = IMG_MGR->GetImg(Image);
		
		GdiTransparentBlt(_hdc,
			m_tInfo.rc.left - MAP_MANAGER.GetCamPosition().x,
			m_tInfo.rc.top - MAP_MANAGER.GetCamPosition().y,
			MAP_TILE_SIZE, MAP_TILE_SIZE, img->GetImgDC(), m_tInfo.DrawIDX * MAP_TILE_SIZE, m_tInfo.DrawIDY * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE, RGB(153, 51, 204));
		
		return;
	}

	if (m_tInfo.click)
	{
		ImgClass* img = IMG_MGR->GetImg(Image);

		/*if (m_tInfo.ImageType == IMAGE_LAWNGRASS01)
		{
			IMG_MGR->GetImg(Image)->AniRender(_hdc, m_tInfo.DrawIDX,
				m_tInfo.rc.left - MAP_MANAGER.GetCamPosition().x,
				m_tInfo.rc.top - MAP_MANAGER.GetCamPosition().y);
		}
		else
		{
			GdiTransparentBlt(_hdc,
				m_tInfo.rc.left - MAP_MANAGER.GetCamPosition().x,
				m_tInfo.rc.top - MAP_MANAGER.GetCamPosition().y,
				MAP_TILE_SIZE, MAP_TILE_SIZE, img->GetImgDC(), m_tInfo.DrawIDX * MAP_TILE_SIZE, m_tInfo.DrawIDY * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE, RGB(153, 51, 204));
		}*/
		GdiTransparentBlt(_hdc,
			m_tInfo.rc.left - MAP_MANAGER.GetCamPosition().x,
			m_tInfo.rc.top - MAP_MANAGER.GetCamPosition().y,
			MAP_TILE_SIZE, MAP_TILE_SIZE, img->GetImgDC(), m_tInfo.DrawIDX * MAP_TILE_SIZE, m_tInfo.DrawIDY * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE, RGB(153, 51, 204));
	}
}

void CTile::AniRender(HDC _hdc, int _frameX)
{
	IMG_MGR->GetImg("lawngrass01")->AniRender(_hdc, _frameX,
		m_tInfo.rc.left - MAP_MANAGER.GetCamPosition().x,
		m_tInfo.rc.top - MAP_MANAGER.GetCamPosition().y);
}

void CTile::Release()
{
}
