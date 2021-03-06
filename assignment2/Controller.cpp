/*
 * Controller.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */

#include "Controller.h"
#include <string>
#include <sstream>

using namespace std;

Controller::Controller() {
	arena = new Arena();
	view = new View(arena);
	state = NAVIGATE;
	view->renderAll();
	selectEnemy = nullptr;
	selectRobot = nullptr;
	selectWeapon = nullptr;
}

Controller::~Controller() {
	delete view;
	delete arena;
}

void Controller::run() {
	bool running = true;
	view->pause("Super Robot PA2. \nF1 - exit; Arrow keys, space/enter to control.");
	while (running) {
		running = handleInput();
	}
}

bool Controller::handleInput()
{
	int x = 0, y = 0;
	int u = 0, v = 0;
	int opt;
	int damage;

	switch (state) {
	case NAVIGATE:
		if (arena->isGameOver()) {
			view->pause("Game Over");
			return false;
		}

		switch (view->handleNavigate(x, y)) {
		case EXIT:
			return false;
		case OKAY:
		default:
			Robot* r = arena->getRobotAt(x, y);
			if (r != nullptr && r->getAlly() == WARRIOR) {
				state = COMMAND;
				selectRobot = r;
			} else {
				int code = view->handleCommand(MENU_LIST);
				if (code == M_END_TURN) {
					view->pause(string("Enemy finish their move. Next round starts"));
					arena->setAllRobotReady();
				} 
				state = NAVIGATE;
			}
		}
		break;

	case SELECT_FREE_SPACE:
		switch (view->handleSelectSpace(selectRobot, x, y)) {
		case EXIT:
			return false;
		case OKAY:
			//check if it is free space;  robot is reachable, robot has not end turn
			if (arena->getRobotAt(x, y) == NULL && selectRobot->isInRange(x, y)
					&& !selectRobot->isEndTurn()) {
				selectRobot->move(x, y);
			}
			state = NAVIGATE;
		}
		break;

	case SELECT_WEAPON:
		opt = view->handleSelectWeapon(selectRobot);
		if (opt == EXIT)
			return false;
		if (opt == CANCEL) {
			selectRobot = NULL;
			state = NAVIGATE;
			break;
		}
		selectWeapon = selectRobot->getWeapon(opt);
		state = SELECT_ENEMY;
		break;

	case SELECT_ENEMY:
		selectRobot->getXY(x,y);
		switch (view->handleSelectEnemy(x, y, selectWeapon)) {
		case EXIT:
			return false;
		case OKAY:
			Robot* defender = arena->getRobotAt(x, y);
			selectRobot->getXY(u, v);
			if ( defender != nullptr) {
				if (!selectWeapon->isInRange(u, v, x, y)) {
					selectRobot = nullptr;
					selectWeapon = nullptr;
					state = NAVIGATE;
					break;
				}
				damage = selectRobot->attack(defender, selectWeapon);
				selectRobot->setEndTurn(true);
				stringstream m;
				if (defender->getHP() > 0) {

					m << "Damage for " << damage << " HPs" << endl;

				} else {
					m << defender->getName() << " is killed by " << selectRobot->getName();
					arena->removeRobot(defender);
				}
				if (selectRobot->getHP() == 0) {
					m << selectRobot->getName() << " is dead when attack" << defender->getName();
					arena->removeRobot(selectRobot);
				}
				view->pause(m.str());
			}
			state = NAVIGATE;
		}
		break;

	case COMMAND:
		switch (view->handleCommand(CMD_LIST)) {
		case EXIT:
			return false;
		case CANCEL:
			state = NAVIGATE;
			selectRobot = NULL;
			break;
		case ATTACK:
			if (!selectRobot->isEndTurn()) {
				state = SELECT_WEAPON;
			} else {
				state = NAVIGATE;
				selectRobot = NULL;
			}
			break;
		case MOVE:
			if (!selectRobot->isEndTurn()) {
				state = SELECT_FREE_SPACE;
			} else {
				state = NAVIGATE;
				selectRobot = NULL;
			}
			break;
		case END_TURN:
			selectRobot->setEndTurn(true);
			state = NAVIGATE;
			selectRobot = NULL;
			break;
		}
		break;

	case MENU:
		//should not appear here
		break;
	}

	return true;
}
