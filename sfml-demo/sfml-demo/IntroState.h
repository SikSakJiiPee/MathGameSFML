#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"


class IntroState : public GameState
{
public:
	///A constructor, gets a Game pointer.
	IntroState(Game* game);
	~IntroState();


	///A method for handling the input of the game state
	void handleInput();
	///A method for updating the game state
	void update(const float dt);
	///A method for drawing the game state
	void draw(const float dt);


private:
	///Goes to menu by changing the state to the MenuState.
	void goToMenu();
	

	sf::View view; //ei varma

	sf::Font font;
	sf::Text textTitleIntro;

	sf::Texture texturebgTitle; //kaatuu tähän, katso linkkerit läpi tai vaihda sfml:n uuteen versioon.

	sf::Sprite spritebgTitle;


};





