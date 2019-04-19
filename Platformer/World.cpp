#include "World.h"



World::World(sf::RenderWindow& window) :
	mWindow(window),
	mWorldView(sf::FloatRect(0.0f, 0.0f, 1366.0f, 768.0f)),
	mWorldBounds(0.0f, 0.0f, 1366.0f, 768.0f),
	mSpawnPosition(50.0f, 700.0f),
	mPlayer(nullptr)
{
	loadTextures();
	buildScene();
	
	mWorldView.setCenter(mPlayer->getPosition());
	mWorldView.zoom(2);
}


World::~World()
{
}

void World::update(sf::Time dt)
{
	mWorldView.setCenter(mPlayer->getPosition());

	sf::Vector2f position = mPlayer->getPosition();
	sf::Vector2f velocity = mPlayer->getVelocity();

	/*if (position.x <= mWorldBounds.left)
	{
		velocity.x = -velocity.x;
		mPlayer->setVelocity(velocity);
	}*/
	mPlayer->update(dt);
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Player, "Textures/player.png");
	mTextures.load(Textures::Landscape, "Textures/landscape.png");
	mTextures.load(Textures::Background, "Textures/11_background.png");
}

void World::buildScene()
{
	
	for (size_t i = 0; i < LayerCount; i++)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& texture = mTextures.get(Textures::Background);
	sf::IntRect textureRect(mWorldBounds);
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Player> leader(new Player(Textures::Player, mTextures));
	mPlayer = leader.get();
	mPlayer->setPosition(mSpawnPosition);
	mPlayer->setVelocity(0.0f, 0.0f);
	mSceneLayers[Ground]->attachChild(std::move(leader));
}
