#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
private:
	sf::RenderWindow *window;
	sf::Texture bgTexture;
	sf::Sprite backGround;
	Player *player;
};

