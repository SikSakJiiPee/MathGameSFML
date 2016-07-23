#include "MenuState.h"
#include "MainGameState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

#include <iostream>

MenuState MenuState::menuState;

void MenuState::init()
{


	std::cout << "MenuState init" << std::endl;
}

void MenuState::cleanup()
{


	std::cout << "MenuState cleanup" << std::endl;
}

void MenuState::pause()
{


	std::cout << "MenuState pause" << std::endl;
}

void MenuState::resume()
{


	std::cout << "MenuState resume" << std::endl;
}

void MenuState::handleInput(Game* game)
{

}

void MenuState::update(Game* game)
{

}

void MenuState::draw(Game* game)
{

}