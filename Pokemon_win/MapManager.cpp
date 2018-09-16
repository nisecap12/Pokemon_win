#include "stdafx.h"
#include "MapManager.h"

MapManager::MapManager()
{
	m_bushAni.SetFrameTime({ 0.0f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f });
	m_bushAni.m_isLoop = false;
}

MapManager::~MapManager()
{
	for (auto &i : m_mapList)
	{
		delete i;
	}
	m_mapList.clear();
}

void MapManager::Save()
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "DB/save.txt", "wb");

	int count = m_TileVector[LAYER_TILE].size();

	if (0 == err)
	{
		fwrite(&count, sizeof(int), 1, fp);

		for (int i = 0; i < count; ++i)
		{
			fwrite(&m_TileVector[LAYER_TILE][i], sizeof(CTile), 1, fp);
		}
		for (int i = 0; i < count; ++i)
		{
			fwrite(&m_TileVector[LAYER_OBJ][i], sizeof(CTile), 1, fp);
		}

		fclose(fp);
	}

}

void MapManager::Load()
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "DB/save.txt", "rb");
	int count;
	CTile tile;

	if (0 == err)
	{
		fread(&count, sizeof(int), 1, fp);

		m_TileVector[LAYER_TILE].clear();
		for (int i = 0; i < count; ++i)
		{
			fread(&tile, sizeof(CTile), 1, fp);
			
			m_TileVector[LAYER_TILE].push_back(tile);
		}

		m_TileVector[LAYER_OBJ].clear();
		for (int i = 0; i < count; ++i)
		{
			fread(&tile, sizeof(CTile), 1, fp);
			m_TileVector[LAYER_OBJ].push_back(tile);
		}

		fclose(fp);
	}

	m_mapSize = { 70,100 };
}

void MapManager::Init(HWND _hWnd)
{
	IMG_MGR->SethWnd(_hWnd);
	IMG_MGR->OpenImg("Images/TileImage/bg_tile01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/bg_tree01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/bg02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/bg03.bmp");
	IMG_MGR->OpenImg("Images/TileImage/bg06.bmp");
	IMG_MGR->OpenImg("Images/TileImage/bg07.bmp");
	IMG_MGR->OpenImg("Images/TileImage/bg08.bmp");
	IMG_MGR->OpenImg("Images/TileImage/door01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/door02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/fence01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house03.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house04.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house05.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house06.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house07.bmp");
	IMG_MGR->OpenImg("Images/TileImage/house08.bmp");
	IMG_MGR->OpenImg("Images/TileImage/lawngrass01.bmp");
	IMG_MGR->GetImg("lawngrass01")->SetTrans(true, RGB(153, 51, 204));
	IMG_MGR->GetImg("lawngrass01")->SetFrame(6);
	IMG_MGR->OpenImg("Images/TileImage/lawngrass02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/post01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/post02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/sign01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/sign02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/stone01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/stone01_01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/stone02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/stone02_01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/tree03.bmp");
	IMG_MGR->OpenImg("Images/TileImage/tree04.bmp");
	IMG_MGR->OpenImg("Images/TileImage/wave01.bmp");
	IMG_MGR->OpenImg("Images/TileImage/wave02.bmp");
	IMG_MGR->OpenImg("Images/TileImage/black.bmp");

	int PosX;
	int PosY;
}

void MapManager::MoveUp()
{
	m_xOffset = 0;
	m_yOffset = -MAP_TILE_SIZE;
}

void MapManager::MoveDown()
{
	m_xOffset = 0;
	m_yOffset = MAP_TILE_SIZE;
}

void MapManager::MoveLeft()
{
	m_xOffset = -MAP_TILE_SIZE;
	m_yOffset = 0;
}

void MapManager::MoveRight()
{
	m_xOffset = MAP_TILE_SIZE;
	m_yOffset = 0;
}

void MapManager::ToggleGrid()
{
	m_gridMode = !m_gridMode;
}

void MapManager::DrawGrid(HDC _hdc)
{
	if (m_gridMode)
	{
		int xMax = WIN_WIDTH / MAP_TILE_SIZE;
		int yMax = WIN_HEIGHT / MAP_TILE_SIZE;

		for (int y = 0; y <= yMax; y++)
		{
			MoveToEx(_hdc, 0, y * MAP_TILE_SIZE, nullptr);
			LineTo(_hdc, WIN_WIDTH, y * MAP_TILE_SIZE);
		}
		for (int x = 0; x <= xMax; x++)
		{
			MoveToEx(_hdc, x * MAP_TILE_SIZE, 0, nullptr);
			LineTo(_hdc, x * MAP_TILE_SIZE, WIN_HEIGHT);
		}
	}
}

void MapManager::LoadMap(int _mapNumber)
{
	switch (_mapNumber)
	{
	case 0:
	{
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, "DB/map1.txt", "rb");
		int count;
		CTile tile;

		if (0 == err)
		{
			fread(&count, sizeof(int), 1, fp);

			m_TileVector[LAYER_TILE].clear();
			for (int i = 0; i < count; ++i)
			{
				fread(&tile, sizeof(CTile), 1, fp);

				m_TileVector[LAYER_TILE].push_back(tile);
			}

			m_TileVector[LAYER_OBJ].clear();
			for (int i = 0; i < count; ++i)
			{
				fread(&tile, sizeof(CTile), 1, fp);
				m_TileVector[LAYER_OBJ].push_back(tile);
			}

			fclose(fp);
		}

		m_currentMap = 0;
	}break;

	case 1:
	{
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, "DB/map2.txt", "rb");
		int count;
		CTile tile;

		if (0 == err)
		{
			fread(&count, sizeof(int), 1, fp);

			m_TileVector[LAYER_TILE].clear();
			for (int i = 0; i < count; ++i)
			{
				fread(&tile, sizeof(CTile), 1, fp);

				m_TileVector[LAYER_TILE].push_back(tile);
			}

			m_TileVector[LAYER_OBJ].clear();
			for (int i = 0; i < count; ++i)
			{
				fread(&tile, sizeof(CTile), 1, fp);
				m_TileVector[LAYER_OBJ].push_back(tile);
			}

			fclose(fp);
		}

		m_currentMap = 1;
	}break;
	}

	m_mapSize = { 100,70 };

	int index = 0;
	POINT pos;
	for (auto i : m_TileVector[LAYER_OBJ])
	{
		pos = { (index % m_mapSize.cx), (index / m_mapSize.cx) };
		if (_mapNumber == 0)
		{
			if (i.GetInfo().DrawOption == TILE_START)
			{
				m_startTile = pos;
			}
		}
		else
		{
			if (i.GetInfo().DrawOption == TILE_DOOR9)
			{
				m_startTile = pos;
			}
		}
		index++;
	}
}

POINT MapManager::GetStartTile()
{
	return m_startTile;
}

void MapManager::SetInteractTile(POINT _pos)
{
	m_interactTile = _pos;
	m_bushAni.Start();
}

bool MapManager::IsWalkable(POINT _pos)
{
	if (_pos.x > 0 && _pos.x < m_mapSize.cx && _pos.y > 0 && _pos.y < m_mapSize.cy)
	{
		if (m_TileVector[LAYER_TILE][_pos.x + (_pos.y * m_mapSize.cx)].GetInfo().DrawOption != TILE_OBSTACLE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool MapManager::IsBush(POINT _pos)
{
	if (_pos.x > 0 && _pos.x < m_mapSize.cx && _pos.y > 0 && _pos.y < m_mapSize.cy)
	{
		if (m_TileVector[LAYER_OBJ][_pos.x + (_pos.y * m_mapSize.cx)].GetInfo().DrawOption == TILE_BUSH)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void MapManager::IsPortal(POINT _pos)
{
	if (_pos.x > 0 && _pos.x < m_mapSize.cx && _pos.y > 0 && _pos.y < m_mapSize.cy)
	{
		if (m_TileVector[LAYER_OBJ][_pos.x + (_pos.y * 100)].GetInfo().DrawOption == TILE_DOOR9)
		{
			m_mapChanged = true;
		}
		else
		{
			m_mapChanged = false;
		}
	}
	else
	{
		m_mapChanged = false;
	}
}

bool MapManager::IsMapChange()
{
	return m_mapChanged;
}

POINT MapManager::GetCamPosition()
{
	return m_camPosition;
}

void MapManager::SetStart(POINT _startPos)
{
	m_camPosition.x = (_startPos.x - 7)* 64;
	m_camPosition.y = (_startPos.y - 5)* 64;
	m_prevCamPosition = m_camPosition;
}

void MapManager::SetCamPosition(int _x, int _y)
{
	m_camPosition.x = _x;
	m_camPosition.y = _y;
}

void MapManager::SetMapNumber(int _mapNumber)
{
	m_currentMap = _mapNumber;

	switch (_mapNumber)
	{
	case 0:
	{
		LoadMap(0);
	}break;

	case 1:
	{
		LoadMap(1);
	}break;
	}
}

int MapManager::GetMapNumber()
{
	return m_currentMap;
}

void MapManager::Update(float _elapseTime)
{
	m_elapseTime += _elapseTime;
	float value = m_elapseTime / TIMER.GetTimeUnit();

	if (m_elapseTime >= TIMER.GetTimeUnit())
	{
		m_elapseTime -= TIMER.GetTimeUnit();
	}

	if (value >= 1.0f)
	{
		PLAYER_MANAGER.SetIsMoving(false);
		SetCamPosition(m_prevCamPosition.x + m_xOffset, m_prevCamPosition.y + m_yOffset);
		m_prevCamPosition = m_camPosition;
		m_xOffset = 0;
		m_yOffset = 0;
	}
	else
	{
		SetCamPosition(m_prevCamPosition.x + (value * m_xOffset), m_prevCamPosition.y + (value * m_yOffset));
	}
}

void MapManager::BushUpdate(float _elapseTime)
{
	m_bushAni.Update(_elapseTime);
}

void MapManager::Render(HDC _hdc)
{
	RECT rt = {m_camPosition.x - 64 , m_camPosition.y - 64, m_camPosition.x + 1024, m_camPosition.y + 704};
	
	for (auto &i : m_TileVector[LAYER_TILE])
	{
		if (PtInRect(&rt, i.GetInfo().pos))
		{
			i.Render(_hdc);
		}
	}
}

void MapManager::RoadRender(HDC _hdc)
{
	RECT rt = { m_camPosition.x - 64 , m_camPosition.y - 64, m_camPosition.x + 1024, m_camPosition.y + 704 };

	for (auto &i : m_TileVector[LAYER_OBJ])
	{
		if (PtInRect(&rt, i.GetInfo().pos))
		{
			if (i.GetInfo().ImageType == IMAGE_BG01 || i.GetInfo().ImageType == IMAGE_BG02)
			{
				i.Render(_hdc);
			}
		}
	}
}

void MapManager::ObjRender(HDC _hdc, int _yPos)
{
	RECT rt = { m_camPosition.x - 64 , m_camPosition.y - 64, m_camPosition.x + 1024, m_camPosition.y + 704 };

	for (auto &i : m_TileVector[LAYER_OBJ])
	{
		if (PtInRect(&rt, i.GetInfo().pos) && i.GetInfo().pos.y / 64 == _yPos)
		{
			if (i.GetInfo().ImageType == IMAGE_LAWNGRASS01)
			{
				if(m_interactTile.x == i.GetInfo().pos.x/64 && m_interactTile.y == i.GetInfo().pos.y/64)
				{ 
					i.AniRender(_hdc, m_bushAni.m_nowIndex);
				}
				else
				{
					i.Render(_hdc);
				}
			}
			else if (i.GetInfo().ImageType != IMAGE_BG01 && i.GetInfo().ImageType != IMAGE_BG02)
			{
				i.Render(_hdc);
			}
		}
	}
}
