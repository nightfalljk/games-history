#pragma once

#include <array>
#include <SFML/Graphics.hpp>

#include "Renderable.hpp"

class MiddleLine : public Renderable
{
private:
	std::array<sf::RectangleShape, 10> lineSegments;

public:
	MiddleLine();
	virtual void Draw(Renderer* renderer) override;
};