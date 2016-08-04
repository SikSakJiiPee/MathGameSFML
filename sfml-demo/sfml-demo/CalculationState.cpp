//#include "CalculationState.h"
//#include "MainGameState.h"
//
//#include "Game.h"
//#include "GameState.h"
//
//#include <iostream> //ei ehkä tarvita, game.h
//
//
////CalculationState CalculationState::calculationState;
//
//void CalculationState::init()
//{
//	//Tekstin alustus
//	if (!font.loadFromFile("Font/arial.ttf"))
//	{
//		std::cout << "Loading a font failed!" << std::endl;
//	}
//	textTitleCalc.setFont(font);
//	textTitleCalc.setCharacterSize(30);
//	textTitleCalc.setColor(sf::Color::White);
//	textTitleCalc.setString("Calculation");
//
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
//	textCurrentCombo.setFont(font);
//	textCurrentCombo.setCharacterSize(30);
//	textCurrentCombo.setColor(sf::Color::White);
//
//	textMaxCombo.setFont(font);
//	textMaxCombo.setCharacterSize(30);
//	textMaxCombo.setColor(sf::Color::White);
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
//
//	//playerAnswer = -255;
//
//	std::cout << "CalculationState init" << std::endl;
//}
//
//
//void CalculationState::cleanup()
//{
//	textTitleCalc.setString("");
//	textCalculation.setString("");
//	textPlayerAnswer.setString("");
//
//	std::cout << "CalculationState cleanup" << std::endl;
//}
//
//
//void CalculationState::pause()
//{
//
//
//	std::cout << "CalculationState pause" << std::endl;
//}
//
//
//void CalculationState::resume()
//{
//
//
//	std::cout << "CalculationState resume" << std::endl;
//}
//
//
//void CalculationState::handleInput(Game* game)
//{
//	while (game->window.pollEvent(game->evnt))
//	{
//		//closing the window
//		if (game->evnt.type == sf::Event::Closed)
//		{
//			game->window.close();
//		}
//
//		if (game->evnt.type == sf::Event::KeyPressed)
//		{
//			//popState
//			if (game->evnt.key.code == sf::Keyboard::Escape)
//			{
//				game->popState();
//			}
//
//			//comparing the answer
//			if (game->evnt.key.code == sf::Keyboard::Return)
//			{
//				//ei valmis
//				if (playerAnswerNegative == true)
//				{
//					playerAnswer *= -1;
//				}
//
//				//vastauksien vertaaminen
//				if (playerAnswer == correctAnswer)
//				{
//					answerIsCorrect = true;
//				}
//				else
//				{
//					answerIsCorrect = false;
//					playerAnswer = -255;
//				}
//				playerAnswerNegative = false;
//			}
//
//			//the numbers
//			if (game->evnt.key.code == sf::Keyboard::Num0)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 0;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = playerAnswer * 10;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num1)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 1;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 1;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num2)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 2;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 2;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num3)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 3;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 3;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num4)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 4;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 4;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num5)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 5;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 5;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num6)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 6;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 6;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num7)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 7;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 7;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num8)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 8;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 8;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Num9)
//			{
//				if (playerAnswer == -255)
//				{
//					playerAnswer = 9;
//				}
//				else if (playerAnswer > 100000)
//				{
//					playerAnswer += 0;
//				}
//				else
//				{
//					playerAnswer = (playerAnswer * 10) + 9;
//				}
//			}
//			if (game->evnt.key.code == sf::Keyboard::Subtract || game->evnt.key.code == sf::Keyboard::Dash)
//			{
//				playerAnswerNegative = true;
//			}
//		}
//	}
//}
//
//
//void CalculationState::update(Game* game)
//{
//	//timer
//	timeElapsed = clock.getElapsedTime();
//	timeLeft = 30 - timeElapsed.asSeconds();
//	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;
//	std::string strTimeLeft = convertToString(timeLeft);
//	textTime.setString(strTimeLeft);
//
//	
//	//MUISTA ALUSTAA KAIKKI!
//	CalculationType calculationType = CalculationType::PLUS;
//	NumberType numberType = NumberType::BOTH;
//	int calculationLevel = 1;
//	//int calculationLevel = MainGameState::calculationLevel;
//
//	std::string strPlayerAnswer = convertToString(playerAnswer);
//
//	if (playerAnswer != -255)
//	{
//		textPlayerAnswer.setString(strPlayerAnswer);
//	}
//	if (playerAnswer == -255)
//	{
//		textPlayerAnswer.setString("Give the Answer");
//	}
//	if (playerAnswerNegative)
//	{
//		if (playerAnswer == -255)
//		{
//			textPlayerAnswer.setString(" - ");
//		}
//		else
//		{
//			textPlayerAnswer.setString("-" + strPlayerAnswer);
//		}
//
//	}
//
//	//std::cout << playerAnswer << std::endl;
//
//	while (mistakes < 3)
//	{
//		int luku = randomNumber(numberType, calculationLevel);
//		int luku2 = randomNumber(numberType, calculationLevel);
//
//		correctAnswer = getCorrectAnswer(calculationType, luku, luku2);
//		std::string lasku = getCalculationString(calculationType, luku, luku2);
//		textCalculation.setString(lasku);
//
//		//std::string strPlayerAnswer = convertToString(playerAnswer);
//		//textPlayerAnswer.setString(strPlayerAnswer);
//
//		std::cout << "Anna vastaus" << std::endl;
//		if (answerIsCorrect)
//		{
//			std::cout << "Oikea vastaus on: " << correctAnswer << "	oikein!" << points << std::endl;
//			points++;
//			if (points == 5 || points == 10 || points == 15 || points == 20 || points == 25)
//			{
//				calculationLevel++;
//				std::cout << "taso nousi" << std::endl;
//			}
//		}
//		else if (!answerIsCorrect)
//		{
//			std::cout << "Oikea vastaus on: " << correctAnswer << "	kurahti..." << std::endl;
//			mistakes++;
//		}
//		std::cout << "Pisteet: " << points << ". Virheet: " << mistakes << "." << std::endl;
//		if (mistakes == 3)
//		{
//			std::cout << std::endl;
//			std::cout << "Peli loppui!" << std::endl;;
//		}
//		else
//		{
//			std::cout << std::endl;
//			std::cout << "Seuraava lasku:" << std::endl;;
//		}
//	}
//}
//
//
//void CalculationState::draw(Game* game)
//{
//	game->window.clear(sf::Color::Black);
//
//	//textTitleCalc.setString("Calculation");
//	textTitleCalc.setOrigin(textTitleCalc.getGlobalBounds().width / 2, textTitleCalc.getGlobalBounds().height / 2);
//	textTitleCalc.setPosition(game->window.getSize().x / 2, 10);
//
//	textCalculation.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
//	textCalculation.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 3);
//
//	textPlayerAnswer.setOrigin(textPlayerAnswer.getGlobalBounds().width / 2, textPlayerAnswer.getGlobalBounds().height);
//	textPlayerAnswer.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 3) * 2);
//
//	game->window.draw(textTitleCalc);
//	game->window.draw(textCalculation);
//	game->window.draw(textPlayerAnswer);
//
//	game->window.draw(textTime);
//
//
//	game->window.display();
//}
//
//
////state stuff end
//
//
//
//
//
////other
//
//
//int CalculationState::randomNumber(NumberType ntype, int level)
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
//int CalculationState::getCorrectAnswer(CalculationType type, int number, int number2)
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
//int CalculationState::getCorrectAnswerPlus(int number, int number2)
//{
//	int correctAnswer = number + number2;
//
//	return correctAnswer;
//}
//
//int CalculationState::getCorrectAnswerMinus(int number, int number2)
//{
//	int correctAnswer = number - number2;
//
//	return correctAnswer;
//}
//
//bool CalculationState::checkTheAnswer(int playerAnswer, int correctAnswer)
//{
//	if (playerAnswer == correctAnswer)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//std::string CalculationState::getCalculationString(CalculationType type, int number, int number2)
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
////int CalculationState::calculationGame(Calculation calculation)
////{
////	calculation.timeElapsed = calculation.clock.getElapsedTime();
////	calculation.timeLeft = calculation.calculationTime - calculation.timeElapsed.asSeconds();
////
////	std::string strTimeLeft = convertToString(calculation.timeLeft);
////	calculation.textTime.setString(strTimeLeft);
////
////	CalculationType calculationType = calculation.calculationType;
////	NumberType numberType = calculation.numberType;
////	int calculationLevel = calculation.calculationLevel;
////
////	std::string strPlayerAnswer = convertToString(calculation.playerAnswer);
////
////	if (calculation.playerAnswer != -255)
////	{
////		calculation.textPlayerAnswer.setString(strPlayerAnswer);
////	}
////	if (calculation.playerAnswer == -255)
////	{
////		calculation.textPlayerAnswer.setString("Give the Answer");
////	}
////	if (calculation.playerAnswerNegative)
////	{
////		if (calculation.playerAnswer == -255)
////		{
////			calculation.textPlayerAnswer.setString(" - ");
////		}
////		else
////		{
////			calculation.textPlayerAnswer.setString("-" + strPlayerAnswer);
////		}
////
////	}
////
////	//std::cout << playerAnswer << std::endl;
////
////	while (calculation.timeLeft > 0)
////	{
////		int luku = calculation.randomNumber(numberType, calculationLevel);
////		int luku2 = calculation.randomNumber(numberType, calculationLevel);
////		int muuttuja = calculation.randomNumber(NumberType::BOTH, 1);
////
////		calculation.correctAnswer = calculation.getCorrectAnswer(calculationType, luku, luku2);
////		std::string lasku = calculation.getCalculationString(calculationType, luku, luku2);
////		calculation.textCalculation.setString(lasku);
////
////		//std::string strPlayerAnswer = convertToString(playerAnswer);
////		//textPlayerAnswer.setString(strPlayerAnswer);
////
////		std::cout << "Anna vastaus" << std::endl;
////		if (calculation.answerIsCorrect)
////		{
////			std::cout << "Oikea vastaus on: " << calculation.correctAnswer << "	oikein!" << calculation.points << std::endl;
////			calculation.points++;
////			if (calculation.points == 5 || calculation.points == 10 || calculation.points == 15 || calculation.points == 20 || calculation.points == 25)
////			{
////				calculationLevel++;
////				std::cout << "taso nousi" << std::endl;
////			}
////		}
////		else if (!calculation.answerIsCorrect)
////		{
////			std::cout << "Oikea vastaus on: " << calculation.correctAnswer << "	kurahti..." << std::endl;
////			calculation.mistakes++;
////		}
////		std::cout << "Pisteet: " << calculation.points << ". Virheet: " << calculation.mistakes << "." << std::endl;
////		if (calculation.mistakes == 3)
////		{
////			std::cout << std::endl;
////			std::cout << "Peli loppui!" << std::endl;;
////		}
////		else
////		{
////			std::cout << std::endl;
////			std::cout << "Seuraava lasku:" << std::endl;;
////		}
////
////	}
////
////	return calculation.points;
////}
//
