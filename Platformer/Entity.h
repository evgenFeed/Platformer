#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "SceneNode.h"

class Entity : public SceneNode
{
public: //typedef
	

public: //functions
	virtual void	setVelocity(sf::Vector2f velocity);
	virtual void	setVelocity(float vx, float vy);
	sf::Vector2f	getVelocity() const;
	virtual void	drawCurrent(sf::RenderTarget& target,
								sf::RenderStates states) const = 0;
	
private: //functions
	virtual void	updateCurrent(sf::Time dt);
private: //fields
	sf::Vector2f	mVelocity;
	//sf::Vector2f	mPosition;
};

