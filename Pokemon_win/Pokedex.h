#pragma once

class Pokedex
{
private:
	std::vector<PokedexData> m_pokemonList;

private:
	Pokedex();
	~Pokedex();
	void SavePokemon();
	void LoadPokemon();

public:
	static Pokedex& GetInstance()
	{
		static Pokedex Instance;
		return Instance;
	}

	void Init();
	PokedexData GetPokemonData(short _number);
	const char* GetType(short _type);
	const char* GetSpecial();
	int GetFoundPokemonNum()
	{
		return m_pokemonList.size();
	}
};

#define POKEDEX Pokedex::GetInstance()