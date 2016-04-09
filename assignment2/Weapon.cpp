/*
 * Weapon.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */

#include "Weapon.h"
#include <stdlib.h>

using namespace std;

Weapon::Weapon() : power(0), min_range(0), max_range(0) {

}

Weapon::~Weapon() {
}

Weapon::Weapon(string aName, int aPower, int aMin, int aMax) : weapon_name (aName), power (aPower), min_range(aMin), max_range(aMax) {
}

bool Weapon::isInRange(int att_x, int att_y, int ene_x, int ene_y) const {
	int distance = abs(att_x - ene_x) + abs(att_y - ene_y);
	if (distance >= min_range && distance <= max_range)
		return true;
	return false;
}

