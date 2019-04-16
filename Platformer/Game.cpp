#include "Game.h"



static const float VIEW_HEIGHT = 768;
static const float VIEW_WIDTH = 1366;

void ResizeWindow(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

Game::Game() :
	mTexturesHolder()
{
	window = new sf::RenderWindow(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Platformer");
	mTexturesHolder.load(Textures::Player, "Textures/player.png");
	player = new Player(mTexturesHolder.get(Textures::Player) , sf::Vector2u(4, 4), 0.5f, 150.f, 150.f);
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

void Game::run()
{
	
	sf::Clock timer;
	
	while (window->isOpen())
	{
		processEvents();
		update(timer.restart());
		render();
	}
}

void Game::processEvents()
{	
	sf::Event event;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(window->getSize()));
	view.setCenter(player->GetPosition().x, window->getSize().y / 2);
	window->setView(view);
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
}

void Game::update(sf::Time deltaTime)
{
	
	float dt = deltaTime.asSeconds();
	if (deltaTime.asSeconds() > 1.0f / 600.0f)
		dt = 1.0f / 600.0f;
	player->Update(dt, tiles);
	for (auto &t : tiles)
	{
		if (player->box.Intersects(t->box, player->GetDirection()))
			player->box.directionOfIntersect(t->box, player->GetDirection());
	}
}

void Game::render()
{
	window->clear(sf::Color(114, 201, 207));

	player->Draw(*window);
	for (auto t : tiles)
	{
		t->Draw(*window);
	}

	window->display();
}
