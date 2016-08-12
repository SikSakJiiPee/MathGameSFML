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

	selection = Selection::ATTACK;
	//selectionCharacter = SelectionCharacter::NONE;

	//Character
	characters.push_back(new Character(true, "Player1", "Texture/Sprite/player1.png", 1, 0, 20, 20, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 3, (game->window.getSize().y / 3))));
	characters.push_back(new Character(true, "Player2", "Texture/Sprite/player2.png", 1, 0, 20, 20, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 2, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9)))));
	characters.push_back(new Character(true, "Player3", "Texture/Sprite/player3.png", 1, 0, 20, 20, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 1, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2))));
	characters.push_back(new Character(false, "Enemy1", "Texture/Sprite/enemy1.png", 1, 0, 20, 20, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 5, (game->window.getSize().y / 3))));
	characters.push_back(new Character(false, "Enemy2", "Texture/Sprite/enemy2.png", 1, 0, 20, 20, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 6, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9)))));
	characters.push_back(new Character(false, "Enemy3", "Texture/Sprite/enemy3.png", 1, 0, 20, 20, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 7, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2))));
	

	//characters.push_back(characterPlayer);
	//characters.push_back(characterPlayer2);
	//characters.push_back(characterPlayer3);
	//characters.push_back(characterEnemy);
	//characters.push_back(characterEnemy2);
	//characters.push_back(characterEnemy3);
	//järjestä characterit myöhemmin nopeusjärjestykseen

	//Item
	item = new Item("Potion");
	//item = new Item("Potion2");
	if (getPlayerCharacter(0) != nullptr)
		getPlayerCharacter(0)->items.push_back(*item);


	//Font and Text
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitleMainGame.setFont(font);
	textTitleMainGame.setCharacterSize(30);
	textTitleMainGame.setColor(sf::Color::Black);

	//valintaa varten värin (ja koon?) alustuksen voi siirtää myöhemmin updateen.
	textGameAttack.setFont(font);
	textGameAttack.setCharacterSize(24);
	textGameAttack.setColor(sf::Color::Black);
	textGameAttack.setString("Attack");

	textGameSpecial.setFont(font);
	textGameSpecial.setCharacterSize(24);
	textGameSpecial.setColor(sf::Color::Black);
	textGameSpecial.setString("Special");

	textGameItem.setFont(font);
	textGameItem.setCharacterSize(24);
	textGameItem.setColor(sf::Color::Black);
	textGameItem.setString("Item");

	textGameEscape.setFont(font);
	textGameEscape.setCharacterSize(24);
	textGameEscape.setColor(sf::Color::Black);
	textGameEscape.setString("Escape");

	textInfoPlayer.setFont(font);
	textInfoPlayer.setCharacterSize(20);
	textInfoPlayer.setColor(sf::Color::Black);
	
	textInfoPlayer2.setFont(font);
	textInfoPlayer2.setCharacterSize(20);
	textInfoPlayer2.setColor(sf::Color::Black);

	textInfoPlayer3.setFont(font);
	textInfoPlayer3.setCharacterSize(20);
	textInfoPlayer3.setColor(sf::Color::Black);

	textInfoEnemy.setFont(font);
	textInfoEnemy.setCharacterSize(20);
	textInfoEnemy.setColor(sf::Color::Black);

	textInfoEnemy2.setFont(font);
	textInfoEnemy2.setCharacterSize(20);
	textInfoEnemy2.setColor(sf::Color::Black);

	textInfoEnemy3.setFont(font);
	textInfoEnemy3.setCharacterSize(20);
	textInfoEnemy3.setColor(sf::Color::Black);

	//item
	textInfoItem.setFont(font);
	textInfoItem.setCharacterSize(20);
	textInfoItem.setColor(sf::Color::Black);
	textInfoItem.setString(item->getStringItemInfo(*item));

	textInfoItem2.setFont(font);
	textInfoItem2.setCharacterSize(20);
	textInfoItem2.setColor(sf::Color::Black);
	//textInfoItem2.setString(item2->getStringItemInfo(*item2));

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
	



	//clock.restart();

	std::cout << "MainGameState init" << std::endl;
}

MainGameState::~MainGameState()
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		delete characters[i];
	}
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
			if (selectPlayer)
			{
				if (evnt.key.code == sf::Keyboard::Down)
				{
					if (selection == Selection::PLAYER2)
					{
						selection = Selection::PLAYER3;
					}
					if (selection == Selection::PLAYER1)
					{
						selection = Selection::PLAYER2;
					}
				}
				if (evnt.key.code == sf::Keyboard::Up)
				{
					if (selection == Selection::PLAYER2)
					{
						selection = Selection::PLAYER1;
					}
					if (selection == Selection::PLAYER3)
					{
						selection = Selection::PLAYER2;
					}
				}
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					selectPlayer = false;
					selection = Selection::ATTACK;
				}
				if (evnt.key.code == sf::Keyboard::Return)
				{

				}
			}
			if (selectEnemy)
			{
				if (evnt.key.code == sf::Keyboard::Down)
				{
					if (selection == Selection::ENEMY2)
					{
						selection = Selection::ENEMY3;
					}
					if (selection == Selection::ENEMY1)
					{
						selection = Selection::ENEMY2;
					}
				}
				if (evnt.key.code == sf::Keyboard::Up)
				{
					if (selection == Selection::ENEMY2)
					{
						selection = Selection::ENEMY1;
					}
					if (selection == Selection::ENEMY3)
					{
						selection = Selection::ENEMY2;
					}
				}
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					selectEnemy = false;
					selection = Selection::ATTACK;
				}
				if (evnt.key.code == sf::Keyboard::Return)
				{
					calculationIsOn = true;
					this->startCalculation(/*characterPlayer, characterEnemy*/);
					//if (selection == Selection::ENEMY1) 
						//characterEnemy->healthPoints -= CalculationState::points;
					calculationIsOn = false;
				}
			}
			
			if (!selectCharacter && !selectPlayer && !selectEnemy)
			{
				if (evnt.key.code == sf::Keyboard::F)
				{
					if (getPlayerCharacter(0) != nullptr)
						getPlayerCharacter(0)->healthPoints = 0;
				}
					
				//Go to CalculationState
				if (evnt.key.code == sf::Keyboard::Return)
				{
					if (selection == Selection::ATTACK)
					{
						selectEnemy = true;
						selection = Selection::ENEMY1;
						//selectionCharacter = SelectionCharacter::PLAYER1;
						if (evnt.key.code == sf::Keyboard::Escape)
						{
							////calculationin alustus ja pelin käynnistys
							//Calculation calculation(CalculationType::PLUS, NumberType::POSITIVE, 1, 30);
							//calculationGame(calculation);
							//this->startCalculation();
						}
					}
					if (selection == Selection::SPECIAL)
					{
						std::cout << "Special selected" << std::endl;
					}
					if (selection == Selection::ITEM)
					{
						selectItem = true;
						std::cout << "Item selected" << std::endl;
					}
					if (selection == Selection::ESCAPE)
					{
						std::cout << "Escape selected" << std::endl;
					}
				}
				//return to menu
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					this->backToMenu();
				}

				//selection
				if (evnt.key.code == sf::Keyboard::Right)
				{
					if (selection == Selection::ATTACK)
					{
						selection = Selection::SPECIAL;
					}
					if (selection == Selection::ITEM)
					{
						selection = Selection::ESCAPE;
					}
				}
				if (evnt.key.code == sf::Keyboard::Left)
				{
					if (selection == Selection::SPECIAL)
					{
						selection = Selection::ATTACK;
					}
					if (selection == Selection::ESCAPE)
					{
						selection = Selection::ITEM;
					}
				}
				if (evnt.key.code == sf::Keyboard::Down)
				{
					if (selection == Selection::ATTACK)
					{
						selection = Selection::ITEM;
					}
					if (selection == Selection::SPECIAL)
					{
						selection = Selection::ESCAPE;
					}
				}
				if (evnt.key.code == sf::Keyboard::Up)
				{
					if (selection == Selection::ITEM)
					{
						selection = Selection::ATTACK;
					}
					if (selection == Selection::ESCAPE)
					{
						selection = Selection::SPECIAL;
					}
				}
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
	//textTitleMainGame.setString("MainGame");
	//textTitleMainGame.setOrigin(textTitleMainGame.getGlobalBounds().width / 2, textTitleMainGame.getGlobalBounds().height / 2);
	//textTitleMainGame.setPosition(game->window.getSize().x / 2, 10);

	////UPDATE
	//Text
	//info
	if (selection == Selection::PLAYER1)
		textInfoPlayer.setColor(sf::Color::Blue);
	else
		textInfoPlayer.setColor(sf::Color::Black);
	//
	if (selection == Selection::PLAYER2)
		textInfoPlayer2.setColor(sf::Color::Blue);
	else
		textInfoPlayer2.setColor(sf::Color::Black);
	//
	if (selection == Selection::PLAYER3)
		textInfoPlayer3.setColor(sf::Color::Blue);
	else
		textInfoPlayer3.setColor(sf::Color::Black);
	//
	if (selection == Selection::ENEMY1)
		textInfoEnemy.setColor(sf::Color::Red);
	else
		textInfoEnemy.setColor(sf::Color::Black);
	//
	if (selection == Selection::ENEMY2)
		textInfoEnemy2.setColor(sf::Color::Red);
	else
		textInfoEnemy2.setColor(sf::Color::Black);
	//
	if (selection == Selection::ENEMY3)
		textInfoEnemy3.setColor(sf::Color::Red);
	else
		textInfoEnemy3.setColor(sf::Color::Black);

	//if (selectionCharacter == SelectionCharacter::PLAYER1)
	//	textInfoPlayer.setColor(sf::Color::White);
	//else
	//	textInfoPlayer.setColor(sf::Color::Black);
	////
	//if (selectionCharacter == SelectionCharacter::PLAYER2)
	//	textInfoPlayer2.setColor(sf::Color::White);
	//else
	//	textInfoPlayer2.setColor(sf::Color::Black);
	////
	//if (selectionCharacter == SelectionCharacter::PLAYER3)
	//	textInfoPlayer3.setColor(sf::Color::White);
	//else
	//	textInfoPlayer3.setColor(sf::Color::Black);
	////
	//if (selectionCharacter == SelectionCharacter::ENEMY1)
	//	textInfoEnemy.setColor(sf::Color::White);
	//else
	//	textInfoEnemy.setColor(sf::Color::Black);
	////
	//if (selectionCharacter == SelectionCharacter::ENEMY2)
	//	textInfoEnemy2.setColor(sf::Color::White);
	//else
	//	textInfoEnemy2.setColor(sf::Color::Black);
	////
	//if (selectionCharacter == SelectionCharacter::ENEMY3)
	//	textInfoEnemy3.setColor(sf::Color::White);
	//else
	//	textInfoEnemy3.setColor(sf::Color::Black);

	//selvitä tapa toteuttaa infot tekstivektoreilla tai character attribuutilla
	if (getPlayerCharacter(0) != nullptr)
		textInfoPlayer.setString(getPlayerCharacter(0)->getStringCharacterInfo(*getPlayerCharacter(0)));
	if (getPlayerCharacter(1) != nullptr)
		textInfoPlayer2.setString(getPlayerCharacter(1)->getStringCharacterInfo(*getPlayerCharacter(1)));
	if (getPlayerCharacter(2) != nullptr)
		textInfoPlayer3.setString(getPlayerCharacter(2)->getStringCharacterInfo(*getPlayerCharacter(2)));
	if (getEnemyCharacter(0) != nullptr)
		textInfoEnemy.setString(getEnemyCharacter(0)->getStringCharacterInfo(*getEnemyCharacter(0)));
	if (getEnemyCharacter(1) != nullptr)
		textInfoEnemy2.setString(getEnemyCharacter(1)->getStringCharacterInfo(*getEnemyCharacter(1)));
	if (getEnemyCharacter(2) != nullptr)
		textInfoEnemy3.setString(getEnemyCharacter(2)->getStringCharacterInfo(*getEnemyCharacter(2)));

	textInfoPlayer.setPosition(0, 0);
	textInfoPlayer2.setPosition(0, (game->window.getSize().y / 18));
	textInfoPlayer3.setPosition(0, (game->window.getSize().y / 18) * 2);
	textInfoEnemy.setPosition(game->window.getSize().x / 2, 0);
	textInfoEnemy2.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 18));
	textInfoEnemy3.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 18) * 2);

	textInfoItem.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 16);
	textInfoItem.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 17);

	
	//selection
	if (selection == Selection::ATTACK)
		textGameAttack.setColor(sf::Color::White);
	else
		textGameAttack.setColor(sf::Color::Black);
	//
	if (selection == Selection::ITEM)
		textGameItem.setColor(sf::Color::White);
	else
		textGameItem.setColor(sf::Color::Black);
	//
	if (selection == Selection::SPECIAL)
		textGameSpecial.setColor(sf::Color::White);
	else
		textGameSpecial.setColor(sf::Color::Black);
	//
	if (selection == Selection::ESCAPE)
		textGameEscape.setColor(sf::Color::White);
	else
		textGameEscape.setColor(sf::Color::Black);

	textGameAttack.setPosition(0, (game->window.getSize().y / 18) * 16);
	textGameItem.setPosition(0, (game->window.getSize().y / 18) * 17);
	textGameSpecial.setPosition(game->window.getSize().x / 4, (game->window.getSize().y / 18) * 16);
	textGameEscape.setPosition(game->window.getSize().x / 4, (game->window.getSize().y / 18) * 17);



	////DRAW
	//Sprite
	//background
	game->window.draw(spritebgMainGame);

	//character
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->checkIfAlive())
			game->window.draw(characters[i]->spriteCharacter);
	}

	//Text
	//game->window.draw(textTitleMainGame);
	//game->window.draw(textTime);

	//info
	game->window.draw(textInfoPlayer);
	game->window.draw(textInfoPlayer2);
	game->window.draw(textInfoPlayer3);
	game->window.draw(textInfoEnemy);
	game->window.draw(textInfoEnemy2);
	game->window.draw(textInfoEnemy3);
	if (selectItem)
	{
		game->window.draw(textInfoItem);
		//game->window.draw(textInfoItem2);
	}

	//selection
	game->window.draw(textGameAttack);
	game->window.draw(textGameItem);
	game->window.draw(textGameSpecial);
	game->window.draw(textGameEscape);
	
}


void MainGameState::startCalculation(/*Character* attacker, Character* defender*/)
{
	this->game->pushState(new CalculationState(this->game/*, attacker, defender*/));

	return;
}

void MainGameState::backToMenu()
{
	this->game->popState();

	return;
}


//character vector management
size_t MainGameState::getPlayerCharacterCount()
{
	size_t count(0);

	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->isPlayerCharacter)
			count++;
	}

	return count;
}
size_t MainGameState::getEnemyCharacterCount()
{
	size_t count(0);

	for (size_t i = 0; i < characters.size(); i++)
	{
		if (!characters[i]->isPlayerCharacter)
			count++;
	}

	return count;
}

Character* MainGameState::getPlayerCharacter(int index)
{
	size_t count(0);

	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->isPlayerCharacter)
		{
			if (count == index)
				return characters[i];

			count++;
		}
	}

	return nullptr;
}
Character* MainGameState::getEnemyCharacter(int index)
{
	size_t count(0);

	for (size_t i = 0; i < characters.size(); i++)
	{
		if (!characters[i]->isPlayerCharacter)
		{
			if (count == index)
				return characters[i];

			count++;
		}
	}

	return nullptr;
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