#pragma once

enum TileType 
{ 
	TILE_OBSTACLE,
	TILE_ENABLE_ROAD,
	TILE_START,
	TILE_DOOR1,
	TILE_DOOR2, 
	TILE_DOOR3, 
	TILE_DOOR4, 
	TILE_DOOR5, 
	TILE_DOOR6, 
	TILE_DOOR7, 
	TILE_DOOR8, 
	TILE_DOOR9, 
	TILE_BUSH, 
	TILE_FUNCTION_NONE, 
	TILE_VERTICAL, 
	TILE_HORIZEN, 
	TILE_END 
};
enum ImageType 
{
	IMAGE_TILE, IMAGE_TREE01, IMAGE_BG01, IMAGE_BG02, IMAGE_BG03, IMAGE_BG04, IMAGE_BG05, IMAGE_DOOR01, IMAGE_DOOR02, IMAGE_FENCE, IMAGE_HOUSE01, IMAGE_HOUSE02, IMAGE_HOUSE03, IMAGE_HOUSE04, IMAGE_HOUSE05, IMAGE_HOUSE06,
	IMAGE_HOUSE07, IMAGE_HOUSE08, IMAGE_LAWNGRASS01, IMAGE_LAWNGRASS02, IMAGE_POST01, IMAGE_POST02, IMAGE_SIGN01, IMAGE_SIGN02, IMAGE_STONE01, IMAGE_STONE02, IMAGE_STONE03, IMAGE_STONE04, IMAGE_TREE02, IMAGE_TREE03, IMAGE_WAVE01,
	IMAGE_WAVE02, IMAGE_BLACK, IMAGE_END
};
enum TileLayer { LAYER_TILE, LAYER_OBJ, LAYER_END };

struct TILEINFO
{
	bool click;
	POINT pos;
	SIZE size;
	RECT rc;
	int DrawIDX;
	int DrawIDY;
	int DrawOption; // 타일타입
	bool Drag;
	ImageType ImageType; // 이미지타입
	TileLayer LayerType; // 랜더링순서
};

class CTile
{
public:
	CTile();
	CTile(int _posX, int _posY);
	~CTile();
public:
	void Initialize();
	int Update();
	void Render(HDC _hdc);
	void AniRender(HDC _hdc, int _frameX);
	void Release();

public:
	bool operator == (POINT& _pos)
	{
		return m_tInfo.pos.x == _pos.x && m_tInfo.pos.y == _pos.y;
	}

public:
	TILEINFO& GetInfo() { return m_tInfo; }

public:
	void SetClick(bool _click) { m_tInfo.click = _click; }
	void SetTile(int _DrawX, int _DrawY, int _Option = 0) { m_tInfo.DrawIDX = _DrawX; m_tInfo.DrawIDY = _DrawY; m_tInfo.DrawOption = _Option; }
	void SetDrag(bool _Drag) { m_tInfo.Drag = _Drag; }
	void SetImageType(ImageType _image) { m_tInfo.ImageType = _image; }
	void SetInfo(TILEINFO& _rInfo) { m_tInfo = _rInfo; }
	void SetLayerType(TileLayer _type) { m_tInfo.LayerType = _type; }
	
private:
	TILEINFO m_tInfo;
};

