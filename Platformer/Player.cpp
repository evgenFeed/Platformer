#include "Player.h"


Player::Player(sf::FloatRect rectangle)
{
	dx = 0, dy = 0;
	currentFrame = 0;
	this->rect = rectangle;
	texture.loadFromFile("Textures/moving.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(rect.left , rect.top);
	sprite.setScale(2, 2);
	onGround = false;
	isMoving = false;
	isJumping = false;
}


Player::~Player()
{
	
}

void Player::move()
{
	bool up = false;
	bool left = false, right = false;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !left)
	{
		dx = 0.1f;
		right = true;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !right)
	{
		dx = -0.1f;
		left = true;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (onGround == true)
		{
			dy = -0.3f;
			up = true;
			isJumping = true;
		}
	}
}


void Player::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

sf::Sprite & Player::getSprite()
{
	return sprite;
}

void Player::update(sf::Sprite &ground, float time)
{
	
	move();
	if (onGround == false)
	{
		dy += G * time;
	}
	rect.left += dx * time;
	rect.top += dy * time;

	currentFrame += 0.005f * time;

	if (currentFrame > 4.005f)
		currentFrame = 0;
	if (dx > 0)
		sprite.setTextureRect(sf::IntRect(int(currentFrame) * 32, 0, 32, 32));
	if (dx < 0)
		sprite.setTextureRect(sf::IntRect(int(currentFrame) * 32 + rect.height, 0, -32, 32));
	if (isJumping && dx > 0)
	{
		if (dy < 0)
			sprite.setTextureRect(sf::IntRect(int(currentFrame+4) * 32, 0, 32, 32));
		else if (dy > 0)
			sprite.setTextureRect(sf::IntRect(int(currentFrame + 8) * 32, 0, 32, 32));
	}
	if (isJumping && dx < 0)
	{
		if (dy < 0)
			sprite.setTextureRect(sf::IntRect(int(currentFrame + 4) * 32 + rect.height, 0, -32, 32));
		else if (dy > 0)
			sprite.setTextureRect(sf::IntRect(int(currentFrame + 8) * 32 + rect.height, 0, -32, 32));
	}



	if (dx == 0)
		isMoving = false;
	
	if (isMoving == false)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	
	sprite.setPosition(rect.left, rect.top);
	intersectGround(ground);

	dx = 0;
	if (onGround)
	{
		dy = 0;
	}
}

void Player::intersectGround(sf::Sprite &something)
{
	if (sprite.getGlobalBounds().intersects(something.getGlobalBounds()))
	{
		setOnGround(true);
	}
	else
		setOnGround(false);
}

void Player::setOnGround(bool onGround)
{
	this->onGround = onGround;
}
