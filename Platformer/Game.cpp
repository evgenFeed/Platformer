#include "Game.h"



static const float VIEW_HEIGHT = 768;
static const float VIEW_WIDTH = 1366;

void ResizeWindow(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

Game::Game() :
	mWindow{ sf::VideoMode(1366,768), "Platformer" },
	mWorld(mWindow)
{
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
}


Game::~Game()
{
	for (auto t : tiles)
	{
		delete t;
	}
}

void Game::run()
{
	
	sf::Clock timer;
	
	while (mWindow.isOpen())
	{
		processEvents();
		update(timer.restart());
		render();
	}
}

void Game::processEvents()
{	
	sf::Event event;
	//view.setCenter(player->GetPosition().x, window->getSize().y / 2);
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: 
			mWindow.close();
			break;
		case sf::Event::Resized:
			//ResizeWindow(*window, view);
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	mWorld.update(deltaTime);
}

void Game::render()
{
	mWindow.clear();

	mWorld.draw();
	/*for (auto t : tiles)
	{
		t->Draw(*window);
	}*/

	mWindow.display();
}
