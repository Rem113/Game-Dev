#pragma once

#include "Game.h"

class MainMenu : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Event(sf::RenderWindow* window, sf::Event event);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy();

private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text* quit;

	int selected;
	bool up, down;
};