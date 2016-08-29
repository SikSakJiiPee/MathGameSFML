#include "SpecialMove.h"



SpecialMove::SpecialMove(std::string name, TargetSpecial targetsp, int cost)
{
	specialMoveName = name;
	targetSpecial = targetsp;
	spCost = cost;
}

SpecialMove::~SpecialMove()
{}


std::string SpecialMove::getStringSpecialMoveInfo(SpecialMove specialMove)
{
	std::string name = specialMove.specialMoveName;
	std::string cost = convertToString(specialMove.spCost);

	std::string specialMoveInfo = name + " SP cost: " + cost;

	return specialMoveInfo;
}