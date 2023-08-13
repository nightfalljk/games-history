#include <iostream>
#include "Pong/Game.hpp"

int main()
{
	int i = 0;
	std::cout << "Welcome to a History of Games\n"
		<< "A history of games is a selection of classic video games implemented in C++ to get a better understanding of the language by Julius Krueger.\n"
		<< "Currently the only game available is 'Pong' for two players.\n" 
		<< "Press any key to play 'Pong'"
		<< std::endl;
	std::cin.get();
	Game game;
	game.Run();
}