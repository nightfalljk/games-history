#include "Renderer.hpp"

Renderer::Renderer(int screenWidth, int screenHeight, std::string windowName, sf::Color bgColor) :
	renderWindow(sf::VideoMode(screenWidth, screenHeight), windowName, sf::Style::Close),
	backgroundColor(bgColor)
{
	renderWindow.setActive(true);
}

void Renderer::Clear()
{
	renderWindow.clear(backgroundColor);
}

void Renderer::Display()
{
	renderWindow.display();
}

sf::RenderWindow& Renderer::GetRenderWindow()
{
	return renderWindow;
}
