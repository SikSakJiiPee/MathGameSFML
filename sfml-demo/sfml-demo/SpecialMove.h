#pragma once

//Includes
//StateManager
#include "Game.h"

//Enum classes
///An enum class for possible targets.
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