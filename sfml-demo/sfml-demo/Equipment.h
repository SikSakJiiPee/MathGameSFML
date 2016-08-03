#pragma once

#include <iostream>

class Equipment
{
public:
	Equipment();
	~Equipment();

	std::string name;
	//CalculationType calculationtype
	//NumberType numberType
	int calculationTime;
	int mass;

	//ei varmuutta
	int attack;
	int defence;
	int speed;
	int hp;
	int sp;
};