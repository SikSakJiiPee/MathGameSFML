#pragma once

#include "Game.h"
#include <iostream>

enum class Target{ ALL, ANYONE, PLAYER, ENEMY};
enum class EffectType{ HPUP, SPUP, REVIVE, DAMAGE};

class Item
{
public:
	Item(std::string name, Target targ, EffectType etype,
		int amo, int hp, int sp, int dmg, int rpercent);
	~Item();

	std::string getStringItemInfo(Item item);


	std::string itemName;
	Target target;
	EffectType effectType;
	int amount;
	int healthPoints;
	int specialPoints;
	int damage;
	int revivePercent;
	//erilliset arvot voisi tiivist‰‰ esim. power attribuutiksi

	bool isSelected = false;

};