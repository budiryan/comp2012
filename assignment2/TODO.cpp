/*
 * TODO.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: Budi Ryan
 */
#include "TODO.h"

/*
 *
 * IMPLEMENTATION OF WEAPONRIFLE
 *
 *
 */
WeaponRifle::WeaponRifle() {
	weapon_name = "Rifle";
	min_range = 1;
	max_range = 8;
	power = 10;
}

WeaponRifle::~WeaponRifle() {
}

int WeaponRifle::attack() {
	return power;
}

bool WeaponRifle::isInRange(int att_x, int att_y, int ene_x, int ene_y) const {
	int distance = abs(att_x - ene_x) + abs(att_y - ene_y);
	if (distance >= min_range && distance <= max_range
			&& (att_x == ene_x || att_y == ene_y))
		return true;

	return false;
}

/*
 *
 *
 * IMPLEMENTATION OF WEAPONSUPERRIFLE
 *
 *
 */
WeaponSuperRifle::WeaponSuperRifle() {
	weapon_name = "SuperRifle";
	min_range = 1;
	max_range = 10;
	power = 15;
}

WeaponSuperRifle::~WeaponSuperRifle() {
}

int WeaponSuperRifle::attack() {
	return power;
}

bool WeaponSuperRifle::isInRange(int att_x, int att_y, int ene_x,
		int ene_y) const {
	int distance = abs(att_x - ene_x) + abs(att_y - ene_y);
	if (distance >= min_range && distance <= max_range
			&& (att_x == ene_x || att_y == ene_y))
		return true;

	return false;
}

/*
 *
 *
 * IMPLEMENTATION OF WeaponMissile
 *
 *
 */
WeaponMissile::WeaponMissile(int p) {
	weapon_name = "Missile";
	min_range = 3;
	max_range = 8;
	power = p;
	usedForAttack = false;
}

WeaponMissile::~WeaponMissile() {

}

int WeaponMissile::attack() {
	if (!usedForAttack)
		usedForAttack = true;
	return power;
}

bool WeaponMissile::isInRange(int att_x, int att_y, int ene_x,
		int ene_y) const {
	int distance = abs(att_x - ene_x) + abs(att_y - ene_y);
	if (usedForAttack == true)
		return false;
	else {
		if (distance >= min_range && distance <= max_range)
			return true;
		else
			return false;
	}
	return false;
}

/*
 *
 *
 * IMPLEMENTATION FOR WEAPONFIST
 *
 *
 */
WeaponFist::WeaponFist(int p) {
	weapon_name = "Fist";
	min_range = 1;
	max_range = 1;
	power = p;
}

WeaponFist::~WeaponFist() {
}

int WeaponFist::attack() {
	return power;
}

/*
 *
 *
 * REDEFINITION OF ROBOT::ATTACK() FUNCTION
 *
 *
 */

int Robot::attack(Robot* robot, Weapon* weapon) {
	if (robot == nullptr || weapon == nullptr)
		return 0;
	int damage;
	int enemyX;
	int enemyY;
	robot->getXY(enemyX, enemyY);

	if (robot->getAlly() == getAlly()
			|| !(weapon->isInRange(x, y, enemyX, enemyY)))
		return 0;

	//If the robot uses fist...
	if (weapon->getName() == "Fist" && getAlly() != robot->getAlly()
			&& robot->getAtt() >= getAtt()) {
		damage = max((robot->getAtt() * weapon->attack() - getDef()), 1);
		setHP(hp - damage);
		return (-1 * damage);
	}

	damage = max(getAtt() * weapon->attack() - robot->getDef(), 1);
	robot->setHP(robot->getHP() - damage);
	return damage;
}

/*
 *
 *
 * IMPLEMENTATION OF ROBOTHEALER
 *
 *
 */

RobotHealer::RobotHealer(string s, int health, int speeds, int attk, int deff) :
		Robot(s, health, speeds, attk, deff) {
}

RobotHealer::~RobotHealer() {
}

int RobotHealer::attack(Robot * robot, Weapon * weapon) {
	if (robot == nullptr || weapon == nullptr)
		return 0;
	int enemyX;
	int enemyY;
	robot->getXY(enemyX, enemyY);

	//If the weapon is out of range...
	if (!(weapon->isInRange(x, y, enemyX, enemyY)))
		return 0;

	//In case it heals...
	if ((robot->getAlly() == getAlly())
			&& (abs(enemyX - x) + abs(enemyY - y) == 1)) {
		//heal the shit, extra conditioning first
		if ((robot->getHP() + 100) >= robot->getMaxHP()) {
			robot->setHP(robot->getMaxHP());
			return (-100);
		} else {
			robot->setHP(robot->getHP() + 100);
			return (-100);
		}
	}

	int damage;

//Make a case for special weapons
//Case for Weapon Fist
	if (weapon->getName() == "Fist" && getAlly() != robot->getAlly()
			&& robot->getAtt() >= getAtt()) {
		damage = max((robot->getAtt() * weapon->attack() - getDef()), 1);
		setHP(hp - damage);
		return (-1 * damage);
	}

	//Otherwise just make it other weapons
	damage = max(getAtt() * weapon->attack() - robot->getDef(), 1);
	robot->setHP(robot->getHP() - damage);
	return damage;

}

/*
 *
 *
 * IMPLEMENTATION OF ROBOTHOPPER
 *
 *
 */
RobotHopper::RobotHopper(string n, int health, int attk, int deff) :
		Robot(n, health, 3, attk, deff) {
}

RobotHopper::~RobotHopper() {
}

bool RobotHopper::isInRange(int aX, int aY) const {
	if (aX < 0 || aX > ARENA_W || aY < 0 || aY > ARENA_H)
		return false;

	if ((abs(aX - x) + abs(aY - y) == speed) && abs(aX - x) < 3
			&& abs(aY - y) < 3) {
		return true;
	}

	return false;

}

/*
 *
 *
 * Implementation of RobotHoppingHealer
 *
 *
 */

RobotHoppingHealer::RobotHoppingHealer(string n, int health, int attk, int deff) :
		Robot(n, health, 3, attk, deff), RobotHealer(n, health, 3, attk, deff), RobotHopper(
				n, health, attk, deff) {
}

RobotHoppingHealer::~RobotHoppingHealer() {
}

