#pragma once

#include "Renderable.hpp"
#include "Renderer.hpp"
#include <array>

class Score : public Renderable
{
public:
	//This is not initialize properly when using constructor
	//Calling separate Init function from outside to circumvent this until I figure out why this isn't initializing properly
	std::array<sf::RectangleShape*, 7> scoreSegments;

	sf::RectangleShape topSegment;
	sf::RectangleShape midSegment;
	sf::RectangleShape botSegment;

	sf::RectangleShape leftTopSegment;
	sf::RectangleShape leftBotSegment;

	sf::RectangleShape rightTopSegment;
	sf::RectangleShape rightBotSegment;

	int points = 8;

public:
	Score();
	Score(sf::Vector2f position);
	void Increase();
	int GetPoints();
	virtual void Draw(Renderer* renderer) override;
	void InitScoreSegments();

private:
	void UpdateScoreVisual(const int& scorePoints);

};