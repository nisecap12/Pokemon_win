#include "stdafx.h"
#include "PokemonManager.h"

PokemonManager::PokemonManager()
{
}


PokemonManager::~PokemonManager()
{
}

void PokemonManager::SaveMyPokemon()
{
	std::ofstream fout("DB/MyPokemon.db", std::ios::binary);
	if (fout.fail() == false)
	{
		fout << m_pokemonCount;
		fout.write((const char*)m_myPokemonList, sizeof(Pokemon) * 6);
	}
}

void PokemonManager::LoadMyPokemon()
{
	Pokemon* table = new Pokemon[6];
	std::ifstream fout;

	fout.open("DB/MyPokemon.db", std::ios::binary);

	if (m_myPokemonList[0].m_level == 0)
	{
		if (fout.fail() == false)
		{
			fout >> m_pokemonCount;
			fout.read((char*)table, sizeof(Pokemon) * 6);
			fout.close();

			for (int i = 0; i < m_pokemonCount; i++)
			{
				m_myPokemonList[i] = table[i];
				strcpy_s(m_myPokemonList[i].m_nickname,20, m_myPokemonList[i].m_data.m_name);
			}
		}
		else
		{
			RootMyPokemon();
		}
	}
}

void PokemonManager::SaveNPCPokemon()
{
	EnemyPokemonTable* table = new EnemyPokemonTable[TRAINER_TOTAL_NUMBER];

	short i = 0;

	/*
	NPC 번호 : NPC.db에 작성된 번호랑 일치해야함
	포켓몬 정보 : 
		- 포켓몬1 번호
		- 포켓몬2 번호
		- 포켓몬3 번호
		- 포켓몬4 번호
		- 포켓몬5 번호
		- 포켓몬6 번호
	*/
	table[i++] = { 1,{ {11, } , {15, }, {16, }, {149, }, {127, }, {-1, } } };
	table[i++] = { 4,{ {118, }, {43, }, {106, }, {25, }, {26, }, {32, } } };

	std::ofstream fout("DB/NPC_Pokemon.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.write((const char*)table, sizeof(EnemyPokemonTable) * TRAINER_TOTAL_NUMBER);
	}

	delete[] table;
}

void PokemonManager::LoadNPCPokemon()
{
	EnemyPokemonTable* table = new EnemyPokemonTable[TRAINER_TOTAL_NUMBER];
	std::ifstream fout;

	fout.open("DB/NPC_Pokemon.db", std::ios::binary);

	if (fout.fail() == false)
	{
		fout.read((char*)table, sizeof(EnemyPokemonTable) * TRAINER_TOTAL_NUMBER);
		fout.close();

		for (int i = 0; i < TRAINER_TOTAL_NUMBER; i++)
		{
			EnemyPokemonTable temp;
			temp.npcNumber = table[i].npcNumber;
			temp.PokemonList[0] = table[i].PokemonList[0];
			temp.PokemonList[1] = table[i].PokemonList[1];
			temp.PokemonList[2] = table[i].PokemonList[2];
			temp.PokemonList[3] = table[i].PokemonList[3];
			temp.PokemonList[4] = table[i].PokemonList[4];
			temp.PokemonList[5] = table[i].PokemonList[5];
			m_enemyTable.push_back(temp);
		}
	}
}

void PokemonManager::SavePokemonTable()
{
	PokemonTable* table = new PokemonTable[POKEMON_TOTAL_NUMBER];
	std::ofstream fout("DB/SkillTable.db");

	short i = 0;

	/*
	포켓몬 번호
	기술 1 번호
	기술 2 번호
	기술 3 번호
	기술 4 번호
	기술 없으면 -1
	*/

	table[i++] = { i, 32, 72, -1, -1 }; //이상해씨 - 몸통박치기, 씨뿌리기
	table[i++] = { i, 74, 72, 21, -1 }; //이상해풀 - 잎날가르기, 씨뿌리기, 덩굴채찍
	table[i++] = { i, 74, 72, 21, 75 }; //이상해꽃 - 몸통박치기, 씨뿌리기, 솔라빔
	table[i++] = { i, 44, 9, -1, -1 }; //파이리 - 울음소리, 할퀴기
	table[i++] = { i, 44, 9, 51, -1 }; //리자드 - 울음소리, 할퀴기, 불꽃세례
	table[i++] = { i, 44, 9, 51, 42 }; //리자몽 - 울음소리, 할퀴기, 불꽃세례, 째려보기
	table[i++] = { i, 32, 38, -1, -1 }; //꼬부기 - 몸통박치기, 꼬리흔들기
	table[i++] = { i, 32, 38, 144, -1 }; //어니부기 - 몸통박치기, 꼬리흔들기, 거품
	table[i++] = { i, 32, 38, 144, 54 }; //거북왕 - 몸통박치기, 꼬리흔들기, 거품, 물대포
	table[i++] = { i, 32, 80, -1, -1 }; //캐터피 - 몸통박치기, 실뿜기
	table[i++] = { i, 105, -1, -1, -1 }; //단데기 - 단단해지기
	table[i++] = { i, 92, 76, 77, 78 }; //버터플 - 염동력, 독가루, 저리가루, 수면가루
	table[i++] = { i, 39, 80, -1, -1 }; //뿔충이 - 독침, 실뿜기
	table[i++] = { i, 105, -1, -1, -1 }; //딱충이 - 단단해지기
	table[i++] = { i, 30, 115, 98, -1 }; //독침붕 - 마구찌르기, 기충전, 분노
	table[i++] = { i, 15, 27, -1, -1 }; //구구 - 바람일으키기, 모래뿌리기
	table[i++] = { i, 15, 27, 32, -1 }; //피죤 - 바람일으키기, 모래뿌리기, 몸통박치기
	table[i++] = { i, 15, 27, 32, 97 }; //피죤투 - 바람일으키기, 모래뿌리기, 몸통박치기, 전광석화
	table[i++] = { i, 32, 38, -1, -1 }; //꼬렛 - 몸통박치기, 꼬리흔들기
	table[i++] = { i, 32, 38, 97, -1 }; //레트라 - 몸통박치기, 꼬리흔들기, 전광석화
	table[i++] = { i, 63, 44, -1, -1 }; //깨비참 - 쪼기, 울음소리
	table[i++] = { i, 63, 44, 42, -1 }; //깨비드릴조 - 쪼기, 울음소리, 째려보기
	table[i++] = { i, 34, 42, -1, -1 }; //아보 - 김밥말이, 째려보기
	table[i++] = { i, 34, 42, 39, -1 }; //아보크 - 김밥말이, 째려보기, 독침
	table[i++] = { i, 83, 44, -1, -1 }; //피카츄 - 전기쇼크, 울음소리
	table[i++] = { i, 83, 85, -1, -1 }; //라이츄 - 전기쇼크, 울음소리, 전기자석파
	table[i++] = { i, 9, 27, -1, -1 }; //모래두지 - 할퀴기, 모래뿌리기
	table[i++] = { i, 9, 27, 162, -1 }; //고지 - 할퀴기, 모래뿌리기, 베어가르기
	table[i++] = { i, 44, 32, -1, -1 }; //니드런♀ - 울음소리, 몸통박치기
	table[i++] = { i, 44, 32, 9, -1 }; //니드리나 - 울음소리, 몸통박치기, 할퀴기
	table[i++] = { i, 32, 9, 33, 54 }; //니드퀸 - 몸통박치기, 할퀴기, 누르기, 거품
	table[i++] = { i, 42, 32, -1, -1 }; //니드런♂ - 째려보기, 몸통박치기
	table[i++] = { i, 42, 32, 29, -1 }; //니드리노 - 째려보기, 몸통박치기, 뿔찌르기
	table[i++] = { i, 39, 42, 29, 23 }; //니드킹 - 독침, 몸통박치기, 뿔찌르기, 두번치기
	table[i++] = { i, 0, 44, -1, -1 }; //삐삐 - 막치기, 울음소리
	table[i++] = { i, 106, 2, 46, 117 }; //픽시 - 작아지기, 연속뺨치기, 노래하기, 손가락흔들기
	table[i++] = { i, 51, 38, -1, -1 }; //식스테일 - 불꽃세례, 꼬리흔들기
	table[i++] = { i, 51, 38, 97, 45 }; //나인테일 - 불꽃세례, 꼬리흔들기, 전광석화, 울부짖기
	table[i++] = { i, 46, -1, -1, -1 }; //푸린 - 노래하기
	table[i++] = { i, 46, 49, 110, 2 }; //푸크린 - 노래하기, 사슬묶기, 웅크리기, 연속뺨치기
	table[i++] = { i, 140, -1, -1, -1 }; //주뱃 - 흡혈
	table[i++] = { i, 102, 140, 47, -1 }; //골뱃 - 싫은소리, 흡혈, 초음파
	table[i++] = { i, 70, -1, -1, -1 }; //뚜벅초 - 흡수
	table[i++] = { i, 70, 76, 77, 78 }; //냄새꼬 - 흡수, 독가루, 저리가루, 수면가루
	table[i++] = { i, 76, 77, 78, -1 }; //라플레시아 - 독가루, 저리가루, 수면가루
	table[i++] = { i, 9, -1, -1, -1 }; //파라스 - 할퀴기
	table[i++] = { i, 9, 77, 140, -1 }; //파라섹트 - 할퀴기, 저리가루, 흡혈
	table[i++] = { i, 32, 49, -1, -1 }; //콘팡 - 몸통박치기, 사슬묶기
	table[i++] = { i, 32, 49, 140, 76 }; //도나리 - 몸통박치기, 사슬묶기, 흡혈, 독가루
	table[i++] = { i, 9, -1, -1, -1 }; //디그다 - 할퀴기
	table[i++] = { i, 9, 44, 90, 27 }; //닥트리오 - 할퀴기, 울음소리, 구멍파기, 모래뿌리기
	table[i++] = { i, 9, 44, -1, -1 }; //나옹 - 할퀴기, 울음소리
	table[i++] = { i, 9, 44, 43, 102 }; //페르시온 - 할퀴기, 울음소리, 물기, 싫은소리
	table[i++] = { i, 9, -1, -1, -1 }; //고라파덕 - 할퀴기
	table[i++] = { i, 9, 38, 43, 102 }; //골덕 - 할퀴기, 꼬리흔들기
	table[i++] = { i, 9, 42, -1, -1 }; //망키 - 할퀴기, 째려보기
	table[i++] = { i, 9, 42, 66, -1 }; //성원숭 - 할퀴기, 째려보기, 안다리걸기
	table[i++] = { i, 43, 45, -1, -1 }; //가디 - 물기, 울부짖기
	table[i++] = { i, 45, 51, 42, 35 }; //윈디 - 울부짖기, 불꽃세례, 째려보기, 돌진
	table[i++] = { i, 144, -1, -1, -1 }; //발챙이 - 거품
	table[i++] = { i, 144, 94, 54, 102 }; //수륙챙이 - 거품, 최면술, 물대포
	table[i++] = { i, 94, 102, 2, 33 }; //강챙이 - 최면술, 물대포, 연속뺨치기, 누르기
	table[i++] = { i, 99, -1, -1, -1 }; //케이시 - 순간이동
	table[i++] = { i, 99, 92, 49, 133 }; //윤겔라 - 순간이동, 염동력, 사슬묶기, 숟가락휘기
	table[i++] = { i, 99, 92, 49, 133 }; //후딘 - 순간이동, 염동력, 사슬묶기,숟가락휘기
	table[i++] = { i, 1, -1, -1, -1 }; //알통몬 - 태권당수
	table[i++] = { i, 1, 66, 42, -1 }; //근육몬 - 태권당수, 안다리걸기, 째려보기
	table[i++] = { i, 1, 66, 42, -1 }; //괴력몬 - 태권당수, 안다리걸기, 째려보기
	table[i++] = { i, 21, 73, -1, -1 }; //모다피 - 덩쿨채찍, 성장
	table[i++] = { i, 21, 73, 34, 76 }; //우츠동 - 덩쿨채찍, 성장, 김밥말이, 독가루
	table[i++] = { i, 78, 77, 50, 74 }; //우츠보트 - 수면가루, 저리가루, 용해액, 잎날가르기
	table[i++] = { i, 50, -1, -1, -1 }; //왕눈해 - 용해액
	table[i++] = { i, 50, 47, 34, 39 }; //독파리 - 용해액, 초음파, 김밥말이, 독침
	table[i++] = { i, 32, 73, -1, -1 }; //꼬마돌 - 몸통박치기
	table[i++] = { i, 32, 110, -1, -1 }; //데구리 - 몸통박치기, 웅크리기
	table[i++] = { i, 32, 110, -1, -1 }; //딱구리 - 몸통박치기, 웅크리기
	table[i++] = { i, 51, -1, -1, -1 }; //포니타 - 불꽃세례
	table[i++] = { i, 51, 38, 22, 44 }; //날쌩마 - 불꽃세례, 꼬리흔들기, 짓밟기, 울음소리
	table[i++] = { i, 92, -1, -1, -1 }; //야돈 - 염동력
	table[i++] = { i, 92, 49, 28, -1 }; //야도란 - 염동력, 사슬묶기, 박치기
	table[i++] = { i, 32, 48, -1, -1 }; //코일 - 몸통박치기, 소닉붐
	table[i++] = { i, 32, 48, 83, -1 }; //레어코일 - 몸통박치기, 소닉붐, 전기쇼크
	table[i++] = { i, 63, 27, -1, -1 }; //파오리 - 쪼기, 모래뿌리기
	table[i++] = { i, 63, -1, -1, -1 }; //두두 - 쪼기
	table[i++] = { i, 63, 44, 30, -1 }; //두트리오 - 쪼기, 울음소리, 마구찌르기
	table[i++] = { i, 28, -1, -1, -1 }; //쥬쥬 - 박치기
	table[i++] = { i, 28, 44, 61, -1 }; //쥬레곤 - 박치기, 울음소리, 오로라빔
	table[i++] = { i, 0, 49, -1, -1 }; //질퍽이 - 막치기, 사슬묶기
	table[i++] = { i, 0, 49, 138, -1 }; //질뻐기 - 막치기, 사슬묶기, 독가스
	table[i++] = { i, 32, 109, -1, -1 }; //셀러 - 몸통박치기, 껍질에숨기
	table[i++] = { i, 109, 47, 127, 61 }; //파르셀 - 껍질에숨기, 초음파, 껍질끼우기, 오로라빔
	table[i++] = { i, 121, 108, 100, -1 }; //고오스 - 핥기, 이상한빛, 나이트헤드
	table[i++] = { i, 121, 108, 100, -1 }; //고우스트 - 핥기, 이상한빛, 나이트헤드
	table[i++] = { i, 121, 108, 100, -1 }; //팬텀 - 핥기, 이상한빛, 나이트헤드
	table[i++] = { i, 32, 102, -1, -1 }; //롱스톤 - 몸통박치기, 싫은소리
	table[i++] = { i, 0, 94, -1, -1 }; //슬리프 - 막치기, 최면술
	table[i++] = { i, 0, 94, 49, 92 }; //슬리퍼 - 막치기, 최면술, 사슬묶기, 염동력
	table[i++] = { i, 144, 42, -1, -1 }; //크랩 - 거품, 째려보기
	table[i++] = { i, 144, 42, 10, 11 }; //킹크랩 - 거품, 째려보기, 찝기, 가위자르기
	table[i++] = { i, 32, 102, -1, -1 }; //찌리리공 - 몸통박치기, 싫은소리
	table[i++] = { i, 32, 102, 48, 119 }; //붐볼 - 몸통박치기, 싫은소리, 소닉붐, 자폭
	table[i++] = { i, 139, 94, -1, -1 }; //아라리 - 구슬던지기, 최면술
	table[i++] = { i, 139, 94, -1, -1 }; //나시 - 구슬던지기, 최면술
	table[i++] = { i, 124, 44, -1, -1 }; //탕구리 - 뼈다귀치기, 울음소리
	table[i++] = { i, 124, 44, 42, 115 }; //텅구리 - 뼈다귀치기, 울음소리, 째려보기, 기충전
	table[i++] = { i, 23, 95, -1, -1 }; //시라소몬 - 두번치기, 요가포즈
	table[i++] = { i, 3, 96, 49, 92 }; //홍수몬 - 연속펀치, 고속이동
	table[i++] = { i, 34, 47, -1, -1 }; //내루미 - 김밥말이, 초음파
	table[i++] = { i, 32, 122, -1, -1 }; //또가스 - 몸통박치기, 스모그
	table[i++] = { i, 32, 122, 123, -1 }; //또도가스 - 몸통박치기, 스모그, 오물공격
	table[i++] = { i, 29, -1, -1, -1 }; //뿔카노 - 뿔찌르기
	table[i++] = { i, 29, -1, -1, -1 }; //코뿌리 - 뿔찌르기
	table[i++] = { i, 0, 2, 38, -1 }; //럭키 - 막치기, 연속뺨치기, 꼬리흔들기
	table[i++] = { i, 131, 19, -1, -1 }; //덩쿠리 - 휘감기, 조이기
	table[i++] = { i, 3, 98, -1, -1 }; //킹카 - 연속펀치, 분노
	table[i++] = { i, 144, -1, -1, -1 }; //쏘드라 - 거품
	table[i++] = { i, 144, 107, 42, 54 }; //시드라 - 거품, 연막, 째려보기, 물대포
	table[i++] = { i, 63, 38, -1, -1 }; //콘치 - 쪼기, 꼬리흔들기
	table[i++] = { i, 63, 38, 47, 29 }; //왕콘치 - 쪼기, 꼬리흔들기, 초음파, 뿔찌르기
	table[i++] = { i, 32, -1, -1, -1 }; //별가사리 - 몸통박치기
	table[i++] = { i, 32, 105, 54, -1 }; //아쿠스타 - 몸통박치기, 단단해지기, 물대포
	table[i++] = { i, 92, 111, -1, -1 }; //마임맨 - 염동력, 배리어
	table[i++] = { i, 97, 42, 115, -1 }; //스라크 - 전광석화, 째려보기, 기충전
	table[i++] = { i, 0, 121, 141, -1 }; //루주라 - 막치기, 핥기, 악마의키스
	table[i++] = { i, 97, 42, -1, -1 }; //에레브 - 전광석화, 째려보기
	table[i++] = { i, 51, -1, -1, -1 }; //마그마 - 불꽃세례
	table[i++] = { i, 10, -1, -1, -1 }; //쁘사이저 - 찝기
	table[i++] = { i, 32, 22, -1, -1 }; //켄타로스 - 몸통박치기, 짓밟기
	table[i++] = { i, 149, -1, -1, -1 }; //잉어킹 - 튀어오르기
	table[i++] = { i, 32, -1, -1, -1 }; //갸라도스 - 몸통박치기
	table[i++] = { i, 54, 44, -1, -1 }; //라프라스 - 물대포, 울음소리
	table[i++] = { i, 143, -1, -1, -1 }; //메타몽 - 변신
	table[i++] = { i, 32, 27, 44, 97 }; //이브이 - 몸통박치기, 모래뿌리기, 울음소리, 전광석화
	table[i++] = { i, 32, 27, -1, -1 }; //샤미드 - 몸통박치기, 모래뿌리기
	table[i++] = { i, 32, 38, 97, 83 }; //쥬피썬더 - 몸통박치기, 꼬리흔들기, 전광석화, 전기쇼크
	table[i++] = { i, 32, 38, 97, 51 }; //부스터 - 몸통박치기, 꼬리흔들기, 전광석화, 불꽃세례
	table[i++] = { i, 32, 158, 159, 59 }; //폴리곤 - 몸통박치기, 각지기, 텍스처, 환상빔
	table[i++] = { i, 102, 109, -1, -1 }; //암나이트 - 물대포, 껍질에숨기
	table[i++] = { i, 102, 109, 29, 42 }; //암스타 - 물대포, 껍질에숨기, 뿔찌르기, 째려보기
	table[i++] = { i, 9, 105, -1, -1 }; //투구 - 할퀴기, 단단해지기
	table[i++] = { i, 9, 105, 70, 162 }; //투구푸스 - 할퀴기, 단단해지기, 흡수, 베어가르기
	table[i++] = { i, 16, 96, -1, -1 }; //프테라 - 날개치기, 고속이동
	table[i++] = { i, 28, 132, 155, -1 }; //잠만보 - 박치기, 망각술, 잠자기
	table[i++] = { i, 63, 57, -1, -1 }; //프리져 - 쪼기, 냉동빔
	table[i++] = { i, 64, 83, -1, -1 }; //썬더 - 회전부리, 전기쇼크
	table[i++] = { i, 63, 82, -1, -1 }; //파이어 - 쪼기, 회오리불꽃
	table[i++] = { i, 34, 42, -1, -1 }; //미뇽 - 김밥말이, 째려보기
	table[i++] = { i, 34, 42, 85, 96 }; //신뇽 - 김밥말이, 째려보기, 전기자석파, 고속이동
	table[i++] = { i, 34, 42, 85, 96 }; //망나뇽 - 김밥말이, 째려보기, 전기자석파, 고속이동
	table[i++] = { i, 92, 49, 128, -1 }; //뮤츠 - 염동력, 사슬묶기, 스피드스타
	table[i++] = { i, 0, -1, -1, -1 }; //뮤 - 막치기

	if (fout.fail() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			fout << table[i].pokemonIndex << " "
				<< table[i].skill[0] << " "
				<< table[i].skill[1] << " "
				<< table[i].skill[2] << " "
				<< table[i].skill[3] << std::endl;
		}
		fout.close();
	}

	delete[] table;
}

void PokemonManager::LoadPokemonTable()
{
	std::ifstream fout;

	fout.open("DB/SkillTable.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			PokemonTable temp;
			fout >> temp.pokemonIndex
				>> temp.skill[0]
				>> temp.skill[1]
				>> temp.skill[2]
				>> temp.skill[3];
			m_pokemonTable.push_back(temp);
		}
		fout.close();
	}
}

void PokemonManager::RootMyPokemon()
{
	m_pokemonCount = 5;

	m_myPokemonList[0].m_data = POKEDEX.GetPokemonData(36);
	m_myPokemonList[0].m_level = 65;
	m_myPokemonList[0].m_sex =1;
	m_myPokemonList[0].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[0].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[0].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[0].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[0].m_hpMax = 2500;
	m_myPokemonList[0].m_hp = 2500;
	strcpy_s(m_myPokemonList[0].m_nickname, 20, m_myPokemonList[0].m_data.m_name);

	m_myPokemonList[1].m_data = POKEDEX.GetPokemonData(37);
	m_myPokemonList[1].m_level = 55;
	m_myPokemonList[1].m_sex = 0;
	m_myPokemonList[1].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[1].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[1].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[1].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[1].m_hpMax = m_myPokemonList[1].m_level * 50;
	m_myPokemonList[1].m_hp = m_myPokemonList[1].m_level * 40;
	strcpy_s(m_myPokemonList[1].m_nickname, 20, m_myPokemonList[1].m_data.m_name);

	m_myPokemonList[2].m_data = POKEDEX.GetPokemonData(148);
	m_myPokemonList[2].m_level = 48;
	m_myPokemonList[2].m_sex = 0;
	m_myPokemonList[2].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[2].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[2].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[2].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[2].m_hpMax = m_myPokemonList[2].m_level * 50;
	m_myPokemonList[2].m_hp = m_myPokemonList[2].m_level * 25;
	strcpy_s(m_myPokemonList[2].m_nickname, 20, m_myPokemonList[2].m_data.m_name);

	m_myPokemonList[3].m_data = POKEDEX.GetPokemonData(72);
	m_myPokemonList[3].m_level = 92;
	m_myPokemonList[3].m_sex = 1;
	m_myPokemonList[3].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[3].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[3].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[3].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[3].m_hpMax = m_myPokemonList[3].m_level * 50;
	m_myPokemonList[3].m_hp = m_myPokemonList[3].m_level * 10;
	strcpy_s(m_myPokemonList[3].m_nickname, 20, m_myPokemonList[3].m_data.m_name);

	m_myPokemonList[4].m_data = POKEDEX.GetPokemonData(44);
	m_myPokemonList[4].m_level = 82;
	m_myPokemonList[4].m_sex = 1;
	m_myPokemonList[4].m_skill[0] = SKILL_MANAGER.GetSkill(51);
	m_myPokemonList[4].m_skill[1] = SKILL_MANAGER.GetSkill(82);
	m_myPokemonList[4].m_skill[2] = SKILL_MANAGER.GetSkill(103);
	m_myPokemonList[4].m_skill[3] = SKILL_MANAGER.GetSkill(125);
	m_myPokemonList[4].m_hpMax = m_myPokemonList[4].m_level * 50;
	m_myPokemonList[4].m_hp = m_myPokemonList[4].m_hpMax;
	strcpy_s(m_myPokemonList[4].m_nickname, 20, m_myPokemonList[4].m_data.m_name);
}

void PokemonManager::Init()
{
	//SaveMyPokemon();
	LoadMyPokemon();
	SaveNPCPokemon();
	LoadNPCPokemon();
	SavePokemonTable();
	LoadPokemonTable();
}

void PokemonManager::SetMyPokemonList(Pokemon* _pokemonList, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		m_myPokemonList[i] = _pokemonList[i];
	}

	m_pokemonCount = _size;
}

Pokemon* PokemonManager::GetMyPokemonList()
{
	return m_myPokemonList;
}

Pokemon PokemonManager::GetMyPokemon(int _index)
{
	if (_index >= 6) return Pokemon();
	else return m_myPokemonList[_index];
}

Pokemon* PokemonManager::GetSelectedMyPokemon()
{
	return &m_myPokemonList[m_currentMyIndex];
}

int PokemonManager::GetSelectedPokemonNumber()
{
	return m_currentMyIndex;
}

void PokemonManager::SetSelectedMyPokemon(int _index)
{
	m_currentMyIndex = _index;
}

void PokemonManager::SettingBattleList()
{
	for (int i = 0; i < 6; i++)
	{
		m_battleList[i] = m_myPokemonList[i];
	}
}

Pokemon PokemonManager::GetMyBattlePokemon(int _index)
{
	if (_index >= 6) return Pokemon();
	else return m_battleList[_index];
}

Pokemon* PokemonManager::GetSelectedBattlePokemon()
{
	return &m_battleList[m_currentMyIndex];
}

void PokemonManager::SwapPokemon(int _swapIndex)
{
	Pokemon tmp = m_battleList[_swapIndex];
	m_battleList[_swapIndex] = m_battleList[0];
	m_battleList[0] = tmp;
}

void PokemonManager::SetEnemyPokemonList(int _npcNumber)
{
	EnemyPokemonTable* table = new EnemyPokemonTable;
	for (int i = 0; i < m_enemyTable.size(); i++)
	{
		if (m_enemyTable[i].npcNumber == _npcNumber)
		{
			table = &m_enemyTable[i];
		}
	}
	for (int i = 0; i < 6; i++)
	{
		Pokemon* temp = &m_enemyPokemonList[i];
		temp->m_data = POKEDEX.GetPokemonData(table->PokemonList[i].pokemonIndex);
		temp->m_level = 35;
		temp->m_sex = rand() % 2;
		temp->m_skill[0] = SKILL_MANAGER.GetSkill(16);
		temp->m_skill[1] = SKILL_MANAGER.GetSkill(70);
		temp->m_skill[2] = SKILL_MANAGER.GetSkill(93);
		temp->m_skill[3] = SKILL_MANAGER.GetSkill(108);
		temp->m_hpMax = 1200;
		temp->m_hp = temp->m_hpMax;
	}
}

Pokemon* PokemonManager::GetEnemyPokemonList(int _npcNumber)
{
	return m_enemyPokemonList;
}

Pokemon* PokemonManager::GetSelectedEnemyPokemon()
{
	return &m_enemyPokemonList[m_currentEnemyIndex];
}

void PokemonManager::SetSelectedEnemyPokemon(int _index)
{
	m_currentEnemyIndex = _index;
}

void PokemonManager::GeneratePokemon(int _area)
{	
	m_wildPokemon.m_condition = CONDITION::NO_CONDITION;
	m_wildPokemon.m_sex = rand() % 2;

	//지역에 따라 생성되는 포켓몬목록이 다르게 처리
	switch (_area)
	{
	case 0:
	{
		int indexList[3] = { 12,55,73 }; //등장 포켓몬 번호
		m_wildPokemon.m_data = POKEDEX.GetPokemonData(indexList[(rand()%3)]);
		m_wildPokemon.m_level = 6;
		m_wildPokemon.m_hpMax = 100 * m_wildPokemon.m_level;
		m_wildPokemon.m_hp = m_wildPokemon.m_hpMax;
		m_wildPokemon.m_giveExp = 50 * m_wildPokemon.m_level;
		m_wildPokemon.m_requiredExp = 300 * m_wildPokemon.m_level;
		m_wildPokemon.m_currentExp = 0;
		for (int i = 0; i < 4; i++)
		{
			m_wildPokemon.m_skill[i] = SKILL_MANAGER.GetSkillByType(m_wildPokemon.m_data.m_type_1, m_wildPokemon.m_data.m_type_2);
		}
	}break;
	}
	
}

Pokemon* PokemonManager::GetWildPokemon()
{
	return &m_wildPokemon;
}

void PokemonManager::CatchPokemon()
{
	//들고있는 포켓몬이 6마리라면, 포켓박스로 전송
	if (m_pokemonCount == 6)
	{

	}
	//아니라면 가방에 추가
	else
	{
		m_myPokemonList[5].m_data		= m_wildPokemon.m_data;
		m_myPokemonList[5].m_level		= m_wildPokemon.m_level;
		m_myPokemonList[5].m_sex		= m_wildPokemon.m_sex;
		m_myPokemonList[5].m_skill[0]	= m_wildPokemon.m_skill[0];
		m_myPokemonList[5].m_skill[1]	= m_wildPokemon.m_skill[1];
		m_myPokemonList[5].m_skill[2]	= m_wildPokemon.m_skill[2];
		m_myPokemonList[5].m_skill[3]	= m_wildPokemon.m_skill[3];
		m_myPokemonList[5].m_hpMax		= m_wildPokemon.m_hpMax;
		m_myPokemonList[5].m_hp			= m_wildPokemon.m_hp;
		strcpy_s(m_myPokemonList[5].m_nickname, 20, m_myPokemonList[5].m_data.m_name);

		m_wildPokemon = {};
		m_pokemonCount = 6;
	}
}

void PokemonManager::HealPokemon()
{
	for (auto p : m_myPokemonList)
	{
		p.m_hp = p.m_hpMax;
	}
}
