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

//	초기화
void	SoundManager::InitSound()
{
	//	사운드 시스템 얻기
	FMOD::System_Create(&m_System);

	m_System->init( 
		CHAR_MAX,			//	동시 재생될 사운드 개수
		FMOD_INIT_NORMAL,	//	시스템 기본 옵션
		nullptr );			//	추가 드라이버 관련( 보통 nullptr )

	//	볼륨 설정
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

//	사운드 전부 제거
void	SoundManager::DeleteAll(void)
{
	//	재생중인 채널 정리
	BGPlayListClear();
	EffectPlayListClear();

	//	사운드 리스트에 있는 목록 전부 사운드 해제
	auto Iter = m_SoundList.begin();

	while( m_SoundList.empty() == false )
	{
		SoundTrackInfo	&Info = Iter->second;
		
		Info.m_Sound->release();

		Iter = m_SoundList.erase(Iter);
	}

	//	사운드 리스트와 중복 체크 리스트 정리
	m_SoundList.clear();	
	m_CheckList.clear();
}

//	업데이트( 일정기간에 한번씩 해야 반복재생 유지 )
void	SoundManager::Update()
{
	//	반복재생 유지를 위한 업데이트
	m_System->update();

	//	현재 재생중인 채널 확인
	BGPlayListUpdate();
	EffectPlayListUpdate();
}

//	사운드 생성
SOUND_INDEX	SoundManager::CreateSound(const char *_FilePath, TYPESOUND _Type)
{
	//	인덱스 번호가 겹치지 않기 위해서 사용하는 변수
	static	SOUND_INDEX	Index = 1;

	//	중복 리스트로 파일 확인
	auto	Find = m_CheckList.find(_FilePath);

	//	이미 있는 경우 해당 사운드 인덱스 반환
	if (Find != m_CheckList.end())
	{
		return Find->second;
	}

	//	타입에 따른 플래그 설정
	int	Flag = FMOD_DEFAULT;

	if (_Type == TYPE_EFFECTSOUND)
	{
		Flag |= FMOD_LOOP_OFF;
	}
	else
	{
		Flag |= FMOD_LOOP_NORMAL;
	}

	//	사운드 생성
	SoundTrackInfo	Data;

	m_System->createSound(_FilePath, Flag, nullptr, &Data.m_Sound );

	Data.m_PlayType = _Type;

	//	사운드 리스트에 삽입
	m_SoundList.insert( std::make_pair( Index, Data) );
	//	중복 리스트에 삽입
	m_CheckList.insert(std::make_pair(_FilePath, Index));

	//	해당 인덱스 반환
	return Index++;
}

void SoundManager::StopSoundTrack()
{
	m_BGPlayList.back()->stop();
	m_BGPlayList.clear();
}

//	해당 사운드 재생
bool	SoundManager::PlaySoundTrack(SOUND_INDEX _Index)
{
	//	해당 인덱스 검색
	SoundTrackInfo		*Info = FindSound(_Index);

	if ( Info == nullptr)
	{
		return false;
	}

	//	해당 채널로 사운드 재생  일시정지 상태로
	FMOD_CH	Channel = nullptr;
	m_System->playSound(FMOD_CHANNEL_REUSE, Info->m_Sound, true, &Channel);

	//	볼륨 조절
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

	//	사운드 재생
	Channel->setPaused(false);
	
	return true;
}

//	인덱스를 통한 사운드 찾기
SoundManager::SoundTrackInfo*		SoundManager::FindSound(SOUND_INDEX _Index)
{
	auto Find = m_SoundList.find(_Index);

	if( Find == m_SoundList.end() )
	{
		return nullptr;
	}

	return &(Find->second);
}

//	해당 채널 상태 업데이트
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

//	재생중인 배경음 업데이트
void SoundManager::BGPlayListUpdate(void)
{
	ChannelUpdate(m_BGPlayList);
}

//	재생중인 효과음 업데이트
void SoundManager::EffectPlayListUpdate(void)
{
	ChannelUpdate(m_EffectPlayList);
}

//	해당 리스트 채널 청소
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

//	재생중인 배경음 청소
void		SoundManager::BGPlayListClear()
{
	ChannelClear(m_BGPlayList);
}
//	재생중인 효과음 청소
void		SoundManager::EffectPlayListClear()
{
	ChannelClear(m_EffectPlayList);
}

//	해당 재생 채널리스트의 볼륨 조정
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