#pragma once

//Includes
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//StateManager
#include "GameState.h"

//Enum classes
///An enum class for different selections in the menu
enum class MenuSelection {START, OPTIONS, CONTROLS, QUIT};


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
	///Go to Controls by the ControlsState to the stack.
	void goToControls();

	MenuSelection menuSelection;

	//Font and Text
	sf::Font font;
	sf::Text textMenuStart;
	sf::Text textMenuOptions;
	sf::Text textMenuControls;
	sf::Text textMenuQuit;

	//Audio
	//musiikki p‰‰st‰‰ staattisen r‰s‰hdyksen loopatessaan t‰ll‰
	sf::Music musicMenu;

	sf::SoundBuffer bufferMusicMenu;
	sf::Sound soundMusicMenu;
	sf::SoundBuffer bufferMenuMove;
	sf::Sound soundMenuMove;
	sf::SoundBuffer bufferMenuSelect;
	sf::Sound soundMenuSelect;

	bool musicIsPlaying = false;


};




