#include <SFML/Graphics.hpp>

#include "Game.h"

Game game;

int main()
{
	while (!game.ShouldClose())
	{
		game.Event();
		game.Update();
		game.Render();
	}

	return 0;
}