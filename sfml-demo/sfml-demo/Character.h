#pragma once

//Includes
//own classes
#include "SpecialMove.h"
#include "Item.h"
#include "Equipment.h"
//other
#include <iostream>
#include <vector>
//SFML
#include <SFML/Graphics.hpp>


class Character
{
public:
	///A default constructor.
	Character();
	///A constructor with character name, path and stats.
	Character(bool isplayer, std::string name, std::string path, int lvl, int exp, 
		int hp, int maxhp, int sp, int maxsp, 
		int atk, int def, int spd/*, int atkl, int defl*/, sf::Vector2f pos);
	///A destructor.
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

	//bool isAlive = true;
	bool isSelected = false;
	bool isActive = false;
	bool turnCompleted = false;

	sf::Texture textureCharacter;
	sf::Sprite spriteCharacter;

	

	//ei varmuutta
	int upgradePoints;
	int specialUpgradePoints;
	std::vector<SpecialMove> specialMoves;
	std::vector<Item> items;
	std::vector<Equipment> equipments;
	//Status status;
	
	///Gets a characters and returns info for it as a string.
	static std::string getStringCharacterInfo(Character character);
	///Returns true if characters is alive.
	bool checkIfAlive();
	///Gets a item to use and target characters for using.
	void useItem(Item item, Character* character);
	///Gets a special move to use.
	void useSpecialMove(SpecialMove specialMove, Character* character);

	//specialMoves vector management
	//size_t getSpecialMoveCount();
	//SpecialMove* getSpecialMoveByName(std::string name);
	//items vector management
	//size_t getItemCount();
	//Item* getItemByName(int index);
	//equipments vector management
	//size_t getEquipmentCount();
	//Equipment* getEquipmentByName(int index);

private:


};