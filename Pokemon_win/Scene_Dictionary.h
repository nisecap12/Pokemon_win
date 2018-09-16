#pragma once
#include "Scene.h"
#include <vector>
using namespace std;
typedef TextUI Text;

enum DICTIONARY_IMAGE_TYPE
{
	BY_NUMBER,
	BY_GRASS_FILED,
	BY_FOREST,
	BY_WATER,
	BY_SEA,
	BY_CAVE,
	BY_MOUNTAIN,
	BY_WILDERNESS,
	BY_CITY,
	BY_RARE,
	BY_ABC,
	BY_TYPE,
	BY_WEIGHT,
	BY_SIZE,
	BY_CLOSE
};

struct Label
{
	const char* m_text;
	short isCategory;
};

class Scene_Dictionary :
	public Scene
{
private:
	SIZE m_CellSize = { 32, 32 };

	vector<Label> m_labelList;

	Text text;

	int		m_CursorIndex = 1;
	int		m_Number_CursorIndex = 0;
	int		m_TopIndex = 0;
	int		m_imgIndex = 0;
	int		m_DicSelect = 0;
	int		m_isCheck[15] = {};
	int		m_select = 0;
	int		m_WordSize = 50;
	int		m_Ani = 0;

	bool	isPopup = false;
	bool	m_isDraw = false;
	bool	m_isChange = false;
	bool	m_isClick = false;
	bool	m_isSelect = false;

	std::string m_Numbering[151];

public:
	Scene_Dictionary();
	~Scene_Dictionary();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);

	void Create_Arrow(HDC _hdc, int _posX, int _posY);

	//	도감 - 번호 순
	void Render_Dictionary_List(HDC _hdc, int width, int _height);

	//	도감 - 기타 - 도감을 닫는다.
	void Render_Dictionary_Close()
	{
		SCENE_MGR.SetScene(SCENE_MENU);
	}
};