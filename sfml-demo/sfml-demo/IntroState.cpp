#include "IntroState.h"
#include "MenuState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

#include <iostream>

IntroState IntroState::introState;

void IntroState::init()
{
	

	std::cout << "IntroState init" << std::endl;
}

void IntroState::cleanup()
{


	std::cout << "IntroState cleanup" << std::endl;
}

void IntroState::pause()
{


	std::cout << "IntroState pause" << std::endl;
}

void IntroState::resume()
{
	
	
	std::cout << "IntroState resume" << std::endl;
}

void IntroState::handleInput(Game* game)
{

}

void IntroState::update(Game* game)
{

}

void IntroState::draw(Game* game)
{
	game->window.clear(sf::Color::Black);



	game->window.display();
}
