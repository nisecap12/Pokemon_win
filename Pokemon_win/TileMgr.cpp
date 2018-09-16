#include "stdafx.h"
#include "TileMgr.h"
#include "ImgMgr.h"


CTileMgr::CTileMgr()
{
}


CTileMgr::~CTileMgr()
{
	Release();
}

void CTileMgr::Initialize(HWND _hwnd)
{
	IMG_MGR->SethWnd(_hwnd);
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
	for (int i = 0; i < LAYER_END; ++i)
	{
		for (int y = 0; y < TILEY; ++y)
		{
			for (int x = 0; x < TILEX; ++x)
			{
				/*PosX = x * MAP_TILE_SIZE + (MAP_TILE_SIZE / 2);
				PosY = y * MAP_TILE_SIZE + (MAP_TILE_SIZE / 2);*/
				CTile tile(x, y);
				tile.SetLayerType((TileLayer)i);

				m_TileVector[i].push_back(tile);
			}
		}
	}

	Load();
}

int CTileMgr::Update()
{
	std::vector<CTile>::iterator iter_begin = m_TileVector[LAYER_TILE].begin();
	std::vector<CTile>::iterator iter_end = m_TileVector[LAYER_TILE].end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		if (iter_begin->GetInfo().DrawOption == TILE_BUSH)
		{

			if (PtInRect(&iter_begin->GetInfo().rc, PLAYER_MANAGER.GetPosition()))
			{
				BATTLE_MANAGER.StartBattle(0, false);
				break;
			}

		}
	}



	return 0;
}

void CTileMgr::Render(HDC _hdc)
{
	std::vector<CTile>::iterator iter_begin = m_TileVector[LAYER_TILE].begin();
	std::vector<CTile>::iterator iter_end = m_TileVector[LAYER_TILE].end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		
		iter_begin->Render(_hdc);
	}
}

void CTileMgr::ObjRender(HDC _hdc)
{
	std::vector<CTile>::iterator iter_begin = m_TileVector[LAYER_OBJ].begin();
	std::vector<CTile>::iterator iter_end = m_TileVector[LAYER_OBJ].end();
	for (; iter_begin != iter_end; ++iter_begin)
	{
		iter_begin->Render(_hdc);
	}
}

void CTileMgr::Release()
{
	Save();
}

POINT CTileMgr::GetStartTile()
{
	int width = MAPSIZEX / 64;
	int height = MAPSIZEY / 64;
	int index = 0;
	POINT pos;
	for (auto i : m_TileVector[LAYER_TILE])
	{
		pos = { (index % width), (index / width)};
		if (i.GetInfo().DrawOption == TILE_START)
		{
			return pos;
		}
		index++;
	}
	return {-1,-1};
}

void CTileMgr::Save()
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

void CTileMgr::Load()
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
}
