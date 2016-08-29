#pragma once

#include "Game.h"

enum class TargetSpecial{ ALL, ANYONE, PLAYER, ENEMY, EVERYPLAYER, EVERYENEMY };


class SpecialMove
{
public:
	///A constructor.
	SpecialMove(std::string name, TargetSpecial targetsp, int cost);
	///A destructor.
	~SpecialMove();

	std::string getStringSpecialMoveInfo(SpecialMove specialMove);

	std::string specialMoveName;
	TargetSpecial targetSpecial;
	int spCost;

	bool isSelected = false;
};