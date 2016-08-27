#include "IntroState.h"
#include "MenuState.h"

#include "Game.h"
#include "GameState.h"


IntroState::IntroState(Game* game)
{
	this->game = game;

	//font and text
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitleIntro.setFont(font);
	textTitleIntro.setCharacterSize(30);
	textTitleIntro.setColor(sf::Color::White);

	//texture
	if (!texturebgTitle.loadFromFile("Texture/Background/bgTestTitle.png"))
	{
		std::cout << "Loading a texture failed" << std::endl;
	}
	spritebgTitle.setTexture(texturebgTitle);


	std::cout << "IntroState init" << std::endl;
}


void IntroState::handleInput()
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
		//		std::cout << "joo";
		//		game->changeState(new MenuState(this->game));
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
				this->goToMenu();
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

void IntroState::update(const float dt)
{


	return;
}

void IntroState::draw(const float dt)
{
	//game->window.clear(sf::Color::Black);

	textTitleIntro.setString("MathGame");
	textTitleIntro.setOrigin(textTitleIntro.getGlobalBounds().width / 2, textTitleIntro.getGlobalBounds().height);
	textTitleIntro.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 2);


	game->window.draw(spritebgTitle);


	//game->window.draw(textTitleIntro);


	//game->window.display();

	return;
}


void IntroState::goToMenu()
{
	this->game->changeState(new MenuState(this->game));

	return;
}







