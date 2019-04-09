#include "Game.h"

Game::Game()
{
	this->state = new MainMenu();
	this->state->Initialize(this->window = new sf::RenderWindow(sf::VideoMode(1024, 600), "Memory"));
	this->quit = false;
}

Game::~Game()
{
	delete this->state;
	delete this->window;
}

void Game::SetState(State * state)
{
	if (this->state != nullptr)
		this->state->Destroy();

	this->state = state;

	if (this->state != nullptr)
		this->state->Initialize(window);
}

bool Game::ShouldClose()
{
	if (this->quit)
	{
		this->window->close();
		this->state->Destroy();
	}

	return this->quit;
}

void Game::Quit()
{
	this->quit = true;
}

void Game::Event()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		this->state->Event(this->window, event);
	}
}

void Game::Update()
{
	this->state->Update(this->window);
}

void Game::Render()
{
	this->state->Render(this->window);
}