#include "Card.h"

Card::Card()
{
	this->revealed = true;
}

void Card::setPosition(sf::Vector2f position)
{
	this->rectangle.setPosition(position);
}

void Card::setSize(sf::Vector2f size)
{
	this->rectangle.setSize(size);
}

Symbol& Card::getSymbol()
{
	return this->symbol;
}

void Card::setSymbol(const Symbol & symbol)
{
	this->symbol = symbol;
}

void Card::toggle()
{
	if (!this->revealed)
	{
		this->revealed = true;
		this->rectangle.setFillColor(sf::Color::White);
	}

	else
	{
		this->revealed = false;
		this->rectangle.setFillColor(sf::Color::Transparent);
	}
}

bool Card::isRevealed()
{
	return this->revealed;
}

bool Card::collides(sf::Vector2f position)
{
	if (this->rectangle.getGlobalBounds().intersects(sf::FloatRect(position.x, position.y, 1.0f, 1.0f)))
		return true;

	return false;
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
}