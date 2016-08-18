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


enum class Selection { NONE, ATTACK, SPECIAL, ITEM, ESCAPE, 
	PLAYER1, PLAYER2, PLAYER3, ENEMY1, ENEMY2, ENEMY3 };
enum class Turn {PLAYER, ENEMY};
enum class Phase {MAIN, COMBAT, COMBATEND};
//enum class SelectionCharacter { NONE, PLAYER1, PLAYER2, PLAYER3, ENEMY1, ENEMY2, ENEMY3 };

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

private:
	//state management
	void startCalculation(/* Character* attacker, Character* defender*/);
	void backToMenu();

	void combatAttack();
	void combatDefend();


	//character vector management
	size_t getPlayerCharacterCount();
	size_t getEnemyCharacterCount();

	//doxygen
	///Returns Player Character by its index. Returns nullptr if index is invalid.
	Character* getPlayerCharacter(int index);
	///Returns Enemy Character by its index. Returns nullptr if index is invalid.
	Character* getEnemyCharacter(int index);


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






	//COMBATPHASE
	void initCalculation();
	void uninitCalculation();

	//Methods
	static int randomNumber(NumberType ntype, int level);
	static int getCorrectAnswer(CalculationType type, int number, int number2);
	static int getCorrectAnswerPlus(int number, int number2);
	static int getCorrectAnswerMinus(int number, int number2);
	static bool checkTheAnswer(int playerAnswer, int correctAnswer);
	static std::string getCalculationString(CalculationType type, int number, int number2);
	
	//Text
	//sf::Font font;
	sf::Text textTitleCalc;
	sf::Text textCalculation;
	sf::Text textCalculation2;
	sf::Text textCalculation3;
	sf::Text textPlayerAnswer;
	sf::Text textCorrectAnswer;
	sf::Text textPoints;
	sf::Text textMistakes;
	sf::Text textCurrentCombo;
	sf::Text textMaxCombo;
	sf::Text textTimeLeft;
	
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
	int currentCombo;
	int maxCombo;
	float averageCombo;

	int damageDealt = 0;
	int damageReflected = 0;
	int damageTotal = 0;

	

	//int correctAnswer;
	//int playerAnswer = -255; //tsekkaa null, koska vastaus voi olla myös nolla, joten se ei voi olla alustus.
	//bool answerIsCorrect = false;
	//bool playerAnswerNegative;

	//int points = 0;
	//int mistakes = 0;

	
	//Calculation calculation(CalculationType ctype, NumberType ntype, int level, float time);
	//int calculationGame(Calculation calculation);
	//int calculationGame(Character* player, Character* enemy); 
	


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
