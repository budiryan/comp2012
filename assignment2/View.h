/*
 * View.h
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "Arena.h"
#ifdef _WIN_
#include "./ncurses_lib/curses.h"
#else
#include <curses.h>
#endif
#include <string.h>

#include "Robot.h"
#include "Weapon.h"
#include "definition.h"

/**
 * This is the View class is the MVC model. It is responsible for rendering screen and to do
 * simple interaction with the user. A sequence of key strokes will be turned to a command or option
 * and return to its caller - the controller.
 *
 * In order to display correct information, the View class also has some model class with it.
 */
class View {
public:

	/**
	 * Constructor.
	 * @param Arena* A pointer of the Arena from controller
	 */
	View(Arena*);
	/**
	 * Destructor
	 */
	virtual ~View();
	/**
	 * To display certain message on the screen
	 * @param string A string to display
	 */
	virtual void displayMessage(string);

	/**
	 * During the Navigate state, the View class asks the user to freely navigate on the arena and
	 * select a cell, which can be empty or with a robot. When the cursor moves on a Robot,
	 * it will also render the statistics of the robot.
	 *
	 * @param int X-coordinate of the selected cell
	 * @param int Y-coordinate of the selected cell
	 *
	 * @return EXIT - to quit program; OK - normal
	 */
	virtual int handleNavigate(int&, int&);


	/**
	 * During the Command state and the Menu state, the View class asks the user to pick one of the commands
	 * from the command box. It triggers the next stage.
	 * @param int an integer that is either CMD_LIST, MENU_LIST which controls which list of commands to display
	 * @return an integer that is the index of the option the user chooses
	 *	 * for CMD_LIST: MOVE, ATTACK, END_TURN, CANCEL;
	 *	 * for MENU_LIST: M_END_TURN, M_CANCEL;
	 *	 * for both: EXIT - to quit program
	 */
	virtual int handleCommand(int);

	/**
	 * During the Select_free_space state, the View class asks the user to pick one of the free spaces
	 * for the robot to move to. It also shows the possible cells that the robot can move to.
	 *
	 * @param Robot* A pointer of the Robot needs to be moved.
	 * @param int X-coordinate of the cell that the Robot wishes to move (It may not be feasible)
	 * @param int Y-coordinate of the cell that the Robot wishes to move (It may not be feasible)
	 *
	 * @return EXIT - to quit program; OK - normal
	 */
	virtual int handleSelectSpace(const Robot*, int&, int&);

	/**
	 * During the Select_weapon state, the View class asks the user to pick one of the weapons from a weapon list.
	 *
	 * @param Robot* A pointer of the Robot selected to attack.
	 *
	 * @return EXIT - to quit program; CANCEL - drop this action; or the index of the weapon;
	 */
	virtual int handleSelectWeapon(const Robot*);

	/**
	 * During the Select_enemy state, the View class asks the user to pick an enemy to attack. It also renders the possible cells that the weapon can reach
	 *
	 * @param int input X-coordinate as the location of the attacker robot, return the location of the cell being selected
	 * @param int input Y-coordinate as the location of the attacker robot, return the location of the cell being selected
	 * @param Weapon* a weapon selected for attacking
	 *
	 * @return EXIT - to quit program; OK - normal; CANCEL - drop this action;
	 */
	virtual int handleSelectEnemy(int&, int&, Weapon*);

	/**
	 * To display a message and pause for a key stroke
	 *
	 * @param string the message to display
	 */
	virtual void pause(string = "");

	/**
	 * To render all windows
	 */
	virtual void renderAll();

protected:
	/**
	 * To render the Arena with all robots.
	 */
	virtual void renderArena();
	/**
	 * To render the reachable range of a robot.
	 * @param Robot* the pointer of the Robot being moved
	 */
	virtual void renderRange(const Robot*);
	/**
	 * To render the stats of a robot.
	 * @param Robot* the pointer of the Robot to get the stats from.
	 */
	virtual void renderStat(const Robot*);

	/**
	 * To render the command list.
	 * @param int the type of the command - either CMD_LIST / MENU_LIST
	 * @param int the option of the command currently highlighted
	 */
	virtual void renderCommand(int, int);

	/**
	 * To render the weapon selection list
	 * @param Weapon** the list of weapon pointers
	 * @param int total number of weapons
	 * @param int the index of the weapons currently highlighted
	 */
	virtual void renderWeapon(const Weapon**, int, int);

	/**
	 * To render the range of a weapon during enemy select state
	 * @param Weapon* the weapon to be used for attacking
	 * @param int the x-coordinate of the attacker
	 * @param int the y-coordinate of the attacker
	 */
	virtual void renderWeaponRange(const Weapon*, int, int);

	/**
	 * The arena model.
	 * @see Arena
	 */
	Arena* arena;

private:
	void moveCursor(int);
	int cursor_x, cursor_y;
	WINDOW *msg_win, *arena_win, *stat_win, *comm_win;
	WINDOW *msg_win_box, *arena_win_box, *stat_win_box, *comm_win_box;
};

#endif /* VIEW_H_ */
