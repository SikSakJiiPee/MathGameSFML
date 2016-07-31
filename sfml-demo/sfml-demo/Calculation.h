#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio> //ei välttämättä tarvita enää (rand)
#include <cstdlib> //ei välttämättä tarvita enää (srand)
#include <time.h>
#include <random>

enum class CalculationType {PLUS, MINUS, MULTIPLY, DIVIDE}; //Pitäisikö nimet olla Addition, Subtraction, Multiplication ja Division
enum class NumberType {BOTH, POSITIVE, NEGATIVE};

std::string calculationTypeToString(CalculationType type);

template <typename T>
std::string convertToString(T unconverted)
{
	std::stringstream ss;
	ss << std::fixed << std::setfill ('0') << std::setprecision (2) << unconverted;
	std::string srtConverted = ss.str();

	return srtConverted;
}

class Calculation
{
public:
	Calculation(CalculationType ctype, NumberType ntype, int level, float time);
	~Calculation();

	CalculationType calculationType;
	NumberType numberType;
	int calculationLevel;
	float calculationTime;

	int correctAnswer;
	int playerAnswer = -255; //Pitää olla pienempi
	bool answerIsCorrect = false;
	bool playerAnswerNegative;

	int points = 0;
	int mistakes = 0;
	int currentCombo;
	int maxCombo;
	float averageCombo;

	static int randomNumber(NumberType ntype, int level);
	static int getCorrectAnswer(CalculationType type, int number, int number2);
	static int getCorrectAnswerPlus(int number, int number2);
	static int getCorrectAnswerMinus(int number, int number2);
	static bool checkTheAnswer(int playerAnswer, int correctAnswer);
	static std::string getCalculationString(CalculationType type, int number, int number2);

	//static std::string convertIntToString(int number);
	//static std::string convertFloatToString(float number);

	static int calculationGame(Calculation calculation);

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

};