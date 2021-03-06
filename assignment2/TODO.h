#ifndef __TODO
#define __TODO
#include "Robot.h"
#include "Weapon.h"
#include "definition.h"
#include "arena.h"
#include <iostream>
#include <cmath>
using namespace std;

class WeaponRifle: public Weapon {
public:
	WeaponRifle();

	virtual bool isInRange(int att_x, int att_y, int ene_x, int ene_y) const;

	virtual ~WeaponRifle();

	virtual int attack();

protected:
};

class WeaponSuperRifle: public Weapon {
public:
	WeaponSuperRifle();

	virtual bool isInRange(int att_x, int att_y, int ene_x, int ene_y) const;

	virtual ~WeaponSuperRifle();

	virtual int attack();
protected:
};

class WeaponMissile: public Weapon {
public:
	WeaponMissile(int p);

	virtual ~WeaponMissile();

	virtual int attack();

	virtual bool isInRange(int att_x, int att_y, int ene_x, int ene_y) const;


protected:
	bool usedForAttack;
};

class WeaponFist: public Weapon {
public:
	WeaponFist(int p);

	virtual ~WeaponFist();

	virtual int attack();

protected:
};

class RobotHealer: virtual public Robot {
public:
	RobotHealer(string s, int health, int speeds, int attk, int deff);

	virtual ~RobotHealer();

	virtual int attack(Robot * robot, Weapon * weapon);

protected:

};

class RobotHopper: virtual public Robot {
public:
	RobotHopper(string n, int health, int attk, int deff);

	virtual ~RobotHopper();

	virtual bool isInRange(int aX, int aY) const;

protected:

};

class RobotHoppingHealer: public RobotHealer, public RobotHopper {
public:

	RobotHoppingHealer(string n, int health, int attk, int deff);

	virtual ~RobotHoppingHealer();

protected:

};

#endif


