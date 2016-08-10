#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

#include "Character.h"
#include "Calculation.h"
#include "CalculationState.h"

enum class Selection { NONE, ATTACK, SPECIAL, ITEM, ESCAPE, 
	PLAYER1, PLAYER2, PLAYER3, ENEMY1, ENEMY2, ENEMY3 };
//enum class SelectionCharacter { NONE, PLAYER1, PLAYER2, PLAYER3, ENEMY1, ENEMY2, ENEMY3 };


class MainGameState : public GameState
{
public:
	MainGameState(Game* game);
	
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
	std::vector<Character> characters;

	Character* characterPlayer;
	Character* characterPlayer2;
	Character* characterPlayer3;
	Character* characterEnemy;
	Character* characterEnemy2;
	Character* characterEnemy3;

private:
	void startCalculation(/* Character* attacker, Character* defender*/);
	void backToMenu();


	//other
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



	//Item
	Item* item;
	Item* item2;

	//Texture and Sprite
	//background
	sf::Texture texturebgMainGame;
	sf::Sprite spritebgMainGame;

	//character
	sf::Texture texturesprPlayerCharacter;
	sf::Texture texturesprPlayerCharacter2;
	sf::Texture texturesprPlayerCharacter3;
	sf::Texture texturesprEnemyCharacter;
	sf::Texture texturesprEnemyCharacter2;
	sf::Texture texturesprEnemyCharacter3;

	sf::Sprite spritesprPlayerCharacter;
	sf::Sprite spritesprPlayerCharacter2;
	sf::Sprite spritesprPlayerCharacter3;
	sf::Sprite spritesprEnemyCharacter;
	sf::Sprite spritesprEnemyCharacter2;
	sf::Sprite spritesprEnemyCharacter3;

	sf::Clock clock;
	sf::Time timeElapsed;
	float timeLeft;

	Selection selection;
	//SelectionCharacter selectionCharacter;
	bool selectCharacter = false;
	bool selectPlayer = false;
	bool selectEnemy = false;
	bool selectItem = false;
	bool calculationIsOn = false;

	//int correctAnswer;
	//int playerAnswer = -255; //tsekkaa null, koska vastaus voi olla myös nolla, joten se ei voi olla alustus.
	//bool answerIsCorrect = false;
	//bool playerAnswerNegative;

	//int points = 0;
	//int mistakes = 0;

	
	//Calculation calculation(CalculationType ctype, NumberType ntype, int level, float time);
	//int calculationGame(Calculation calculation);
	//bool calculationGameIsOn = false;


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
