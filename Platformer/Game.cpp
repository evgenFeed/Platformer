#include "Game.h"

static const float VIEW_HEIGHT = 768;
static const float VIEW_WIDTH = 1366;

void ResizeWindow(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Platformer");
	playerTexture = new sf::Texture();
	playerTexture->loadFromFile("Textures/player.png");
	player = new Player(playerTexture, sf::Vector2u(4, 4), 0.5f, 100.f, 150.f);
	map = {
		"CCCC CCCCCC CCCCCCCC CCCCCC CCCCCCCC CCCCCCC",
		"   CCC    CCC      CCC    CCC      CCC    CC",
		" CC              CC              CC         ",
		"              CC              CC            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"                                            ",
		"  I         I              I     I          ",
		"  I         I              I     I          ",
		"  I         I              I     I          ",
		"  I         I              I     I          ",
		"  I         I              I     I          ",
		"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
		"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
		"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
		"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
	};
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 'C')
				tiles.push_back(new Tile(j, i, 21, 1));
			else if (map[i][j] == 'G')
				tiles.push_back(new Tile(j, i, 1, 1));
			else if (map[i][j] == ' ')
				continue;//tiles.push_back(new Tile(j, i, 20, 0));
			else if (map[i][j] == 'I')
				tiles.push_back(new Tile(j, i, 17, 1));
		}
	}
	//sf::View view(sf::FloatRect(0.0f, 0.0f, 1366.f, 768.f));
	
}


Game::~Game()
{
	delete player;
	for (auto t : tiles)
	{
		delete t;
	}
	delete window;
}

void Game::Start()
{
	sf::Clock timer;
	float deltaTime = 0.0f;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(window->getSize()));
	while (window->isOpen())
	{
		sf::Event event;
		deltaTime = timer.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		view.setCenter(player->GetPosition().x, window->getSize().y / 2);
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: 
				window->close();
				break;
			case sf::Event::Resized:
				ResizeWindow(*window, view);
				break;
			}
		}
		

		
		
		player->Update(deltaTime);
		sf::Vector2f direction;
		for (auto &t : tiles)
		{
			if (player->GetCollider().CheckCollision(&t->GetCollider(), direction, 1.0f))
				player->OnCollision(direction);
		}
		

		window->clear(sf::Color(114,201,207));
		window->setView(view);

		player->Draw(*window);
		for (auto t : tiles)
		{
			t->Draw(*window);
		}


		window->display();
	}
}
