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
	///A constructor, gets name, target and sp cost of the special move.
	SpecialMove(std::string name, TargetSpecial targetsp, int cost);
	///A destructor.
	~SpecialMove();

	//Methods
	///Gets a special move and return info for it as a string.
	std::string getStringSpecialMoveInfo(SpecialMove specialMove);

	//Attributes
	std::string specialMoveName;
	TargetSpecial targetSpecial;
	int spCost;

	bool isSelected = false;
};