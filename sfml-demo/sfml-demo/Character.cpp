#include "Character.h"

#include "Game.h"


Character::Character(bool isplayer, std::string name, std::string path, int lvl, int exp, 
	int hp, int maxhp, int sp, int maxsp,
	int atk, int def, int spd/*, int atkl, int defl*/, sf::Vector2f pos)
{
	isPlayerCharacter = isplayer;
	characterName = name;
	pathTexture = path;
	level = lvl;
	experiencePoints = exp;
	healthPoints = hp;
	maxHp = maxhp;
	specialPoints = sp;
	maxSp = maxsp;
	attack = atk;
	defence = def;
	speed = spd;
	//attackLuck = atkl;
	//defenceLuck = defl;
	position = pos;
	

	//texture and sprite
	if (!textureCharacter.loadFromFile(pathTexture))
		std::cout << "Loading textureCharacter failed!" << std::endl;
	spriteCharacter.setTexture(textureCharacter); // ei toimi oikein, lataa tekstuurin täysin valkoisena
	spriteCharacter.setPosition(position);
}

Character::~Character()
{}


std::string Character::getStringCharacterInfo(Character character)
{
	std::string name = character.characterName;
	std::string level = convertToString(character.level);
	std::string hp = convertToString(character.healthPoints);
	std::string maxhp = convertToString(character.maxHp);
	std::string sp = convertToString(character.specialPoints);
	std::string maxsp = convertToString(character.maxSp);

	std::string characterInfo = name + " " + "Lvl" + level + " " +
		"HP" + hp + "/" + maxhp + " " + "SP" + sp + "/" + maxsp;
		
	return characterInfo;
}

bool Character::checkIfAlive()
{
	if (healthPoints <= 0)
		return false;

	return true;
}

void Character::useItem(Item item, Character* character)
{
	if (item.effectType == EffectType::HPUP)
	{
		if (character->checkIfAlive())
		{
			character->healthPoints += item.healthPoints;
			if (character->healthPoints > character->maxHp)
				character->healthPoints = character->maxHp;
		}
			
		else 
			character->healthPoints += 0;
	}

	if (item.effectType == EffectType::SPUP)
	{
		character->specialPoints += item.specialPoints;
		if (character->specialPoints > character->maxSp)
			character->specialPoints = character->maxSp;
	}

	if (item.effectType == EffectType::DAMAGE)
	{
		character->healthPoints -= item.damage;
	}

	if (item.effectType == EffectType::REVIVE)
	{
		if (character->checkIfAlive() == false)
			character->healthPoints = (character->maxHp / 100) * item.revivePercent;
		else
			character->healthPoints += (character->maxHp / 100) * item.revivePercent;
	}

	//item.amount--;

	return;
}

void Character::useSpecialMove(SpecialMove specialMove, Character* character)
{
	if (specialMove.specialMoveName == "Super Punch")
	{
		character->healthPoints -= 25;
	}
	if (specialMove.specialMoveName == "Hyper Punch")
	{
		character->healthPoints -= 65;
	}

	return;
}


//specialMoves vector management
//size_t Character::getSpecialMoveCount()
//{
//
//}
//SpecialMove* Character::getSpecialMoveByName(std::string name)
//{
//	//size_t count(0);
//
//	//for (size_t i = 0; i < specialMoves.size(); i++)
//	//{
//	//	if (specialMoves[i].speciaMoveName == name)
//	//	{
//	//		return specialMoves[i];
//
//	//		count++;
//	//	}
//	//}
//
//	//return nullptr;
//}
//
////items vector management
////size_t Character::getItemCount()
////{
////
////}
//Item* Character::getItemByName(int index)
//{
//
//}
//
////equipments vector management
////size_t Character::getEquipmentCount()
////{
////
////}
//Equipment* Character::getEquipmentByName(int index)
//{
//
//}