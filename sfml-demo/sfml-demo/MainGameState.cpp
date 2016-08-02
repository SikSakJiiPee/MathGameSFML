#include "MainGameState.h"
#include "MenuState.h"
#include "CalculationState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

//#include <iostream>

MainGameState MainGameState::mainGameState;

void MainGameState::init()
{
	//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);

	//Tekstin alustus
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitleMainGame.setFont(font);
	textTitleMainGame.setCharacterSize(30);
	textTitleMainGame.setColor(sf::Color::White);

	textGame.setFont(font);
	textGame.setCharacterSize(30);
	textGame.setColor(sf::Color::White);

	textGame2.setFont(font);
	textGame2.setCharacterSize(30);
	textGame2.setColor(sf::Color::White);

	textGame3.setFont(font);
	textGame3.setCharacterSize(30);
	textGame3.setColor(sf::Color::White);

	textPlayerAnswer.setFont(font);
	textPlayerAnswer.setCharacterSize(30);
	textPlayerAnswer.setColor(sf::Color::White);

	textCorrectAnswer.setFont(font);
	textCorrectAnswer.setCharacterSize(30);
	textCorrectAnswer.setColor(sf::Color::White);

	textPoints.setFont(font);
	textPoints.setCharacterSize(30);
	textPoints.setColor(sf::Color::White);

	textMistakes.setFont(font);
	textMistakes.setCharacterSize(30);
	textMistakes.setColor(sf::Color::White);

	textTime.setFont(font);
	textTime.setCharacterSize(30);
	textTime.setColor(sf::Color::White);

	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);

	clock.restart();

	std::cout << "MainGameState init" << std::endl;
}

void MainGameState::cleanup()
{
	//State täytyy jotenkin tyhjentää
	textTitleMainGame.setString("");

	std::cout << "MainGameState cleanup" << std::endl;
}

void MainGameState::pause()
{
	//ajan pysäytys

	std::cout << "MainGameState pause" << std::endl;
}

void MainGameState::resume()
{


	std::cout << "MainGameState resume" << std::endl;
}

void MainGameState::handleInput(Game* game)
{

	while (game->window.pollEvent(game->evnt))
	{
		//closing the window
		if (game->evnt.type == sf::Event::Closed)
		{
			game->window.close();
		}
		
		//keyboard
		if (game->evnt.type == sf::Event::KeyPressed)
		{
			//Go to CalculationState
			if (game->evnt.key.code == sf::Keyboard::Return)
			{
				////calculationin alustus ja pelin käynnistys
				//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
				//calculationGame(calculation);

				game->pushState(CalculationState::instance());
			}
			//return to menu
			if (game->evnt.key.code == sf::Keyboard::Escape)
			{
				game->popState();
			}
		
		}
	}
	
}


void MainGameState::update(Game* game)
{

	
	timeElapsed = clock.getElapsedTime();
	timeLeft = 30 - timeElapsed.asSeconds();
	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;

	std::string strTimeLeft = convertToString(timeLeft);
	textTime.setString(strTimeLeft);

	
}

void MainGameState::draw(Game* game)
{
	game->window.clear(sf::Color::Black);

	textTitleMainGame.setString("MainGame");
	textTitleMainGame.setOrigin(textTitleMainGame.getGlobalBounds().width / 2, textTitleMainGame.getGlobalBounds().height / 2);
	textTitleMainGame.setPosition(game->window.getSize().x / 2, 10);
	


	game->window.draw(textTitleMainGame);
	game->window.draw(textTime);


	game->window.display();
}

//int MainGameState::calculationGame(Calculation calculation)
//{
//	calculationGameIsOn = true;
//
//	timeElapsed = clock.getElapsedTime();
//	timeLeft = calculation.calculationTime - timeElapsed.asSeconds();
//	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;
//
//	std::string strTimeLeft = convertToString(timeLeft);
//	textTime.setString(strTimeLeft);
//
//	CalculationType calculationType = calculation.calculationType;
//	NumberType numberType = calculation.numberType;
//	int calculationLevel = calculation.calculationLevel;
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
//		int luku = calculation.randomNumber(numberType, calculationLevel);
//		int luku2 = calculation.randomNumber(numberType, calculationLevel);
//		int muuttuja = calculation.randomNumber(NumberType::BOTH, 1);
//
//		correctAnswer = calculation.getCorrectAnswer(calculationType, luku, luku2);
//		std::string lasku = calculation.getCalculationString(calculationType, luku, luku2);
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
//
//	}
//
//
//	calculationGameIsOn = false;
//
//	return calculation.points;
//}