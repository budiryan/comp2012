/*
 * Arena.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */

#include "Arena.h"
#include "Weapon.h"
#include "WeaponBlade.h"

const int ARENA_W = 35;
const int ARENA_H = 17;

#ifndef _TESTING
//in case the flag TESTING is turned on in by the command line, the constructor shall be seen in newArena.cpp


Arena::Arena() {
	Robot* warrior_a = new Robot("Evin", 10, 2, 4, 3);
	Robot* warrior_b = new Robot("Allace", 20, 5, 4, 2);
	Robot* warrior_c = new Robot("Ong", 5, 2, 4, 4);

	Robot* enemy_a = new Robot("Bug", 1000, 2, 2, 2);
	Robot* enemy_b = new Robot("Worm", 2000, 2, 2, 2);

	warrior_a->setXY(1, 1);
	warrior_b->setXY(2, 3);
	warrior_c->setXY(2, 4);

	Weapon* w1[] = {new WeaponBlade(5)};
	Weapon* w2[] = {new WeaponBlade(15)};
	Weapon* w3[] = {new WeaponBlade(8)};
	warrior_a->setWeapon(w1, 1);
	warrior_b->setWeapon(w2, 1);
	warrior_c->setWeapon(w3, 1);

	enemy_a->setXY(1, 2);
	enemy_b->setXY(9, 5);

	num_robots = 5;

	robots = new Robot*[num_robots];
	robots[0] = warrior_a;
	robots[1] = warrior_b;
	robots[2] = warrior_c;
	robots[3] = enemy_a;
	robots[4] = enemy_b;

	for (int i = 0; i < 3; i++)
		robots[i]->setAlly(WARRIOR);

	for (int i = 3; i < num_robots; i++)
		robots[i]->setAlly(ENEMY);

}

#endif

Arena::~Arena() {
	for (int i = 0; i < num_robots; i++)
		delete robots[i];
	delete[] robots;
}

void Arena::getRobots(Robot**& aRobot, int& aNum, ally aAlly) const {

	if (aAlly == ALL_ROBOTS) {
		aRobot = new Robot*[num_robots];
		for (int i = 0; i < num_robots; i++)
			aRobot[i] = robots[i];
		aNum = num_robots;
		return;
	}

	//otherwise
	aNum = 0;
	for (int i = 0; i < num_robots; i++) {
		if (robots[i]->getAlly() == aAlly) {
			aNum++;
		}
	}
	aRobot = new Robot*[aNum];
	int counter = 0;
	for (int i = 0; i < num_robots; i++) {
		if (robots[i]->getAlly() == aAlly) {
			aRobot[counter++] = robots[i];
		}
	}

}

Robot* Arena::getRobotAt(int aX, int aY) const {
	int x, y;
	for (int i = 0; i < num_robots; i++) {
		robots[i]->getXY(x,y);
		if (x == aX && y == aY)
			return robots[i];
	}

	return nullptr;

}

bool Arena::isGameOver() const {
	bool warrior_die_out = true;
	bool enemy_die_out = true;
	for (int i = 0; i < num_robots; i++) {
		if (robots[i]->getAlly() == WARRIOR)
			warrior_die_out = false;
		if (robots[i]->getAlly() == ENEMY)
			enemy_die_out = false;
	}
	return (warrior_die_out || enemy_die_out);
}

void Arena::removeRobot(Robot* r) {
	int i;
	for (i = 0; i < num_robots; i++) {
		if (robots[i] == r)
			break;
	}
	//remove the i-th robot from the list, remember to delete the robot and the old robots array
	Robot ** newRobots = new Robot*[num_robots - 1];
	for (int j = 0; j < i; j++)
		newRobots[j] = robots[j];
	for (int j = i + 1; j < num_robots; j++)
		newRobots[j - 1] = robots[j];

	delete robots[i];
	delete [] robots;
	robots = newRobots;
	num_robots--;
}
