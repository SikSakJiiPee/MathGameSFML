#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class MenuState : public GameState
{
public:
	MenuState(Game* game);

	//state stuff
	//void init();
	//void cleanup();

	//void pause();
	//void resume();

	void handleInput();
	void update(const float dt);
	void draw(const float dt);


private:
	void startGame();
	void backToIntro();


	sf::Font font;
	sf::Text text;
	sf::Text text2;

};




//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include "GameState.h"
//
//class MenuState : public GameState
//{
//public:
//	//state stuff
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
//	static MenuState* instance()
//	{
//		return &menuState;
//	}
//
//protected:
//	MenuState() {}
//
//private:
//	//state stuff
//	static MenuState menuState; //tässä on joku häikkä (sama muissa stateissa)
//
//	//other
//	sf::Font font;
//	sf::Text text;
//	sf::Text text2;
//};