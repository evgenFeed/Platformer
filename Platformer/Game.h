#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "Player.h"
#include "Tile.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>



class Game
{
public:
									Game();
									~Game();
	void							run();
private:
	void							processEvents();
	void							update(sf::Time deltaTime);
	void							render();
private:
	std::vector<std::string>		map;
	std::vector<Tile*>				tiles;
	sf::RenderWindow				mWindow;
	World							mWorld;
};

