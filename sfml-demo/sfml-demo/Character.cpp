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