#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Player.h"
#include <array>

class World : private sf::NonCopyable
{
public:
	explicit	World(sf::RenderWindow& window);
				~World();
	void		update(sf::Time dt);
	void		draw();
private:
	void		loadTextures();
	void		buildScene();
private:
	enum Layer
	{
		Background,
		Ground,
		LayerCount
	};
private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Player*								mPlayer;
};


