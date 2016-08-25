#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

#include "Character.h"
#include "Calculation.h"
#include "CalculationState.h"

#include <cstdio> //ei välttämättä tarvita enää (rand)
#include <cstdlib> //ei välttämättä tarvita enää (srand)
#include <time.h>
#include <random>


enum class Selection { NONE, ATTACK, SPECIAL, ITEM, ESCAPE};
enum class Turn {PLAYER, ENEMY};
enum class Phase {MAIN, COMBAT, COMBATEND};

enum class CalculationType { PLUS, MINUS, MULTIPLY, DIVIDE }; //Pitäisikö nimet olla Addition, Subtraction, Multiplication ja Division
enum class NumberType { BOTH, POSITIVE, NEGATIVE };

class MainGameState : public GameState
{
public:
	MainGameState(Game* game);
	~MainGameState();
	
	//state stuff
	//void init();
	//void cleanup();

	//void pause();
	//void resume();

	void handleInput();
	void update(const float dt);
	void draw(const float dt);



	//other stuff
	//static const int calculationLevel = 1;
	
	//Character
	std::vector<Character*> characters;
	Character* activeCharacter;
	Character* targetCharacter;

private:
	//state management
	void backToMenu();

	void combatAttack();
	void combatDefend();

	int selectedPlayer = 0;
	int selectedEnemy = 0;
	

	//character vector management
	size_t getPlayerCharacterCount();
	size_t getEnemyCharacterCount();

	//doxygen
	///Returns Player Character by its index. Returns nullptr if index is invalid.
	Character* getPlayerCharacter(int index);
	///Returns Enemy Character by its index. Returns nullptr if index is invalid.
	Character* getEnemyCharacter(int index);

	///Returns true if any no player character is alive
	bool noPlayerAlive();
	///Returns true if any no enemy character is alive
	bool noEnemyAlive();

	void getFirstAliveCharacter();

	//INPUT
	//void inputSelectCharacter();
	///handles the input during player selection
	void inputSelectPlayer();
	///handles the input during enemy selection
	void inputSelectEnemy();
	//handles the input during special selection
	void inputSelectSpecial();
	//handles the input during item selection
	void inputSelectItem();
	///handles the input after winning a battle 
	void inputBattleWin();
	///handles the input after losing a battle 
	void inputBattleLose();

	//MAINPHASE
	//Time
	sf::Clock clock;
	sf::Time timeElapsed;
	float timeLeft;

	//Font and Text
	sf::Font font;
	sf::Text textTitleMainGame;
	sf::Text textGameAttack;
	sf::Text textGameSpecial;
	sf::Text textGameItem;
	sf::Text textGameEscape;
	sf::Text textInfoPlayer;
	sf::Text textInfoPlayer2;
	sf::Text textInfoPlayer3;
	sf::Text textInfoEnemy;
	sf::Text textInfoEnemy2;
	sf::Text textInfoEnemy3;
	sf::Text textInfoItem;
	sf::Text textInfoItem2;
	sf::Text textTime;
	sf::Text text;

	//Texture and Sprite
	//background
	sf::Texture texturebgMainGame;
	sf::Sprite spritebgMainGame;

	


	//SpecialMoves


	//Item
	Item* item;
	Item* item2;

	//Equipment
	Equipment* eqArmor;
	Equipment* eqWeapon;

	//Selection
	Selection selection;
	//SelectionCharacter selectionCharacter;
	bool selectCharacter = false;
	bool selectPlayer = false;
	bool selectEnemy = false;
	bool selectItem = false;
	bool escapeCalculation = false;
	bool calculationIsOn = false;

	//Turns
	Turn turn;
	int turnsPassed = 0;

	//Enemy Turn
	void enemyChoosesTarget();

	//-----------




	//COMBATPHASE
	void initCalculation();
	void uninitCalculation();

	//INPUT
	void inputCalculation();

	//Methods
	///Return random number
	static int randomNumber(NumberType ntype, int level);
	///Returns correct answer
	static int getCorrectAnswer(CalculationType type, int number, int number2);
	///Returns true if player's answer is the correct answer
	static bool checkTheAnswer(int playerAnswer, int correctAnswer);
	///Returns calculation as a string
	static std::string getCalculationString(CalculationType type, int number, int number2);
	
	//Text
	//sf::Font font;
	sf::Text textTitleCalc;
	sf::Text textTimeLeft;
	sf::Text textAttacker;
	sf::Text textDefender;
	sf::Text textCalculation;
	sf::Text textCalculation2;
	sf::Text textCalculation3;
	sf::Text textPlayerAnswer;
	sf::Text textCorrectAnswer; //tarvitseeko?
	sf::Text textPoints;
	sf::Text textMistakes;
	sf::Text textCurrentCombo;
	sf::Text textBestCombo;
	
	
	//other
	bool calculationGameIsOn = false;
	bool isCalculationVisible = false;
	bool isCalculationVisible2 = false;
	bool isCalculationVisible3 = false;
	bool answerIsChecked = false;
	bool answerIsChecked2 = false;
	bool answerIsChecked3 = false;

	CalculationType calculationType;
	NumberType numberType;
	int calculationLevel = 0;
	float calculationTime;

	int playerAnswer = -255; //Pitää olla pienempi
	bool playerAnswerNegative = false;
	int correctAnswer;
	int correctAnswer2;
	int correctAnswer3;
	bool answerIsCorrect = false;
	bool answerIsCorrect2 = false;
	bool answerIsCorrect3 = false;

	int points = 0;
	int mistakes = 0;
	int currentCombo = 0;
	int bestCombo = 0;
	float averageCombo;

	int damageDealt = 0;
	int damageReflected = 0;
	int damageTotal = 0;

	//-------------



	//WIN BATTLE
	sf::Text textBattleWin;



	//-------------




	//LOSE BATTLE
	sf::Text textBattleLose;
	

};





//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include "GameState.h"
//
//#include "Calculation.h"
//
//class MainGameState : public GameState
//{
//public:
//	//state stuff
//	void init();
//	void cleanup();
//
//	void pause();
//	void resume();
//
//	void handleInput(Game* game);
//	void update(Game* game);
//	void draw(Game* game);
//
//	static MainGameState* instance()
//	{
//		return &mainGameState;
//	}
//
//	//other stuff
//	//static const int calculationLevel = 1;
//
//protected:
//	MainGameState() {}
//
//private:
//	static MainGameState mainGameState;
//
//	//other
//	sf::Font font;
//	sf::Text textTitleMainGame;
//	sf::Text textGame;
//	sf::Text textGame2;
//	sf::Text textGame3;
//	sf::Text textPlayerAnswer;
//	sf::Text textCorrectAnswer;
//	sf::Text textPoints;
//	sf::Text textMistakes;
//	sf::Text textTime;
//	sf::Text text;
//
//	sf::Clock clock;
//	sf::Time timeElapsed;
//	float timeLeft;
//
//
//	//int correctAnswer;
//	//int playerAnswer = -255; //tsekkaa null, koska vastaus voi olla myös nolla, joten se ei voi olla alustus.
//	//bool answerIsCorrect = false;
//	//bool playerAnswerNegative;
//
//	//int points = 0;
//	//int mistakes = 0;
//
//	
//
//	//Calculation calculation(CalculationType ctype, NumberType ntype, int level, float time);
//	//int calculationGame(Calculation calculation);
//	//bool calculationGameIsOn = false;
//};
//
