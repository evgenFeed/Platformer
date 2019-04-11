#pragma once
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"
#include "Tile.h"
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Draw(sf::RenderWindow &window);
	void OnCollision(sf::Vector2f direction);
	void Update(float &deltaTime);

	sf::Vector2f GetPosition();
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	bool faceRight;
	unsigned int row;
	float speed;
	Animation animation;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

	const float G = 981.0f;
};

