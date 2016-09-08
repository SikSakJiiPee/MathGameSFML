#pragma once

//Includes
//SFML
#include <SFML/Graphics.hpp>
//StateManager
#include "GameState.h"


class IntroState : public GameState
{
public:
	///A constructor, gets a Game pointer.
	IntroState(Game* game);
	///A destructor.
	~IntroState();


	///A method for handling the input of the game state.
	void handleInput();
	///A method for updating the game state.
	void update(const float dt);
	///A method for drawing the game state.
	void draw(const float dt);


private:
	//Methods
	//State management
	///Goes to menu by changing the state to the MenuState.
	void goToMenu();

	//Attributes
	//Font and Text
	sf::Font font;
	sf::Text textTitleIntro;

	//Texture and Sprite
	sf::Texture texturebgTitle;
	sf::Sprite spritebgTitle;


};





