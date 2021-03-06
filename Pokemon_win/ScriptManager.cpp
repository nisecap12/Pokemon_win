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
	ScriptList.push_back({ 0,{ "神酵紫亜 匂掴佼 舌奄古古研 梅陥澗浦", "走榎 神酵紫亜 亀諺団辞 呪事掻戚空陥.", "戚 悦坦拭辞 神酵紫研 左暗窮 重壱馬慧" } });
	ScriptList.push_back({ 1,{ "賎舌 級鍔浦", "獲 繕遂馬惟 幻級 琶推亜 赤畏嬢..."} });
	ScriptList.push_back({ 2,{ "ぞぞぞぞぞ", "せせせせせせせ" } });
	ScriptList.push_back({ 3,{ "煽 焼捜原澗 耕庁紫寓戚醤", "畳原亜 亜猿戚亜走 源虞壱 梅嬢" } });
	ScriptList.push_back({ 4,{ "焼猿 戚雌廃 拝焼獄走亜 州紗生稽 亜澗杏 挫嬢", "誓? 蟹亀 刊浦走 侯虞" } });
	ScriptList.push_back({ 5,{ "照括馬室推 匂掴佼湿斗脊艦陥.", "帖戟馬獣畏柔艦猿?", "節獣 匂掴佼聖 乎焼砧畏柔艦陥.", "帖戟亜 魁概柔艦陥.", "照括備亜室推." } });
	
	
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
