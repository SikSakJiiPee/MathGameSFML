#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

#include "Character.h"
#include "Calculation.h"
#include "CalculationState.h"

#include <cstdio> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (rand)
#include <cstdlib> //ei v‰ltt‰m‰tt‰ tarvita en‰‰ (srand)
#include <time.h>
#include <random>

//enum classes
//MAINPHASE
///An enum class for action selection.
enum class Selection { NONE, ATTACK, SPECIAL, ITEM, ESCAPE};
///An enum class for player and enemy turn.
enum class Turn { PLAYER, ENEMY };
//ei ehk‰ tarvita
enum class Phase {MAIN, COMBAT, COMBATEND};

//COMBATPHASE
///An enum class for calculation types
enum class CalculationType { PLUS, MINUS, MULTIPLY, DIVIDE }; //Pit‰isikˆ nimet olla Addition, Subtraction, Multiplication ja Division
///An enum class for number types
enum class NumberType { BOTH, POSITIVE, NEGATIVE };


class MainGameState : public GameState
{
public:
	///A constructor, gets a Game pointer.
	MainGameState(Game* game);
	///A desctructor.
	~MainGameState();
	

	///A method for handling the input of the game state
	void handleInput();
	///A method for updating the game state
	void update(const float dt);
	///A method for drawing the game state
	void draw(const float dt);



	//other stuff
	//static const int calculationLevel = 1;
	
	//Character
	std::vector<Character*> characters;
	Character* activeCharacter;
	Character* targetCharacter;

private:
	//state management
	///Pops the current state and returns to previous state. 
	void backToMenu();

	//tarvitaanko?
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

	///Returns true if any no player character is alive
	bool noPlayerAlive();
	///Returns true if any no enemy character is alive
	bool noEnemyAlive();

	void getFirstAliveCharacter();

	//INPUT
	//void inputSelectCharacter();
	///Handles the input during player selection
	void inputSelectPlayer();
	///Handles the input during enemy selection
	void inputSelectEnemy();
	///Handles the input during special selection
	void inputSelectSpecial();
	///Handles the input during item selection
	void inputSelectItem();
	///Handles the input after winning a battle 
	void inputBattleWin();
	///Handles the input after losing a battle 
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
	int selectedPlayer = 0;
	int selectedEnemy = 0;
	int selectedSpecial = 0;
	int selectedItem = 0;
	bool selectCharacter = false;
	bool selectPlayer = false;
	bool selectEnemy = false;
	bool selectSpecial = false;
	bool selectItem = false;
	bool escapeCalculation = false;
	bool calculationIsOn = false;


	//Turns
	Turn turn;
	///Keeps track how many turns has passed on the current round.
	int turnsPassed = 0;

	//Enemy Turn
	///Chooses a player targer for an enemy character.
	void enemyChoosesTarget();

	//-----------




	//COMBATPHASE
	///Initializes calculation.
	void initCalculation();
	///Uninitializes calculation.
	void uninitCalculation();

	//INPUT
	///Handles the input during calculation.
	void inputCalculation();

	//Methods
	///Returns random number
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

	int playerAnswer = -255; //Pit‰‰ olla pienempi
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






