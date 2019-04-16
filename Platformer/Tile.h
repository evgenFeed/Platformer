#pragma once
#include "SFML\Graphics.hpp"
#include "BoundingBox.h"

class Tile
{
public:
						Tile(float x, float y, int blockX, int blockY);
						~Tile();

	void				Draw(sf::RenderWindow &window);
	BoundingBox			box;
	//Collider			GetCollider() { return Collider(tile); }
private:
	sf::RectangleShape	tile;
	sf::Texture			*tile_texture;
	sf::IntRect			pos;
};

