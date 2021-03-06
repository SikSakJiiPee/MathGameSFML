#include "MenuState.h"
#include "ControlsState.h"
#include "MainGameState.h"

#include "Game.h"


MenuState::MenuState(Game* game)
{
	this->game = game;
	
	menuSelection = MenuSelection::START;

	//Font and Text
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textMenuStart.setFont(font);
	textMenuStart.setCharacterSize(30);
	textMenuStart.setOrigin(textMenuStart.getGlobalBounds().width / 2, textMenuStart.getGlobalBounds().height);
	textMenuStart.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 4);
	textMenuStart.setString("Start");

	//textMenuOptions.setFont(font);
	//textMenuOptions.setCharacterSize(30);
	//textMenuOptions.setOrigin(textMenuOptions.getGlobalBounds().width / 2, textMenuOptions.getGlobalBounds().height);
	//textMenuOptions.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 4) * 2);
	//textMenuOptions.setString("Options");

	textMenuControls.setFont(font);
	textMenuControls.setCharacterSize(30);
	textMenuControls.setOrigin(textMenuOptions.getGlobalBounds().width / 2, textMenuOptions.getGlobalBounds().height);
	textMenuControls.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 4) * 2);
	textMenuControls.setString("Controls");

	textMenuQuit.setFont(font);
	textMenuQuit.setCharacterSize(30);
	textMenuQuit.setOrigin(textMenuQuit.getGlobalBounds().width / 2, textMenuQuit.getGlobalBounds().height);
	textMenuQuit.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 4) * 3);
	textMenuQuit.setString("Quit");

	//Audio
	if (!bufferMusicMenu.loadFromFile("Audio/Music/hungerland.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMusicMenu.setBuffer(bufferMusicMenu);

	//sfx
	if (!bufferMenuMove.loadFromFile("Audio/SFX/menu_move.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMenuMove.setBuffer(bufferMenuMove);

	if (!bufferMenuSelect.loadFromFile("Audio/SFX/menu_select.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMenuSelect.setBuffer(bufferMenuSelect);

	std::cout << "MenuState init" << std::endl;
}


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
				soundMenuSelect.play();
				if (menuSelection == MenuSelection::START)
				{
					this->startGame();
				}
				//if (menuSelection == MenuSelection::OPTIONS)
				//{
				//	std::cout << "Options selected" << std::endl;
				//}
				if (menuSelection == MenuSelection::CONTROLS)
				{
					this->goToControls();
				}
				if (menuSelection == MenuSelection::QUIT)
				{
					this->game->window.close();
				}
				break;
			}
			case sf::Keyboard::Down:
			{
				soundMenuMove.play();
				if (menuSelection == MenuSelection::CONTROLS)
					menuSelection = MenuSelection::QUIT;
				if (menuSelection == MenuSelection::START)
					menuSelection = MenuSelection::CONTROLS;
				break;
			}
			case sf::Keyboard::Up:
			{
				soundMenuMove.play();
				if (menuSelection == MenuSelection::CONTROLS)
					menuSelection = MenuSelection::START;
				if (menuSelection == MenuSelection::QUIT)
					menuSelection = MenuSelection::CONTROLS;
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
	if (!musicIsPlaying)
	{
		soundMusicMenu.play();
		soundMusicMenu.setLoop(true);
		musicIsPlaying = true;
	}
}

void MenuState::draw(const float dt)
{
	if (menuSelection == MenuSelection::START)
		textMenuStart.setColor(sf::Color::Red);
	else
		textMenuStart.setColor(sf::Color::White);

	//if (menuSelection == MenuSelection::OPTIONS)
	//	textMenuOptions.setColor(sf::Color::Red);
	//else
	//	textMenuOptions.setColor(sf::Color::White);

	if (menuSelection == MenuSelection::CONTROLS)
		textMenuControls.setColor(sf::Color::Red);
	else
		textMenuControls.setColor(sf::Color::White);

	if (menuSelection == MenuSelection::QUIT)
		textMenuQuit.setColor(sf::Color::Red);
	else
		textMenuQuit.setColor(sf::Color::White);

	game->window.draw(textMenuStart);
	//game->window.draw(textMenuOptions);
	game->window.draw(textMenuControls);
	game->window.draw(textMenuQuit);
}


void MenuState::startGame()
{
	musicIsPlaying = false;
	soundMusicMenu.stop();
	this->game->pushState(new MainGameState(this->game));

	return;
}

void MenuState::goToControls()
{
	musicIsPlaying = false;
	soundMusicMenu.stop();
	this->game->pushState(new ControlsState(this->game));

	return;
}




