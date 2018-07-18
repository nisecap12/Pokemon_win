#pragma once

class Character;

class DataManager
{

private:
	DataManager();
	~DataManager();

public:
	static DataManager& GetInstance()
	{
		static DataManager Instance;
		return Instance;
	}

	
	void Save(int _data);
	void Load(int& _data);

	void SaveTile(int _width, int _height, vector<int> _tileArray);
	void LoadTile();
};

#define DATA_MANAGER DataManager::GetInstance()