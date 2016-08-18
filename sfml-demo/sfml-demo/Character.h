#pragma once

#include "SpecialMove.h"
#include "Item.h"
#include "Equipment.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Character
{
public:
	Character();
	Character(bool isplayer, std::string name, std::string path, int lvl, int exp, 
		int hp, int maxhp, int sp, int maxsp, 
		int atk, int def, int spd/*, int atkl, int defl*/, sf::Vector2f pos);
	~Character();


	//attributes, mieti onko public vai private
	bool isPlayerCharacter;
	std::string characterName;
	std::string pathTexture;
	int level;
	int experiencePoints;
	int nextLevelExp;
	int healthPoints;
	int maxHp;
	int specialPoints;
	int maxSp;
	int attack;
	int defence;
	int speed;
	//int attackLuck;
	//int defenceLuck;
	sf::Vector2f position;

	bool isAlive = true;
	bool activeCharacter = false;

	sf::Texture textureCharacter;
	sf::Sprite spriteCharacter;

	

	//ei varmuutta
	int upgradePoints;
	int specialUpgradePoints;
	std::vector<SpecialMove> specialMoves;
	std::vector<Item> items;
	std::vector<Equipment> equipments;
	//Status status;
	

	static std::string getStringCharacterInfo(Character character);
	bool checkIfAlive();

private:


};