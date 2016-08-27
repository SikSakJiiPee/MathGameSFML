#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

#include "GameState.h"


enum class MenuSelection {START, OPTIONS, QUIT};


class MenuState : public GameState
{
public:
	///A constructor, gets a Game pointer.
	MenuState(Game* game);
	~MenuState();

	///A method for handling the input of the game state
	void handleInput();
	///A method for updating the game state
	void update(const float dt);
	///A method for drawing the game state
	void draw(const float dt);


private:
	///Starting the game by pushing the MainGameState to the stack.
	void startGame();
	//ei tarvita en‰‰?
	void backToIntro();

	MenuSelection menuSelection;

	sf::Font font;
	sf::Text textMenuStart;
	sf::Text textMenuOptions;
	sf::Text textMenuQuit;

	//sf::Music musicMenu;
	//sf::SoundBuffer bufferMenuMove;
	//sf::SoundBuffer bufferMenuSelect;



};




