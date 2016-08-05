#pragma once

#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


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
	std::stack<GameState*> states;

	sf::RenderWindow window;
	//sf::Event evnt;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();

private:
	////selvitä tarvitaanko kaikkia
	//const char* titleName;
	//int windowWidth;
	//int windowHeight;
	bool running;
	bool fullscreen;

};





//#pragma once
//
//#include <vector>
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <iomanip>
//
//#include <SFML/Graphics.hpp>
//
//
//template <typename T>
//std::string convertToString(T unconverted)
//{
//	std::stringstream ss;
//	ss << std::fixed << std::setfill('0') << std::setprecision(2) << unconverted;
//	std::string srtConverted = ss.str();
//
//	return srtConverted;
//}
//
//class GameState;
//
//class Game
//{
//public:
//	void init(const char* title, int width, int height, bool fscreen);
//	void cleanup();
//
//	void changeState(GameState* state);
//	void pushState(GameState* state);
//	void popState();
//
//	void handleEvents();
//	void update();
//	void draw();
//
//	bool isRunning() { return running; }
//	void quit() { running = false; }
//
//	sf::RenderWindow window;
//	sf::Event evnt;
//
//private:
//	std::vector<GameState*> states;
//
//	const char* titleName;
//	int windowWidth;
//	int windowHeight;
//	bool running;
//	bool fullscreen;
//
//};