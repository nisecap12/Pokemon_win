#include "stdafx.h"
#include "Scene_Bag.h"
#include "SceneMgr.h"


Scene_Bag::Scene_Bag()
{
	m_BGDC = IMG_MGR->GetImg("Bag_00")->GetImgDC();
}


Scene_Bag::~Scene_Bag()
{
}

void Scene_Bag::Init(HWND _hWnd)
{
}

void Scene_Bag::Update(float _elapseTime)
{
	m_time += _elapseTime;

	if (0.2f <= m_time)
	{
		m_time -= 0.2f;
		m_Ani++;

		if (m_Ani > 5)
		{
			m_Ani = 0;
		}
	}
}

void Scene_Bag::Render(HDC _hdc)
{
	BitBlt(_hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, m_BGDC, 0, 0, SRCCOPY);
	auto	bagImg		= IMG_MGR->GetImg("Bag_01");
	auto	arrowUp		= IMG_MGR->GetImg("Arrow_Up");
	auto	arrowDown	= IMG_MGR->GetImg("Arrow_Down");
	auto	arrowLeft	= IMG_MGR->GetImg("Arrow_Left");
	auto	arrowRight	= IMG_MGR->GetImg("Arrow_Right");
	auto	itemImg		= IMG_MGR->GetImg("Item");
	auto	cursorImg	= IMG_MGR->GetImg("Select");
	auto	xMark		= IMG_MGR->GetImg("xMark");

	std::stringstream description;

	switch (m_BagNum)
	{
	case ItemType::SPECIAL:		//	중요한 물건
	{
		bagImg->AniRender(_hdc, 1, 46, 140);
		m_Txt.TextBox(_hdc, 80, 40, "중요한 물건", 35, WHITE, GRAY);

		std::stringstream	buf;
		cursorImg->Render(_hdc, 360, 42 + (m_cursorIndex * 66));

		for (int i = 0; i < MAX_ITEM_VIEW; i++)
		{
			if (i < BAG_MANAGER.GetSpecialList().size())
			{
				buf.str("");
				int index = BAG_MANAGER.GetSpecialList()[i + m_topIndex].m_itemNumber;
				buf << ITEM_MANAGER.GetItem(index).m_name;
				m_Txt.TextBox(_hdc, 392, 40 + (64 * i), buf.str().c_str(), 50);
			}
			else if (i == BAG_MANAGER.GetSpecialList().size())
			{
				buf.str("");
				buf << "닫기";
				m_Txt.TextBox(_hdc, 392, 40 + (64 * i), buf.str().c_str(), 50);
			}
		}

		if (m_specialIndex < BAG_MANAGER.GetSpecialList().size())
		{
			itemImg->AniRender(_hdc, BAG_MANAGER.GetSpecialList()[m_specialIndex].m_itemNumber, 28, 492);
			description.str("");
			description << BAG_MANAGER.GetSpecialList()[m_specialIndex].m_description;
		}
	}break;

	case ItemType::TOOL:		//	도구
	{
		bagImg->AniRender(_hdc, 0, 46, 140);
		m_Txt.TextBox(_hdc, 120, 40, "도구", 35, WHITE, GRAY);

		std::stringstream	buf;
	
		cursorImg->Render(_hdc, 360, 42 + (m_cursorIndex * 66));
		
		for (int i = 0; i < MAX_ITEM_VIEW; i++)
		{
			if (i + m_topIndex < BAG_MANAGER.GetToolList().size())
			{
				buf.str("");
				int index = BAG_MANAGER.GetToolList()[i + m_topIndex].m_itemNumber;
				buf << ITEM_MANAGER.GetItem(index).m_name;
				m_Txt.TextBox(_hdc, 392, 40 + (64 * i), buf.str().c_str(), 50);
				xMark->Render(_hdc, 772, 40 + (64 * i));
				int count = 0;
				for (int j = 1; j < 3; j++)
				{
					if (BAG_MANAGER.GetToolList()[i + m_topIndex].m_count / pow(10, j) >= 1)
					{
						count++;
					}
				}
				buf.str("");
				buf << BAG_MANAGER.GetToolList()[i + m_topIndex].m_count;
				m_Txt.TextBox(_hdc, 864 - (32 * count), 40 + (64 * i), buf.str().c_str(), 50);
			}
			else if (i + m_topIndex == BAG_MANAGER.GetToolList().size())
			{
				buf.str("");
				buf << "닫기";
				m_Txt.TextBox(_hdc, 392, 40 + (64 * i), buf.str().c_str(), 50);
			}
		}	
		if (m_toolIndex < BAG_MANAGER.GetToolList().size())
		{
			itemImg->AniRender(_hdc, BAG_MANAGER.GetToolList()[m_toolIndex].m_itemNumber, 28, 492);
			description.str("");
			description << BAG_MANAGER.GetToolList()[m_toolIndex].m_description;
		}
	}break;

	case ItemType::BALL:		//	볼
	{
		bagImg->AniRender(_hdc, 2, 46, 140);
		m_Txt.TextBox(_hdc, 140, 40, "볼", 35, WHITE, GRAY);

		std::stringstream	buf;
		cursorImg->Render(_hdc, 360, 42 + (m_cursorIndex * 66));

		for (int i = 0; i < MAX_ITEM_VIEW; i++)
		{
			if (i + m_topIndex < BAG_MANAGER.GetBallList().size())
			{
				buf.str("");
				int index = BAG_MANAGER.GetBallList()[i + m_topIndex].m_itemNumber;
				buf << ITEM_MANAGER.GetItem(index).m_name;
				m_Txt.TextBox(_hdc, 392, 40 + (64 * i), buf.str().c_str(), 50);
				xMark->Render(_hdc, 772, 40 + (64 * i));
				int count = 0;
				for (int j = 1; j < 3; j++)
				{
					if (BAG_MANAGER.GetBallList()[i + m_topIndex].m_count / pow(10, j) >= 1)
					{
						count++;
					}
				}
				buf.str("");
				buf << BAG_MANAGER.GetBallList()[i + m_topIndex].m_count;
				m_Txt.TextBox(_hdc, 864 - (32 * count), 40 + (64 * i), buf.str().c_str(), 50);
			}
			else if (i + m_topIndex == BAG_MANAGER.GetBallList().size())
			{
				buf.str("");
				buf << "닫기";
				m_Txt.TextBox(_hdc, 392, 40 + (64 * i), buf.str().c_str(), 50);
			}
		}

		if (m_ballIndex < BAG_MANAGER.GetBallList().size())
		{
			itemImg->AniRender(_hdc, BAG_MANAGER.GetBallList()[m_ballIndex].m_itemNumber, 28, 492);
			description.str("");
			description << BAG_MANAGER.GetBallList()[m_ballIndex].m_description;
		}
	}break;
	}	

	m_Txt.TextBox(_hdc, 176, 480, description.str().c_str(), 50, WHITE);

	if (isPopup)
	{
		switch (m_popupMode)
		{
		case POPUP_MODE::ASK_JOB:
		{
			m_Box.BoxCreate(_hdc, 19, 12, 29, 19, 3, true);

			std::string temp;
			m_Txt.TextBox(_hdc, 672, 416, "쓴다", 50);
			if (m_BagNum != ItemType::SPECIAL)
			{
				m_Txt.TextBox(_hdc, 672, 480, "버린다", 50);
			}
			else
			{
				m_Txt.TextBox(_hdc, 672, 480, "등록", 50);
			}
			m_Txt.TextBox(_hdc, 672, 544, "그만둔다", 50);
			
			
		}break;

		case POPUP_MODE::ASK_COUNT:
		{
			m_Box.BoxCreate(_hdc, 23, 14, 29, 19);
			std::stringstream buf;
			buf << m_discardCount;
			m_Txt.TextBox(_hdc, 826, 520, buf.str().c_str(), 40);

			arrowUp->AniRender(_hdc, m_Ani, 822, 448);
			arrowDown->AniRender(_hdc, m_Ani, 822, 592);

			//좌측 설명창
			IMG_MGR->GetImg("bagDialog")->Render(_hdc, 168, 456);
			description.str("");
			description << "아이템이름";
			m_Txt.TextBox(_hdc, 192, 492, description.str().c_str(), 40);
			description.str("");
			description << "몇개 버리시겠습니까?";
			m_Txt.TextBox(_hdc, 192, 556, description.str().c_str(), 40);
		}break;

		case POPUP_MODE::ASK_YES_NO:
		{
			m_Box.BoxCreate(_hdc, 23, 14, 29, 19, 2, true);

			std::stringstream buf;
			buf << "예";
			m_Txt.TextBox(_hdc, 800, 480, buf.str().c_str(), 40);
			buf.str("");
			buf << "아니오";
			m_Txt.TextBox(_hdc, 800, 544, buf.str().c_str(), 40);

			//좌측 설명창
			IMG_MGR->GetImg("bagDialog")->Render(_hdc, 168, 456);
			description.str("");
			description << "정말 아이템이름 을";
			m_Txt.TextBox(_hdc, 192, 492, description.str().c_str(), 40);
			description.str("");
			description << m_discardCount << "개 버리시겠습니까?";
			m_Txt.TextBox(_hdc, 192, 556, description.str().c_str(), 40);
		}break;
		}
	}
	else
	{
		if (m_BagNum != ItemType::SPECIAL)
			arrowLeft->AniRender(_hdc, m_Ani, 0, 260);
		if (m_BagNum != ItemType::BALL)
			arrowRight->AniRender(_hdc, m_Ani, 270, 260);

		if (m_topIndex > 0)
		{
			arrowUp->AniRender(_hdc, m_Ani, 610, 0);
		}
		switch (m_BagNum)
		{
			case ItemType::SPECIAL:
			{
				if (m_topIndex < BAG_MANAGER.GetSpecialList().size() - 5)
				{
					arrowDown->AniRender(_hdc, m_Ani, 610, 400);
				}
			}break;
			case ItemType::TOOL:
			{
				if (m_topIndex < BAG_MANAGER.GetToolList().size() - 5)
				{
					arrowDown->AniRender(_hdc, m_Ani, 610, 400);
				}
			}break;
			case ItemType::BALL:
			{
				if (m_topIndex < BAG_MANAGER.GetBallList().size() - 5)
				{
					arrowDown->AniRender(_hdc, m_Ani, 610, 400);
				}
			}break;
		}
		
	}
}

bool Scene_Bag::WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	switch (_message)
	{
	case WM_KEYDOWN:
	{
		switch (_wParam)
		{
		case VK_LEFT:
		{
			m_BagNum--;
			if (m_BagNum < ItemType::SPECIAL)
				m_BagNum = ItemType::SPECIAL;
			switch (m_BagNum)
			{
			case ItemType::SPECIAL:
			{				
				m_specialIndex = 0;
			}break;
			case ItemType::TOOL:
			{
				m_toolIndex = 0;
			}break;
			case ItemType::BALL:
			{
				m_ballIndex = 0;
			}break;
			}
			m_cursorIndex = 0;
			m_topIndex = 0;
		}break;

		case VK_RIGHT:
		{
			m_BagNum++;
			if (m_BagNum > ItemType::BALL)
				m_BagNum = ItemType::BALL;
			switch (m_BagNum)
			{
			case ItemType::SPECIAL:
			{
				m_specialIndex = 0;
			}break;
			case ItemType::TOOL:
			{
				m_toolIndex = 0;
			}break;
			case ItemType::BALL:
			{
				m_ballIndex = 0;
			}break;
			}
			m_cursorIndex = 0;
			m_topIndex = 0;
		}break;
		case VK_UP:
		{
			if (isPopup)
			{
				if (m_popupMode == POPUP_MODE::ASK_COUNT)
				{
					m_discardCount++;
					if (m_discardCount == m_maxDiscardCount)
					{
						m_discardCount = 1;
					}
				}
			}
			else
			{
				switch (m_BagNum)
				{
				case ItemType::SPECIAL:
				{
					if (m_cursorIndex > 0)
					{
						if (m_specialIndex > 0)
						{
							m_cursorIndex--;
							m_specialIndex--;
						}
					}
					else if (m_cursorIndex == 0)
					{
						if (m_topIndex > 0)
						{
							m_topIndex--;
							m_toolIndex--;
						}
					}
				}break;
				case ItemType::TOOL:
				{
					if (m_cursorIndex > 0)
					{
						if (m_toolIndex > 0)
						{
							m_cursorIndex--;
							m_toolIndex--;
						}
					}
					else if (m_cursorIndex == 0)
					{
						if (m_topIndex > 0)
						{
							m_topIndex--;
							m_toolIndex--;
						}
					}
				}break;
				case ItemType::BALL:
				{
					if (m_cursorIndex > 0)
					{
						if (m_ballIndex > 0)
						{
							m_cursorIndex--;
							m_ballIndex--;
						}
					}
					else if (m_cursorIndex == 0)
					{
						if (m_topIndex > 0)
						{
							m_topIndex--;
							m_toolIndex--;
						}
					}
				}break;
				}
			}
		}break;
		case VK_DOWN:
		{
			if (isPopup)
			{
				if (m_popupMode == POPUP_MODE::ASK_COUNT)
				{
					m_discardCount--;
					if (m_discardCount == 0)
					{
						m_discardCount = m_maxDiscardCount;
					}
				}
			}
			else
			{
				switch (m_BagNum)
				{
				case ItemType::SPECIAL:
				{
					if (m_cursorIndex < BAG_MANAGER.GetSpecialList().size() &&
						m_cursorIndex < 5)
					{
						if (m_specialIndex < BAG_MANAGER.GetSpecialList().size())
						{
							m_cursorIndex++;
							m_specialIndex++;
						}
					}
					else if (m_cursorIndex == 5)
					{
						if (m_topIndex < BAG_MANAGER.GetSpecialList().size() - 5)
						{
							m_topIndex++;
							m_toolIndex++;
						}
					}
				}break;
				case ItemType::TOOL:
				{
					if (m_cursorIndex < BAG_MANAGER.GetToolList().size() &&
						m_cursorIndex < 5)
					{
						if (m_toolIndex < BAG_MANAGER.GetToolList().size())
						{
							m_cursorIndex++;
							m_toolIndex++;
						}
					}
					else if (m_cursorIndex == 5)
					{
						if (m_topIndex < BAG_MANAGER.GetToolList().size() - 5)
						{
							m_topIndex++;
							m_toolIndex++;
						}
					}
				}break;
				case ItemType::BALL:
				{
					if (m_cursorIndex < BAG_MANAGER.GetBallList().size() &&
						m_cursorIndex < 5)
					{
						if (m_ballIndex < BAG_MANAGER.GetBallList().size())
						{
							m_cursorIndex++;
							m_ballIndex++;
						}
					}
					else if (m_cursorIndex == 5)
					{
						if (m_topIndex < BAG_MANAGER.GetBallList().size() - 5)
						{
							m_topIndex++;
							m_toolIndex++;
						}
					}
				}break;
				}
			}
		}break;
		case 'Z':
		{
			SOUND_MGR.PlaySoundTrack(12);
			int closeIndex;
			switch (m_BagNum)
			{
			case ItemType::SPECIAL:
			{
				closeIndex = BAG_MANAGER.GetSpecialList().size();
			}break;
			case ItemType::TOOL:
			{
				closeIndex = BAG_MANAGER.GetToolList().size();
			}break;
			case ItemType::BALL:
			{
				closeIndex = BAG_MANAGER.GetBallList().size();
			}break;
			}

			if (m_cursorIndex + m_topIndex == closeIndex) //닫기
			{
				//SCENE_MGR.SetScene(SCENE_MENU);
				SCENE_MGR.CloseScene();
			}
			else
			{
				if (isPopup)
				{
					switch (m_popupMode)
					{
					case POPUP_MODE::ASK_JOB:
					{
						switch (m_Box.m_Select)
						{
						case 0: // 쓴다
						{
							SCENE_MGR.SetMsg((void*)true);
							SCENE_MGR.CloseScene();
						}break;

						case 1: // 버린다
						{
							switch (m_BagNum)
							{
							case ItemType::TOOL:
							{
								if (BAG_MANAGER.GetToolList()[m_toolIndex].m_count > 1)
								{
									m_maxDiscardCount = BAG_MANAGER.GetToolList()[m_toolIndex].m_count;
									m_popupMode = ASK_COUNT;
								}
								else
								{
									m_popupMode = ASK_YES_NO;
								}
							}break;
							case ItemType::BALL:
							{
								if (BAG_MANAGER.GetBallList()[m_ballIndex].m_count > 1)
								{
									m_maxDiscardCount = BAG_MANAGER.GetToolList()[m_ballIndex].m_count;
									m_popupMode = ASK_COUNT;
								}
								else
								{
									m_popupMode = ASK_YES_NO;
								}
							}break;
							}

							m_discardCount = 1;
						}break;
						case 2: //그만둔다
						{
							m_popupMode = ASK_JOB;
							isPopup = false;
						}break;
						}
					}break;

					case POPUP_MODE::ASK_COUNT:
					{
						m_popupMode = POPUP_MODE::ASK_YES_NO;
					}break;

					case POPUP_MODE::ASK_YES_NO:
					{
						if (m_Box.m_Select == 0) // yes
						{
							int index;
							if (m_BagNum == ItemType::TOOL)
							{
								index = m_toolIndex;
							}
							else
							{
								index = m_ballIndex;
							}
							BAG_MANAGER.DiscardItem(m_BagNum, index, m_discardCount);
							
						}
						m_popupMode = ASK_JOB;
						isPopup = false;
					}break;
					}
				}
				else
				{
					isPopup = true;
				}
			}
		}break;
		case 'x':
		case 'X': {
			if (SCENE_MGR.IsOnBattle())
			{
				SCENE_MGR.CloseScene();
			}
			else
			{
				if (isPopup)
				{
					m_popupMode = ASK_JOB;
					isPopup = false;
				}
				else
				{
					SCENE_MGR.CloseScene();
					//SCENE_MGR.SetScene(SCENE_MENU);
				}
			}
		}break;

		case VK_ESCAPE: return true;	break;
		}
	}break;

	}
	return false;
}