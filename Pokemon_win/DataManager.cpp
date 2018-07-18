#include "stdafx.h"
#include "DataManager.h"
using namespace std;

class Character;

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::Save(int _data)
{
}

void DataManager::Load(int& _data)
{
}

void DataManager::SaveTile(int _width, int _height, vector<int> _tileArray)
{
	
	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			_tileArray[x + (y * _width)];
		}
	}
}
