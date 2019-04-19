#pragma once
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "Tile.h"
#include "Animation.h"
#include "BoundingBox.h"
#include "Entity.h"

class Player : public Entity  // inherits indirectly SceneNode
{


public:
	explicit			Player(const TextureHolder& textures);
						Player(Textures::ID id, const TextureHolder& textures);
	void				animationUpdate(sf::Time &deltaTime);
	void				setPosition(sf::Vector2f position);
	sf::Vector2f		getPosition();
	virtual void		drawCurrent(sf::RenderTarget& target,
									sf::RenderStates states) const override;
	virtual void		updateCurrent(sf::Time dt) override;
private:
	
public:
	BoundingBox			mBox;
	Animation			mAnimation;
private:
	sf::Texture			mTexture;
	sf::Sprite			mBody;
	sf::Vector2f		mPosition;
	float				row;
	bool				faceRight;
	const float			G = 98.1f;
};

