#pragma once
#include "SFML\Graphics.hpp"
class BoundingBox
{
public:
					BoundingBox();
					~BoundingBox();
	bool			Intersects(const BoundingBox & other, sf::Vector2f &direction) const;
	void			directionOfIntersect(const BoundingBox & other, sf::Vector2f &direction) const;
	void			setMinMax(sf::Vector2f min, sf::Vector2f max);
	void			setMinMax(float minX, float minY, float maxX, float maxY);
	void			setMinMax(sf::FloatRect);
public:
	sf::Vector2f	min;
	sf::Vector2f	max;
};

