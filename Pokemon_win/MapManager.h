#pragma once
class MapManager
{
private:
	MapManager();
	~MapManager();

public:
	static MapManager& GetInstance()
	{
		static MapManager Instance;
		return Instance;
	}
};

#define MAP_MANAGER MapManager::GetInstance()