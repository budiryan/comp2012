/*
 * View.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: kevinw
 */

#include "View.h"

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

/**
 * Reason for not moving the following parameters to definition.h is to allow
 * further extension of the view class. For example one may like to extend a GUI
 * view class using Qt!
 *
 * But the size of ARENA does matter as it is governing the logic of arena. So these
 * parameters are actually defined somewhere else.
 */

extern const int ARENA_W;
extern const int ARENA_H;

const int ARENA_X = 0;
const int ARENA_Y = 0;
const int ARENA_BOX_W = ARENA_W + 2;
const int ARENA_BOX_H = ARENA_H + 2;

const int MSG_X = 0;
const int MSG_Y = ARENA_BOX_H + ARENA_Y;
const int MSG_W = ARENA_BOX_W;
const int MSG_H = 5;

const int STAT_X = ARENA_BOX_W + ARENA_X;
const int STAT_Y = 0;
const int STAT_H = 12;
const int STAT_W = 25;

const int COMM_Y = STAT_Y + STAT_H;
const int COMM_X = STAT_X;
const int COMM_H = 12;
const int COMM_W = STAT_W;

const char* COMMANDS[] = { "Move", "Attack/Heal", "End Turns", "Cancel" };
const char* MENUS[] = { "End Main Turns", "Cancel" };
enum {UP, DOWN, LEFT, RIGHT};


View::View(Arena* aArena) : arena(aArena)
{
	initscr();
	clear();
	noecho();
	curs_set(0);
	cbreak(); /* Line buffering disabled. pass on everything */

	keypad(stdscr, TRUE);
	raw();
	nonl();

	cursor_x = 0;
	cursor_y = 0;

	refresh();

	msg_win_box = newwin(MSG_H, MSG_W, MSG_Y, MSG_X);
	box(msg_win_box, 0, 0);
	wrefresh(msg_win_box);
	arena_win_box = newwin(ARENA_BOX_H, ARENA_BOX_W, ARENA_Y, ARENA_X);
	box(arena_win_box, 0, 0);
	wrefresh(arena_win_box);
	stat_win_box = newwin(STAT_H, STAT_W, STAT_Y, STAT_X);
	box(stat_win_box, 0, 0);
	wrefresh(stat_win_box);
	comm_win_box = newwin(COMM_H, COMM_W, COMM_Y, COMM_X);
	box(comm_win_box, 0, 0);
	wrefresh(comm_win_box);

	msg_win = newwin(MSG_H - 2, MSG_W - 2, MSG_Y + 1, MSG_X + 1);
	wrefresh(msg_win);
	arena_win = newwin(ARENA_H, ARENA_W, ARENA_Y + 1, ARENA_X + 1);
	wrefresh(arena_win);
	stat_win = newwin(STAT_H - 2, STAT_W - 2, STAT_Y + 1, STAT_X + 1);
	wrefresh(stat_win);
	comm_win = newwin(COMM_H - 2, COMM_W - 2, COMM_Y + 1, COMM_X + 1);
	wrefresh(comm_win);

}

View::~View() {
	clrtoeol();
	refresh();
	endwin();
	delwin(msg_win);
	delwin(comm_win);
	delwin(stat_win);
	delwin(arena_win);
	delwin(msg_win_box);
	delwin(arena_win_box);
	delwin(stat_win_box);
	delwin(comm_win_box);
}

void View::renderArena() {
	Robot** robots;
	int num_robots;

	bool cursor_display = false;
	wclear(arena_win);

	arena->getRobots(robots, num_robots, ALL_ROBOTS);
	for (int i = 0; i < num_robots; i++) {
		int x, y;

		Robot* r = robots[i];
		r->getXY(x, y);
		char c = r->getName().at(0);

		if (r->getAlly() == ENEMY)
			wattron(arena_win, A_BOLD);

		if (cursor_x == x && cursor_y == y) {
			wattron(arena_win, A_REVERSE);
			mvwaddch(arena_win, y, x, c);
			wattroff(arena_win, A_REVERSE);
			cursor_display = true;
		} else {
			mvwaddch(arena_win, y, x, c);
		}

		if (r->getAlly() == ENEMY)
			wattroff(arena_win, A_BOLD);
	}

	if (!cursor_display) {
		wattron(arena_win, A_BLINK);
		mvwaddch(arena_win, cursor_y, cursor_x, '@');
		wattroff(arena_win, A_BLINK);
	}

	wrefresh(arena_win);
	delete[] robots;
}

void View::renderRange(const Robot* r) {
	wattron(arena_win, A_REVERSE);

	for (int i = 0; i < ARENA_W; i++)
		for (int j = 0; j < ARENA_H; j++) {
			//print the highlighted map except for existing robot, cursor, and unreachable area
			if (arena->getRobotAt(i, j) == NULL && r->isInRange(i, j)
					&& !(i == cursor_x && j == cursor_y)) {
				mvwaddch(arena_win, j, i, ' ');
			}
		}

	wattroff(arena_win, A_REVERSE);
	wrefresh(arena_win);
}

void View::renderWeaponRange(const Weapon* w, int x, int y) {
	wattron(arena_win, A_REVERSE);
	for (int i = 0; i < ARENA_W; i++)
		for (int j = 0; j < ARENA_H; j++) {
			//print the highlighted map except for existing robot, cursor, and unreachable area
			if (arena->getRobotAt(i, j) == NULL && w->isInRange(x, y, i, j)
					&& !(i == cursor_x && j == cursor_y)) {
				mvwaddch(arena_win, j, i, ' ');
			}
		}

	wattroff(arena_win, A_REVERSE);
	wrefresh(arena_win);
}

void View::displayMessage(string message) {
	wclear(msg_win);
	mvwprintw(msg_win, 0, 0, message.c_str());
	wrefresh(msg_win);
}

void View::renderStat(const Robot* robot = nullptr) {
	wclear(stat_win);
	wrefresh(stat_win);
	if (robot == nullptr) {
		robot = arena->getRobotAt(cursor_x, cursor_y);
		if (robot == nullptr) //if it is still nullptr means there is no robot to run
			return;
	}

	int line = 1;
	stringstream m;

	m << robot->getName() << " (" << robot->getAllyName() << ")";
	mvwprintw(stat_win, line++, 0, m.str().c_str());
	m.str("");
	m.clear();

	m << "HP\t\t" << robot->getHP();
	mvwprintw(stat_win, line++, 0, m.str().c_str());
	m.str("");
	m.clear();

	m << "Att\t\t" << robot->getAtt();
	mvwprintw(stat_win, line++, 0, m.str().c_str());
	m.str("");
	m.clear();

	m << "Def\t\t" << robot->getDef();
	mvwprintw(stat_win, line++, 0, m.str().c_str());
	m.str("");
	m.clear();

	m << "Speed\t\t" << robot->getSpeed();
	mvwprintw(stat_win, line++, 0, m.str().c_str());
	m.str("");
	m.clear();

	m << "Turns End\t" << robot->isEndTurn();
	mvwprintw(stat_win, line++, 0, m.str().c_str());
	wrefresh(stat_win);
}

void View::renderCommand(int cmd, int opt) {
	wclear(comm_win);
	int lastopt;
	const char** cmdText;

	if (cmd == CMD_LIST) {
		lastopt = LAST_OPTION;
		cmdText = COMMANDS;
	} else {
		lastopt = M_LAST_OPTION;
		cmdText = MENUS;
	}

	for (int i = 0; i <= lastopt; i++) {
		if (opt == i) { //highlight that one
			wattron(comm_win, A_REVERSE);
			mvwprintw(comm_win, i, 0, cmdText[i]);
			wattroff(comm_win, A_REVERSE);
		} else
			mvwprintw(comm_win, i, 0, cmdText[i]);
	}

	wrefresh(comm_win);
}


void View::renderWeapon(const Weapon** w, int count, int opt) {
	wclear(comm_win);

	for (int i = 0; i <= count; i++) {
		const char * to_display;

		if (i == count)
			to_display = "Cancel";
		else
			to_display = w[i]->getName().c_str();

		if (opt == i) { //highlight that one
			wattron(comm_win, A_REVERSE);
			mvwprintw(comm_win, i, 0, to_display);
			wattroff(comm_win, A_REVERSE);
		} else
			mvwprintw(comm_win, i, 0, to_display);
	}

	if (opt != count) {
		stringstream m;

		m << "Power: \t" << w[opt]->getPower() << endl <<
				"Min Range: \t" << w[opt]->getMinRange() << endl <<
				"Max Range: \t" << w[opt]->getMaxRange();

		mvwprintw(comm_win, count + 1, 0, m.str().c_str());
	}

	wrefresh(comm_win);
}

void View::renderAll() {
	renderArena();
	const Robot* r = arena->getRobotAt(cursor_x, cursor_y);

	if (r != NULL)
		renderStat(r);
}

/*************************************************************************
 *
 * Input handlers
 *
 *
 *************************************************************************/

void View::pause(string message) {
	message += "\nHit any key to continue..";
	displayMessage(message);
	getch();
	wclear(msg_win);
	wrefresh(msg_win);
}



int View::handleCommand(int cmd) {
	int ch;
	int option = 0; // to return this value after all;

	renderCommand(cmd, option);
	displayMessage(string("Use Up/Down arrows and Enter/Space to select"));
	int lastopt;

	if (cmd == CMD_LIST)
		lastopt = LAST_OPTION;
	else
		lastopt = M_LAST_OPTION;

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
		case KEY_UP:
			option--;
			if (option == -1)
				option = lastopt;
			break;
		case KEY_DOWN:
			option++;
			if (option > lastopt)
				option = 0;
			break;
		case '\n':case KEY_ENTER: case '\r':
		case ' ':
			return option;
		}

		renderCommand(cmd, option);
	}

	return EXIT;
}

int View::handleSelectSpace(const Robot* selectRobot, int& x, int& y) {
	string message = "";
	int ch;

	renderArena();
	renderStat(selectRobot);
	renderRange(selectRobot);
	wclear(comm_win);
	wrefresh(comm_win);

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
		case KEY_UP:
			message += "UP KEY";
			moveCursor(UP);
			break;
		case KEY_DOWN:
			message += "DOWN KEY";
			moveCursor(DOWN);
			break;
		case KEY_LEFT:
			message += "LEFT KEY";
			moveCursor(LEFT);
			break;
		case KEY_RIGHT:
			message += "RIGHT KEY";
			moveCursor(RIGHT);
			break;
		case '\n':case KEY_ENTER: case '\r':
		case ' ':
			x = cursor_x;
			y = cursor_y;
			return OKAY;
		}

		//message += to_string(y) + ":" + to_string(x); // warning, lab mingw have not patched yet

		//displayMessage(message);
		renderArena();
		renderRange(selectRobot);
	}

	return EXIT;
}

int View::handleSelectWeapon(const Robot* robot) {
	int ch;
	int option = 0; // to return this value after all;

	renderArena();
	wclear(comm_win);
	wrefresh(comm_win);
	displayMessage(string("Use Up/Down arrows and Enter/Space to select weapon."));
	int numWeapon = robot->getNumWeapons();
	int numOption = numWeapon + 1;
	const Weapon* w[numWeapon];

	for (int i = 0; i < numWeapon; i++)
		w[i] = robot->getWeapon(i);

	renderWeapon(w, numWeapon, option);

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
		case KEY_UP:
			option--;
			if (option == -1)
				option = numOption - 1;
			break;
		case KEY_DOWN:
			option++;
			if (option >= numOption)
				option = 0;
			break;
		case '\n':case KEY_ENTER: case '\r':
		case ' ':
			if (option == numOption - 1)
				return CANCEL;
			return option;
		}

		renderWeapon(w, numWeapon, option);
	}

	return EXIT;

}

void View::moveCursor(int d) {
	switch (d) {
	case UP:
		if (cursor_y > 0)
			cursor_y--;
		break;
	case DOWN:
		if (cursor_y < ARENA_H - 1)  // from 0 to ARENA_H - 1, height = ARENA_H
			cursor_y++;
		break;
	case LEFT:
		if (cursor_x > 0)
			cursor_x--;
		break;
	case RIGHT:
		if (cursor_x < ARENA_W - 1)
			cursor_x++;
		break;
	}
}

int View::handleNavigate(int& x, int&y) {
	string message = "Use Up/Down/Left/Right arrows to navigate and Enter/Space to select";
	int ch;

	displayMessage(message);
	renderStat();
	renderArena();
	wclear(comm_win);
	wrefresh(comm_win);

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {

		case KEY_UP:
			message += "UP KEY";
			moveCursor(UP);
			break;
		case KEY_DOWN:
			message += "DOWN KEY";
			moveCursor(DOWN);
			break;
		case KEY_LEFT:
			message += "LEFT KEY";
			moveCursor(LEFT);
			break;
		case KEY_RIGHT:
			message += "RIGHT KEY";
			moveCursor(RIGHT);
			break;
		case '\n':case KEY_ENTER: case '\r':
		case ' ':
			x = cursor_x;
			y = cursor_y;
			return OKAY;
		}

		renderArena();
		renderStat();
	}

	return EXIT;
}

int View::handleSelectEnemy(int& x, int& y, Weapon* w) {
	string message = "Select your enemy";
	int ch;
	int robotX = x;
	int robotY = y;

	displayMessage(message);
	renderStat();
	renderArena();
	renderWeaponRange(w, robotX, robotY);
	wclear(comm_win);
	wrefresh(comm_win);

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {

		case KEY_UP:
			message += "UP KEY";
			moveCursor(UP);
			break;
		case KEY_DOWN:
			message += "DOWN KEY";
			moveCursor(DOWN);
			break;
		case KEY_LEFT:
			message += "LEFT KEY";
			moveCursor(LEFT);
			break;
		case KEY_RIGHT:
			message += "RIGHT KEY";
			moveCursor(RIGHT);
			break;
		case '\n':case KEY_ENTER: case '\r':
		case ' ':
			x = cursor_x;
			y = cursor_y;
			return OKAY;
		}

		renderArena();
		renderStat();
		renderWeaponRange(w, robotX, robotY);
	}

	return EXIT;
}

