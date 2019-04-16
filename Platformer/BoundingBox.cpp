#include "BoundingBox.h"



BoundingBox::BoundingBox()
{
	
}


BoundingBox::~BoundingBox()
{
}

bool BoundingBox::Intersects(const BoundingBox & other, sf::Vector2f &direction) const
{
	return
		(min.x < other.max.x) && (max.x > other.min.x) &&
		(min.y < other.max.y) && (max.y > other.min.y);
}

void BoundingBox::directionOfIntersect(const BoundingBox & other, sf::Vector2f &direction) const
{
	if (max.y >= other.min.y)
		direction.y = 1.0f;
	else if (min.y <= other.max.y)
		direction.y = -1.0f;
	else
		direction.y = 0;
	if (max.x >= other.min.x && min.x < other.min.x)
		direction.x = 1.0f;
	else if (min.x <= other.max.x && max.x > other.max.x)
		direction.x = -1.0f;
	else
		direction.x = 0;
}

void BoundingBox::setMinMax(sf::Vector2f min, sf::Vector2f max)
{
	this->min = min;
	this->max = max;
}

void BoundingBox::setMinMax(float minX, float minY, float maxX, float maxY)
{
	min.x = minX;
	min.y = minY;
	max.x = maxX;
	max.y = maxY;
}

void BoundingBox::setMinMax(sf::FloatRect rect)
{
	min.x = rect.left;
	min.y = rect.top;
	max.x = rect.left + rect.width;
	max.y = rect.top + rect.height;
}
