#include "MainMenu.h"

extern Game game;

void MainMenu::Initialize(sf::RenderWindow * window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("arial.ttf");

	this->title = new sf::Text("Memory", *this->font, window->getSize().x / 15);
	this->play = new sf::Text("New Game", *this->font, window->getSize().x / 30);
	this->quit = new sf::Text("Quit", *this->font, window->getSize().x / 30);

	this->title->setOrigin(sf::Vector2f(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2));
	this->title->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4));

	this->play->setOrigin(sf::Vector2f(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2));
	this->play->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 12 * 6));

	this->quit->setOrigin(sf::Vector2f(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2));
	this->quit->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 12 * 8));

	this->title->setColor(sf::Color::Black);
}

void MainMenu::Event(sf::RenderWindow * window, sf::Event event)
{
	if (event.type == sf::Event::Closed ||
		(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && this->selected == 1))
		game.Quit();

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && this->selected == 0)
		game.SetState(new MainGame());
}

void MainMenu::Update(sf::RenderWindow * window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->up)
		selected--;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->down)
		selected++;

	if (selected > 1)
		selected = 0;

	if (selected < 0)
		selected = 1;

	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void MainMenu::Render(sf::RenderWindow * window)
{
	window->clear(sf::Color::White);

	this->play->setColor(sf::Color(128, 128, 128, 64U));
	this->quit->setColor(sf::Color(128, 128, 128, 64U));

	switch (selected)
	{
	case 0:
		this->play->setColor(sf::Color(256, 256, 256, 128U));
		break;

	case 1:
		this->quit->setColor(sf::Color(256, 256, 256, 128U));
		break;
	}

	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);

	window->display();
}

void MainMenu::Destroy()
{
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
}
