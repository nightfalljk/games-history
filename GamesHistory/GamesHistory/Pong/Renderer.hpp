#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class Renderer
{

private:
	sf::RenderWindow renderWindow;
	sf::Color backgroundColor;

public:
	Renderer(int screenWidth, int screenHeight, std::string windowName, sf::Color bgColor);
	void Clear();
	void Display();
	sf::RenderWindow& GetRenderWindow();

};