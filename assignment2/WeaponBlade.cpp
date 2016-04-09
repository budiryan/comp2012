/*
 * WeaponBlade.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */

#include "WeaponBlade.h"

using namespace std;

WeaponBlade::WeaponBlade(int aPower) {
	weapon_name = "Blade";
	min_range = 1;
	max_range = 1;
	power = aPower;
}

WeaponBlade::~WeaponBlade() {

}

int WeaponBlade::attack() {
	return power;
}
