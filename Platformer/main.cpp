#include "SFML\Graphics.hpp"
#include <iostream>
#include "Game.h"
using namespace sf;

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch(std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
	return 0;

}