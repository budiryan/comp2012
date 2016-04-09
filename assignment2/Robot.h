/*
 * Robot.h
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */
#include "definition.h"
#include "Weapon.h"
#include <string>

#ifndef ROBOT_H_
#define ROBOT_H_

using namespace std;
const int MAX_WEAPON = 5;

enum ally {WARRIOR, ENEMY, ALL_ROBOTS};
extern const char* ALLYNAME[3];


/**
 * Robot is a model class the models a robot (cf. chess piece). Each robot can move and fight.
 * It has its health point, attack point, and defense point. It also has a list of weapons (at
 * most MAX_WEAPON).
 */
class Robot {
public:
	/**
	 * Constructor
	 * @param string Name of the Robot. The first letter will be used to display on Map as an icon
	 * @param int Maximum Health Point
	 * @param int Speed of the Robot
	 * @param int Attack Point
	 * @param int Defense Point
	 */
	Robot(string, int, int, int, int);
	/**
	 * Destructor
	 */
	virtual ~Robot();

	/**
	 * @return the string name of the robot
	 */
	string getName() const {return name;}
	/**
	 * @return the integer of Maximum Health Point
	 */
	int getMaxHP() const {return max_hp;}
	/**
	 * @return the integer of its Speed
	 */
	int getSpeed() const {return speed;}
	/**
	 * @return the integer of its current Health Point
	 */
	int getHP() const {return hp;}
	/**
	 * @return the integer of its defense point
	 */
	int getDef() const {return def;}
	/**
	 * @return the integer of its attack point
	 */
	int getAtt() const {return att;}
	/**
	 * @return the boolean if the Robot has endTurn
	 */
	bool isEndTurn() const {return endTurn;}
	/**
	 * @return the integer of the number of weapons the robot has
	 */
	int getNumWeapons() const {return num_of_weapons;}
	/**
	 * @return the ally that the robot belongs to
	 */
	ally getAlly() const {return my_ally;}
	/**
	 * @return the ally name
	 */
	const char* getAllyName() const {return ALLYNAME[my_ally];}

	/**
	 * @param int the index of a chosen weapon
	 * @return the point of Weapon of a particular index
	 */
	Weapon* getWeapon(int i) const {if (i < 0 || i >= MAX_WEAPON) return nullptr; else return weapons[i];}

	/**
	 * @param int the x-coordinate
	 * @param int the y-coordinate
	 */
	void getXY(int &aX, int &aY) const {aX = x; aY = y;}


	//setter function
	/**
	 * Set a list of Weapons to the Robot
	 * @param Weapon*[] The list of Weapon pointer
	 * @param int The number of Weapon
	 */
	void setWeapon(Weapon *[], int);
	/**
	 * Set the HP of a Robot which bounded 0 <= HP <= MAX_HP
	 * @param int desire HP
	 */
	void setHP(int);
	/**
	 * set the Ally of a Robot
	 * @param ally it can be either WARRIOR/ENEMY/ALL_ROBOTS. ally itself is an enum.
	 */
	void setAlly(ally a) {my_ally = a;}
	/**
	 * Set the xy coordinate, use only in the initialize stage.
	 * @param int the X-coordinate
	 * @param int the Y-coordinate
	 */
	void setXY(int aX, int aY) { x = aX; y = aY;}
	/**
	 * To set if the Robot should end its turn
	 * @param bool a boolean if turns end
	 */
	void setEndTurn(bool aTurn) { endTurn = aTurn;}
	/**
	 * Move is called when a user tries to move the robot from A to B. Unlike setXY, it also sets the turns end.
	 * @param int the X-coordinate
	 * @param int the Y-coordinate
	 */
	virtual void move(int aX, int aY) {x = aX; y=aY; endTurn = true;}

	/**
	 * To tell the robot to attack another enemy with a particular weapon. Before invoking this function the Controller
	 * shall check if the enemy being attacked is not null and is in range of the weapon.
	 * The default formula of calculating the damage is max(weapon's attack * attacker's attack point - defender's defense point, 1)
	 *
	 *
	 * @param Robot* A Robot pointer pointing to the enemy being attacked
	 * @param Weapon* A Weapon pointer pointing to the weapon chosen
	 */
	virtual int attack(Robot*, Weapon*);
	/**
	 * To tell if a particular space is reachable from the robot
	 * @param int the X-coordinate that wish to move to
	 * @param int the Y-coordinate that wish to move to
	 * @return a boolean indicate if it is in its reachable range. It does not really care about
	 * if there is another robot there or if it is out of bound.
	 */
	virtual bool isInRange(int aX, int aY) const;

protected:
	//general ability;
	/**
	 * The name of the the robot
	 */
	string name;
	/**
	 * Maximum HP
	 */
	int max_hp;
	/**
	 * The speed of it
	 */
	int speed;
	/**
	 * x-coordinate of its current location
	 */
	int x;
	/**
	 * y-coordinate of its current location
	 */
	int y;
	/**
	 * Is it turns end yet
	 */
	bool endTurn;
	/**
	 * Its ally
	 */
	ally my_ally;

	//ability needed during combat
	/**
	 * Its current Health Point (HP)
	 */
	int hp; //Health Point
	/**
	 * Power its arm, attack point
	 */
	int att;
	/**
	 * Thickness of shield, defense point
	 */
	int def;


	/**
	 * A list of Weapon
	 */
	Weapon* weapons[MAX_WEAPON];
	/**
	 * Total number of Weapon
	 */
	int num_of_weapons;


};

#endif /* ROBOT_H_ */
