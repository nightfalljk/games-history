#pragma once

#include <SFML/Graphics.hpp>

static class VectorMath2D
{
public:
	static sf::Vector2f Normalize(sf::Vector2f vec);
	static float Dot(const sf::Vector2f& vecA, const sf::Vector2f& vecB);
};