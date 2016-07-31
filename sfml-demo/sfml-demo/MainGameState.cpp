#include "MainGameState.h"
#include "MenuState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

#include <iostream>

MainGameState MainGameState::mainGameState;

void MainGameState::init()
{
	//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);

	//Tekstin alustus
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textCalculation.setFont(font);
	textCalculation.setCharacterSize(30);
	textCalculation.setColor(sf::Color::White);

	textCalculation2.setFont(font);
	textCalculation2.setCharacterSize(30);
	textCalculation2.setColor(sf::Color::White);

	textCalculation3.setFont(font);
	textCalculation3.setCharacterSize(30);
	textCalculation3.setColor(sf::Color::White);

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


	std::cout << "MainGameState cleanup" << std::endl;
}

void MainGameState::pause()
{


	std::cout << "MainGameState pause" << std::endl;
}

void MainGameState::resume()
{


	std::cout << "MainGameState resume" << std::endl;
}

void MainGameState::handleInput(Game* game)
{
	//if (!calculationGameIsOn)
	//{
	//	while (game->window.pollEvent(game->evnt))
	//	{
	//		if (game->evnt.type == sf::Event::Closed)
	//		{
	//			game->window.close();
	//		}
	//		if (game->evnt.type == sf::Event::KeyPressed)
	//		{
	//			if (game->evnt.key.code == sf::Keyboard::Return)
	//			{
	//				//calculationin alustus ja pelin käynnistys
	//				Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);

	//				calculationGameIsOn = true;
	//			}
	//			if (game->evnt.key.code == sf::Keyboard::Escape)
	//			{
	//				game->window.close();
	//				game->cleanup();
	//			}
	//		}
	//	}
	//}
	//else if (calculationGameIsOn)
	//{
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
				//comparing the answer
				if (game->evnt.key.code == sf::Keyboard::Return)
				{
					//ei valmis
					if (playerAnswerNegative == true)
					{
						playerAnswer *= -1;
					}

					//vastauksien vertaaminen
					if (playerAnswer == correctAnswer)
					{
						answerIsCorrect = true;
					}
					else
					{
						answerIsCorrect = false;
						playerAnswer = -255;
					}
					playerAnswerNegative = false;
				}

				//the numbers
				if (game->evnt.key.code == sf::Keyboard::Num0)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 0;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = playerAnswer * 10;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num1)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 1;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 1;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num2)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 2;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 2;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num3)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 3;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 3;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num4)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 4;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 4;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num5)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 5;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 5;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num6)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 6;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 6;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num7)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 7;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 7;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num8)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 8;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 8;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Num9)
				{
					if (playerAnswer == -255)
					{
						playerAnswer = 9;
					}
					else if (playerAnswer > 100000)
					{
						playerAnswer += 0;
					}
					else
					{
						playerAnswer = (playerAnswer * 10) + 9;
					}
				}
				if (game->evnt.key.code == sf::Keyboard::Subtract || game->evnt.key.code == sf::Keyboard::Dash)
				{
					playerAnswerNegative = true;
				}
			}
		}
	}
	
//}

void MainGameState::update(Game* game)
{
	Calculation calculationPlus(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
	Calculation calculationMinus(CalculationType::MINUS, NumberType::POSITIVE, 1, 30);
	
	timeElapsed = clock.getElapsedTime();
	timeLeft = calculationPlus.calculationTime - timeElapsed.asSeconds();
	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;

	std::string strTimeLeft = convertToString(timeLeft);
	textTime.setString(strTimeLeft);

	CalculationType calculationType = calculationPlus.calculationType;
	NumberType numberType = calculationPlus.numberType;
	int calculationLevel = calculationPlus.calculationLevel;
	
	std::string strPlayerAnswer = convertToString(playerAnswer);

	if (playerAnswer != -255)
	{
		textPlayerAnswer.setString(strPlayerAnswer);
	}
	if (playerAnswer == -255)
	{
		textPlayerAnswer.setString("Give the Answer");
	}
	if (playerAnswerNegative)
	{
		if (playerAnswer == -255)
		{
			textPlayerAnswer.setString(" - ");
		}
		else
		{
			textPlayerAnswer.setString("-" + strPlayerAnswer);
		}

	}

	//std::cout << playerAnswer << std::endl;

	while (virheet < 3)
	{
		int luku = calculationPlus.randomNumber(numberType, calculationLevel);
		int luku2 = calculationPlus.randomNumber(numberType, calculationLevel);
		int muuttuja = calculationPlus.randomNumber(NumberType::BOTH, 1);
		
		correctAnswer = calculationPlus.getCorrectAnswer(calculationType, luku, luku2);
		std::string lasku = calculationPlus.getCalculationString(calculationType, luku, luku2);
		textCalculation.setString(lasku);

		//std::string strPlayerAnswer = convertToString(playerAnswer);
		//textPlayerAnswer.setString(strPlayerAnswer);

		std::cout << "Anna vastaus" << std::endl;
		if (answerIsCorrect)
		{
			std::cout << "Oikea vastaus on: " << correctAnswer << "	oikein!" << pisteet << std::endl;
			pisteet++;
			if (pisteet == 5 || pisteet == 10 || pisteet == 15 || pisteet == 20 || pisteet == 25)
			{
				calculationLevel++;
				std::cout << "taso nousi" << std::endl;
			}
		}
		else if (!answerIsCorrect)
		{
			std::cout << "Oikea vastaus on: " << correctAnswer << "	kurahti..." << std::endl;
			virheet++;
		}
		std::cout << "Pisteet: " << pisteet << ". Virheet: " << virheet << "." << std::endl;
		if (virheet == 3)
		{
			std::cout << std::endl;
			std::cout << "Peli loppui!" << std::endl;;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Seuraava lasku:" << std::endl;;
		}
				
	}
	
}

void MainGameState::draw(Game* game)
{
	game->window.clear(sf::Color::Black);

	textCalculation.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
	textCalculation.setPosition(game->window.getSize().x / 2, game->window.getSize().y / 3);
	
	textPlayerAnswer.setOrigin(textPlayerAnswer.getGlobalBounds().width / 2, textPlayerAnswer.getGlobalBounds().height);
	textPlayerAnswer.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 3) * 2);

	game->window.draw(textTime);
	game->window.draw(textCalculation);
	game->window.draw(textPlayerAnswer);

	game->window.display();
}
