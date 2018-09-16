#include "stdafx.h"
#include "BoxUI.h"

BoxUI::BoxUI()
{
}


BoxUI::~BoxUI()
{
}

void BoxUI::Init(HWND _hWnd)
{
	IMG_MGR->OpenImg("Images/UI/Tile.bmp", m_CellSize.cx * 15, m_CellSize.cy * 3);
	IMG_MGR->OpenImg("Images/UI/Select.bmp");

	auto	select = IMG_MGR->GetImg("Select");
	if (select != nullptr)
	{
		select->SetTrans();
	}
	
	auto	img = IMG_MGR->GetImg("Tile");
	if (img != nullptr)
	{
		img->SetTrans();
		img->SetFrame(15, 3);
	}
}

void BoxUI::BoxImg(HDC _hdc, int _posX, int _posY, int _tileX, int _tileY)
{
	auto	img = IMG_MGR->GetImg("Tile");

	switch (SCENE_MGR.GetBoxType())
	{
	case 0:
		img->AniRenderXY(_hdc, (_tileX % 3), _tileY, _posX * m_CellSize.cx, _posY * m_CellSize.cy);
		break;
	case 1:
		img->AniRenderXY(_hdc, (_tileX % 3) + 3, _tileY, _posX * m_CellSize.cx, _posY * m_CellSize.cy);
		break;
	case 2:
		img->AniRenderXY(_hdc, (_tileX % 3) + 6, _tileY, _posX * m_CellSize.cx, _posY * m_CellSize.cy);
		break;
	case 3:
		img->AniRenderXY(_hdc, (_tileX % 3) + 9, _tileY, _posX * m_CellSize.cx, _posY * m_CellSize.cy);
		break;
	case 4:
		img->AniRenderXY(_hdc, (_tileX % 3) + 12, _tileY, _posX * m_CellSize.cx, _posY * m_CellSize.cy);
		break;
	}
}

void BoxUI::BoxCreate(HDC _hdc, int _startPosX, int _startPosY, int _endPosX, int _endPosY, int _MaxNum, bool _select)
{
	POINT	drawPos = { _startPosX, _startPosY };
	int		RangeX = _endPosX - _startPosX;
	int		RangeY = _endPosY - _startPosY;

	//	첫줄
	BoxImg(_hdc, drawPos.x, drawPos.y, 0, 0);
	drawPos.x++;

	for (int x = 1; x < RangeX; x++)
	{
		BoxImg(_hdc, drawPos.x, drawPos.y, 1, 0);
		drawPos.x++;
	}

	BoxImg(_hdc, drawPos.x, drawPos.y, 2, 0);
	drawPos.y++;
	drawPos.x = _startPosX;
	//	중간줄
	for (int y = 0; y < RangeY - 1; y++)
	{
		for (int x = 0; x < RangeX + 1; x++)
		{
			if (x == 0)
				BoxImg(_hdc, drawPos.x, drawPos.y, 0, 1);
			else if (x == RangeX)
				BoxImg(_hdc, drawPos.x, drawPos.y, 2, 1);
			else
				BoxImg(_hdc, drawPos.x, drawPos.y, 1, 1);
			drawPos.x++;
		}
		drawPos.y++;
		drawPos.x = _startPosX;
	}
	//	끝줄
	BoxImg(_hdc, drawPos.x, drawPos.y, 0, 2);
	drawPos.x++;

	for (int x = 1; x < RangeX; x++)
	{
		BoxImg(_hdc, drawPos.x, drawPos.y, 1, 2);
		drawPos.x++;
	}

	BoxImg(_hdc, drawPos.x, drawPos.y, 2, 2);
	drawPos.y++;
	drawPos.x = _startPosX;


	//	화살표 : 기본값 false
	if (_select == false)	return;

	auto select = IMG_MGR->GetImg("Select");
	select->AniRender(_hdc, 0, (_startPosX + 1) * m_CellSize.cx, (_startPosY + 1 + m_Select * 2) * m_CellSize.cy);


	if (m_isClick == false)
	{
		if (KEY_MANAGER.OnceKeyDown(VK_DOWN))
		{
			m_Select++;
			if (m_Select > _MaxNum - 1)
				m_Select = 0;
		}
		if (KEY_MANAGER.OnceKeyDown(VK_UP))
		{
			m_Select--;
			if (m_Select < 0)
				m_Select = _MaxNum - 1;
		}
	}
}