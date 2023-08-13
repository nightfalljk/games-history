#pragma once

#include <SFML/Graphics.hpp>


#include "Renderable.hpp"
#include "Score.hpp"

class Player : public Renderable
{
private:
	Score* score = nullptr;
	sf::RectangleShape shape;
	sf::FloatRect scoreZone;
	float moveSpeed{};
	float upperBound{};
	float lowerBound{};
public:
	Player();
	Player(
		const sf::Vector2f& position,
		sf::Color color,
		const sf::Vector2f& size,
		const float& speed,
		const int& upperScreenEdge,
		const int& lowerScreenEdge
	);
	virtual void Draw(Renderer* renderer) override;
	void Move(const sf::Vector2f& moveDir, float deltaTime);
	sf::Vector2f GetPosition();
	bool CollidesWith(const sf::RectangleShape& other);
	void IncreaseScore();
	bool CheckWinCondition();
	Score* GetScore();
	void SetScore(Score* score);
};