#pragma once

//Includes
//other
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


//Templates
///Template for converting data to string. Floats are converted with decimal precision of two.
template <typename T>
std::string convertToString(T unconverted)
{
	std::stringstream ss;
	ss << std::fixed << std::setfill('0') << std::setprecision(2) << unconverted;
	std::string srtConverted = ss.str();

	return srtConverted;
}


class GameState;

class Game
{
public: 
	///A constructor
	Game();
	///A Destructor
	~Game();

	///Stack for handling the game states
	std::stack<GameState*> states;

	sf::RenderWindow window;
	//sf::Event evnt;

	///Pushes a new game state to the stack
	void pushState(GameState* state);
	///Removes the current game state from the top of the stack
	void popState();
	///Removes the current game state and changes a state to a new game state
	void changeState(GameState* state);
	///Returns a game state from the top of the stack. Returns nullptr if stack is empty.
	GameState* peekState();

	///Handles the game loop meaning methods of the current game state.
	void gameLoop();


private:
	////selvitä tarvitaanko kaikkia
	//const char* titleName;
	//int windowWidth;
	//int windowHeight;
	bool running;
	bool fullscreen;

};





