#pragma once

#include <SFML/Graphics.hpp>

#include "Renderer.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "MiddleLine.hpp"

class Game
{
private:
	Renderer renderer;
	Player playerOne;
	Player playerTwo;
	Ball ball;
	MiddleLine middleLine;

	sf::Clock clock;
	sf::Time elapsedTime;

	const sf::Vector2f upDir{0.f, -1.f};
	const sf::Vector2f downDir{0.f, 1.f};

	const sf::Vector2f playerOneSpawnPosition;
	const sf::Vector2f playerTwoSpawnPosition;
	const sf::Vector2f playerOneScorePosition;
	const sf::Vector2f playerTwoScorePosition;
	const int upperScreenEdge;
	const int lowerScreenEdge;
	const sf::Vector2f playerSize;
	const float playerMoveSpeed;

	Score playerOneScore;
	Score playerTwoScore;


	const sf::Vector2f ballSpawnPosition{640.f / 2.f, 480.f / 2.f};
	const sf::Vector2f ballSize{10.f, 10.f};
	const sf::Color ballColor{sf::Color::White};
	const sf::Time update_ms = sf::seconds(1.f / 60.f);

	const float ballSpeed = 250.f;
	const float ballSpeedUpFactor = 1.2f;


	bool gameEnded;

public:
	Game();
	void Run();

private:
	bool CheckGameEndCondition();
	void Render();
};