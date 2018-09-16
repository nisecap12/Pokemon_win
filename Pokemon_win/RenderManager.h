#pragma once

class RenderManager
{
private :
	std::multimap<int, int> m_renderList;

private:
	RenderManager();
	~RenderManager();

public:
	static RenderManager& GetInstance()
	{
		static RenderManager Instance;
		return Instance;
	}

	void InsertImg(int _yPos, int _type);

	void Render(HDC _hdc);
};

#define RENDER_MANAGER RenderManager::GetInstance()