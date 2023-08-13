#pragma once

#include <SFML/Graphics.hpp>

#include "Renderable.hpp"

class Ball : public Renderable
{
private:
	sf::RectangleShape shape;
	sf::Vector2f moveDir;
	sf::Vector2f spawnPosition;
	sf::Vector2f topNormal = sf::Vector2f(0.f, -1.f);
	sf::Vector2f bottomNormal = sf::Vector2f(0.f, 1.f);
	sf::Vector2f leftDir = sf::Vector2f(-1.f, 0.f);
	sf::Vector2f rightDir = sf::Vector2f(1.f, 0.f);
	float moveSpeed{};
	float initSpeed{};
	float speedUpFactor{};
	float upperBound{};
	float lowerBound{};



public:
	Ball() {};
	Ball(const sf::Vector2f& position,
		sf::Color color,
		const sf::Vector2f& size,
		const float& initSpeed,
		const float& speedUpFactor,
		const int& upperScreenEdge,
		const int& lowerScreenEdge
	);
	void Move(const float& deltaTime);
	void Reset();
	virtual void Draw(Renderer* renderer) override;
	//TODO: Change to velocity vectors instead of directional vectors?
	void SetDir(const sf::Vector2f dir);
	void IncreaseSpeed();
	const sf::Vector2f& GetPosition();
	const sf::RectangleShape& GetShape();
};