/*
 * WeaponBlade.h
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */

#ifndef WEAPONBLADE_H_
#define WEAPONBLADE_H_

#include "Weapon.h"


/**
 * A sample implementation of Weapon.
 */

class WeaponBlade: public Weapon {
public:
	/**
	 * Constructor of a blade with default power 100
	 */
	WeaponBlade(int=100);
	/**
	 * Destructor
	 */
	virtual ~WeaponBlade();
	/**
	 * An implementation of attack that simply returns power.
	 */
	virtual int attack();
protected:

};


#endif /* WEAPONBLADE_H_ */
