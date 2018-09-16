#include "stdafx.h"

using namespace std;

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::Init()
{
	LoadData();
}

void DataManager::SaveData()
{
	DataUnit* data = new DataUnit;
	std::ofstream fout("DB/SaveData.db", std::ios::binary);

	data->player_pos = PLAYER_MANAGER.GetPosition();
	data->direction = PLAYER_MANAGER.GetDirection();
	data->badgeCount = PLAYER_MANAGER.GetBadgeCount();
	data->money = PLAYER_MANAGER.GetMoney();
	data->mapNumber = MAP_MANAGER.GetMapNumber();

	if (fout.fail() == false)
	{
		fout.write((const char*)data, sizeof(DataUnit));
	}

	delete data;
	m_dataExist = true;

	POKEMON_MANAGER.SaveMyPokemon();
}

void DataManager::LoadData()
{
	DataUnit* data = new DataUnit;
	std::ifstream fout;

	fout.open("DB/SaveData.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.read((char*)data, sizeof(DataUnit));
		fout.close();

		PLAYER_MANAGER.SetData(data->player_pos, data->direction, data->badgeCount, data->money);
		MAP_MANAGER.SetMapNumber(data->mapNumber);
		m_dataExist = true;
	}
	else
	{
		m_dataExist = false;
	}
}
