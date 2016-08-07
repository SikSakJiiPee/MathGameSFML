#include "MenuState.h"
#include "MainGameState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

//#include <iostream> //ei ehkä tarvita, game.h

MenuState::MenuState(Game* game)
{
	this->game = game;
	
	menuSelection = MenuSelection::START;

	//Tekstin alustus
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textMenuStart.setFont(font);
	textMenuStart.setCharacterSize(30);
	textMenuStart.setOrigin(textMenuStart.getGlobalBounds().width / 2, textMenuStart.getGlobalBounds().height);
	textMenuStart.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 4);
	textMenuStart.setString("Start");

	textMenuOptions.setFont(font);
	textMenuOptions.setCharacterSize(30);
	textMenuOptions.setOrigin(textMenuOptions.getGlobalBounds().width / 2, textMenuOptions.getGlobalBounds().height);
	textMenuOptions.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 4) * 2);
	textMenuOptions.setString("Options");

	textMenuQuit.setFont(font);
	textMenuQuit.setCharacterSize(30);
	textMenuQuit.setOrigin(textMenuQuit.getGlobalBounds().width / 2, textMenuQuit.getGlobalBounds().height);
	textMenuQuit.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 4) * 3);
	textMenuQuit.setString("Quit");

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
				break;
			}
			case sf::Keyboard::Return:
			{
				if (menuSelection == MenuSelection::START)
				{
					this->startGame();
				}
				if (menuSelection == MenuSelection::OPTIONS)
				{
					std::cout << "Options selected" << std::endl;
				}
				if (menuSelection == MenuSelection::QUIT)
				{
					this->game->window.close();
				}
				break;
			}
			case sf::Keyboard::Down:
			{
				if (menuSelection == MenuSelection::OPTIONS)
					menuSelection = MenuSelection::QUIT;
				if (menuSelection == MenuSelection::START)
					menuSelection = MenuSelection::OPTIONS;
				break;
			}
			case sf::Keyboard::Up:
			{
				if (menuSelection == MenuSelection::OPTIONS)
					menuSelection = MenuSelection::START;
				if (menuSelection == MenuSelection::QUIT)
					menuSelection = MenuSelection::OPTIONS;
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

	if (menuSelection == MenuSelection::START)
		textMenuStart.setColor(sf::Color::Red);
	else
		textMenuStart.setColor(sf::Color::White);

	if (menuSelection == MenuSelection::OPTIONS)
		textMenuOptions.setColor(sf::Color::Red);
	else
		textMenuOptions.setColor(sf::Color::White);

	if (menuSelection == MenuSelection::QUIT)
		textMenuQuit.setColor(sf::Color::Red);
	else
		textMenuQuit.setColor(sf::Color::White);


	game->window.draw(textMenuStart);
	game->window.draw(textMenuOptions);
	game->window.draw(textMenuQuit);

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