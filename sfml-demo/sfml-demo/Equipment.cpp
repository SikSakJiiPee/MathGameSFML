#include "Equipment.h"

Equipment::Equipment(std::string name, EquipmentType etype, int ctime, int clevel, int mass,
	int atk, int def, int spd, int hp, int sp)
{
	equipmentName = name;
	equipmentType = etype;
	calculationTime = ctime;
	calculationLevel = clevel;
	equipmentMass = mass;
	attack = atk;
	defence = def;
	speed = spd;
	healthPoints = hp;
	specialPoints = sp;
}

Equipment::~Equipment()
{}

