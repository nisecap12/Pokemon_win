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
	ScriptList.push_back({ 0,{ "���ڻ簡 ���ϸ� ���ŸŸ� �ߴٴ±�", "���� ���ڻ簡 �����ļ� �������̶���.", "�� ��ó���� ���ڻ縦 ���ŵ� �Ű��Ϸ�" } });
	ScriptList.push_back({ 1,{ "���� ���ױ�", "�� �����ϰ� ���� �ʿ䰡 �ְھ�..."} });
	ScriptList.push_back({ 2,{ "����������", "��������������" } });
	ScriptList.push_back({ 3,{ "�� ���ܸ��� ��ģ����̾�", "������ �����̰��� ����� �߾�" } });
	ScriptList.push_back({ 4,{ "�Ʊ� �̻��� �Ҿƹ����� �������� ���°� �þ�", "��? ���� ������ ����" } });
	ScriptList.push_back({ 5,{ "�ȳ��ϼ��� ���ϸ����Դϴ�.", "ġ���Ͻðڽ��ϱ�?", "��� ���ϸ��� �þƵΰڽ��ϴ�.", "ġ�ᰡ �������ϴ�.", "�ȳ���������." } });
	
	
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
