#include "stdafx.h"
#include "ScriptManager.h"


ScriptManager::ScriptManager()
{
}


ScriptManager::~ScriptManager()
{
}

void ScriptManager::Init()
{
	ScriptList.push_back({ 0,{ "오박사가 포켓몬 장기매매를 했다는군", "지금 오박사가 도망쳐서 수색중이란다.", "이 근처에서 오박사를 보거든 신고하렴" } });
	ScriptList.push_back({ 1,{ "젠장 들켰군", "넌 조용하게 만들 필요가 있겠어..."} });
	ScriptList.push_back({ 2,{ "ㅎㅎㅎㅎㅎ", "ㅋㅋㅋㅋㅋㅋㅋ" } });
	ScriptList.push_back({ 3,{ "저 아줌마는 미친사람이야", "엄마가 가까이가지 말라고 했어" } });
	ScriptList.push_back({ 4,{ "아까 이상한 할아버지가 숲속으로 가는걸 봤어", "응? 나도 누군지 몰라" } });
	ScriptList.push_back({ 5,{ "안녕하세요 포켓몬센터입니다.", "치료하시겠습니까?", "잠시 포켓몬을 맡아두겠습니다.", "치료가 끝났습니다.", "안녕히가세요." } });
	
	
}

std::vector<std::string> ScriptManager::GetScript(int _npcNumber)
{
	for (int i = 0; i < ScriptList.size(); i++)
	{
		if (ScriptList[i].npcNumber == _npcNumber)
		{
			return ScriptList[i].script;
		}
	}

	return std::vector<std::string>();
}
