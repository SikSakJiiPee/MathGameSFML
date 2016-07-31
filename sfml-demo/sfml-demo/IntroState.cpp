#include "IntroState.h"
#include "MenuState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

#include <iostream>

IntroState IntroState::introState;

void IntroState::init()
{
	//Tekstin alustus
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitle.setFont(font);
	textTitle.setCharacterSize(30);
	textTitle.setColor(sf::Color::White);

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
	while (game->window.pollEvent(game->evnt))
	{
		if (game->evnt.type == sf::Event::Closed)
		{
			game->window.close();
		}
		if (game->evnt.type == sf::Event::KeyPressed)
		{
			if (game->evnt.key.code == sf::Keyboard::Return)
			{
				game->changeState(MenuState::instance());
			}
		}
	}
}

void IntroState::update(Game* game)
{

}

void IntroState::draw(Game* game)
{
	game->window.clear(sf::Color::Black);

	textTitle.setString("MathGame");
	textTitle.setOrigin(textTitle.getGlobalBounds().width / 2, textTitle.getGlobalBounds().height);
	textTitle.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 2);

	game->window.draw(textTitle);
	
	game->window.display();
}
