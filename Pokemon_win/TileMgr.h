#pragma once

#include "Tile.h"
#include "TemplateSingletonB.h"

class CTileMgr : public TemplateSingletonB<CTileMgr>
{
	friend TemplateSingletonB;
private:
	CTileMgr();
	~CTileMgr();

public:
	void Initialize(HWND _hwnd);
	int Update();
	void Render(HDC _hdc);
	void ObjRender(HDC _hdc);
	void Release();

private:
	void Picking();
	void Clear();

public:
	std::vector<CTile>& GetVector(TileLayer _type) { return m_TileVector[_type]; }
	bool GetClick() { return m_bClick; }
	HDC& GetHDC() { return m_hdc; }
	bool GetInit() { return m_Init; }
	int GetScrollX() { return ScrollX; }
	int GetScrollY() { return ScrollY; }

public:
	void SetTile(int _DrawX, int _DrawY, int _Option = 0) { m_DrawIDX = _DrawX, m_DrawIDY = _DrawY; m_Option = _Option; }
	void SetClick(bool _click) { m_bClick = _click; }
	void SetDrag(bool _Drag) { m_bDrag = _Drag; }
	void SetDragXY(int _OldX, int _OldY, int _CurX, int _CurY) { m_DragOldX = _OldX; m_DragOldY = _OldY; m_DragCurX = _CurX; m_DragCurY = _CurY; }
	void SetTileOption(int _option) { m_Option = _option; }
	void SetImageType(ImageType _type) { m_ImageType = _type; }
	void SetLayerType(TileLayer _type) { m_TileLayerType = _type; }
	void UpScroll() { ScrollY -= 64; }
	void DownScroll() { ScrollY += 64; }
	void LeftScroll() { ScrollX -= 64; }
	void RightScroll() { ScrollX += 64; }
	POINT GetStartTile();
	
public:
	void Save();
	void Load();

private:
	std::vector<CTile> m_TileVector[LAYER_END];
	
	int m_DrawIDX;
	int m_DrawIDY;
	int m_Option;
	int m_bClick;
	bool m_bDrag = false;
	int m_DragOldX;
	int m_DragOldY;
	int m_DragCurX;
	int m_DragCurY;
	HDC m_hdc;
	HBITMAP m_hbitmap;
	HBITMAP m_holdbitmap;
	bool m_Init=false;
	bool m_Load = false;
	ImageType m_ImageType = IMAGE_END;
	TileLayer m_TileLayerType = LAYER_END;
	int ScrollX = 0;
	int ScrollY = 0;
	
	POINT m_interactTile = {};
};

#define TILE_MGR CTileMgr::GetInstance()