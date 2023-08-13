#include "VectorMath2D.h"

sf::Vector2f VectorMath2D::Normalize(sf::Vector2f vec)
{
	float length = vec.x * vec.x + vec.y * vec.y;
	if (length == 0)
		return vec;
	length = sqrtf(length);
	vec  = sf::Vector2f(vec.x / length, vec.y / length);
	return vec;
}
float VectorMath2D::Dot(const sf::Vector2f& vecA, const sf::Vector2f& vecB)
{
	return vecA.x * vecB.x + vecA.y * vecB.y;
}