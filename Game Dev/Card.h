#pragma once

#include <SFML/Graphics.hpp>

struct Symbol
{
	enum Shapes { Circle, Square, Donut, Diamond, Ellipse };
	enum Colors { Red, Green, Blue, Yellow, Orange, Purple, Cyan };

	bool operator==(Symbol s)
	{
		return (this->shape == s.shape && this->color == s.color);
	}

	Symbol::Shapes shape;
	Symbol::Colors color;
};


class Card : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;
	bool revealed;
	Symbol symbol;

public:
	Card();

	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

	Symbol& getSymbol();
	void setSymbol(const Symbol& symbol);

	void toggle();
	bool isRevealed();

	bool collides(sf::Vector2f position);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
