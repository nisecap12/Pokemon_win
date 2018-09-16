#include "stdafx.h"

SoundManager::SoundManager()
{
	InitSound();
}

SoundManager::~SoundManager()
{
	DeleteAll();
	m_System->release();
	m_System->close();
}

//	�ʱ�ȭ
void	SoundManager::InitSound()
{
	//	���� �ý��� ���
	FMOD::System_Create(&m_System);

	m_System->init( 
		CHAR_MAX,			//	���� ����� ���� ����
		FMOD_INIT_NORMAL,	//	�ý��� �⺻ �ɼ�
		nullptr );			//	�߰� ����̹� ����( ���� nullptr )

	//	���� ����
	m_BGVolume		=	1.0f;
	m_EffectVolume	=	1.0f;

	CreateSound("Sound/03 Opening.mp3", TYPE_BGSOUND);							//1
	CreateSound("Sound/07 Welcome To The World Of Pokemon.mp3", TYPE_BGSOUND);	//2
	CreateSound("Sound/18 Pewter City Theme.mp3", TYPE_BGSOUND);				//3
	CreateSound("Sound/21 Battle (VS Wild Pokemon).mp3", TYPE_BGSOUND);			//4
	CreateSound("Sound/49 Pokemon Print.mp3", TYPE_EFFECTSOUND);				//5
	CreateSound("Sound/29 Guidance.mp3", TYPE_BGSOUND);							//6
	CreateSound("Sound/39 Mt Moon.mp3", TYPE_BGSOUND);							//7
	CreateSound("Sound/31 Tense Competition.mp3", TYPE_BGSOUND);				//8
	CreateSound("Sound/Encounter.mp3", TYPE_EFFECTSOUND);						//9
	CreateSound("Sound/Data Saved.mp3", TYPE_EFFECTSOUND);						//10
	CreateSound("Sound/Pokemon Catched.mp3", TYPE_EFFECTSOUND);					//11
	CreateSound("Sound/Button click.mp3", TYPE_EFFECTSOUND);					//12
	CreateSound("Sound/Pokemon Dying.mp3", TYPE_EFFECTSOUND);					//13
	CreateSound("Sound/Enter map.mp3", TYPE_EFFECTSOUND);						//14
	CreateSound("Sound/Runaway.mp3", TYPE_EFFECTSOUND);							//15
	CreateSound("Sound/Ball Bounce.mp3", TYPE_EFFECTSOUND);						//16
	CreateSound("Sound/Normal Attack.mp3", TYPE_EFFECTSOUND);					//17
	CreateSound("Sound/Fire Attack.mp3", TYPE_EFFECTSOUND);						//18
}

//	���� ���� ����
void	SoundManager::DeleteAll(void)
{
	//	������� ä�� ����
	BGPlayListClear();
	EffectPlayListClear();

	//	���� ����Ʈ�� �ִ� ��� ���� ���� ����
	auto Iter = m_SoundList.begin();

	while( m_SoundList.empty() == false )
	{
		SoundTrackInfo	&Info = Iter->second;
		
		Info.m_Sound->release();

		Iter = m_SoundList.erase(Iter);
	}

	//	���� ����Ʈ�� �ߺ� üũ ����Ʈ ����
	m_SoundList.clear();	
	m_CheckList.clear();
}

//	������Ʈ( �����Ⱓ�� �ѹ��� �ؾ� �ݺ���� ���� )
void	SoundManager::Update()
{
	//	�ݺ���� ������ ���� ������Ʈ
	m_System->update();

	//	���� ������� ä�� Ȯ��
	BGPlayListUpdate();
	EffectPlayListUpdate();
}

//	���� ����
SOUND_INDEX	SoundManager::CreateSound(const char *_FilePath, TYPESOUND _Type)
{
	//	�ε��� ��ȣ�� ��ġ�� �ʱ� ���ؼ� ����ϴ� ����
	static	SOUND_INDEX	Index = 1;

	//	�ߺ� ����Ʈ�� ���� Ȯ��
	auto	Find = m_CheckList.find(_FilePath);

	//	�̹� �ִ� ��� �ش� ���� �ε��� ��ȯ
	if (Find != m_CheckList.end())
	{
		return Find->second;
	}

	//	Ÿ�Կ� ���� �÷��� ����
	int	Flag = FMOD_DEFAULT;

	if (_Type == TYPE_EFFECTSOUND)
	{
		Flag |= FMOD_LOOP_OFF;
	}
	else
	{
		Flag |= FMOD_LOOP_NORMAL;
	}

	//	���� ����
	SoundTrackInfo	Data;

	m_System->createSound(_FilePath, Flag, nullptr, &Data.m_Sound );

	Data.m_PlayType = _Type;

	//	���� ����Ʈ�� ����
	m_SoundList.insert( std::make_pair( Index, Data) );
	//	�ߺ� ����Ʈ�� ����
	m_CheckList.insert(std::make_pair(_FilePath, Index));

	//	�ش� �ε��� ��ȯ
	return Index++;
}

void SoundManager::StopSoundTrack()
{
	m_BGPlayList.back()->stop();
	m_BGPlayList.clear();
}

//	�ش� ���� ���
bool	SoundManager::PlaySoundTrack(SOUND_INDEX _Index)
{
	//	�ش� �ε��� �˻�
	SoundTrackInfo		*Info = FindSound(_Index);

	if ( Info == nullptr)
	{
		return false;
	}

	//	�ش� ä�η� ���� ���  �Ͻ����� ���·�
	FMOD_CH	Channel = nullptr;
	m_System->playSound(FMOD_CHANNEL_REUSE, Info->m_Sound, true, &Channel);

	//	���� ����
	if( Info->m_PlayType == TYPE_BGSOUND )
	{
		if (m_BGPlayList.size() > 0)
		{
			m_BGPlayList.back()->stop();
			m_BGPlayList.clear();
		}
		
		Channel->setVolume( m_BGVolume );
		m_BGPlayList.push_back(Channel);
	}
	else
	{
		Channel->setVolume( m_EffectVolume );
		m_EffectPlayList.push_back(Channel);
	}

	//	���� ���
	Channel->setPaused(false);
	
	return true;
}

//	�ε����� ���� ���� ã��
SoundManager::SoundTrackInfo*		SoundManager::FindSound(SOUND_INDEX _Index)
{
	auto Find = m_SoundList.find(_Index);

	if( Find == m_SoundList.end() )
	{
		return nullptr;
	}

	return &(Find->second);
}

//	�ش� ä�� ���� ������Ʈ
void		SoundManager::ChannelUpdate(PLAYLIST &_List)
{
	auto		iter		= _List.begin();
	bool		IsPlaying	=	false;

	while( iter != _List.end() )
	{
		FMOD_CH	&Chanel	=	*iter;

		Chanel->isPlaying( &IsPlaying);

		if( IsPlaying == false )
		{
			iter	= _List.erase( iter );
		}

		else
		{
			iter++;
		}
	}
}

//	������� ����� ������Ʈ
void SoundManager::BGPlayListUpdate(void)
{
	ChannelUpdate(m_BGPlayList);
}

//	������� ȿ���� ������Ʈ
void SoundManager::EffectPlayListUpdate(void)
{
	ChannelUpdate(m_EffectPlayList);
}

//	�ش� ����Ʈ ä�� û��
void SoundManager::ChannelClear(PLAYLIST &_List)
{
	auto		iter		= _List.begin();
	bool		IsPlaying	=	false;

	while( _List.empty() == false )
	{
		FMOD_CH	&Channel = *iter;

		Channel->isPlaying( &IsPlaying);

		if(IsPlaying ==	true )
		{
			Channel->stop();
		}

		iter	= _List.erase( iter );
	}
}

//	������� ����� û��
void		SoundManager::BGPlayListClear()
{
	ChannelClear(m_BGPlayList);
}
//	������� ȿ���� û��
void		SoundManager::EffectPlayListClear()
{
	ChannelClear(m_EffectPlayList);
}

//	�ش� ��� ä�θ���Ʈ�� ���� ����
float SoundManager::SetVolume(float _Volume, PLAYLIST &_List)
{
	if (_Volume > 1.0f)
	{
		_Volume = 1.0f;
	}
	else if (_Volume < 0)
	{
		_Volume = 0;
	}

	for (auto &i : _List)
	{
		i->setVolume(_Volume);
	}

	return _Volume;
}

float	SoundManager::SetBGVolume(float _Volume)
{
	return m_BGVolume = SetVolume(_Volume, m_BGPlayList);
}

float	SoundManager::SetEffectVolume(float _Volume)
{
	return m_EffectVolume = SetVolume(_Volume, m_EffectPlayList);
}