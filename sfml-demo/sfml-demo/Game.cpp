#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"


Game::Game()
{
	this->window.create(sf::VideoMode(640, 480), "MathGame");
	this->window.setFramerateLimit(60);
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
	//delete this->states.top(); //hajottaa ohjelman, mutta voi olla muistinhallinan kannalta tärkeä
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





//#include "Game.h"
//#include "GameState.h"
//
////#include <stdio.h>
//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//
//void Game::init(const char* title, int width, int height, bool fscreen)
//{
//	this->window.create(sf::VideoMode(width, height), title);
//	this->window.setFramerateLimit(60);
//
//	titleName = title;
//	windowWidth = width;
//	windowHeight = height;
//	fullscreen = fscreen;
//	running = true;
//
//	std::cout << "Game init" << std::endl;
//}
//
//void Game::cleanup()
//{
//	//cleanup all the states
//	while (!states.empty())
//	{
//		states.back()->cleanup();
//		states.pop_back();
//	}
//
//	// switch back to windowed mode so other 
//	// programs won't get accidentally resized
//	//En tiedä tarvitseeko sfml:ssä
//
//	std::cout << "Game cleanup" << std::endl;
//
//	//sfml quit
//}
//
//void Game::changeState(GameState* state)
//{
//	if (!states.empty())
//	{
//		states.back()->cleanup();
//		states.pop_back();
//	}
//
//	states.push_back(state);
//	states.back()->init();
//}
//
//void Game::pushState(GameState* state)
//{
//	if (!states.empty())
//	{
//		states.back()->pause();
//	}
//
//	states.push_back(state);
//	states.back()->init();
//}
//
//void Game::popState()
//{
//	if (!states.empty())
//	{
//		states.back()->cleanup();
//		states.pop_back();
//	}
//
//	if (!states.empty())
//	{
//		states.back()->resume();
//	}
//}
//
//void Game::handleEvents()
//{
//	states.back()->handleInput(this);
//}
//
//void Game::update()
//{
//	states.back()->update(this);
//}
//
//void Game::draw()
//{
//	states.back()->draw(this);
//}
