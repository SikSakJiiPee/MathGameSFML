//#include "Calculation.h"
//#include "Game.h"
//
//Calculation::Calculation(CalculationType ctype, NumberType ntype, int level, float time)
//{
//	calculationType = ctype;
//	numberType = ntype;
//	calculationLevel = level;
//	calculationTime = time;
//
//	//Tekstin alustus
//	if (!font.loadFromFile("Fonts/arial.ttf"))
//	{
//		std::cout << "Loading a font failed!" << std::endl;
//	}
//	textCalculation.setFont(font);
//	textCalculation.setCharacterSize(30);
//	textCalculation.setColor(sf::Color::White);
//
//	textCalculation2.setFont(font);
//	textCalculation2.setCharacterSize(30);
//	textCalculation2.setColor(sf::Color::White);
//
//	textCalculation3.setFont(font);
//	textCalculation3.setCharacterSize(30);
//	textCalculation3.setColor(sf::Color::White);
//
//	textPlayerAnswer.setFont(font);
//	textPlayerAnswer.setCharacterSize(30);
//	textPlayerAnswer.setColor(sf::Color::White);
//
//	textCorrectAnswer.setFont(font);
//	textCorrectAnswer.setCharacterSize(30);
//	textCorrectAnswer.setColor(sf::Color::White);
//
//	textPoints.setFont(font);
//	textPoints.setCharacterSize(30);
//	textPoints.setColor(sf::Color::White);
//
//	textMistakes.setFont(font);
//	textMistakes.setCharacterSize(30);
//	textMistakes.setColor(sf::Color::White);
//
//	textTime.setFont(font);
//	textTime.setCharacterSize(30);
//	textTime.setColor(sf::Color::White);
//
//	text.setFont(font);
//	text.setCharacterSize(30);
//	text.setColor(sf::Color::White);
//
//	clock.restart();
//}
//
//Calculation::~Calculation()
//{
//
//}
//
//int Calculation::randomNumber(NumberType ntype, int level)
//{
//	int rMin;
//	int rMax;
//
//	if (ntype == NumberType::BOTH)
//	{
//		rMin = -5 * level;
//		rMax = 5 * level;
//	}
//	else if (ntype == NumberType::POSITIVE)
//	{
//		rMin = 0;
//		rMax = 10 * level;
//	}
//	else if (ntype == NumberType::NEGATIVE)
//	{
//		rMin = -10 * level;
//		rMax = 0;
//	}
//
//	std::random_device rd;
//	std::mt19937 rng(rd());
//	std::uniform_int_distribution<int> uni(rMin, rMax);
//	auto rNumber = uni(rng);
//
//	return rNumber;
//}
//
//int Calculation::getCorrectAnswer(CalculationType type, int number, int number2)
//{
//	if (type == CalculationType::PLUS)
//	{
//		int correctAnswer = number + number2;
//
//		return correctAnswer;
//	}
//	else if (type == CalculationType::MINUS)
//	{
//		int correctAnswer = number - number2;
//
//		return correctAnswer;
//	}
//	else if (type == CalculationType::MULTIPLY)
//	{
//		int correctAnswer = number * number2;
//
//		return correctAnswer;
//	}
//	else if (type == CalculationType::DIVIDE)
//	{
//		int correctAnswer = number / number2;
//
//		return correctAnswer;
//	}
//}
//
//int Calculation::getCorrectAnswerPlus(int number, int number2)
//{
//	int correctAnswer = number + number2;
//
//	return correctAnswer;
//}
//
//int Calculation::getCorrectAnswerMinus(int number, int number2)
//{
//	int correctAnswer = number - number2;
//
//	return correctAnswer;
//}
//
//bool Calculation::checkTheAnswer(int playerAnswer, int correctAnswer)
//{
//	if (playerAnswer == correctAnswer)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//std::string Calculation::getCalculationString(CalculationType type, int number, int number2)
//{
//	std::string stringNumber = convertToString(number);
//	std::string stringNumber2 = convertToString(number2);
//	std::string stringType;
//	std::string stringCalculation;
//	
//
//	if (type == CalculationType::PLUS)
//	{
//		stringType = " + ";
//		stringCalculation = stringNumber + stringType + stringNumber2;
//
//		return stringCalculation;
//	}
//	else if (type == CalculationType::MINUS)
//	{
//		stringType = " - ";
//		stringCalculation = stringNumber + stringType + stringNumber2;
//
//		return stringCalculation;
//	}
//	else if (type == CalculationType::MULTIPLY)
//	{
//		stringType = " * ";
//		stringCalculation = stringNumber + stringType + stringNumber2;
//
//		return stringCalculation;
//	}
//	else if (type == CalculationType::DIVIDE)
//	{
//		stringType = " / ";
//		stringCalculation = stringNumber + stringType + stringNumber2;
//
//		return stringCalculation;
//	}
//}
//
////std::string Calculation::convertIntToString(int intNumber)
////{
////	std::stringstream ss;
////	ss << intNumber;
////	std::string stringNumber = ss.str();
////
////	return stringNumber;
////}
////
////std::string Calculation::convertFloatToString(float floatNumber)
////{
////	std::stringstream ss;
////	ss << floatNumber;
////	std::string stringNumber = ss.str();
////
////	return stringNumber;
////}
//
//int Calculation::calculationGame(Calculation calculation)
//{
//	calculation.timeElapsed = calculation.clock.getElapsedTime();
//	calculation.timeLeft = calculation.calculationTime - calculation.timeElapsed.asSeconds();
//
//	std::string strTimeLeft = convertToString(calculation.timeLeft);
//	calculation.textTime.setString(strTimeLeft);
//
//	CalculationType calculationType = calculation.calculationType;
//	NumberType numberType = calculation.numberType;
//	int calculationLevel = calculation.calculationLevel;
//
//	std::string strPlayerAnswer = convertToString(calculation.playerAnswer);
//
//	if (calculation.playerAnswer != -255)
//	{
//		calculation.textPlayerAnswer.setString(strPlayerAnswer);
//	}
//	if (calculation.playerAnswer == -255)
//	{
//		calculation.textPlayerAnswer.setString("Give the Answer");
//	}
//	if (calculation.playerAnswerNegative)
//	{
//		if (calculation.playerAnswer == -255)
//		{
//			calculation.textPlayerAnswer.setString(" - ");
//		}
//		else
//		{
//			calculation.textPlayerAnswer.setString("-" + strPlayerAnswer);
//		}
//
//	}
//
//	//std::cout << playerAnswer << std::endl;
//
//	while (calculation.timeLeft > 0)
//	{
//		int luku = calculation.randomNumber(numberType, calculationLevel);
//		int luku2 = calculation.randomNumber(numberType, calculationLevel);
//		int muuttuja = calculation.randomNumber(NumberType::BOTH, 1);
//
//		calculation.correctAnswer = calculation.getCorrectAnswer(calculationType, luku, luku2);
//		std::string lasku = calculation.getCalculationString(calculationType, luku, luku2);
//		calculation.textCalculation.setString(lasku);
//
//		//std::string strPlayerAnswer = convertToString(playerAnswer);
//		//textPlayerAnswer.setString(strPlayerAnswer);
//
//		std::cout << "Anna vastaus" << std::endl;
//		if (calculation.answerIsCorrect)
//		{
//			std::cout << "Oikea vastaus on: " << calculation.correctAnswer << "	oikein!" << calculation.points << std::endl;
//			calculation.points++;
//			if (calculation.points == 5 || calculation.points == 10 || calculation.points == 15 || calculation.points == 20 || calculation.points == 25)
//			{
//				calculationLevel++;
//				std::cout << "taso nousi" << std::endl;
//			}
//		}
//		else if (!calculation.answerIsCorrect)
//		{
//			std::cout << "Oikea vastaus on: " << calculation.correctAnswer << "	kurahti..." << std::endl;
//			calculation.mistakes++;
//		}
//		std::cout << "Pisteet: " << calculation.points << ". Virheet: " << calculation.mistakes << "." << std::endl;
//		if (calculation.mistakes == 3)
//		{
//			std::cout << std::endl;
//			std::cout << "Peli loppui!" << std::endl;;
//		}
//		else
//		{
//			std::cout << std::endl;
//			std::cout << "Seuraava lasku:" << std::endl;;
//		}
//
//	}
//
//	return calculation.points;
//}