#include "Game.h"
#include <iostream>


Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1366, 768), "Platformer");
	bgTexture.loadFromFile("Textures/11_background.png");
	backGround.setTexture(bgTexture);

	sf::Texture ground;
	sf::Sprite board;
	if (!ground.loadFromFile("Textures/ground.png"))
	{
		std::cout << "ERROR!" << std::endl;
	}
	board.setPosition(sf::Vector2f(0.f,500.f));
	board.setTexture(ground);
	board.setTextureRect(sf::IntRect(0, 1204, 1366, 200));

	player = new Player(sf::FloatRect(400,300,32,32));

	//sf::View view(sf::FloatRect(0.0f, 0.0f, 1366.f, 768.f));

	sf::Clock timer;
	float time;

	while (window->isOpen())
	{
		sf::Event event;
		
		
		while (window->pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		//view.setCenter(player->getSprite().getPosition().x, board.getPosition().y);

		time = timer.getElapsedTime().asMicroseconds();
		timer.restart();
		time /= 800;
		//window->setView(view);
		window->clear();

		player->update(board, time);
		
		
		//window->draw(backGround);
		player->draw(*window);
		window->draw(board);
		window->display();
	}

}


Game::~Game()
{
	delete player;
	delete window;
}
