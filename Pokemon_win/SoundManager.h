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

//============= FMOD ���� =============================
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
	//	FMOD ���� ������
	typedef	FMOD::Sound*		FMOD_ST;
	typedef	FMOD::Channel*		FMOD_CH;
	typedef	FMOD::System*		FMOD_SYS;

	//	���� ����ü
	struct SoundTrackInfo
	{
		FMOD_ST		m_Sound;
		TYPESOUND	m_PlayType;
	};

	//	����� ä���� ������� �ڷᱸ�� �ڷ��� ����
	typedef		std::map<SOUND_INDEX, SoundTrackInfo>		SOUNDLIST;
	typedef		std::map<std::string, SOUND_INDEX>			OVERLAPCHECKLIST;
	typedef		std::list<FMOD_CH>							PLAYLIST;

private:
	FMOD_SYS			m_System;			//	FMOD ������
	SOUNDLIST			m_SoundList;		//	���� ����Ʈ
	OVERLAPCHECKLIST	m_CheckList;		//	���� �ߺ�üũ ����Ʈ
	PLAYLIST			m_BGPlayList;		//	����� ä�� ����Ʈ
	PLAYLIST			m_EffectPlayList;	//	ȿ���� ä�� ����Ʈ
	float				m_BGVolume;			//	����� ����( 0~1 )
	float				m_EffectVolume;		//	ȿ���� ����( 0~1 )

private:
	//	�ʱ�ȭ
	void			InitSound();
	//	���� ���� ����
	void			DeleteAll(void);
	//	�ε����� ���� ���� ã��
	SoundTrackInfo*	FindSound(SOUND_INDEX _Index);

	//	�ش� ä�� ���� ������Ʈ
	void			ChannelUpdate(PLAYLIST &_List);
	//	������� ����� ������Ʈ
	void			BGPlayListUpdate(void);
	//	������� ȿ���� ������Ʈ
	void			EffectPlayListUpdate(void);

	//	�ش� ����Ʈ ä�� û��
	void			ChannelClear(PLAYLIST &_List);
	//	������� ����� û��
	void			BGPlayListClear();
	//	������� ȿ���� û��
	void			EffectPlayListClear();

	//	�ش� ��� ä�θ���Ʈ�� ���� ����
	float			SetVolume(float _Volume, PLAYLIST &_List);

public:
	//	������Ʈ( �����Ⱓ�� �ѹ��� �ؾ� �ݺ���� ���� )
	void			Update();
	//	�ش� ���� ���
	bool			PlaySoundTrack(SOUND_INDEX _Index);
	//	���� ����
	SOUND_INDEX		CreateSound(const char *_FilePath, TYPESOUND _Type);
	void			StopSoundTrack();

	//	���� ����( 0 ~ 1 )
	float			SetBGVolume( float	_Volume );
	float			SetEffectVolume(float	_Volume );
};	