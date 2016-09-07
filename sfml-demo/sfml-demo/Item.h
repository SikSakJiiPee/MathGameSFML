#pragma once

//Includes
//StateManager
#include "Game.h"


//Enum classes
///An enum class for possible targets.
enum class Target{ ALL, ANYONE, PLAYER, ENEMY};
///An enum class for effect type.
enum class EffectType{ HPUP, SPUP, REVIVE, DAMAGE };


class Item
{
public:
	///A constructor with name, enums and stats.
	Item(std::string name, Target targ, EffectType etype,
		int amo, int hp, int sp, int dmg, int rpercent);
	///A destructor.
	~Item();

	///Gets an item and return info for it as a string.
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