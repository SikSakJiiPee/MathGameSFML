#include "Item.h"



Item::Item(std::string name)
{
	itemName = name;
}

Item::~Item()
{}

std::string Item::getStringItemInfo(Item item)
{
	std::string name = item.itemName;

	std::string itemInfo = name;

	return itemInfo;
}