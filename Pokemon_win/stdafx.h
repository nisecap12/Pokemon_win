// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once
#undef UNICODE
// Windows 헤더 파일:
#include <Windows.h>
#include <windowsx.h>
#include "resource.h"

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "TemplateSingletonA.h"
#include "NPC.h"
#include "ImgMgr.h"
#include "TimerManager.h"
#include "DataManager.h"
#include "NPCManager.h"
#include "MapManager.h"
#include "BattleManager.h"
#include "SkillManager.h"
#include "ItemManager.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include "PlayerManager.h"
#include "PokemonManager.h"
#include "BagManager.h"
#include "KeyManager.h"
#include "SoundManager.h"
#include "ScriptManager.h"
#include "RenderManager.h"
#include "Scene_Main.h"
#include "BoxUI.h"
#include "TextUI.h"
#include "Tile.h"
#include "SceneMgr.h"

#define BLACK		RGB(0, 0, 0)
#define WHITE		RGB(255, 255, 255)
#define ORANGE		RGB(255, 69, 0)
#define RED			RGB(255, 0, 0)
#define LORANGE		RGB(224, 168, 104)
#define GRAY		RGB(96, 96, 96)
#define LGRAY		RGB(208, 208, 208)
#define BLUE		RGB(49, 81, 201)
#define LBLUE		RGB(150, 181, 236)

#define MAPSIZEX 6400
#define MAPSIZEY 4480

#define TILEX MAPSIZEX / MAP_TILE_SIZE
#define TILEY MAPSIZEY / MAP_TILE_SIZE

#define MAP_TILE_SIZE 64
#define HERO_WIDTH 80
#define HERO_HEIGHT 88
#define WIN_WIDTH 960
#define WIN_HEIGHT 640
#define DEFAULT_FPS 60
#define NPC_TOTAL_NUMBER 8
#define TRAINER_TOTAL_NUMBER 2
#define POKEMON_TOTAL_NUMBER 151
#define SKILL_TOTAL_NUMBER 165
#define ITEM_TOTAL_NUMBER 29
#define TRANS_COLOR RGB(255,0,255)

//방향
enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum STEP
{
	NO_FEET,
	R_FEET,
	L_FEET,
};

enum SEX
{
	MALE,
	FEMALE,
};

enum CONDITION
{
	NO_CONDITION,
	POISONED,
	SLEEP,
	PARELIZED,
	ICED,
	BURN,
};

/*
- 아이템 정리 -
중요한 물건 : 낚싯대, 자전거, 지도 등....
도구 : 상처약, 이상한사탕, 진화돌, 상태회복약 등...
포켓볼 : 포켓볼, 슈퍼볼, 하이퍼볼, 마스터볼 .....
*/

enum ItemType
{
	SPECIAL,
	TOOL,
	BALL,
};

enum ItemFunction
{
	POTION,
	RECOVERY,
	REVIVE,
	EVOLVE,
	LEVUP,
};

enum SpecialItem
{
	DICTIONARY,
	MAP,
	SHOES,
	BIKE,
	ROD,
};

/*
NPC 행동
1. 일반 NPC
한 방향 주시하다가 말걸면 캐릭터를 쳐다보며 스크립트 재생
*/

//NPC 기능
enum NPC_FUNCTION
{
	NONE,		//일반
	HEAL,		//포켓몬센터
	SHOP,		//상점
	TRAINER,	//일반 트레이너
	CHAMP,		//체육관 관장
};

//NPC 상태
enum NPC_STATE
{
	NPC_NORMAL,		//일반
	ENCOUNTER,	//조우
	COMING,
	INTERACT,	//상호작용
	FINISHED,
};

//NPC 행동패턴
enum NPC_PATTERN
{
	STARRING, //주시
	TURN_ARROUND_CLOCKWISE, //주변 시계방향 빙글빙글 배회
	TURN_ARROUND_COUNTER_CLOCKWISE, //반시계방향 배회
	TURNING, //제자리 빙글빙글
	RANDOM, //랜덤 행동
};

//RENDER TYPE

enum RENDER_TYPE
{
	RENDER_BUSH,
	RENDER_NPC,
	RENDER_PLAYER,
};

static int			m_SettingMenu_Num = 0;
static int			m_SettingMenu_TextSpeed = 0;
static int			m_SettingMenu_BattleScene = 0;
static int			m_SettingMenu_BattleStyle = 0;
static int			m_SettingMenu_ButtonMode = 0;
static int			m_SettingMenu_Frame = 0;
static float		m_SettingMenu_Sound = 10.0f;
static float		g_playTime = 200.0f;
