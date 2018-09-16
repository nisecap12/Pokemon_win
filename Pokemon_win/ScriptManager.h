#pragma once

struct NPC_SCRIPT
{
	int npcNumber;
	std::vector<std::string> script;
};

class ScriptManager
{
private:
	std::vector<NPC_SCRIPT> ScriptList;

private:
	ScriptManager();
	~ScriptManager();

public:
	static ScriptManager& GetInstance()
	{
		static ScriptManager Instance;
		return Instance;
	}

	void Init();
	std::vector<std::string> GetScript(int _npcNumber);
};

#define SCRIPT_MANAGER ScriptManager::GetInstance()