#include "stdafx.h"
#include "SceneMgr.h"

//	씬 클래스 포함
#include "Scene_Intro.h"
#include "Scene_Main.h"
#include "Scene_Menu.h"
#include "Scene_Dictionary.h"
#include "Scene_Pokemon.h"
#include "Scene_Info.h"
#include "Scene_Bag.h"
#include "Scene_Trainer.h"
#include "Scene_Report.h"
#include "Scene_Setting.h"
#include "Scene_Battle.h"
#include "Scene_Forest.h"
///////////////////////////

#include "NPC.h"

SceneMgr::SceneMgr()
{
}
SceneMgr::~SceneMgr()
{
	for (auto &i : m_pScene)
	{
		delete[] i;
	}
	m_pScene.clear();
}

void SceneMgr::ChangeScene()
{
	for (auto &i : m_pScene)
	{
		delete i;
	}
	m_pScene.clear();

	switch (m_SceneType)
	{
	case SCENE_TYPE::SCENE_INTRO:	m_pScene.push_back(new Scene_Intro);		break;
	case SCENE_TYPE::SCENE_MAIN:	m_pScene.push_back(new Scene_Main);			break;
	case SCENE_TYPE::SCENE_MENU:	m_pScene.push_back(new Scene_Menu);			break;
	case SCENE_TYPE::SCENE_DIC:		m_pScene.push_back(new Scene_Dictionary);	break;
	case SCENE_TYPE::SCENE_POKEMON:	m_pScene.push_back(new Scene_Pokemon);		break;
	case SCENE_TYPE::SCENE_INFO:	m_pScene.push_back(new Scene_Info);			break;
	case SCENE_TYPE::SCENE_BAG:		m_pScene.push_back(new Scene_Bag);			break;
	case SCENE_TYPE::SCENE_TRAINER:	m_pScene.push_back(new Scene_Trainer);		break;
	case SCENE_TYPE::SCENE_REPORT:	m_pScene.push_back(new Scene_Report);		break;
	case SCENE_TYPE::SCENE_SETTING:	m_pScene.push_back(new Scene_Setting);		break;
	case SCENE_TYPE::SCENE_BATTLE:	m_pScene.push_back(new Scene_Battle);		break;
	case SCENE_TYPE::SCENE_FOREST:	m_pScene.push_back(new Scene_Forest);		break;

	default: break;
	}

	m_pScene.back()->Init(m_hwnd);
	m_isChange = false;
}

void SceneMgr::Init(HWND _hWnd)
{
	m_hwnd = _hWnd;

	//콜백등록
	for (auto &i : NPC_MANAGER.GetNPCList())
	{
		i->SetHandler(std::bind(&SceneMgr::CreateDialogBox, this, std::placeholders::_1));
		i->SetStopHandler(std::bind(&SceneMgr::RemoveDialogBox, this));
		i->SetScriptHandler(std::bind(&SceneMgr::GoNextDialog, this));
	}

	m_tempScreen.CreateImg(_hWnd, WIN_WIDTH, WIN_HEIGHT);
	IMG_MGR->SethWnd(_hWnd);

	IMG_MGR->OpenImg("Images/UI/Dialog_00.bmp");
	IMG_MGR->OpenImg("Images/UI/Dialog_01.bmp");

	//	포켓몬이미지
	IMG_MGR->OpenImg("Images/UI/pokemonImg_01.bmp");
	IMG_MGR->OpenImg("Images/UI/pokemonImg_02.bmp");
	IMG_MGR->OpenImg("Images/UI/pokemonImg_03.bmp");
	auto	pokemonImg1 = IMG_MGR->GetImg("pokemonImg_01");
	if (pokemonImg1 != nullptr)
	{
		pokemonImg1->SetTrans();
		pokemonImg1->SetFrame(151);
	}
	auto	pokemonImg2 = IMG_MGR->GetImg("pokemonImg_02");
	if (pokemonImg2 != nullptr)
	{
		pokemonImg2->SetTrans(TRUE, RGB(255, 0, 251));
		pokemonImg2->SetFrame(151);
	}
	auto	pokemonImg3 = IMG_MGR->GetImg("pokemonImg_03");
	if (pokemonImg3 != nullptr)
	{
		pokemonImg3->SetTrans();
		pokemonImg3->SetFrame(151, 2);
	}

	//	가방
	IMG_MGR->OpenImg("Images/UI/Bag_00.bmp");
	IMG_MGR->OpenImg("Images/UI/Bag_01.bmp");
	IMG_MGR->OpenImg("Images/UI/Arrow_Up.bmp");
	IMG_MGR->OpenImg("Images/UI/Arrow_Down.bmp");
	IMG_MGR->OpenImg("Images/UI/Arrow_Left.bmp");
	IMG_MGR->OpenImg("Images/UI/Arrow_Right.bmp");
	IMG_MGR->OpenImg("Images/UI/Item.bmp");
	IMG_MGR->OpenImg("Images/UI/xMark.bmp");
	IMG_MGR->OpenImg("Images/UI/bagDialog.bmp");

	IMG_MGR->GetImg("bagDialog")->SetTrans();

	auto	bagImg = IMG_MGR->GetImg("Bag_01");
	if (bagImg != nullptr)
	{
		bagImg->SetTrans();
		bagImg->SetFrame(4);
	}

	auto	arrowUp = IMG_MGR->GetImg("Arrow_Up");
	if (arrowUp != nullptr)
	{
		arrowUp->SetTrans();
		arrowUp->SetFrame(6);

	}
	auto	arrowDown = IMG_MGR->GetImg("Arrow_Down");
	if (arrowDown != nullptr)
	{
		arrowDown->SetTrans();
		arrowDown->SetFrame(6);
	}
	auto	arrowLeft = IMG_MGR->GetImg("Arrow_Left");
	if (arrowLeft != nullptr)
	{
		arrowLeft->SetTrans();
		arrowLeft->SetFrame(6);
	}
	auto	arrowRight = IMG_MGR->GetImg("Arrow_Right");
	if (arrowRight != nullptr)
	{
		arrowRight->SetTrans();
		arrowRight->SetFrame(6);
	}
	auto	itemImg = IMG_MGR->GetImg("Item");
	if (itemImg != nullptr)
	{
		itemImg->SetTrans();
		itemImg->SetFrame(28);
	}


	//	포켓몬
	IMG_MGR->OpenImg("Images/UI/Pokemon_00.bmp");
	IMG_MGR->OpenImg("Images/UI/Pokemon_01.bmp");
	IMG_MGR->OpenImg("Images/UI/Pokemon_02.bmp");
	IMG_MGR->OpenImg("Images/UI/Pokemon_03.bmp");
	IMG_MGR->OpenImg("Images/UI/PokemonChange_01.bmp");
	IMG_MGR->OpenImg("Images/UI/PokemonChange_02.bmp");
	IMG_MGR->OpenImg("Images/UI/redbar.bmp");
	IMG_MGR->OpenImg("Images/UI/yellowbar.bmp");
	IMG_MGR->OpenImg("Images/UI/greenbar.bmp");
	auto	focusImg1 = IMG_MGR->GetImg("Pokemon_01");
	if (focusImg1 != nullptr)
	{
		focusImg1->SetTrans();
		focusImg1->SetFrame(2);
	}

	auto	focusImg2 = IMG_MGR->GetImg("Pokemon_02");
	if (focusImg2 != nullptr)
	{
		focusImg2->SetTrans();
		focusImg2->SetFrame(2);
	}

	auto	focusImg3 = IMG_MGR->GetImg("Pokemon_03");
	if (focusImg3 != nullptr)
	{
		focusImg3->SetTrans();
		focusImg3->SetFrame(2);
	}

	auto	changeImg1 = IMG_MGR->GetImg("PokemonChange_01");
	if (changeImg1 != nullptr)
	{
		changeImg1->SetTrans();
		changeImg1->SetFrame(2);
	}

	auto	changeImg2 = IMG_MGR->GetImg("PokemonChange_02");
	if (changeImg2 != nullptr)
	{
		changeImg2->SetTrans();
		changeImg2->SetFrame(2);
	}
	
	//	Info(포켓몬 상태보기)
	IMG_MGR->OpenImg("Images/UI/Info_01.bmp");
	IMG_MGR->OpenImg("Images/UI/Info_02.bmp");
	IMG_MGR->OpenImg("Images/UI/Info_03.bmp");
	IMG_MGR->OpenImg("Images/UI/Type_01.bmp");

	auto	typeImg = IMG_MGR->GetImg("Type_01");
	if (typeImg != nullptr)
	{
		typeImg->SetTrans();
		typeImg->SetFrame(18);
	}

	//	리포트
	IMG_MGR->OpenImg("Images/UI/Dialog_01.bmp");
	IMG_MGR->OpenImg("Images/UI/SaveBox1.bmp");
	IMG_MGR->OpenImg("Images/UI/SaveBox2.bmp");
	auto	dialogImg = IMG_MGR->GetImg("Dialog_01");
	if (dialogImg != nullptr)
	{
		dialogImg->SetTrans();
	}
	auto	saveImg1 = IMG_MGR->GetImg("SaveBox1");
	if (saveImg1 != nullptr)
	{
		saveImg1->SetTrans();
	}
	auto	saveImg2 = IMG_MGR->GetImg("SaveBox2");
	if (saveImg2 != nullptr)
	{
		saveImg2->SetTrans();
	}

	//	세팅
	IMG_MGR->OpenImg("Images/UI/SettingMenu.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuSBOX.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack0.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack1.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack2.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack3.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack4.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack5.bmp");
	IMG_MGR->OpenImg("Images/UI/SettingMenuBlack6.bmp");
	IMG_MGR->OpenImg("Images/SB/SB01_01.bmp");
	IMG_MGR->OpenImg("Images/SB/SB01_02.bmp");
	IMG_MGR->OpenImg("Images/SB/SB02_01.bmp");
	IMG_MGR->OpenImg("Images/SB/SB02_02.bmp");
	IMG_MGR->OpenImg("Images/SB/SB03_01.bmp");
	IMG_MGR->OpenImg("Images/SB/SB03_02.bmp");
	IMG_MGR->GetImg("SB02_02")->SetTrans(true, TRANS_COLOR);
	IMG_MGR->GetImg("SB02_01")->SetTrans(true, TRANS_COLOR);

	//	사전
	IMG_MGR->OpenImg("Images/UI/Dic_01.bmp");
	IMG_MGR->OpenImg("Images/UI/Dic_02.bmp");
	IMG_MGR->OpenImg("Images/UI/Dic_03.bmp");
	auto dic = IMG_MGR->GetImg("Dic_02");
	if (dic != nullptr)
	{
		dic->SetTrans();
		dic->SetFrame(2);
	}

	//	배틀
	IMG_MGR->OpenImg("Images/UI/Battle_bg.bmp");		//	배경
	IMG_MGR->OpenImg("Images/UI/Battle_grass.bmp");		//	배경
	IMG_MGR->OpenImg("Images/UI/Dialog_02.bmp");		//	대화창
	IMG_MGR->OpenImg("Images/UI/BattleInfo_01.bmp");	//	대화창
	IMG_MGR->OpenImg("Images/UI/BattleInfo_02.bmp");	//	대화창
	IMG_MGR->OpenImg("Images/UI/Player.bmp");
	IMG_MGR->OpenImg("Images/UI/ThrowBall.bmp");
	IMG_MGR->OpenImg("Images/UI/Battle_Choice.bmp");
	IMG_MGR->OpenImg("Images/UI/Battle_Attack.bmp");
	IMG_MGR->OpenImg("Images/UI/Battle_Select.bmp");
	IMG_MGR->OpenImg("Images/UI/openBall.bmp");
	auto	field = IMG_MGR->GetImg("Battle_grass");
	if (field != nullptr)
	{
		field->SetTrans();
	}
	auto	myInfo = IMG_MGR->GetImg("BattleInfo_01");
	if (myInfo != nullptr)
	{
		myInfo->SetTrans();
		myInfo->SetFrame(2);
	}
	auto	enemyInfo = IMG_MGR->GetImg("BattleInfo_02");
	if (enemyInfo != nullptr)
	{
		enemyInfo->SetTrans();
	}
	auto	playerImg = IMG_MGR->GetImg("Player");
	if (playerImg != nullptr)
	{
		playerImg->SetTrans();
		playerImg->SetFrame(5);
	}
	auto	ballImg = IMG_MGR->GetImg("ThrowBall");
	if (ballImg != nullptr)
	{
		ballImg->SetTrans();
		ballImg->SetFrame(9);
	}
	auto	battleSelect = IMG_MGR->GetImg("Battle_Select");
	if (battleSelect != nullptr)
	{
		battleSelect->SetTrans();
	}
	auto	openBall = IMG_MGR->GetImg("openBall");
	if (openBall != nullptr)
	{
		openBall->SetTrans();
		openBall->SetFrame(4);
	}

	//트레이너 카드
	IMG_MGR->OpenImg("Images/UI/TrainerCard.bmp");
	IMG_MGR->OpenImg("Images/UI/League.bmp");

	//트레이너
	IMG_MGR->OpenImg("Images/Trainer/Trainer_01.bmp");
	auto	trainerImg1 = IMG_MGR->GetImg("Trainer_01");
	if (trainerImg1 != nullptr)
	{
		trainerImg1->SetTrans();
	}

	m_box.Init(_hWnd);
}

void SceneMgr::Update(float _elapseTime)
{
	if (m_isChange == true) ChangeScene();

	if (m_pScene.size() == 0) return;

	else
	{
		m_pScene.back()->Update(_elapseTime);
	}

	if (KEY_MANAGER.OnceKeyDown('Z'))
	{
		if (isDialogShow)
		{
			GoNextDialog();
		}
	}

	if (KEY_MANAGER.OnceKeyDown('R'))
	{
		POKEMON_MANAGER.RootMyPokemon();
	}
}

void SceneMgr::Render(HDC _hdc)
{
	if (_hdc == nullptr || m_pScene.size() == 0) return;

	m_pScene.back()->Render(_hdc);

	if (isDialogShow)
	{
		m_box.BoxCreate(_hdc, 0, 14, 29, 19);
		m_txt.TextBox(_hdc, 60, 448 + 32, m_script.c_str());
	}
}

bool SceneMgr::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	if (m_pScene.size() == 0) return false;
	
	return m_pScene.back()->WndProc(_hWnd, _message, _wParam, _lParam);
}

void SceneMgr::CreateDialogBox(std::string _text)
{
	isDialogShow = true;
	m_script = _text;
}

void SceneMgr::RemoveDialogBox()
{
	isDialogShow = false;
}

void SceneMgr::GoNextDialog()
{
	for (auto &i : NPC_MANAGER.GetNPCList())
	{
		i->GoNextScript();
	}
}

void SceneMgr::OpenScene(int _scene)
{
	switch (_scene)
	{
	case SCENE_BATTLE:
	{
		m_pScene.push_back(new Scene_Battle);
	}break;
	case SCENE_BAG:
	{
		m_pScene.push_back(new Scene_Bag);
	}break; 

	case SCENE_POKEMON:
	{
		m_pScene.push_back(new Scene_Pokemon);
	}break;
	case SCENE_INFO:
	{
		m_pScene.push_back(new Scene_Info);
	}break;
	case SCENE_MENU:
	{
		m_pScene.push_back(new Scene_Menu);
	}break;
	case SCENE_DIC:
	{
		m_pScene.push_back(new Scene_Dictionary);
	}break;
	case SCENE_TRAINER:
	{
		m_pScene.push_back(new Scene_Trainer);
	}break;
	case SCENE_REPORT:
	{
		m_pScene.push_back(new Scene_Report);
	}break;
	case SCENE_SETTING:
	{
		m_pScene.push_back(new Scene_Setting);
	}break;
	case SCENE_FOREST:
	{
		m_pScene.push_back(new Scene_Forest);
	}
	}

	m_pScene.back()->Init(nullptr);
}

void SceneMgr::CloseScene()
{
	m_pScene.pop_back();
}

bool SceneMgr::IsOnBattle()
{
	return m_isBattle;
}

void SceneMgr::SetBattle(bool _isBattle)
{
	m_isBattle = _isBattle;
}

void SceneMgr::SetEnter(bool _b)
{
	m_isEnter = _b;
}
