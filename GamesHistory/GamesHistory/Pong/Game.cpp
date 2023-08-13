#include "Game.hpp"

Game::Game() : 
	renderer(640, 480, "A History of Games", sf::Color::Black),
	playerOneSpawnPosition(20.f, 480.f / 2.f),
	playerTwoSpawnPosition(620.f, 480.f / 2.f),
	playerOneScorePosition(160.f, 50.f),
	playerTwoScorePosition(480.f, 50.f),
	playerSize(20.f, 70.f),
	upperScreenEdge(0),
	lowerScreenEdge(480),
	playerMoveSpeed(300.f),
	clock(),
	elapsedTime(clock.restart())
{
	playerOne = Player(
		playerOneSpawnPosition,
		sf::Color::White,
		playerSize,
		playerMoveSpeed,
		upperScreenEdge,
		lowerScreenEdge);
	playerTwo = Player(
		playerTwoSpawnPosition,
		sf::Color::White,
		playerSize,
		playerMoveSpeed,
		upperScreenEdge,
		lowerScreenEdge);
	ball = Ball(
		ballSpawnPosition,
		ballColor,
		ballSize,
		ballSpeed,
		ballSpeedUpFactor,
		upperScreenEdge,
		lowerScreenEdge);

	playerOneScore = Score(playerOneScorePosition);
	playerTwoScore = Score(playerTwoScorePosition);

	playerOne.SetScore(&playerOneScore);
	playerTwo.SetScore(&playerTwoScore);

	playerOneScore.InitScoreSegments();
	playerTwoScore.InitScoreSegments();
	


	gameEnded = false;


}

void Game::Run()
{
	renderer.GetRenderWindow().setFramerateLimit(60);

	


	while (renderer.GetRenderWindow().isOpen() && !gameEnded)
	{
		sf::Event event;
		while (renderer.GetRenderWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				renderer.GetRenderWindow().close();
			}
		}

		elapsedTime += clock.restart();
		while (elapsedTime >= update_ms)
		{
			//Player Input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
			{
				playerOne.Move(upDir, update_ms.asSeconds());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
			{
				playerOne.Move(downDir, update_ms.asSeconds());
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
			{
				playerTwo.Move(upDir, update_ms.asSeconds());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
			{
				playerTwo.Move(downDir, update_ms.asSeconds());
			}

			//Ball Movement
			ball.Move(update_ms.asSeconds());


			//TODO: Create some sort of Collision Interface for classes to implement
			//Case: Ball hits paddle
			if (playerOne.CollidesWith(ball.GetShape()))
			{
				//TODO: Direction setting could work differently
				ball.SetDir(ball.GetPosition() - playerOne.GetPosition());
				ball.IncreaseSpeed();
			}
			else if (playerTwo.CollidesWith(ball.GetShape()))
			{
				ball.SetDir(ball.GetPosition() - playerTwo.GetPosition());
				ball.IncreaseSpeed();
			}
			//Case: Ball hits left or right -> Scoring
			else if (ball.GetPosition().x < 0)
			{
				playerTwo.IncreaseScore();
				//ballDir = sf::Vector2f(-1.f, 0.f);
				ball.Reset();
			}
			else if (ball.GetPosition().x > 640)
			{
				playerOne.IncreaseScore();
				//ballDir = sf::Vector2f(1.f, 0.f);
				ball.Reset();
			}

			if (playerOne.CheckWinCondition() || playerTwo.CheckWinCondition())
			{
				gameEnded = true;
			}


			elapsedTime -= update_ms;
		}

		Render();

	}
}


void Game::Render()
{
	renderer.Clear();
	middleLine.Draw(&renderer);
	playerOne.Draw(&renderer);
	playerTwo.Draw(&renderer);
	playerOneScore.Draw(&renderer);
	playerTwoScore.Draw(&renderer);
	ball.Draw(&renderer);
	renderer.Display();
}