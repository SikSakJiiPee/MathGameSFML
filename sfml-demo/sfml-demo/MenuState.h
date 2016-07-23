#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"

class MenuState : public GameState
{
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void handleInput(Game* game);
	void update(Game* game);
	void draw(Game* game);

	static MenuState* instance()
	{
		return &menuState;
	}

protected:
	MenuState() {}

private:
	static MenuState menuState;
};