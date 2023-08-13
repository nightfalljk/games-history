#include "MiddleLine.hpp"

MiddleLine::MiddleLine()
{
	//TODO: Use screen size as constructor dimensions
	int rsCount = 0;
	for (sf::RectangleShape& rs : lineSegments)
	{
		rs.setSize(sf::Vector2f(10.f, 10.f));
		rs.setFillColor(sf::Color::White);
		rs.setOrigin(5.f, 5.f);
		rs.setPosition(640.f / 2.f, 25 + rsCount * 480.f / 10.f);
		++rsCount;
	}

}

void MiddleLine::Draw(Renderer* renderer)
{
	for (sf::RectangleShape& rs : lineSegments)
	{
		renderer->GetRenderWindow().draw(rs);
	}

}
