#include "Player.hpp"
#include <iostream>

Player::Player() {
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(0.f, 0.f);
	shape.setPosition(sf::Vector2f(0.f, 0.f));
	upperBound = 0;
	lowerBound = 0;
}

Player::Player(const sf::Vector2f& position,
	sf::Color color,
	const sf::Vector2f& size,
	const float& speed,
	const int& upperScreenEdge,
	const int& lowerScreenEdge
	) :
	shape(size),
	moveSpeed(speed)
{
	shape.setFillColor(color);
	shape.setOrigin(size.x / 2.f, size.y / 2.f);
	shape.setPosition(position);
	upperBound = upperScreenEdge - shape.getSize().y + shape.getOrigin().y;
	lowerBound = lowerScreenEdge + shape.getOrigin().y;
}


void Player::Draw(Renderer* renderer)
{
	renderer->GetRenderWindow().draw(shape);
}

void Player::Move(const sf::Vector2f& moveDir, float deltaTime)
{
	sf::Vector2f newPos = GetPosition();
	newPos += moveDir * (moveSpeed * deltaTime);
 
	//TODO: Rename lower and upper bound since variable naming and boolean logic are unintuitve/contradictory
	if (lowerBound >= newPos.y && newPos.y >= upperBound)
	{
		shape.setPosition(newPos);
	}
}

sf::Vector2f Player::GetPosition()
{
	return shape.getPosition();
}

bool Player::CollidesWith(const sf::RectangleShape& other)
{
	if (shape.getGlobalBounds().intersects(other.getGlobalBounds()))
		return true;

	return false;
}

void Player::IncreaseScore()
{
	score->Increase();
}

bool Player::CheckWinCondition()
{
	return score->GetPoints() == 10;
}

Score* Player::GetScore()
{
	return score;
}

void Player::SetScore(Score* score)
{
	this->score = score;
}