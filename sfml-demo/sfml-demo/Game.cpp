#include "Game.h"
#include "GameState.h"


Game::Game()
{
	this->window.create(sf::VideoMode(640, 480), "MathGame");
	this->window.setFramerateLimit(60);
	this->window.setKeyRepeatEnabled(false);
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}


void Game::pushState(GameState* state)
{
	this->states.push(state);

	return;
}

void Game::popState()
{
	//delete this->states.top(); //hajottaa ohjelman, mutta voi olla muistinhallinan kannalta t�rke�
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);

	return;
}

GameState* Game::peekState()
{
	if (this->states.empty())
		return nullptr;
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr)
			continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}






