#include "Tile.h"



Tile::Tile(float x, float y, int blockX, int blockY)
{
	tile_texture = new sf::Texture();
	pos.left = x * 31;
	pos.top = y * 31;
	pos.height = 31;
	pos.width = 31;
	tile_texture->loadFromFile("Textures/map.png");
	tile.setSize(sf::Vector2f(pos.height, pos.height));
	tile.setOrigin(pos.height / 2, pos.width / 2);
	tile.setTexture(tile_texture);
	tile.setTextureRect(sf::IntRect(blockX * 33 , blockY * 33, 31, 31));
	tile.setPosition(pos.left, pos.top);
}


Tile::~Tile()
{
	delete tile_texture;
}


void Tile::Draw(sf::RenderWindow & window)
{
	window.draw(tile);
}
