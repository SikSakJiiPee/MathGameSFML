//#pragma once
//
//#include <stack>
//#include <SFML/Graphics.hpp>
//
//class GameState;
//
//class Game
//{
//public: 
//	Game();
//	~Game();
//
//	std::stack<GameState*> states;
//
//	sf::RenderWindow window;
//
//	void pushState(GameState* state);
//	void popState();
//	void changeState(GameState* state);
//	GameState* peekState();
//
//	void gameLoop();
//
//
//};

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class GameState;

class Game
{
public:
	void init(const char* title, int width, int height, bool fscreen);
	void cleanup();

	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();

	void handleEvents();
	void update();
	void draw();

	bool isRunning() { return running; }
	void quit() { running = false; }

	sf::RenderWindow window;
	sf::Event evnt;

private:
	std::vector<GameState*> states;

	const char* titleName;
	int windowWidth;
	int windowHeight;
	bool running;
	bool fullscreen;

};