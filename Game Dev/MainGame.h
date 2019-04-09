#pragma once

#include "Game.h"
#include "Card.h"

#include <vector>

class MainGame : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Event(sf::RenderWindow* window, sf::Event event);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy();

private:
	std::vector<Symbol::Shapes> shapes;
	std::vector<Symbol::Colors> colors;
	std::vector<Symbol*> symbols;
	std::vector<std::vector<Card>> cards;
	int revealedCount;
};
