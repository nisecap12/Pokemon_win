#pragma once
#include "TextUI.h"
#include "BoxUI.h"

#define WIN_WIDTH 960
#define WIN_HEIGHT 640

enum SCENE_TYPE
{
	SCENE_INTRO,
	SCENE_MAIN,
	SCENE_MENU,
	SCENE_DIC,
	SCENE_POKEMON,
	SCENE_INFO,
	SCENE_BAG,
	SCENE_TRAINER,
	SCENE_REPORT,
	SCENE_SETTING,
	SCENE_BATTLE,
	SCENE_FOREST,
};

class Scene;

class SceneMgr
	: public TemplateSingletonA<SceneMgr>
{
	friend TemplateSingletonA;
private:
	std::vector<Scene*>	m_pScene;
	//SCENE_TYPE		m_SceneType = SCENE_MAIN;
	SCENE_TYPE		m_SceneType = SCENE_INTRO;
	bool			m_isChange	= true;
	BoxUI			m_box;
	TextUI			m_txt;
	ImgClass		m_tempScreen;
	HWND			m_hwnd;
	void*			m_msg;

	bool			isDialogShow = false;
	std::string		m_script;
	bool			m_isBattle = false;
	bool			m_isEnter = false;

	int				m_BoxType = 0;

private:
	SceneMgr();
	~SceneMgr();

	void	ChangeScene();

public:
	void	Init(HWND _hWnd);
	void	Update(float _elapseTime);
	void	Render(HDC _hdc);
	bool	WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);

	//	씬 타입 얻기 및 변환
	void SetScene()
	{
		switch (MAP_MANAGER.GetMapNumber())
		{
		case 0:
		{
			m_SceneType = SCENE_MAIN;
			m_isChange = true;
		}break;

		case 1:
		{
			m_SceneType = SCENE_FOREST;
			m_isChange = true;
		}break;
		}
	}

	void		SetScene(SCENE_TYPE _type)
	{
		m_SceneType = _type;
		m_isChange	= true;
	}
	
	SCENE_TYPE	GetScene()
	{
		return m_SceneType;
	}
	void SetScreen(HDC _hdc)
	{
		BitBlt(m_tempScreen.GetImgDC(), 0, 0, WIN_WIDTH, WIN_HEIGHT, _hdc, 0, 0, SRCCOPY);
	}
	HDC GetScreen()
	{
		return m_tempScreen.GetImgDC();
	}

	void CreateDialogBox(std::string _text);
	void RemoveDialogBox();
	void GoNextDialog();
	void SetMsg(void* _msg)
	{
		m_msg = _msg;
	}
	void* GetMsg()
	{
		return m_msg;
	}
	void	OpenScene(int _scene);
	void	CloseScene();
	bool	IsOnBattle();
	void	SetBattle(bool _isBattle);
	void	SetEnter(bool _b);
	bool	GetEnter()
	{
		return m_isEnter;
	}
	void SetBoxType(int _type)
	{
		m_BoxType = _type;
	}
	int GetBoxType()
	{
		return m_BoxType;
	}
};

#define		SCENE_MGR		SceneMgr::GetInstance()