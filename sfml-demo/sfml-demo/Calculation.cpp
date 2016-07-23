#include "Calculation.h"

Calculation::Calculation(CalculationType ctype, NumberType ntype, int level, int time)
{
	calculationType = ctype;
	numberType = ntype;
	calculationLevel = level;
	calculationTime = time;
}

Calculation::~Calculation()
{

}

int Calculation::randomNumber(NumberType ntype, int level)
{
	int rMin;
	int rMax;

	if (ntype == NumberType::NORMAL)
	{
		rMin = -5 * level;
		rMax = 5 * level;
	}
	else if (ntype == NumberType::POSITIVE)
	{
		rMin = 0;
		rMax = 10 * level;
	}
	else if (ntype == NumberType::NEGATIVE)
	{
		rMin = -10 * level;
		rMax = 0;
	}

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(rMin, rMax);
	auto rNumber = uni(rng);

	return rNumber;
}

int Calculation::getCorrectAnswer(CalculationType type, int number, int number2)
{
	if (type == CalculationType::PLUS)
	{
		int correctAnswer = number + number2;

		return correctAnswer;
	}
	else if (type == CalculationType::MINUS)
	{
		int correctAnswer = number - number2;

		return correctAnswer;
	}
	else if (type == CalculationType::MULTIPLY)
	{
		int correctAnswer = number * number2;

		return correctAnswer;
	}
	else if (type == CalculationType::DIVIDE)
	{
		int correctAnswer = number / number2;

		return correctAnswer;
	}
}

int Calculation::getCorrectAnswerPlus(int number, int number2)
{
	int correctAnswer = number + number2;

	return correctAnswer;
}

int Calculation::getCorrectAnswerMinus(int number, int number2)
{
	int correctAnswer = number - number2;

	return correctAnswer;
}

std::string Calculation::convertIntToString(int intNumber)
{
	std::stringstream ss;
	ss << intNumber;
	std::string stringNumber = ss.str();

	return stringNumber;
}

bool Calculation::checkTheAnswer(int playerAnswer, int correctAnswer)
{
	if (playerAnswer == correctAnswer)
	{
		return true;
	}

	return false;
}

std::string Calculation::getCalculationString(CalculationType type, int number, int number2)
{
	std::string stringNumber = Calculation::convertIntToString(number);
	std::string stringNumber2 = Calculation::convertIntToString(number2);
	std::string stringType;
	std::string stringCalculation;
	

	if (type == CalculationType::PLUS)
	{
		stringType = " + ";
		stringCalculation = stringNumber + stringType + stringNumber2;

		return stringCalculation;
	}
	else if (type == CalculationType::MINUS)
	{
		stringType = " - ";
		stringCalculation = stringNumber + stringType + stringNumber2;

		return stringCalculation;
	}
	else if (type == CalculationType::MULTIPLY)
	{
		stringType = " * ";
		stringCalculation = stringNumber + stringType + stringNumber2;

		return stringCalculation;
	}
	else if (type == CalculationType::DIVIDE)
	{
		stringType = " / ";
		stringCalculation = stringNumber + stringType + stringNumber2;

		return stringCalculation;
	}
}