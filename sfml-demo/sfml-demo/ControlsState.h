#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameState.h"


class ControlsState : public GameState
{
public:
	///A constructor, gets a Game pointer.
	ControlsState(Game* game);
	~ControlsState();

	///A method for handling the input of the game state
	void handleInput();
	///A method for updating the game state
	void update(const float dt);
	///A method for drawing the game state
	void draw(const float dt);


	///Pops the current state and returns to previous state. 
	void backToMenu();


private:
	//Texture and Sprite
	sf::Texture texturebgControls;
	sf::Sprite spritebgControls;

	//Audio
	sf::SoundBuffer bufferMusicControls;
	sf::Sound soundMusicControls;
	bool isMusicControlsPlaying = false;


};