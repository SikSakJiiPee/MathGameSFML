#include "Item.h"



Item::Item(std::string name, Target targ, EffectType etype,
	int amo, int hp, int sp, int dmg, int rpercent)
{
	itemName = name;
	target = targ;
	effectType = etype;
	amount = amo;
	healthPoints = hp;
	specialPoints = sp;
	damage = dmg;
	revivePercent = rpercent;
}

Item::~Item()
{}


std::string Item::getStringItemInfo(Item item)
{
	std::string name = item.itemName;
	std::string amount = convertToString(item.amount);

	std::string itemInfo = name + " x" + amount;

	return itemInfo;
}

