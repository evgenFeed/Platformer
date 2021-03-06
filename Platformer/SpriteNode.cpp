#include "SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture & texture):
	mSprite(texture)
{
}

SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rect):
	mSprite()
{
	mSprite.setTexture(texture);
	mSprite.setTextureRect(rect);
}

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
