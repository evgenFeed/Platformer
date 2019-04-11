#include "Player.h"
#include <iostream>


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation{ texture, imageCount, switchTime }
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	canJump = false;

	body.setSize(sf::Vector2f(32.0f, 32.0f));
	body.setTexture(texture);
	body.setPosition(sf::Vector2f(683.0f,500.0f));
	body.setOrigin(body.getSize() / 2.0f);
	
}


Player::~Player()
{
	
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0; //collision on the left
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0; //collision on the right
	}

	if (direction.y < 0.0f)
	{
		velocity.y = 0; //collision on the bottom
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0; //collision on the top
	}
}

sf::Vector2f Player::GetPosition()
{
	return body.getPosition();
}

void Player::Update(float &deltaTime)
{
	velocity.x = 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * G * jumpHeight);
	}
	
	velocity.y += G * deltaTime;
	

	if (velocity.x == 0)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	
	/*if (abs(velocity.y) > 0)
	{
		if (velocity.y < 0.0f && velocity.x > 0.0f)
		{
			faceRight = true;
			row = 2;
		}
		else if (velocity.y < 0.0f && velocity.x < 0.0f)
		{
			faceRight = false;
			row = 2;
		}
		else if (velocity.y > 0.0f && velocity.x > 0.0f)
		{
			faceRight = true;
			row = 3;
		}
		else if (velocity.y > 0.0f && velocity.x < 0.0f)
		{
			faceRight = false;
			row = 3;
		}
	}*/

	

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);

	body.move(velocity * deltaTime);
}

