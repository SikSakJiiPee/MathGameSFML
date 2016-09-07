#pragma once

//Includes
//StateManager
#include "Game.h"

//Enum classes
///An enum class for equipment type.
enum class EquipmentType { WEAPON, ARMOR };
///An enum class for calculation types
enum class CalculationType { PLUS, MINUS, MULTIPLY, DIVIDE }; //Pitäisikö nimet olla Addition, Subtraction, Multiplication ja Division

class Equipment
{
public:
	///A constructor with name, type and stats.
	Equipment(std::string name, EquipmentType etype, CalculationType ctype,/* NumberType ntype,*/
		int ctime, int clevel, int mass, 
		int atk, int def, int spd, int hp, int sp);
	///A destructor.
	~Equipment();

	std::string equipmentName;
	EquipmentType equipmentType;
	CalculationType calculationType;
	//NumberType numberType;
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