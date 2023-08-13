#include "Ball.hpp"
#include "../Utility/VectorMath2D.h"

Ball::Ball(const sf::Vector2f& position,
	sf::Color color,
	const sf::Vector2f& size,
	const float& initSpeed,
	const float& speedUpFactor,
	const int& upperScreenEdge,
	const int& lowerScreenEdge) :
	shape(size),
	moveDir(sf::Vector2f(1.f, 0.f)),
	spawnPosition(position),
	moveSpeed(initSpeed),
	initSpeed(initSpeed),
	speedUpFactor(speedUpFactor)
{
	shape.setFillColor(color);
	shape.setOrigin(size.x / 2.f, size.y / 2.f);
	shape.setPosition(position);
	upperBound = upperScreenEdge + shape.getOrigin().y;
	lowerBound = lowerScreenEdge - shape.getOrigin().y;
}

void Ball::Move(const float& deltaTime)
{
	sf::Vector2f ballPos = shape.getPosition();
	ballPos += moveDir * moveSpeed * deltaTime;
	shape.setPosition(ballPos);

	if (shape.getPosition().y < upperBound)
	{
	//Ball reflected at top edge normal
		moveDir -= 2 * VectorMath2D::Dot(topNormal, moveDir) * topNormal;
	}
	else if (shape.getPosition().y > lowerBound)
	{
		moveDir -= 2 * VectorMath2D::Dot(bottomNormal, moveDir) * bottomNormal;
	}
}
void Ball::Reset()
{
	//TODO: Need to set direction
	moveSpeed = initSpeed;
	shape.setPosition(spawnPosition);
	moveDir = moveDir.x < 0 ? rightDir : leftDir;
}
void Ball::Draw(Renderer* renderer)
{
	renderer->GetRenderWindow().draw(shape);
}

void Ball::SetDir(const sf::Vector2f dir)
{
	moveDir = VectorMath2D::Normalize(dir);
}
void Ball::IncreaseSpeed()
{
	moveSpeed *= speedUpFactor;
}
const sf::Vector2f& Ball::GetPosition()
{
	return shape.getPosition();
}

const sf::RectangleShape& Ball::GetShape()
{
	return shape;
}