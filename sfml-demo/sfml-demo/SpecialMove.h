#pragma once

#include <iostream>

class SpecialMove
{
public:
	SpecialMove();
	~SpecialMove();

	std::string speciaMoveName;
	int spCost;

	bool isSelected = false;
};