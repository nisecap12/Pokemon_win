#pragma once
class Scene_Forest :
	public Scene
{
private:
	bool isEnter = true;
	bool isIntro = false;

	float m_time = 0.0f;
	bool m_isGridMode = false;
	std::stringstream m_posStr;
	POINT m_mousePos;
	bool m_rideBike = false;
	int fadeAlpha = 255;

public:
	Scene_Forest();
	~Scene_Forest();

	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
	void	SetEnter()
	{
		isEnter = true;
	}
};

