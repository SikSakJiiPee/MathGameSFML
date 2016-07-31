//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//
//#include "GameState.h"
//
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <iomanip>
//#include <cstdio> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (rand)
//#include <cstdlib> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (srand)
//#include <time.h>
//#include <random>
//
//enum class CalculationType { PLUS, MINUS, MULTIPLY, DIVIDE }; //Pit‰isikˆ nimet olla Addition, Subtraction, Multiplication ja Division
//enum class NumberType { BOTH, POSITIVE, NEGATIVE };
//
//std::string calculationTypeToString(CalculationType type); //selvit‰ tarviitseko t‰t‰?
//
////T‰ytyy ehk‰ siirt‰‰ game.h
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
//class CalculationState : public GameState
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
//	static CalculationState* instance()
//	{
//		return &calculationState;
//	}
//
//
//	//other
//	CalculationType calculationType;
//	NumberType numberType;
//	int calculationLevel;
//	float calculationTime;
//
//	int correctAnswer;
//	int playerAnswer = -255; //Pit‰‰ olla pienempi
//	bool answerIsCorrect = false;
//	bool playerAnswerNegative;
//
//	int points = 0;
//	int mistakes = 0;
//	int currentCombo;
//	int maxCombo;
//	float averageCombo;
//
//	static int randomNumber(NumberType ntype, int level);
//	static int getCorrectAnswer(CalculationType type, int number, int number2);
//	static int getCorrectAnswerPlus(int number, int number2);
//	static int getCorrectAnswerMinus(int number, int number2);
//	static bool checkTheAnswer(int playerAnswer, int correctAnswer);
//	static std::string getCalculationString(CalculationType type, int number, int number2);
//
//
//	static int calculationGame(Calculation calculation);
//
//protected:
//	CalculationState() {}
//
//private:
//	//state stuff
//	static CalculationState calculationState;
//
//	//other
//	sf::Font font;
//	sf::Text textCalculation;
//	sf::Text textCalculation2;
//	sf::Text textCalculation3;
//	sf::Text textPlayerAnswer;
//	sf::Text textCorrectAnswer;
//	sf::Text textPoints;
//	sf::Text textMistakes;
//	sf::Text textTime;
//	sf::Text text;
//
//	sf::Clock clock;
//	sf::Time timeElapsed;
//	float timeLeft;
//};