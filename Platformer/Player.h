#pragma once
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"

class Player
{
public:
	Player(sf::FloatRect rectangle);
	~Player();
	void move();
	float currentFrame = 0;
	float dx, dy;
	void draw(sf::RenderWindow &window);
	sf::FloatRect rect;
	sf::Sprite &getSprite();
	void update(sf::Sprite &ground, float time);
	void intersectGround(sf::Sprite &something);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	bool onGround;
	bool isMoving;
	bool isJumping;
	const float G = 0.0005f;
	void setOnGround(bool onGround);
};

