/*
 * Arena.h
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */
#include "Robot.h"

#ifndef ARENA_H_
#define ARENA_H_

extern const int ARENA_W;
extern const int ARENA_H;


/**
 * The Arena class
 * The Arena class is a model class that contains the Robot on it.
 * It also manages the coordinate of the game board and maintains the
 * size of the Arena (ARENA_W / ARENA_H) as defined in Arena.cpp
 */

class Arena {
public:
	/**
	 * Default constructor
	 */
	Arena();
	/**
	 * Destructor
	 */
	virtual ~Arena();

	//getter functions

	/**
	 * To obtain a list of Robots
	 * @param Robot** returns a list of Robot pointer
	 * @param int returns the total number of Robots
	 * @param int can be WARRIOR / ENEMY / ALL_ROBOTS to retrive the list of WARRIORs, the list of ENEMYs, or all Robots
	 *
	 * Note. Please clean up the array Robot*.
	 */
	void getRobots(Robot**&, int &, ally = WARRIOR) const;

	/**
	 * To retrieve the Robot at the given coordinate
	 * @param  is the x coordinate.
	 * @param 2nd is the y coordinate.
	 *
	 * @return A Robot point if there is a robot, nullptr if none.
	 */
	Robot* getRobotAt(int, int) const;

	/**
	 * A boolean function to check if either all Warriors have died or all Allies have died
	 *
	 * @return true if game over
	 */
	bool isGameOver() const;

	//setter functions

	/**
	 * To set all Robot EndTurn to false.
	 */
	void setAllRobotReady() { for (int i = 0; i < num_robots; i++) robots[i]->setEndTurn(false);}

	/**
	 * Remove a particular robot from the Arena (may have died?)
	 * @param A Robot pointer that one wishes to remove.
	 */
	void removeRobot(Robot*);

protected:
	/**
	 * A list of robots stored
	 */
	Robot** robots;
	/**
	 * Total number of robots
	 */
	int num_robots;
};

#endif /* ARENA_H_ */
