#include "SFML\Graphics.hpp"
#include <iostream>
#include "Game.h"
using namespace sf;

int main()
{
	Game *game = new Game();
	game->run();
	
	return 0;

}