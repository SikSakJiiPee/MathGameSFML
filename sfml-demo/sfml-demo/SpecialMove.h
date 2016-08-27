#pragma once

#include "Game.h"


class SpecialMove
{
public:
	///A constructor.
	SpecialMove();
	///A destructor.
	~SpecialMove();

	std::string speciaMoveName;
	int spCost;

	bool isSelected = false;
};