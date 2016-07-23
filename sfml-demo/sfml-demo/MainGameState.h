#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"

class MainGameState : public GameState
{
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void handleInput(Game* game);
	void update(Game* game);
	void draw(Game* game);
	
	

	static MainGameState* instance()
	{
		return &mainGameState;
	}

protected:
	MainGameState() {}

private:
	static MainGameState mainGameState;

};

