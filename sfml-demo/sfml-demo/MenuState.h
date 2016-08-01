#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"

class MenuState : public GameState
{
public:
	//state stuff
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
	//state stuff
	static MenuState menuState;

	//other
	sf::Font font;
	sf::Text text;
	sf::Text text2;
};