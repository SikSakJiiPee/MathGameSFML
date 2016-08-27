#pragma once

//#include "Game.h" //jos tarvitsee convertToString()
#include <iostream>

//enum classes
///An enum class for equipment type.
enum class EquipmentType { WEAPON, ARMOR };


class Equipment
{
public:
	///A constructor with name, type and stats.
	Equipment(std::string name, EquipmentType etype, int ctime, int clevel, int mass, 
		int atk, int def, int spd, int hp, int sp);
	///A destructor.
	~Equipment();

	std::string equipmentName;
	EquipmentType equipmentType;
	//CalculationType calculationtype
	//NumberType numberType
	int calculationTime;
	int calculationLevel;
	int equipmentMass;

	//ei varmuutta
	int attack;
	int defence;
	int speed;
	int healthPoints;
	int specialPoints;

	int numberOfCalculations;
};