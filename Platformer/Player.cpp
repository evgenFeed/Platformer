#include "Player.h"
#include <iostream>


Player::Player(const TextureHolder & textures) :
	mBody(),
	mBox(),
	mAnimation{ textures.get(Textures::Player),sf::Vector2u(4,4),0.25f }
{
	mTexture = textures.get(Textures::Player);
	row = 0;
	faceRight = true;

	mBody.setTexture(this->mTexture);
	mBody.setPosition(sf::Vector2f(683.0f, 500.0f));
	mPosition = mBody.getPosition();
	sf::FloatRect bounds = mBody.getLocalBounds();
	mBody.setOrigin(bounds.width / 2, bounds.height / 2);
	mBox.setMinMax(mBody.getGlobalBounds());
}

Player::Player(Textures::ID id, const TextureHolder& textures) :
	mBody(),
	mAnimation{ textures.get(Textures::Player) , sf::Vector2u(4,4),0.3f },
	mBox()
{
	this->mTexture = textures.get(id);
	row = 0;
	faceRight = true;
	
	mBody.setTexture(this->mTexture);
	mBody.setTextureRect(mAnimation.uvRect);
//	mBody.setPosition(sf::Vector2f(683.0f,500.0f));
	mPosition = mBody.getPosition();
	sf::FloatRect bounds = mBody.getLocalBounds();
	mBody.setOrigin(bounds.width / 2, bounds.height / 2);
	mBox.setMinMax(mBody.getGlobalBounds());
}



void Player::setPosition(sf::Vector2f position)
{
	mPosition = position;
}

sf::Vector2f Player::getPosition()
{
	return mPosition;
}



void Player::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mBody, states);
}

void Player::updateCurrent(sf::Time dt)
{
	animationUpdate(dt);
	move(getVelocity() * dt.asSeconds());
}



void Player::animationUpdate(sf::Time &deltaTime)
{
	setVelocity(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		setVelocity(1.0f,getVelocity().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		setVelocity(-1.0f, getVelocity().y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//setVelocity(1.0f, getVelocity().y);
	}

	//velocity.y += G * deltaTime;

	//CheckCollision();
	//if (direction.y > 0)
	//{
	//	velocity.y = 0;
	//	canJump = true;
	//}
	if (getVelocity().x == 0)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (getVelocity().x > 0.0f)
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
	mBody.move(getVelocity());
	mAnimation.Update(row, deltaTime.asSeconds(), faceRight);
	mBody.setTextureRect(mAnimation.uvRect);
}

