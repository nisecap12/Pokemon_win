#pragma once

#include <map>
#include <string>
#include <list>

enum	TYPESOUND
{
	TYPE_BGSOUND = 0,
	TYPE_EFFECTSOUND,
	TYPE_END
};

typedef	unsigned int		SOUND_INDEX;

#define	SOUND_MGR			SoundManager::GetInstance()

//============= FMOD 관련 =============================
#include "fmod/fmod.hpp"

#ifndef _WIN64
#pragma	comment (lib, "fmod/fmodex_vc.lib")
#else
#pragma	comment (lib, "fmod/fmodex64_vc.lib")
#endif
//=====================================================

#include "TemplateSingletonA.h"

class	SoundManager
	: public TemplateSingletonA<SoundManager>
{
	friend	TemplateSingletonA;
private:
	SoundManager();
	~SoundManager();
private:
	//	FMOD 변수 재정의
	typedef	FMOD::Sound*		FMOD_ST;
	typedef	FMOD::Channel*		FMOD_CH;
	typedef	FMOD::System*		FMOD_SYS;

	//	사운드 구조체
	struct SoundTrackInfo
	{
		FMOD_ST		m_Sound;
		TYPESOUND	m_PlayType;
	};

	//	사운드와 채널을 담기위한 자료구조 자료형 정의
	typedef		std::map<SOUND_INDEX, SoundTrackInfo>		SOUNDLIST;
	typedef		std::map<std::string, SOUND_INDEX>			OVERLAPCHECKLIST;
	typedef		std::list<FMOD_CH>							PLAYLIST;

private:
	FMOD_SYS			m_System;			//	FMOD 스시템
	SOUNDLIST			m_SoundList;		//	사운드 리스트
	OVERLAPCHECKLIST	m_CheckList;		//	사운드 중복체크 리스트
	PLAYLIST			m_BGPlayList;		//	배경음 채널 리스트
	PLAYLIST			m_EffectPlayList;	//	효과음 채널 리스트
	float				m_BGVolume;			//	배경음 볼륨( 0~1 )
	float				m_EffectVolume;		//	효과음 볼륨( 0~1 )

private:
	//	초기화
	void			InitSound();
	//	사운드 전부 제거
	void			DeleteAll(void);
	//	인덱스를 통한 사운드 찾기
	SoundTrackInfo*	FindSound(SOUND_INDEX _Index);

	//	해당 채널 상태 업데이트
	void			ChannelUpdate(PLAYLIST &_List);
	//	재생중인 배경음 업데이트
	void			BGPlayListUpdate(void);
	//	재생중인 효과음 업데이트
	void			EffectPlayListUpdate(void);

	//	해당 리스트 채널 청소
	void			ChannelClear(PLAYLIST &_List);
	//	재생중인 배경음 청소
	void			BGPlayListClear();
	//	재생중인 효과음 청소
	void			EffectPlayListClear();

	//	해당 재생 채널리스트의 볼륨 조정
	float			SetVolume(float _Volume, PLAYLIST &_List);

public:
	//	업데이트( 일정기간에 한번씩 해야 반복재생 유지 )
	void			Update();
	//	해당 사운드 재생
	bool			PlaySoundTrack(SOUND_INDEX _Index);
	//	사운드 생성
	SOUND_INDEX		CreateSound(const char *_FilePath, TYPESOUND _Type);
	void			StopSoundTrack();

	//	볼륨 제어( 0 ~ 1 )
	float			SetBGVolume( float	_Volume );
	float			SetEffectVolume(float	_Volume );
};	