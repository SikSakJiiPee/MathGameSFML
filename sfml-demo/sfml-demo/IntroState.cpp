#include "IntroState.h"
#include "MenuState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

#include <iostream>

IntroState IntroState::introState;

void IntroState::init()
{
	//font and text
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitleIntro.setFont(font);
	textTitleIntro.setCharacterSize(30);
	textTitleIntro.setColor(sf::Color::White);

	////texture
	//if (!texturebgTitle->loadFromFile("Texture/test.png"))
	//{
	//	std::cout << "Loading a texture failed" << std::endl;
 //	}
	//spritebgTitle.setTexture(*texturebgTitle);


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

	textTitleIntro.setString("MathGame");
	textTitleIntro.setOrigin(textTitleIntro.getGlobalBounds().width / 2, textTitleIntro.getGlobalBounds().height);
	textTitleIntro.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 2);

	//game->window.draw(spritebgTitle);
	game->window.draw(textTitleIntro);
	
	game->window.display();
}
