#pragma once
#include "Tile.h"

enum MAP_NUMBER
{
	HOME_TOWN,
	ROAD_NO_1,
	VIRIDIAN_CITY,
	CHAMPION_ROAD,
};

class MapManager
{

private:
	POINT m_camPosition;
	POINT m_prevCamPosition;
	POINT m_mapPosition;
	float m_xOffset = 0.0f;
	float m_yOffset = 0.0f;
	float m_elapseTime = 0.0f;
	bool m_gridMode = false;
	bool m_mapChanged = false;
	std::vector<ImgClass*> m_mapList;
	int m_currentMap = 0;
	SIZE m_mapSize;
	POINT m_interactTile = {};
	POINT m_startTile = {};
	AniInfo m_bushAni;

	std::vector<CTile> m_TileVector[LAYER_END];

private:
	MapManager();
	~MapManager();

	void Save();
	void Load();

public:
	static MapManager& GetInstance()
	{
		static MapManager Instance;
		return Instance;
	}

	POINT GetCamPosition();

	void Init(HWND _hWnd);
	void Update(float _elapseTime);
	void BushUpdate(float _elapseTime);
	void Render(HDC _hdc);
	void RoadRender(HDC _hdc);
	void ObjRender(HDC _hdc, int _yPos);

	void SetStart(POINT _startPos);
	void SetCamPosition(int _x, int _y);
	void SetMapNumber(int _mapNumber);
	int GetMapNumber();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void ToggleGrid();
	void DrawGrid(HDC _hdc);
	void LoadMap(int _mapNumber);

	POINT GetStartTile();
	void SetInteractTile(POINT _pos);
	bool IsWalkable(POINT _pos);
	bool IsBush(POINT _pos);
	SIZE GetMapSize()
	{
		return m_mapSize;
	}
	
	void IsPortal(POINT _pos);
	bool IsMapChange();
};

#define MAP_MANAGER MapManager::GetInstance()