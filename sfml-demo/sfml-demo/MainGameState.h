#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"

#include "Calculation.h"

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

	//other
	sf::Font font;
	sf::Text textCalculation;
	sf::Text textCalculation2;
	sf::Text textCalculation3;
	sf::Text textPlayerAnswer;
	sf::Text textCorrectAnswer;
	sf::Text textPoints;
	sf::Text textMistakes;
	sf::Text textTime;
	sf::Text text;

	sf::Clock clock;
	sf::Time timeElapsed;
	float timeLeft;


	int correctAnswer;
	int playerAnswer = -255; //tsekkaa null, koska vastaus voi olla myös nolla, joten se ei voi olla alustus.
	bool answerIsCorrect = false;
	bool playerAnswerNegative;

	int pisteet = 0;
	int virheet = 0;

	Calculation calculation(CalculationType ctype, NumberType ntype, int level, float time);
	bool calculationGameIsOn = false;
};

