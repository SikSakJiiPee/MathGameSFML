#include "MenuState.h"
#include "MainGameState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

//#include <iostream> //ei ehkä tarvita, game.h

MenuState::MenuState(Game* game)
{
	this->game = game;
	
	//Tekstin alustus
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);

	text2.setFont(font);
	text2.setCharacterSize(30);
	text2.setColor(sf::Color::White);

	std::cout << "MenuState init" << std::endl;
}

//void MenuState::init()
//{
	////Tekstin alustus
	//if (!font.loadFromFile("Font/arial.ttf"))
	//{
	//	std::cout << "Loading a font failed!" << std::endl;
	//}
	//text.setFont(font);
	//text.setCharacterSize(30);
	//text.setColor(sf::Color::White);
	//
	//text2.setFont(font);
	//text2.setCharacterSize(30);
	//text2.setColor(sf::Color::White);
	//
	//std::cout << "MenuState init" << std::endl;
//}
//
//void MenuState::cleanup()
//{
//
//
//	std::cout << "MenuState cleanup" << std::endl;
//}
//
//void MenuState::pause()
//{
//
//
//	std::cout << "MenuState pause" << std::endl;
//}
//
//void MenuState::resume()
//{
//
//
//	std::cout << "MenuState resume" << std::endl;
//}

void MenuState::handleInput()
{
	sf::Event evnt;

	while (this->game->window.pollEvent(evnt))
	{
		//if (evnt.type == sf::Event::Closed)
		//{
		//	game->window.close();
		//}
		//if (evnt.type == sf::Event::KeyPressed)
		//{
		//	if (evnt.key.code == sf::Keyboard::Return)
		//	{
		//		//game->pushState(MainGameState::instance());
		//	}
		//	if (evnt.key.code == sf::Keyboard::Escape)
		//	{
		//		game->window.close();
		//		//game->cleanup(); //kaataa pelin
		//	}
		//}


		switch (evnt.type)
		{
		case sf::Event::Closed:
		{
			this->game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
			{
				this->game->window.close();
				//this->backToIntro();
				break;
			}
			case sf::Keyboard::Return:
			{
				std::cout << "joo";
				this->startGame();
				break;
			}
			default:
				break;
			}
		default:
			break;
		}
	}

	return;
}

void MenuState::update(const float dt)
{

}

void MenuState::draw(const float dt)
{
	//game->window.clear(sf::Color::Black);

	text.setString("Press ENTER to start the game");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
	text.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 3);

	text2.setString("Press ESC to quit");
	text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height);
	text2.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 3) * 2);

	game->window.draw(text);
	game->window.draw(text2);

	//game->window.display();
}


void MenuState::startGame()
{
	this->game->pushState(new MainGameState(this->game));

	return;
}

void MenuState::backToIntro()
{
	this->game->popState();

	return;
}




//#include "MenuState.h"
//#include "MainGameState.h"
//
//#include "Game.h"
//#include "GameState.h"
//
////#include <SFML/Graphics.hpp>
//
//#include <iostream> //ei ehkä tarvita, game.h
//
////MenuState MenuState::menuState;
//
//void MenuState::init()
//{
//	//Tekstin alustus
//	if (!font.loadFromFile("Font/arial.ttf"))
//	{
//		std::cout << "Loading a font failed!" << std::endl;
//	}
//	text.setFont(font);
//	text.setCharacterSize(30);
//	text.setColor(sf::Color::White);
//
//	text2.setFont(font);
//	text2.setCharacterSize(30);
//	text2.setColor(sf::Color::White);
//
//	std::cout << "MenuState init" << std::endl;
//}
//
//void MenuState::cleanup()
//{
//
//
//	std::cout << "MenuState cleanup" << std::endl;
//}
//
//void MenuState::pause()
//{
//
//
//	std::cout << "MenuState pause" << std::endl;
//}
//
//void MenuState::resume()
//{
//
//
//	std::cout << "MenuState resume" << std::endl;
//}
//
//void MenuState::handleInput(Game* game)
//{
//	while (game->window.pollEvent(game->evnt))
//	{
//		if (game->evnt.type == sf::Event::Closed)
//		{
//			game->window.close();
//		}
//		if (game->evnt.type == sf::Event::KeyPressed)
//		{
//			if (game->evnt.key.code == sf::Keyboard::Return)
//			{
//				game->pushState(MainGameState::instance());
//			}
//			if (game->evnt.key.code == sf::Keyboard::Escape)
//			{
//				game->window.close();
//				//game->cleanup(); //kaataa pelin
//			}
//		}
//	}
//}
//
//void MenuState::update(Game* game)
//{
//
//}
//
//void MenuState::draw(Game* game)
//{
//	game->window.clear(sf::Color::Black);
//
//	text.setString("Press ENTER to start the game");
//	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
//	text.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 3);
//
//	text2.setString("Press ESC to quit");
//	text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height);
//	text2.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 3) * 2);
//
//	game->window.draw(text);
//	game->window.draw(text2);
//
//	game->window.display();
//}