#pragma once

#include "Game.h"

class GameState
{
public:
	//Game* game;

	virtual void init() = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleInput(Game* game) = 0;
	virtual void update(Game* game) = 0;
	virtual void draw(Game* game) = 0;
	
	void changeState(Game* game, GameState* state)
	{
		game->changeState(state);
	}

protected:
	GameState() {}
};