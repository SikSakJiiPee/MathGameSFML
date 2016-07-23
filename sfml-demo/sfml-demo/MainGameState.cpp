#include "MainGameState.h"
#include "MenuState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

#include "Calculation.h"

#include <iostream>

MainGameState MainGameState::mainGameState;

void MainGameState::init()
{


	std::cout << "MainMenuState init" << std::endl;
}

void MainGameState::cleanup()
{


	std::cout << "MainMenuState cleanup" << std::endl;
}

void MainGameState::pause()
{


	std::cout << "MainMenuState pause" << std::endl;
}

void MainGameState::resume()
{


	std::cout << "MainMenuState resume" << std::endl;
}

void MainGameState::handleInput(Game* game)
{

}

void MainGameState::update(Game* game)
{

}

void MainGameState::draw(Game* game)
{

}
