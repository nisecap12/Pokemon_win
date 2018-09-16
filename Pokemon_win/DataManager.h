#pragma once
#include "NPC.h"

struct DataUnit
{
	POINT player_pos;
	short mapNumber;
	short direction;
	short badgeCount;
	int money;
};

class DataManager
{
private:
	bool m_dataExist;

private:
	DataManager();
	~DataManager();

public:
	static DataManager& GetInstance()
	{
		static DataManager Instance;
		return Instance;
	}

	void Init();
	void SaveData();
	void LoadData();
	bool DataExist()
	{
		return m_dataExist;
	}
};

#define DATA_MANAGER DataManager::GetInstance()