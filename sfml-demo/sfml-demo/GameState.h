#pragma once

//Includes
//StateManager
#include "Game.h"


class GameState
{
public:
	Game* game;

	///A method for handling the input of the game state.
	virtual void handleInput() = 0;
	///A method for updating the game state.
	virtual void update(const float dt) = 0;
	///A method for drawing the game state.
	virtual void draw(const float dt) = 0;


};







