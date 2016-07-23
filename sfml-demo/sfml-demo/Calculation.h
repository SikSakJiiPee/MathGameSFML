#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (rand)
#include <cstdlib> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (srand)
#include <time.h>
#include <random>

enum class CalculationType {PLUS, MINUS, MULTIPLY, DIVIDE};
enum class NumberType {NORMAL ,POSITIVE, NEGATIVE};

std::string calculationTypeToString(CalculationType type);

class Calculation
{
public:
	Calculation(CalculationType ctype, NumberType ntype, int level, int time);
	~Calculation();

	CalculationType calculationType;
	NumberType numberType;
	int calculationLevel;
	int calculationTime;

	static int randomNumber(NumberType ntype, int level);
	static int getCorrectAnswer(CalculationType type, int number, int number2);
	static int getCorrectAnswerPlus(int number, int number2);
	static int getCorrectAnswerMinus(int number, int number2);
	static std::string convertIntToString(int number);
	static bool checkTheAnswer(int playerAnswer, int correctAnswer);
	static std::string getCalculationString(CalculationType type, int number, int number2);
};