#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "MainMenu.h"
#include "MainGame.h"

class Game
{
public:
	Game();
	~Game();

	void SetState(State* state);
	bool ShouldClose();
	void Quit();

	void Event();
	void Update();
	void Render();

private:
	sf::RenderWindow* window;
	State* state;
	bool quit;
};