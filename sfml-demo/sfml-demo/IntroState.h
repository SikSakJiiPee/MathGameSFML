#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GameState.h"

class IntroState : public GameState
{
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void handleInput(Game* game);
	void update(Game* game);
	void draw(Game* game);
	
	static IntroState* instance()
	{
		return &introState;
	}

protected:
	IntroState() {}

private:
	static IntroState introState;

	sf::Font font;
	sf::Text textTitleIntro;

	//sf::Texture* texturebgTitle; //kaatuu tähän, katso linkkerit läpi tai vaihda sfml:n uuteen versioon.

	//sf::Sprite spritebgTitle;
};