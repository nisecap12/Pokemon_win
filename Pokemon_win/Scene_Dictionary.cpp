#include "stdafx.h"
#include "Scene_Dictionary.h"
#include "SceneMgr.h"

typedef TextUI Text;

Scene_Dictionary::Scene_Dictionary()
{
	int i = 0;
	m_labelList.push_back({ "포켓몬   목록" , 0});
	m_labelList.push_back({ "번호  순" , 1 });
	m_labelList.push_back({ "여러장소에   사는   포켓몬" , 0 });
	m_labelList.push_back({ "초원에   사는   포켓몬" , 1 });
	m_labelList.push_back({ "숲에   사는   포켓몬", 1 });
	m_labelList.push_back({ "물가에   사는   포켓몬", 1 });
	m_labelList.push_back({ "바다에   사는   포켓몬" , 1 });
	m_labelList.push_back({ "동굴에   사는   포켓몬" , 1 });
	m_labelList.push_back({ "산에   사는   포켓몬" , 1 });
	m_labelList.push_back({ "황야에   사는   포켓몬", 1 });
	m_labelList.push_back({ "도시에   사는   포켓몬", 1 });
	m_labelList.push_back({ "희귀한   포켓몬" , 1 });
	m_labelList.push_back({ "정   렬" , 0 });
	m_labelList.push_back({ "가나다   순" , 1 });
	m_labelList.push_back({ "타입   순", 1 });
	m_labelList.push_back({ "무게   순", 1 });
	m_labelList.push_back({ "크기   순", 1 });
	m_labelList.push_back({ "기타" , 0 });
	m_labelList.push_back({ "도감을   닫는다" , 1 });
	
	std::stringstream buf;
	for (int i = 0; i < 151; i++)
	{
		buf.str("");
		buf << "No";
		if (i < 99)
		{
			buf << 0;
		}
		if (i < 9)
		{
			buf << 0;
		}
		 buf << i + 1 << "        " << POKEDEX.GetPokemonData(i).m_name;
		 m_Numbering[i] = buf.str().c_str();
	}


}

Scene_Dictionary::~Scene_Dictionary()
{
}

void Scene_Dictionary::Init(HWND _hWnd)
{
}

void Scene_Dictionary::Update(float _elapseTime)
{
}

void Scene_Dictionary::Render(HDC _hdc)
{
	HDC _BGDC = IMG_MGR->GetImg("Dic_01")->GetImgDC();
	BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, _BGDC, 0, 0, SRCCOPY);

	if (isPopup == false)
	{
		auto dic = IMG_MGR->GetImg("Dic_02");
		auto arrowUp = IMG_MGR->GetImg("Arrow_Up");
		auto arrowDown = IMG_MGR->GetImg("Arrow_Down");

		Create_Arrow(_hdc, 50, 66 + (m_CursorIndex * (m_WordSize + 6)));

		for (int i = 0; i < 9; i++)
		{
			if ((signed)m_labelList.size() > i + m_TopIndex)
			{
				if (m_labelList[i + m_TopIndex].isCategory == 0)
				{
					text.TextBox(_hdc, 15, 66 + (i * m_WordSize) + (i * 6), m_labelList[i + m_TopIndex].m_text, m_WordSize, ORANGE);
				}
				else if (m_labelList[i + m_TopIndex].isCategory == 1)
				{
					text.TextBox(_hdc, 80, 66 + (i * m_WordSize) + (i * 6), m_labelList[i + m_TopIndex].m_text, m_WordSize, BLACK);
				}
			}
		}

		text.TextBox(_hdc, 680, 113, "발견한  포켓몬", (m_WordSize - 10), BLACK);
		text.TextBox(_hdc, 680, 203, "잡은  포켓몬", (m_WordSize - 10), BLACK);

		dic->AniRender(_hdc, m_imgIndex, 670, 300);
		arrowUp->AniRender(_hdc, m_Ani, 770, 40);
		arrowDown->AniRender(_hdc, m_Ani, 770, 560);
	}

	else if (isPopup == true)
	{
		Render_Dictionary_List(_hdc, WIN_WIDTH, WIN_HEIGHT);
	}
}

#pragma region
void Scene_Dictionary::Create_Arrow(HDC _hdc, int _posX, int _posY)
{
	auto select = IMG_MGR->GetImg("Select");
	select->Render(_hdc, _posX, _posY);
}
#pragma endregion 커서(화살표) 만드는 함수

bool Scene_Dictionary::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_UP:
		{
			SOUND_MGR.PlaySoundTrack(12);

			//	메인 화면에서의 텍스트 스크롤
			if (!isPopup)
			{
				if (m_CursorIndex > 1)
				{
					if (m_CursorIndex == 4)
					{
						if (m_TopIndex == 0)
						{
							if (m_labelList[m_CursorIndex - 1].isCategory == 0)
							{
								m_CursorIndex--;
							}
							m_CursorIndex--;
							m_imgIndex--;
						}
						else
						{
							if (m_labelList[m_CursorIndex - 1].isCategory == 0)
							{
								if (m_CursorIndex - 1 != 0)
								{
									m_CursorIndex--;
									m_imgIndex--;
								}
							}
							m_TopIndex--;
						}
					}
					else
					{
						if (m_labelList[m_TopIndex + m_CursorIndex - 1].isCategory == 0)
						{
							if (m_CursorIndex - 1 != 0)
							{
								m_CursorIndex--;
							}
						}
						m_CursorIndex--;
						m_imgIndex--;
					}
				}
			}
			else  //	도감 - 번호순에서의 텍스트 스크롤
			{
				if (m_TopIndex == 0)
				{
					if(m_Number_CursorIndex > 0)
					{
						m_Number_CursorIndex--;
					}
				}
				else
				{
					if (m_Number_CursorIndex > 0)
					{
						m_Number_CursorIndex--;
					}
					else
					{
						m_TopIndex--;
					}
				}
			}
			

		}break;
		case VK_DOWN:
		{
			SOUND_MGR.PlaySoundTrack(12);

			if (!isPopup)
			{
				if (m_CursorIndex < 8)
				{
					if (m_CursorIndex == 4)
					{
						if (m_TopIndex + 9 == m_labelList.size())
						{
							if (m_labelList[m_TopIndex + m_CursorIndex + 1].isCategory == 0)
							{
								if (m_CursorIndex + 1 != 8)
								{
									m_CursorIndex++;
								}
							}
							m_CursorIndex++;
							m_imgIndex++;
						}
						else
						{
							if (m_labelList[m_TopIndex + m_CursorIndex + 1].isCategory == 0)
							{
								if (m_CursorIndex + 1 != 8)
								{
									m_TopIndex++;
								}
							}
							m_TopIndex++;
						}
					}
					else
					{
						if (m_labelList[m_TopIndex + m_CursorIndex + 1].isCategory == 0)
						{
							if (m_CursorIndex + 1 != 8)
							{
								m_CursorIndex++;
							}
						}
						m_CursorIndex++;
						m_imgIndex++;
					}
				}
			}
			else
			{
				if (m_TopIndex + 9 == 150)
				{
					if (m_TopIndex + m_Number_CursorIndex < 150)
					{
						m_Number_CursorIndex++;
					}
				}
				else
				{
					if (m_Number_CursorIndex < 9)
					{
						m_Number_CursorIndex++;
					}
					else
					{
						m_TopIndex++;
					}
				}
			}
		}break;

		case 'z':
		case 'Z':
		{
			SOUND_MGR.PlaySoundTrack(12);
			if (!isPopup)
			{
				m_TopIndex = 0;
				m_Number_CursorIndex = 0;
				isPopup = true;
			}

		}break;
		case 'x':
		case 'X': 
		{	
			if (isPopup)
			{
				m_TopIndex = 0;
				m_CursorIndex = 1;
				isPopup = false;
			}
			else
			{
				//SCENE_MGR.SetScene(SCENE_MENU);
				SCENE_MGR.CloseScene();
			}
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;
	}

	return false;
}

void Scene_Dictionary::Render_Dictionary_List(HDC _hdc, int width, int _height)
{
	HDC _BGDC = IMG_MGR->GetImg("Dic_03")->GetImgDC();
	BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, _BGDC, 0, 0, SRCCOPY);

	Create_Arrow(_hdc, 45, 75 + (m_Number_CursorIndex * m_WordSize));

	for (int i = 0; i < 10; i++)
	{
		if (151 > i + m_TopIndex)
		{
			text.TextBox(_hdc, 70, 66 + (i * m_WordSize), m_Numbering[i + m_TopIndex].c_str(), m_WordSize, BLACK);
		}
	}
}