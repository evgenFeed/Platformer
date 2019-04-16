#pragma once
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "Tile.h"
#include "Animation.h"
#include "BoundingBox.h"


class Player
{
public:
						Player(sf::Texture texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
						~Player();

	void				Draw(sf::RenderWindow &window);
	//void				OnCollision(sf::Vector2f direction);
	void				Update(float &deltaTime, std::vector<Tile*> tiles);

	sf::Vector2f		GetPosition();
	sf::Vector2f&		GetDirection();
	//Collider			GetCollider() { return Collider(body); }
private:
	void				CheckCollision();
public:

	BoundingBox			box;
private:
	sf::Sprite			body;
	bool				faceRight;
	unsigned int		row;
	float				speed;
	Animation			animation;

	sf::Vector2f		direction;
	sf::Vector2f		velocity;
	bool				canJump;
	float				jumpHeight;

	const float			G = 98.1f;
};

