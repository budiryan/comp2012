/*
 * Weapon.h
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */

#include <string>
using namespace std;


#ifndef WEAPON_H_
#define WEAPON_H_

/**
 * Weapon is an abstract model class that represents the logic of weapon.
 * A robot may have several weapons and use them during an attack. Each weapon has its own behavior.
 * The virtual function int attack() must be implemented by its non-abstract derived classes.
 */
class Weapon {
public:
	/**
	 * Default constructor that does nothing
	 */
	Weapon();
	/**
	 * Constructor.
	 * @param string the name of the Weapon
	 * @param int the power of the weapon
	 * @param int the minimum range of a weapon
	 * @param int the maximum range of a weapon
	 */
	Weapon(string, int, int, int);
	/**
	 * Destructor
	 */
	virtual ~Weapon();
	/**
	 * @return the string stores the name of weapon
	 */
	string getName() const {return weapon_name;}
	/**
	 * @return the integer of the minimum range
	 */
	int getMinRange() const {return min_range;}
	/**
	 * @return the integer of the maximum range
	 */
	int getMaxRange() const {return max_range;}
	/**
	 * @return the power of a weapon
	 */
	int getPower() const {return power;}
	/**
	 * To see if an coorindate is in range
	 * @param int the x-coordinate of the attacker
	 * @param int the y-coordinate of the attacker
	 * @param int the x-coordinate of the defender
	 * @param int the y-coordinate of the defender
	 * @return bool value of a coordinate is in range.
	 */
	virtual bool isInRange(int, int, int, int) const;

	/**
	 * This virtual function shall be called by the Robot when the attack happens.
	 * Before invoking this, the Controller shall check if a target is selected, and if the target's location being attacked is in the range.
	 * @return the attack coefficient brought by the weapon.
	 */
	virtual int attack() = 0;

protected:
	string weapon_name;
	int power;
	int min_range;
	int max_range;

};

#endif /* WEAPON_H_ */
