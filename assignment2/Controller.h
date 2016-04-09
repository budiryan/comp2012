/*
 * Controller.h
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Arena.h"
#include "View.h"
#include "definition.h"

/**
 * The Controller in the MVC model. It acts like the big brother to dispatch jobs and ask
 * the View to render the screen.
 */
class Controller {
public:
	/**
	 * Default constructor
	 */
	Controller();
	/**
	 * Destructor
	 */
	virtual ~Controller();
	/**
	 * The program entry to start the game
	 */
	virtual void run();
protected:
	/**
	 * The main looping function that handles inputs from the user. Rather than taking a concrete
	 * key stroke, this function handles only the option and the coordinate that a user has chosen
	 * from the View class.
	 */
	virtual bool handleInput();


	/**
	 * An model class
	 * @see Arena
	 */
	Arena *arena;
	/**
	 * A view class
	 * @see View
	 */
	View *view;
	/**
	 * The state of the game: NAVIGATE, COMMAND, SELECT_FREE_SPACE, SELECT_WEAPON, SELECT_ENEMY, MENU
	 */
	gamestate state;
	/**
	 * To record which Robot (Warrior) is selected by the user
	 */
	Robot *selectRobot;
	/**
	 * To record which enemy robot the user wishes to attack
	 */
	Robot *selectEnemy;
	/**
	 * To record which weapon the user has chosen
	 */
	Weapon *selectWeapon;

};

#endif /* CONTROLLER_H_ */
