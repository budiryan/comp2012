#ifndef __TODO
#define __TODO
#include "Robot.h"
#include "Weapon.h"
#include <iostream>
#include <cmath>
using namespace std;

class WeaponRifle: public Weapon {
public:
	WeaponRifle();

	bool isInRange(int att_x, int att_y, int ene_x, int ene_y) const;

	virtual ~WeaponRifle();

	int attack();

protected:
};

class WeaponSuperRifle: public Weapon {
public:
	WeaponSuperRifle();

	bool isInRange(int att_x, int att_y, int ene_x, int ene_y) const;

	virtual ~WeaponSuperRifle();

	int attack();
protected:
};

class WeaponMissle: public Weapon {
public:
	WeaponMissle(int p);

	virtual ~WeaponMissle();

	int attack();

protected:
	bool usedForAttack;
};

class WeaponFist: public Weapon{
public:
	WeaponFist(int p);

	virtual ~WeaponFist();

	int attack();

protected:
};

#endif
