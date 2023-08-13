#include "Score.hpp"
#include <iostream>

Score::Score()
{
	sf::Vector2f horizontalSegmentDimensions(40.f, 10.f);
	sf::Vector2f verticalTopSegmentDimensions(10.f, 40.f);
	sf::Vector2f verticalBotSegmentDimensions(10.f, 30.f);

	topSegment.setSize(horizontalSegmentDimensions);
	midSegment.setSize(horizontalSegmentDimensions);
	botSegment.setSize(horizontalSegmentDimensions);

	leftTopSegment.setSize(verticalTopSegmentDimensions);
	leftBotSegment.setSize(verticalBotSegmentDimensions);

	rightTopSegment.setSize(verticalTopSegmentDimensions);
	rightBotSegment.setSize(verticalBotSegmentDimensions);

	midSegment.setPosition(sf::Vector2f(-20.f, 5.f));
	leftTopSegment.setPosition(sf::Vector2f(-20.f, -25.f));
	leftBotSegment.setPosition(sf::Vector2f(-20.f, 15.f));

	rightTopSegment.setPosition(sf::Vector2f(10.f, -25.f));
	rightBotSegment.setPosition(sf::Vector2f(10.f, 15.f));

	topSegment.setPosition(sf::Vector2f(-20.f, -25.f));
	botSegment.setPosition(sf::Vector2f(-20.f, 35.f));

	topSegment.setFillColor(sf::Color::White);
	midSegment.setFillColor(sf::Color::Transparent);
	botSegment.setFillColor(sf::Color::White);
	leftTopSegment.setFillColor(sf::Color::White);
	leftBotSegment.setFillColor(sf::Color::White);
	rightTopSegment.setFillColor(sf::Color::White);
	rightBotSegment.setFillColor(sf::Color::White);
	InitScoreSegments();
}

Score::Score(sf::Vector2f position)
{
	sf::Vector2f horizontalSegmentDimensions(40.f, 10.f);
	sf::Vector2f verticalTopSegmentDimensions(10.f, 40.f);
	sf::Vector2f verticalBotSegmentDimensions(10.f, 30.f);

	topSegment.setSize(horizontalSegmentDimensions);
	midSegment.setSize(horizontalSegmentDimensions);
	botSegment.setSize(horizontalSegmentDimensions);

	leftTopSegment.setSize(verticalTopSegmentDimensions);
	leftBotSegment.setSize(verticalBotSegmentDimensions);

	rightTopSegment.setSize(verticalTopSegmentDimensions);
	rightBotSegment.setSize(verticalBotSegmentDimensions);

	midSegment.setPosition(position + sf::Vector2f(-20.f, 5.f));
	leftTopSegment.setPosition(position + sf::Vector2f(-20.f, -25.f));
	leftBotSegment.setPosition(position + sf::Vector2f(-20.f, 15.f));

	rightTopSegment.setPosition(position + sf::Vector2f(10.f, -25.f));
	rightBotSegment.setPosition(position + sf::Vector2f(10.f, 15.f));

	topSegment.setPosition(position + sf::Vector2f(-20.f, -25.f));
	botSegment.setPosition(position + sf::Vector2f(-20.f, 35.f));

	topSegment.setFillColor(sf::Color::White);
	midSegment.setFillColor(sf::Color::Transparent);
	botSegment.setFillColor(sf::Color::White);
	leftTopSegment.setFillColor(sf::Color::White);
	leftBotSegment.setFillColor(sf::Color::White);
	rightTopSegment.setFillColor(sf::Color::White);
	rightBotSegment.setFillColor(sf::Color::White);

	points = 0;
	UpdateScoreVisual(points);
	InitScoreSegments();
}

void Score::Increase()
{
	++points;
	UpdateScoreVisual(points);

}

int Score::GetPoints()
{
	return points;
}

void Score::Draw(Renderer* renderer)
{
	for (int i = 0; i < scoreSegments.size(); ++i)
	{
		renderer->GetRenderWindow().draw(*scoreSegments[i]);
	}
}

void Score::InitScoreSegments()
{
	scoreSegments[0] = &topSegment;
	scoreSegments[1] = &midSegment;
	scoreSegments[2] = &botSegment;
	scoreSegments[3] = &leftBotSegment;
	scoreSegments[4] = &leftTopSegment;
	scoreSegments[5] = &rightBotSegment;
	scoreSegments[6] = &rightTopSegment;
}

void Score::UpdateScoreVisual(const int& scorePoints)
{
	switch (points)
	{
	case 1:
		topSegment.setFillColor(sf::Color::Transparent);
		midSegment.setFillColor(sf::Color::Transparent);
		botSegment.setFillColor(sf::Color::Transparent);
		leftTopSegment.setFillColor(sf::Color::Transparent);
		leftBotSegment.setFillColor(sf::Color::Transparent);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 2:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::White);
		leftTopSegment.setFillColor(sf::Color::Transparent);
		leftBotSegment.setFillColor(sf::Color::White);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::Transparent);
		break;
	case 3:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::White);
		leftTopSegment.setFillColor(sf::Color::Transparent);
		leftBotSegment.setFillColor(sf::Color::Transparent);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 4:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::Transparent);
		leftTopSegment.setFillColor(sf::Color::White);
		leftBotSegment.setFillColor(sf::Color::Transparent);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 5:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::White);
		leftTopSegment.setFillColor(sf::Color::White);
		leftBotSegment.setFillColor(sf::Color::Transparent);
		rightTopSegment.setFillColor(sf::Color::Transparent);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 6:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::White);
		leftTopSegment.setFillColor(sf::Color::White);
		leftBotSegment.setFillColor(sf::Color::White);
		rightTopSegment.setFillColor(sf::Color::Transparent);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 7:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::Transparent);
		botSegment.setFillColor(sf::Color::Transparent);
		leftTopSegment.setFillColor(sf::Color::Transparent);
		leftBotSegment.setFillColor(sf::Color::Transparent);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 8:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::White);
		leftTopSegment.setFillColor(sf::Color::White);
		leftBotSegment.setFillColor(sf::Color::White);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	case 9:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::White);
		botSegment.setFillColor(sf::Color::Transparent);
		leftTopSegment.setFillColor(sf::Color::White);
		leftBotSegment.setFillColor(sf::Color::Transparent);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	default:
		topSegment.setFillColor(sf::Color::White);
		midSegment.setFillColor(sf::Color::Transparent);
		botSegment.setFillColor(sf::Color::White);
		leftTopSegment.setFillColor(sf::Color::White);
		leftBotSegment.setFillColor(sf::Color::White);
		rightTopSegment.setFillColor(sf::Color::White);
		rightBotSegment.setFillColor(sf::Color::White);
		break;
	}
}