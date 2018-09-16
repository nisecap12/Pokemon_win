#include "stdafx.h"
#include "Pokedex.h"

Pokedex::Pokedex()
{
}


Pokedex::~Pokedex()
{
	m_pokemonList.clear();
}

void Pokedex::SavePokemon()
{
	PokedexData* pokemon = new PokedexData[POKEMON_TOTAL_NUMBER];
	short i = 0;

	/*
	short m_number;			//포켓몬 번호
	char m_name[20];		//종 이름
	short m_type_1;			//타입1
	short m_type_2;			//타입2
	short m_evolutionLevel;	// 총 진화 단계
	short m_evolvedLevel;	// 진화 단계
	*/

	pokemon[i++] = { i, "이상해씨", Type::GRASS, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "이상해풀", Type::GRASS, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "이상해꽃", Type::GRASS, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "파이리", Type::FIRE, Type::FIRE, 3, 1 };
	pokemon[i++] = { i, "리자드", Type::FIRE, Type::FIRE, 3, 2 };
	pokemon[i++] = { i, "리자몽", Type::FIRE, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "꼬부기", Type::WATER, Type::WATER, 3, 1 };
	pokemon[i++] = { i, "어니부기", Type::WATER, Type::WATER, 3, 2 };
	pokemon[i++] = { i, "거북왕", Type::WATER, Type::WATER, 3, 3 };
	pokemon[i++] = { i, "캐터피", Type::BUG, Type::BUG, 3, 1 };
	pokemon[i++] = { i, "단데기", Type::BUG, Type::BUG, 3, 2 };
	pokemon[i++] = { i, "버터플", Type::BUG, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "뿔충이", Type::BUG, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "딱충이", Type::BUG, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "독침붕", Type::BUG, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "구구", Type::NORMAL, Type::FLY, 3, 1 };
	pokemon[i++] = { i, "피죤", Type::NORMAL, Type::FLY, 3, 2 };
	pokemon[i++] = { i, "피죤투", Type::NORMAL, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "꼬렛", Type::NORMAL, Type::NORMAL, 2, 1 };
	pokemon[i++] = { i, "레트라", Type::NORMAL, Type::NORMAL, 2, 2 };
	pokemon[i++] = { i, "깨비참", Type::NORMAL, Type::FLY, 2, 1 };
	pokemon[i++] = { i, "깨비드릴조", Type::NORMAL, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "아보", Type::POISON, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "아보크", Type::POISON, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "피카츄", Type::THUNDER, Type::THUNDER, 2, 1 };
	pokemon[i++] = { i, "라이츄", Type::THUNDER, Type::THUNDER, 2, 2 };
	pokemon[i++] = { i, "모래두지", Type::GROUND, Type::GROUND, 2, 1 };
	pokemon[i++] = { i, "고지", Type::GROUND, Type::GROUND, 2, 2 };
	pokemon[i++] = { i, "니드런♀", Type::POISON, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "니드리나", Type::POISON, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "니드퀸", Type::POISON, Type::GROUND, 3, 3 };
	pokemon[i++] = { i, "니드런♂", Type::POISON, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "니드리노", Type::POISON, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "니드킹", Type::POISON, Type::GROUND, 3, 3 };
	pokemon[i++] = { i, "삐삐", Type::FAIRY, Type::FAIRY, 2, 1 };
	pokemon[i++] = { i, "픽시", Type::FAIRY, Type::FAIRY, 2, 2 };
	pokemon[i++] = { i, "식스테일", Type::FIRE, Type::FIRE, 2, 1 };
	pokemon[i++] = { i, "나인테일", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "푸린", Type::NORMAL, Type::FAIRY, 2, 1 };
	pokemon[i++] = { i, "푸크린", Type::NORMAL, Type::FAIRY, 2, 2 };
	pokemon[i++] = { i, "주뱃", Type::POISON, Type::FLY, 2, 1 };
	pokemon[i++] = { i, "골뱃", Type::POISON, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "뚜벅초", Type::GRASS, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "냄새꼬", Type::GRASS, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "라플레시아", Type::GRASS, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "파라스", Type::BUG, Type::GRASS, 2, 1 };
	pokemon[i++] = { i, "파라섹트", Type::BUG, Type::GRASS, 2, 2 };
	pokemon[i++] = { i, "콘팡", Type::BUG, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "도나리", Type::BUG, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "디그다", Type::GROUND, Type::GROUND, 2, 1 };
	pokemon[i++] = { i, "닥트리오", Type::GROUND, Type::GROUND, 2, 2 };
	pokemon[i++] = { i, "나옹", Type::NORMAL, Type::NORMAL, 2, 1 };
	pokemon[i++] = { i, "페르시온", Type::NORMAL, Type::NORMAL, 2, 2 };
	pokemon[i++] = { i, "고라파덕", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "골덕", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "망키", Type::FIGHT, Type::FIGHT, 2, 1 };
	pokemon[i++] = { i, "성원숭", Type::FIGHT, Type::FIGHT, 2, 2 };
	pokemon[i++] = { i, "가디", Type::FIRE, Type::FIRE, 2, 1 };
	pokemon[i++] = { i, "윈디", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "발챙이", Type::WATER, Type::WATER, 3, 1 };
	pokemon[i++] = { i, "수륙챙이", Type::WATER, Type::WATER, 3, 2 };
	pokemon[i++] = { i, "강챙이", Type::WATER, Type::FIGHT, 3, 3 };
	pokemon[i++] = { i, "케이시", Type::ESPER, Type::ESPER, 3, 1 };
	pokemon[i++] = { i, "윤겔라", Type::ESPER, Type::ESPER, 3, 2 };
	pokemon[i++] = { i, "후딘", Type::ESPER, Type::ESPER, 3, 3 };
	pokemon[i++] = { i, "알통몬", Type::FIGHT, Type::FIGHT, 3, 1 };
	pokemon[i++] = { i, "근육몬", Type::FIGHT, Type::FIGHT, 3, 2 };
	pokemon[i++] = { i, "괴력몬", Type::FIGHT, Type::FIGHT, 3, 3 };
	pokemon[i++] = { i, "모다피", Type::GRASS, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "우츠동", Type::GRASS, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "우츠보트", Type::GRASS, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "왕눈해", Type::WATER, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "독파리", Type::WATER, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "꼬마돌", Type::ROCK, Type::GROUND, 3, 1 };
	pokemon[i++] = { i, "데구리", Type::ROCK, Type::GROUND, 3, 2 };
	pokemon[i++] = { i, "딱구리", Type::ROCK, Type::GROUND, 3, 3 };
	pokemon[i++] = { i, "포니타", Type::FIRE, Type::FIRE, 2, 1 };
	pokemon[i++] = { i, "날쌩마", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "야돈", Type::WATER, Type::ESPER, 2, 1 };
	pokemon[i++] = { i, "야도란", Type::WATER, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "코일", Type::THUNDER, Type::STEEL, 2, 1 };
	pokemon[i++] = { i, "레어코일", Type::THUNDER, Type::STEEL, 2, 2 };
	pokemon[i++] = { i, "파오리", Type::NORMAL, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "두두", Type::NORMAL, Type::FLY, 2, 1 };
	pokemon[i++] = { i, "두트리오", Type::NORMAL, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "쥬쥬", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "쥬레곤", Type::WATER, Type::ICE, 2, 2 };
	pokemon[i++] = { i, "질퍽이", Type::POISON, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "질뻐기", Type::POISON, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "셀러", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "파르셀", Type::WATER, Type::ICE, 2, 2 };
	pokemon[i++] = { i, "고오스", Type::GHOST, Type::POISON, 3, 1 };
	pokemon[i++] = { i, "고우스트", Type::GHOST, Type::POISON, 3, 2 };
	pokemon[i++] = { i, "팬텀", Type::GHOST, Type::POISON, 3, 3 };
	pokemon[i++] = { i, "롱스톤", Type::ROCK, Type::GROUND, 1, 1 };
	pokemon[i++] = { i, "슬리프", Type::ESPER, Type::ESPER, 2, 1 };
	pokemon[i++] = { i, "슬리퍼", Type::ESPER, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "크랩", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "킹크랩", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "찌리리공", Type::THUNDER, Type::THUNDER, 2, 1 };
	pokemon[i++] = { i, "붐볼", Type::THUNDER, Type::THUNDER, 2, 2 };
	pokemon[i++] = { i, "아라리", Type::GRASS, Type::ESPER, 2, 1 };
	pokemon[i++] = { i, "나시", Type::GRASS, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "탕구리", Type::GROUND, Type::GROUND, 2, 1 };
	pokemon[i++] = { i, "텅구리", Type::GROUND, Type::GROUND, 2, 2 };
	pokemon[i++] = { i, "시라소몬", Type::FIGHT, Type::FIGHT, 2, 1 };
	pokemon[i++] = { i, "홍수몬", Type::FIGHT, Type::FIGHT, 2, 2 };
	pokemon[i++] = { i, "내루미", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "또가스", Type::POISON, Type::POISON, 2, 1 };
	pokemon[i++] = { i, "또도가스", Type::POISON, Type::POISON, 2, 2 };
	pokemon[i++] = { i, "뿔카노", Type::GROUND, Type::ROCK, 2, 1 };
	pokemon[i++] = { i, "코뿌리", Type::GROUND, Type::ROCK, 2, 2 };
	pokemon[i++] = { i, "럭키", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "덩쿠리", Type::GRASS, Type::GRASS, 1, 1 };
	pokemon[i++] = { i, "캥카", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "쏘드라", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "시드라", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "콘치", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "왕콘치", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "별가사리", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "아쿠스타", Type::WATER, Type::ESPER, 2, 2 };
	pokemon[i++] = { i, "마임맨", Type::ESPER, Type::FAIRY, 1, 1 };
	pokemon[i++] = { i, "스라크", Type::BUG, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "루주라", Type::ICE, Type::ESPER, 1, 1 };
	pokemon[i++] = { i, "에레브", Type::THUNDER, Type::THUNDER, 1, 1 };
	pokemon[i++] = { i, "마그마", Type::FIRE, Type::FIRE, 1, 1 };
	pokemon[i++] = { i, "쁘사이저", Type::BUG, Type::BUG, 1, 1 };
	pokemon[i++] = { i, "켄타로스", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "잉어킹", Type::WATER, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "갸라도스", Type::WATER, Type::FLY, 2, 2 };
	pokemon[i++] = { i, "라프라스", Type::WATER, Type::ICE, 1, 1 };
	pokemon[i++] = { i, "메타몽", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "이브이", Type::NORMAL, Type::NORMAL, 2, 1 };
	pokemon[i++] = { i, "샤미드", Type::WATER, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "쥬피썬더", Type::THUNDER, Type::THUNDER, 2, 2 };
	pokemon[i++] = { i, "부스터", Type::FIRE, Type::FIRE, 2, 2 };
	pokemon[i++] = { i, "폴리곤", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "암나이트", Type::ROCK, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "암스타", Type::ROCK, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "투구", Type::ROCK, Type::WATER, 2, 1 };
	pokemon[i++] = { i, "투구푸스", Type::ROCK, Type::WATER, 2, 2 };
	pokemon[i++] = { i, "프테라", Type::ROCK, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "잠만보", Type::NORMAL, Type::NORMAL, 1, 1 };
	pokemon[i++] = { i, "프리져", Type::ICE, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "썬더", Type::THUNDER, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "파이어", Type::FIRE, Type::FLY, 1, 1 };
	pokemon[i++] = { i, "미뇽", Type::DRAGON, Type::DRAGON, 3, 1 };
	pokemon[i++] = { i, "신뇽", Type::DRAGON, Type::DRAGON, 3, 2 };
	pokemon[i++] = { i, "망나뇽", Type::DRAGON, Type::FLY, 3, 3 };
	pokemon[i++] = { i, "뮤츠", Type::ESPER, Type::ESPER, 1, 1 };
	pokemon[i++] = { i, "뮤", Type::ESPER, Type::ESPER, 1, 1 };

	std::ofstream fout("DB/Pokedex.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < POKEMON_TOTAL_NUMBER; i++)
		{
			fout << pokemon[i].m_number << " "
				<< pokemon[i].m_name << " "
				<< pokemon[i].m_type_1 << " "
				<< pokemon[i].m_type_2 << " "
				<< pokemon[i].m_evolutionLevel << " "
				<< pokemon[i].m_evolvedLevel << std::endl;
		}
		fout.close();
	}

	delete[] pokemon;
}

void Pokedex::LoadPokemon()
{
	std::ifstream fout;

	//NPC.db 파일 열기
	fout.open("DB/Pokedex.db");

	if (fout.fail() == false)
	{
		for (int i = 0; i < POKEMON_TOTAL_NUMBER; i++)
		{
			PokedexData temp;
			fout >> temp.m_number
				>> temp.m_name
				>> temp.m_type_1
				>> temp.m_type_2
				>> temp.m_evolutionLevel
				>> temp.m_evolvedLevel;
			m_pokemonList.push_back(temp);
		}
		fout.close();
	}
}

void Pokedex::Init()
{
	SavePokemon();
	LoadPokemon();
}

PokedexData Pokedex::GetPokemonData(short _number)
{
	if (_number >= 0)
	{
		return m_pokemonList[_number];
	}
	else
	{
		return PokedexData();
	}
}

const char * Pokedex::GetType(short _type)
{
	switch (_type)
	{
	case Type::NORMAL: return "노말";
	case Type::FIRE: return "불";
	case Type::WATER:	return "물";
	case Type::GRASS:	return "풀";
	case Type::THUNDER:	return "전기";
	case Type::ICE:	return "얼음";
	case Type::FIGHT:	return "격투";
	case Type::POISON:	return "독";
	case Type::GROUND:	return "땅";
	case Type::FLY:	return "비행";
	case Type::ESPER: return "에스퍼";
	case Type::BUG: return "벌레";
	case Type::ROCK: return "바위";
	case Type::GHOST: return "고스트";
	case Type::DRAGON: return "드래곤";
	case Type::EVIL: return "악";
	case Type::STEEL: return "강철";
	case Type::FAIRY: return "페어리";
	}
}

const char * Pokedex::GetSpecial()
{
	const char* list[20] =
	{ "옹골참", "가속", "습기", "유연", "정전기",
	"축전", "둔감", "마이페이스", "인분", "위협",
	"까칠한피부", "독가시", "자력", "정신력", "트레이스",
	"모래날림", "돌머리", "순수한힘", "심록", "내열" };

	return list[rand() % 20];
}
