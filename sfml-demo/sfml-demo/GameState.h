#pragma once

#include "Game.h"


class GameState
{
public:
	Game* game;

	//virtual void init() = 0;
	//virtual void cleanup() = 0;

	//virtual void pause() = 0;
	//virtual void resume() = 0;

	///A method for handling the input of the game state
	virtual void handleInput() = 0;
	///A method for updating the game state
	virtual void update(const float dt) = 0;
	///A method for drawing the game state
	virtual void draw(const float dt) = 0;


};







