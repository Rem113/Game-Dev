#include "MainGame.h"

#include <random>
#include <algorithm>

const float MARGIN_X = 10.0f;
const float MARGIN_Y = 10;

const unsigned int TILES_X = 10;
const unsigned int TILES_Y = 7;

extern Game game;

void MainGame::Initialize(sf::RenderWindow * window)
{
	this->shapes = {Symbol::Shapes::Donut, Symbol::Shapes::Square, Symbol::Shapes::Diamond, Symbol::Shapes::Circle, Symbol::Shapes::Ellipse};
	this->colors = {Symbol::Colors::Red, Symbol::Colors::Green, Symbol::Colors::Blue, Symbol::Colors::Yellow, Symbol::Colors::Orange, Symbol::Colors::Purple, Symbol::Colors::Cyan};

	this->revealedCount = 0;

	for (unsigned int i = 0; i < this->shapes.size(); ++i)
		for (unsigned int j = 0; j < this->colors.size(); ++j)
			this->symbols.push_back(new Symbol{this->shapes.at(i), this->colors.at(j)});

	sf::Vector2f cardSize((window->getSize().x - MARGIN_X) / TILES_X - MARGIN_X, (window->getSize().y - MARGIN_Y) / TILES_Y - MARGIN_Y);

	this->cards.resize(TILES_X);

	for (int i = 0; i < TILES_X; ++i)
		this->cards[i].resize(TILES_Y);

	for (unsigned int i = 0; i < TILES_X; ++i)
	{
		for (unsigned int j = 0; j < TILES_Y; ++j)
		{
			this->cards[i][j].setPosition(sf::Vector2f(i * (cardSize.x + MARGIN_X) + MARGIN_X, j * (cardSize.y + MARGIN_Y) + MARGIN_Y));
			this->cards[i][j].setSize(cardSize);
			this->cards[i][j].toggle();
		}
	}

	std::random_device rd;
	std::mt19937 random(rd());

	std::shuffle(this->shapes.begin(), this->shapes.end(), random);
	std::shuffle(this->colors.begin(), this->colors.end(), random);

	

	for (unsigned int i = 0; i < this->shapes.size(); ++i)
	{
		for (unsigned int j = 0; j < this->colors.size(); ++j)
		{

		}
	}

	sf::CircleShape circle(cardSize.x / 4);

	sf::CircleShape donut(cardSize.x / 4);
	donut.setFillColor(sf::Color::Transparent);
	donut.setOutlineThickness(-cardSize.x / 8);

	sf::RectangleShape diamond(sf::Vector2f(cardSize.x / 2.8f, cardSize.x / 2.8f));
	diamond.rotate(45.0f);

	sf::RectangleShape square(sf::Vector2f(cardSize.x / 2, cardSize.x / 2));

	sf::CircleShape ellipse(cardSize.x / 6.0f);
	ellipse.setScale(sf::Vector2f(2.0f, 1.0f));
}

void MainGame::Event(sf::RenderWindow * window, sf::Event event)
{
	if (event.type == sf::Event::Closed)
		game.Quit();

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		for (unsigned int i = 0; i < this->cards.size(); ++i)
		{
			for (unsigned int j = 0; j < this->cards[i].size(); ++j)
			{
				if (this->cards[i][j].collides(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					this->cards[i][j].toggle();

					++this->revealedCount;

					std::vector<Card> temp;
					temp.resize(2);

					if (this->revealedCount == 2)
					{
						for (unsigned int a = 0; a < TILES_X; ++a)
						{
							for (unsigned int b = 0; b < TILES_Y; ++b)
							{
								if (this->cards[a][b].isRevealed())
									temp.push_back(this->cards[a][b]);
							}
						}

						this->revealedCount = 0;
					}

					if (temp[0].getSymbol() == temp[1].getSymbol())
					{
						// Paire
					}

					else
					{
						temp[0].toggle();
						temp[1].toggle();
					}
				}
			}
		}
	}
}

void MainGame::Update(sf::RenderWindow * window)
{
}

void MainGame::Render(sf::RenderWindow * window)
{
	window->clear(sf::Color(0, 153, 188));

	for (unsigned int i = 0; i < TILES_X; ++i)
	{
		for (unsigned int j = 0; j < TILES_Y; ++j)
		{
			window->draw(this->cards[i][j]);
		}
	}

	window->display();
}

void MainGame::Destroy()
{
}
