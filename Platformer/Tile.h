#pragma once
#include "SFML\Graphics.hpp"

class Tile
{
public:
	Tile();
	~Tile();
private:
	sf::Sprite tile;
	sf::Texture tile_texture;
};

