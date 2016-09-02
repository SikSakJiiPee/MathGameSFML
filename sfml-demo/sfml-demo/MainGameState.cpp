#include "MainGameState.h"
#include "MenuState.h"
#include "CalculationState.h"

#include "Game.h"
#include "GameState.h"


MainGameState::MainGameState(Game* game)
{
	this->game = game;

	selection = Selection::ATTACK;

	//Character
	characters.push_back(new Character(true, "Player1", "Texture/Sprite/player1.png", 1, 0, 100, 100, 10, 10, 5, 5, 7, sf::Vector2f((game->window.getSize().x / 8) * 3, (game->window.getSize().y / 3))));
	characters.push_back(new Character(true, "Player2", "Texture/Sprite/player2.png", 1, 0, 100, 100, 10, 10, 7, 5, 3, sf::Vector2f((game->window.getSize().x / 8) * 2, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9)))));
	characters.push_back(new Character(true, "Player3", "Texture/Sprite/player3.png", 1, 0, 100, 100, 10, 10, 10, 5, 5, sf::Vector2f((game->window.getSize().x / 8) * 1, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2))));
	characters.push_back(new Character(false, "Enemy1", "Texture/Sprite/enemy1.png", 1, 0, 100, 100, 10, 10, 7, 5, 6, sf::Vector2f((game->window.getSize().x / 8) * 5, (game->window.getSize().y / 3))));
	characters.push_back(new Character(false, "Enemy2", "Texture/Sprite/enemy2.png", 1, 0, 100, 100, 10, 10, 7, 15, 2, sf::Vector2f((game->window.getSize().x / 8) * 6, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9)))));
	characters.push_back(new Character(false, "Enemy3", "Texture/Sprite/enemy3.png", 1, 0, 100, 100, 10, 10, 7, 30, 4, sf::Vector2f((game->window.getSize().x / 8) * 7, ((game->window.getSize().y / 3) + (game->window.getSize().y / 9) * 2))));
	

	//
	//SpecialMoves
	specialSuperPunch = new SpecialMove("Super Punch", TargetSpecial::ENEMY, 3);
	specialHyperPunch = new SpecialMove("Hyper Punch", TargetSpecial::ENEMY, 7);
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i]->specialMoves.push_back(*specialSuperPunch);
		characters[i]->specialMoves.push_back(*specialHyperPunch);
	}

	//
	//Item
	item = new Item("Potion", Target::PLAYER, EffectType::HPUP, 2, 50, 0, 0, 0);
	item2 = new Item("Potion2", Target::PLAYER, EffectType::HPUP, 2, 75, 0, 0, 0);
	//if (getPlayerCharacter(0) != nullptr)
	//	getPlayerCharacter(0)->items.push_back(*item);
	//pushing items to every character
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i]->items.push_back(*item);
		characters[i]->items.push_back(*item2);
	}

	//
	//Equipment
	//armor
	eqArmor = new Equipment("Basic Armor", EquipmentType::ARMOR, CalculationType::PLUS, 20, 5, 50, 0, 5, 0, 0, 0);
	eqArmor2 = new Equipment("Basic Armor", EquipmentType::ARMOR, CalculationType::MINUS, 20, 5, 50, 0, 5, 0, 0, 0);
	eqArmor3 = new Equipment("Basic Armor", EquipmentType::ARMOR, CalculationType::MULTIPLY, 20, 5, 50, 0, 5, 0, 0, 0);
	
	//weapon
	eqWeapon = new Equipment("Basic Weapon", EquipmentType::WEAPON, CalculationType::PLUS, 15, 5, 50, 7, 0, 0, 0, 0);
	eqWeapon2 = new Equipment("Basic Weapon", EquipmentType::WEAPON, CalculationType::MINUS, 15, 5, 50, 7, 0, 0, 0, 0);
	eqWeapon3 = new Equipment("Basic Weapon", EquipmentType::WEAPON, CalculationType::MULTIPLY, 15, 5, 50, 7, 0, 0, 0, 0);

	//pushing equipments to every character
	//for (size_t i = 0; i < characters.size(); i++)
	//{
	//	characters[i]->equipments.push_back(*eqArmor);
	//	characters[i]->equipments.push_back(*eqWeapon);
	//}

	characters[0]->equipments.push_back(*eqArmor);
	characters[0]->equipments.push_back(*eqWeapon);

	characters[1]->equipments.push_back(*eqArmor2);
	characters[1]->equipments.push_back(*eqWeapon2);

	characters[2]->equipments.push_back(*eqArmor3);
	characters[2]->equipments.push_back(*eqWeapon3);

	characters[3]->equipments.push_back(*eqArmor);
	characters[3]->equipments.push_back(*eqWeapon);

	characters[4]->equipments.push_back(*eqArmor2);
	characters[4]->equipments.push_back(*eqWeapon2);

	characters[5]->equipments.push_back(*eqArmor3);
	characters[5]->equipments.push_back(*eqWeapon3);

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
	//First Turn
	//Search the fastest character and make it active
	activeCharacter = characters[0];
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->speed > activeCharacter->speed)
			activeCharacter = characters[i];
	}

	//activeCharacter = characters[0];
	activeCharacter->isActive = true;
	std::cout << "Active Character: " << activeCharacter->characterName << std::endl;

	if (activeCharacter->isPlayerCharacter)
	{
		turn = Turn::PLAYER;
	}
	else
	{
		turn = Turn::ENEMY;
	}
	//-----


	//
	//Font and Text
	if (!font.loadFromFile("Font/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}
	textTitleMainGame.setFont(font);
	textTitleMainGame.setCharacterSize(30);
	textTitleMainGame.setColor(sf::Color::Black);

	//valintaa varten v‰rin (ja koon?) alustuksen voi siirt‰‰ myˆhemmin updateen.
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

	textActiveCharacter.setFont(font);
	textActiveCharacter.setCharacterSize(24);
	textActiveCharacter.setColor(sf::Color::Black);

	//character
	textInfoPlayer.setFont(font);
	textInfoPlayer.setColor(sf::Color::Black);
	
	textInfoPlayer2.setFont(font);
	textInfoPlayer2.setColor(sf::Color::Black);

	textInfoPlayer3.setFont(font);
	textInfoPlayer3.setColor(sf::Color::Black);

	textInfoEnemy.setFont(font);
	textInfoEnemy.setColor(sf::Color::Black);

	textInfoEnemy2.setFont(font);
	textInfoEnemy2.setColor(sf::Color::Black);

	textInfoEnemy3.setFont(font);
	textInfoEnemy3.setColor(sf::Color::Black);

	//special
	textInfoSpecial.setFont(font);
	textInfoSpecial.setCharacterSize(24);
	textInfoSpecial.setColor(sf::Color::Black);

	textInfoSpecial2.setFont(font);
	textInfoSpecial2.setCharacterSize(24);
	textInfoSpecial2.setColor(sf::Color::Black);

	//item
	textInfoItem.setFont(font);
	textInfoItem.setCharacterSize(24);
	textInfoItem.setColor(sf::Color::Black);	

	textInfoItem2.setFont(font);
	textInfoItem2.setCharacterSize(24);
	textInfoItem2.setColor(sf::Color::Black);

	//tarvitaanko en‰‰?
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

	//textTime.setFont(font);
	//textTime.setCharacterSize(30);
	//textTime.setColor(sf::Color::Black);

	//Audio
	//music
	if (!bufferMusicBattle.loadFromFile("Audio/Music/matikkajytky.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMusicBattle.setBuffer(bufferMusicBattle);

	//sfx
	if (!bufferMenuMove.loadFromFile("Audio/SFX/menu_move.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMenuMove.setBuffer(bufferMenuMove);

	if (!bufferMenuSelect.loadFromFile("Audio/SFX/menu_select.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundMenuSelect.setBuffer(bufferMenuSelect);

	//-----------




	//COMBATPHASE
	//Text
	textTitleCalc.setFont(font);
	textTitleCalc.setCharacterSize(24);
	textTitleCalc.setColor(sf::Color::Black);

	textTimeLeft.setFont(font);
	textTimeLeft.setCharacterSize(24);

	textAttacker.setFont(font);
	textAttacker.setCharacterSize(24);
	textAttacker.setColor(sf::Color::Black);

	textDefender.setFont(font);
	textDefender.setCharacterSize(24);
	textDefender.setColor(sf::Color::Black);

	textCalculation.setFont(font);
	textCalculation.setCharacterSize(24);
	textCalculation.setColor(sf::Color::Black);
	
	textCalculation2.setFont(font);
	textCalculation2.setCharacterSize(24);
	textCalculation2.setColor(sf::Color::Black);
	
	textCalculation3.setFont(font);
	textCalculation3.setCharacterSize(24);
	textCalculation3.setColor(sf::Color::Black);
	
	textPlayerAnswer.setFont(font);
	textPlayerAnswer.setCharacterSize(24);
	textPlayerAnswer.setColor(sf::Color::Black);
	
	textCorrectAnswer.setFont(font); //tarvitseeko?
	textCorrectAnswer.setCharacterSize(24);
	textCorrectAnswer.setColor(sf::Color::Black);
	
	textPoints.setFont(font);
	textPoints.setCharacterSize(24);
	textPoints.setColor(sf::Color::Black);
	
	textMistakes.setFont(font);
	textMistakes.setCharacterSize(24);
	textMistakes.setColor(sf::Color::Black);
	
	textCurrentCombo.setFont(font);
	textCurrentCombo.setCharacterSize(24);
	textCurrentCombo.setColor(sf::Color::Black);
	
	textBestCombo.setFont(font);
	textBestCombo.setCharacterSize(24);
	textBestCombo.setColor(sf::Color::Black);
	
	//Audio
	//sfx
	if (!bufferCalculationCorrect.loadFromFile("Audio/SFX/calculation_correct.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundCalculationCorrect.setBuffer(bufferCalculationCorrect);

	if (!bufferCalculationWrong.loadFromFile("Audio/SFX/calculation_wrong.wav"))
		std::cout << "Loading an audio failed!" << std::endl;
	soundCalculationWrong.setBuffer(bufferCalculationWrong);

	//-------------



	//WIN BATTLE
	textBattleWin.setFont(font);
	textBattleWin.setCharacterSize(30);
	textBattleWin.setColor(sf::Color::White);
	textBattleWin.setString("YOU WON");


	//-------------




	//BATTLE LOSE
	textBattleLose.setFont(font);
	textBattleLose.setCharacterSize(30);
	textBattleLose.setColor(sf::Color::White);
	textBattleLose.setString("GAME OVER");




	//-------------

	std::cout << "MainGameState init" << std::endl;
}

MainGameState::~MainGameState()
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		delete characters[i];
	}

	delete specialSuperPunch;
	delete specialHyperPunch;

	//selvit‰ tarvitseeko jonkun paremman systeemin itemien poistoon
	delete item;

	delete eqArmor;
	delete eqWeapon;

	//selvit‰ poistuuko kaikki itemit, equipit ja specialit poistettaessa characterit
}
//-----




//INPUT
void MainGameState::handleInput()
{
	//During player turn
	if (turn == Turn::PLAYER)
	{
		//during select player
		if (selectPlayer)
		{
			inputSelectPlayer();
		}
		//--------------

		//during select enemy
		if (selectEnemy)
		{
			inputSelectEnemy();
		}
		//--------------

		//during select special
		if (selectSpecial)
		{
			inputSelectSpecial();
		}

		//during select item
		if (selectItem)
		{
			inputSelectItem();
		}


		//during calculation
		if (calculationGameIsOn)
		{
			inputCalculation();
		}
		//--------------



		//during battle lose
		if (noPlayerAlive())
		{
			inputBattleLose();
		}
		//--------------

		//during battle win
		if (noEnemyAlive())
		{
			inputBattleWin();
		}
		//--------------

		//muuta loputkin inputit omiksi metodeikseen
		sf::Event evnt;

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
					//selecting the action
					if (!selectCharacter && !selectPlayer && !selectEnemy)
					{
						//quick button to kill all players
						if (evnt.key.code == sf::Keyboard::F)
						{
							for (size_t i = 0; i < characters.size(); i++)
							{
								if (characters[i]->isPlayerCharacter == true)
									characters[i]->healthPoints = 0;
							}
						}
						//quick button to kill all enemies
						if (evnt.key.code == sf::Keyboard::G)
						{
							for (size_t i = 0; i < characters.size(); i++)
							{
								if (characters[i]->isPlayerCharacter == false)
									characters[i]->healthPoints = 0;
							}
						}

						//Go to CalculationState
						if (evnt.key.code == sf::Keyboard::Return)
						{
							soundMenuSelect.play();

							if (selection == Selection::ATTACK)
							{
								selectEnemy = true;
								if (getEnemyCharacter(0) != false)
									getEnemyCharacter(0)->isSelected = true;
							}
							if (selection == Selection::SPECIAL)
							{
								selectSpecial = true;
								activeCharacter->specialMoves[0].isSelected = true;
								std::cout << "Special selected" << std::endl;
							}
							if (selection == Selection::ITEM)
							{
								selectItem = true;
								activeCharacter->items[0].isSelected = true;
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
							soundMenuMove.play();

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
							soundMenuMove.play();

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
							soundMenuMove.play();

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
							soundMenuMove.play();

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
		}
	}
	//-----

	//During enemy turn
	if (turn == Turn::ENEMY)
	{
		//during calculation
		if (calculationGameIsOn)
		{
			inputCalculation();
		}
		//--------------



		//during battle lose
		if (noPlayerAlive())
		{
			inputBattleLose();
		}
		//--------------

		//during battle win
		if (noEnemyAlive())
		{
			inputBattleWin();
		}
		//--------------
		
		sf::Event evnt;

		while (this->game->window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed)
			{
				if (evnt.key.code == sf::Keyboard::Return)
				{
					enemyChoosesTarget();
					initCalculation();
				}
			}
		}
	}

	return;
}
//-----





//UPDATE
void MainGameState::update(const float dt)
{
	//if (isMusicBattlePlaying == false)
	//{
	//	soundMusicBattle.play();
	//	soundMusicBattle.setLoop(true);
	//	isMusicBattlePlaying = true;
	//}

	//if (turn == Turn::PLAYER)
	//{
	//
	//}


	//during main phase
	if (!calculationGameIsOn)
	{
	


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
		textTimeLeft.setString("Time: " + strTimeLeft);
		
		if (timeLeft <= 0)
		{

			if (targetCharacter != false || activeCharacter != false)
			{
				if (turn == Turn::PLAYER)
					damageDealt = (points * activeCharacter->attack);
				if (turn == Turn::ENEMY)
					damageDealt = ((randomNumber(NumberType::POSITIVE, 10)) * activeCharacter->attack);
				
				if (turn == Turn::PLAYER)
				{
					damageReflected = (((randomNumber(NumberType::POSITIVE, 10)) * targetCharacter->defence) / 2);
				}
				if (turn == Turn::ENEMY)
				{
					damageReflected = ((points * targetCharacter->defence) / 2);
				}

				damageTotal = damageDealt - damageReflected;
				if (damageDealt < damageReflected)
					damageTotal = 0;

				std::cout << targetCharacter->defence << std::endl;
				std::cout << "damageDealt: " << damageDealt << "  damageReflected: " << damageReflected << std::endl;
				std::cout << "damageTotal: " << damageTotal << std::endl;

				targetCharacter->healthPoints -= damageTotal;

				if (targetCharacter->healthPoints > targetCharacter->maxHp)
					targetCharacter->healthPoints = targetCharacter->maxHp;
				if (targetCharacter->healthPoints < 0)
					targetCharacter->healthPoints = 0;
			}
				
			uninitCalculation();
		}
			
		//MUISTA ALUSTAA KAIKKI!
		//korjaa calculationType menem‰‰n puolustaessa puolustajan mukaan, ei aktiivisen hahmon
		//aseta calculationType puolustaessa armorin mukaan
		CalculationType calculationType = activeCharacter->equipments[0].calculationType;
		NumberType numberType = NumberType::POSITIVE;
		int calculationLevel = 5;
		
		std::string strPlayerAnswer = convertToString(playerAnswer);
		
		//handling text for the player answer
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
		//
		//	int number = randomNumber(numberType, calculationLevel);
		//	int number2 = randomNumber(numberType, calculationLevel);
		//
		//	correctAnswer2 = getCorrectAnswer(calculationType, number, number2);
		//	std::string strCalculation = getCalculationString(calculationType, number, number2);
		//	textCalculation2.setString(strCalculation);
		//
		//	//std::string strPlayerAnswer = convertToString(playerAnswer);
		//	//textPlayerAnswer.setString(strPlayerAnswer);
		//}
		//if (!isCalculationVisible3)
		//{
		//	isCalculationVisible3 = true;
		//
		//	int number = randomNumber(numberType, calculationLevel);
		//	int number2 = randomNumber(numberType, calculationLevel);
		//
		//	correctAnswer3 = getCorrectAnswer(calculationType, number, number2);
		//	std::string strCalculation = getCalculationString(calculationType, number, number2);
		//	textCalculation3.setString(strCalculation);
		//
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
					soundCalculationCorrect.play();

					//escapeCalculation = false;
					backToMenu();
				}
				else if (!answerIsCorrect)
				{
					soundCalculationWrong.play();

					uninitCalculation();
				}
			}

			//Normal (Attack and Defend)
			if (answerIsCorrect)
			{
				soundCalculationCorrect.play();

				std::cout << "Oikea vastaus 1 on: " << correctAnswer << "	oikein!" << std::endl;
				points++;
				currentCombo++;
				if (bestCombo < currentCombo)
					bestCombo = currentCombo;
				
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
				soundCalculationWrong.play();

				std::cout << "Oikea vastaus 1 on: " << correctAnswer << "	kurahti..." << std::endl;
				mistakes++;
				currentCombo = 0;
			}
		
			std::cout << "Pisteet: " << points << ". Virheet: " << mistakes << "." << std::endl;
		
			//est‰ moneen laskuun vastaaminen kerralla
			//esim. siirt‰m‰ll‰ seuraavaa linea iffeihin
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
		//
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
	//--------------



	//during battle lose
	if (noPlayerAlive())
	{
		//std::cout << "Game Over!" << std::endl;
	}
	//--------------



	//during battle win
	if (noEnemyAlive())
	{
		//std::cout << "You Won!" << std::endl;
	}
	//--------------

}
//-----





//DRAW
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
		////ei toimi viel‰
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
			if (getPlayerCharacter(0)->isActive == true)
				textInfoPlayer.setCharacterSize(21);
			else
				textInfoPlayer.setCharacterSize(20);
			if (getPlayerCharacter(0)->isSelected == true)
				textInfoPlayer.setColor(sf::Color::Blue);
			else
				textInfoPlayer.setColor(sf::Color::Black);
		//
		if (getPlayerCharacter(1) != false)
			if (getPlayerCharacter(1)->isActive == true)
				textInfoPlayer2.setCharacterSize(21);
			else
				textInfoPlayer2.setCharacterSize(20);
			if (getPlayerCharacter(1)->isSelected == true)
				textInfoPlayer2.setColor(sf::Color::Blue);
			else
				textInfoPlayer2.setColor(sf::Color::Black);
		//
		if (getPlayerCharacter(2) != false)
			if (getPlayerCharacter(2)->isActive == true)
				textInfoPlayer3.setCharacterSize(21);
			else
				textInfoPlayer3.setCharacterSize(20);
			if (getPlayerCharacter(2)->isSelected == true)
				textInfoPlayer3.setColor(sf::Color::Blue);
			else
				textInfoPlayer3.setColor(sf::Color::Black);
		//
		if (getEnemyCharacter(0) != false)
			if (getEnemyCharacter(0)->isActive == true)
				textInfoEnemy.setCharacterSize(21);
			else
				textInfoEnemy.setCharacterSize(20);
			if (getEnemyCharacter(0)->isSelected == true)
				textInfoEnemy.setColor(sf::Color::Red);
			else
				textInfoEnemy.setColor(sf::Color::Black);
		//
		if (getEnemyCharacter(1) != false)
			if (getEnemyCharacter(1)->isActive == true)
				textInfoEnemy2.setCharacterSize(21);
			else
				textInfoEnemy2.setCharacterSize(20);
			if (getEnemyCharacter(1)->isSelected == true)
				textInfoEnemy2.setColor(sf::Color::Red);
			else
				textInfoEnemy2.setColor(sf::Color::Black);
		//
		if (getEnemyCharacter(2) != false)
			if (getEnemyCharacter(2)->isActive == true)
				textInfoEnemy3.setCharacterSize(21);
			else
				textInfoEnemy3.setCharacterSize(20);
			if (getEnemyCharacter(2)->isSelected == true)
				textInfoEnemy3.setColor(sf::Color::Red);
			else
				textInfoEnemy3.setColor(sf::Color::Black);
		//


		//selvit‰ tapa toteuttaa infot tekstivektoreilla tai character attribuutilla
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

		

		//selection
		textActiveCharacter.setString(activeCharacter->characterName);

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

		textActiveCharacter.setPosition(0, (game->window.getSize().y / 18) * 15);
		textGameAttack.setPosition(0, (game->window.getSize().y / 18) * 16);
		textGameItem.setPosition(0, (game->window.getSize().y / 18) * 17);
		textGameSpecial.setPosition(game->window.getSize().x / 4, (game->window.getSize().y / 18) * 16);
		textGameEscape.setPosition(game->window.getSize().x / 4, (game->window.getSize().y / 18) * 17);


		//special
		textInfoSpecial.setString(activeCharacter->specialMoves[0].getStringSpecialMoveInfo(activeCharacter->specialMoves[0]));
		textInfoSpecial.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 16);
		textInfoSpecial2.setString(activeCharacter->specialMoves[1].getStringSpecialMoveInfo(activeCharacter->specialMoves[1]));
		textInfoSpecial2.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 17);

		if (activeCharacter->specialMoves[0].isSelected == true)
			textInfoSpecial.setColor(sf::Color::Blue);
		else
			textInfoSpecial.setColor(sf::Color::Black);
		if (activeCharacter->specialMoves[1].isSelected == true)
			textInfoSpecial.setColor(sf::Color::Blue);
		else
			textInfoSpecial.setColor(sf::Color::Black);

		//item
		textInfoItem.setString(activeCharacter->items[0].getStringItemInfo(activeCharacter->items[0]));
		textInfoItem.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 16);
		textInfoItem2.setString(activeCharacter->items[1].getStringItemInfo(activeCharacter->items[1]));
		textInfoItem2.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 17);

		if (activeCharacter->items[0].isSelected == true)
			textInfoItem.setColor(sf::Color::Blue);
		else
			textInfoItem.setColor(sf::Color::Black);
		if (activeCharacter->items[1].isSelected == true)
			textInfoItem2.setColor(sf::Color::Blue);
		else
			textInfoItem2.setColor(sf::Color::Black);


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
		
		//selection
		game->window.draw(textActiveCharacter);
		game->window.draw(textGameAttack);
		game->window.draw(textGameItem);
		game->window.draw(textGameSpecial);
		game->window.draw(textGameEscape);

		//special
		if (selectSpecial)
		{
			game->window.draw(textInfoSpecial);
			game->window.draw(textInfoSpecial2);
		}

		//item
		if (selectItem)
		{
			game->window.draw(textInfoItem);
			game->window.draw(textInfoItem2);
		}
	}
	//------------------



	//during calculation
	if (calculationGameIsOn)
	{
		if (turn == Turn::PLAYER)
			textTitleCalc.setString("Attack");
		if (turn == Turn::ENEMY)
			textTitleCalc.setString("Defend");
		if (escapeCalculation)
			textTitleCalc.setString("Escape");
		
		//textTitleCalc.setOrigin(textTitleCalc.getGlobalBounds().width / 2, textTitleCalc.getGlobalBounds().height / 2);
		//textTitleCalc.setPosition(game->window.getSize().x / 2, 10);
		
		if (timeLeft <= 5.00f)
			textTimeLeft.setColor(sf::Color::Red);
		else
			textTimeLeft.setColor(sf::Color::Black);
		textTimeLeft.setPosition(game->window.getSize().x / 2, 0);

		textAttacker.setString(activeCharacter->characterName);
		if (!escapeCalculation)
			textDefender.setString(targetCharacter->characterName);
		if (turn == Turn::PLAYER)
		{
			textAttacker.setPosition(0, (game->window.getSize().y / 18));
			textDefender.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 18));
		}
		if (turn == Turn::ENEMY)
		{
			textDefender.setPosition(0, (game->window.getSize().y / 18));
			textAttacker.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 18));
		}


		textCalculation.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
		textCalculation.setPosition((game->window.getSize().x / 4) * 2, game->window.getSize().y / 3);
		//l‰hemp‰n‰ oikeaa
		//textCalculation.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 3);
		
		//textCalculation2.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
		//textCalculation2.setPosition((game->window.getSize().x / 4) * 2, game->window.getSize().y / 3);
		//textCalculation3.setOrigin(textCalculation.getGlobalBounds().width / 2, textCalculation.getGlobalBounds().height);
		//textCalculation3.setPosition((game->window.getSize().x / 4) * 3, game->window.getSize().y / 3);
		
		textPlayerAnswer.setOrigin(textPlayerAnswer.getGlobalBounds().width / 2, textPlayerAnswer.getGlobalBounds().height);
		textPlayerAnswer.setPosition(game->window.getSize().x / 2, (game->window.getSize().y / 3) * 2);
		//l‰hemp‰n‰ oikeaa
		//textPlayerAnswer.setPosition((game->window.getSize().x / 4) * 2, (game->window.getSize().y / 18) * 4);

		textPoints.setString("Correct: " + convertToString(points));
		textMistakes.setString("Miss: " + convertToString(mistakes));
		textCurrentCombo.setString("Combo: " + convertToString(currentCombo));
		textBestCombo.setString("Best Combo: " + convertToString(bestCombo));
		textPoints.setPosition(0, (game->window.getSize().y / 18) * 16);
		textMistakes.setPosition(0, (game->window.getSize().y / 18) * 17);
		textCurrentCombo.setPosition(game->window.getSize().x / 4, (game->window.getSize().y / 18) * 16);
		textBestCombo.setPosition(game->window.getSize().x / 4, (game->window.getSize().y / 18) * 17);



		//DRAW
		game->window.draw(textTitleCalc);
		game->window.draw(textCalculation);
		//game->window.draw(textCalculation2);
		//game->window.draw(textCalculation3);
		game->window.draw(textPlayerAnswer);
		game->window.draw(textAttacker);
		game->window.draw(textDefender);
		game->window.draw(textPoints);
		game->window.draw(textMistakes);
		game->window.draw(textCurrentCombo);
		game->window.draw(textBestCombo);
		
		game->window.draw(textTimeLeft);
	}
	//------------------



	//during battle lose
	if (noPlayerAlive())
	{
		soundMusicBattle.stop();

		game->window.clear(sf::Color::Black);
		game->window.draw(textBattleLose);
	}
	//------------------



	//during battle win
	if (noEnemyAlive())
	{
		soundMusicBattle.stop();


		game->window.clear(sf::Color::Black);
		game->window.draw(textBattleWin);
	}
}
//-----




//state management
void MainGameState::backToMenu()
{
	soundMusicBattle.stop();

	this->game->popState();

	return;
}
//-----


//characters vector management
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
//-----



//checks for alive characters
bool MainGameState::noPlayerAlive()
{
	size_t alive(0);

	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->isPlayerCharacter && characters[i]->checkIfAlive())
			alive++;
	}

	if (alive == 0)
		return true;

	return false;
}
bool MainGameState::noEnemyAlive()
{
	size_t alive(0);

	for (size_t i = 0; i < characters.size(); i++)
	{
		if (!characters[i]->isPlayerCharacter && characters[i]->checkIfAlive())
			alive++;
	}

	if (alive == 0)
		return true;

	return false;
}


////ei ajatus kulje en‰‰, jatka myˆhemmin
void MainGameState::getFirstAliveCharacter()
{
	size_t count(0);
	
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->checkIfAlive())
		{
			activeCharacter = characters[count];
			return;
		}


		count++;
	}
	return;
}
//-----




//INPUT
void MainGameState::inputSelectPlayer()
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
			for (size_t i = 0; i < characters.size(); i++)
			{
				characters[i]->isSelected = false;
			}

			if (evnt.key.code == sf::Keyboard::Down)
			{
				soundMenuMove.play();

				selectedPlayer++;

				if (selectedPlayer >= getPlayerCharacterCount() - 1)
					selectedPlayer = getPlayerCharacterCount() - 1;
			}
			if (evnt.key.code == sf::Keyboard::Up)
			{
				soundMenuMove.play();

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
				for (size_t i = 0; i < characters.size(); i++)
				{
					characters[i]->isSelected = false;
				}
				selectPlayer = false;
				selectedPlayer = 0;
				//selection = Selection::ATTACK;
			}
			if (evnt.key.code == sf::Keyboard::Return)
			{
				//soundMenuSelect.play();

				targetCharacter = getPlayerCharacter(selectedPlayer);
				if (selection == Selection::SPECIAL && targetCharacter->checkIfAlive())
				{
					soundMenuSelect.play();

					std::cout << "Player target for a special selected" << std::endl;
				}
				if (selection == Selection::ITEM && targetCharacter->checkIfAlive())
				{
					soundMenuSelect.play();

					std::cout << "Player target for an item selected" << std::endl;
					activeCharacter->useItem(activeCharacter->items[selectedItem], targetCharacter);
					activeCharacter->items[selectedItem].amount--;
					initCalculation();
					uninitCalculation();
				}
			}
		}
	}
}

void MainGameState::inputSelectEnemy()
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
			for (size_t i = 0; i < characters.size(); i++)
			{
				characters[i]->isSelected = false;
			}

			if (evnt.key.code == sf::Keyboard::Down)
			{
				soundMenuMove.play();

				selectedEnemy++;

				if (selectedEnemy >= getEnemyCharacterCount() - 1)
					selectedEnemy = getEnemyCharacterCount() - 1;
			}
			if (evnt.key.code == sf::Keyboard::Up)
			{
				soundMenuMove.play();

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
				for (size_t i = 0; i < characters.size(); i++)
				{
					characters[i]->isSelected = false;
				}
				selectEnemy = false;
				selectedEnemy = 0;
				//selection = Selection::ATTACK;
			}
			if (evnt.key.code == sf::Keyboard::Return /*&& getEnemyCharacter(selectedEnemy)->checkIfAlive()*/)
			{
				targetCharacter = getEnemyCharacter(selectedEnemy);

				if (selection == Selection::ATTACK && targetCharacter->checkIfAlive())
				{
					soundMenuSelect.play();

					initCalculation();
				}
				if (selection == Selection::SPECIAL && targetCharacter->checkIfAlive())
				{
					soundMenuSelect.play();

					activeCharacter->useSpecialMove(activeCharacter->specialMoves[selectedSpecial], targetCharacter);
					activeCharacter->specialPoints -= activeCharacter->specialMoves[selectedSpecial].spCost;
					initCalculation();
					uninitCalculation();

					std::cout << "Player target for a special selected" << std::endl;
				}
				if (selection == Selection::ITEM && targetCharacter->checkIfAlive())
				{
					soundMenuSelect.play();

					std::cout << "Player target for an item selected" << std::endl;
					activeCharacter->useItem(activeCharacter->items[selectedItem], targetCharacter);
					activeCharacter->items[selectedItem].amount--;
					initCalculation();
					uninitCalculation();
				}
			}
		}
	}
}

void MainGameState::inputSelectSpecial()
{
	//valintaa bugaa jotenkin ja v‰‰r‰n tekstin valittuna
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
			for (size_t i = 0; i < activeCharacter->specialMoves.size(); i++)
			{
				activeCharacter->specialMoves[i].isSelected = false;
			}

			if (evnt.key.code == sf::Keyboard::Down)
			{
				soundMenuMove.play();

				selectedSpecial++;

				if (selectedSpecial >= activeCharacter->specialMoves.size() - 1)
					selectedSpecial = activeCharacter->specialMoves.size() - 1;
			}
			if (evnt.key.code == sf::Keyboard::Up)
			{
				soundMenuMove.play();

				selectedSpecial--;

				if (selectedSpecial <= 0)
					selectedSpecial = 0;
			}

			activeCharacter->specialMoves[selectedSpecial].isSelected = true;

			if (evnt.key.code == sf::Keyboard::Escape)
			{
				for (size_t i = 0; i < activeCharacter->specialMoves.size(); i++)
				{
					activeCharacter->specialMoves[i].isSelected = false;
				}
				selectSpecial = false;
				selectedSpecial = 0;
				selection = Selection::ATTACK;
			}
			if (evnt.key.code == sf::Keyboard::Return)
			{
				soundMenuSelect.play();

				if (activeCharacter->specialPoints >= activeCharacter->specialMoves[selectedSpecial].spCost)
				{
					if (activeCharacter->specialMoves[selectedSpecial].targetSpecial == TargetSpecial::PLAYER)
					{
						if (getPlayerCharacter(0) != false)
							getPlayerCharacter(0)->isSelected = true;

						selectPlayer = true;
					}
					if (activeCharacter->specialMoves[selectedSpecial].targetSpecial == TargetSpecial::ENEMY)
					{
						if (getEnemyCharacter(0) != false)
							getEnemyCharacter(0)->isSelected = true;

						selectEnemy = true;
					}
				}
				else
					std::cout << "No SP left" << std::endl;
			}
		}
	}
}

void MainGameState::inputSelectItem()
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
			for (size_t i = 0; i < activeCharacter->items.size(); i++)
			{
				activeCharacter->items[i].isSelected = false;
			}

			if (evnt.key.code == sf::Keyboard::Down)
			{
				soundMenuMove.play();

				selectedItem++;

				if (selectedItem >= activeCharacter->items.size() - 1)
					selectedItem = activeCharacter->items.size() - 1;
			}
			if (evnt.key.code == sf::Keyboard::Up)
			{
				soundMenuMove.play();

				selectedItem--;

				if (selectedItem <= 0)
					selectedItem = 0;
			}

			activeCharacter->items[selectedItem].isSelected = true;
		
			if (evnt.key.code == sf::Keyboard::Escape)
			{
				for (size_t i = 0; i < activeCharacter->items.size(); i++)
				{
					activeCharacter->items[i].isSelected = false;
				}
				selectItem = false;
				selectedItem = 0;
				selection = Selection::ATTACK;
			}
			if (evnt.key.code == sf::Keyboard::Return)
			{
				soundMenuSelect.play();

				if (activeCharacter->items[selectedItem].amount > 0)
				{
					if (activeCharacter->items[selectedItem].target == Target::PLAYER)
					{
						if (getPlayerCharacter(0) != false)
							getPlayerCharacter(0)->isSelected = true;

						selectPlayer = true;
					}
				}
				else
					std::cout << "No items left" << std::endl;
			}
		}
	}
}


void MainGameState::inputBattleWin()
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
			if (evnt.key.code == sf::Keyboard::Return)
			{
				backToMenu();
			}
		}
	}
}
void MainGameState::inputBattleLose()
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
			if (evnt.key.code == sf::Keyboard::Return)
			{
				backToMenu();
			}
		}
	}
}
//-----




//Turns
void MainGameState::enemyChoosesTarget()
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->isPlayerCharacter && characters[i]->checkIfAlive())
		{
			targetCharacter = characters[i];
		}
	}
}
//------









//COMBATPHASE
//INIT AND UNINIT
void MainGameState::initCalculation() //tarvitsee jonkun tiedon taistelijoista
{
	selectCharacter = false;
	selectPlayer = false;
	selectEnemy = false;
	selectSpecial = false;
	selectItem = false;
	calculationGameIsOn = true;
	clock.restart();
}
void MainGameState::uninitCalculation()
{
	//reset calculation stuff
	playerAnswer = -255;
	playerAnswerNegative = false;
	points = 0;
	mistakes = 0;
	currentCombo = 0;
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

	selectedEnemy = 0;
	selectedPlayer = 0;
	std::cout << "Items left: " << activeCharacter->items[selectedItem].amount << std::endl;
	selectedItem = 0;
	selection = Selection::ATTACK;
	escapeCalculation = false;


	//Set every character unselected
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i]->isSelected = false;
	}



	//Changes to characters after completing the turn
	//Check which characters have completed turn
	activeCharacter->turnCompleted = true;
	std::cout << "Turn Completed:" << std::endl;
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->turnCompleted == true)
			std::cout << characters[i]->characterName << std::endl;
	}
	
	//Make every character inactive
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i]->isActive = false;
	}

	//bugaa edelleen, hitain hahmo saattaa j‰‰d‰ joka vuoroksi aktiiviseksi
	//viimeisten hahmojen vuorot saattavat skippaantua (yhden hahmon kuoltua?)
	//vuoro vaikuttaa j‰‰v‰n viimeiselle hahmolle jos joku kuolee sen vuorolla.
	//Update the count of dead characters
	int count(0);
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->checkIfAlive() == false)
			count++;
		deadCharacters = count;
	}
	count = 0;
	std::cout << "Dead characters: " << deadCharacters << std::endl;

	//Update number of passed turns of this round
	turnsPassed++;
	if (turnsPassed == getPlayerCharacterCount() + getEnemyCharacterCount() - deadCharacters)
	{
		turnsPassed = 0;
		for (size_t i = 0; i < characters.size(); i++)
		{
			characters[i]->turnCompleted = false;
		}

		//kuolleiden hahmojen p‰ivitys t‰ss‰ antaa viimeiselle hahmolle
		//jonkun kuollessa uuden vuoron,
		//mutta nyt viimeisen hahmon vuoro ei j‰‰ aktiiviseksi
		//Update the count of dead characters
		//int count(0);
		//for (size_t i = 0; i < characters.size(); i++)
		//{
		//	if (characters[i]->checkIfAlive() == false)
		//		count++;
		//	deadCharacters = count;
		//}
		//count = 0;
		//std::cout << "Dead characters: " << deadCharacters << std::endl;
	}
	


	
	//Sets the fastest character which have not made its turn active
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->speed < activeCharacter->speed)
		{
			activeCharacter = characters[i];
		}
	}
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->speed > activeCharacter->speed 
			&& characters[i]->turnCompleted == false
			&& characters[i]->checkIfAlive())
		{
			activeCharacter = characters[i];
		}
	}

	activeCharacter->isActive = true;

	if (activeCharacter->isPlayerCharacter)
	{
		turn = Turn::PLAYER;
	}
	else
	{
		turn = Turn::ENEMY;
	}


	//activeCharacter->isActive = true;
	for (size_t i = 0; i < characters.size(); i++)
	{
		if (characters[i]->isActive == true)
			std::cout << "Active Character: " << characters[i]->characterName << std::endl;
	}

	

	calculationGameIsOn = false;
	
}
//-----





//INPUT
void MainGameState::inputCalculation()
{
	sf::Event evnt;

	while (this->game->window.pollEvent(evnt))
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
				std::cout << "Your answer: " << playerAnswer << std::endl;
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
//-----





//Calculation stuff
int MainGameState::randomNumber(NumberType ntype, int level)
{
	int rMin;
	int rMax;

	if (ntype == NumberType::BOTH)
	{
		rMin = -level;
		rMax = level;
	}
	else if (ntype == NumberType::POSITIVE)
	{
		rMin = 0;
		rMax = level;
	}
	else if (ntype == NumberType::NEGATIVE)
	{
		rMin = -level;
		rMax = 0;
	}

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(rMin, rMax);
	auto rNumber = uni(rng);

	return rNumber;
}
//
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
//
bool MainGameState::checkTheAnswer(int playerAnswer, int correctAnswer)
{
	if (playerAnswer == correctAnswer)
	{
		return true;
	}

	return false;
}
//
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

