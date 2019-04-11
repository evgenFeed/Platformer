#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>
#include <vector>


class Game
{
public:
	Game();
	~Game();
	void Start();
private:
	std::vector<std::string> map;
	std::vector<Tile*> tiles;
	sf::RenderWindow *window;
	sf::Texture *playerTexture;
	Player *player;
};

