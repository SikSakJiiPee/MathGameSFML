#include "MainGameState.h"
#include "MenuState.h"
#include "CalculationState.h"

#include "Game.h"
#include "GameState.h"

//#include <SFML/Graphics.hpp>

//#include <iostream>


MainGameState::MainGameState(Game* game)
{
	this->game = game;

	//character
	characterPlayer = new Character(true, "player1", "Texture/Sprite/player1.png", 1, 0, 20, 20, 10, 10, 5, 5, 5);
	characterPlayer2 = new Character(true, "player2", "Texture/Sprite/player2.png", 1, 0, 20, 20, 10, 10, 5, 5, 5);
	characterPlayer3 = new Character(true, "player3", "Texture/Sprite/player3.png", 1, 0, 20, 20, 10, 10, 5, 5, 5);
	characterEnemy = new Character(false, "enemy1", "Texture/Sprite/enemy1.png", 1, 0, 20, 20, 10, 10, 5, 5, 5);
	characterEnemy2 = new Character(false, "enemy2", "Texture/Sprite/enemy2.png", 1, 0, 20, 20, 10, 10, 5, 5, 5);
	characterEnemy3 = new Character(false, "enemy3", "Texture/Sprite/enemy3.png", 1, 0, 20, 20, 10, 10, 5, 5, 5);
	
	//characters.push_back(characterPlayer);
	//characters.push_back(characterPlayer2);
	//characters.push_back(characterPlayer3);
	//characters.push_back(characterEnemy);
	//characters.push_back(characterEnemy2);
	//characters.push_back(characterEnemy3);


	//font and text
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitleMainGame.setFont(font);
	textTitleMainGame.setCharacterSize(30);
	textTitleMainGame.setColor(sf::Color::Black);

	textGame.setFont(font);
	textGame.setCharacterSize(20);
	textGame.setColor(sf::Color::White);
	//textGame.setString(characterPlayer->getStringCharacterInfo(*characterPlayer));
	//std::cout << characterPlayer->getStringCharacterInfo(*characterPlayer) << std::endl;

	textGame2.setFont(font);
	textGame2.setCharacterSize(30);
	textGame2.setColor(sf::Color::White);

	textGame3.setFont(font);
	textGame3.setCharacterSize(30);
	textGame3.setColor(sf::Color::White);

	textInfoPlayer.setFont(font);
	textInfoPlayer.setCharacterSize(30);
	textInfoPlayer.setColor(sf::Color::White);
	
	textInfoPlayer2.setFont(font);
	textInfoPlayer2.setCharacterSize(30);
	textInfoPlayer2.setColor(sf::Color::White);

	textInfoPlayer3.setFont(font);
	textInfoPlayer3.setCharacterSize(30);
	textInfoPlayer3.setColor(sf::Color::White);

	textInfoEnemy.setFont(font);
	textInfoEnemy.setCharacterSize(30);
	textInfoEnemy.setColor(sf::Color::White);
	

	textInfoEnemy2.setFont(font);
	textInfoEnemy2.setCharacterSize(30);
	textInfoEnemy2.setColor(sf::Color::White);
	textInfoEnemy2.setString(characterEnemy2->getStringCharacterInfo(*characterEnemy2));

	textInfoEnemy3.setFont(font);
	textInfoEnemy3.setCharacterSize(30);
	textInfoEnemy3.setColor(sf::Color::White);
	textInfoEnemy3.setString(characterEnemy3->getStringCharacterInfo(*characterEnemy3));

	textTime.setFont(font);
	textTime.setCharacterSize(30);
	textTime.setColor(sf::Color::Black);

	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);

	//texture and sprite
	//background
	if (!texturebgMainGame.loadFromFile("Texture/Background/bgTestBattle.png"))
	{
		std::cout << "Loading a texture failed" << std::endl;
	}
	spritebgMainGame.setTexture(texturebgMainGame);

	//character
	//spritesprPlayerCharacter = characterPlayer.spriteCharacter; //palauttaa spriten valkoisena
	texturesprPlayerCharacter = characterPlayer->textureCharacter;
	spritesprPlayerCharacter.setTexture(texturesprPlayerCharacter);
	spritesprPlayerCharacter.setPosition(sf::Vector2f((game->window.getSize().x / 8) * 1, (game->window.getSize().y / 3)));

	texturesprPlayerCharacter2 = characterPlayer2->textureCharacter;
	spritesprPlayerCharacter2.setTexture(texturesprPlayerCharacter2);
	spritesprPlayerCharacter2.setPosition(sf::Vector2f((game->window.getSize().x / 8) * 2, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9))));

	texturesprPlayerCharacter3 = characterPlayer3->textureCharacter;
	spritesprPlayerCharacter3.setTexture(texturesprPlayerCharacter3);
	spritesprPlayerCharacter3.setPosition(sf::Vector2f((game->window.getSize().x / 8) * 3, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2)));

	texturesprEnemyCharacter = characterEnemy->textureCharacter;
	spritesprEnemyCharacter.setTexture(texturesprEnemyCharacter);
	spritesprEnemyCharacter.setPosition(sf::Vector2f((game->window.getSize().x / 8) * 7, (game->window.getSize().y / 3)));
	
	texturesprEnemyCharacter2 = characterEnemy2->textureCharacter;
	spritesprEnemyCharacter2.setTexture(texturesprEnemyCharacter2);
	spritesprEnemyCharacter2.setPosition(sf::Vector2f((game->window.getSize().x / 8) * 6, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9))));

	texturesprEnemyCharacter3 = characterEnemy3->textureCharacter;
	spritesprEnemyCharacter3.setTexture(texturesprEnemyCharacter3);
	spritesprEnemyCharacter3.setPosition(sf::Vector2f((game->window.getSize().x / 8) * 5, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2)));



	//clock.restart();

	std::cout << "MainGameState init" << std::endl;
}

//void MainGameState::init()
//{
//	//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
//
//	//Tekstin alustus
//	if (!font.loadFromFile("Font/arial.ttf"))
//	{
//		std::cout << "Loading a font failed!" << std::endl;
//	}
//	textTitleMainGame.setFont(font);
//	textTitleMainGame.setCharacterSize(30);
//	textTitleMainGame.setColor(sf::Color::White);
//
//	textGame.setFont(font);
//	textGame.setCharacterSize(30);
//	textGame.setColor(sf::Color::White);
//
//	textGame2.setFont(font);
//	textGame2.setCharacterSize(30);
//	textGame2.setColor(sf::Color::White);
//
//	textGame3.setFont(font);
//	textGame3.setCharacterSize(30);
//	textGame3.setColor(sf::Color::White);
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
//
//	std::cout << "MainGameState init" << std::endl;
//}
//
//void MainGameState::cleanup()
//{
//	//State täytyy jotenkin tyhjentää
//	textTitleMainGame.setString("");
//
//	std::cout << "MainGameState cleanup" << std::endl;
//}
//
//void MainGameState::pause()
//{
//	//ajan pysäytys
//
//	std::cout << "MainGameState pause" << std::endl;
//}
//
//void MainGameState::resume()
//{
//
//
//	std::cout << "MainGameState resume" << std::endl;
//}

void MainGameState::handleInput()
{
	sf::Event evnt;

	while (this->game->window.pollEvent(evnt))
	{
		//closing the window
		if (evnt.type == sf::Event::Closed)
		{
			game->window.close();
		}
		
		//keyboard
		if (evnt.type == sf::Event::KeyPressed)
		{
			//Go to CalculationState
			if (evnt.key.code == sf::Keyboard::Return)
			{
				////calculationin alustus ja pelin käynnistys
				//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
				//calculationGame(calculation);
				this->startCalculation();
			}
			//return to menu
			if (evnt.key.code == sf::Keyboard::Escape)
			{
				this->backToMenu();
			}
			if (evnt.key.code == sf::Keyboard::F)
			{
				characterPlayer->healthPoints = 0;
			}
		}
	}

	return;
}


void MainGameState::update(const float dt)
{
	timeElapsed = clock.getElapsedTime();
	timeLeft = 30 - timeElapsed.asSeconds();
	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;

	std::string strTimeLeft = convertToString(timeLeft);
	textTime.setString(strTimeLeft);
}

void MainGameState::draw(const float dt)
{
	textTitleMainGame.setString("MainGame");
	textTitleMainGame.setOrigin(textTitleMainGame.getGlobalBounds().width / 2, textTitleMainGame.getGlobalBounds().height / 2);
	textTitleMainGame.setPosition(game->window.getSize().x / 2, 10);

	textInfoPlayer.setString(characterPlayer->getStringCharacterInfo(*characterPlayer));
	textInfoPlayer2.setString(characterPlayer2->getStringCharacterInfo(*characterPlayer2));
	textInfoPlayer3.setString(characterPlayer3->getStringCharacterInfo(*characterPlayer3));
	textInfoEnemy.setString(characterEnemy->getStringCharacterInfo(*characterEnemy));
	textInfoEnemy2.setString(characterEnemy2->getStringCharacterInfo(*characterEnemy2));
	textInfoEnemy3.setString(characterEnemy3->getStringCharacterInfo(*characterEnemy3));

	textInfoPlayer.setPosition(game->window.getSize().x / 4, 400);

	game->window.draw(spritebgMainGame);

	if (characterPlayer->checkIfAlive(*characterPlayer))
		game->window.draw(spritesprPlayerCharacter);
	if (characterPlayer2->checkIfAlive(*characterPlayer2))
		game->window.draw(spritesprPlayerCharacter2);
	if (characterPlayer3->checkIfAlive(*characterPlayer3))
		game->window.draw(spritesprPlayerCharacter3);
	if (characterEnemy->checkIfAlive(*characterEnemy))
		game->window.draw(spritesprEnemyCharacter);
	if (characterEnemy2->checkIfAlive(*characterEnemy2))
		game->window.draw(spritesprEnemyCharacter2);
	if (characterEnemy3->checkIfAlive(*characterEnemy3))
		game->window.draw(spritesprEnemyCharacter3);


	game->window.draw(textTitleMainGame);
	game->window.draw(textInfoPlayer);
	game->window.draw(textTime);
}


void MainGameState::startCalculation()
{
	this->game->pushState(new CalculationState(this->game));

	return;
}

void MainGameState::backToMenu()
{
	this->game->popState();

	return;
}







//#include "MainGameState.h"
//#include "MenuState.h"
//#include "CalculationState.h"
//
//#include "Game.h"
//#include "GameState.h"
//
////#include <SFML/Graphics.hpp>
//
////#include <iostream>
//
////MainGameState MainGameState::mainGameState;
//
//void MainGameState::init()
//{
//	//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
//
//	//Tekstin alustus
//	if (!font.loadFromFile("Font/arial.ttf"))
//	{
//		std::cout << "Loading a font failed!" << std::endl;
//	}
//	textTitleMainGame.setFont(font);
//	textTitleMainGame.setCharacterSize(30);
//	textTitleMainGame.setColor(sf::Color::White);
//
//	textGame.setFont(font);
//	textGame.setCharacterSize(30);
//	textGame.setColor(sf::Color::White);
//
//	textGame2.setFont(font);
//	textGame2.setCharacterSize(30);
//	textGame2.setColor(sf::Color::White);
//
//	textGame3.setFont(font);
//	textGame3.setCharacterSize(30);
//	textGame3.setColor(sf::Color::White);
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
//
//	std::cout << "MainGameState init" << std::endl;
//}
//
//void MainGameState::cleanup()
//{
//	//State täytyy jotenkin tyhjentää
//	textTitleMainGame.setString("");
//
//	std::cout << "MainGameState cleanup" << std::endl;
//}
//
//void MainGameState::pause()
//{
//	//ajan pysäytys
//
//	std::cout << "MainGameState pause" << std::endl;
//}
//
//void MainGameState::resume()
//{
//
//
//	std::cout << "MainGameState resume" << std::endl;
//}
//
//void MainGameState::handleInput(Game* game)
//{
//
//	while (game->window.pollEvent(game->evnt))
//	{
//		//closing the window
//		if (game->evnt.type == sf::Event::Closed)
//		{
//			game->window.close();
//		}
//		
//		//keyboard
//		if (game->evnt.type == sf::Event::KeyPressed)
//		{
//			//Go to CalculationState
//			if (game->evnt.key.code == sf::Keyboard::Return)
//			{
//				////calculationin alustus ja pelin käynnistys
//				//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
//				//calculationGame(calculation);
//
//				game->pushState(CalculationState::instance());
//			}
//			//return to menu
//			if (game->evnt.key.code == sf::Keyboard::Escape)
//			{
//				game->popState();
//			}
//		
//		}
//	}
//	
//}
//
//
//void MainGameState::update(Game* game)
//{
//
//	
//	timeElapsed = clock.getElapsedTime();
//	timeLeft = 30 - timeElapsed.asSeconds();
//	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;
//
//	std::string strTimeLeft = convertToString(timeLeft);
//	textTime.setString(strTimeLeft);
//
//	
//}
//
//void MainGameState::draw(Game* game)
//{
//	game->window.clear(sf::Color::Black);
//
//	textTitleMainGame.setString("MainGame");
//	textTitleMainGame.setOrigin(textTitleMainGame.getGlobalBounds().width / 2, textTitleMainGame.getGlobalBounds().height / 2);
//	textTitleMainGame.setPosition(game->window.getSize().x / 2, 10);
//	
//
//
//	game->window.draw(textTitleMainGame);
//	game->window.draw(textTime);
//
//
//	game->window.display();
//}
//
////int MainGameState::calculationGame(Calculation calculation)
////{
////	calculationGameIsOn = true;
////
////	timeElapsed = clock.getElapsedTime();
////	timeLeft = calculation.calculationTime - timeElapsed.asSeconds();
////	//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;
////
////	std::string strTimeLeft = convertToString(timeLeft);
////	textTime.setString(strTimeLeft);
////
////	CalculationType calculationType = calculation.calculationType;
////	NumberType numberType = calculation.numberType;
////	int calculationLevel = calculation.calculationLevel;
////
////	std::string strPlayerAnswer = convertToString(playerAnswer);
////
////	if (playerAnswer != -255)
////	{
////		textPlayerAnswer.setString(strPlayerAnswer);
////	}
////	if (playerAnswer == -255)
////	{
////		textPlayerAnswer.setString("Give the Answer");
////	}
////	if (playerAnswerNegative)
////	{
////		if (playerAnswer == -255)
////		{
////			textPlayerAnswer.setString(" - ");
////		}
////		else
////		{
////			textPlayerAnswer.setString("-" + strPlayerAnswer);
////		}
////
////	}
////
////	//std::cout << playerAnswer << std::endl;
////
////	while (mistakes < 3)
////	{
////		int luku = calculation.randomNumber(numberType, calculationLevel);
////		int luku2 = calculation.randomNumber(numberType, calculationLevel);
////		int muuttuja = calculation.randomNumber(NumberType::BOTH, 1);
////
////		correctAnswer = calculation.getCorrectAnswer(calculationType, luku, luku2);
////		std::string lasku = calculation.getCalculationString(calculationType, luku, luku2);
////		textCalculation.setString(lasku);
////
////		//std::string strPlayerAnswer = convertToString(playerAnswer);
////		//textPlayerAnswer.setString(strPlayerAnswer);
////
////		std::cout << "Anna vastaus" << std::endl;
////		if (answerIsCorrect)
////		{
////			std::cout << "Oikea vastaus on: " << correctAnswer << "	oikein!" << points << std::endl;
////			points++;
////			if (points == 5 || points == 10 || points == 15 || points == 20 || points == 25)
////			{
////				calculationLevel++;
////				std::cout << "taso nousi" << std::endl;
////			}
////		}
////		else if (!answerIsCorrect)
////		{
////			std::cout << "Oikea vastaus on: " << correctAnswer << "	kurahti..." << std::endl;
////			mistakes++;
////		}
////		std::cout << "Pisteet: " << points << ". Virheet: " << mistakes << "." << std::endl;
////		if (mistakes == 3)
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
////
////	calculationGameIsOn = false;
////
////	return calculation.points;
////}