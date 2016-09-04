#include "ControlsState.h"

#include "Game.h"


ControlsState::ControlsState(Game* game)
{
	this->game = game;

	//texture
	if (!texturebgControls.loadFromFile("Texture/Background/bgControls.png"))
	{
		std::cout << "Loading a texture failed" << std::endl;
	}
	spritebgControls.setTexture(texturebgControls);
	
	//Audio
	if (!bufferMusicControls.loadFromFile("Audio/Music/langer.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMusicControls.setBuffer(bufferMusicControls);


	std::cout << "ControlsState init" << std::endl;
}



void ControlsState::handleInput()
{
	sf::Event evnt;

	while (this->game->window.pollEvent(evnt))
	{
		if (evnt.type == sf::Event::Closed)
		{
			game->window.close();
		}
		if (evnt.type == sf::Event::KeyPressed)
		{
			if (evnt.key.code == sf::Keyboard::Return)
			{
				this->backToMenu();
			}
			if (evnt.key.code == sf::Keyboard::Escape)
			{
				this->backToMenu();
			}
		}
	}
}

void ControlsState::update(const float dt)
{
	//Music
	if (isMusicControlsPlaying == false)
	{
		soundMusicControls.play();
		soundMusicControls.setLoop(true);
		isMusicControlsPlaying = true;
	}


}

void ControlsState::draw(const float dt)
{
	game->window.draw(spritebgControls);


}



void ControlsState::backToMenu()
{
	soundMusicControls.stop();

	this->game->popState();

	return;
}