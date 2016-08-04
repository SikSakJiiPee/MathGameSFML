#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class IntroState : public GameState
{
public:
	IntroState(Game* game);
	
	//void init(); //voidaan tehdä konstruktorissa
	//void cleanup();

	//void pause();
	//void resume();

	void handleInput();
	void update(const float dt);
	void draw(const float dt);


private:
	void goToMenu();
	

	sf::View view; //ei varma

	sf::Font font;
	sf::Text textTitleIntro;

	sf::Texture texturebgTitle; //kaatuu tähän, katso linkkerit läpi tai vaihda sfml:n uuteen versioon.

	sf::Sprite spritebgTitle;


};




//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Texture.hpp>
//#include "GameState.h"
//
//class IntroState : public GameState
//{
//public:
//	void init();
//	void cleanup();
//
//	void pause();
//	void resume();
//
//	void handleInput(Game* game);
//	void update(Game* game);
//	void draw(Game* game);
//	
//	static IntroState* instance()
//	{
//		return &introState;
//	}
//
//protected:
//	IntroState() {}
//
//private:
//	static IntroState introState;
//
//	sf::Font font;
//	sf::Text textTitleIntro;
//
//	//sf::Texture* texturebgTitle; //kaatuu tähän, katso linkkerit läpi tai vaihda sfml:n uuteen versioon.
//
//	//sf::Sprite spritebgTitle;
//};

