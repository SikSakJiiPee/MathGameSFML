#pragma once

#include <iostream>

enum class EquipmentType {WEAPON, ARMOR};

class Equipment
{
public:
	Equipment(std::string name, EquipmentType etype, int ctime, int clevel, int mass, 
		int atk, int def, int spd, int hp, int sp);
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