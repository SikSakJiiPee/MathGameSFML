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

	//Character
	characters.push_back(new Character(true, "Player1", "Texture/Sprite/player1.png", 1, 0, 200, 200, 10, 10, 5, 5, 6, sf::Vector2f((game->window.getSize().x / 8) * 3, (game->window.getSize().y / 3))));
	characters.push_back(new Character(true, "Player2", "Texture/Sprite/player2.png", 1, 0, 200, 200, 10, 10, 5, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 2, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9)))));
	characters.push_back(new Character(true, "Player3", "Texture/Sprite/player3.png", 1, 0, 200, 200, 10, 10, 5, 5, 4, sf::Vector2f((game->window.getSize().x / 8) * 1, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2))));
	characters.push_back(new Character(false, "Enemy1", "Texture/Sprite/enemy1.png", 1, 0, 200, 200, 10, 10, 5, 5, 3, sf::Vector2f((game->window.getSize().x / 8) * 5, (game->window.getSize().y / 3))));
	characters.push_back(new Character(false, "Enemy2", "Texture/Sprite/enemy2.png", 1, 0, 200, 200, 10, 10, 5, 5, 2, sf::Vector2f((game->window.getSize().x / 8) * 6, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9)))));
	characters.push_back(new Character(false, "Enemy3", "Texture/Sprite/enemy3.png", 1, 0, 200, 200, 10, 10, 5, 5, 1, sf::Vector2f((game->window.getSize().x / 8) * 7, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2))));
	
	//järjestä characterit myöhemmin nopeusjärjestykseen

	//
	//SpecialMoves

	
	//
	//Item
	item = new Item("Potion");
	//item = new Item("Potion2");
	if (getPlayerCharacter(0) != nullptr)
		getPlayerCharacter(0)->items.push_back(*item);

	//
	//Equipment
	//armor
	eqArmor = new Equipment("Basic Armor", EquipmentType::ARMOR, 20, 1, 50, 0, 5, 0, 0, 0);
	//eqArmor2 = new Equipment("Basic Armor", EquipmentType::ARMOR, 20, 1, 50, 0, 10, 0, 0, 0);
	//weapon
	eqWeapon = new Equipment("Basic Weapon", EquipmentType::WEAPON, 15, 1, 50, 7, 0, 0, 0, 0);

	//pushing equipments to every character
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i]->equipments.push_back(*eqArmor);
		characters[i]->equipments.push_back(*eqWeapon);
	}

	//applying stats from the equipments
	for (size_t i = 0; i < characters.size(); i++)
	{
		for (size_t j = 0; j < characters[i]->equipments.size(); j++)
		{
			characters[i]->maxHp += characters[i]->equipments[j].healthPoints;
			characters[i]->maxSp += characters[i]->equipments[j].specialPoints;
			characters[i]->attack += characters[i]->equipments[j].attack;
			characters[i]->defence += characters[i]->equipments[j].defence;
			characters[i]->speed += characters[i]->equipments[j].speed;
		}
	}

	//
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

	//clock.restart();

	textTime.setFont(font);
	textTime.setCharacterSize(30);
	textTime.setColor(sf::Color::Black);

	//-----------




	//COMBATPHASE
	textTitleCalc.setFont(font);
	textTitleCalc.setCharacterSize(30);
	textTitleCalc.setColor(sf::Color::Black);

	textCalculation.setFont(font);
	textCalculation.setCharacterSize(30);
	textCalculation.setColor(sf::Color::Black);
	
	textCalculation2.setFont(font);
	textCalculation2.setCharacterSize(30);
	textCalculation2.setColor(sf::Color::Black);
	
	textCalculation3.setFont(font);
	textCalculation3.setCharacterSize(30);
	textCalculation3.setColor(sf::Color::Black);
	
	textPlayerAnswer.setFont(font);
	textPlayerAnswer.setCharacterSize(30);
	textPlayerAnswer.setColor(sf::Color::Black);
	
	textCorrectAnswer.setFont(font);
	textCorrectAnswer.setCharacterSize(30);
	textCorrectAnswer.setColor(sf::Color::Black);
	
	textPoints.setFont(font);
	textPoints.setCharacterSize(30);
	textPoints.setColor(sf::Color::Black);
	
	textMistakes.setFont(font);
	textMistakes.setCharacterSize(30);
	textMistakes.setColor(sf::Color::Black);
	
	textCurrentCombo.setFont(font);
	textCurrentCombo.setCharacterSize(30);
	textCurrentCombo.setColor(sf::Color::Black);
	
	textMaxCombo.setFont(font);
	textMaxCombo.setCharacterSize(30);
	textMaxCombo.setColor(sf::Color::Black);
	
	textTimeLeft.setFont(font);
	textTimeLeft.setCharacterSize(30);

	std::cout << "MainGameState init" << std::endl;
}

MainGameState::~MainGameState()
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		delete characters[i];
	}

	//selvitä tarvitseeko jonkun paremman systeemin itemien poistoon
	delete item;

	delete eqArmor;
	delete eqWeapon;

	//selvitä poistuuko kaikki itemit, equipit ja specialit poistettaessa characterit
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
	
	//korjaa ongelma valintojen "nopeuden" kansssa
	while (this->game->window.pollEvent(evnt))
	{
		if (!calculationGameIsOn)
		{
			//closing the window
			if (evnt.type == sf::Event::Closed)
			{
				game->window.close();
			}

			//keyboard
			if (evnt.type == sf::Event::KeyPressed)
			{
				//selecting the player target
				if (selectPlayer)
				{
					for (size_t i = 0; i < characters.size(); i++)
					{
						characters[i]->isSelected = false;
					}

					if (evnt.key.code == sf::Keyboard::Down)
					{
						selectedPlayer++;

						if (selectedPlayer >= getPlayerCharacterCount() - 1)
							selectedPlayer = getPlayerCharacterCount() - 1;
					}
					if (evnt.key.code == sf::Keyboard::Up)
					{
						selectedPlayer--;

						if (selectedPlayer <= 0)
							selectedPlayer = 0;
					}
					if (getPlayerCharacter(selectedPlayer) != false)
					{
						getPlayerCharacter(selectedPlayer)->isSelected = true;
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
				//selecting the enemy target
				if (selectEnemy)
				{
					for (size_t i = 0; i < characters.size(); i++)
					{
						characters[i]->isSelected = false;
					}

					if (evnt.key.code == sf::Keyboard::Down)
					{
						selectedEnemy++;

						if (selectedEnemy >= getEnemyCharacterCount() - 1)
							selectedEnemy = getEnemyCharacterCount() - 1;
					}
					if (evnt.key.code == sf::Keyboard::Up)
					{
						selectedEnemy--;
						
						if (selectedEnemy <= 0)
							selectedEnemy = 0;
					}
					if (getEnemyCharacter(selectedEnemy) != false)
					{
						getEnemyCharacter(selectedEnemy)->isSelected = true;
					}

					if (evnt.key.code == sf::Keyboard::Escape)
					{
						selectEnemy = false;
						selection = Selection::ATTACK;
					}
					if (evnt.key.code == sf::Keyboard::Return)
					{
						initCalculation();
					}
				}

				//selecting the action
				if (!selectCharacter && !selectPlayer && !selectEnemy)
				{
					if (evnt.key.code == sf::Keyboard::F)
					{
						if (getPlayerCharacter(0) != nullptr)
							getPlayerCharacter(0)->healthPoints = 0;
						if (getPlayerCharacter(1) != nullptr)
							getPlayerCharacter(1)->healthPoints = 0;
						if (getPlayerCharacter(2) != nullptr)
							getPlayerCharacter(2)->healthPoints = 0;

						//characters.back()->healthPoints = 0;
					}

					//Go to CalculationState
					if (evnt.key.code == sf::Keyboard::Return)
					{
						if (selection == Selection::ATTACK)
						{
							selectEnemy = true;
							if (getEnemyCharacter(0) != false)
								getEnemyCharacter(0)->isSelected = true;
							selection = Selection::NONE;
							if (evnt.key.code == sf::Keyboard::Escape)
							{

							}
						}
						if (selection == Selection::SPECIAL)
						{
							selectPlayer = true;
							if (getPlayerCharacter(0) != false)
								getPlayerCharacter(0)->isSelected = true;
							selection = Selection::NONE;

							std::cout << "Special selected" << std::endl;
						}
						if (selection == Selection::ITEM)
						{
							selectItem = true;

							std::cout << "Item selected" << std::endl;
						}
						if (selection == Selection::ESCAPE)
						{
							escapeCalculation = true;
							initCalculation();
							std::cout << "Escape selected" << std::endl;
						}
					}
					//return to menu
					if (evnt.key.code == sf::Keyboard::Escape)
					{
						this->backToMenu();
					}

					//selection (action)
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
		//------------------



		//during calculation
		if (calculationGameIsOn)
		{
			//closing the window
			if (evnt.type == sf::Event::Closed)
			{
				game->window.close();
			}
			if (evnt.type == sf::Event::KeyPressed)
			{

				//closing the window
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					uninitCalculation();
				}

				//comparing the answer
				if (evnt.key.code == sf::Keyboard::Return)
				{
					answerIsChecked = true;
					//answerIsChecked2 = true;
					//answerIsChecked3 = true;
				
					//ei valmis
					if (playerAnswerNegative == true)
					{
						playerAnswer *= -1;
					}
					std::cout << "sinun vastaus: " << playerAnswer << std::endl;
					//std::cout << "oikea vastaus1: " << correctAnswer << std::endl;
					//std::cout << "oikea vastaus2: " << correctAnswer2 << std::endl;
					//std::cout << "oikea vastaus3: " << correctAnswer3 << std::endl;
				
					//vastauksien vertaaminen
					if (playerAnswer == correctAnswer)
					{
						answerIsCorrect = true;
					}
					//else if (playerAnswer == correctAnswer2)
					//{
					//	answerIsCorrect2 = true;
					//}
					//else if (playerAnswer == correctAnswer3)
					//{
					//	answerIsCorrect3 = true;
					//}
					else if (playerAnswer != correctAnswer)
					{
						answerIsCorrect = false;
						//playerAnswer = -255;
					}
					//else if (playerAnswer != correctAnswer2)
					//{
					//	answerIsCorrect2 = false;
					//	//playerAnswer = -255;
					//}
					//else if (playerAnswer != correctAnswer3)
					//{
					//	answerIsCorrect3 = false;
					//	//playerAnswer = -255;
					//}
					playerAnswer = -255;
					playerAnswerNegative = false;
				}
				
				//the numbers
				if (evnt.key.code == sf::Keyboard::Num0 || evnt.key.code == sf::Keyboard::Numpad0)
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
				if (evnt.key.code == sf::Keyboard::Num1 || evnt.key.code == sf::Keyboard::Numpad1)
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
				if (evnt.key.code == sf::Keyboard::Num2 || evnt.key.code == sf::Keyboard::Numpad2)
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
				if (evnt.key.code == sf::Keyboard::Num3 || evnt.key.code == sf::Keyboard::Numpad3)
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
				if (evnt.key.code == sf::Keyboard::Num4 || evnt.key.code == sf::Keyboard::Numpad4)
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
				if (evnt.key.code == sf::Keyboard::Num5 || evnt.key.code == sf::Keyboard::Numpad5)
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
				if (evnt.key.code == sf::Keyboard::Num6 || evnt.key.code == sf::Keyboard::Numpad6)
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
				if (evnt.key.code == sf::Keyboard::Num7 || evnt.key.code == sf::Keyboard::Numpad7)
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
				if (evnt.key.code == sf::Keyboard::Num8 || evnt.key.code == sf::Keyboard::Numpad8)
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
				if (evnt.key.code == sf::Keyboard::Num9 || evnt.key.code == sf::Keyboard::Numpad9)
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
				if (evnt.key.code == sf::Keyboard::Subtract || evnt.key.code == sf::Keyboard::Dash)
				{
					playerAnswerNegative = true;
				}
				
			}
		}
	}

	return;
}


void MainGameState::update(const float dt)
{
	if (!calculationGameIsOn)
	{
		//timeElapsed = clock.getElapsedTime();
		//timeLeft = 30 - timeElapsed.asSeconds();
		////std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;

		//std::string strTimeLeft = convertToString(timeLeft);
		//textTime.setString(strTimeLeft);
	}
	//------------------

	//during calculation
	if (calculationGameIsOn)
	{
		
		
		//timer
		timeElapsed = clock.getElapsedTime();
		timeLeft = 15 - timeElapsed.asSeconds();
		//std::cout << timeElapsed.asSeconds() << " " << timeLeft << std::endl;
		std::string strTimeLeft = convertToString(timeLeft);
		textTimeLeft.setString(strTimeLeft);
		
		if (timeLeft <= 0)
		{
			if (getEnemyCharacter(selectedEnemy) != false || getPlayerCharacter(0) != false)
			{
				damageDealt = (points * getPlayerCharacter(0)->attack);
				damageReflected = (((randomNumber(NumberType::POSITIVE, 1)) * getEnemyCharacter(selectedEnemy)->defence) / 2);
				damageTotal = damageDealt - damageReflected;
				if (damageDealt < damageReflected)
					damageTotal = 0;

				std::cout << getEnemyCharacter(selectedEnemy)->defence << std::endl;
				std::cout << "damageDealt: " << damageDealt << "  damageReflected: " << damageReflected << std::endl;
				std::cout << "damageTotal: " << damageTotal << std::endl;

				getEnemyCharacter(selectedEnemy)->healthPoints -= damageTotal;

				if (getEnemyCharacter(selectedEnemy)->healthPoints > getEnemyCharacter(selectedEnemy)->maxHp)
					getEnemyCharacter(selectedEnemy)->healthPoints = getEnemyCharacter(selectedEnemy)->maxHp;
				if (getEnemyCharacter(selectedEnemy)->healthPoints < 0)
					getEnemyCharacter(selectedEnemy)->healthPoints = 0;
			}
				
			uninitCalculation();
		}
			
		
		//MUISTA ALUSTAA KAIKKI!
		CalculationType calculationType = CalculationType::PLUS;
		NumberType numberType = NumberType::POSITIVE;
		int calculationLevel = 1;
		
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
		//std::cout << "calculationLevel: " << calculationLevel << std::endl;
		
		//generating the calculations
		if (!isCalculationVisible && escapeCalculation)
		{
			isCalculationVisible = true;

			calculationType = CalculationType::PLUS;

			int number = 1;
			int number2 = 1;

			correctAnswer = getCorrectAnswer(calculationType, number, number2);
			std::string strCalculation = getCalculationString(calculationType, number, number2);
			textCalculation.setString(strCalculation);
		}

		if (!isCalculationVisible)
		{
			isCalculationVisible = true;
		
			int number = randomNumber(numberType, calculationLevel);
			int number2 = randomNumber(numberType, calculationLevel);
				
			correctAnswer = getCorrectAnswer(calculationType, number, number2);
			std::string strCalculation = getCalculationString(calculationType, number, number2);
			textCalculation.setString(strCalculation);
		
			//std::string strPlayerAnswer = convertToString(playerAnswer);
			//textPlayerAnswer.setString(strPlayerAnswer);
		}
		//if (!isCalculationVisible2)
		//{
		//	isCalculationVisible2 = true;
		
		//	int number = randomNumber(numberType, calculationLevel);
		//	int number2 = randomNumber(numberType, calculationLevel);
		
		//	correctAnswer2 = getCorrectAnswer(calculationType, number, number2);
		//	std::string strCalculation = getCalculationString(calculationType, number, number2);
		//	textCalculation2.setString(strCalculation);
		
		//	//std::string strPlayerAnswer = convertToString(playerAnswer);
		//	//textPlayerAnswer.setString(strPlayerAnswer);
		//}
		//if (!isCalculationVisible3)
		//{
		//	isCalculationVisible3 = true;
		
		//	int number = randomNumber(numberType, calculationLevel);
		//	int number2 = randomNumber(numberType, calculationLevel);
		
		//	correctAnswer3 = getCorrectAnswer(calculationType, number, number2);
		//	std::string strCalculation = getCalculationString(calculationType, number, number2);
		//	textCalculation3.setString(strCalculation);
		
		//	//std::string strPlayerAnswer = convertToString(playerAnswer);
		//	//textPlayerAnswer.setString(strPlayerAnswer);
		//}
		
		//checking the answers
		if (answerIsChecked)
		{
			//Escape
			if (escapeCalculation)
			{
				if (answerIsCorrect)
				{
					//escapeCalculation = false;
					backToMenu();
				}
				else if (!answerIsCorrect)
				{
					uninitCalculation();
				}
			}

			//Normal
			if (answerIsCorrect)
			{
				std::cout << "Oikea vastaus 1 on: " << correctAnswer << "	oikein!" << std::endl;
				points++;
				if (points == 5 || points == 10 || points == 15 || points == 20 || points == 25)
				{
					calculationLevel++;
					std::cout << "taso nousi" << std::endl;
				}
				//playerAnswer = -255;
				isCalculationVisible = false;
			}
			else if (!answerIsCorrect)
			{
				std::cout << "Oikea vastaus 1 on: " << correctAnswer << "	kurahti..." << std::endl;
				mistakes++;
			}
		
		
		
			std::cout << "Pisteet: " << points << ". Virheet: " << mistakes << "." << std::endl;
		
			//charaEnemy->healthPoints -= points;
		
		
			//estä monen laskuun vastaaminen kerralla
			//esim. siirtämällä seuraavaa linea iffeihin
			answerIsChecked = false;
		}
		
		//if (answerIsChecked2)
		//{
		//	if (answerIsCorrect2)
		//	{
		//		std::cout << "Oikea vastaus 2 on: " << correctAnswer2 << "	oikein!" << std::endl;
		//		points++;
		//		if (points == 5 || points == 10 || points == 15 || points == 20 || points == 25)
		//		{
		//			calculationLevel++;
		//			std::cout << "taso nousi" << std::endl;
		//		}
		//		//playerAnswer = -255;
		//		isCalculationVisible2 = false;
		//		answerIsChecked = false;
		//	}
		//	else if (!answerIsCorrect2)
		//	{
		//		std::cout << "Oikea vastaus 2 on: " << correctAnswer2 << "	kurahti..." << std::endl;
		//		mistakes++;
		//		answerIsChecked = false;
		//	}
		//	std::cout << "Pisteet: " << points << ". Virheet: " << mistakes << "." << std::endl;
		//	answerIsChecked2 = false;
		//}
		
		//if (answerIsChecked3)
		//{
		//	if (answerIsCorrect3)
		//	{
		//		std::cout << "Oikea vastaus 3 on: " << correctAnswer3 << "	oikein!" << std::endl;
		//		points++;
		//		if (points == 5 || points == 10 || points == 15 || points == 20 || points == 25)
		//		{
		//			calculationLevel++;
		//			std::cout << "taso nousi" << std::endl;
		//		}
		//		//playerAnswer = -255;
		//		isCalculationVisible3 = false;
		//		answerIsChecked = false;
		//	}
		//	else if (!answerIsCorrect3)
		//	{
		//		std::cout << "Oikea vastaus 3 on: " << correctAnswer3 << "	kurahti..." << std::endl;
		//		mistakes++;
		//		answerIsChecked = false;
		//	}
		//	std::cout << "Pisteet: " << points << ". Virheet: " << mistakes << "." << std::endl;
		//	answerIsChecked3 = false;
		//}
			
	}

}

void MainGameState::draw(const float dt)
{
	//during whole battle
	//DRAW
	//Sprite
	//background
	game->window.draw(spritebgMainGame);

	//character
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->checkIfAlive())
			game->window.draw(characters[i]->spriteCharacter);
	}

	

	//during main phase
	if (!calculationGameIsOn)
	{
		////UPDATE
		//Text
		//info
		////ei toimi vielä
		//for (size_t i = 0; i < characters.size(); i++)
		//{
		//	if (characters[i]->isSelected)
		//		textInfoPlayer.setColor(sf::Color::Blue);
		//	if (characters[i]->isSelected && characters[i]->isPlayerCharacter == false)
		//		textInfoPlayer.setColor(sf::Color::Red);
		//	else
		//		textInfoPlayer.setColor(sf::Color::Black);
		//}

		if (getPlayerCharacter(0) != false)
			if (getPlayerCharacter(0)->isSelected == true)
				textInfoPlayer.setColor(sf::Color::Blue);
			else
				textInfoPlayer.setColor(sf::Color::Black);
		//
		if (getPlayerCharacter(1) != false)
			if (getPlayerCharacter(1)->isSelected == true)
				textInfoPlayer2.setColor(sf::Color::Blue);
			else
				textInfoPlayer2.setColor(sf::Color::Black);
		//
		if (getPlayerCharacter(2) != false)
			if (getPlayerCharacter(2)->isSelected == true)
				textInfoPlayer3.setColor(sf::Color::Blue);
			else
				textInfoPlayer3.setColor(sf::Color::Black);
		//
		if (getEnemyCharacter(0) != false)
			if (getEnemyCharacter(0)->isSelected == true)
				textInfoEnemy.setColor(sf::Color::Red);
			else
				textInfoEnemy.setColor(sf::Color::Black);
		//
		if (getEnemyCharacter(1) != false)
			if (getEnemyCharacter(1)->isSelected == true)
				textInfoEnemy2.setColor(sf::Color::Red);
			else
				textInfoEnemy2.setColor(sf::Color::Black);
		//
		if (getEnemyCharacter(2) != false)
			if (getEnemyCharacter(2)->isSelected == true)
				textInfoEnemy3.setColor(sf::Color::Red);
			else
				textInfoEnemy3.setColor(sf::Color::Black);
		//


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
	//------------------



	//during calculation
	if (calculationGameIsOn)
	{
		textTitleCalc.setString("Calculation");
		textTitleCalc.setOrigin(textTitleCalc.getGlobalBounds().width / 2, textTitleCalc.getGlobalBounds().height / 2);
		textTitleCalc.setPosition(game->window.getSize().x / 2, 10);
		
		textCalculation.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
		textCalculation.setPosition((game->window.getSize().x / 4) * 2, game->window.getSize().y / 3);
		//textCalculation2.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
		//textCalculation2.setPosition((game->window.getSize().x / 4) * 2, game->window.getSize().y / 3);
		//textCalculation3.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
		//textCalculation3.setPosition((game->window.getSize().x / 4) * 3, game->window.getSize().y / 3);
		
		textPlayerAnswer.setOrigin(textPlayerAnswer.getGlobalBounds().width / 2, textPlayerAnswer.getGlobalBounds().height);
		textPlayerAnswer.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 3) * 2);
		
		if (timeLeft <= 5.00f)
			textTimeLeft.setColor(sf::Color::Red);
		else
			textTimeLeft.setColor(sf::Color::Black);
		
		game->window.draw(textTitleCalc);
		game->window.draw(textCalculation);
		//game->window.draw(textCalculation2);
		//game->window.draw(textCalculation3);
		game->window.draw(textPlayerAnswer);
		
		game->window.draw(textTimeLeft);
	}
}


//state management
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

//input
void MainGameState::inputSelectPlayer()
{

}





//COMBATPHASE
void MainGameState::initCalculation() //tarvitsee jonkun tiedon taistelijoista
{
	calculationGameIsOn = true;
	clock.restart();
}
void MainGameState::uninitCalculation()
{
	//reset calculation stuff
	points = 0;
	mistakes = 0;
	calculationLevel = 0;
	isCalculationVisible = false;
	isCalculationVisible2 = false;
	isCalculationVisible3 = false;
	answerIsChecked = false;
	answerIsChecked2 = false;
	answerIsChecked3 = false;
	answerIsCorrect = false;
	answerIsCorrect2 = false;
	answerIsCorrect3 = false;

	selectCharacter = false;
	selectPlayer = false;
	selectEnemy = false;
	selectedEnemy = 0;
	selection = Selection::ATTACK;
	escapeCalculation = false;

	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i]->isSelected = false;
	}

	calculationGameIsOn = false;
	
}


int MainGameState::randomNumber(NumberType ntype, int level)
{
	int rMin;
	int rMax;

	if (ntype == NumberType::BOTH)
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

int MainGameState::getCorrectAnswer(CalculationType type, int number, int number2)
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

bool MainGameState::checkTheAnswer(int playerAnswer, int correctAnswer)
{
	if (playerAnswer == correctAnswer)
	{
		return true;
	}

	return false;
}

std::string MainGameState::getCalculationString(CalculationType type, int number, int number2)
{
	std::string stringNumber = convertToString(number);
	std::string stringNumber2 = convertToString(number2);
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