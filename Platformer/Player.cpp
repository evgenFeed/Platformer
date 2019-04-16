#include "Player.h"
#include <iostream>


Player::Player(sf::Texture texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation{ texture, imageCount, switchTime },
	box()
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	canJump = false;

	//body.setSize(sf::Vector2f(32.0f, 32.0f));
	body.setTexture(texture);
	body.setPosition(sf::Vector2f(683.0f,500.0f));
	body.setOrigin(body.getLocalBounds().width / 2, body.getLocalBounds().height / 2);
	box.setMinMax(body.getGlobalBounds());
}


Player::~Player()
{
	
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}



sf::Vector2f Player::GetPosition()
{
	return body.getPosition();
}

sf::Vector2f& Player::GetDirection()
{
	return direction;
}

void Player::CheckCollision()
{
	bool movedX = false, movedY = false;
	if (direction.x > 0 || direction.x < 0 && movedX == false)
	{
		//velocity.x = -velocity.x;
		movedX = true;
	}
	if (direction.y < 0 && movedY == false)
	{
		velocity.y = -velocity.y;
		movedY = true;
	}
}

void Player::Update(float &deltaTime, std::vector<Tile*> tiles)
{
	box.setMinMax(this->body.getGlobalBounds());
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

	//CheckCollision();
	if (direction.y > 0)
	{
		velocity.y = 0;
		canJump = true;
	}


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

