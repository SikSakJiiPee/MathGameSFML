#pragma once

#include <iostream>

enum class Target{ ALL, ANYONE, PLAYER, ENEMY};

class Item
{
public:
	Item(std::string name);
	~Item();

	std::string getStringItemInfo(Item item);

	std::string itemName;

};