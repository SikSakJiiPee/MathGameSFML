#pragma once

#include <iostream>
#include <vector>

class Character
{
public:
	Character();
	~Character();


	//attributes, mieti onko public vai private
	std::string characterName;
	int level;
	int exp;
	int nextLevelExp;
	int hp;
	int maxHp;
	int sp;
	int maxSp;
	int attack;
	int defence;
	int speed;
	int attackLuck;
	int defenceLuck;

	//ei varmuutta
	int upgradePoints;
	int specialUpgradePoints;
	//std::vector<SpecialMove> specialMoves;
	//std::vector<Item> items;
	//std::vector<Equipment> equipments;
	//Status status;
	bool isPlayerCharacter;


private:


};